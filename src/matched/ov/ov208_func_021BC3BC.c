/*
 * function: ZUKAN_DETAIL_COMMON_GetMaxValue
 * address:  0x021BC3BC
 * packet:   pkt_ov208_021BC3BC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (the listing prints it as ARM data): returns the
 * halfword at +0x1c.
 */
#include "../include/Obj25414.h"

typedef unsigned short u16;

u16 ZUKAN_DETAIL_COMMON_GetMaxValue(char *p)
{
    return ((struct Obj25414 *)p)->f1C;
}
