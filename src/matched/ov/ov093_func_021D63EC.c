/*
 * function: BTL_POKEPARAM_StartTurnThreshold
 * address: 0x021D63EC
 * packet: pkt_ov093_021D63EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_ClearHitHistory 0x021D67F4 thumb ov093
 */
#include "../include/Obj00041.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void BTL_POKEPARAM_ClearHitHistory(u8 *);
void BTL_POKEPARAM_StartTurnThreshold(u8 *p, u16 n)
{
    ((struct Obj00041 *)p)->f148 = n;
    ((struct Obj00041 *)p)->f146 = 0;
    p[0x1b] |= 0x80;
    BTL_POKEPARAM_ClearHitHistory(p);
}
