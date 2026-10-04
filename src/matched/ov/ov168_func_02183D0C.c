/*
 * function: func_02183D0C
 * address:  0x02183D0C
 * packet:   pkt_02183D0C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D34  0x02183D34  thumb  ov168
 */
#include "../include/Obj14257.h"

extern void func_02183D34(int *, int);

void func_02183D0C(int *p, int a, int b)
{
    *p = a;
    ((struct Obj14257 *)p)->fC = 0;
    func_02183D34(p, b);
}
