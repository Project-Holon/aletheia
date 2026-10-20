#ifndef GAME_ARM9_G3IMM_H
#define GAME_ARM9_G3IMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3imm.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"
#include "../sdk_fx.h"

void G3_LoadMtx44(const void *m);
void G3_LoadMtx43(const void *m);
void G3_MultMtx44(const void *m);
void G3_MultMtx43(const void *m);
void G3_MultMtx33(const void *m);
void G3_MultTransMtx33(const MtxFx33 *mtx, const VecFx32 *trans);
/* END mkheaders: generated region */

#endif
