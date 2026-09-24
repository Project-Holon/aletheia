/*
 * function: func_021EF4C0
 * address:  0x021EF4C0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Push tag rows 0x20 for six entries; element (i*3+2) is a
 *   signed char.  The counter is UNSIGNED or the image's blo becomes blt.
 */


extern void func_0202CB4C(char *, int, int, signed char);
void func_021EF4C0(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(p, i, 0x20, (signed char)(i * 3 + 2));
}
