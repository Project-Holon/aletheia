#ifndef GAME_ARM9_ITEM_GFX_H
#define GAME_ARM9_ITEM_GFX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of item_gfx.c, prototypes copied from their definitions. */

#include "../types.h"

u32 ITEM_GFX_IsFlagClear(const u8 *bits, u32 index);
u16 ITEM_GFX_GetItemId(u32 row);
u32 ITEM_GFX_GetExtraValue(u32 itemId);
u32 ITEM_GFX_GetRowIndex(u32 itemId);
/* END mkheaders: generated region */

#endif
