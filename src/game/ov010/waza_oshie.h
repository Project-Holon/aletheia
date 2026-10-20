#ifndef GAME_OV010_WAZA_OSHIE_H
#define GAME_OV010_WAZA_OSHIE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of waza_oshie.c, prototypes copied from their definitions. */

#include "../types.h"

void *WAZA_OSHIE_Create(u32 heapId);
u32 WAZA_OSHIE_Delete(void *work);
u16 *WAZA_OSHIE_CreateMoveList(void *mon, u32 heap);
int WAZA_OSHIE_IsListEntryValid(u16 *p);
/* END mkheaders: generated region */

#endif
