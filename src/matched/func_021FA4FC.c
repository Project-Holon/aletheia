/*
 * function: func_021FA4FC
 * address:  0x021FA4FC
 * packet:   pkt_021FA4FC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Map a mode value: 9 and 10 have fixed answers, everything else passes through.
 */

int func_021FA4FC(int unused, int mode)
{
    switch (mode) {
    case 9:
        return ~1;
    case 10:
        return 10;
    default:
        return mode;
    }
}
