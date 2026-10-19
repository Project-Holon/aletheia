/*
 * function: make_dn
 * address:  0x021601CC
 * packet:   pkt_ov009_021601CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      make_dn (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   (none)
 */

static void make_dn(char *d, char *s, int len)
{
    char *d0;

    d0 = d;
    if (*d != 0) {
        do
            d++;
        while (*d != 0);
        if (d - d0 >= 255)
            return;
        *d++ = ',';
        *d++ = ' ';
    }
    while (len-- != 0 && d - d0 < 255)
        *d++ = *s++;
    *d = 0;
}
