/*
 * function: LIVEBATTLEMATCH_IRC_TakeRegulation
 * address: 0x0217E23C
 * packet: pkt_ov176_0217E23C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: follower of LIVEBATTLEMATCH_IRC_SendRegulation
 */
#include "../include/Obj14368.h"
int LIVEBATTLEMATCH_IRC_TakeRegulation(char *p, void **out)
{
    int value = ((struct Obj14368 *)p)->f1008;
    if (value) {
        ((struct Obj14368 *)p)->f1008 = 0;
        *out = p + 6;
    }
    return value;
}
