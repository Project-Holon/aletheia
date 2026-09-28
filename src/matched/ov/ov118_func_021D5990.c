/*
 * function: func_021D5990
 * address:  0x021D5990
 * packet:   pkt_ov118_021D5990
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5950  0x021D5950  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02051774(void *);
extern void func_02051A2C(void *, unsigned int);
extern void func_02051A24(void *, void (*)(void));
extern void func_021D5950(void);

void func_021D5990(void *p)
{
    func_02051A2C(p, func_02051774(p));
    func_02051A24(p, func_021D5950);
}
