/*
 * tacview.c
 *
 *  Created on: 25.mar.2009
 *      Author: arneh
 */

#include "project.h"

#include "tacview.h"
#include "version.h"

#define M1 111132.92
#define M2 -559.82
#define M3 1.175
#define P1 111412.84
#define P2 -93.5

#define FAST_UPDATE_FREQ 4
#define MEDIUM_UPDATE_FREQ 8
#define SLOW_UPDATE_FREQ 16

#define tacview_id(obj)  (get_local_entity_safe_index(obj) + 2)

static FILE* log_file = NULL;

static float
	latitude_offset = 0.0,
	longitude_offset = 0.0,
	latitude_scale = 0.0,
	tacview_starttime = 0.0;

static int
	update_group = 0,
	slow_update_group = 0,
	medium_update_group = 0,
	frequent_update_group = 0;

static void write_coordinates(entity* en);
static void write_srtm3_grid(int latitude, int longitude);
static void write_srtm3_terrain_elevation(void);
static int tacview_log_this_frame(entity* en);

void open_tacview_log(void)
{
	char
		log_filename[256];

	int
		tod = get_system_time_of_day(),
		hour = tod / 3600,
		minute = (tod % 3600) / 60,
		day,
		month,
		year;

	get_system_date(&day, &month, &year);
	year += 2000;
	snprintf(log_filename, ARRAY_LENGTH(log_filename), "tacview-logs\\eech-%4d-%02d-%02dT%02d%02d.txt.acmi", year, month, day, hour, minute);

	if (log_file)
	{
		ASSERT(FALSE);
		close_tacview_log();
	}

	log_file = safe_fopen(log_filename, "wb");
}

void close_tacview_log(void)
{
	if (log_file)
	{
		safe_fclose(log_file);
		log_file = NULL;
	}
}

void write_tacview_header(entity* pilot, entity* player_gunship)
{
	char
		cleaned_variable[256],
		byte_order_mark[] = {0xEF, 0xBB, 0xBF, 0};

	int
		tod = get_system_time_of_day(),
		hour = tod / 3600,
		minute = (tod % 3600) / 60,
		second = tod % 60,
		day,
		month,
		year,
		game_day = get_local_entity_int_value (get_session_entity (), INT_TYPE_DAY),
		game_hour,
		game_minute,
		game_second;

	session_list_data_type
		*session = get_current_game_session();

	entity
		*player_task = pilot ? get_player_task(pilot) : NULL;

	tacview_starttime = get_local_entity_float_value (get_session_entity (), FLOAT_TYPE_TIME_OF_DAY);

	if (!session)
		return;

	latitude_offset = get_current_map_latitude_offset();
	longitude_offset = get_current_map_longitude_offset();

	if (longitude_offset == 0.0 && latitude_offset == 0.0)
		debug_fatal("Current map has no longitude and latitude which is needed by tacview.  Add this information in mapinfo.txt as e.g. coordinate=10.0,20.1");

	latitude_scale = 1.0 / (M1 + (M2 * cos(2 * rad(latitude_offset)) + (M3 * cos(4 * rad(latitude_offset)))));

	get_system_date(&day, &month, &year);
	year += 2000;
	get_digital_clock_int_values (tacview_starttime, &game_hour, &game_minute, &game_second);

	fputs(byte_order_mark, log_file);

	// CORE HEADER

	fputs("FileType=text/acmi/tacview\n", log_file);
	fputs("FileVersion=1.2\n", log_file);
	fprintf(log_file, "Source=EECH %d.%d.%d\n", MAJOR_VERSION, DATA_VERSION, MINOR_VERSION);
	fputs("Recorder=EECH\n", log_file);
	fprintf(log_file, "RecordingTime=%04d-%02d-%02dT%02d:%02d:%02dZ\n", year, month, day, hour, minute, second);
	fputs("Author=", log_file);
	if (pilot)
	{
		const char* pilot_name = get_local_entity_string(pilot, STRING_TYPE_PILOTS_NAME);
		if (pilot_name)
		{
			latin1_to_utf8(pilot_name, cleaned_variable, sizeof(cleaned_variable), TRUE);
			fputs(cleaned_variable, log_file);
		}
	}
	fputs("\n", log_file);

	// DECLARATIONS

	latin1_to_utf8(session->displayed_title, cleaned_variable, sizeof(cleaned_variable), TRUE);
	fprintf(log_file, "Title=%s\n", cleaned_variable);
	if (player_task)
		fprintf(log_file, "Category=%s\n", get_local_entity_string(player_task, STRING_TYPE_SHORT_DISPLAY_NAME));
	fprintf(log_file, "MissionTime=%04d-%02d-%02dT%02d:%02d:%02dZ\n", year, month, day + game_day - 1, game_hour, game_minute, game_second);

	fprintf(log_file, "LatitudeOffset=%f\n", deg(latitude_offset));
	fprintf(log_file, "LongitudeOffset=%f\n", deg(longitude_offset));

	fputs("Coalition=Neutral,Green\n", log_file);
	fputs("Coalition=Blue,Blue\n", log_file);
	fputs("Coalition=Red,Red\n", log_file);
	fputs("ProvidedEvents=Takeoff,Landing,Destroyed,LeftArea\n", log_file);

	// ADDITIONAL INFO

	if (player_gunship)
		fprintf(log_file, "MainAircraftID=%x\n", tacview_id(player_gunship));

	//if (command_line_tacview_generate_srtm_height_data)
		write_srtm3_terrain_elevation();
}

