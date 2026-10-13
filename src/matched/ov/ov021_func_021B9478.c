/*
 * function: FIELD_RAIL_CLOSED_Add
 * address:  0x021B9478
 * packet:   pkt_ov021_021B9478
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

void FIELD_RAIL_CLOSED_Add(u16 *p, u16 v)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (p[i] == 0xFFFF) {
            p[i] = v;
            return;
        }
    }
}
