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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "maths.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double dbound ( double value, double min, double max )
{

	if ( value < min )
	{

		return ( min );
	}

	if ( value > max )
	{

		return ( max );
	}

	return ( value );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ibound ( int value, int min, int max )
{

	if ( value < min )
	{

		return ( min );
	}

	if ( value > max )
	{

		return ( max );
	}

	return ( value );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int uibound ( unsigned int value, unsigned int min, unsigned int max )
{

	if ( value < min )
	{

		return ( min );
	}

	if ( value > max )
	{

		return ( max );
	}

	return ( value );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float fast_modf ( float value, float *iptr )
{

	int
		whole_value;

	convert_float_to_int ( value, &whole_value );

	value -= whole_value;

	*iptr = ( float ) whole_value;

	return ( value );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float frac ( float value )
{
	//
	// takes a floating point value, and returns only the fractional part
	//
	
	float
		dummy;

	return fast_modf ( value, &dummy );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int log_base_2 (int val)
{
	//
	// if y = 2^x, returns x for given y
	//

	int
		result;

	result = 0;

	while (val >>= 1)
	{
		result += 1;
	}

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modify_angle ( float *angle, float target, float rate )
{
	float
		l,
		n,
		d;

	ASSERT ( rate >= 0.0f );

	for ( l = fabs ( target - *angle ); ; *angle = n, l = d )
	{
		n = *angle < target ? *angle + PI2 : *angle - PI2;
		d = fabs ( target - n );
		if ( d >= l )
		{
			break;
		}
	}

	if ( rate > l )
	{
		rate = l;
	}

	*angle = *angle > target ? *angle - rate : *angle + rate;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

