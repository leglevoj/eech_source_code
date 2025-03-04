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

static void call_radio_ui_object_function (ui_object *obj, void *arg)
{

	void
		((*function) (ui_object *object, void *arg));
	
	radio_ui_object
		*radio;

	int
		mouse_state,
		mouse_graphic_state;

	radio = (radio_ui_object *) obj->data;

	function = radio->area.function;

	if (function)
	{

		set_ui_object_redraw (obj, TRUE);

		if
			(
				(get_ui_object_notify_on (obj) == (int) arg) ||
				(get_ui_object_notify_on (obj) == NOTIFY_TYPE_BUTTON_EITHER)
			)
		{

			set_ui_object_state (obj, UI_OBJECT_STATE_ON);

			mouse_state = get_mouse_on ();

			mouse_graphic_state = get_mouse_graphic_on ();

//			set_mouse_off ();

			function (obj, (void *) arg);

//			if (mouse_state)
//			{
//
//				set_mouse_on ();
//			}
//
//			if (mouse_graphic_state)
//			{
//
//				set_mouse_graphic_on ();
//			}
		}

		if ((int) arg == BUTTON_STATE_INVALID)
		{

			radio->area.state = UI_OBJECT_STATE_OFF;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void call_radio_ui_object_right_function (ui_object *obj, void *arg)
{

	void
		((*function) (ui_object *object, void *arg));
	
	radio_ui_object
		*radio;

	radio = (radio_ui_object *) obj->data;

	function = radio->area.right_function;

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

		if
			(
				(get_ui_object_notify_on (obj) == (int) arg) ||
				(get_ui_object_notify_on (obj) == NOTIFY_TYPE_BUTTON_EITHER)
			)
		{

			function (obj, (void *) arg);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_radio_ui_object_function_functions (ui_object_types type)
{

	fn_call_ui_object_function [type] 			= call_radio_ui_object_function;

	fn_call_ui_object_right_function [type] 	= call_radio_ui_object_right_function;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
