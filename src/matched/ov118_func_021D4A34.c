/*
 * function: func_021D4A34
 * address:  0x021D4A34
 * packet:   pkt_ov118_021D4A34
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D49F4  0x021D49F4  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02051774(void *);
extern void func_02051A2C(void *, unsigned int);
extern void func_02051A24(void *, void (*)(void));
extern void func_021D49F4(void);

void func_021D4A34(void *p)
{
    func_02051A2C(p, func_02051774(p));
    func_02051A24(p, func_021D49F4);
}
