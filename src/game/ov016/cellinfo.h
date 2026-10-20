#ifndef GAME_OV016_CELLINFO_H
#define GAME_OV016_CELLINFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cellinfo.c, prototypes copied from their definitions. */

#include "../sdk_gx.h"

void DWCi_CEINlRead(int lcd, char *file);
void DWCi_CEINlRelease(int lcd);
void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
/* END mkheaders: generated region */

#endif