void write_tacview_frame_header(void)
{
	float time = get_local_entity_float_value (get_session_entity (), FLOAT_TYPE_TIME_OF_DAY);
	fprintf(log_file, "#%.2f\n", time - tacview_starttime);
}

void write_tacview_new_unit(entity* en)
{
	entity_sub_types sub_type;
	int is_mobile = TRUE;

	if (!en || !log_file)
		return;

	sub_type = get_local_entity_int_value(en, INT_TYPE_ENTITY_SUB_TYPE);

	switch (en->type)
	{
	case ENTITY_TYPE_HELICOPTER:
	case ENTITY_TYPE_FIXED_WING:
		{
			int
				type = (en->type == ENTITY_TYPE_HELICOPTER) ? 0x18 : 0x10;
			entity
				*group = NULL;
			const char
				*callsign = NULL;
			char
				pilot[128] = "";

			if (get_local_entity_int_value(en, INT_TYPE_PLAYER) != ENTITY_PLAYER_AI)
			{
				entity* aircrew = get_local_entity_first_child(en, LIST_TYPE_AIRCREW);
				for (; aircrew; aircrew = get_local_entity_child_succ(aircrew, LIST_TYPE_AIRCREW))
				{
					if (get_local_entity_int_value(aircrew, INT_TYPE_ENTITY_SUB_TYPE) == ENTITY_SUB_TYPE_PILOT_PILOT)
					{
						const char* raw_pilot = get_local_entity_string(aircrew, STRING_TYPE_PILOTS_NAME);
						if (raw_pilot)
							latin1_to_utf8(raw_pilot, pilot, sizeof(pilot), TRUE);

						break;
					}
				}
			}

			group = get_local_entity_parent (en, LIST_TYPE_MEMBER);
			if (group)
				callsign = get_local_entity_string (group, STRING_TYPE_GROUP_CALLSIGN);

			// id, parent (empty), object type, coalition, country(empty), name, pilot, group, rank
			fprintf(log_file, "+%x,,%x,%x,,%s,%s,%s,%d\n",
					tacview_id(en),
					type,
					get_local_entity_int_value(en, INT_TYPE_SIDE),
					aircraft_database[sub_type].full_name,
					pilot ? pilot : "",
					callsign ? callsign : "",
					get_local_entity_int_value (en, INT_TYPE_GROUP_MEMBER_ID));

			set_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING, TRUE);
			break;
		}
	case ENTITY_TYPE_KEYSITE:
		{
			int
				length = 50,
				width = 50,
				height = 20,
				type = 0x88;

			char
				height_str[10] = "";

			switch (sub_type)
			{
			case ENTITY_SUB_TYPE_KEYSITE_AIRBASE:
			{
				length = 1000,
				type = 0x80;
				break;
			}
			case ENTITY_SUB_TYPE_KEYSITE_FARP:
			{
				length = 100,
				width = 100,
				type = 0x80;
				break;
			}
			case ENTITY_SUB_TYPE_KEYSITE_RADIO_TRANSMITTER:
			{
				length = 10;
				width = 10;
				height = 100;
				break;
			}
			case ENTITY_SUB_TYPE_KEYSITE_ANCHORAGE:
//				type = 0x34;
//				length = width = height = 0;
				// carriers have a ship entity too, so use that for tacview
				return;
//				break;
			default:
				break;
			}

			if (type == 0x88)
				snprintf(height_str, sizeof(height_str), ",%d", height);

#if 0
			if (type == 0x34)  // carrier, add as object
				// id, parent (empty), object type, coalition, country(empty), name, pilot(empty), group(empty), rank(empty)
				fprintf(log_file, "+%x,,%x,%x,,%s,,,\n",
						tacview_id(en),
						type,
						get_local_entity_int_value(en, INT_TYPE_SIDE),
						get_local_entity_string(en, STRING_TYPE_KEYSITE_NAME));
			else
#endif
				// id,, type, coalition, country(empty), name, length, width, height(for type 88)
				fprintf(log_file, "+%x,,%x,%d,,%s,%d,%d%s\n",
						tacview_id(en),
						type,
						get_local_entity_int_value(en, INT_TYPE_SIDE),
						get_local_entity_string(en, STRING_TYPE_KEYSITE_NAME),
						length,
						width,
						height_str);

			is_mobile = FALSE;
			break;
		}
	case ENTITY_TYPE_WEAPON:
		{
			int type = 0;
			const char* name = "";
			entity* parent = NULL;
			char parent_str[16] = "?";

			// gun rounds
			if (sub_type <= ENTITY_SUB_TYPE_WEAPON_NO_WEAPON)
				return;

			parent = get_local_entity_parent(en, LIST_TYPE_LAUNCHED_WEAPON);
			if (parent && get_local_entity_int_value(parent, INT_TYPE_TACVIEW_LOGGING))
				sprintf(parent_str, "%x", tacview_id(parent));

			if (sub_type <= ENTITY_SUB_TYPE_WEAPON_2A65_152MM_ROUND)
			{
				if (sub_type == ENTITY_SUB_TYPE_WEAPON_M2_12P7MM_ROUND
					|| sub_type == ENTITY_SUB_TYPE_WEAPON_NSV_12P7MM_ROUND
					|| sub_type == ENTITY_SUB_TYPE_WEAPON_9A642_12P7MM_ROUND
					|| sub_type == ENTITY_SUB_TYPE_WEAPON_KPV_14P5MM_ROUND
					|| sub_type == ENTITY_SUB_TYPE_WEAPON_ADMG_630_30MM_ROUND)  // Kiev's AA gun
				{
					type = 0x49;  // bullets
				}
				else if (sub_type == ENTITY_SUB_TYPE_WEAPON_BM21_122MM_ROCKET
						 || sub_type == ENTITY_SUB_TYPE_WEAPON_M270_227MM_ROCKET)
				{
					// these are actually rockets, despite being in the projectile section
					name = weapon_database[sub_type].full_name;
					type = 0x44;
				}
				else
					type = 0x48;  // shell
			}
			// rockets
			else if (sub_type <= ENTITY_SUB_TYPE_WEAPON_S13)
			{
				type = 0x44;
				name = weapon_database[sub_type].full_name;
			}
			// missiles
			else if (sub_type <= ENTITY_SUB_TYPE_WEAPON_AT11_SNIPER)
			{
				type = 0x40;
				name = weapon_database[sub_type].full_name;
			}
			else if (sub_type == ENTITY_SUB_TYPE_WEAPON_CHAFF)
			{
				type = 0x50;
			}
			// flares and smoke grenades
			else if (sub_type <= ENTITY_SUB_TYPE_WEAPON_SMOKE_GRENADE)
			{
				type = 0x54;
			}
			else  // crates, debris etc.
			{
				type = 0x46;
			}

			// id, parent (empty), object type, coalition(empty), country(empty), name, pilot(empty), group(empty), rank(empty)
			fprintf(log_file, "+%x,%s,%x,,,%s,,,\n",
					tacview_id(en),
					parent_str,
					type,
					name);

			break;
		}
	case ENTITY_TYPE_ANTI_AIRCRAFT:
	case ENTITY_TYPE_ROUTED_VEHICLE:
	case ENTITY_TYPE_SHIP_VEHICLE:
		{
			int type;
			const char* name = "";

			switch (en->type)
			{
			case ENTITY_TYPE_ANTI_AIRCRAFT:
				if (vehicle_database[sub_type].view_category == VIEW_CATEGORY_INFANTRY)
					type = 0x2c;
				else
					type = 0x20;
				break;
			case ENTITY_TYPE_ROUTED_VEHICLE:
				if (vehicle_database[sub_type].default_weapon_type == ENTITY_SUB_TYPE_WEAPON_NO_WEAPON)
					type = 0x28;
				else
					type = 0x24;
				break;
			case ENTITY_TYPE_SHIP_VEHICLE:
				if (vehicle_database[sub_type].map_icon == MAP_ICON_CARRIER)
					type = 0x34;
				else if (vehicle_database[sub_type].force_info_catagory == FORCE_INFO_CATAGORY_ARMED_SHIP_VEHICLE)
					type = 0x30;
				else
					type = 0x38;

				break;
			}
			name = vehicle_database[sub_type].full_name;

			// id, parent (empty), object type, coalition, country(empty), name, pilot, group, rank
			fprintf(log_file, "+%x,,%x,%x,,%s,,,\n",
					tacview_id(en),
					type,
					get_local_entity_int_value(en, INT_TYPE_SIDE),
					name);

			set_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING, TRUE);
			break;
		}

		break;
