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

//
// Special type of vec3d, needed for sharing point normals
//

struct OBJECT_3D_POINT
{

	float
		x,
		y,
		z;
};

typedef struct OBJECT_3D_POINT object_3d_point;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Compressed object point. This is a master stroke!
//

struct OBJECT_SHORT_3D_POINT
{

	short int
		x,
		y,
		z;
};

typedef struct OBJECT_SHORT_3D_POINT object_short_3d_point;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_HEADING_PITCH_NORMAL
{
	/** 
	 *  normal encoded as a pitch / heading angle offset measured from a 
	 *  vector pointing along x axis.
	 *  The angles are stored as an index into a 256-elemnt table with
	 *  radians from -PI to PI for heading; -PI/2 to +PI/2 for pitch
	 * 
	 *  So for heading 0 = -PI, 255 = PI and 128 = 0 radians
	 */

	unsigned char
		heading,
		pitch;
};

typedef struct OBJECT_3D_HEADING_PITCH_NORMAL object_3d_heading_pitch_normal;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_TRANSFORMED_3D_POINT
{

	float
		x,
		y;
};

typedef struct OBJECT_TRANSFORMED_3D_POINT object_transformed_3d_point;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_TRANSFORMED_2D_POINT
{

	float
		i,
		j,
		q,
		z;
};

typedef struct OBJECT_TRANSFORMED_2D_POINT object_transformed_2d_point;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_POINT_NORMAL
{

	short int
		x,
		y,
		z;
};

typedef struct OBJECT_3D_POINT_NORMAL object_3d_point_normal;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_TRANSFORMED_POINT_NORMAL
{

	union
	{
	
		struct
		{
	
			unsigned char
				b,
				g,
				r,
				alpha;
		};
	
		unsigned int
			colour;
	};

	float
		specular;
};

typedef struct OBJECT_3D_TRANSFORMED_POINT_NORMAL object_3d_transformed_point_normal;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_SHORT_TEXTURED_POINT
{

	float
//	short int
		u,
		v;
};

typedef struct OBJECT_3D_SHORT_TEXTURED_POINT object_3d_short_textured_point;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct POINT_3D_TEXTURED_REFERENCE
{

	unsigned int

		//
		// Reference number of transformed point ( index number )
		//
	
		point;

	float

		//
		// Texture map coordinates for this face point
		//

		u,
		v;
};

typedef struct POINT_3D_TEXTURED_REFERENCE point_3d_textured_reference;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct POINT_3D_PLAIN_REFERENCE
{

	unsigned short int

		//
		// Reference number of transformed point ( index number )
		//
	
		point;
};

typedef struct POINT_3D_PLAIN_REFERENCE point_3d_plain_reference;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct POINT_3D_SHORT_REFERENCE
{

	unsigned char
		point;
};

typedef struct POINT_3D_SHORT_REFERENCE point_3d_short_reference;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SURFACE_TEXTURE_INFORMATION
{

	unsigned short int
		animation:1,
		filtered:1,
		mipmapped:1,
		wrapper:1,
		light_map:1;

	unsigned short int
		index;
};

typedef struct SURFACE_TEXTURE_INFORMATION surface_texture_information;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FACE_SURFACE_DESCRIPTION
{

	union
	{

		struct
		{

			unsigned short int
				polygons:1,
				detail:1,
				smoothed:1,
				textured:1,
				has_luminosity_texture:1,
				additive:1,
				translucent:1,
				luminous:1,
				has_specularity:1,
				texture_animation:1,
				texture_filtered:1,
				texture_mipmapped:1,
				texture_wrapped_u:1,
				texture_wrapped_v:1;

			unsigned char
				luminosity_texture_animation:1,
				luminosity_texture_filtered:1,
				luminosity_texture_mipmapped:1,
				luminosity_texture_wrapped_u:1,
				luminosity_texture_wrapped_v:1;

			unsigned char
				number_of_points;  // 0 = is 256 points (since it makes no sense for a surface to have no points)
		};
	
		unsigned int
			surface_flags;
	};

	unsigned short int
		texture_index,
		luminosity_texture_index,
		number_of_faces;

	union
	{

		struct
		{

			unsigned char
				reflectivity,
				specularity;
		};

		unsigned short int
			additional_surface_information;
	};

	union
	{
	
		struct
		{
		
			unsigned char
				blue,
				green,
				red,
				alpha;
		};

		unsigned int
			colour;
	};
};

