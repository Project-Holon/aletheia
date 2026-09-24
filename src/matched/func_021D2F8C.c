/*
 * function: func_021D2F8C
 * address:  0x021D2F8C
 * packet:   pkt_021D2F8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D2F8C 0x021D2F8C arm
 *
 * Query the global object's tail, then reset on anything but the ready answer.
 * Addresses are Black-image addresses.
 */

extern int func_02090BB8(int);
extern int func_021D2A44(void);

int func_021D2F8C(void)
{
    int *g = (int *)0x021DE660;

    if (func_02090BB8(g[1] + 0x1e00) == 2)
        return 1;
    func_021D2A44();
    return 0;
}

