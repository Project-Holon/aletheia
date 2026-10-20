#ifndef GAME_OV010_TOWN_MAP_SPOT_H
#define GAME_OV010_TOWN_MAP_SPOT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of town_map_spot.c, prototypes copied from their definitions. */

struct Rec;
struct Pos;

#include "../types.h"

int TOWN_MAP_SPOT_Classify(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);
int TOWN_MAP_SPOT_CountVisited(void *spots, void *position, u8 *unlockMask);
/* END mkheaders: generated region */

#endif
