#ifndef GAME_ARM9_GF_OVERLAY_H
#define GAME_ARM9_GF_OVERLAY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gf_overlay.c, prototypes copied from their definitions. */

struct OverlaySlot;

#include "../types.h"

void GF_OVERLAY_Init(u32 heapId, int mainCount, int itcmCount, int twlCount);
void GF_OVERLAY_ReleaseSlot(struct OverlaySlot *slot);
void GF_OVERLAY_Unload(s32 handle);
int GF_OVERLAY_Load(s32 handle);
int GF_OVERLAY_CheckRangeFree(s32 handle);
void *GF_OVERLAY_GetSlots(int area);
u8 GF_OVERLAY_GetSlotCount(int area);
int GF_OVERLAY_GetArea(u32 id);
int GF_OVERLAY_GetRamRange(u32 id, u32 *start, u32 *end);
/* END mkheaders: generated region */

#endif
