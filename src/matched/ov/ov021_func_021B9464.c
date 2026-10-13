/*
 * function: FIELD_RAIL_CLOSED_Clear
 * address:  0x021B9464
 * packet:   pkt_ov021_021B9464
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

u16 *FIELD_RAIL_CLOSED_Clear(u16 *p)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        p[i] = 0xFFFF;
    }
    return p;
}
