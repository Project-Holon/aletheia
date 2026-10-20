#ifndef GAME_OV177_WIFIBATTLEMATCH_UTIL_H
#define GAME_OV177_WIFIBATTLEMATCH_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_util.c, prototypes copied from their definitions. */

struct WifibattlematchUtilWork;
struct WifibattlematchMenu;
struct WifibattlematchCallback;
typedef struct WifibattlematchUtilWork WifibattlematchUtilWork;
typedef struct WifibattlematchMenu WifibattlematchMenu;
typedef struct WifibattlematchCallback WifibattlematchCallback;

#include "../ov177/wifibattlematch_menu_types.h"
#include "../types.h"

WifibattlematchUtilWork *WIFIBATTLEMATCH_UTIL_Create(int layer, int winType, unsigned short winWidth, unsigned short winHeight, int unused, int printArg, unsigned short heap);
void WIFIBATTLEMATCH_UTIL_Delete(WifibattlematchUtilWork *p);
void WIFIBATTLEMATCH_UTIL_Main(WifibattlematchUtilWork *p);
void WIFIBATTLEMATCH_UTIL_PrintMessage(WifibattlematchUtilWork *p, void *msgBank, int msgIndex, int mode);
void WIFIBATTLEMATCH_UTIL_SetMode(WifibattlematchUtilWork *p, int mode);
int WIFIBATTLEMATCH_UTIL_GetBusy(const WifibattlematchUtilWork *p);
void WIFIBATTLEMATCH_UTIL_StopTimeIcon(WifibattlematchUtilWork *p);
void WIFIBATTLEMATCH_UTIL_ClearBmp(WifibattlematchUtilWork *p);
WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_ShowMenu(const WifibattlematchMenuDesc *p, u16 heap);
WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_CreateMenu(const WifibattlematchMenuDesc *p,u8 x,u8 y,u8 width,int height,u16 heap);
void WIFIBATTLEMATCH_UTIL_DeleteMenu(WifibattlematchMenu *p);
int WIFIBATTLEMATCH_UTIL_UpdateMenu(WifibattlematchMenu *p);
WifibattlematchCallback *WIFIBATTLEMATCH_UTIL_CreateCallback(int owner, int callback, int heap);
void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p);
void WIFIBATTLEMATCH_UTIL_InvokeCallback(WifibattlematchCallback *p);
int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p);
void WIFIBATTLEMATCH_UTIL_SetCallback(WifibattlematchCallback *p, int callback);
void WIFIBATTLEMATCH_UTIL_ClearCallback(void *record);
void WIFIBATTLEMATCH_UTIL_SetRequest(s32 *record, u32 request);
void WIFIBATTLEMATCH_UTIL_CommitRequest(u32 record);
void WIFIBATTLEMATCH_UTIL_SetSaveState(int owner, int state);
/* END mkheaders: generated region */

#endif
