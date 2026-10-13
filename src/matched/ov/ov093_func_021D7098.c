/*
 * function: BTL_EVENT_IsFactorDead
 * address: 0x021D7098
 * packet: pkt_ov093_021D7098
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj21247.h"
typedef unsigned char u8;
int BTL_EVENT_IsFactorDead(u8 *p)
{
    if (((struct Obj21247 *)p)->f10 == 6) return 1;
    return 0;
}
