/*
 * function: FIELD_RAIL_LINE_EndsAtPoint
 * address:  0x021B868C
 * packet:   pkt_021B868C
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

int FIELD_RAIL_LINE_EndsAtPoint(u8 *p, u32 *q, void *v)
{
    return FIELD_RAIL_SETTING_GetPoint(p, q[1]) == (u8 *)v;
}
