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

#include "graphics.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX_INTERNAL_SCREENS	8192

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen
	screen_array[MAX_INTERNAL_SCREENS];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static screen
	video_screen_structure;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen
	*video_screen,
	*active_screen;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void destroy_all_screens ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_system_graphics_screens ( void )
{

	int
		count;

	for ( count = 0; count < MAX_INTERNAL_SCREENS; count++ )
	{

		screen_array[count].used = FALSE;
	}

	register_exit_function ( destroy_all_screens );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen * get_free_screen ( void )
{

	int
		count;

	for ( count = 0; count < MAX_INTERNAL_SCREENS; count++ )
	{

		if ( !screen_array[count].used )
		{
			screen_array[count].used = TRUE;

			return ( &screen_array[count] );
		}
	}

	debug_fatal ( "Unable to create a free screen" );

	return ( NULL );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen * create_user_texture_screen ( int width, int height, int type, int number_of_mipmaps )
{

	screen
		*this_screen;

	ASSERT ( width );
	ASSERT ( height );
	ASSERT ( video_screen );

	this_screen = get_free_screen ();

	f3d_texture_create ( this_screen, width, height, number_of_mipmaps, TEXTURE_MAP_ALPHA(type) ? TEXTURE_ROLE_DYNAMIC_RGBA : TEXTURE_ROLE_DYNAMIC_RGBX );

	return ( this_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen * create_system_texture_screen ( int width, int height, int texture_index, int type )
{

	screen
		*this_screen;

	ASSERT ( width );
	ASSERT ( height );
	ASSERT ( video_screen );

	this_screen = get_free_screen ();

	create_system_indexed_texture_map ( this_screen, width, height, texture_index, ( enum TEXTURE_MAP_TYPES ) type );

	return ( this_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen *create_user_3dvisual_texture_screen ( int width, int height, int type )
{

	screen
		*this_screen;

	ASSERT ( width );
	ASSERT ( height );
	ASSERT ( video_screen );

	this_screen = get_free_screen ();

	f3d_texture_create ( this_screen, width, height, 1, TEXTURE_ROLE_RENDER_TARGET );

	return ( this_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_system_texture_screen ( screen *this_screen, int texture_index )
{

	ASSERT ( texture_index >= 0 );

	system_textures[texture_index] = this_screen;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen * get_screen_of_system_texture ( int texture_index )
{

	ASSERT ( video_screen );

	return ( system_textures[texture_index] );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL destroy_screen ( screen *this_screen )
{
#ifdef DEBUG
	int
		count;

	for ( count = 0; count < number_of_system_textures; count++ )
	{
		if ( system_textures[count] == this_screen )
		{
			system_textures[count] = NULL;
		}
		if ( backup_system_textures[count] == this_screen )
		{
			debug_fatal ( "Attempt to destroy required texture %s", system_texture_names[count] );
		}
	}
#endif

	f3d_texture_release ( this_screen );

	this_screen->used = FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void create_video_screen ( int width, int height )
{
	video_screen_structure.width = width;

	video_screen_structure.height = height;

	video_screen_structure.role = TEXTURE_ROLE_RENDER_TARGET;

	video_screen_structure.texture = NULL;

	video_screen = &video_screen_structure;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL lock_screen ( screen *this_screen )
{
	f3d_texture_lock ( this_screen, 0 );

	return ( this_screen->data != NULL );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL unlock_screen ( screen *this_screen )
{
	return f3d_texture_unlock ( this_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL set_active_screen ( screen *this_screen )
{

	ASSERT ( this_screen );

	active_screen = this_screen;

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

screen * get_active_screen ( void )
{

	ASSERT ( active_screen );

	return ( active_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_screen_pitch ( screen *this_screen )
{

	ASSERT ( this_screen );
	ASSERT ( this_screen->data );

	return ( this_screen->pitch );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned * get_screen_data ( screen *this_screen )
{

	ASSERT ( this_screen );
	ASSERT ( this_screen->data );

	return this_screen->data;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_screen_width ( screen *this_screen )
{

	ASSERT ( this_screen );

	return ( this_screen->width );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_screen_height ( screen *this_screen )
{

	ASSERT ( this_screen );

	return ( this_screen->height );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_screen_locked ( screen *this_screen )
{

	ASSERT ( this_screen );

	return ( this_screen->data != NULL );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void clear_screen ( void )
{
	f3d_clear_screen ( 0 );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int set_3d_render_target ( screen *this_screen )
{
	return f3d_set_3d_render_target ( this_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void finalise_3d_render_target_texture ( screen *this_screen )
{
	f3d_stop_3d_render_target ( this_screen );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_block ( int x1, int y1, int x2, int y2, rgb_colour colour )
{
	ASSERT ( active_screen );
	ASSERT ( active_screen->data );
	ASSERT ( x2 >= x1 );
	ASSERT ( y2 >= y1 );
	ASSERT ( x1 >= 0 && y1 >= 0 );
	ASSERT ( ( unsigned ) x2 < active_screen->width );
	ASSERT ( ( unsigned ) y2 < active_screen->height );

	{
		//
		// Perform the blit using the CPU
		//

		int
			x,
			y,
			pitch;

		unsigned
			*ptr;

		pitch = get_screen_pitch ( active_screen );

		ptr = get_screen_data ( active_screen );

		{
			unsigned int
				*line;

			for ( y = y1; y <= y2; y++ )
			{
				line = ptr + ( y * pitch ) + x1;

				for ( x = x1; x <= x2; x++ )
				{
					*line++ = colour.colour;
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void destroy_all_screens ( void )
{

	int
		count,
		destroyed;

	//
	// Destroy all the direct draw surfaces - but in reverse order to their creation, as its a lot faster
	//

	destroyed = 0;

	for ( count = ( MAX_INTERNAL_SCREENS - 1 ); count >= 0; count-- )
	{

		if ( screen_array[count].used )
		{

			if ( screen_array[count].data )
			{

				unlock_screen ( &screen_array[count] );
			}

			destroy_screen ( &screen_array[count] );

			destroyed++;
		}
	}

	debug_log ( "Screens destroyed: %d", destroyed );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void release_video_screens ( void )
{
	screen
		*scr;

	debug_log ( "release_video_screens: start" );

	for ( scr = screen_array; scr != screen_array + MAX_INTERNAL_SCREENS; scr++ )
	{
		if ( scr->used )
		{
			f3d_texture_pre ( scr );
		}
	}

	debug_log ( "release_video_screens: stop" );
}

void recreate_video_screens ( void )
{
	screen
		*scr;

	debug_log ( "recreate_video_screens: start" );

	for ( scr = screen_array; scr != screen_array + MAX_INTERNAL_SCREENS; scr++ )
	{
		if ( scr->used )
		{
			f3d_texture_post ( scr );
		}
	}

	debug_log ( "recreate_video_screens: stop" );
}
#endif
