/*
 * function: FIELD_RAIL_LINE_StartsAtPoint
 * address:  0x021B8674
 * packet:   pkt_021B8674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);

int FIELD_RAIL_LINE_StartsAtPoint(u8 *p, u32 *q, u32 v)
{
    return FIELD_RAIL_SETTING_GetPoint(p, *q) == (u8 *)v;
}
