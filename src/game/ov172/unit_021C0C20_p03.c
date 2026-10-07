/*
 * file:     unit_021C0C20_p03.c
 * unit:     yes
 * function: func_021C1868, func_021C19E4, func_021C1A80, func_021C1AE4, func_021C1D8C
 * address:  0x021C1868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0D04  0x021C0D04  arm  ov172
 *   _u32_div_f  0x0209C2B0  arm
 *   MI_CpuFill8                     0x02082BCC  arm
 *   OS_IsRunOnTwl                   0x02085D3C  arm
 *   AESi_Init                       0x027073AC  arm
 *   AESi_SignForJpeg                0x02707774  arm
 *   MI_CpuCopy8                     0x02082D44  arm
 *   gBitLen                         0x021CADE4  data
 */
typedef struct component_structure {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021C0D04(unsigned char *data, long *qtable, short *output);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int OS_IsRunOnTwl(void);
extern void AESi_Init(void);
extern int AESi_SignForJpeg(u8 *sign, u8 *dst, u32 ptr);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern unsigned long _u32_div_f(unsigned long a, unsigned long b);
void func_021C1868(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
unsigned long func_021C19E4(unsigned long width, unsigned long height, unsigned long sampling);
unsigned long func_021C1A80(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);
void func_021C1D8C(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
extern u8 gBitLen[];


/*
 * sdk:      Yos_JpegEncodeSample1to1Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * Static: copies an unsubsampled component plane into 8x8 blocks through eight row pointers, each block handed to the forward DCT.
 */
void func_021C1868(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx)
{
    unsigned char data[64];
    unsigned long v;
    unsigned long x;
    unsigned long y;
    unsigned long z;
    short *dct_coff;
    unsigned long cx;
    unsigned long cy;
    unsigned char *row0;
    unsigned char *row1;
    unsigned char *row2;
    unsigned char *row3;
    unsigned char *row4;
    unsigned char *row5;
    unsigned char *row6;
    unsigned char *row7;

    cy = component->mRows;
    row0 = buffer;
    row1 = buffer + dx;
    row2 = buffer + dx * 2;
    row3 = buffer + dx * 3;
    row4 = buffer + dx * 4;
    row5 = buffer + dx * 5;
    row6 = buffer + dx * 6;
    row7 = buffer + dx * 7;
    dct_coff = component->mCofficients;
    cx = component->mCols;
    for (y = 0, v = 0; y < cy; y++) {
        for (x = 0; x < cx; x++) {
            for (z = 0; z < 8; z++) {
                data[z + 0] = *row0++;
                data[z + 8] = *row1++;
                data[z + 16] = *row2++;
                data[z + 24] = *row3++;
                data[z + 32] = *row4++;
                data[z + 40] = *row5++;
                data[z + 48] = *row6++;
                data[z + 56] = *row7++;
            }
            func_021C0D04(data, qTable, dct_coff + v * 64);
            v++;
        }
        row0 = row7;
        row1 = row0 + dx;
        row2 = row1 + dx;
        row3 = row2 + dx;
        row4 = row3 + dx;
        row5 = row4 + dx;
        row6 = row5 + dx;
        row7 = row6 + dx;
    }
}

/*
 * notes:    w9_nm2: both mask locals (mx, my) in place of the inline samplingN * 8 - 1 expressions close it; the object holds the masks in r4 and a short-lived r2.
 *
 * sdk:      Yos_JPEGGetMemorySize (jpegenc.o)
 */
unsigned long func_021C19E4(unsigned long width, unsigned long height, unsigned long sampling)
{
    unsigned long i;
    unsigned long mx;
    unsigned long my;
    unsigned long cx;
    unsigned long cy;
    unsigned long dx;
    unsigned long dy;
    unsigned long samplingx;
    unsigned long samplingy;

    samplingy = samplingx = 1;
    switch (sampling) {
    case 1:
        break;
    case 2:
        samplingy = 2;
        samplingx = samplingy;
        break;
    case 3:
        samplingx = 2;
        break;
    }
    mx = samplingx * 8 - 1;
    dx = (width + mx) & ~mx;
    my = samplingy * 8 - 1;
    dy = (height + my) & ~my;
    cx = dx >> 3;
    cy = dy >> 3;
    return dx * dy * 3 + ((cx * cy + ((cx / samplingx) * (cy / samplingy)) * 2) << 7) + 0x2b40;
}


/*
 * sdk:      SSP_GetJpegEncoderBufferSize (jpegenc.o)
 */
unsigned long func_021C1A80(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option)
{
    unsigned long thumb;
    unsigned long mainSize;
    unsigned long thumbSize;

    thumb = option & 1;
    if (thumb) {
        if (width < 160)
            width = 160;
        if (height < 120)
            height = 120;
    }
    mainSize = func_021C19E4(width, height, sampling);
    thumbSize = func_021C19E4(160, 120, 1);
    if (mainSize > thumbSize)
        return mainSize + (thumb ? 0x12c00 : 0);
    return thumbSize + (thumb ? 0x12c00 : 0);
}


static int SSPi_JpegEncoderDoSign(u8 *dst, unsigned long ptr)
{
    unsigned long offset;
    unsigned char *p;
    unsigned char sign[28];
    unsigned long registrationNumber;
    int i;
    u16 tag;

    if (*(u32 *)(gBitLen + 8) < 0x17)
        return 0;

    offset = dst[0x13] + 0xc;
    if (offset + 2 > *(u32 *)(gBitLen + 8))
        return 0;
    p = dst + offset;
    registrationNumber = (u16)((p[1] + (dst[offset] << 8)));
    offset += 2;
    if (registrationNumber * 0xc + offset > *(u32 *)(gBitLen + 8))
        return 0;

    tag = 0;
    for (i = 0; i < registrationNumber; i++) {
        p = dst + offset;
        tag = (u16)((p[1] + (dst[offset] << 8)));
        if (tag == 0x8769) {
            offset = (((u32)p[8] << 24) + ((u32)p[9] << 16) +
                      ((u32)p[10] << 8) + p[11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x8769)
        return 0;

    if (offset + 2 > *(u32 *)(gBitLen + 8))
        return 0;
    p = dst + offset;
    registrationNumber = (u16)((p[1] + (dst[offset] << 8)));
    offset += 2;
    if (registrationNumber * 0xc + offset > *(u32 *)(gBitLen + 8))
        return 0;

    tag = 0;
    for (i = 0; i < registrationNumber; i++) {
        p = dst + offset;
        tag = (u16)((p[1] + (dst[offset] << 8)));
        if (tag == 0x927c) {
            offset = (((u32)p[8] << 24) + ((u32)p[9] << 16) +
                      ((u32)p[10] << 8) + p[11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x927c)
        return 0;

    if (offset + 4 > *(u32 *)(gBitLen + 8))
        return 0;
    p = dst + offset;
    if (p[2] != 0x10 || p[3] != 0)
        return 0;
    if (offset + 0xe > *(u32 *)(gBitLen + 8))
        return 0;

    offset = (((u32)p[0xa] << 24) + ((u32)p[0xb] << 16) +
              ((u32)p[0xc] << 8) + p[0xd]) + 0xc;
    if (offset + 0x1c > *(u32 *)(gBitLen + 8))
        return 0;

    MI_CpuFill8(dst + offset, 0, 0x1c);
    if (OS_IsRunOnTwl())
        AESi_Init();
    if (AESi_SignForJpeg(sign, dst, ptr) != 1)
        return 0;
    MI_CpuCopy8(sign, dst + offset, 0x1c);
    return 1;
}


/*
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
 */
void func_021C1D8C(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option)
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
