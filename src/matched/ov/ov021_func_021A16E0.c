/*
 * function: FIELD_3DBG_SetBillboardTexOffsetY
 * address:  0x021A16E0
 * packet:   pkt_ov021_021A16E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (str r1,[r0,#0x10]; bx lr), filed for the ov026 lane.
 *
 * symbols:
 *   FIELD_3DBG_SetBillboardTexOffsetY 0x021A16E0 thumb ov021
 */
#include "../include/Obj19721.h"

void FIELD_3DBG_SetBillboardTexOffsetY(unsigned char *p, unsigned int v)
{
    ((struct Obj19721 *)p)->f10 = v;
}
