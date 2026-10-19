/*
 * function: has_method
 * address:  0x02160D68
 * packet:   pkt_ov009_02160D68
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      has_method (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   (none)
 */

static int has_method(unsigned char *s, int num, int size, unsigned short method)
{
    unsigned long n;
    int i;

    for (i = 0; i < num; i++) {
        n = (s[0] << 8) + s[1];
        if (size == 3)
            n = (n << 8) + s[2];
        if (n == method)
            return 1;
        s += size;
    }
    return 0;
}
