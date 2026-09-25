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

extern void func_02006448(int, int, int);

void func_021F9664(char *p, int a)
{
    *(int *)(p + 0x24) = 1;
    func_02006448(*(int *)(p + 0x1dc), *(int *)(p + 0x1e0), a);
}
