#ifndef GAME_OV132_STA_ACT_SCRIPT_H
#define GAME_OV132_STA_ACT_SCRIPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_script.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/tcb_list.h"

void *STA_ACT_SCRIPT_Create(u32 heap, void *owner);
void STA_ACT_SCRIPT_Delete(char *p);
void STA_ACT_SCRIPT_Update(char *p);
void *STA_ACT_SCRIPT_AddScript(char *p, void *arg, int flag);
char *STA_ACT_SCRIPT_AddScriptFromTable(char *p, char *base, unsigned index, unsigned char flag);
int STA_ACT_SCRIPT_RunScript(void *unused, char *p);
u8 STA_ACT_SCRIPT_CountScripts(char *p);
void *STA_ACT_SCRIPT_AddTask(char *p, TcbFunc taskFunc, void *arg, u32 key);
void STA_ACT_SCRIPT_RemoveTask(char *p, char *node);
int STA_ACT_SCRIPT_StepTaskInt(char *p, int *out);
int STA_ACT_SCRIPT_StepTaskVec(char *p, int *out);
int STA_ACT_SCRIPT_StepTaskActor(char *p, void *out);
int STA_ACT_SCRIPT_TickSlot(char *p);
int STA_ACT_SCRIPT_SetWaitFlag(void *unused, char *p);
int STA_ACT_SCRIPT_SkipArg(void *unused, char *p);
int STA_ACT_SCRIPT_SetWaitFromArg(void *unused, u8 *p);
int STA_ACT_SCRIPT_SetRemainingWait(void *unused, u8 *p);
int STA_ACT_SCRIPT_SetPendingFlag(int unused, char *entry);
/* END mkheaders: generated region */

#endif
