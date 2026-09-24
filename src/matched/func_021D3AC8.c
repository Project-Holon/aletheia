/*
 * function: func_021D3AC8
 * address:  0x021D3AC8
 * packet:   pkt_021D3AC8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D3AC8 0x021D3AC8 arm
 *
 * Wake the sound system when idle, select port 3 and run the 0x021D3200 script.
 * Addresses are Black-image addresses.
 */

extern void func_02088234(void);
extern int func_0208F43C(int);
extern int func_021D29C8(int);

int func_021D3AC8(void)
{
    int *g = (int *)0x021DE660;

    if (*(int *)(g[1] + 0x40) != 1)
        func_02088234();
    func_021D29C8(3);
    if (func_0208F43C((int)0x021D3200) == 2)
        return 1;
    func_021D29C8(9);
    return 0;
}

