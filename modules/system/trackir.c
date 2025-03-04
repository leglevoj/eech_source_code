//**********************************************************************
//	Filename:	TrackIR.c
//	Authors:	Lukas "Retro" Friembichler
//	Date:		31Jan2005
//
//	Description:	Hooks up my TrackIR.dll (whose code is not allowed to
//					go into the repo :( and sets up access functions.
//
//					See the functions for further comments
//
//					For this stuff to work you need the TRACKIR.DLL
//					located in the /setup/cohokum folder to be placed
//					in the same directory as the executable. Maybe it also
//					works if you put it in the DLL search path but I have
//					not tried this (in fact I barely know what I am talking
//					about here.. so do not play the hero.. )
//*********************************************************************/
#include "system.h"
#include "cmndline.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Typedefs for the functions imported from the DLL. Enables some minimal type checking..
	//

typedef int (__cdecl *PF_NP_INITTRACKIR)( HWND );
typedef void (__cdecl *PF_NP_EXITTRACKIR)( void );

typedef int (__cdecl *PF_NP_GETVERSION)( void );

typedef int (__cdecl *PF_NP_QUERYTIRACTIVE)( void );
typedef void (__cdecl *PF_NP_POLL)( void );

typedef int (__cdecl *PF_NP_GETYAW)( void );
typedef int (__cdecl *PF_NP_GETPITCH)( void );
typedef int (__cdecl *PF_NP_GETROLL)( void );
typedef int (__cdecl *PF_NP_GETX)( void );
typedef int (__cdecl *PF_NP_GETY)( void );
typedef int (__cdecl *PF_NP_GETZ)( void );

typedef void (__cdecl *PF_NP_SETTIMEOUT)( unsigned int );
typedef void (__cdecl *PF_NP_SETMAXXY) ( unsigned int );
typedef unsigned int (__cdecl *PF_NP_GETMAXXY) ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// The functions themselves.. static as I do not need them outside this file..
	//

static PF_NP_INITTRACKIR		gpfNP_InitTrackIR = NULL;
static PF_NP_EXITTRACKIR		gpfNP_ExitTrackIR = NULL;

static PF_NP_GETVERSION			gpfNP_GetVersion = NULL;	// Only one DLL exists right now, which returns 1

static PF_NP_QUERYTIRACTIVE		gpfNP_QueryTIRActive = NULL;
static PF_NP_POLL				gpfNP_Poll = NULL;

static PF_NP_GETYAW				gpfNP_GetYaw = NULL;
static PF_NP_GETPITCH			gpfNP_GetPitch = NULL;
static PF_NP_GETROLL			gpfNP_GetRoll = NULL;
static PF_NP_GETX				gpfNP_GetX = NULL;
static PF_NP_GETY				gpfNP_GetY = NULL;
static PF_NP_GETZ				gpfNP_GetZ = NULL;

static PF_NP_SETMAXXY			gpfNP_SetMaxXY = NULL;
static PF_NP_GETMAXXY			gpfNP_GetMaxXY = NULL;

static PF_NP_SETTIMEOUT			gpfNP_SetTimeout = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Handle to library and status bit..
	//

static HMODULE modTrackIR = NULL;
static BOOL dllLoadedOK = FALSE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Right.. let's init this thing.. load the library and try to set up the exported functions. Once this is done successfully,
	// start the TrackIR. This will register the game with the NP software so that it can load the proper module
	//

