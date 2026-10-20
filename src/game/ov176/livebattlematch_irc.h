#ifndef GAME_OV176_LIVEBATTLEMATCH_IRC_H
#define GAME_OV176_LIVEBATTLEMATCH_IRC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of livebattlematch_irc.c, prototypes copied from their definitions. */

struct GFLNetHandle;

#include "../types.h"

void LIVEBATTLEMATCH_IRC_ShowMenu(int *p, int a);
void LIVEBATTLEMATCH_IRC_CreateWindow(char *p, int mode);
void LIVEBATTLEMATCH_IRC_DeleteWindow(int *p);
int LIVEBATTLEMATCH_IRC_PollWindowResult(int *p);
void LIVEBATTLEMATCH_IRC_SetMenuValue(int *p, int a, int b);
int LIVEBATTLEMATCH_IRC_GetMenuValue(int *p);
void LIVEBATTLEMATCH_IRC_ToggleSe(int unused, int visible);
void LIVEBATTLEMATCH_IRC_DeleteMenuRecord(int *p);
void *LIVEBATTLEMATCH_IRC_Create(int unused, u16 heap);
void LIVEBATTLEMATCH_IRC_Delete(int *p);
void LIVEBATTLEMATCH_IRC_NoOp(void *unused);
int LIVEBATTLEMATCH_IRC_CheckError(u8 *p);
int LIVEBATTLEMATCH_IRC_InitState(int *p);
int LIVEBATTLEMATCH_IRC_StartSession(unsigned *p);
void LIVEBATTLEMATCH_IRC_Exit(u32 *p);
int LIVEBATTLEMATCH_IRC_WaitExit(int *p);
int LIVEBATTLEMATCH_IRC_ResetState(int *p);
int LIVEBATTLEMATCH_IRC_EndSession(int *p);
int LIVEBATTLEMATCH_IRC_SendRegulation(int unused, int arg);
int LIVEBATTLEMATCH_IRC_TakeRegulation(char *p, void **out);
int LIVEBATTLEMATCH_IRC_SendSaveData(int unused, int arg);
int LIVEBATTLEMATCH_IRC_RecvSaveData(u8 *p,const void *q);
u32 LIVEBATTLEMATCH_IRC_SendSyncValue(int unused,int a);
int LIVEBATTLEMATCH_IRC_RecvSyncValue(u8 *p,const void *q);
void LIVEBATTLEMATCH_IRC_CreateDelivery(char *p, unsigned value);
int LIVEBATTLEMATCH_IRC_DeliveryMain(char *p);
void LIVEBATTLEMATCH_IRC_ClearState(int *p);
int LIVEBATTLEMATCH_IRC_DeliveryEnd(char *p);
void LIVEBATTLEMATCH_IRC_RecvHandler0(u32 a, void *b, void *c, u8 *p, struct GFLNetHandle *e);
void LIVEBATTLEMATCH_IRC_RecvHandler1(u32 a, void *b, void *c, u8 *p, struct GFLNetHandle *e);
void LIVEBATTLEMATCH_IRC_RecvHandler2(u32 a, void *b, void *c, u8 *p, struct GFLNetHandle *e);
void LIVEBATTLEMATCH_IRC_RecvHandler3(u32 a, void *b, void *c, u8 *p, struct GFLNetHandle *e);
int LIVEBATTLEMATCH_IRC_RecvHandler4(int a, int b);
int LIVEBATTLEMATCH_IRC_OnFilter(int a, int b);
/* END mkheaders: generated region */

#endif
