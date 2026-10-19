/*
 * function: BTLV_STAGE_IsTintActive
 * address:  0x021F6A18
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_STAGE_IsTintActive   0x021F6A18  thumb
 *
 * lane O10 candidate
 */
#include "../include/Obj18549.h"

int BTLV_STAGE_IsTintActive(char *p)
{
    return ((struct Obj18549 *)p)->fAC != 0;
}

