/*
 * function: func_021C2B74
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
 *   func_021C2AD0  0x021C2AD0  arm  ov172
 *   func_021C1D8C  0x021C1D8C  arm  ov172
 *   func_021C20B0  0x021C20B0  arm  ov172
 *   func_021C2050  0x021C2050  arm  ov172
 *   func_021C1F04  0x021C1F04  arm  ov172
 */

extern int func_021C2AD0(unsigned long width, unsigned long height, unsigned long sampling);
extern void func_021C1D8C(void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
extern unsigned long func_021C20B0(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, int thumb, unsigned char *thumb_src, unsigned long thumb_size, void (*func)(void *, unsigned long, unsigned long, void *));
extern void func_021C2050(void *src, unsigned long width, unsigned long height, void *dst);
extern void func_021C1F04(void *src, unsigned long width, unsigned long height, void *dst);

unsigned long func_021C2B74(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option)
{
    void (*convFunc)(void *, unsigned long, unsigned long, void *);
    unsigned char *pThumbWork = 0;
    unsigned long thumb_size = 0;
    unsigned long thumb = option & 1;

    if (!func_021C2AD0(width, height, sampling))
        return 0;
    switch (option & 0x104) {
    case 0x100:
        convFunc = func_021C2050;
        break;
    case 4:
    default:
        convFunc = func_021C1F04;
        break;
    }
    if (thumb) {
        unsigned long thumb_quality = quality;
        pThumbWork = wrk;
        wrk += 0x12c00;
        func_021C1D8C(src, width, height, pThumbWork + 0x9600, 160, 120, option);
        if (quality > 70)
            thumb_quality = 70;
        thumb_size = func_021C20B0(pThumbWork + 0x9600, pThumbWork, 0x9600, wrk, 160, 120, thumb_quality, 3, 1, 0, 0, convFunc);
        if (thumb_size == 0)
            return 0;
    }
    return func_021C20B0(src, dst, limit, wrk, width, height, quality, sampling, 0, thumb ? pThumbWork : 0, thumb_size, convFunc);
}
