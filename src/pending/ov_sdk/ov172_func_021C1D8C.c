/*
 * function: func_021C1D8C
 * address:  0x021C1D8C
 * packet:   pkt_ov172_021C1D8C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (388 vs 376 B, 230 concrete bytes - allocator only)
 *
 * sdk:      SSP_JpegEncoderResample (libssp.TWL.HYB.a jpegenc.o)
 *
 * Lane U57 (2026-09-30): the object's DWARF lists exactly eleven locals
 * (fmt r5, yuyvBak r4, v ip, u r3, y r0, ofs, loopDstH [fb+16], loopDstW r2,
 * loopSrcH, loopSrcW r1, stepSrcW [fb+20]) and every one of them is in the
 * register the image uses, so the vendor's source has NO pointer locals: sb
 * (src+ofs*2), r8 (dst+rowOfs*2), r7 (loopDstH*dstWidth) and lr (ofs) are the
 * compiler's own CSE/strength-reduction values.  The row is parked on the
 * allocator, not on the shape: the image keeps dst in fp and y/u/v in
 * r0/r3/ip, ours spills dst to [sp+8] (frame 0x1c vs 0x18) and puts y/u/v in
 * r7/sl/r8, because our srcP/dstP land in r0/r1 and leave only r3 free for the
 * YUV block.  Eight declaration orders (including reverse and the DWARF
 * reverse) and pointer-local vs inline row expressions all give 388 B / 230-246
 * bytes.  First differing instruction:
 *   +0x0010 image `mov r6, r0` | ours `mov fp, r0`.
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
    unsigned short *srcP;
    unsigned short *dstP;

    fmt = option & 0x104;
    yuyvBak = 0;
    stepSrcW = (srcWidth << 4) / dstWidth;
    for (loopDstH = dstHeight - 1; loopDstH >= 0; loopDstH--) {
        loopSrcH = ((srcHeight * loopDstH) << 4) / dstHeight;
        ofs = srcWidth * (loopSrcH >> 4);
        loopSrcW = srcWidth << 4;
        srcP = (unsigned short *)src + ofs;
        dstP = (unsigned short *)dst + loopDstH * dstWidth;
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
                dstP[loopDstW] = srcP[loopSrcW >> 4];
            }
        }
    }
}
