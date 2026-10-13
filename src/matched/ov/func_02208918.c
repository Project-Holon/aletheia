/*
 * function: BTLV_GAUGE_SetSavedBgmNo
 * address:  0x02208918
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_GAUGE_SetSavedBgmNo   0x02208918  thumb
 *   BODY

 *
 * lane O10 candidate
 */
#include "../include/Obj18617.h"

void BTLV_GAUGE_SetSavedBgmNo(char *p, int v)
{
    ((struct Obj18617 *)p)->f444 = v;
}

