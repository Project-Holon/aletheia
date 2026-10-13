/*
 * function: C_GEAR_SetStepFunc
 * address: 0x021EFEE4
 * packet: pkt_ov029_021EFEE4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj09784.h"
void C_GEAR_SetStepFunc(unsigned char *p, unsigned int v)
{
    ((struct Obj09784 *)p)->f0 = v;
    p[0x456] = 0;
    p[0x455] = 0;
}
