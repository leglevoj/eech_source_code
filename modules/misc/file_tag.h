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

// NB. ALL SYSTEM TAGS ARE NEGATIVE

enum SYSTEM_FILE_TAGS
{

	FILE_TAG_INVALID 				= -1,

	FILE_TAG_BIND_KEY				= -2,
	FILE_TAG_CALCULATE			= -3,
	FILE_TAG_CALL					= -4,
	FILE_TAG_CREATE_EVENT		= -5,
	FILE_TAG_CREATE_TRIGGER		= -6,
	FILE_TAG_CREATE_VARIABLE	= -7,
	FILE_TAG_ECHO_MESSAGE		= -8,
	FILE_TAG_ELSE					= -9,
	FILE_TAG_END					= -10,
	FILE_TAG_END_EVENT			= -11,
	FILE_TAG_ENDIF					= -12,
	FILE_TAG_END_WHILE			= -13,
	FILE_TAG_EVENT					= -14,
	FILE_TAG_FILENAME				= -15,
	FILE_TAG_FLOAT					= -16,
	FILE_TAG_IF						= -17,
	FILE_TAG_INT					= -18,
	FILE_TAG_KEY_CODE				= -19,
	FILE_TAG_KEY_MODIFIER		= -20,
	FILE_TAG_KEY_STATE			= -21,
	FILE_TAG_LET					= -22,
	FILE_TAG_PATH					= -23,
	FILE_TAG_SET_VARIABLE		= -24,
	FILE_TAG_START					= -25,
	FILE_TAG_TYPE					= -26,
	FILE_TAG_VALUE					= -27,
	FILE_TAG_VARIABLE				= -28,
	FILE_TAG_UNICODE				= -29,
	FILE_TAG_WHILE					= -30,

	FILE_TAG_UNKNOWN				= -30
};

typedef enum SYSTEM_FILE_TAGS system_file_tags;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum FILE_TAG_OPERATORS
{

	FILE_TAG_EQUALS,
	FILE_TAG_LESS_THAN,
	FILE_TAG_GREATER_THAN,
	NUM_FILE_TAGS
};

typedef enum FILE_TAG_OPERATORS file_tag_operators;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FILE_TAG_VARIABLE_TYPE
{

	char
		*name;

	int
		id,
		*variable;

	struct FILE_TAG_VARIABLE_TYPE
		*next;
};

typedef struct FILE_TAG_VARIABLE_TYPE file_tag_variable_type;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern const char
	*system_tag_strings [];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_file_tag_system (void);

extern void deinitialise_file_tag_system (void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SET FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void set_file_tag (FILE *file_ptr, const char *application_nums [], int tag);

extern void set_file_int (FILE *file_ptr, int value);

extern void set_file_float (FILE *file_ptr, float value);

extern void set_file_string (FILE *file_ptr, const char *string);

extern void set_file_enum (FILE *file_ptr, const char *enum_strings [], int enum_value);

extern void set_file_new_line (FILE *file_ptr, int count);

extern void set_file_comment (FILE *file_ptr, const char *string);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GET FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern int get_file_tag (const char *line, const char *application_enums [], int last_application_enum);

extern int get_next_file_tag (FILE *file_ptr, const char *application_enums [], int last_application_enum);

extern int check_next_file_tag (FILE *file_ptr, const char *application_enums [], int last_application_enum);

extern int get_next_file_int (FILE *file_ptr);

extern float get_next_file_float (FILE *file_ptr);

extern int get_next_file_paragraph (FILE *file_ptr, char *buffer, int size);

extern int get_next_file_string (FILE *file_ptr, char *buffer, int size);

extern int get_next_file_word (FILE *file_ptr, char *buffer, int size);

extern int get_next_file_enum (FILE *file_ptr, const char *enum_strings [], int last_enum);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void register_file_tag_variable (const char *variable_name, int *variable);

extern void unregister_file_tag_variable (const char *variable_name);

extern int *get_file_tag_variable (const char *variable_name);

extern int if_file_tag_variable (const char *variable_name, const char *operator_, int value);

extern int if_file_tag_operator (int value1, const char *operator_, int value2);

extern int set_file_tag_variable (const char *variable_name, int value);

extern int get_variable_id (const char *name);

extern int get_operator_id (const char *name);

extern const char *get_variable_name (int id);

extern char get_operator_name (int id);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
