/*
 * function: func_021D1D04
 * address:  0x021D1D04
 * packet:   pkt_021D1D04
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D1D04 0x021D1D04 arm
 *
 * Publish the object, initialise the tail region, and clear its two control words.
 * Addresses are Black-image addresses.
 */

extern void func_021D298C(int);

void func_021D1D04(int x)
{
    int *g = (int *)0x021DE65C;

    g[0] = x;
    func_021D298C(x + 0x160 + 0x1b000);
    *(int *)(g[0] + 0x1b000 + 0x140) = 0;
    *(int *)(g[0] + 0x1b000 + 0x144) = 0;
}

