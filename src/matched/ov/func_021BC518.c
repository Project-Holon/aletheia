/*
 * function: ZUKAN_DETAIL_COMMON_InitBrightnessTarget
 * address:  0x021BC518
 * packet:   pkt_021BC518
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Writes 0x2D to the first two words.
 */


void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p)
{
    p[0] = 0x2d;
    p[1] = 0x2d;
}

