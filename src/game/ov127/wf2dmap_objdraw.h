#ifndef GAME_OV127_WF2DMAP_OBJDRAW_H
#define GAME_OV127_WF2DMAP_OBJDRAW_H

#include "../types.h"

/* Signed 16-bit pair passed by value (the same layout as Wf2dmapPos). */
struct Wf2dmapPair {
    s16 x;
    s16 y;
};

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_objdraw.c, prototypes copied from their definitions. */

struct Wf2dmapAnimSeq;
struct Wf2dmapPair;
typedef struct Wf2dmapAnimSeq Wf2dmapAnimSeq;
typedef struct Wf2dmapPair Wf2dmapPair;

#include "../types.h"

void WF2DMAP_OBJDRAW_FillSpawnDesc(u8 *out,void *p,int kind,int index,int value);
Wf2dmapAnimSeq *WF2DMAP_OBJDRAW_CreateAnimSeq(void *srcA, void *srcB, u32 count, void *palette, int animData, u32 mode, u32 heap);
void WF2DMAP_OBJDRAW_DeleteAnimSeq(u8 *p);
void WF2DMAP_OBJDRAW_DeleteSprite(void *p);
void WF2DMAP_OBJDRAW_ConfigureSprite(char *p, int a, int b);
u8 *WF2DMAP_OBJDRAW_AddActor(u8 *seq, void *resource, int variant, u32 heap);
void WF2DMAP_OBJDRAW_RemoveActor(u8 *p);
void WF2DMAP_OBJDRAW_UpdateAllActors(u8 *p);
void WF2DMAP_OBJDRAW_UpdateActor(u8 *p);
void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v);
void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *p);
void WF2DMAP_OBJDRAW_StepActorAnim(char *p);
void WF2DMAP_OBJDRAW_RestoreFrame(u8 *p);
void WF2DMAP_OBJDRAW_SetActorPos(char *p, Wf2dmapPair v);
int WF2DMAP_OBJDRAW_GetActorDrawEnable(char *p);
void WF2DMAP_OBJDRAW_SetActorDrawEnable(char *p, int a);
void WF2DMAP_OBJDRAW_SetSubActorDrawEnable(u8 *p, int a);
int WF2DMAP_OBJDRAW_GetActorDrawPriority(u8 *p);
void WF2DMAP_OBJDRAW_SetFrameZero(u8 *p, int b);
int WF2DMAP_OBJDRAW_GetDepth(int a,int b);
void WF2DMAP_OBJDRAW_SetSubActorPos(char *p, Wf2dmapPair v);
int WF2DMAP_OBJDRAW_IsActorFree(char *p);
char *WF2DMAP_OBJDRAW_AllocActor(u8 *seq);
int WF2DMAP_OBJDRAW_GetFrameValue(char *p, int b);
void WF2DMAP_OBJDRAW_GetOwnerPos(char *p,short *x,short *y);
void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int n, int a);
void WF2DMAP_OBJDRAW_SetPosFromOwner(void *p, void *q);
void WF2DMAP_OBJDRAW_ClearPos(void *p);
/* END mkheaders: generated region */

#endif
