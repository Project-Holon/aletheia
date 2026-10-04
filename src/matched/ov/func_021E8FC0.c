/*
 * function: func_021E8FC0
 * address:  0x021E8FC0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC9A0  0x021DC9A0  thumb  ov170
 *
 * Store the third argument, then reset the sub-object.
 */
#include "../include/Obj00000.h"



extern void func_021DC9A0(char *, int);
int func_021E8FC0(char *p, int a, int b)
{
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x68) = b;
    func_021DC9A0(*(char * *)&((struct Obj00000 *)p)->f2C, a);
    return 5;
}
