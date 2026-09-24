/*
 * function: func_021DF128
 * address:  0x021DF128
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC000  0x021EC000  thumb  ov170
 *
 * Seat the six 0x13 entries.
 */



extern void func_021EC000(int, unsigned, int);
void func_021DF128(int p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_021EC000(p, i + 0x13, 0);
}
