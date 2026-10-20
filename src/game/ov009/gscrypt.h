#ifndef GAME_OV009_GSCRYPT_H
#define GAME_OV009_GSCRYPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gscrypt.c, prototypes copied from their definitions. */

#include "../ov175/auth_types.h"
#include "../types.h"

int gsCryptRSAVerifySignedHash(const gsCryptRSAKey *publicKey, const u8 *hash, u32 hashLen, const u8 *sig, u32 sigLen);
/* END mkheaders: generated region */

#endif
