/*
 * function: CTVT_ADPCM_Decode
 * address:  0x021B6A18
 * packet:   pkt_021B6A18
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CTVT_ADPCM_DecodeSamples  0x021B6A88  thumb  ov172
 */

typedef signed short   s16;
extern void CTVT_ADPCM_DecodeSamples(char *input, s16 *output, int size, char *state);

int CTVT_ADPCM_Decode(int a, int b, int c)
{
    CTVT_ADPCM_DecodeSamples((char *)a, (s16 *)c, b * 2, (void *)0x021C88E4);
    return b * 4;
}
