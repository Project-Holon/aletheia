#ifndef GAME_OV121_MYSTERY_H
#define GAME_OV121_MYSTERY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery.c, prototypes copied from their definitions. */

struct MysteryClactActor;
struct MysteryCardView;
struct GameData;
struct MysteryScroll;
typedef struct MysteryClactActor MysteryClactActor;
typedef struct MysteryCardView MysteryCardView;
typedef struct MysteryScroll MysteryScroll;

#include "../types.h"

int MYSTERY_Create(void *owner, u32 unused, u32 arg);
void MYSTERY_InitBgHeap(u16 *p,u16 heap);
void MYSTERY_ExitBgHeap(void *work);
void MYSTERY_SetupBg(u16 *p,int mode);
void MYSTERY_CreateClact(MysteryClactActor *p, void *owner, u16 heap);
void MYSTERY_DeleteClact(MysteryClactActor *p);
void *MYSTERY_GetClactActor(const MysteryClactActor *p,int i);
void MYSTERY_TransferPalette(MysteryClactActor *p,int heap);
void MYSTERY_RotateActors(MysteryClactActor *p);
void MYSTERY_ResetActorAngle(MysteryClactActor *p);
void MYSTERY_TaskFadeToMenu(void *a, int *state, void *unused2);
void MYSTERY_TaskExitAlbum(void *a, int *state, void *unused2);
void MYSTERY_CardMenuCallback(void *p);
void MYSTERY_CreateReceivedMon(MysteryCardView *out,void *owner,const u8 *desc,struct GameData *save,MysteryClactActor *list,u16 *bgHeap,MysteryScroll *scroll,u16 heap);
void MYSTERY_InitCardView(MysteryCardView *p,int mode);
void MYSTERY_DeleteCardView(MysteryCardView *p);
void MYSTERY_StepCardView(MysteryCardView *p);
int MYSTERY_IsCardViewDone(MysteryCardView *p);
void MYSTERY_CardViewAnimScroll(MysteryCardView *p);
void MYSTERY_CardViewAnimReveal(MysteryCardView *p);
void MYSTERY_CardViewAnimFade(MysteryCardView *p);
void MYSTERY_InitScroll(MysteryScroll *p,MysteryClactActor *q,u16 h);
void MYSTERY_ClearScroll(MysteryScroll *p);
void MYSTERY_StepScroll(MysteryScroll *p);
void MYSTERY_StartScroll(MysteryScroll *p,int n);
void MYSTERY_SetScrollParam(MysteryScroll *p,unsigned v);
void MYSTERY_UpdateScrollA(MysteryScroll *p);
void MYSTERY_UpdateScrollB(MysteryScroll *p);
unsigned MYSTERY_MeasureGraChar(void *id,int heap);
void MYSTERY_SetupDisplay3d(void);
/* END mkheaders: generated region */

#endif
