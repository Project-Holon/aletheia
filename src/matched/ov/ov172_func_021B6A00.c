/*
 * function: CTVT_ADPCM_Encode
 * address:  0x021B6A00
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Half-length packer: runs CTVT_ADPCM_EncodeSamples over a1>>1 halfwords of a0 into a2, returns the rounded-up byte count.
 *
 * symbols:
 *   CTVT_ADPCM_EncodeSamples  0x021B6A30  thumb  ov172
 *   gCtvtAdpcmEncoderState     0x021C88E8  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CTVT_ADPCM_EncodeSamples(short *src, unsigned char *dst, int n, int ctx);
extern u32 gCtvtAdpcmEncoderState[];

int CTVT_ADPCM_Encode(void *a0, unsigned a1, void *a2)
{
    CTVT_ADPCM_EncodeSamples((short *)a0, (unsigned char *)a2, (int)(a1 >> 1), (int)gCtvtAdpcmEncoderState);
    return (int)((a1 + 3) >> 2);
}
