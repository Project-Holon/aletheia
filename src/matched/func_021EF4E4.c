/*
 * function: func_021EF4E4
 * address:  0x021EF4E4
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
 * Twin of func_021EF4C0 with the row tag 0x15.
 */


extern void func_0202CB4C(char *, int, int, signed char);
void func_021EF4E4(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(p, i, 0x15, (signed char)(i * 3 + 2));
}
