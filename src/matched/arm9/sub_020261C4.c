/*
 * function: CURSOR_MOVE_TestSkipBit
 * address:  0x020261C4
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;

int CURSOR_MOVE_TestSkipBit(const u32 *bitmap, u32 bit)
{
    u32 mask = 1 << (bit & 0x1f);
    int res = 1;

    if ((bitmap[bit >> 5] & mask) == 0) {
        res = 0;
    }
    return res;
}
