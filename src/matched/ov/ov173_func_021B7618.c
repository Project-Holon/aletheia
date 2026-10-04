/*
 * function: func_021B7618
 * address:  0x021B7618
 * packet:   pkt_021B7618
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7460  0x021B7460  thumb  ov173
 */
#include "../include/Obj14318.h"

extern void func_021B7460(int *, int);

int func_021B7618(int *p)
{
    func_021B7460(p, 4);
    ((struct Obj14318 *)p)->f1BA = 2;
    ((struct Obj14318 *)p)->f1B0 = 3;
    return 2;
}
