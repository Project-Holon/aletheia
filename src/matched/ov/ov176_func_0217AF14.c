/*
 * function: func_0217AF14
 * address:  0x0217AF14
 * packet:   pkt_0217AF14
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E5534  0x021E5534  thumb  ov177
 *   func_021E5980  0x021E5980  thumb  ov177
 */
#include "../include/Obj04561.h"

typedef unsigned char  u8;
extern void func_021E5534(u8 *p);
extern void func_021E5980(int);

void func_0217AF14(int *p)
{
    if (((struct Obj04561 *)p)->f24) {
        func_021E5534((u8 *)(((struct Obj04561 *)p)->f24));
        func_021E5980(((struct Obj04561 *)p)->f20);
    }
}
