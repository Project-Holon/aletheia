/*
 * function: func_0217AF04
 * address:  0x0217AF04
 * packet:   pkt_0217AF04
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E54E0  0x021E54E0  thumb  ov177
 */
#include "../include/Obj03869.h"

extern void func_021E54E0(char *p);

void func_0217AF04(int *p)
{
    func_021E54E0((char *)(((struct Obj03869 *)p)->f24));
    ((struct Obj03869 *)p)->f24 = 0;
}
