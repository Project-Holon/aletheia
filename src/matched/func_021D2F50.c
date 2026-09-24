/*
 * function: func_021D2F50
 * address:  0x021D2F50
 * packet:   pkt_021D2F50
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D2F50 0x021D2F50 arm
 *
 * Select port 6, start key sharing on the global object's tail, then reset on mismatch.
 * Addresses are Black-image addresses.
 */

extern int func_02090B9C(int, int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);

int func_021D2F50(void)
{
    int *g = (int *)0x021DE660;

    func_021D29C8(6);
    if (func_02090B9C(g[1] + 0x1e00, 0xd) == 2)
        return 1;
    func_021D2A44();
    return 0;
}

