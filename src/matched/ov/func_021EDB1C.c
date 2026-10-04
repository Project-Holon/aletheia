/*
 * function: func_021EDB1C
 * address:  0x021EDB1C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDAB0  0x021EDAB0  thumb  ov170
 *
 * Clear all 24 entries.
 */



extern void func_021EDAB0(char *p, int i);
void func_021EDB1C(int p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        func_021EDAB0((char *)p, i);
}
