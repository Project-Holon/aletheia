/*
 * function: MANUAL_COMMON_GetEntry
 * address:  0x021B9CFC
 * packet:   pkt_021B9CFC
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MANUAL_COMMON_GetEntryOffset  0x021B9D0C  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26142.h"

extern unsigned short MANUAL_COMMON_GetEntryOffset(char *p, unsigned i);

int MANUAL_COMMON_GetEntry(char *p, int idx)
{
    return MANUAL_COMMON_GetEntryOffset(p, idx) + ((struct Obj26142 *)p)->f8;
}
