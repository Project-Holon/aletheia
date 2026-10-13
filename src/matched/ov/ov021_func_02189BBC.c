/*
 * function: FIELDMAP_GetHeapSizeForMapType
 * address:  0x02189BBC
 * packet:   pkt_ov021_02189BBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMapType  0x02189B28  thumb  ov021
 *   gMapTypeCtrlTable     0x021D373C  data  a4
 */

#include "../include/G__anon_Ent.h"

extern struct _anon_Ent gMapTypeCtrlTable[];
unsigned int FIELDMAP_GetMapType(unsigned int x);

int FIELDMAP_GetHeapSizeForMapType(int x)
{
    return gMapTypeCtrlTable[(int)FIELDMAP_GetMapType((unsigned int)x)].f8;
}
