#ifndef GAME_OV121_MYSTERY_H
#define GAME_OV121_MYSTERY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery.c, prototypes copied from their definitions. */

#include "../types.h"

int MYSTERY_Create(void *owner, u32 unused, u32 arg);
int MYSTERY_Delete(void *a, int b, int c, char *p);
int MYSTERY_Main(int a, int b, int c, char *p);
void MYSTERY_InitBgHeap(u16 *p,u16 heap);
void MYSTERY_ExitBgHeap(void *work);
void MYSTERY_SetupBg(u16 *p,int mode);
void MYSTERY_CreateClact(char *p, void *owner, u16 heap);
void MYSTERY_DeleteClact(u8 *p);
void *MYSTERY_GetClactActor(u8 *p,int i);
void MYSTERY_TransferPalette(u8 *p,int heap);
void MYSTERY_RotateActors(u8 *p);
void MYSTERY_ResetActorAngle(u8 *p);
void MYSTERY_CreateParticle(int *p, int heap);
void MYSTERY_DeleteParticle(void *p);
void MYSTERY_LoadParticle(int *p, int a, int b, int c);
int MYSTERY_StartParticle(void **p, int x);
void *MYSTERY_IsParticleCreated(u8 *p);
void MYSTERY_TaskInitSave(void *a,int b,u8 *p);
void MYSTERY_TaskFadeToMenu(void *a, int *state);
void MYSTERY_TaskExitAlbum(void *a, int *state);
void MYSTERY_TaskMenu(void *task,u32 *state,u8 *p);
void MYSTERY_TaskMenuAction(void *a, int *state, char *p);
void MYSTERY_TaskReceive(void *task,u32 *state,u8 *p);
void MYSTERY_TaskAlbum(void *task,u32 *state,u8 *p);
void MYSTERY_TaskAlbumView(void *task,u32 *state,u8 *p);
void MYSTERY_TaskNetAlbum(void *task,u32 *state,u8 *p);
void MYSTERY_TaskNetExit(void *task,u32 *state,u8 *p);
void MYSTERY_TaskCleanup(void *p,int n,char *q);
void MYSTERY_TaskMessage(void *a, int *state, u8 *p);
void MYSTERY_CreateSaveMenu(u8 *p, int unused, int heap);
void MYSTERY_DeleteSaveMenu(char *p);
void MYSTERY_CreateCardMenu(u8 *p,u32 which,int heap);
void MYSTERY_DeleteCardMenu(char *p);
int MYSTERY_PollCardMenu(char *p);
void MYSTERY_CardMenuCallback(char *p);
void MYSTERY_CreatePartyMenu(u8 *p,int heap);
void MYSTERY_DeletePartyMenu(char *p);
void MYSTERY_CreateReceivedMon(u8 *out,void *owner,const u8 *desc,void *save,void *list,void *bgHeap,void *scroll,u16 heap);
void MYSTERY_InitCardView(u8 *p,int mode);
void MYSTERY_DeleteCardView(u8 *p);
void MYSTERY_StepCardView(char *p);
int MYSTERY_IsCardViewDone(char *p);
void MYSTERY_CardViewAnimScroll(u8 *p);
void MYSTERY_CardViewAnimReveal(u8 *p);
void MYSTERY_CardViewAnimFade(u8 *p);
void MYSTERY_InitScroll(u8 *p,void *q,u16 h);
void MYSTERY_ClearScroll(void *p);
void MYSTERY_StepScroll(char *p);
void MYSTERY_StartScroll(char *p,int n);
void MYSTERY_SetScrollParam(unsigned *p,unsigned v);
void MYSTERY_UpdateScrollA(u8 *p);
void MYSTERY_UpdateScrollB(u8 *p);
void MYSTERY_CreateOamSprite(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap);
void MYSTERY_DeleteOamSprite(void **p);
int MYSTERY_PollOamSprite(char *p);
unsigned MYSTERY_MeasureGraChar(int id,int heap);
int MYSTERY_IsCardValid(char *p,int n);
void MYSTERY_SetupDisplay3d(void);
/* END mkheaders: generated region */

#endif
