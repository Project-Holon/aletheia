/*
 * function: func_0202FAB4
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

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct CRYPTORC4Context {
    u8 i;
    u8 j;
    u8 padding[2];
    u8 s[256];
} CRYPTORC4Context;

void func_0202FAB4(CRYPTORC4Context *context, void *key, u32 key_len)
{
    u8 *d;
    u8 id1;
    u8 id2;
    int i;
    u8 tmp;

    if (key_len > 16) {
        key_len = 16;
    }
    context->i = 0;
    context->j = 0;
    d = context->s;
    for (i = 0; i < 256; i++) {
        d[i] = (u8)i;
    }
    id2 = 0;
    id1 = 0;
    for (i = 0; i < 256; i++) {
        tmp = d[i];
        id2 = (u8)(id2 + (tmp + ((u8 *)key)[id1]));
        id1++;
        if (id1 == (u8)key_len) {
            id1 = 0;
        }
        d[i] = d[id2];
        d[id2] = tmp;
    }
}
