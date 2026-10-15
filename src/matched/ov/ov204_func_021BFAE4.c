/*
 * function: INTRO_G3D_SetVisible
 * address: 0x021BFAE4
 * packet: pkt_ov204_021BFAE4
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing switch follower 0x021BFAE8 is separately filed, followed by two-byte padding.
 * symbols:

 */
#include "../include/Obj25391.h"



void INTRO_G3D_SetVisible(char *p, int v)
{
    ((struct Obj25391 *)p)->f14 = v;
}
