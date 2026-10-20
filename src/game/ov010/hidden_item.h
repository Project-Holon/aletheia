#ifndef GAME_OV010_HIDDEN_ITEM_H
#define GAME_OV010_HIDDEN_ITEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hidden_item.c, prototypes copied from their definitions. */

struct EventWork;
struct HiddenItemEntry;
typedef struct HiddenItemEntry HiddenItemEntry;

#include "../types.h"

u16 HIDDEN_ITEM_GetIndex(u32 scriptId);
u16 HIDDEN_ITEM_GetFlag(u16 scriptId);
void HIDDEN_ITEM_Respawn(struct EventWork *eventWork);
const HiddenItemEntry *HIDDEN_ITEM_GetTable(unsigned short *count);
/* END mkheaders: generated region */

#endif
