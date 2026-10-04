/*
 * function: func_0217DFA8
 * address:  0x0217DFA8
 * packet:   pkt_0217DFA8
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E89D0  0x021E89D0  thumb  ov177
 */
#include "../include/Obj00348.h"

extern void func_021E89D0(int);

void func_0217DFA8(int *p)
{
    if (*(int *)&((struct Obj00348 *)p)->fC) {
        func_021E89D0(*(int *)&((struct Obj00348 *)p)->fC);
        *(int *)&((struct Obj00348 *)p)->fC = 0;
    }
}
