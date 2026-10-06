/*
 * function: func_021B9B50
 * address:  0x021B9B50
 * packet:   pkt_021B9B50
 * region:   ov224
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
#include "../include/Obj26111.h"

struct Bank;
typedef unsigned int   u32;
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *, int, int);

void func_021B9B50(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26111 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
