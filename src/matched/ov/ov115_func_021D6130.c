/*
 * function: WIFILOGIN_MSG_SetStepHandler
 * address:  0x021D6130
 * packet:   pkt_021D6130
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFILOGIN_MSG_SetStepHandler   0x021D6130  thumb ov115
 *
 * Unlabelled ov115 leaf: stores the second argument at +0xc of the first.
 * Matched to supply the `matched` witness for the pending ov115 caller
 * WIFILOGIN_MSG_RunStep.
 */
#include "../include/Obj22604.h"

void WIFILOGIN_MSG_SetStepHandler(int *p, int v)
{
    ((struct Obj22604 *)p)->fC = v;
}
