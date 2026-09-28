/*
 * function: func_0202FAB4
 * address:  0x0202FAB4
 * packet:   pkt_0202FAB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CRYPTO_RC4Init (libcrypto.TWL.HYB.a rc4.o)
 * notes:    38 bytes differ, register allocation only (same instruction shapes and order). The image keeps d in lr and puts (u8)key_len in a fresh register (r3) with 0 in key_len's r2; this C coalesces the mask into r2 and gives d r4. Declaration order (120 permutations), increment/compare spellings, key casts and permuter seeds 13601, 13602 did not move it.
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
    id1 = 0;
    id2 = 0;
    for (i = 0; i < 256; i++) {
        tmp = d[i];
        id2 = (u8)(id2 + (tmp + ((u8 *)key)[id1]));
        id1++;
        d[i] = d[id2];
        d[id2] = tmp;
        if (id1 == (u8)key_len) {
            id1 = 0;
        }
    }
}
