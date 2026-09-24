/*
 * function: func_021D5D74
 * address:  0x021D5D74
 * packet:   pkt_021D5D74
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5D74 0x021D5D74 arm
 *
 * Forward five arguments plus a 16-bit index to the global-object dispatcher.
 * Addresses are Black-image addresses.
 */

extern int func_02068EA0(int, int, int, int, int, int);

int func_021D5D74(int a0, int a1, int a2, int a3, unsigned short s0, int s1)
{
    return func_02068EA0(a0, *(int *)0x021DE680 + s1 * 8, a1, a2, a3, s0);
}

