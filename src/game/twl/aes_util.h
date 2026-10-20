#ifndef GAME_TWL_AES_UTIL_H
#define GAME_TWL_AES_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of aes_util.c, prototypes copied from their definitions. */

#include "../types.h"

void AESi_InitRand(void);
u32 AESi_Rand(u8 *dst, u32 size);
int AESi_SignForJpeg(u8 *sign, u32 data, u32 length);
int AESi_VerifySignForJpeg(u8 *sign, u32 data, u32 length);
/* END mkheaders: generated region */

#endif
