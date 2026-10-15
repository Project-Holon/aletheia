/*
 * function: db64
 * address:  0x0205EE98
 * packet:   pkt_0205EE98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      db64 (libdwcac.TWL.HYB.a(shop_usb.o))
 *
 * symbols:
 *   codetovalue                      0x0205ee28 arm
 */

typedef union tagU4B {
    unsigned long l;
    unsigned char b[4];
} tagU4B;

extern long codetovalue(unsigned char c);

int db64(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize)
{
    tagU4B u4b;
    unsigned long x;
    unsigned long base64;
    int srcmod;
    int srcmax;
    int i;
    int j;
    int k;

    x = srcsize * 3 / 4;
    if (destsize >= x) {
        srcmod = srcsize & 3;
        srcmax = srcsize - srcmod;
    } else {
        return -1;
    }
    for (i = 0; i < srcmax; i += 4) {
        base64 = 0;
        for (j = 0; j < 4; j++) {
            base64 |= codetovalue(src[i + j]) << ((3 - j) * 6);
        }
        u4b.l = base64;
        for (k = 0; k < 3; k++) {
            dest[(i / 4) * 3 + k] = u4b.b[2 - k];
        }
    }
    if (srcmod != 0) {
        base64 = 0;
        u4b.l = 0;
        for (j = 0; j < srcmod; j++) {
            base64 |= codetovalue(src[srcmax + j]) << ((3 - j) * 6);
            u4b.l |= base64;
        }
        for (k = 0; k < srcmod; k++) {
            dest[srcmax * 3 / 4 + k] = u4b.b[2 - k];
        }
    }
    return x;
}
