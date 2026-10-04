/*
 * function: func_021FC5E0
 * address:  0x021FC5E0
 * packet:   pkt_021FC5E0
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 */

struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *, int, int);

void func_021FC5E0(void *p)
{
    func_0204B1CC((struct Bank *)(*(int *)p));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
