/*
 * function: func_0217B950
 * address:  0x0217B950
 * packet:   pkt_0217B950
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8738  0x021E8738  thumb  ov177
 */
#include "../include/Obj01762.h"

extern void func_021E8738(int *p, int a, int b, int c);

void func_0217B950(int *p, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj01762 *)p)->f18), ((struct Obj01762 *)p)->fC, b, 1);
}
