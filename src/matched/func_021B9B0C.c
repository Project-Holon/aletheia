/*
 * function: func_021B9B0C
 * address:  0x021B9B0C
 * packet:   pkt_021B9B0C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0204B1CC(int);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *, int, int);

void func_021B9B0C(char *p)
{
    func_0204B1CC(*(int *)p);
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
