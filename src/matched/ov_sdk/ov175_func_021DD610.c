/*
 * function: sakeiCheckHttpResult
 * address:  0x021DD610
 * packet:   pkt_021DD610
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
 * Category selector: 0 -> 0, 1 -> 6, 0x12 -> 0x17, anything else -> 4.
 */

typedef int s32;

s32 sakeiCheckHttpResult(s32 a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 6;
    case 0x12:
        return 0x17;
    default:
        return 4;
    }
}
