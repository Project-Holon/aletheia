/*
 * unit:     no
 * function: func_020371AC
 * address:  0x020371AC
 * packet:   pkt_02037154
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469C8      0x021469C8  data
 */

extern unsigned short g_021469C8[];
void func_020371AC(unsigned short a, unsigned int b)
{
    g_021469C8[0] = a;
    g_021469C8[1] = (unsigned short)((g_021469C8[1] & ~0x3fff) | (b & 0x3fff));
}
