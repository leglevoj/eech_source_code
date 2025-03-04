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

#define DEBUG_MODULE 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ah64a_damage_flags
	ah64a_damage;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_ah64a_weapon_damage_status (void)
{
	entity
		*en;

	entity_sub_types
		weapon_sub_type;

	en = get_gunship_entity ();

	set_client_server_entity_weapon_damage (en, AH64A_CHAIN_GUN_TURRET, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.gun_jammed);

	set_client_server_entity_weapon_damage (en, AH64A_LHS_WING_TIP_MOUNT, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.lh_wing_tip_mount);
	set_client_server_entity_weapon_damage (en, AH64A_LHS_OUTER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.lh_outer_pylon);
	set_client_server_entity_weapon_damage (en, AH64A_LHS_INNER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.lh_inner_pylon);

	set_client_server_entity_weapon_damage (en, AH64A_RHS_WING_TIP_MOUNT, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.rh_wing_tip_mount);
	set_client_server_entity_weapon_damage (en, AH64A_RHS_OUTER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.rh_outer_pylon);
	set_client_server_entity_weapon_damage (en, AH64A_RHS_INNER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, ah64a_damage.rh_inner_pylon);

	set_client_server_entity_weapon_damage (en, AH64A_CHAFF_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, ah64a_damage.chaff_dispenser);
	set_client_server_entity_weapon_damage (en, AH64A_FLARE_DISPENSER, ENTITY_SUB_TYPE_WEAPON_FLARE, ah64a_damage.flare_dispenser);

	//
	// check if selected weapon is still available, if not, select next
	//

	weapon_sub_type = get_local_entity_int_value (en, INT_TYPE_SELECTED_WEAPON);

	if (weapon_sub_type != ENTITY_SUB_TYPE_WEAPON_NO_WEAPON)
	{
		if (!get_local_entity_weapon_available (en, weapon_sub_type))
		{
			weapon_sub_type = get_next_available_weapon_sub_type (en);

			set_gunship_weapon (weapon_sub_type);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fully_repair_ah64a_damage (void)
{
	set_ah64a_upfront_display_text ("", "", NULL, NULL);

	fire_extinguisher_used = FALSE;

	////////////////////////////////////////

	ah64a_damage.radar = FALSE;

	////////////////////////////////////////

	ah64a_damage.flir = FALSE;

	////////////////////////////////////////

	ah64a_damage.dtv = FALSE;

	////////////////////////////////////////

	ah64a_damage.dvo = FALSE;

	////////////////////////////////////////

	ah64a_damage.laser_designator = FALSE;

	////////////////////////////////////////

	ah64a_damage.radar_jammer = FALSE;

	////////////////////////////////////////

	ah64a_damage.infra_red_jammer = FALSE;

	////////////////////////////////////////

	ah64a_damage.navigation_computer = FALSE;

	////////////////////////////////////////

	ah64a_damage.communications = FALSE;

	////////////////////////////////////////

	ah64a_damage.radar_warning_system = FALSE;

	////////////////////////////////////////

	ah64a_damage.ihadss = FALSE;

	////////////////////////////////////////

	if (ah64a_damage.lh_mfd)
	{
		ah64a_damage.lh_mfd = FALSE;

		select_ah64a_mfd_mode (MFD_MODE_OFF, MFD_LOCATION_LHS);
	}

	////////////////////////////////////////

	if (ah64a_damage.rh_mfd)
	{
		ah64a_damage.rh_mfd = FALSE;

		select_ah64a_mfd_mode (MFD_MODE_OFF, MFD_LOCATION_RHS);
	}

	////////////////////////////////////////

	ah64a_damage.pnvs = FALSE;

	////////////////////////////////////////

	ah64a_damage.gun_jammed = FALSE;

	////////////////////////////////////////

	ah64a_damage.lh_wing_tip_mount = FALSE;

	////////////////////////////////////////

	ah64a_damage.lh_outer_pylon = FALSE;

	////////////////////////////////////////

	ah64a_damage.lh_inner_pylon = FALSE;

	////////////////////////////////////////

	ah64a_damage.rh_wing_tip_mount = FALSE;

	////////////////////////////////////////

	ah64a_damage.rh_outer_pylon = FALSE;

	////////////////////////////////////////

	ah64a_damage.rh_inner_pylon = FALSE;

	////////////////////////////////////////

	ah64a_damage.chaff_dispenser = FALSE;

	////////////////////////////////////////

	ah64a_damage.flare_dispenser = FALSE;

	////////////////////////////////////////

	set_ah64a_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void partially_repair_ah64a_damage (void)
{
	set_ah64a_upfront_display_text ("", "", NULL, NULL);

	fire_extinguisher_used = FALSE;

	////////////////////////////////////////

	if (ah64a_damage.radar)
	{
		ah64a_damage.radar = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.flir)
	{
		ah64a_damage.flir = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.dtv)
	{
		ah64a_damage.dtv = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.dvo)
	{
		ah64a_damage.dvo = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.laser_designator)
	{
		ah64a_damage.laser_designator = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.radar_jammer)
	{
		ah64a_damage.radar_jammer = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.infra_red_jammer)
	{
		ah64a_damage.infra_red_jammer = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.navigation_computer)
	{
		ah64a_damage.navigation_computer = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.communications)
	{
		ah64a_damage.communications = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.radar_warning_system)
	{
		ah64a_damage.radar_warning_system = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.ihadss)
	{
		ah64a_damage.ihadss = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.lh_mfd)
	{
		ah64a_damage.lh_mfd = frand1 () > 0.90;

		if (!ah64a_damage.lh_mfd)
		{
			select_ah64a_mfd_mode (MFD_MODE_OFF, MFD_LOCATION_LHS);
		}
	}

	////////////////////////////////////////

	if (ah64a_damage.rh_mfd)
	{
		ah64a_damage.rh_mfd = frand1 () > 0.90;

		if (!ah64a_damage.rh_mfd)
		{
			select_ah64a_mfd_mode (MFD_MODE_OFF, MFD_LOCATION_RHS);
		}
	}

	////////////////////////////////////////

	if (ah64a_damage.pnvs)
	{
		ah64a_damage.pnvs = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.gun_jammed)
	{
		ah64a_damage.gun_jammed = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.lh_wing_tip_mount)
	{
		ah64a_damage.lh_wing_tip_mount = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.lh_outer_pylon)
	{
		ah64a_damage.lh_outer_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.lh_inner_pylon)
	{
		ah64a_damage.lh_inner_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.rh_wing_tip_mount)
	{
		ah64a_damage.rh_wing_tip_mount = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.rh_outer_pylon)
	{
		ah64a_damage.rh_outer_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.rh_inner_pylon)
	{
		ah64a_damage.rh_inner_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.chaff_dispenser)
	{
		ah64a_damage.chaff_dispenser = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (ah64a_damage.flare_dispenser)
	{
		ah64a_damage.flare_dispenser = frand1 () > 0.90;
	}

	////////////////////////////////////////

	set_ah64a_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void repair_ah64a_weapon_damage (void)
{
	set_ah64a_upfront_display_text ("", "", NULL, NULL);

	ah64a_damage.gun_jammed			= FALSE;
	ah64a_damage.lh_wing_tip_mount	= FALSE;
	ah64a_damage.lh_outer_pylon		= FALSE;
	ah64a_damage.lh_inner_pylon		= FALSE;
	ah64a_damage.rh_wing_tip_mount	= FALSE;
	ah64a_damage.rh_outer_pylon		= FALSE;
	ah64a_damage.rh_inner_pylon		= FALSE;
	ah64a_damage.chaff_dispenser		= FALSE;
	ah64a_damage.flare_dispenser		= FALSE;

	set_ah64a_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void damage_systems (ah64a_damage_flags damage)
{
	entity
		*en;

	en = get_gunship_entity ();

	////////////////////////////////////////

	if (damage.radar)
	{
		if (!ah64a_damage.radar)
		{
			ah64a_damage.radar = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("RADAR FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_RADAR_FAILURE);

			if
			(
				(target_acquisition_system == TARGET_ACQUISITION_SYSTEM_GROUND_RADAR) ||
				(target_acquisition_system == TARGET_ACQUISITION_SYSTEM_AIR_RADAR)
			)
			{
				select_ah64a_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.flir)
	{
		if (!ah64a_damage.flir)
		{
			ah64a_damage.flir = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("FLIR FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_FLIR_FAILURE);

			if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_FLIR)
			{
				select_ah64a_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.dtv)
	{
		if (!ah64a_damage.dtv)
		{
			ah64a_damage.dtv = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("DTV FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_DTV_FAILURE);

			if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_DTV)
			{
				select_ah64a_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.dvo)
	{
		if (!ah64a_damage.dvo)
		{
			ah64a_damage.dvo = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("DVO FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_DVO_FAILURE);

			if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_DVO)
			{
				select_ah64a_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.laser_designator)
	{
		if (!ah64a_damage.laser_designator)
		{
			ah64a_damage.laser_designator = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("LASER DESIG", "FAILURE", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_LASER_DESIGNATOR_FAILURE);
		}
	}

	////////////////////////////////////////

	if (damage.radar_jammer)
	{
		if (!ah64a_damage.radar_jammer)
		{
			ah64a_damage.radar_jammer = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("RADAR JAMMER", "FAILURE", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_RADAR_JAMMER_FAILURE);

			if (get_local_entity_int_value (get_gunship_entity (), INT_TYPE_RADAR_JAMMER_ON))
			{
				set_client_server_entity_int_value (get_gunship_entity (), INT_TYPE_RADAR_JAMMER_ON, FALSE);
			}
		}
	}

	////////////////////////////////////////

	if (damage.infra_red_jammer)
	{
		if (!ah64a_damage.infra_red_jammer)
		{
			ah64a_damage.infra_red_jammer = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("IR JAMMER", "FAILURE", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_IR_JAMMER_FAILURE);

			if (get_local_entity_int_value (get_gunship_entity (), INT_TYPE_INFRA_RED_JAMMER_ON))
			{
				set_client_server_entity_int_value (get_gunship_entity (), INT_TYPE_INFRA_RED_JAMMER_ON, FALSE);
			}
		}
	}

	////////////////////////////////////////

	if (damage.navigation_computer)
	{
		if (!ah64a_damage.navigation_computer)
		{
			ah64a_damage.navigation_computer = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("NAV COMPUTER", "FAILURE", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_NAV_COMPUTER_FAILURE);
		}
	}

	////////////////////////////////////////

	if (damage.communications)
	{
		if (!ah64a_damage.communications)
		{
			ah64a_damage.communications = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("COMMS FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_COMMS_FAILURE);
		}
	}

	////////////////////////////////////////

	if (damage.radar_warning_system)
	{
		if (!ah64a_damage.radar_warning_system)
		{
			ah64a_damage.radar_warning_system = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("RADAR WARNING", "FAILURE", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_RADAR_WARNING_FAILURE);
		}
	}

	////////////////////////////////////////

	if (get_global_avionics_realism_level () > AVIONICS_REALISM_LEVEL_SIMPLE)
	{
		if (damage.ihadss)
		{
			if (!ah64a_damage.ihadss)
			{
				ah64a_damage.ihadss = TRUE;

				dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

				set_ah64a_upfront_display_text ("IHADSS FAILURE", "", NULL, NULL);

				play_client_server_warning_message (en, SPEECH_SYSTEM_IHADSS_FAILURE);

				if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_IHADSS)
				{
					select_ah64a_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
				}
			}
		}
	}

	////////////////////////////////////////

	if (damage.lh_mfd)
	{
		if (!ah64a_damage.lh_mfd)
		{
			ah64a_damage.lh_mfd = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("MFD FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_MFD_FAILURE);

			select_ah64a_mfd_mode (MFD_MODE_DAMAGED, MFD_LOCATION_LHS);
		}
	}

	////////////////////////////////////////

	if (damage.rh_mfd)
	{
		if (!ah64a_damage.rh_mfd)
		{
			ah64a_damage.rh_mfd = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("MFD FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_MFD_FAILURE);

			select_ah64a_mfd_mode (MFD_MODE_DAMAGED, MFD_LOCATION_RHS);
		}
	}

	////////////////////////////////////////

	if (damage.pnvs)
	{
		if (!ah64a_damage.pnvs)
		{
			ah64a_damage.pnvs = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("PNVS FAILURE", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_PNVS_FAILURE);

			night_vision_system_active = FALSE;
		}
	}

	////////////////////////////////////////

	if (damage.gun_jammed)
	{
		if (!ah64a_damage.gun_jammed)
		{
			ah64a_damage.gun_jammed = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("GUN JAMMED", "", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_GUN_JAMMED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_wing_tip_mount)
	{
		if (!ah64a_damage.lh_wing_tip_mount)
		{
			ah64a_damage.lh_wing_tip_mount = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("HARDPOINT", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_outer_pylon)
	{
		if (!ah64a_damage.lh_outer_pylon)
		{
			ah64a_damage.lh_outer_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("HARDPOINT", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_inner_pylon)
	{
		if (!ah64a_damage.lh_inner_pylon)
		{
			ah64a_damage.lh_inner_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("HARDPOINT", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_wing_tip_mount)
	{
		if (!ah64a_damage.rh_wing_tip_mount)
		{
			ah64a_damage.rh_wing_tip_mount = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("HARDPOINT", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_outer_pylon)
	{
		if (!ah64a_damage.rh_outer_pylon)
		{
			ah64a_damage.rh_outer_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("HARDPOINT", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_inner_pylon)
	{
		if (!ah64a_damage.rh_inner_pylon)
		{
			ah64a_damage.rh_inner_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("HARDPOINT", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.chaff_dispenser)
	{
		if (!ah64a_damage.chaff_dispenser)
		{
			ah64a_damage.chaff_dispenser = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("CHAFF DISPNSR", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_CHAFF_DISPENSER_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.flare_dispenser)
	{
		if (!ah64a_damage.flare_dispenser)
		{
			ah64a_damage.flare_dispenser = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_ah64a_upfront_display_text ("FLARE DISPNSR", "DAMAGED", NULL, NULL);

			play_client_server_warning_message (en, SPEECH_SYSTEM_FLARE_DISPENSER_DAMAGED);
		}
	}

	////////////////////////////////////////

	set_ah64a_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void damage_ah64a (gunship_damage_levels damage_level)
{
	unsigned int
		damage;

	ah64a_damage_flags
		ah64a_damage;

	damage = 0;

	switch (damage_level)
	{
		case GUNSHIP_DAMAGE_LEVEL_LIGHT:
		{
			damage |= 1 << (rand16 () & 0x1f);

			break;
		}
		case GUNSHIP_DAMAGE_LEVEL_MEDIUM:
		{
			damage |= 1 << (rand16 () & 0x1f);
			damage |= 1 << (rand16 () & 0x1f);

			break;
		}
		case GUNSHIP_DAMAGE_LEVEL_HEAVY:
		{
			damage |= 1 << (rand16 () & 0x1f);
			damage |= 1 << (rand16 () & 0x1f);
			damage |= 1 << (rand16 () & 0x1f);

			break;
		}
		default:
		{
			debug_fatal ("Invalid damage_level = %d", damage_level);

			break;
		}
	}

	ah64a_damage.flags = damage;

	damage_systems (ah64a_damage);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_ah64a_avionics_of_dynamics_fault (unsigned int damage)
{
	if (damage & DYNAMICS_DAMAGE_MAIN_ROTOR)
	{
		activate_ah64a_master_caution ();

		set_ah64a_upfront_display_text ("MAIN ROTOR", "DAMAGED", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_TAIL_ROTOR)
	{
		activate_ah64a_master_caution ();

		set_ah64a_upfront_display_text ("TAIL ROTOR", "DAMAGED", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_LEFT_ENGINE)
	{
		activate_ah64a_master_caution ();

		set_ah64a_upfront_display_text ("ENGINE 1", "DAMAGED", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_RIGHT_ENGINE)
	{
		activate_ah64a_master_caution ();

		set_ah64a_upfront_display_text ("ENGINE 2", "DAMAGED", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_LEFT_ENGINE_FIRE)
	{
		activate_ah64a_master_caution ();

		set_ah64a_upfront_display_text ("ENGINE 1 FIRE", "", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_RIGHT_ENGINE_FIRE)
	{
		activate_ah64a_master_caution ();

		set_ah64a_upfront_display_text ("ENGINE 2 FIRE", "", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_LOW_HYDRAULICS)
	{
		set_ah64a_upfront_display_text ("HYDRAULICS", "PRESSURE LOW", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_SECONDARY_HYDRAULICS)
	{
		set_ah64a_upfront_display_text ("SEC HYDRAULICS", "DAMAGED", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_STABILISER)
	{
		set_ah64a_upfront_display_text ("STABILISER", "FAILURE", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_FUEL_LEAK)
	{
		set_ah64a_upfront_display_text ("FUEL LEAK", "", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_LOW_OIL_PRESSURE)
	{
		set_ah64a_upfront_display_text ("LOW OIL", "PRESSURE", NULL, NULL);
	}

	if (damage & DYNAMICS_DAMAGE_HIGH_OIL_PRESSURE)
	{
		set_ah64a_upfront_display_text ("HIGH OIL", "PRESSURE", NULL, NULL);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
