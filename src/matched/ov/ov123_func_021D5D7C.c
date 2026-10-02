/*
 * function: func_021D5D7C
 * address:  0x021D5D7C
 * packet:   pkt_021D5D7C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5CAC  0x021D5CAC  thumb
 *   func_021C5AB8  0x021C5AB8  arm  ov114
 *
 * Addresses are Black-image addresses.
 */

extern int func_021D5CAC(char *p);
extern void func_021C5AB8(void);

void func_021D5D7C(char *p)
{
    if (func_021D5CAC(p) != 0)
        func_021C5AB8();
}
