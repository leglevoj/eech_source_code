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

debug_3d_object
	*debug_3d_object_list = NULL;

debug_3d_line
	*debug_3d_line_list = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_debug_3d_objects (void)
{
	ASSERT (!debug_3d_object_list);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_debug_3d_objects (void)
{
	destroy_all_debug_3d_objects ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

debug_3d_object *create_debug_3d_object (viewpoint *vp, object_3d_index_numbers object_3d_shape, float lifetime, float relative_scale)
{
	vec3d
		relative_scale_vector;

	debug_3d_object
		*new_;

	ASSERT (vp);

	ASSERT (object_3d_shape > OBJECT_3D_INVALID_OBJECT_INDEX);

	ASSERT (lifetime >= 0.0);

	new_ = (debug_3d_object *) malloc_fast_mem (sizeof (debug_3d_object));

	new_->vp = *vp;

	new_->object_3d_shape = object_3d_shape;

	new_->lifetime = lifetime;

	relative_scale_vector.x = relative_scale;
	relative_scale_vector.y = relative_scale;
	relative_scale_vector.z = relative_scale;

	new_->relative_scale = relative_scale_vector;

	new_->succ = debug_3d_object_list;

	new_->pred = NULL;

	if (new_->succ)
	{
		new_->succ->pred = new_;
	}

	debug_3d_object_list = new_;

	return (new_);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

debug_3d_object *create_rotated_debug_3d_object (vec3d *position, float heading, float pitch, float roll, object_3d_index_numbers object_3d_shape, float lifetime, float relative_scale)
{
	debug_3d_object
		*new_;

	viewpoint
		vp;

	ASSERT (position);

	ASSERT (object_3d_shape > OBJECT_3D_INVALID_OBJECT_INDEX);

	ASSERT (lifetime >= 0.0);

	vp.position = *position;

	get_3d_transformation_matrix (vp.attitude, heading, pitch, roll);

	new_ = create_debug_3d_object (&vp, object_3d_shape, lifetime, relative_scale);

	return (new_);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

debug_3d_object *create_vectored_debug_3d_object (vec3d *position, vec3d *vector, object_3d_index_numbers object_3d_shape, float lifetime, float relative_scale)
{
	debug_3d_object
		*new_;

	viewpoint
		vp;

	vec3d
		uvec;

	ASSERT (position);

	ASSERT (vector);

	ASSERT (object_3d_shape > OBJECT_3D_INVALID_OBJECT_INDEX);

	ASSERT (lifetime >= 0.0);

	if (get_3d_vector_magnitude (vector) > 0.001)
	{
		vp.position = *position;

		uvec = *vector;

		normalise_3d_vector (&uvec);

		get_matrix3x3_from_unit_vec3d (vp.attitude, &uvec);

		new_ = create_debug_3d_object (&vp, object_3d_shape, lifetime, relative_scale);
	}
	else
	{
		debug_log ("Failed to create vectored debug 3D object");

		new_ = NULL;
	}

	return (new_);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void destroy_debug_3d_object (debug_3d_object *object)
{
	ASSERT (object);

	if (object->pred)
	{
		object->pred->succ = object->succ;
	}
	else
	{
		debug_3d_object_list = object->succ;
	}

	if (object->succ)
	{
		object->succ->pred = object->pred;
	}

	free_mem (object);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void destroy_all_debug_3d_objects (void)
{
	while (debug_3d_object_list)
	{
		destroy_debug_3d_object (debug_3d_object_list);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_debug_3d_objects (viewpoint *vp, float visual_range)
{
#ifndef OGRE_EE
	debug_3d_object
		*object,
		*succ;

	object_3d_instance
		*inst3d;

	ASSERT (vp);

	ASSERT (visual_range > 0.0);

	object = debug_3d_object_list;

	while (object)
	{
		succ = object->succ;

		if (get_approx_3d_range (&vp->position, &object->vp.position) < visual_range)
		{
			inst3d = construct_temporary_3d_object (object->object_3d_shape, FALSE);

			if (inst3d)
			{
				inst3d->relative_scale = object->relative_scale;

				inst3d->vp = object->vp;

				inst3d->object_has_shadow = FALSE;

				insert_object_into_3d_scene (OBJECT_3D_DRAW_TYPE_OBJECT, inst3d);
			}
		}

		//
		// if this function is invoked more than once per frame then lifetime will expire more quickly
		//

		if (get_time_acceleration () != TIME_ACCELERATION_PAUSE)
			object->lifetime -= get_delta_time ();

		if (object->lifetime < 0.0)
		{
			destroy_debug_3d_object (object);
		}

		object = succ;
	}
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_debug_3d_lines (void)
{
	ASSERT (!debug_3d_line_list);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_debug_3d_lines (void)
{
	destroy_all_debug_3d_lines ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

debug_3d_line *create_debug_3d_line (vec3d *point1, vec3d *point2, rgb_colour colour, float lifetime)
{
	debug_3d_line
		*new_;

	ASSERT (point1);

	ASSERT (point2);

	ASSERT (lifetime >= 0.0);

	new_ = (debug_3d_line *) malloc_fast_mem (sizeof (debug_3d_line));

	new_->point1 = *point1;

	new_->point2 = *point2;

	new_->colour = colour;

	new_->lifetime = lifetime;

	new_->succ = debug_3d_line_list;

	new_->pred = NULL;

	if (new_->succ)
	{
		new_->succ->pred = new_;
	}

	debug_3d_line_list = new_;

	return (new_);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void destroy_debug_3d_line (debug_3d_line *line)
{
	ASSERT (line);

	if (line->pred)
	{
		line->pred->succ = line->succ;
	}
	else
	{
		debug_3d_line_list = line->succ;
	}

	if (line->succ)
	{
		line->succ->pred = line->pred;
	}

	free_mem (line);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void destroy_all_debug_3d_lines (void)
{
	while (debug_3d_line_list)
	{
		destroy_debug_3d_line (debug_3d_line_list);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_debug_3d_lines (viewpoint *vp, float visual_range)
{
#ifndef OGRE_EE
	debug_3d_line
		*line,
		*succ;

	ASSERT (vp);

	ASSERT (visual_range > 0.0);

	line = debug_3d_line_list;

	while (line)
	{
		succ = line->succ;

		if
		(
			(get_approx_3d_range (&vp->position, &line->point1) < visual_range) ||
			(get_approx_3d_range (&vp->position, &line->point2) < visual_range)
		)
		{
			insert_3d_line_into_3d_scene (line->colour, &line->point1, &line->point2);
		}

		//
		// if this function is invoked more than once per frame then lifetime will expire more quickly
		//

		line->lifetime -= get_delta_time ();

		if (line->lifetime < 0.0)
		{
			destroy_debug_3d_line (line);
		}

		line = succ;
	}
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
