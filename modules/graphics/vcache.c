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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "graphics.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_CACHE_STATS 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct VERTEX_CACHE_INFO
{

	int
		index,
		age;
};

typedef struct VERTEX_CACHE_INFO vertex_cache_info;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vertex_cache_info
	*vertex_cache_indices = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int
	vertex_cache_size = 2,
	number_of_vertex_cache_hits,
	number_of_vertex_cache_misses;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int index_is_in_vertex_cache ( int index );

static int get_oldest_vertex_cache_index ( void );

static void age_vertex_cache ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_vertex_cache_size ( int size )
{

	ASSERT ( size > 1 );

	if ( vertex_cache_indices )
	{

		safe_free ( vertex_cache_indices );

		vertex_cache_indices = NULL;
	}

	vertex_cache_indices = ( vertex_cache_info * ) safe_malloc ( sizeof ( vertex_cache_info ) * size );

	vertex_cache_size = size;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reset_vertex_cache_data ( void )
{

	number_of_vertex_cache_hits = 0;

	number_of_vertex_cache_misses = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void report_vertex_cache_statistics ( void )
{

#if REPORT_CACHE_STATS
	debug_log ( "Vertex cache:- Size: %d, Hits: %d, Misses: %d", vertex_cache_size, number_of_vertex_cache_hits, number_of_vertex_cache_misses );
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void assess_vertex_cache_usage ( WORD *indices, int number_of_indices )
{

	int
		count;

	for ( count = 0; count < vertex_cache_size; count++ )
	{

		vertex_cache_indices[count].index = -1;
		vertex_cache_indices[count].age = vertex_cache_size;
	}

	for ( count = 0; count < number_of_indices; count++ )
	{

		int
			index,
			cache_index;

		index = ( int ) indices[count];

		//
		// Check to see if the vertex is in the cache
		//

		cache_index = index_is_in_vertex_cache ( index );

		if ( cache_index != -1 )
		{

			age_vertex_cache ();

			vertex_cache_indices[cache_index].age = 0;

			number_of_vertex_cache_hits++;

			continue;
		}
		else
		{

			cache_index = get_oldest_vertex_cache_index ();

			age_vertex_cache ();

			vertex_cache_indices[cache_index].index = index;

			vertex_cache_indices[cache_index].age = 0;

			number_of_vertex_cache_misses++;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int index_is_in_vertex_cache ( int index )
{

	int
		count;

	for ( count = 0; count < vertex_cache_size; count++ )
	{

		if ( vertex_cache_indices[count].index == index )
		{

			return ( count );
		}
	}

	return ( -1 );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_oldest_vertex_cache_index ( void )
{

	int
		count,
		oldest_index,
		oldest_age;

	oldest_index = 0;

	oldest_age = vertex_cache_indices[0].age;

	for ( count = 1; count < vertex_cache_size; count++ )
	{

		if ( vertex_cache_indices[count].age > oldest_age )
		{

			oldest_index = count;

			oldest_age = vertex_cache_indices[count].age;
		}
	}

	return ( oldest_index );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void age_vertex_cache ( void )
{

	int
		count;

	for ( count = 0; count < vertex_cache_size; count++ )
	{

		vertex_cache_indices[count].age++;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
