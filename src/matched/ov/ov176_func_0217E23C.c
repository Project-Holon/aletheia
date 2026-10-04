/*
 * function: func_0217E23C
 * address: 0x0217E23C
 * packet: pkt_ov176_0217E23C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: follower of func_0217E1FC
 */
#include "../include/Obj14368.h"
int func_0217E23C(char *p, void **out)
{
    int value = ((struct Obj14368 *)p)->f1008;
    if (value) {
        ((struct Obj14368 *)p)->f1008 = 0;
        *out = p + 6;
    }
    return value;
}
