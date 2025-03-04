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

extern void set_2d_pixel (float x, float y, const rgb_colour col);

extern void draw_2d_line (float x1, float y1, float x2, float y2, const rgb_colour col);

extern void draw_2d_dash_line(float x1, float y1, float x2, float y2, const rgb_colour col1, rgb_colour col2, float length, int thick);

//extern void draw_2d_thick_line (float x1, float y1, float x2, float y2, const rgb_colour col);

extern void draw_2d_half_thick_line (float x1, float y1, float x2, float y2, const rgb_colour col);

extern void draw_2d_filled_triangle (float x1, float y1, float x2, float y2, float x3, float y3, const rgb_colour col);

extern void set_2d_mono_font_position (float x, float y);

extern void get_2d_world_position (const float x, const float y, float *x_world, float *y_world);

extern void get_2d_int_screen_coordinates (const float wx, const float wy, int *x, int *y);

extern void get_2d_float_screen_coordinates (float wx, float wy, float *x, float *y);

extern void get_2d_float_screen_x_coordinate (const float wx, float *x);

extern void get_2d_float_screen_y_coordinate (const float wy, float *y);

extern void draw_2d_mono_sprite (const char *sprite_ptr, float x, float y, const rgb_colour colour);

extern void draw_2d_circle (float x, float y, const float r, const rgb_colour col);

extern void draw_2d_arc (float x, float y, const float r, unsigned part, const rgb_colour colour);

extern void draw_2d_hatched_area (float x1, float y1, float x2, float y2, const rgb_colour col);

extern void draw_2d_hatched_circle (float x, float y, const float r, const rgb_colour col);

extern void draw_2d_box(float x1_c, float y1_c, float x2_c, float y2_c, int filled, int thick_border, rgb_colour colour);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
