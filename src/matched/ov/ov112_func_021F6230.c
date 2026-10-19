/*
 * function: MUSICAL_MCSS_SetAnimVramBase
 * address: 0x021F6230
 * packet: pkt_ov112_021F6230
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj22544.h"
typedef unsigned char u8;
void MUSICAL_MCSS_SetAnimVramBase(u8 *p, int a)
{
    ((struct Obj22544 *)p)->f10 = a;
}
