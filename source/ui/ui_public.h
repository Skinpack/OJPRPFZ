// Copyright (C) 1999-2000 Id Software, Inc.
//
#ifndef __UI_PUBLIC_H__
#define __UI_PUBLIC_H__

#define UI_API_VERSION	7

typedef struct {
	connstate_t		connState;
	int				connectPacketCount;
	int				clientNum;
	char			servername[MAX_STRING_CHARS];
	char			updateInfoString[MAX_STRING_CHARS];
	char			messageString[MAX_STRING_CHARS];
} uiClientState_t;

typedef enum {
	UI_ERROR,
	UI_PRINT,
	UI_MILLISECONDS,
	UI_CVAR_SET,
	UI_CVAR_VARIABLEVALUE,
	UI_CVAR_VARIABLESTRINGBUFFER,
	UI_CVAR_SETVALUE,
	UI_CVAR_RESET,
	UI_CVAR_CREATE,
	UI_CVAR_INFOSTRINGBUFFER,
	UI_ARGC,
	UI_ARGV,
	UI_CMD_EXECUTETEXT,
	UI_FS_FOPENFILE,
	UI_FS_READ,
	UI_FS_WRITE,
	UI_FS_FCLOSEFILE,
	UI_FS_GETFILELIST,
	UI_R_REGISTERMODEL,
	UI_R_REGISTERSKIN,
	UI_R_REGISTERSHADERNOMIP,
	UI_R_SHADERNAMEFROMINDEX,
	UI_R_CLEARSCENE,
	UI_R_ADDREFENTITYTOSCENE,
	UI_R_ADDPOLYTOSCENE,
	UI_R_ADDLIGHTTOSCENE,
	UI_R_RENDERSCENE,
	UI_R_SETCOLOR,
	UI_R_DRAWSTRETCHPIC,
	UI_UPDATESCREEN,
	UI_CM_LERPTAG,
	UI_CM_LOADMODEL,
	UI_S_REGISTERSOUND,
	UI_S_STARTLOCALSOUND,
	UI_KEY_KEYNUMTOSTRINGBUF,
	UI_KEY_GETBINDINGBUF,
	UI_KEY_SETBINDING,
	UI_KEY_ISDOWN,
	UI_KEY_GETOVERSTRIKEMODE,
	UI_KEY_SETOVERSTRIKEMODE,
	UI_KEY_CLEARSTATES,
	UI_KEY_GETCATCHER,
	UI_KEY_SETCATCHER,
	UI_GETCLIPBOARDDATA,
	UI_GETGLCONFIG,
	UI_GETCLIENTSTATE,
	UI_GETCONFIGSTRING,
	UI_LAN_GETPINGQUEUECOUNT,
	UI_LAN_CLEARPING,
	UI_LAN_GETPING,
	UI_LAN_GETPINGINFO,
	UI_CVAR_REGISTER,
	UI_CVAR_UPDATE,
	UI_MEMORY_REMAINING,
	UI_GET_CDKEY,
	UI_SET_CDKEY,
	UI_VERIFY_CDKEY,
	UI_R_REGISTERFONT,
	UI_R_FONT_STRLENPIXELS,
	UI_R_FONT_STRLENCHARS,
	UI_R_FONT_STRHEIGHTPIXELS,
	UI_R_FONT_DRAWSTRING,
	UI_LANGUAGE_ISASIAN,
	UI_LANGUAGE_USESSPACES,
	UI_ANYLANGUAGE_READCHARFROMSTRING,
	UI_R_MODELBOUNDS,
	UI_PC_ADD_GLOBAL_DEFINE,
	UI_PC_LOAD_SOURCE,
	UI_PC_FREE_SOURCE,
	UI_PC_READ_TOKEN,
	UI_PC_SOURCE_FILE_AND_LINE,
	UI_PC_LOAD_GLOBAL_DEFINES,
	UI_PC_REMOVE_ALL_GLOBAL_DEFINES,

	UI_S_STOPBACKGROUNDTRACK,
	UI_S_STARTBACKGROUNDTRACK,
	UI_REAL_TIME,
	UI_LAN_GETSERVERCOUNT,
	UI_LAN_GETSERVERADDRESSSTRING,
	UI_LAN_GETSERVERINFO,
	UI_LAN_MARKSERVERVISIBLE,
	UI_LAN_UPDATEVISIBLEPINGS,
	UI_LAN_RESETPINGS,
	UI_LAN_LOADCACHEDSERVERS,
	UI_LAN_SAVECACHEDSERVERS,
	UI_LAN_ADDSERVER,
	UI_LAN_REMOVESERVER,
	UI_CIN_PLAYCINEMATIC,
	UI_CIN_STOPCINEMATIC,
	UI_CIN_RUNCINEMATIC,
	UI_CIN_DRAWCINEMATIC,
	UI_CIN_SETEXTENTS,
	UI_R_REMAP_SHADER,
	UI_LAN_SERVERSTATUS,
	UI_LAN_GETSERVERPING,
	UI_LAN_SERVERISVISIBLE,
	UI_LAN_COMPARESERVERS,

	UI_MEMSET = 100,
	UI_MEMCPY,
	UI_STRNCPY,
	UI_SIN,
	UI_COS,
	UI_ATAN2,
	UI_SQRT,
	UI_MATRIXMULTIPLY,
	UI_ANGLEVECTORS,
	UI_PERPENDICULARVECTOR,
	UI_FLOOR,
	UI_CEIL,

	UI_TESTPRINTINT,
	UI_TESTPRINTFLOAT,

	UI_ACOS,
	UI_ASIN,

	UI_SP_GETNUMLANGUAGES,
	UI_SP_GETLANGUAGENAME,
	UI_SP_GETSTRINGTEXTSTRING = 200,

/*
Ghoul2 Insert Start
*/
	UI_G2_LISTSURFACES,
	UI_G2_LISTBONES,
	UI_G2_SETMODELS,
	UI_G2_HAVEWEGHOULMODELS,
	UI_G2_GETBOLT,
	UI_G2_GETBOLT_NOREC,
	UI_G2_GETBOLT_NOREC_NOROT,
	UI_G2_INITGHOUL2MODEL,
	UI_G2_COLLISIONDETECT,
	UI_G2_COLLISIONDETECTCACHE,
	UI_G2_CLEANMODELS,
	UI_G2_ANGLEOVERRIDE,
	UI_G2_PLAYANIM,
	UI_G2_GETBONEANIM,
	UI_G2_GETBONEFRAME, //trimmed down version of GBA, so I don't have to pass all those unused args across the VM-exe border
	UI_G2_GETGLANAME,
	UI_G2_COPYGHOUL2INSTANCE,
	UI_G2_COPYSPECIFICGHOUL2MODEL,
	UI_G2_DUPLICATEGHOUL2INSTANCE,
	UI_G2_HASGHOUL2MODELONINDEX,
	UI_G2_REMOVEGHOUL2MODEL,
	UI_G2_ADDBOLT,
	UI_G2_SETBOLTON,
	UI_G2_SETROOTSURFACE,
	UI_G2_SETSURFACEONOFF,
	UI_G2_SETNEWORIGIN,

	UI_G2_GETTIME,
	UI_G2_SETTIME,

/*
	//rww - RAGDOLL_BEGIN
*/
	UI_G2_SETRAGDOLL,
	UI_G2_ANIMATEG2MODELS,
/*
	//rww - RAGDOLL_END
*/

	//rww - ik move method, allows you to specify a bone and move it to a world point (within joint constraints)
	//by using the majority of gil's existing bone angling stuff from the ragdoll code.
	UI_G2_SETBONEIKSTATE,
	UI_G2_IKMOVE,

	UI_G2_GETSURFACENAME,
	UI_G2_SETSKIN,
	UI_G2_ATTACHG2MODEL,
/*
Ghoul2 Insert End
*/
} uiImport_t;

