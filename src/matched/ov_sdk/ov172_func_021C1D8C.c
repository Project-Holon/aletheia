/*
 * function: func_021C1D8C
 * address:  0x021C1D8C
 * packet:   pkt_ov172_021C1D8C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   WIP
 *
 * sdk:      SSP_JpegEncoderResample (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

extern unsigned long _u32_div_f(unsigned long a, unsigned long b);

void func_021C1D8C(void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option)
{
    unsigned long stepSrcW;
    unsigned long loopSrcW;
    unsigned long loopSrcH;
    long loopDstW;
    long loopDstH;
    unsigned long ofs;
    unsigned long y;
    unsigned long u;
    unsigned long v;
    unsigned long yuyvBak;
    unsigned long fmt;

    fmt = option & 0x104;
    yuyvBak = 0;
    stepSrcW = (srcWidth << 4) / dstWidth;
    for (loopDstH = dstHeight - 1; loopDstH >= 0; loopDstH--) {
        loopSrcH = ((srcHeight * loopDstH) << 4) / dstHeight;
        ofs = srcWidth * (loopSrcH >> 4);
        loopSrcW = srcWidth << 4;
        for (loopDstW = dstWidth - 1; loopDstW >= 0; loopDstW--) {
            loopSrcW -= stepSrcW;
            if (fmt != 4 && fmt == 0x100) {
                y = ((unsigned long *)src)[((((loopSrcW >> 4) & ~1UL) + ofs) >> 1)];
                u = y & 0xff00;
                v = y & 0xff000000;
                if ((loopSrcW >> 4) & 1) {
                    y = y & ((y >> 16) & 0xff);
                } else {
                    y = y & 0xff;
                }
                if (loopDstW & 1) {
                    yuyvBak = y | u | v;
                } else {
                    ((unsigned long *)dst)[(loopDstW + loopDstH * dstWidth) >> 1] =
                        y | (((u >> 1) + (yuyvBak >> 1) + (v >> 1)) & 0xff00ff00) | ((yuyvBak << 24) >> 8);
                }
            } else {
                ((unsigned short *)dst)[loopDstH * dstWidth + loopDstW] = ((unsigned short *)src)[ofs + (loopSrcW >> 4)];
            }
        }
    }
}
