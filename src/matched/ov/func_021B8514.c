/*
 * function: FIELD_RAIL_POINT_FindLine
 * address:  0x021B8514
 * packet:   pkt_021B8514
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetOpenLine  0x021B9510  thumb
 *   FIELD_RAIL_SETTING_GetLine  0x021B87FC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *FIELD_RAIL_GetOpenLine(u16 *p, u8 *q, u32 v);
u8 *FIELD_RAIL_SETTING_GetLine(u8 *p, u32 idx);

u8 *FIELD_RAIL_POINT_FindLine(u8 *p, u32 v, u8 *q, u16 *r, int flag)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (v == ((u32 *)p)[i + 4]) {
            if (flag)
                return FIELD_RAIL_GetOpenLine(r, q, ((u32 *)p)[i]);
            return FIELD_RAIL_SETTING_GetLine(q, ((u32 *)p)[i]);
        }
    }
    return 0;
}
