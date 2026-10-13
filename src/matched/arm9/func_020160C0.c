/*
 * function: MCSS_SetGlobalScale
 * address: 0x020160C0
 * packet: pkt_020160C0
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj15671.h"
void MCSS_SetGlobalScale(char *p, unsigned int v)
{
    ((struct Obj15671 *)p)->f44 = v;
}