#if 0
	case ENTITY_TYPE_BRIDGE:
	case ENTITY_TYPE_CARGO:
	case ENTITY_TYPE_CITY:
	case ENTITY_TYPE_CITY_BUILDING:
	case ENTITY_TYPE_OBJECT:
	case ENTITY_TYPE_SCENIC:
	case ENTITY_TYPE_SITE:
	case ENTITY_TYPE_SITE_UPDATABLE:
#endif
	default:
		return;
	}

	if (is_mobile)
		set_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING, TRUE);

	write_tacview_unit_update(en, TRUE, TRUE, TRUE);
}

void write_tacview_unit_event(entity* en, tacview_event_type type, entity* related)
{
	int event_type;

	if (!get_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING))
		return;

	switch(type)
	{
	case TACVIEW_UNIT_LEFT_AREA:
		fprintf(log_file, "!28,%x\n", tacview_id(en));

		set_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING, FALSE);

		return;
	case TACVIEW_UNIT_DESTROYED:
		event_type = 0x2c;

		write_tacview_unit_update(en, TRUE, TRUE, TRUE);

		set_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING, FALSE);
		break;
	case TACVIEW_UNIT_TOOK_OFF:
		event_type = 0x40;
		break;
	case TACVIEW_UNIT_LANDED:
		event_type = 0x41;
		break;
	default:
		ASSERT(FALSE);
		return;
	}

	if (related)
		fprintf(log_file, "!%x,%x,%x\n", event_type, tacview_id(en), tacview_id(related));
	else
		fprintf(log_file, "!%x,%x,?\n", event_type, tacview_id(en));
}

