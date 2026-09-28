/*
 * function: encode_ct
 * address:  0x0219B810
 * packet:   pkt_ov009_0219B810
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      encode_ct (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 */

static unsigned char encode_ct(unsigned char c)
{
    if (c < 26)
        return (unsigned char)(c + 'A');
    if (c < 52)
        return (unsigned char)(c + 'G');
    if (c < 62)
        return (unsigned char)(c - 4);
    if (c == 62)
        return '+';
    if (c == 63)
        return '/';
    return 0;
}
