/*
 * function: func_021B9AF4
 * address:  0x021B9AF4
 * packet:   pkt_021B9AF4
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj24516.h"

struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *, int, int);

void func_021B9AF4(void *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24516 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