void write_tacview_unit_update(entity* en, int moved, int rotated, int force)
{
	if (!tacview_log_this_frame(en) && !force)
		return;

	// TODO: start logging if in mission mode and inside area/FoW
	if (!get_local_entity_int_value(en, INT_TYPE_TACVIEW_LOGGING))
		return;

	fprintf(log_file, "%x,", tacview_id(en));

	if (moved)
		write_coordinates(en);
	else
		fputs(",,", log_file);

	if (rotated)
	{
		mobile* raw = get_local_entity_data(en);
		fprintf(log_file, ",%.1f,%.1f,%.1f\n",
				deg(get_roll_from_attitude_matrix(raw->attitude)),
				deg(get_pitch_from_attitude_matrix(raw->attitude)),
				deg(get_heading_from_attitude_matrix(raw->attitude)));
	}
	else
		fprintf(log_file, ",,,\n");
}

void write_coordinates(entity* en)
{
	vec3d
		*pos = get_local_entity_vec3d_ptr(en, VEC3D_TYPE_POSITION);
	float
		latitude = (pos->z * latitude_scale),
		abs_lat = fabs(latitude_offset + rad(latitude)),
		longitude_length = (P1 * cos(abs_lat)) + (P2 * cos(3 * abs_lat)),
		longitude = (pos->x / longitude_length);

	fprintf(log_file, "%.6f,%.6f,%.2f", latitude, longitude, pos->y);
}

