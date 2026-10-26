#ifndef GAME_OV173_POKE_SUMMARY_ACTOR_H
#define GAME_OV173_POKE_SUMMARY_ACTOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of poke_summary_actor.c, prototypes copied from their definitions. */

#include "../types.h"

void POKE_SUMMARY_ACTOR_InitSystem(u8 *work, void *archiveHandle);
void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *work);
void POKE_SUMMARY_ACTOR_RegisterResources(char *work,void *archiveHandle);
void POKE_SUMMARY_ACTOR_TransferCharacter(void *archiveHandle,int charId,u32 memberIdx,u32 heapID,u16 heap);
void POKE_SUMMARY_ACTOR_SetMoveIcon(u8 *work, u16 id, u16 i);
void POKE_SUMMARY_ACTOR_FlushPendingTransfers(char *work);
void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *work);
void POKE_SUMMARY_ACTOR_SetMoveAnim(u8 *work, u16 id);
void POKE_SUMMARY_ACTOR_CreateActors(char *work,void *archiveHandle);
void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *work, u32 idx, int unused);
int POKE_SUMMARY_ACTOR_StartWipe(u8 *work);
int POKE_SUMMARY_ACTOR_StartProc(char *work);
int POKE_SUMMARY_ACTOR_StartNetRestart(void *work);
void POKE_SUMMARY_ACTOR_CreateSound(u8 *work);
int POKE_SUMMARY_ACTOR_UpdateSound(int *work);
void POKE_SUMMARY_ACTOR_Noop(void);
void POKE_SUMMARY_ACTOR_SelectRow(char *work,int row,int old);
void POKE_SUMMARY_ACTOR_HandleCursorInput(char *work,int i);
void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *work, int flag);
int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *work);
void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *work);
void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *work,int direction);
void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *work);
int POKE_SUMMARY_ACTOR_OpenDecideWin(char *work, u16 result);
int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *work,u16 result);
int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *work,unsigned short id);
int POKE_SUMMARY_ACTOR_WaitDecide(u8 *work);
int POKE_SUMMARY_ACTOR_ShowTextKind2(char *work);
int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *work);
void POKE_SUMMARY_ACTOR_SetSubBrightness(int enable);
/* END mkheaders: generated region */

#endif
