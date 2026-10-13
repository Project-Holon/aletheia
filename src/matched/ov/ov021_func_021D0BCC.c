/*
 * function: TRIAL_HOUSE_GetTrainerObjCode
 * address:  0x021D0BCC
 * packet:   pkt_021D0BCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLD_BTL_INST_TOOL_LookupKeyValue  0x02168AEC  thumb  ov010
 *
 * Unblocked by matching FLD_BTL_INST_TOOL_LookupKeyValue (ov010, EXACT): the +0008 ABS32 site now
 * attests as `matched`.
 */
#include "../include/Obj20293.h"

typedef unsigned short u16;

u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 a0);

void TRIAL_HOUSE_GetTrainerObjCode(char *p)
{
    FLD_BTL_INST_TOOL_LookupKeyValue(((struct Obj20293 *)p)->f4);
}