// latitude in degrees, not rads!
static void get_latitude_longitude_length(float latitude, float* lat_length, float* long_length)
{
	float
		lat = rad(fabs(latitude));

	*lat_length = (M1 + (M2 * cos(2 * lat) + (M3 * cos(4 * lat)))),
	*long_length = (P1 * cos(lat)) + (P2 * cos(3 * lat));
}

static void write_srtm3_terrain_elevation(void)
{
	int
		lat,
		lng,
		start_latitude = (int)floor(deg(latitude_offset)),
		end_latitude,
		start_longitude = (int)floor(deg(longitude_offset)),
		end_longitude;

	float
		latitude_length,
		longitude_length;

	get_latitude_longitude_length(deg(latitude_offset), &latitude_length, &longitude_length);

	end_latitude = (int)ceil(deg(latitude_offset) + (MAX_MAP_Z / latitude_length));
	end_longitude = (int)ceil(deg(longitude_offset) + (MAX_MAP_X / longitude_length));

	for (lat = start_latitude; lat <= end_latitude; lat++)
		for (lng = start_longitude; lng <= end_longitude; lng++)
			write_srtm3_grid(lat, lng);
}

static short htons(short input)
{
	union {
		short s;
		char  bytes[2];
	} swapper;

	char tmp;

	swapper.s = input;
	tmp = swapper.bytes[0];
	swapper.bytes[0] = swapper.bytes[1];
	swapper.bytes[1] = tmp;

	return swapper.s;
}

static void write_srtm3_grid(int latitude, int longitude)
{
	char filename[256];
	FILE* srtm = NULL;
	int row, column;

	sprintf(filename, "%c%02d%c%03d.hgt", (latitude >= 0) ? 'N' : 'S', abs(latitude), (longitude >= 0) ? 'E' : 'W', abs(longitude));
	srtm = safe_fopen(filename, "wb");

	for (row = 0; row < 1201; row++)
	{
		float
			lat = (latitude + 1) - (row / 1200.0),
			latitude_length, //= (M1 + (M2 * cos(2 * rad(lat)) + (M3 * cos(4 * rad(lat))))),
			longitude_length; //= (P1 * cos(fabs(rad(lat)))) + (P2 * cos(3 * fabs(rad(lat))));

		get_latitude_longitude_length(lat, &latitude_length, &longitude_length);

		for (column = 0; column < 1201; column++)
		{
			float
				lng = longitude + (column / 1200.0);

			vec3d
				pos;

			int
				int_elevation;

			short
				elevation;

			pos.x = (lng - deg(longitude_offset)) * longitude_length,
			pos.y = 0.0;
			pos.z = (lat - deg(latitude_offset)) * latitude_length;

			if (point_inside_map_volume(&pos))
				pos.y = get_3d_terrain_elevation(pos.x, pos.z);

			convert_float_to_int(pos.y + 0.99, &int_elevation);
			elevation = (short)int_elevation;
			elevation = htons(elevation);

			fwrite(&elevation, sizeof(short), 1, srtm);
		}
	}

	safe_fclose(srtm);
}

int tacview_reset_frame(void)
{
	if (++update_group == SLOW_UPDATE_FREQ)
		update_group = 0;

	frequent_update_group = update_group & 3;
	medium_update_group = update_group & 7;
	slow_update_group = update_group;

	return TRUE; // frequent_update_group == 0;
}

static int tacview_log_this_frame(entity* en)
{
	switch (en->type)
	{
	case ENTITY_TYPE_HELICOPTER:
		if (++frequent_update_group == 4)
		{
			frequent_update_group = 0;
			return TRUE;
		}
		break;
	case ENTITY_TYPE_FIXED_WING:
	case ENTITY_TYPE_WEAPON:
		if (++medium_update_group == 8)
		{
			medium_update_group = 0;
			return TRUE;
		}
		break;
	case ENTITY_TYPE_ROUTED_VEHICLE:
	case ENTITY_TYPE_ANTI_AIRCRAFT:
	case ENTITY_TYPE_CARGO:
	case ENTITY_TYPE_SHIP_VEHICLE:
		if (++slow_update_group == 16)
		{
			slow_update_group = 0;
			return TRUE;
		}
		break;
	}

	return FALSE;
}