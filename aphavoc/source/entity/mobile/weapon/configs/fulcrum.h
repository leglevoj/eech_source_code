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
		// ENTITY_SUB_TYPE_AIRCRAFT_MIG29_FULCRUM
		//
		////////////////////////////////////////////////////////////////////////////////

		#define LHS_HARDPOINT1	 		(0)
		#define RHS_HARDPOINT1 	 		(1)
		#define LHS_HARDPOINT2	 		(2)
		#define RHS_HARDPOINT2 	 		(3)
		#define LHS_HARDPOINT3	 		(4)
		#define RHS_HARDPOINT3 	 		(5)
		#define CANNON				 		(6)
		#define LHS_CHAFF_DISPENSER	(7)
		#define RHS_CHAFF_DISPENSER	(8)
		#define LHS_FLARE_DISPENSER	(7)
		#define RHS_FLARE_DISPENSER	(8)

		#define CANNON_BARREL 			(0)
		#define KAREN_PYLON 		 		(0)
		#define ALAMO_PYLON	 			(1)
		#define ARCHER_PYLON				(0)
		#define CHAFF_VECTOR	 		 	(0)
		#define FLARE_VECTOR	  			(0)

		#define NUM_CANNON_ROUNDS		(150)
		#define NUM_KAREN_MISSILES		(1)
		#define NUM_ALAMO_MISSILES		(1)
		#define NUM_ARCHER_MISSILES	(1)
		#define NUM_CHAFFS				(30)
		#define NUM_FLARES				(30)

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_MIG29_FULCRUM_1
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,	 	  												// number
				LHS_CHAFF_DISPENSER,											// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,	 	  												// number
				RHS_CHAFF_DISPENSER,											// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,	 													// number
				LHS_FLARE_DISPENSER,											// heading_depth
				FLARE_VECTOR,			  										// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,	 													// number
				RHS_FLARE_DISPENSER,											// heading_depth
				FLARE_VECTOR,			  										// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_GSH_30_1_30MM_ROUND,				// sub_type
				NUM_CANNON_ROUNDS,	 										// number
				CANNON,	  														// heading_depth
				CANNON_BARREL,			  	 									// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_CALIBRE_STRAIGHT,					// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_R_27R,	  					// sub_type
				NUM_ALAMO_MISSILES,	 				 						// number
				LHS_HARDPOINT1,												// heading_depth
				ALAMO_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_R_27R,	  					// sub_type
				NUM_ALAMO_MISSILES,	 				 						// number
				RHS_HARDPOINT1,												// heading_depth
				ALAMO_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_R_27T,	  					// sub_type
				NUM_ALAMO_MISSILES,	 				 						// number
				LHS_HARDPOINT2,												// heading_depth
				ALAMO_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_R_27T,	  					// sub_type
				NUM_ALAMO_MISSILES,	 				 						// number
				RHS_HARDPOINT2,												// heading_depth
				ALAMO_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{
				ENTITY_SUB_TYPE_WEAPON_R_73,	  					// sub_type
				NUM_ARCHER_MISSILES,	 				 						// number
				LHS_HARDPOINT3,												// heading_depth
				ARCHER_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 11
			{
				ENTITY_SUB_TYPE_WEAPON_R_73,	  					// sub_type
				NUM_ARCHER_MISSILES,	 				 						// number
				RHS_HARDPOINT3,												// heading_depth
				ARCHER_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
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
		// WEAPON_CONFIG_TYPE_MIG29_FULCRUM_2
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,	 	  												// number
				LHS_CHAFF_DISPENSER,											// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,	 	  												// number
				RHS_CHAFF_DISPENSER,											// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,	 													// number
				LHS_FLARE_DISPENSER,											// heading_depth
				FLARE_VECTOR,			  										// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,	 													// number
				RHS_FLARE_DISPENSER,											// heading_depth
				FLARE_VECTOR,			  										// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_GSH_30_1_30MM_ROUND,				// sub_type
				NUM_CANNON_ROUNDS,	 										// number
				CANNON,	  														// heading_depth
				CANNON_BARREL,			  	 									// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_SMALL_CALIBRE_STRAIGHT,					// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_KH_25MT,	  					// sub_type
				NUM_KAREN_MISSILES,	 				 						// number
				LHS_HARDPOINT2,												// heading_depth
				KAREN_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_KH_25MT,	  					// sub_type
				NUM_KAREN_MISSILES,	 				 						// number
				RHS_HARDPOINT2,												// heading_depth
				KAREN_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_KH_25MT,	  					// sub_type
				NUM_KAREN_MISSILES,	 				 						// number
				LHS_HARDPOINT1,												// heading_depth
				KAREN_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_KH_25MT,	  					// sub_type
				NUM_KAREN_MISSILES,	 				 						// number
				RHS_HARDPOINT1,												// heading_depth
				KAREN_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{
				ENTITY_SUB_TYPE_WEAPON_R_73,	  					// sub_type
				NUM_ARCHER_MISSILES,	 				 						// number
				LHS_HARDPOINT3,												// heading_depth
				ARCHER_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
			// WEAPON PACKAGE 11
			{
				ENTITY_SUB_TYPE_WEAPON_R_73,	  					// sub_type
				NUM_ARCHER_MISSILES,	 				 						// number
				RHS_HARDPOINT3,												// heading_depth
				ARCHER_PYLON,	  		 		  	 							// pitch_depth
				0,						  				 							// muzzle_depth
				FALSE,				  				 							// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),												 		// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),			  		// rotate_inhibit_velocity
				0,		 															// heading_share_mask
				0,		 		 													// pitch_share_mask
				MUZZLE_FLASH_INVALID,							 			// muzzle_flash_type
			},
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
		#undef LHS_HARDPOINT2
		#undef RHS_HARDPOINT2
		#undef LHS_HARDPOINT3
		#undef RHS_HARDPOINT3
		#undef CANNON
		#undef LHS_CHAFF_DISPENSER
		#undef RHS_CHAFF_DISPENSER
		#undef LHS_FLARE_DISPENSER
		#undef RHS_FLARE_DISPENSER

		#undef CANNON_BARREL
		#undef KAREN_PYLON
		#undef ALAMO_PYLON
		#undef ARCHER_PYLON
		#undef CHAFF_VECTOR
		#undef FLARE_VECTOR

		#undef NUM_CANNON_ROUNDS
		#undef NUM_KAREN_MISSILES
		#undef NUM_ALAMO_MISSILES
		#undef NUM_ARCHER_MISSILES
		#undef NUM_CHAFFS
		#undef NUM_FLARES
