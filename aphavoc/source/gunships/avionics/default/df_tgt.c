// 
// 	 Enemy Engaged RAH-66 Comanche Versus KA-52 Hokum
// 	 Copyright (C) 2000 Empire Interactive (Europe) Ltd,
// 	 677 High Road, North Finchley, London N12 0DA
// 
// 	 Please see the document LICENSE.TXT for the full licence agreement
// 
// 2. LICENCE
//  2.1 	
//  	Subject to the provisions of this Agreement we now grant to you the 
//  	following rights in respect of the Source Code:
//   2.1.1 
//   	the non-exclusive right to Exploit  the Source Code and Executable 
//   	Code on any medium; and 
//   2.1.2 
//   	the non-exclusive right to create and distribute Derivative Works.
//  2.2 	
//  	Subject to the provisions of this Agreement we now grant you the
// 	following rights in respect of the Object Code:
//   2.2.1 
// 	the non-exclusive right to Exploit the Object Code on the same
// 	terms and conditions set out in clause 3, provided that any
// 	distribution is done so on the terms of this Agreement and is
// 	accompanied by the Source Code and Executable Code (as
// 	applicable).
// 
// 3. GENERAL OBLIGATIONS
//  3.1 
//  	In consideration of the licence granted in clause 2.1 you now agree:
//   3.1.1 
// 	that when you distribute the Source Code or Executable Code or
// 	any Derivative Works to Recipients you will also include the
// 	terms of this Agreement;
//   3.1.2 
// 	that when you make the Source Code, Executable Code or any
// 	Derivative Works ("Materials") available to download, you will
// 	ensure that Recipients must accept the terms of this Agreement
// 	before being allowed to download such Materials;
//   3.1.3 
// 	that by Exploiting the Source Code or Executable Code you may
// 	not impose any further restrictions on a Recipient's subsequent
// 	Exploitation of the Source Code or Executable Code other than
// 	those contained in the terms and conditions of this Agreement;
//   3.1.4 
// 	not (and not to allow any third party) to profit or make any
// 	charge for the Source Code, or Executable Code, any
// 	Exploitation of the Source Code or Executable Code, or for any
// 	Derivative Works;
//   3.1.5 
// 	not to place any restrictions on the operability of the Source 
// 	Code;
//   3.1.6 
// 	to attach prominent notices to any Derivative Works stating
// 	that you have changed the Source Code or Executable Code and to
// 	include the details anddate of such change; and
//   3.1.7 
//   	not to Exploit the Source Code or Executable Code otherwise than
// 	as expressly permitted by  this Agreement.
// 



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEBUG_MODULE	0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_default_target_acquisition_systems (void)
{
	initialise_default_radar ();

	initialise_default_eo ();

	initialise_default_hms ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_default_target_acquisition_systems (void)
{
	deinitialise_default_radar ();

	deinitialise_default_eo ();

	deinitialise_default_hms ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void deselect_default_target_acquisition_system (target_acquisition_systems system)
{
	
	switch (system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			// laser is on in all modes but OFF in automatic mode
			if (!command_line_manual_laser_radar)
				set_laser_is_active(TRUE);
			
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			if (!command_line_manual_laser_radar)
				deactivate_common_ground_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (!command_line_manual_laser_radar)
				deactivate_common_air_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			deactivate_common_hms ();

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid target acquisition system = %d", system);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void select_default_target_acquisition_system (target_acquisition_systems system)
{
	target_acquisition_systems
		new_system,
		old_system;

	int
		damaged;

	new_system = system;
	old_system = target_acquisition_system;

	damaged = FALSE;

	reset_common_target_acquisition_system_keys ();

	if (eo_is_tracking_point())
		eo_stop_tracking();
			
	deselect_default_target_acquisition_system (target_acquisition_system);

	switch (system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			target_acquisition_system = system;

			set_gunship_target (NULL);
			
			if (!command_line_manual_laser_radar)
				set_laser_is_active(FALSE);

			#if 0

			hud_mode = previous_hud_mode;

			#endif

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			if (!default_damage.radar)
			{
				target_acquisition_system = system;

				deactivate_common_air_radar();

				if (!command_line_manual_laser_radar)
					activate_common_ground_radar ();

				if (command_line_targeting_system_auto_page)
					select_default_ground_radar_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = default_damage.radar;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (!default_damage.radar)
			{
				target_acquisition_system = system;

				deactivate_common_air_radar();

				if (!command_line_manual_laser_radar)
					activate_common_air_radar ();

				if (command_line_targeting_system_auto_page)
					select_default_air_radar_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = default_damage.radar;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			reset_mfd_mouse_buttons();
			
			if (!default_damage.flir)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_default_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = default_damage.flir;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			reset_mfd_mouse_buttons();
			
			if (!default_damage.dtv)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_default_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = default_damage.dtv;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			reset_mfd_mouse_buttons();
			
			if (!default_damage.dvo)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_default_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = default_damage.dvo;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			if (!default_damage.ihadss)
			{
				target_acquisition_system = system;

				activate_common_hms ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = default_damage.ihadss;

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid target acquisition system = %d", system);

			break;
		}
	}

	if (!command_line_manual_laser_radar)
		play_common_cpg_target_acquisition_system_speech (new_system, old_system, damaged);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_default_target_acquisition_system (void)
{
	if (ground_radar_is_active())
		update_common_ground_radar(FALSE);
	else if (air_radar_is_active())
		update_common_air_radar();
	
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			target_locked = FALSE;

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_OFF);

			slave_common_eo_to_current_target ();

			slave_default_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			update_default_ground_radar ();  // this only updates scan zones etc, only need to do it when radar is active

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_GROUND_RADAR);

			slave_common_eo_to_current_target ();

			slave_default_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			update_default_air_radar ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_AIR_RADAR);

			slave_common_eo_to_current_target ();

			slave_default_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			update_default_eo (&default_flir);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_FLIR);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			update_default_eo (&default_dtv);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_DTV);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			update_default_eo (&default_dvo);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_DVO);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			update_default_hms ();

			update_common_hms ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_IHADSS);

			slave_common_eo_to_current_target ();

			slave_default_eo_to_current_target ();

			break;
		}
	}

	////////////////////////////////////////
	//
	// radar / laser / los to target
	//
	////////////////////////////////////////

	{
		entity
			*source,
			*target;

		int
			radar_on,
			laser_on,
			los_to_target;

		source = get_gunship_entity ();

		target = get_local_entity_parent (source, LIST_TYPE_TARGET);

		//
		// radar on/off
		//

		radar_on = FALSE;

		if (ground_radar_is_active() && ground_radar.sweep_mode != RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			radar_on = TRUE;

		else if (air_radar_is_active() && air_radar.sweep_mode != RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			radar_on = TRUE;

		if (radar_on != get_local_entity_int_value (source, INT_TYPE_RADAR_ON))
			set_client_server_entity_int_value (source, INT_TYPE_RADAR_ON, radar_on);

		//
		// laser on/off
		//

		laser_on = laser_is_active() && !default_damage.laser_designator;

		if (laser_on != get_local_entity_int_value (source, INT_TYPE_LASER_ON))
		{
			set_client_server_entity_int_value (source, INT_TYPE_LASER_ON, laser_on);
		}

		//
		// line of sight to target
		//

		if (target)
		{
			switch (target_acquisition_system)
			{
				case TARGET_ACQUISITION_SYSTEM_OFF:
				{
					los_to_target = FALSE;

					break;
				}
				case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
				case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
				{
					los_to_target = get_local_entity_int_value (target, INT_TYPE_GUNSHIP_RADAR_LOS_CLEAR);

					break;
				}
				case TARGET_ACQUISITION_SYSTEM_FLIR:
				case TARGET_ACQUISITION_SYSTEM_DTV:
				case TARGET_ACQUISITION_SYSTEM_DVO:
				{
					los_to_target = TRUE;

					break;
				}
				case TARGET_ACQUISITION_SYSTEM_IHADSS:
				{
					los_to_target = TRUE;

					break;
				}
			}
		}
		else
		{
			los_to_target = FALSE;
		}

		if (los_to_target != get_local_entity_int_value (source, INT_TYPE_LOS_TO_TARGET))
		{
			set_client_server_entity_int_value (source, INT_TYPE_LOS_TO_TARGET, los_to_target);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void centre_default_target_acquisition_system (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			centre_default_ground_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			centre_default_air_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			centre_default_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			centre_default_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			centre_default_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_default_show_allied_targets (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.show_allied_targets ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_default_auto_target (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			ground_radar.auto_target ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.auto_target ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_default_lock_target (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			ground_radar.target_locked ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.target_locked ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			toggle_eo_lock();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			hms_target_locked ^= 1;

			if (hms_target_locked)
			{
				if (in_cockpit)
				{
					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET);
				}
			}
			else
			{
				if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET)
				{
					select_padlock_view_event (PADLOCK_MODE_NONE);
				}
			}

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_default_lock_target (int lock)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			ground_radar.target_locked = lock;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.target_locked = lock;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			set_eo_lock(lock);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			hms_target_locked = lock;

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void default_target_acquisition_system_misc_function1 (void)
{
	switch (target_acquisition_system)
	{
		case TARGET_ACQUISITION_SYSTEM_OFF:
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		{
			if (default_damage.radar)
			{
				set_ground_radar_is_active(FALSE);
				set_air_radar_is_active(FALSE);
			}
			else if (ground_radar.sweep_mode == RADAR_SWEEP_MODE_CONTINUOUS)
			{
				if (ground_radar_is_active())
					ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
				else
					ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
			}
			else
			{
				set_ground_radar_is_active(ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE);
				
				ground_radar.sweep_mode = RADAR_SWEEP_MODE_CONTINUOUS;
			}

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (default_damage.radar)
			{
				set_ground_radar_is_active(FALSE);
				set_air_radar_is_active(FALSE);
			}
			else if (air_radar.sweep_mode == RADAR_SWEEP_MODE_CONTINUOUS)
			{
				if (air_radar_is_active())
					air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
				else
					air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
			}
			else
			{
				set_air_radar_is_active(air_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE);
				
				air_radar.sweep_mode = RADAR_SWEEP_MODE_CONTINUOUS;
			}

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void default_target_acquisition_system_misc_function2 (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			if (ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			{
				if (!default_damage.radar)
				{
					ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
					set_ground_radar_is_active(TRUE);
				}
			}
			else if (ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE)
			{
				ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
				set_ground_radar_is_active(FALSE);
			}
			else if (!default_damage.radar)
				toggle_ground_radar_active();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (air_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			{
				if (!default_damage.radar)
				{
					air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
					set_air_radar_is_active(TRUE);
				}
			}
			else if (air_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE)
			{
				air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
				set_air_radar_is_active(FALSE);
			}
			else if (!default_damage.radar)
				toggle_air_radar_active();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
