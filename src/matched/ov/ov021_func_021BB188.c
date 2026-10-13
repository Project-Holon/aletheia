/*
 * function: RAIL_ATTR_IsSignBoard
 * address:  0x021BB188
 * packet:   pkt_ov021_021BB188
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

int RAIL_ATTR_IsSignBoard(u16 a)
{
    if ((u16)(a + 0xFF60) <= 1) {
        return 1;
    }
    return 0;
}
