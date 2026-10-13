/*
 * function: FIELD_RAIL_SetLineEnable
 * address:  0x021B7C04
 * packet:   pkt_ov021_021B7C04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_CLOSED_Contains  0x021B94C0  thumb ov021
 *   FIELD_RAIL_CLOSED_Add  0x021B9478  thumb ov021
 *   FIELD_RAIL_CLOSED_Remove  0x021B949C  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_RAIL_CLOSED_Contains(u16 *p, u16 v);
extern void FIELD_RAIL_CLOSED_Add(u16 *p, u16 v);
extern void FIELD_RAIL_CLOSED_Remove(u16 *p, u16 v);

void FIELD_RAIL_SetLineEnable(u8 *o, int k, int flag)
{
    if (flag == 0) {
        if (FIELD_RAIL_CLOSED_Contains((u16 *)(o + 0x50), k) == 0) {
            FIELD_RAIL_CLOSED_Add((u16 *)(o + 0x50), k);
        }
    } else {
        FIELD_RAIL_CLOSED_Remove((u16 *)(o + 0x50), k);
    }
}