typedef struct FACE_SURFACE_DESCRIPTION face_surface_description;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_FACE
{

	unsigned char 

		//
		// Number of points in the face.
		//

		number_of_points;

//		//
//		// Flags, designating the type of face ( textured, shaded, etc )
//		//
//
//		flags;
};

typedef struct OBJECT_3D_FACE object_3d_face;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_INFO
{

	struct VEC3D
		*normals;

	struct LIGHT_3D_SOURCE
		*lights;

	vec3d
		camera_position,
		camera_direction;

	int
		object_number;

	int
		points_base;

	struct VIEWPOINT
		*object_vp;
};

typedef	struct OBJECT_3D_INFO object_3d_info;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_BOUNDS
{

	float
		xmin,
		xmax,
		ymin,
		ymax,
		zmin,
		zmax;
};

typedef struct OBJECT_3D_BOUNDS object_3d_bounds;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D
{

	unsigned short int
		number_of_points,
		number_of_faces,
		number_of_point_normals,
		number_of_surfaces,
		number_of_lighting_normals,
//		number_of_surface_points,					//  given by number of faces, and faces list
//		number_of_surface_point_normals,			//
//		number_of_surface_texture_points,		//      same as number of surface points if a textured surface
		culling_normals_offset;

	float
		radius;

	object_3d_bounds
		bounding_box;

	object_3d_bounds
		bounding_box2;

	object_short_3d_point
		*points;

	struct OBJECT_3D_FACE
		*faces;

//	float
//		*culling_factors;

	object_3d_heading_pitch_normal
		*point_normals;

//	object_3d_point_normal
//		*point_normals;

	/* All the points of the faces in the same order (i.e. first all the points
	 * of face 0, then all for face 1 etc.
	 * This is an index into the surface_points array which is itself an index into
	 * the points array.  The index is local to each surface (so index 1 for one 
	 * surface is a different point in the surface_point array than one for another
	 * surface).  Since it's a char each surface is limited to 256 points. */
	struct POINT_3D_SHORT_REFERENCE
		*object_faces_point_plain_list;

	struct FACE_SURFACE_DESCRIPTION
		*surfaces;

	/* Index into the point_normals array.  One normal for each face, in the order
	 * of the faces in surfaces */
	struct POINT_3D_PLAIN_REFERENCE
		*object_face_normal_references;

	/* all texture UV coordinates */
	struct OBJECT_3D_SHORT_TEXTURED_POINT
		*surface_texture_points;

	struct POINT_3D_PLAIN_REFERENCE
		*surface_points;

	/* point normals, used for smooth surfaces for calculating rounding */
	struct POINT_3D_PLAIN_REFERENCE
		*surface_point_normals;

    /* 26JUL06 Casm Import of 3D objects */
    int
        custom;
};

