typedef struct SSPiJpegThumbnailWork {
    unsigned char dst[38400];
    unsigned short src[19200];
} SSPiJpegThumbnailWork;

typedef void (*ConvFunc)(void *, unsigned long, unsigned long, void *);

extern int func_021C2AD0(unsigned long width, unsigned long height, unsigned long sampling);
extern void func_021C1D8C(void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
extern unsigned long func_021C20B0(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, int thumb, unsigned char *thumb_src, unsigned long thumb_size, ConvFunc func);
extern void func_021C2050(void *src, unsigned long width, unsigned long height, void *dst);
extern void func_021C1F04(void *src, unsigned long width, unsigned long height, void *dst);

unsigned long func_021C2B74(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option)
{
    ConvFunc convFunc;
    SSPiJpegThumbnailWork *pThumbWork;
    unsigned long thumb_size;
    unsigned long thumb;
    unsigned long thumb_quality;

    pThumbWork = 0;
    thumb_size = 0;
    thumb = option & 1;
    if (!func_021C2AD0(width, height, sampling)) return 0;
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
        pThumbWork = (SSPiJpegThumbnailWork *)wrk;
        func_021C1D8C(src, width, height, pThumbWork->src, 160, 120, option);
        wrk += sizeof(SSPiJpegThumbnailWork);
        thumb_quality = quality;
        if (thumb_quality > 70) thumb_quality = 70;
        thumb_size = func_021C20B0(pThumbWork->src, pThumbWork->dst, 0x9600, wrk, 160, 120, thumb_quality, 3, 1, 0, 0, convFunc);
        if (thumb_size == 0) return 0;
    }
    return func_021C20B0(src, dst, limit, wrk, width, height, quality, sampling, 0, thumb ? pThumbWork->dst : 0, thumb_size, convFunc);
}
