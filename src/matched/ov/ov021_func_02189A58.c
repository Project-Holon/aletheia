/*
 * function: FIELDMAP_SetUpdateStopped
 * address:  0x02189A58
 * packet:   pkt_ov021_02189A58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter, called from EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn.
 */
#include "../include/Obj19506.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

void FIELDMAP_SetUpdateStopped(u8 *p, u32 v)
{
    ((struct Obj19506 *)p)->f140 = v;
}
