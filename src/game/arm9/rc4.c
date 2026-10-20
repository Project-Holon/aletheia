/*
 * file:     rc4.c
 * function: CRYPTO_RC4Init
 * address:  0x0202FAB4
 * packet:   pkt_0202FAB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTO_RC4Init (libcrypto.TWL.HYB.a rc4.o)
 * notes:    the key index wraps before the swap (id1++ and the compare ahead of the two stores); with the wrap after the swap the colouring rotates d, id1, id2 and tmp.
 *
 * symbols:
 *   (none)
 */

#include "../types.h"

#include "rc4.h"

void CRYPTO_RC4Init(CRYPTORC4Context *context, void *key, u32 keyLength)
{
    u8 *state;
    u8 keyIndex;
    u8 stateIndex;
    int index;
    u8 temp;

    if (keyLength > 16) {
        keyLength = 16;
    }
    context->i = 0;
    context->j = 0;
    state = context->s;
    for (index = 0; index < 256; index++) {
        state[index] = (u8)index;
    }
    stateIndex = 0;
    keyIndex = 0;
    for (index = 0; index < 256; index++) {
        temp = state[index];
        stateIndex = (u8)(stateIndex + (temp + ((u8 *)key)[keyIndex]));
        keyIndex++;
        if (keyIndex == (u8)keyLength) {
            keyIndex = 0;
        }
        state[index] = state[stateIndex];
        state[stateIndex] = temp;
    }
}
