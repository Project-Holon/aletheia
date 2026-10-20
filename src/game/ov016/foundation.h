#ifndef GAME_OV016_FOUNDATION_H
#define GAME_OV016_FOUNDATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of foundation.c, prototypes copied from their definitions. */

#include "../ov016/dwcutil_types.h"
#include "../ov016/dwcutil_types.h"
#include "../ov016/dwcutil_types.h"

void DWCi_InputCoord(int a, int b, unsigned short *p);
void DWCi_InputRect(int a, int b, int c, int d, unsigned short *p);
void DWCi_Coord2Rect(const COORD *coord, const COORD *size, RECT *rect);
/* END mkheaders: generated region */

#endif
