/*
 * function: GIMMICK41_StartBounce
 * address: 0x021F3FD8
 * packet: pkt_ov041_021F3FD8
 * region: ov041
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK41_ResetBounce 0x021F3FEC thumb ov041
 */
#include "../include/Obj20502.h"

extern void GIMMICK41_ResetBounce(unsigned char *);
void GIMMICK41_StartBounce(unsigned char *p)
{
    GIMMICK41_ResetBounce(p + 0x720);
    ((struct Obj20502 *)p)->f720 = 1;
}
