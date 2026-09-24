/*
 * function: func_021DF5E4
 * address:  0x021DF5E4
 * packet:   pkt_021DF5E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * ARM jump-table selector over 0..0xe: only two values carry a code of their
 * own (0 and 6), everything else is 0x14.
 */

typedef int s32;

s32 func_021DF5E4(s32 a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    case 5:
        return 9;
    }
    return 0x14;
}
