/*
 * function: func_021EBADC
 * address:  0x021EBADC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBA84  0x021EBA84  thumb  ov170
 *
 * Sibling of func_021EBB28: index 0x34 when state is 5, else 0xb.
 */
#include "../include/Obj18517.h"


extern void func_021EBA84(char *, int, int);
void func_021EBADC(char *p, int b)
{
    if (*(int *)(((struct Obj18517 *)p)->f0 + 0x24) == 5)
        func_021EBA84(p, 0x34, b);
    else
        func_021EBA84(p, 0xb, b);
}
