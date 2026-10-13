/*
 * function: FIELD_GIMMICK_CANNONS_StartBounce
 * address: 0x021F3FD8
 * packet: pkt_ov041_021F3FD8
 * region: ov041
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_GIMMICK_CANNONS_ResetBounce 0x021F3FEC thumb ov041
 */
#include "../include/Obj20502.h"

extern void FIELD_GIMMICK_CANNONS_ResetBounce(unsigned char *);
void FIELD_GIMMICK_CANNONS_StartBounce(unsigned char *p)
{
    FIELD_GIMMICK_CANNONS_ResetBounce(p + 0x720);
    ((struct Obj20502 *)p)->f720 = 1;
}
