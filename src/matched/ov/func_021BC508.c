/*
 * function: ZUKAN_DETAIL_COMMON_SetBrightnessNone
 * address:  0x021BC508
 * packet:   pkt_021BC508
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_ApplyBrightness 0x021BC520  thumb  ov208
 *
 * Zeroes +8, +0xC and +0x10, then tail-calls ZUKAN_DETAIL_COMMON_ApplyBrightness with both arguments.
 */

extern void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, int *p);

void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p)
{
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    ZUKAN_DETAIL_COMMON_ApplyBrightness(flag, p);
}
