/*
 * function: SSP_JpegEncoderResample
 * address:  0x021C1D8C
 * packet:   pkt_ov172_021C1D8C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      SSP_JpegEncoderResample (libssp.TWL.HYB.a jpegenc.o)
 *
 * 2026-10-01 wave 3 lane12: closed. Not an allocator tie: two source-shape
 * errors. (1) The row offsets are written inline in the inner loop (no
 * srcP/dstP, `ofs = loopSrcW >> 4` per branch), so the compiler hoists them
 * into the preheader after the inner guard. (2) The packed store groups as
 * `y | ((sum & 0xff00ff00) | (bak << 24 >> 8))` with the sum written
 * `(yuyvBak >> 1) + (u >> 1) + (v >> 1)`; the old left-to-right OR chain kept
 * y live one register longer, which is what spilled dst. Either change alone
 * stays DIFF. src is `const void *` (mangled PKv). The vendor object also has
 * an unreferenced function-local `static const prec` (= 4, folded; no reloc),
 * omitted here; including it is inert.
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

extern unsigned long _u32_div_f(unsigned long a, unsigned long b);

void SSP_JpegEncoderResample(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option)
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
        loopSrcW = srcWidth << 4;
        for (loopDstW = dstWidth - 1; loopDstW >= 0; loopDstW--) {
            loopSrcW -= stepSrcW;
            if (fmt != 4 && fmt == 0x100) {
                ofs = loopSrcW >> 4;
                y = ((const unsigned long *)src)[((ofs & ~1UL) + srcWidth * (loopSrcH >> 4)) >> 1];
                u = y & 0xff00;
                v = y & 0xff000000;
                if (ofs & 1) {
                    y = y & ((y >> 16) & 0xff);
                } else {
                    y = y & 0xff;
                }
                if (loopDstW & 1) {
                    yuyvBak = y | u | v;
                } else {
                    ((unsigned long *)dst)[(loopDstW + loopDstH * dstWidth) >> 1] =
                        y | ((((yuyvBak >> 1) + (u >> 1) + (v >> 1)) & 0xff00ff00) | ((yuyvBak << 24) >> 8));
                }
            } else {
                ofs = loopSrcW >> 4;
                ((unsigned short *)dst)[loopDstH * dstWidth + loopDstW] = ((const unsigned short *)src)[srcWidth * (loopSrcH >> 4) + ofs];
            }
        }
    }
}
