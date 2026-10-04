/*
 * function: func_0217D174
 * address:  0x0217D174
 * packet:   pkt_0217D174
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E62A0  0x021E62A0  thumb  ov177
 */
#include "../include/Obj10701.h"

extern void func_021E62A0(void *p);

void func_0217D174(int *p)
{
    if (((struct Obj10701 *)p)->f10) {
        func_021E62A0((void *)(((struct Obj10701 *)p)->f10));
        ((struct Obj10701 *)p)->f10 = 0;
    }
}
