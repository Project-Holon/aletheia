/*
 * function: func_021BDC2C
 * address:  0x021BDC2C
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD3B4 0x021BD3B4  thumb  ov208

 * Returns the result of func_021BD3B4 on two fields while +0x10 is clear, else 0.
 */
#include "../include/Obj09200.h"


extern int func_021BD3B4(void *mgr, int key);

int func_021BDC2C(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return func_021BD3B4((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}

