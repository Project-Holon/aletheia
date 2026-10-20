#ifndef GAME_OV097_VS_MULTI_LIST_H
#define GAME_OV097_VS_MULTI_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vs_multi_list.c, prototypes copied from their definitions. */

struct Proc;
struct VsMultiListArgs;
struct VsMultiList;
struct TcbTask;

#include "../types.h"

int VS_MULTI_LIST_ProcInit(struct Proc *proc, int seq, struct VsMultiListArgs *args);
int VS_MULTI_LIST_ProcMain(struct Proc *proc, int *seq, int unused, struct VsMultiList *work);
int VS_MULTI_LIST_ProcExit(struct Proc *proc);
int VS_MULTI_LIST_StateSetup(struct VsMultiList *work);
int VS_MULTI_LIST_StateTeardown(struct VsMultiList *work);
int VS_MULTI_LIST_StateWaitWipe(struct VsMultiList *work);
int VS_MULTI_LIST_StateWaitFrames(struct VsMultiList *work);
int VS_MULTI_LIST_StateSlideIn(struct VsMultiList *work);
int VS_MULTI_LIST_StartWipeIn(struct VsMultiList *work, int nextState);
int VS_MULTI_LIST_StartWipeOut(struct VsMultiList *work, int nextState);
int VS_MULTI_LIST_EnterWaitState(struct VsMultiList *work, int count, int result);
void VS_MULTI_LIST_SetVramBanks(void);
void VS_MULTI_LIST_InitBgs(void);
void VS_MULTI_LIST_ExitBgs(void);
void VS_MULTI_LIST_LoadBgGraphics(struct VsMultiList *work);
void VS_MULTI_LIST_CreateTextResources(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteTextResources(struct VsMultiList *work);
void VS_MULTI_LIST_AddVBlankTask(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteVBlankTask(struct VsMultiList *work);
void VS_MULTI_LIST_VBlankCallback(struct TcbTask *tcb, void *work);
void VS_MULTI_LIST_InitMons(struct VsMultiList *work);
void VS_MULTI_LIST_CreateWindows(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteWindows(struct VsMultiList *work);
void VS_MULTI_LIST_UpdatePrintQueue(struct VsMultiList *work);
void VS_MULTI_LIST_PrintName(struct VsMultiList *work, int slot);
void VS_MULTI_LIST_PrintLevel(struct VsMultiList *work, u32 slot);
void VS_MULTI_LIST_PrintHp(struct VsMultiList *work, int slot);
void VS_MULTI_LIST_DrawHpDivider(struct VsMultiList *work, unsigned slot);
void VS_MULTI_LIST_InitIcons(struct VsMultiList *work);
void VS_MULTI_LIST_ExitIcons(struct VsMultiList *work);
void VS_MULTI_LIST_InitClact(void);
void VS_MULTI_LIST_ExitClact(void);
void VS_MULTI_LIST_LoadIconResources(struct VsMultiList *work);
void VS_MULTI_LIST_ReleaseIconResources(struct VsMultiList *work);
void VS_MULTI_LIST_CreateActors(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteActors(struct VsMultiList *work);
void VS_MULTI_LIST_MoveActorX(struct VsMultiList *work, unsigned actor, int dx);
void VS_MULTI_LIST_MoveSlotActors(struct VsMultiList *work, unsigned firstSlot, int dx);
void VS_MULTI_LIST_CreateBgFrames(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteBgFrames(struct VsMultiList *work);
/* END mkheaders: generated region */

#endif
