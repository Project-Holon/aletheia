/*
 * function: FIELD_GIMMICK_CANNONS_ResetBounce
 * address: 0x021F3FEC
 * packet: pkt_ov041_021F3FEC
 * region: ov041
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 18 bytes of code followed by two zero alignment bytes.
 * symbols:
 */
#include "../include/Obj04319.h"

void FIELD_GIMMICK_CANNONS_ResetBounce(unsigned char *p)
{
    ((struct Obj04319 *)p)->f0 = 0;
    ((struct Obj04319 *)p)->f4 = 0;
    ((struct Obj04319 *)p)->f8 = 0;
    p[13] = 0;
    p[12] = 0;
    p[14] = 0;
    p[15] = 0;
}
