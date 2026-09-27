/*
 * function: func_0202FAB4
 * address:  0x0202FAB4
 * packet:   pkt_0202FAB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   pending
 *
 * TwlSDK CRYPTO_RC4Init, `libcrypto.TWL.HYB.a(rc4.o)`, recovered at
 * src/pending/func_0202FAB4.c by symbol table (layout/symbols_sdk.json,
 * arm9) + DWARF from the SDK archive.  Body reproduced faithfully: the
 * declaration order, the signed/unsigned widths and the exact variable set
 * come out of the member's DWARF (rc4.c:34, params context/key/key_len,
 * locals d/id1/id2/i/tmp).  Verdict is SIZE (~124 compiled against 128
 * original) under every front end and spelling tried: the prime suspect is
 * that the branch-5_3 archive is Release-profile code while the shipped
 * image holds the Debug-profile object (the Debug member's *structure* is
 * this function, but its own arithmetic still does not match, so a C
 * spelling has not been reached).  Not filed as EXACT; see below.
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u8 i;
    u8 j;
    u8 padd[2];
    u8 s[256];
} CRYPTORC4Context;

void func_0202FAB4(CRYPTORC4Context *d, const void *key, u8 key_len)
{
    u8 id1;
    u8 id2;
    u8 *d2;
    int i;
    u8 tmp;

    if (key_len > 16)
        key_len = 16;

    d->i = 0;
    d->j = 0;
    d2 = d->s;
    for (i = 0; i < 256; i++)
        d2[i] = i;

    id1 = 0;
    id2 = 0;
    for (i = 0; i < 256; i++) {
        tmp = d2[i];
        id2 = id2 + tmp + ((const u8 *)key)[id1];
        id1 = id1 + 1;
        if (id1 == key_len)
            id1 = 0;
        d2[i] = d2[id2];
        d2[id2] = tmp;
    }
}
