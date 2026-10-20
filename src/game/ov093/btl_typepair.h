#ifndef GAME_OV093_BTL_TYPEPAIR_H
#define GAME_OV093_BTL_TYPEPAIR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_typepair.c, prototypes copied from their definitions. */

#include "../types.h"

u16 BTL_TYPEPAIR_Make(u32 high, u32 low);
int BTL_TYPEPAIR_MakeSingle(int byte);
u8 BTL_TYPEPAIR_GetHigh(s32 word);
int BTL_TYPEPAIR_GetLow(int word);
void BTL_TYPEPAIR_Split(int word, unsigned char *high, unsigned char *low);
int BTL_TYPEPAIR_HasType(int word, int byte);
int BTL_TYPEPAIR_ShareType(int wordA, int wordB);
int BTL_TYPEPAIR_IsSingleType(int word);
/* END mkheaders: generated region */

#endif