typedef struct OBJECT_3D object_3d;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_INSTANCE // 92 bytes
{
#ifndef OGRE_EE

	//
	// Parent pointer - this is ALWAYS NULL and *has* to be at the start of the structure to tie in with OBJECT_3D_SUB_INSTANCE
	//

	struct OBJECT_3D_SUB_INSTANCE
		*parent;

	//
	// For main objects this number is the SCENE index. For sub objects, its the actual object number.
	//

	int	//enum OBJECT_3D_INDEX_NUMBERS
		object_number;

	struct VIEWPOINT

		//
		// Object's actual position in the world
		//

		vp;

	//
	// The objects position relative to the view
	//

	vec3d
		view_position;

	//
	// The object's scale
	//

	vec3d
		relative_scale;

	unsigned int

		//
		// Flag if this object ( and its sub objects ) are visible
		//

		visible_object:1,
		requires_immediate_render:1,
		object_has_shadow:1,
		object_internal_lighting:1,
		object_dissolve_value:8,
		object_sprite_lights:1,
		object_diffuse_value:8;

	int
		*texture_animations;

  	/* array with all subobjects an object of this type has (not just immediate
  	 * sub objects,but also  children's children etc.).
  	 * Array has length of 
  	 * objects_3d_scene_database[object_number].total_number_of_sub_objects 
  	 * and is malloced individually for each object_3d_instance */
	struct OBJECT_3D_SUB_INSTANCE
		*sub_objects;
#else
	struct OgreGameObjectScene
		vp;
	struct VEC3D
		relative_scale;
	int
		object_number;
	int
		temporary;
#endif
};

typedef struct OBJECT_3D_INSTANCE object_3d_instance;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_SUB_INSTANCE // 48 bytes long
{

	//
	// Parent pointer
	//

	struct OBJECT_3D_SUB_INSTANCE
		*parent;

	struct OBJECT_3D_SUB_INSTANCE
		*sub_objects;

	unsigned int
		visible_object:1,
		requires_immediate_render:1,
		object_has_shadow:1,
		object_internal_lighting:1,
		object_dissolve_value:8;

	vec3d
		relative_position;

	float
		relative_heading,
		relative_pitch,
		relative_roll;

	vec3d
		relative_scale;
};

typedef struct OBJECT_3D_SUB_INSTANCE object_3d_sub_instance;

#ifndef OGRE_EE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TEMPORARY_OBJECT_3D_INSTANCE
{

	struct OBJECT_3D_INSTANCE
		*instance;

	struct TEMPORARY_OBJECT_3D_INSTANCE
		*next_temporary_instance;

	int
		real_object;
};

typedef struct TEMPORARY_OBJECT_3D_INSTANCE temporary_object_3d_instance;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_SURFACE_INFO
{

	union
	{

		unsigned short int
			*indices;

		struct POINT_3D_SHORT_REFERENCE
			*line_points;
	};

	int
		number_of_indices;

	unsigned short int
		start_vertex,
		number_of_vertices;

	union
	{

		void
			*vertex_buffer;
	
		struct POINT_3D_PLAIN_REFERENCE
			*surface_points;
	};
};

typedef struct OBJECT_3D_SURFACE_INFO object_3d_surface_info;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct OBJECT_3D_EXTRA_OBJECT_INFO
{

	object_3d_surface_info
		*surfaces;
};

typedef struct OBJECT_3D_EXTRA_OBJECT_INFO object_3d_extra_object_info;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TRANSLUCENT_OBJECT_SURFACE
{

	face_surface_description
		*surface;

	viewpoint
		vp;

	int
		texture_index,
		object_index,
		dissolve_value;

	union
	{

		struct
		{

			unsigned int
				clipped:1,
				lightmaps_enabled:1;
		};

		unsigned int
			flags;
	};

	vec3d
		object_3d_scale,
		object_view_position,
		object_unit_position;

	union
	{

		struct
		{
	
			object_3d_face
				*faces;
		
			point_3d_plain_reference
				*surface_point_list,
				*surface_point_normal_list;
		
			object_3d_short_textured_point
				*surface_point_texture_list;
		
			point_3d_short_reference
				*faces_point_list;
		
			point_3d_plain_reference
				*faces_normal_list;
		};

		struct
		{

			object_3d_surface_info
				*surface_info;
		};
	};

	struct TRANSLUCENT_OBJECT_SURFACE
		*succ;
};

typedef struct TRANSLUCENT_OBJECT_SURFACE translucent_object_surface;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
