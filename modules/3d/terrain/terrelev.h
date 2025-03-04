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

#define DEBUG_TERRAIN 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_3d_terrain_elevation ( void );

extern void clear_3d_terrain_point_data ( terrain_3d_point_data *point_data );

#if ( DEBUG_TERRAIN )

extern float get_3d_terrain_point_data_ex ( float x, float z, terrain_3d_point_data *point_data, const char *file, int line );

#define get_3d_terrain_point_data(X,Z,DATA) (get_3d_terrain_point_data_ex ((X), (Z), (DATA), __FILE__, __LINE__))

#else
extern float get_3d_terrain_point_data ( float x, float z, terrain_3d_point_data *point_data );
#endif

extern vec3d *get_3d_terrain_point_data_normal ( terrain_3d_point_data *point_data );

extern float get_3d_terrain_point_data_elevation ( terrain_3d_point_data *point_data );

extern terrain_types get_3d_terrain_point_data_type ( terrain_3d_point_data *point_data );

extern void terrain_elevation_soak_test ( int samples_per_sector_side );

extern void display_terrain_elevation_statistics ( void );

extern float get_3d_terrain_elevation_and_face_normal ( float x, float z, vec3d *normal, terrain_3d_point_data *point_data );

extern void get_3d_terrain_face_normal ( vec3d *normal, float x, float z );

extern void get_3d_terrain_last_normal ( vec3d *normal );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if ( DEBUG_TERRAIN )
#define get_3d_terrain_elevation(X,Z) (get_3d_terrain_point_data_ex ((X), (Z), NULL, __FILE__, __LINE__))
#else
#define get_3d_terrain_elevation(X,Z) (get_3d_terrain_point_data ((X), (Z), NULL))
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
