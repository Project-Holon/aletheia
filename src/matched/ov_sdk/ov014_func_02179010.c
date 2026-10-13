/*
 * function: WHi_MeasureChannel
 * address:  0x02179010
 * packet:   pkt_ov014_02179010
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WM_MeasureChannel            0x02090E50  arm
*/

extern int WM_MeasureChannel(void *callback, unsigned short ccaMode, unsigned short edThreshold, unsigned short channel, unsigned short measureTime);

int WHi_MeasureChannel(void *callback, unsigned short channel)
{
    return WM_MeasureChannel(callback, 3, 0x11, channel, 0x1E);
}
