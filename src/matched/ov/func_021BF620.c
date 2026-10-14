/*
 * function: ZUKAN_DETAIL_INFO_StartHighlightBlink
 * address:  0x021BF620
 * packet:   pkt_021BF620
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Zeroes word 0x42 and sets word 0x43 when word 0x26 is not 6.
 */


struct Ov208Heap;

void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, int *p, int *ctx)
{
    if (p[0x26] == 6)
        return;
    p[0x42] = 0;
    p[0x43] = 1;
}

