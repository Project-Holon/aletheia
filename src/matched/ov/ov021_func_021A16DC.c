/*
 * function: FIELD_3DBG_SetBillboardTexOffsetX
 * address:  0x021A16DC
 * packet:   pkt_ov021_021A16DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (str r1,[r0,#0xc]; bx lr), filed for the ov026 lane.
 *
 * symbols:
 *   FIELD_3DBG_SetBillboardTexOffsetX 0x021A16DC thumb ov021
 */
#include "../include/Obj19720.h"

void FIELD_3DBG_SetBillboardTexOffsetX(unsigned char *p, unsigned int v)
{
    ((struct Obj19720 *)p)->fC = v;
}
