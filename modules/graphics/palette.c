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



#if 0
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "graphics.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PALETTEENTRY
	application_colour_table[256];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_application_palette ( const char *filename )
{

	short int
		width,
		height;

	int
		bits;

	if ( load_tga_file ( filename, &width, &height, &bits ) )
	{

		int
			count;

		for ( count = 0; count < 256; count ++ )
		{

			application_colour_table[count].peRed = tga_image_palette[count].peRed;
			application_colour_table[count].peGreen = tga_image_palette[count].peGreen;
			application_colour_table[count].peBlue = tga_image_palette[count].peBlue;
		}
	}
	else
	{

		debug_fatal ( "Error during initialise_application_palette %s", filename );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_best_colour_table_entry ( int red, int green, int blue )
{

	int
		count,
		match;

	float
		distance,
		temp,
		rd,
		bd,
		gd,
		r,
		g,
		b,
		colour_r,
		colour_g,
		colour_b;

	match = -1;
	distance = 256 * 256 * 256;

	r = ( ( float ) red );
	g = ( ( float ) green );
	b = ( ( float ) blue );

	for ( count = 0; count < 256; count++ )
	{

		colour_r = ( ( float ) application_colour_table[count].peRed );

		colour_g = ( ( float ) application_colour_table[count].peGreen );

		colour_b = ( ( float ) application_colour_table[count].peBlue );

		rd = r - colour_r;	//red - application_colour_table[count].peRed;

		gd = g - colour_g;	//green - application_colour_table[count].peGreen;

		bd = b - colour_b;	//blue - application_colour_table[count].peBlue;

		temp = ( rd * rd ) + ( gd * gd ) + ( bd * bd );

		if ( temp < distance )
		{

			distance = temp;

			match = count;
		}
	}

//	debug_log ( "Best distance: %d", distance );

	return ( match );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
