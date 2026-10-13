/*
 * function: FIELD_PLAYER_SetDirDisp
 * address:  0x021A305C
 * packet:   pkt_021A305C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_PLAYER_CORE_SetDirDisp  0x021A392C  thumb  ov021
 *
 * blocker: target 0x021A392C has no witness outside the compared range
 *          (ov009/ov021 overlap; the ov021 hint does not locate a func_ label).
 
 *
 * UNBLOCKED: FIELD_PLAYER_CORE_SetDirDisp is now an EXACT entry in layout/matched/ov021;
 * the call site resolves as matched, verdict promoted to EXACT.
*/
#include "../include/Obj19764.h"

typedef unsigned int u32;

void FIELD_PLAYER_CORE_SetDirDisp(void *p, int b);

void FIELD_PLAYER_SetDirDisp(char *p, u32 b)
{
    FIELD_PLAYER_CORE_SetDirDisp((void *)(((struct Obj19764 *)p)->f4), b);
}
