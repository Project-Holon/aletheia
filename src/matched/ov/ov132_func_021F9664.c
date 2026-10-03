/*
 * function: func_021F9664
 * address:  0x021F9664
 * packet:   pkt_021F9664
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006448  0x02006448  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern int func_02006448(u32 a0, u32 a1, u32 a2);

void func_021F9664(char *p, int a)
{
    *(int *)(p + 0x24) = 1;
    func_02006448(*(int *)(p + 0x1dc), *(int *)(p + 0x1e0), a);
}