void __cdecl InitTrackIR()
{
	modTrackIR = LoadLibrary("TRACKIR.DLL");

	gpfNP_InitTrackIR  =	(PF_NP_INITTRACKIR)GetProcAddress( modTrackIR, "InitTrackIR" );
	gpfNP_ExitTrackIR =		(PF_NP_EXITTRACKIR)GetProcAddress( modTrackIR, "ExitTrackIR" );

	gpfNP_GetVersion =		(PF_NP_GETVERSION)GetProcAddress( modTrackIR, "TIR_GetVersion" );

	gpfNP_QueryTIRActive =	(PF_NP_QUERYTIRACTIVE)GetProcAddress( modTrackIR, "query_TIR_active" );
	gpfNP_Poll =			(PF_NP_POLL)GetProcAddress( modTrackIR, "TIR_Poll" );

	gpfNP_GetYaw =			(PF_NP_GETYAW)GetProcAddress( modTrackIR, "TIR_GetYaw" );
	gpfNP_GetPitch =		(PF_NP_GETPITCH)GetProcAddress( modTrackIR, "TIR_GetPitch" );
	gpfNP_GetRoll =			(PF_NP_GETROLL)GetProcAddress( modTrackIR, "TIR_GetRoll" );
	gpfNP_GetX =			(PF_NP_GETX)GetProcAddress( modTrackIR, "TIR_GetX" );
	gpfNP_GetY =			(PF_NP_GETY)GetProcAddress( modTrackIR, "TIR_GetY" );
	gpfNP_GetZ =			(PF_NP_GETZ)GetProcAddress( modTrackIR, "TIR_GetZ" );
	gpfNP_SetTimeout =		(PF_NP_SETTIMEOUT)GetProcAddress( modTrackIR, "TIR_SetTimeout" );

	gpfNP_SetMaxXY =		(PF_NP_SETMAXXY)GetProcAddress( modTrackIR, "TIR_SetMaxXY" );
	gpfNP_GetMaxXY =		(PF_NP_GETMAXXY)GetProcAddress( modTrackIR, "TIR_GetMaxXY" );

	// Yuck..
	if ((gpfNP_InitTrackIR == NULL)||(gpfNP_ExitTrackIR == NULL)||
		(gpfNP_GetVersion == NULL)||
		(gpfNP_QueryTIRActive == NULL)||(gpfNP_Poll == NULL)||
		(gpfNP_GetYaw == NULL)||(gpfNP_GetPitch == NULL)||(gpfNP_GetRoll == NULL)||
		(gpfNP_GetX == NULL)||(gpfNP_GetY == NULL)||(gpfNP_GetZ == NULL)||
		(gpfNP_SetTimeout == NULL)||
		(gpfNP_SetMaxXY == NULL)||(gpfNP_GetMaxXY == NULL))
	{
		FreeLibrary(modTrackIR);
		return;
	}

	//
	// Returns FALSE if NP Gui not started, path to NP DLL not found etc..
	//

	if (gpfNP_InitTrackIR(application_window) == FALSE)
	{
		FreeLibrary(modTrackIR);
		return;
	}

	gpfNP_SetTimeout(300);	// 300 frames without TIR input will cause it to disable itself.. this is 10 seconds @ 30fps..

	dllLoadedOK = TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Unregisters the TIR with the NP software, and frees the DLL.. you really should not call any TIR functions after this !!
	//

void __cdecl ExitTrackIR()
{
	if (dllLoadedOK == FALSE)
		return;

	gpfNP_ExitTrackIR();
	FreeLibrary(modTrackIR);

	dllLoadedOK = FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Queries the DLL if the TIR receives updates. Will result 0 if
	//
	// 1) User has disabled the interface
	// 2) User has paused the interface
	// 3) User has moved outside the tracker FOV
	//
	// You can configure the time the TIR waits till it disables itself in case 3) above by calling the gpNP_SetTimeout() function
	//

int __cdecl query_TIR_active()
{
	if (dllLoadedOK == FALSE)
		return 0;
	
	if (!gpfNP_QueryTIRActive())
		return 0;
	
	// ENABLED BUT NOT USED
	if (command_line_TIR_idle && (float)gpfNP_GetYaw() == 0.0 && (float)gpfNP_GetPitch() == 0.0)
		return 0;

	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Specifies the number of _FRAMES_ the TIR will wait before it disables itself because of lack of input. This may happen
	// because the user moved out of the trackers FOV. E.g. a value of 300 for a waitingtime of 10 seconds at 30FPS.
	// Of course this ASSumes that you poll once per frame.
	//
	// The DLL defaults to 100 frames
	//

void TIR_SetTimeout(unsigned int frames)
{
	if (dllLoadedOK == FALSE)
		return;

	gpfNP_SetTimeout(frames);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Polls the TIR device. Should be called once per frame, if it is not called at all then all axisvalues will be 0
	//

void TIR_Poll()
{
	if (dllLoadedOK == FALSE)
		return;

	gpfNP_Poll();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Retrieves max +-16383 or 0 if axis is disabled
	//

float TIR_GetYaw()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetYaw();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Retrieves max +-16383 or 0 if axis is disabled
	//

float TIR_GetPitch()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetPitch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Retrieves max +-16383 or 0 if axis is disabled
	//

float TIR_GetRoll()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetRoll();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// TrackIR 6DOF mode
	// The value range of the additional axis (x/y/z) is +-16383
	//
	// HOWEVER this is the whole FOV of the TIR receiver and it is VERY easy
	// to move the head out of its FOV.. in that case the TIR gets crazy and
	// reports bogus data.. hence it is possible to limit (clamp) this value
	// in my DLL and scale on that value.. this value should be > 0 and <= 16383
	//

void TIR_SetMaxXY(const unsigned int value)
{
	if (dllLoadedOK == FALSE)
		return;

	gpfNP_SetMaxXY(value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Retrieves the current maximum value for X and Y axis.
	//

float TIR_GetMaxXY()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetMaxXY();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Left/Right, clamped to maxvalue..
	//

float TIR_GetX()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetX();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Up/Down, clamped to maxvalue..
	//

float TIR_GetY()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetY();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Forward/Backward, clamped to maxvalue..
	//

float TIR_GetZ()
{
	if (dllLoadedOK == FALSE)
		return 0.f;

	return (float)gpfNP_GetZ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Compatibility function to work with 1.6.1W4 code.. deprecated with 6DOF
	//

int __cdecl GetYaw()
{
	if (dllLoadedOK == FALSE)
		return 0;

	gpfNP_Poll();
	return gpfNP_GetYaw();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	// Compatibility function to work with 1.6.1W4 code.. deprecated with 6DOF
	//

int __cdecl GetPitch()
{
	if (dllLoadedOK == FALSE)
		return 0;

	gpfNP_Poll();
	return gpfNP_GetPitch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






