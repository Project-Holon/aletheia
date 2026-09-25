/*
 * function: func_021F96B0
 * address:  0x021F96B0
 * packet:   pkt_021F96B0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005D90  0x02005D90  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void func_02005D90(int, int);

void func_021F96B0(char *p, int a)
{
    *(int *)(p + 0x2c) = 1;
    func_02005D90(a, 0xffff);
}
