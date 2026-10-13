/*
 * function: VCT_AUDIO_ConvertPcm8ToPcm16
 * address:  0x021B16B4
 * packet:   pkt_021B16B4
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void VCT_AUDIO_ConvertPcm8ToPcm16(signed char *src, short *dst, unsigned int n, int fmt)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dst[i] = (short)(src[i] << 8);
}
