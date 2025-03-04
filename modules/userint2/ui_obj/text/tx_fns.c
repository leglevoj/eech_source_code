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

#include "userint2.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void set_text_ui_object_function (ui_object *obj, void (*function) (ui_object *obj, void *arg))
{
	
	text_ui_object
		*text;

	text = (text_ui_object *) obj->data;

	text->area.function = function;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static FUNCTION get_text_ui_object_function (ui_object *obj)
{
	
	text_ui_object
		*text;

	text = (text_ui_object *) obj->data;

	return (text->area.function);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void set_text_ui_object_right_function (ui_object *obj, void (*function) (ui_object *obj, void *arg))
{
	
	text_ui_object
		*text;

	text = (text_ui_object *) obj->data;

	text->area.right_function = function;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static FUNCTION get_text_ui_object_right_function (ui_object *obj)
{
	
	text_ui_object
		*text;

	text = (text_ui_object *) obj->data;

	return (text->area.right_function);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void call_text_ui_object_function (ui_object *obj, void *arg)
{

	void
		((*function) (ui_object *object, void *arg));
	
	text_ui_object
		*text;

	ui_object
		*notify_obj,
		*list_parent;

	int
		mouse_state,
		mouse_graphic_state;

	text = (text_ui_object *) obj->data;

	function = text->area.function;

	if (function)
	{

		//set_ui_object_redraw (obj, TRUE);
		{

			ui_object
				*temp_obj;
	
			temp_obj = obj;
	
			while (temp_obj)
			{
	
				set_ui_object_redraw (temp_obj, TRUE);

				if (!get_ui_object_clear (temp_obj))
				{
	
					break;
				}
	
				temp_obj = get_ui_object_parent (temp_obj);
			}
		}

		if ((int) arg == BUTTON_STATE_DOWN)
		{

			set_ui_object_state (obj, UI_OBJECT_STATE_ON);
		}
		else 
		{
			
			set_ui_object_state (obj, UI_OBJECT_STATE_OFF);
		}

		//
		// if list text get lists notify type
		//

		list_parent = get_ui_object_parent (obj);

		notify_obj = obj;

		if (list_parent->type == UI_TYPE_LIST_BOX)
		{

			notify_obj = list_parent;
		}

		if
			(
				(get_ui_object_notify_on (notify_obj) == (int) arg) ||
				(get_ui_object_notify_on (notify_obj) == NOTIFY_TYPE_BUTTON_EITHER)
			)
		{

			mouse_state = get_mouse_on ();

			mouse_graphic_state = get_mouse_graphic_on ();

//			set_mouse_off ();

			ui_repaint ();

			function (obj, (void *) arg);
		}

//		if (mouse_state)
//		{
//
//			set_mouse_on ();
//		}
//
//		if (mouse_graphic_state)
//		{
//
//			set_mouse_graphic_on ();
//		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void call_text_ui_object_right_function (ui_object *obj, void *arg)
{

	void
		((*function) (ui_object *object, void *arg));
	
	text_ui_object
		*text;

	text = (text_ui_object *) obj->data;

	function = text->area.right_function;

	if (function)
	{

		set_ui_object_redraw (obj, TRUE);

		if ((int) arg == BUTTON_STATE_DOWN)
		{

			set_ui_object_state (obj, UI_OBJECT_STATE_ON);
		}
		else 
		{
			
			set_ui_object_state (obj, UI_OBJECT_STATE_OFF);
		}

		if (
				(get_ui_object_notify_on (obj) == (int) arg) ||
				(get_ui_object_notify_on (obj) == NOTIFY_TYPE_BUTTON_EITHER)
			)
		{

			ui_repaint ();

			function (obj, (void *) arg);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_text_ui_object_function_functions (ui_object_types type)
{

	fn_set_ui_object_function [type] 			= set_text_ui_object_function;

	fn_get_ui_object_function [type] 			= get_text_ui_object_function;

	fn_set_ui_object_right_function [type]		= set_text_ui_object_right_function;

	fn_get_ui_object_right_function [type]		= get_text_ui_object_right_function;

	fn_call_ui_object_function [type]			= call_text_ui_object_function;

	fn_call_ui_object_right_function [type]	= call_text_ui_object_right_function;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