enum {
	UIMENU_NONE,
	UIMENU_MAIN,
	UIMENU_INGAME,
	UIMENU_PLAYERCONFIG,
	UIMENU_TEAM,
	UIMENU_POSTGAME,
	UIMENU_PLAYERFORCE,
	UIMENU_SIEGEMESSAGE,
	UIMENU_SIEGEOBJECTIVES,
	UIMENU_VOICECHAT,
	UIMENU_CLOSEALL,
	//[CoOp]
	UIMENU_CLASSSEL,
	UIMENU_BRIEFING			//briefing menus
	//UIMENU_CLASSSEL
	//[/CoOp]
};
typedef int uiMenuCommand_t;

#define SORT_HOST			0
#define SORT_MAP			1
#define SORT_CLIENTS		2
#define SORT_GAME			3
#define SORT_PING			4

typedef enum {
	UI_GETAPIVERSION = 0,	// system reserved

	UI_INIT,
//	void	UI_Init( void );

	UI_SHUTDOWN,
//	void	UI_Shutdown( void );

	UI_KEY_EVENT,
//	void	UI_KeyEvent( int key );

	UI_MOUSE_EVENT,
//	void	UI_MouseEvent( int dx, int dy );

	UI_REFRESH,
//	void	UI_Refresh( int time );

	UI_IS_FULLSCREEN,
//	qboolean UI_IsFullscreen( void );

	UI_SET_ACTIVE_MENU,
//	void	UI_SetActiveMenu( uiMenuCommand_t menu );

	UI_CONSOLE_COMMAND,
//	qboolean UI_ConsoleCommand( int realTime );

	UI_DRAW_CONNECT_SCREEN,
//	void	UI_DrawConnectScreen( qboolean overlay );
	UI_HASUNIQUECDKEY,
// if !overlay, the background will be drawn, otherwise it will be
// overlayed over whatever the cgame has drawn.
// a GetClientState syscall will be made to get the current strings

	UI_MENU_RESET
} uiExport_t;

#endif
