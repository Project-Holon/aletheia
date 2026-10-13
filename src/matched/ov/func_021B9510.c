/*
 * function: FIELD_RAIL_GetOpenLine
 * address:  0x021B9510
 * packet:   pkt_021B9510
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_CLOSED_Contains  0x021B94C0  thumb
 *   FIELD_RAIL_SETTING_GetLine  0x021B87FC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FIELD_RAIL_CLOSED_Contains(u16 *p, u16 v);
u8 *FIELD_RAIL_SETTING_GetLine(u8 *p, u32 idx);

u8 *FIELD_RAIL_GetOpenLine(u16 *p, u8 *q, u32 v)
{
    if (FIELD_RAIL_CLOSED_Contains(p, (u16)v) == 0)
        return FIELD_RAIL_SETTING_GetLine(q, v);
    return 0;
}
