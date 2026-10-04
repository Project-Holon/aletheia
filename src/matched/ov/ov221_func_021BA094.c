/*
 * function: func_021BA094
 * address:  0x021BA094
 * packet:   pkt_ov221_021BA094
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as func_021BA094 in ov217; the ov221 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26073.h"

struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *, int, int);

void func_021BA094(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26073 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
