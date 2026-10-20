#ifndef GAME_ARM9_RC4S_ARM4CW_H
#define GAME_ARM9_RC4S_ARM4CW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of rc4s_arm4cw.c, prototypes copied from their definitions. */

#include "../arm9/rc4.h"
#include "../types.h"

void CRYPTO_RC4Encrypt(CRYPTORC4Context *context, const void *in, u32 length, void *out);
/* END mkheaders: generated region */

#endif
