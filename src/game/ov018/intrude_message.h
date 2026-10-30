#ifndef GAME_OV018_INTRUDE_MESSAGE_H
#define GAME_OV018_INTRUDE_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_message.c, prototypes copied from their definitions. */

struct GameSystem;
struct ScriptWork;
struct GameEvent;
struct FieldMap;
struct FldMmdl;

#include "../ov018/event_comm_common_types.h"
#include "../types.h"
#include "../ov011/intrude_comm_types.h"
#include "../arm9/script_vm_types.h"

void EVENT_COMM_COMMON_InitMsgBox(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
void EVENT_COMM_COMMON_ExitMsgBox(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_SetupPrintWin(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_DeletePrintWin(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_PrintText(EventCommMsgBox *msgBox, void *text);
void EVENT_COMM_COMMON_PrintMsg(EventCommMsgBox *msgBox, u16 msgId);
void EVENT_COMM_COMMON_ClearPrintWin(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsPrintFinished(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_SetupListWindow(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_DeleteListWindow(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_PrintToWindow(EventCommMsgBox *msgBox, void *msgData, void *window, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_PrintListWindow(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_DeleteChoice(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_StartChoice(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_PollChoice(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_SetupListWindowB(EventCommMsgBox *msgBox, struct GameSystem *gameSystem, int x, int y, int width, int height);
void EVENT_COMM_COMMON_PrintListWindowB(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_DeleteListWindowB(EventCommMsgBox *msgBox);
/* END mkheaders: generated region */

#endif
