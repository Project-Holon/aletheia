#ifndef GAME_ARM9_DGT_HMAC_H
#define GAME_ARM9_DGT_HMAC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dgt_hmac.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_math.h"

void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length, MATHiHMACFuncs *funcs);
/* END mkheaders: generated region */

#endif
