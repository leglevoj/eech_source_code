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



		////////////////////////////////////////////////////////////////////////////////
		//
		// ENTITY_SUB_TYPE_AIRCRAFT_OH58D_KIOWA_WARRIOR
		//
		////////////////////////////////////////////////////////////////////////////////

		#define LHS_HARDPOINT1							(KIOWA_LHS_PYLON)
		#define RHS_HARDPOINT1 							(KIOWA_RHS_PYLON)
		#define CHAFF_DISPENSER							(KIOWA_CHAFF_DISPENSER)
		#define FLARE_DISPENSER							(KIOWA_FLARE_DISPENSER)

		#define HELLFIRE_RACK								(0)
		#define STINGER_TUBES		  					(1)
		#define HYDRA70_M261_POD						(2)
		#define CHAINGUN_POD								(3)
		#define CHAFF_VECTOR								(0)
		#define FLARE_VECTOR								(0)

		#define NUM_HELLFIRE_MISSILES					(2)
		#define NUM_STINGER_MISSILES					(2)
		#define NUM_HYDRA70_ROCKETS						(7)
		#define NUM_CHAINGUN_POD_ROUNDS				(500)
		#define NUM_CHAFFS								(0)
		#define NUM_FLARES								(0)
  
		#define HYDRA_POD_PITCH_RATE					(rad (20.0))
		#define HYDRA_POD_MIN_PITCH_LIMIT			(rad (-7.5))
		#define HYDRA_POD_MAX_PITCH_LIMIT			(rad (2.45))

		#define HYDRA_POD_ROTATE_INHIBIT_VELOCITY	(knots_to_metres_per_second (100.0))

  ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_1
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_2
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_3
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_4
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_5
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_M2HB_12P7MM_ROUND,	 								// sub_type
				NUM_CHAINGUN_POD_ROUNDS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				CHAINGUN_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_CALIBRE_STRAIGHT,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_6
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_7
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_8
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_9
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_10
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_M2HB_12P7MM_ROUND,	 								// sub_type
				NUM_CHAINGUN_POD_ROUNDS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				CHAINGUN_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_CALIBRE_STRAIGHT,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_11
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_12
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_13
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_14
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_15
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_M2HB_12P7MM_ROUND,	 								// sub_type
				NUM_CHAINGUN_POD_ROUNDS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				CHAINGUN_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_CALIBRE_STRAIGHT,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_16
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_17
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114R_HELLFIRE_II,	 								// sub_type
				NUM_HELLFIRE_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_18
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92A_STINGER,	 								// sub_type
				NUM_STINGER_MISSILES,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				STINGER_TUBES,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_19
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
    ////////////////////////////////////////
    //
    // WEAPON_CONFIG_TYPE_OH58D_KIOWA_WARRIOR_20
    //
    ////////////////////////////////////////
    {
      // WEAPON PACKAGE 1
      {
        ENTITY_SUB_TYPE_WEAPON_CHAFF,               // sub_type
        NUM_CHAFFS,                             // number
        CHAFF_DISPENSER,                        // heading_depth
        CHAFF_VECTOR,                         // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                    // heading_share_mask
        0,                                    // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
      // WEAPON PACKAGE 2
      {
        ENTITY_SUB_TYPE_WEAPON_FLARE,               // sub_type
        NUM_FLARES,                           // number
        FLARE_DISPENSER,                        // heading_depth
        FLARE_VECTOR,                           // pitch_depth
        0,                                    // muzzle_depth
        FALSE,                                // make_weapon_system_ready
        FALSE,                              // rotate
        1,                                  // salvo_size
        rad (0.0),                            // heading_rate
        rad (0.0),                            // min_heading_limit
        rad (0.0),                            // max_heading_limit
        rad (0.0),                            // pitch_rate
        rad (0.0),                            // min_pitch_limit
        rad (0.0),                            // max_pitch_limit
        rad (0.0),                            // muzzle_rotate_rate
        knots_to_metres_per_second (10000.0),         // rotate_inhibit_velocity
        0,                                  // heading_share_mask
        0,                                  // pitch_share_mask
        MUZZLE_FLASH_INVALID,                   // muzzle_flash_type
      },
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,	 								// sub_type
				NUM_HYDRA70_ROCKETS,	 											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA70_M261_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				TRUE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,												// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,											// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,											// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_ROCKET,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_M2HB_12P7MM_ROUND,	 								// sub_type
				NUM_CHAINGUN_POD_ROUNDS,	 											// number
				LHS_HARDPOINT1,												// heading_depth
				CHAINGUN_POD,			  												// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,		 													// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_CALIBRE_STRAIGHT,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		#undef LHS_HARDPOINT1
		#undef RHS_HARDPOINT1
		#undef CHAFF_DISPENSER
		#undef FLARE_DISPENSER

		#undef HELLFIRE_RACK
		#undef STINGER_TUBES
		#undef HYDRA70_M261_POD
		#undef CHAINGUN_POD
		#undef CHAFF_VECTOR
		#undef FLARE_VECTOR

		#undef NUM_HELLFIRE_MISSILES
		#undef NUM_STINGER_MISSILES
		#undef NUM_STINGER_MISSILES
		#undef NUM_HYDRA70_ROCKETS
		#undef NUM_CHAFFS
		#undef NUM_FLARES

		#undef HYDRA_POD_PITCH_RATE
		#undef HYDRA_POD_MIN_PITCH_LIMIT
		#undef HYDRA_POD_MAX_PITCH_LIMIT

		#undef HYDRA_POD_ROTATE_INHIBIT_VELOCITY
