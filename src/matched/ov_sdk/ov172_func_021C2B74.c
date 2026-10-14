/*
 * function: SSP_StartJpegEncoder
 * address:  0x021C2B74
 * packet:   pkt_ov172_021C2B74
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SSP_StartJpegEncoder (jpegenc.o)
 *
 * symbols:
 *   SSPi_JpegEncoderCheckWidthHeight  0x021C2AD0  arm  ov172
 *   SSP_JpegEncoderResample  0x021C1D8C  arm  ov172
 *   Yos_JPEGEncode  0x021C20B0  arm  ov172
 *   SSP_YUV422ToYUV888  0x021C2050  arm  ov172
 *   SSP_RGB555ToYUV888  0x021C1F04  arm  ov172
 */

extern int SSPi_JpegEncoderCheckWidthHeight(unsigned long width, unsigned long height, unsigned long sampling);
extern void SSP_JpegEncoderResample(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
extern unsigned long Yos_JPEGEncode(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, int thumb, unsigned char *thumb_src, unsigned long thumb_size, void (*func)(void *, unsigned long, unsigned long, void *));
extern void SSP_YUV422ToYUV888(void *src, unsigned long width, unsigned long height, void *dst);
extern void SSP_RGB555ToYUV888(void *src, unsigned long width, unsigned long height, void *dst);

unsigned long SSP_StartJpegEncoder(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option)
{
    void (*convFunc)(void *, unsigned long, unsigned long, void *);
    unsigned char *pThumbWork = 0;
    unsigned long thumb_size = 0;
    unsigned long thumb = option & 1;

    if (!SSPi_JpegEncoderCheckWidthHeight(width, height, sampling))
        return 0;
    switch (option & 0x104) {
    case 0x100:
        convFunc = SSP_YUV422ToYUV888;
        break;
    case 4:
    default:
        convFunc = SSP_RGB555ToYUV888;
        break;
    }
    if (thumb) {
        unsigned long thumb_quality = quality;
        pThumbWork = wrk;
        wrk += 0x12c00;
        SSP_JpegEncoderResample(src, width, height, pThumbWork + 0x9600, 160, 120, option);
        if (quality > 70)
            thumb_quality = 70;
        thumb_size = Yos_JPEGEncode(pThumbWork + 0x9600, pThumbWork, 0x9600, wrk, 160, 120, thumb_quality, 3, 1, 0, 0, convFunc);
        if (thumb_size == 0)
            return 0;
    }
    return Yos_JPEGEncode(src, dst, limit, wrk, width, height, quality, sampling, 0, thumb ? pThumbWork : 0, thumb_size, convFunc);
}
