#ifndef GAME_OV107_MB_UTIL_MSG_H
#define GAME_OV107_MB_UTIL_MSG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_util_msg.c, prototypes copied from their definitions. */

struct MbMsgWork;
struct MsgBank;
struct WordSet;
struct GfFont;
typedef struct MbMsgWork MbMsgWork;

#include "../types.h"

MbMsgWork *MB_UTIL_MSG_Create(u16 heapId, u32 bgFrame, u32 menuBgFrame, u32 msgFile, u32 useTalkWin, u32 cursorMode);
void MB_UTIL_MSG_Delete(MbMsgWork *work);
void MB_UTIL_MSG_Main(MbMsgWork *work);
void MB_UTIL_MSG_SetWindowLayout(MbMsgWork *work, int layout);
void MB_UTIL_MSG_PrintStream(MbMsgWork *work, int msgId, int speed);
void MB_UTIL_MSG_PrintQueued(MbMsgWork *work, int msgId);
void MB_UTIL_MSG_ClearWindow(MbMsgWork *work);
void MB_UTIL_MSG_CreateWordSet(MbMsgWork *work);
void MB_UTIL_MSG_DeleteWordSet(MbMsgWork *work);
void MB_UTIL_MSG_SetNumberLeft(MbMsgWork *work, int index, int value, int digits);
void MB_UTIL_MSG_SetNumberZeroPad(MbMsgWork *work, int index, int value, int digits);
void MB_UTIL_MSG_OpenYesNoTaskMenu(MbMsgWork *work, int layout);
void MB_UTIL_MSG_CloseTaskMenu(MbMsgWork *work);
int MB_UTIL_MSG_GetTaskMenuResult(MbMsgWork *work);
void MB_UTIL_MSG_OpenYesNoMenu(MbMsgWork *work, int unused);
void MB_UTIL_MSG_ClearYesNoMenu(MbMsgWork *work);
int MB_UTIL_MSG_ProcessYesNoMenu(MbMsgWork *work);
void MB_UTIL_MSG_PrintStreamSystemMsg(MbMsgWork *work, int speed);
struct MsgBank *MB_UTIL_MSG_GetMsgData(MbMsgWork *work);
struct WordSet *MB_UTIL_MSG_GetWordSet(MbMsgWork *work);
struct GfFont *MB_UTIL_MSG_GetFont(MbMsgWork *work);
int MB_UTIL_MSG_IsPrintQueFinished(MbMsgWork *work);
int MB_UTIL_MSG_IsStreamIdle(MbMsgWork *work);
void MB_UTIL_MSG_SetKeyWaitFlag(MbMsgWork *work, int flag);
void MB_UTIL_MSG_SetTimeIconPending(MbMsgWork *work, int pending);
/* END mkheaders: generated region */

#endif
