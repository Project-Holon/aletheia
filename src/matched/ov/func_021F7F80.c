/*
 * function: func_021F7F80
 * address:  0x021F7F80
 * packet:   pkt_021F7F80
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
 * Mode table: 0 -> 0x14c0, 1 -> 0xc80, anything else 0.
 */

typedef unsigned short u16;

u16 func_021F7F80(int mode)
{
    switch (mode) {
    case 0:
        return 0x53 << 6;
    case 1:
        return 0x32 << 6;
    default:
        return 0;
    }
}
