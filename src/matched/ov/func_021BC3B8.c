/*
 * function: ZUKAN_DETAIL_COMMON_GetHeadbar
 * address:  0x021BC3B8
 * packet:   pkt_021BC3B8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Returns the word at +0x14.
 */
#include "../include/Obj18183.h"

int ZUKAN_DETAIL_COMMON_GetHeadbar(char *p)
{
    return ((struct Obj18183 *)p)->f14;
}
