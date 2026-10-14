/*
 * function: WORLDTRADE_DETAIL_GetModeColor
 * address:  0x021FC8A8
 * packet:   pkt_021FC8A8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Mode table: 0 -> 0, 1 -> 0x14c0, 2 -> 0xc80, anything else 0.
 */

typedef unsigned short u16;

u16 WORLDTRADE_DETAIL_GetModeColor(int mode)
{
    switch (mode) {
    case 0:
        return 0;
    case 1:
        return 0x53 << 6;
    case 2:
        return 0x32 << 6;
    default:
        return 0;
    }
}
