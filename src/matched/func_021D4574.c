/*
 * function: func_021D4574
 * address:  0x021D4574
 * packet:   pkt_021D4574
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D4574 0x021D4574 arm
 *
 * Enter state 1 once func_021D3250 reports ready.
 * Addresses are Black-image addresses.
 */

extern int func_021D3250(void);
extern void func_021D3AC8(void);

int func_021D4574(void)
{
    if (func_021D3250() != 1)
        return 0;
    func_021D3AC8();
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 1;
    return 1;
}
