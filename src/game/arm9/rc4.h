#ifndef GAME_ARM9_RC4_H
#define GAME_ARM9_RC4_H

#include "../types.h"

/* RC4 stream cipher state. */

typedef struct CRYPTORC4Context
{
    u8 i;
    u8 j;
    u8 padding[2];
    u8 s[256];
} CRYPTORC4Context;

void CRYPTO_RC4Init(CRYPTORC4Context *context, void *key, u32 keyLength);

#endif
