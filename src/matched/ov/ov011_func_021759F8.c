/*
 * function: INTRUDE_COMM_StartSessionTimer
 * address: 0x021759F8
 * packet: pkt_ov011_021759F8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 0x02175A24 already filed separately.
 * symbols:
 *   func_0203F4FC 0x0203F4FC arm
 *   func_0203D378 0x0203D378 arm
 */
#include "../include/Obj09352.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0203F4FC(void);
extern u32 func_0203D378(void);
void INTRUDE_COMM_StartSessionTimer(u8 *p, int n)
{
    p[0x1A5] |= 2;
    ((struct Obj09352 *)p)->fAA = n;
    if (func_0203D378() == 0) ((struct Obj09352 *)p)->f190 = func_0203F4FC();
}
