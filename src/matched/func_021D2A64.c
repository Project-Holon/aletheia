/*
 * function: func_021D2A64
 * address:  0x021D2A64
 * packet:   pkt_021D2A64
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D2A64 0x021D2A64 arm
 *
 * Select port 3, poll the global tail against the table at 0x021D2AA8, then fall back.
 * Addresses are Black-image addresses.
 */

extern int func_0208F480(int, int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);

int func_021D2A64(void)
{
    int *g = (int *)0x021DE660;

    func_021D29C8(3);
    if (func_0208F480((int)0x021D2AA8, g[1]) == 2)
        return 1;
    func_021D2A44();
    func_021D29C8(9);
    return 0;
}

