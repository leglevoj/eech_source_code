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



#ifndef OGRE_EE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "terrain.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_3d_terrain_clipped_polygon ( vertex *poly, int triangle_outcode );

static void draw_3d_terrain_twopass_clipped_polygon ( vertex *poly, int triangle_outcode );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_colour_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_colour_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_colour_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_colour_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_colour_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{

			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_colour_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_colour_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_colour_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_colour_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{

			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_x_colour_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_colour_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_texture_z_colour_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;


	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{


			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{


			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_colour_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_colour_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_colour_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_colour_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_colour_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{

			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_colour_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_colour_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_colour_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_colour_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{

			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_x_colour_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_zy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_colour_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_texture_z_colour_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count+2].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+0].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count+0].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_xy_triangle ( fan_point_refs );
	
			poly = terrain_3d_copy_and_recolour_polygon ( poly );

			draw_3d_terrain_twopass_clipped_polygon ( poly, triangle_outcode );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_threepass_clipped_fan_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			if ( triangle_outcode )
			{
	
				clip_3d_coord = 0;

				if ( triangle_outcode & CLIP_YONDER )
				{

					poly = yonder_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
			
				if ( triangle_outcode & CLIP_HITHER )
				{
			
					poly = hither_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
			
				if ( triangle_outcode )
				{
			
					apply_perspective_to_polygon_dual_texture ( poly );
			
					poly = clip_3d_dual_texture_polygon ( poly, triangle_outcode );
			
					terrain_3d_faces_screen_clipped++;
			
					if ( !poly )
					{
			
						terrain_3d_faces_rejected++;
					}
					else
					{
				
						remove_perspective_from_polygon_dual_texture ( poly );
					}
				}
			}

			if ( poly )
			{
			
				draw_wbuffered_gouraud_coloured_distance_fogged_textured_polygon ( poly, current_terrain_type_class->texture );

				render_3d_terrain_secondary_vertex_polygon ( poly );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_threepass_clipped_fan_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;


	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		fan_point_refs[0] = point_refs[0].point;
		fan_point_refs[1] = point_refs[count+1].point;
		fan_point_refs[2] = point_refs[count+2].point;

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			clip_3d_coord = 0;

			if ( triangle_outcode )
			{
	
				if ( triangle_outcode & CLIP_YONDER )
				{

					poly = yonder_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}

				if ( triangle_outcode & CLIP_HITHER )
				{
			
					poly = hither_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
			
				if ( triangle_outcode )
				{
			
					apply_perspective_to_polygon_dual_texture ( poly );
			
					poly = clip_3d_dual_texture_polygon ( poly, triangle_outcode );
			
					terrain_3d_faces_screen_clipped++;
			
					if ( !poly )
					{
			
						terrain_3d_faces_rejected++;
					}
					else
					{
				
						remove_perspective_from_polygon_dual_texture ( poly );
					}
				}
			}

			if ( poly )
			{
			
				draw_wbuffered_gouraud_coloured_distance_fogged_textured_polygon ( poly, current_terrain_type_class->texture );

				render_3d_terrain_secondary_vertex_polygon ( poly );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_threepass_clipped_strip_word_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_word_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_word_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			clip_3d_coord = 0;

			if ( triangle_outcode )
			{
			
				if ( triangle_outcode & CLIP_YONDER )
				{

					poly = yonder_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
		
				if ( triangle_outcode & CLIP_HITHER )
				{
			
					poly = hither_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
			
				if ( triangle_outcode )
				{
			
					apply_perspective_to_polygon_dual_texture ( poly );
			
					poly = clip_3d_dual_texture_polygon ( poly, triangle_outcode );
			
					terrain_3d_faces_screen_clipped++;
			
					if ( !poly )
					{
			
						terrain_3d_faces_rejected++;
					}
					else
					{
				
						remove_perspective_from_polygon_dual_texture ( poly );
					}
				}
			}

			if ( poly )
			{
			
				draw_wbuffered_gouraud_coloured_distance_fogged_textured_polygon ( poly, current_terrain_type_class->texture );

				render_3d_terrain_secondary_vertex_polygon ( poly );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_threepass_clipped_strip_byte_face ( int number_of_points )
{

	vertex
		*poly;

	terrain_3d_point_byte_reference
		*point_refs;

	int
		fan_point_refs[3],
		triangle_outcode,
		count;

	point_refs = terrain_3d_sector_point_byte_references;

	terrain_3d_faces_constructed += ( number_of_points - 2 );

	for ( count = 0; count < ( number_of_points - 2 ); count++ )
	{

		if ( count & 1 )
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+2].point;
			fan_point_refs[2] = point_refs[count+1].point;
		}
		else
		{

			fan_point_refs[0] = point_refs[count].point;
			fan_point_refs[1] = point_refs[count+1].point;
			fan_point_refs[2] = point_refs[count+2].point;
		}

		terrain_3d_faces_outcoded++;
	
		if ( outcode_3d_terrain_triangle ( fan_point_refs, &triangle_outcode ) )
		{
	
			poly = construct_3d_terrain_dual_texture_triangle ( fan_point_refs );
	
			clip_3d_coord = 0;

			if ( triangle_outcode )
			{
			
				if ( triangle_outcode & CLIP_YONDER )
				{

					poly = yonder_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
		
				if ( triangle_outcode & CLIP_HITHER )
				{
			
					poly = hither_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
			
					terrain_3d_faces_hither_clipped++;
			
					if ( !poly )
					{

						triangle_outcode = 0;

						terrain_3d_faces_rejected++;
					}
				}
			
				if ( triangle_outcode )
				{
			
					apply_perspective_to_polygon_dual_texture ( poly );
			
					poly = clip_3d_dual_texture_polygon ( poly, triangle_outcode );
			
					terrain_3d_faces_screen_clipped++;
			
					if ( !poly )
					{
			
						terrain_3d_faces_rejected++;
					}
					else
					{
				
						remove_perspective_from_polygon_dual_texture ( poly );
					}
				}
			}

			if ( poly )
			{
			
				draw_wbuffered_gouraud_coloured_distance_fogged_textured_polygon ( poly, current_terrain_type_class->texture );

				render_3d_terrain_secondary_vertex_polygon ( poly );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_clipped_polygon ( vertex *poly, int triangle_outcode )
{

	if ( triangle_outcode )
	{

		clip_3d_coord = 0;

		if ( triangle_outcode & CLIP_YONDER )
		{

			poly = yonder_clip_3d_polygon ( poly, &triangle_outcode );
	
			terrain_3d_faces_hither_clipped++;
	
			if ( !poly )
			{

				triangle_outcode = 0;

				terrain_3d_faces_rejected++;
			}
		}
	
		if ( triangle_outcode & CLIP_HITHER )
		{
	
			poly = hither_clip_3d_polygon ( poly, &triangle_outcode );
	
			terrain_3d_faces_hither_clipped++;
	
			if ( !poly )
			{

				triangle_outcode = 0;

				terrain_3d_faces_rejected++;
			}
		}
	
		if ( triangle_outcode )
		{
	
			apply_perspective_to_polygon_texture ( poly );
	
			poly = clip_3d_polygon ( poly, triangle_outcode );
	
			terrain_3d_faces_screen_clipped++;
	
			if ( !poly )
			{
	
				terrain_3d_faces_rejected++;
			}
			else
			{
		
				remove_perspective_from_polygon_texture ( poly );
			}
		}
	}

	if ( poly )
	{

		draw_wbuffered_gouraud_coloured_distance_fogged_textured_polygon ( poly, current_terrain_type_class->texture );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_3d_terrain_twopass_clipped_polygon ( vertex *poly, int triangle_outcode )
{

	clip_3d_coord = 0;

	if ( triangle_outcode )
	{

		if ( triangle_outcode & CLIP_YONDER )
		{

			poly = yonder_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
	
			terrain_3d_faces_hither_clipped++;
	
			if ( !poly )
			{

				terrain_3d_faces_rejected++;

				return;
			}
		}

		if ( triangle_outcode & CLIP_HITHER )
		{
	
			poly = hither_clip_3d_dual_texture_polygon ( poly, &triangle_outcode );
	
			terrain_3d_faces_hither_clipped++;
	
			if ( !poly )
			{

				terrain_3d_faces_rejected++;

				return;
			}
		}
	
		if ( triangle_outcode )
		{
	
			apply_perspective_to_polygon_dual_texture ( poly );
	
			poly = clip_3d_dual_texture_polygon ( poly, triangle_outcode );
	
			terrain_3d_faces_screen_clipped++;
	
			if ( !poly )
			{
	
				terrain_3d_faces_rejected++;

				return;
			}
			else
			{
		
				remove_perspective_from_polygon_dual_texture ( poly );
			}
		}
	}

	if ( poly )
	{

		draw_wbuffered_gouraud_coloured_distance_fogged_textured_polygon ( poly, current_terrain_type_class->texture );

		render_3d_terrain_secondary_vertex_polygon ( poly );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
