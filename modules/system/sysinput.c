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

#include "system.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LPDIRECTINPUT7
	direct_input;

input_types
	input_system_type = INPUT_INVALID;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void internal_initialise_input_system ( void );

static void generate_input_events ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_input_system ( input_types type )
{

	input_system_type = type;

	internal_initialise_input_system ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void internal_initialise_input_system ( void )
{

	HRESULT
		ret;

	//
	// We always need to create the DirectInput device - the joystick always uses it.
	//

	ret = DirectInputCreateEx ( application_instance, DIRECTINPUT_VERSION, GUID_PREFIX IID_IDirectInput7, ( LPVOID * ) &direct_input, NULL );

	if ( ret != DI_OK )
	{

		debug_fatal ( "Unable to create DirectInput" );
	}
	
	initialise_keyboard ();

	initialise_mouse ();

	register_exit_function ( deinitialise_input_system );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_input_system ( void )
{

	if ( direct_input )
	{

		deinitialise_keyboard ();

		deinitialise_mouse ();

		IDirectInput7_Release ( direct_input );

		direct_input = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DINPUT_ERROR_MESSAGE
{

	HRESULT
		error;

	char
		*error_string;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static struct DINPUT_ERROR_MESSAGE dinput_error_table[] =
{

	{ DI_NOTATTACHED, "DI_NOTATTACHED" },
	{ DI_BUFFEROVERFLOW, "DI_BUFFEROVERFLOW" },
	{ DI_PROPNOEFFECT, "DI_PROPNOEFFECT" },
	{ DI_NOEFFECT, "DI_NOEFFECT" },
	{ DI_POLLEDDEVICE, "DI_POLLEDDEVICE" },
	{ DI_DOWNLOADSKIPPED, "DI_DOWNLOADSKIPPED" },
	{ DI_EFFECTRESTARTED, "DI_EFFECTRESTARTED" },
	{ DI_TRUNCATED, "DI_TRUNCATED" },
	{ DI_TRUNCATEDANDRESTARTED, "DI_TRUNCATEDANDRESTARTED" },
	{ DIERR_OLDDIRECTINPUTVERSION, "DIERR_OLDDIRECTINPUTVERSION" },
	{ DIERR_BETADIRECTINPUTVERSION, "DIERR_BETADIRECTINPUTVERSION" },
	{ DIERR_BADDRIVERVER, "DIERR_BADDRIVERVER" },
	{ DIERR_DEVICENOTREG, "DIERR_DEVICENOTREG" },
	{ DIERR_NOTFOUND, "DIERR_NOTFOUND" },
	{ DIERR_OBJECTNOTFOUND, "DIERR_OBJECTNOTFOUND" },
	{ DIERR_INVALIDPARAM, "DIERR_INVALIDPARAM" },
	{ DIERR_NOINTERFACE, "DIERR_NOINTERFACE" },
	{ DIERR_GENERIC, "DIERR_GENERIC" },
	{ DIERR_OUTOFMEMORY, "DIERR_OUTOFMEMORY" },
	{ DIERR_UNSUPPORTED, "DIERR_UNSUPPORTED" },
	{ DIERR_NOTINITIALIZED, "DIERR_NOTINITIALIZED" },
	{ DIERR_ALREADYINITIALIZED, "DIERR_ALREADYINITIALIZED" },
	{ DIERR_NOAGGREGATION, "DIERR_NOAGGREGATION" },
	{ DIERR_OTHERAPPHASPRIO, "DIERR_OTHERAPPHASPRIO" },
	{ DIERR_INPUTLOST, "DIERR_INPUTLOST" },
	{ DIERR_ACQUIRED, "DIERR_ACQUIRED" },
	{ DIERR_NOTACQUIRED, "DIERR_NOTACQUIRED" },
	{ DIERR_READONLY, "DIERR_READONLY" },
	{ DIERR_HANDLEEXISTS, "DIERR_HANDLEEXISTS" },
	{ DIERR_INSUFFICIENTPRIVS, "DIERR_INSUFFICIENTPRIVS" },
	{ DIERR_DEVICEFULL, "DIERR_DEVICEFULL" },
	{ DIERR_MOREDATA, "DIERR_MOREDATA" },
	{ DIERR_NOTDOWNLOADED, "DIERR_NOTDOWNLOADED" },
	{ DIERR_HASEFFECTS, "DIERR_HASEFFECTS" },
	{ DIERR_NOTEXCLUSIVEACQUIRED, "DIERR_NOTEXCLUSIVEACQUIRED" },
	{ DIERR_INCOMPLETEEFFECT, "DIERR_INCOMPLETEEFFECT" },
	{ DIERR_NOTBUFFERED, "DIERR_NOTBUFFERED" },
	{ DIERR_EFFECTPLAYING, "DIERR_EFFECTPLAYING" },
	{ DI_OK, "DI_OK" }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char * get_dinput_error_message ( HRESULT error )
{

	int
		count;

	count = 0;

	while ( ( dinput_error_table[count].error != 0 ) && ( dinput_error_table[count].error != error ) )
	{

		count ++;
	}

	return ( dinput_error_table[count].error_string );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
