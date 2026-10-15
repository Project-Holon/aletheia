/*
 * function: MANUAL_COMMON_GetGroupEntry
 * address:  0x021B9CE0
 * packet:   pkt_021B9CE0
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MANUAL_COMMON_GetGroupOffset  0x021B9CF0  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26140.h"

extern unsigned short MANUAL_COMMON_GetGroupOffset(char *p, unsigned i);

int MANUAL_COMMON_GetGroupEntry(char *p, int idx)
{
    return MANUAL_COMMON_GetGroupOffset(p, idx) + ((struct Obj26140 *)p)->f0;
}
