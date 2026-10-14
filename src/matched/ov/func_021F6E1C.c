/*
 * function: BTLV_FIELD_IsEffectActive
 * address:  0x021F6E1C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FIELD_IsEffectActive   0x021F6E1C  thumb
 *
 * lane O10 candidate
 */
#include "../include/Obj18551.h"

int BTLV_FIELD_IsEffectActive(char *p)
{
    return ((struct Obj18551 *)p)->f60 != 0;
}

