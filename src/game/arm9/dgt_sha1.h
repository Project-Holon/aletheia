#ifndef GAME_ARM9_DGT_SHA1_H
#define GAME_ARM9_DGT_SHA1_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dgt_sha1.c, prototypes copied from their definitions. */

struct MATHSHA1Context;
typedef struct MATHSHA1Context MATHSHA1Context;

#include "../types.h"

int MATHi_SetOverlayTableMode(int flag);
void MATH_SHA1Init(MATHSHA1Context *context);
void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest);
void MATH_CalcSHA1(void *digest, const void *data, u32 dataLength);
void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len);
/* END mkheaders: generated region */

typedef struct MATHSHA1Context MATHSHA1Context;

#endif
