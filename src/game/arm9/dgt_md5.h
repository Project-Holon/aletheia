#ifndef GAME_ARM9_DGT_MD5_H
#define GAME_ARM9_DGT_MD5_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dgt_md5.c, prototypes copied from their definitions. */

#include "../sdk_math.h"
#include "../types.h"

void MATH_MD5Init(MATHMD5Context *context);
void MATH_MD5Update(MATHMD5Context *context, const void *input, u32 length);
void MATH_MD5GetHash(MATHMD5Context *context, void *digest);
/* END mkheaders: generated region */

#endif
