/*
 * file:     jpegenc.c
 * unit:     yes
 * function: Yos_BitInit, Yos_BitWrite, Yos_JpegEncoderForwardDct, Yos_JpegEncoderHuffmanEncoderBuildTable, Yos_JpegEncoderHuffmanEncoderPrintTable, Yos_JpegEncoderHuffmanEncoderOutputSize, Yos_JpegEncoderComponentSequential, Yos_JpegEncodeSample2to2Component, Yos_JpegEncodeSample2to1Component, Yos_JpegEncodeSample1to1Component, Yos_JPEGGetMemorySize, SSP_GetJpegEncoderBufferSize, SSPi_JpegEncoderDoSign, SSP_JpegEncoderResample, SSP_RGB555ToYUV888, SSP_YUV422ToYUV888, Yos_JPEGEncode, SSPi_JpegEncoderCheckWidthHeight, SSP_StartJpegEncoder
 * address:  0x021C0C20
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
 *   gJpegBitWriterState  0x021CADE4  data  ov172
 *   gBitLen      0x021CADE4  data
 *   gBitCode     0x021CADE8  data
 *   gWriteLimit  0x021CADEC  data
 *   gJpegBitMask   0x021C7150  data
 *   MIi_CpuClearFast                0x02082AC0  arm
 *   MIi_CpuCopyFast                 0x02082B0C  arm
 *   MI_CpuCopy                      0x02082EA4  arm
 *   dc0_tbl                         0x021C8500  data  ov172
 *   dc1_tbl                         0x021C8520  data  ov172
 *   ac0_tbl                         0x021C86C0  data  ov172
 *   ac1_tbl                         0x021C8600  data  ov172
 *   Yos_BitWrite                    0x021C0C3C  arm  ov172
 *   JpegZigZagInputOrderCodes       0x021C85BC  data
 *   Yos_JpegEncoderForwardDct  0x021C0D04  arm  ov172
 *   _u32_div_f  0x0209C2B0  arm
 *   MI_CpuFill8                     0x02082BCC  arm
 *   OS_IsRunOnTwl                   0x02085D3C  arm
 *   AESi_Init                       0x027073AC  arm
 *   AESi_SignForJpeg                0x02707774  arm
 *   MI_CpuCopy8                     0x02082D44  arm
 *   _s32_div_f                       0x0209C0A4  arm
 *   Yos_JpegEncodeSample1to1Component 0x021C1868 arm
 *   Yos_JpegEncodeSample2to1Component 0x021C1710 arm
 *   SSP_ExifEncode                   0x021C4B9C  arm
 *   Yos_JpegEncoderHuffmanEncoderOutputSize 0x021C12F4 arm
 *   Yos_JpegEncoderHuffmanEncoderPrintTable 0x021C1248 arm
 *   Yos_BitInit                      0x021C0C20  arm
 *   luminance_quantization_table     0x021C853C  data
 *   scaleTable                       0x021C8774  data
 *   chrominance_quantization_table   0x021C857C  data
 *   thumbnail                        0x021C84E5  data
 *   jfif                             0x021C84CE  data
 *   jsos                             0x021C84C0  data
 *   SSPiEncodeSignCheckMode          0x021CADF8  data
 *   Yos_JPEGEncode  0x021C20B0  arm  ov172
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct Yos_JpegEncoderHuffmanEncoderBuildTableWork {
    unsigned long mHuffSize[256];
    unsigned long mHuffCode[256];
} Yos_JpegEncoderHuffmanEncoderBuildTableWork;

typedef struct component_structure {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure;

typedef struct huffman_structure {
    unsigned long mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[260];
} huffman_structure;

extern void MIi_CpuClearFast(unsigned long data, void *destp, unsigned long size);
extern void MIi_CpuCopyFast(void *srcp, void *destp, unsigned long size);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern int Yos_BitWrite(u8 *dst, unsigned long *ptr, unsigned long num, unsigned long size);
extern void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int OS_IsRunOnTwl(void);
extern void AESi_Init(void);
extern int AESi_SignForJpeg(u8 *sign, u8 *dst, u32 ptr);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern unsigned long _u32_div_f(unsigned long a, unsigned long b);
extern unsigned long SSP_ExifEncode(u8 *l_dst, unsigned long width, unsigned long height,
                                    u8 *thumb_src, unsigned long thumb_size);
extern unsigned long Yos_JPEGEncode(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, int thumb, unsigned char *thumb_src, unsigned long thumb_size, void (*func)(void *, unsigned long, unsigned long, void *));
void Yos_BitInit(void);
int Yos_JpegEncoderHuffmanEncoderPrintTable(u8 *huff, u8 *dst, u32 *pos);
int Yos_JpegEncoderHuffmanEncoderOutputSize(unsigned char *p);
void Yos_JpegEncodeSample2to2Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
void Yos_JpegEncodeSample2to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
void Yos_JpegEncodeSample1to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
unsigned long Yos_JPEGGetMemorySize(unsigned long width, unsigned long height, unsigned long sampling);
unsigned long SSP_GetJpegEncoderBufferSize(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);
void SSP_JpegEncoderResample(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
void SSP_RGB555ToYUV888(void *src, unsigned long width, unsigned long height, void *dst);
void SSP_YUV422ToYUV888(void *src, unsigned long width, unsigned long height, void *dst);
int SSPi_JpegEncoderCheckWidthHeight(u32 width, u32 height, u32 samplingFormat);
unsigned long SSP_StartJpegEncoder(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);
extern unsigned long gJpegBitMask[];
extern u8 JpegZigZagInputOrderCodes[64];
extern u8 luminance_quantization_table[64];
extern u8 chrominance_quantization_table[64];
extern long scaleTable[256];
extern u8 thumbnail[25];
extern u8 jfif[23];
extern u8 jsos[14];
extern int SSPiEncodeSignCheckMode;



static unsigned long gBitCode = 0;


static unsigned long gBitLen = 0;


static unsigned long gWriteLimit = 0;

/*
 * Clear the word at +4 of gJpegBitWriterState and set the word at +0 to 8.
 *
 * Addresses are Black-image addresses.
 */
void Yos_BitInit(void)
{
    gBitCode = 0;
    gBitLen = 8;
}





/*
 * sdk:      Yos_BitWrite (jpegenc.o)
 *
 * note: gBitLen/gBitCode/gWriteLimit are three adjacent file statics in
 * ov172's bss (zero-initialised; offsets 0/4/8 from 0x021CADE4).  The
 * relocation against `.bss` is placed by the three symbols: lines, which keep
 * the compiled layout (gBitCode is declared first so the compiler lays len
 * out at +0).
 */
int Yos_BitWrite(unsigned char *dst, unsigned long *ptr, unsigned long num, unsigned long size)
{
    unsigned long i;

    for (i = size; i != 0; i--) {
        if (num & gJpegBitMask[i])
            gBitCode |= gJpegBitMask[gBitLen];
        gBitLen--;
        if (gBitLen == 0) {
            dst[*ptr] = gBitCode;
            if (gBitCode == 0xff) {
                if (*ptr + 2 >= gWriteLimit)
                    return 0;
                dst[*ptr + 1] = 0;
                *ptr += 2;
            } else {
                *ptr += 1;
                if (*ptr >= gWriteLimit)
                    return 0;
            }
            gBitCode = 0;
            gBitLen = 8;
        }
    }
    return 1;
}






static void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output)
{
    long tmp[64];
    long dst;
    long loop;
    long a0, a1, a2, a3, a4, a5, a6, a7;
    long c0, c1, c2, c3, c4, c5, c6, c7;

    for (loop = 0; loop < 8; loop++) {
        a0 = data[loop + 0] + data[loop + 56] - 256;
        a1 = data[loop + 8] + data[loop + 48] - 256;
        a2 = data[loop + 16] + data[loop + 40] - 256;
        a3 = data[loop + 24] + data[loop + 32] - 256;
        a4 = data[loop + 24] - data[loop + 32];
        a5 = data[loop + 16] - data[loop + 40];
        a6 = data[loop + 8] - data[loop + 48];
        a7 = data[loop + 0] - data[loop + 56];

        c0 = a0 + a3;
        c1 = a1 + a2;
        a1 = a1 - a2 + a0 - a3;
        a0 = a0 - a3;
        a2 = a5 + a6;
        a6 = a6 + a7;

        a5 = a4 + a5 + a6;

        c2 = a1 * 181;
        c3 = a2 * 181;
        c4 = a5 * 98;
        c5 = a5 * 237;
        c6 = a6 * 139;
        c7 = a6 * 334;

        tmp[loop + 0] = (c0 + c1) << 8;
        tmp[loop + 32] = (c0 - c1) << 8;
        tmp[loop + 16] = c2 + (a0 << 8);
        tmp[loop + 48] = (a0 << 8) - c2;
        tmp[loop + 8] = c3 + (a7 << 8) + c4 + c6;
        tmp[loop + 40] = (a7 << 8) - c3 + c5 - c7;
        tmp[loop + 24] = (a7 << 8) - c3 - c5 + c7;
        tmp[loop + 56] = c3 + (a7 << 8) - c4 - c6;
    }

    for (loop = dst = 0; loop < 8; loop++, dst += 8) {
        a0 = tmp[dst + 0] + tmp[dst + 7];
        a1 = tmp[dst + 1] + tmp[dst + 6];
        a2 = tmp[dst + 2] + tmp[dst + 5];
        a3 = tmp[dst + 3] + tmp[dst + 4];
        a4 = tmp[dst + 3] - tmp[dst + 4];
        a5 = tmp[dst + 2] - tmp[dst + 5];
        a6 = tmp[dst + 1] - tmp[dst + 6];
        a7 = tmp[dst + 0] - tmp[dst + 7];

        c0 = a0 + a3;
        c1 = a1 + a2;
        a1 = a1 - a2 + a0 - a3;
        a0 = a0 - a3;
        a2 = a5 + a6;
        a6 = a6 + a7;

        a5 = a4 + a5 + a6;

        c2 = a1 * 181;
        c3 = a2 * 181;
        c4 = a5 * 98;
        c5 = a5 * 237;
        c6 = a6 * 139;
        c7 = a6 * 334;

        output[dst + 0] = ((((c0 + c1) + 128) >> 8) * qtable[loop * 8 + 0] + 0x800) >> 12;
        output[dst + 1] = (((c3 + (a7 << 8) + c4 + c6 + 0x8000) >> 16) * qtable[loop * 8 + 1] + 0x800) >> 12;
        output[dst + 2] = (((c2 + (a0 << 8) + 0x8000) >> 16) * qtable[loop * 8 + 2] + 0x800) >> 12;
        output[dst + 3] = ((((a7 << 8) - c3 - c5 + c7 + 0x8000) >> 16) * qtable[loop * 8 + 3] + 0x800) >> 12;
        output[dst + 4] = ((((c0 - c1) + 128) >> 8) * qtable[loop * 8 + 4] + 0x800) >> 12;
        output[dst + 5] = ((((a7 << 8) - c3 + c5 - c7 + 0x8000) >> 16) * qtable[loop * 8 + 5] + 0x800) >> 12;
        output[dst + 6] = ((((a0 << 8) - c2 + 0x8000) >> 16) * qtable[loop * 8 + 6] + 0x800) >> 12;
        output[dst + 7] = (((c3 + (a7 << 8) - c4 - c6 + 0x8000) >> 16) * qtable[loop * 8 + 7] + 0x800) >> 12;
    }
}






extern u8 dc0_tbl[28] __attribute__((aligned(32)));
extern u8 dc1_tbl[28] __attribute__((aligned(32)));
extern u8 ac0_tbl[178] __attribute__((aligned(32)));
extern u8 ac1_tbl[178] __attribute__((aligned(32)));

























static void Yos_JpegEncoderHuffmanEncoderBuildTable(Yos_JpegEncoderHuffmanEncoderBuildTableWork *pWork,
                          huffman_structure *hf, unsigned long idx)
{
    unsigned long ii;
    unsigned long jj;
    unsigned long kk;
    unsigned long si;
    u16 code = 0;


    MIi_CpuClearFast(0, &hf->mHuffBits[0], 0x428);

    switch (idx) {
    case 0: MIi_CpuCopyFast(dc0_tbl, &hf->mHuffBits[0], 0x10); break;
    case 1: MIi_CpuCopyFast(dc1_tbl, &hf->mHuffBits[0], 0x10); break;
    case 2: MIi_CpuCopyFast(ac0_tbl, &hf->mHuffBits[0], 0x10); break;
    case 3: MIi_CpuCopyFast(ac1_tbl, &hf->mHuffBits[0], 0x10); break;
    }

    switch (idx) {
    case 0: MIi_CpuCopyFast(dc0_tbl + 0x10, &hf->mHuffValues[0], 0xc); break;
    case 1: MIi_CpuCopyFast(dc1_tbl + 0x10, &hf->mHuffValues[0], 0xc); break;
    case 2: MI_CpuCopy(ac0_tbl + 0x10, &hf->mHuffValues[0], 0xa2); break;
    case 3: MI_CpuCopy(ac1_tbl + 0x10, &hf->mHuffValues[0], 0xa2); break;
    }

    MIi_CpuClearFast(0, pWork, 0x400);
    ii = 0;
    kk = 0;
    while (ii < 0x10) {
        for (jj = 0; jj < hf->mHuffBits[ii]; jj++)
            pWork->mHuffSize[kk++] = ii + 1;
        pWork->mHuffSize[kk] = 0;
        ii++;
    }

    MIi_CpuClearFast(0, pWork->mHuffCode, 0x400);
    kk = 0;
    si = pWork->mHuffSize[0];
    while (pWork->mHuffSize[kk] != 0) {
        while (pWork->mHuffSize[kk] == si) {
            pWork->mHuffCode[kk++] = code++;
        }
        si++;
        code = code << 1;
    }

    for (kk = 0; kk < 0x100; kk++) {
        if (pWork->mHuffSize[kk] != 0) {
            si = hf->mHuffValues[kk];
            hf->mEhufco[si] = pWork->mHuffCode[kk];
            hf->mEhufsi[si] = pWork->mHuffSize[kk];
        }
    }
}






/*
 * Block copier with a running sum: appends the 16 bytes at a0+0x404 to the
 * output buffer a1 (advancing the cursor *a2), accumulates their sum, then
 * appends `sum` more bytes from a0+0x424.  Both the pre-check and the post-check
 * compare the cursor (plus 0x10, then plus sum) against the limit at +8 of
 * gJpegBitWriterState and return 0 when the buffer would overrun; returns 1 otherwise.
 * The limit is re-read from the global at each of the two sites (the global is
 * volatile in the original), which is what makes the pool word load twice.
 *
 * Addresses are Black-image addresses.
 */
int Yos_JpegEncoderHuffmanEncoderPrintTable(u8 *huff, u8 *dst, u32 *pos)
{
    u32 v;
    u32 i;
    u32 sum = 0;

    if (*pos + 0x10 >= ((unsigned long *)&gBitLen)[2])
        return 0;

    for (i = 0; i < 0x10; i++) {
        v = huff[i + 0x404];
        dst[*pos] = v;
        (*pos)++;
        sum += v;
    }

    if (*pos + sum >= ((unsigned long *)&gBitLen)[2])
        return 0;

    for (i = 0; i < sum; i++) {
        dst[*pos] = huff[i + 0x424];
        (*pos)++;
    }
    return 1;
}





/*
 * Symbols:
 *   (none)
 *
 * Sums 16 bytes at +0x404 and returns the total plus 0x11.
 *
 * Addresses are Black-image addresses.
 */
int Yos_JpegEncoderHuffmanEncoderOutputSize(unsigned char *p)
{
    unsigned int i;
    int sum = 0;

    for (i = 0; i < 0x10; i++)
        sum += p[i + 0x404];

    return sum + 0x11;
}






static int Yos_JpegEncoderComponentSequential(huffman_structure *dc, huffman_structure *ac,
                                              component_structure *component, u8 *dst,
                                              unsigned long *ptr, unsigned long col, unsigned long row)
{
    unsigned long index;
    unsigned long ssss;
    unsigned long zerorun;
    long bits;
    short *du;
    long diff;
    int value;
    unsigned long rrrrssss;
    unsigned long inner_tmp;

    du = component->mCofficients + (row * component->mCols + col) * 64;
    value = du[0];
    diff = value - component->mLastDcValue;
    component->mLastDcValue = value;

    if (diff >= 0) {
        value = diff;
    } else {
        diff = -diff;
        value = ~diff;
    }
    index = 0;
    while (diff != 0) {
        index++;
        diff >>= 1;
    }

    if (!Yos_BitWrite(dst, ptr, dc->mEhufco[index], dc->mEhufsi[index]))
        return 0;
    if (index != 0) {
        if (!Yos_BitWrite(dst, ptr, value, index))
            return 0;
    }

    zerorun = 0;
    for (ssss = 1; ssss < 64; ssss++) {
        if (du[JpegZigZagInputOrderCodes[ssss]] != 0) {
            while (zerorun >= 16) {
                if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0xF0], ac->mEhufsi[0xF0]))
                    return 0;
                zerorun -= 16;
            }
            value = du[JpegZigZagInputOrderCodes[ssss]];
            if (value >= 0) {
                bits = value;
            } else {
                value = -value;
                bits = ~value;
            }
            for (inner_tmp = 0; value != 0; inner_tmp++)
                value >>= 1;
            rrrrssss = inner_tmp | (zerorun << 4);
            if (!Yos_BitWrite(dst, ptr, ac->mEhufco[rrrrssss], ac->mEhufsi[rrrrssss]))
                return 0;
            if (inner_tmp != 0) {
                if (!Yos_BitWrite(dst, ptr, bits, inner_tmp))
                    return 0;
            }
            zerorun = 0;
        } else {
            zerorun++;
        }
    }
    if (zerorun != 0) {
        if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0], ac->mEhufsi[0]))
            return 0;
    }
    return 1;
}






void Yos_JpegEncodeSample2to2Component(unsigned char *buffer, long *qTable,
                                       component_structure *component, unsigned long dx)
{
    unsigned char data[64];
    unsigned long v;
    unsigned long x;
    unsigned long y;
    unsigned long u;
    unsigned long z;
    short *dct_coff;
    unsigned long cx;
    unsigned long cy;

    cy = component->mRows;
    dct_coff = component->mCofficients;
    cx = component->mCols;
    for (y = 0, v = 0; y < cy; y++) {
        for (x = 0; x < cx; x++) {
            u = ((y << 4) * dx) + (x << 4);
            for (z = 0; z < 64; z += 8) {
                data[z + 0] = (buffer[u + 0] + buffer[u + 1] + buffer[u + dx + 0] + buffer[u + dx + 1]) >> 2;
                data[z + 1] = (buffer[u + 2] + buffer[u + 3] + buffer[u + dx + 2] + buffer[u + dx + 3]) >> 2;
                data[z + 2] = (buffer[u + 4] + buffer[u + 5] + buffer[u + dx + 4] + buffer[u + dx + 5]) >> 2;
                data[z + 3] = (buffer[u + 6] + buffer[u + 7] + buffer[u + dx + 6] + buffer[u + dx + 7]) >> 2;
                data[z + 4] = (buffer[u + 8] + buffer[u + 9] + buffer[u + dx + 8] + buffer[u + dx + 9]) >> 2;
                data[z + 5] = (buffer[u + 10] + buffer[u + 11] + buffer[u + dx + 10] + buffer[u + dx + 11]) >> 2;
                data[z + 6] = (buffer[u + 12] + buffer[u + 13] + buffer[u + dx + 12] + buffer[u + dx + 13]) >> 2;
                data[z + 7] = (buffer[u + 14] + buffer[u + 15] + buffer[u + dx + 14] + buffer[u + dx + 15]) >> 2;
                u += dx * 2;
            }
            Yos_JpegEncoderForwardDct(data, qTable, dct_coff + v * 64);
            v++;
        }
    }
}






/*
 * sdk:      Yos_JpegEncodeSample2to1Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * Static: horizontal 2:1 chroma subsampling of a component plane into 8x8 blocks, each handed to the forward DCT.
 */
void Yos_JpegEncodeSample2to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx)
{
    unsigned char data[64];
    unsigned long v;
    unsigned long u;
    unsigned long x;
    unsigned long y;
    unsigned long z;
    short *dct_coff;
    unsigned long cx;
    unsigned long cy;

    cy = component->mRows;
    dct_coff = component->mCofficients;
    cx = component->mCols;
    for (y = 0, v = 0; y < cy; y++) {
        for (x = 0; x < cx; x++) {
            u = ((y << 3) * dx) + (x << 4);
            for (z = 0; z < 64; z += 8) {
            data[z + 0] = (buffer[u + 0] + buffer[u + 1]) >> 1;
            data[z + 1] = (buffer[u + 2] + buffer[u + 3]) >> 1;
            data[z + 2] = (buffer[u + 4] + buffer[u + 5]) >> 1;
            data[z + 3] = (buffer[u + 6] + buffer[u + 7]) >> 1;
            data[z + 4] = (buffer[u + 8] + buffer[u + 9]) >> 1;
            data[z + 5] = (buffer[u + 10] + buffer[u + 11]) >> 1;
            data[z + 6] = (buffer[u + 12] + buffer[u + 13]) >> 1;
            data[z + 7] = (buffer[u + 14] + buffer[u + 15]) >> 1;
                u += dx;
            }
            Yos_JpegEncoderForwardDct(data, qTable, dct_coff + v * 64);
            v++;
        }
    }
}






/*
 * sdk:      Yos_JpegEncodeSample1to1Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * Static: copies an unsubsampled component plane into 8x8 blocks through eight row pointers, each block handed to the forward DCT.
 */
void Yos_JpegEncodeSample1to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx)
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
            Yos_JpegEncoderForwardDct(data, qTable, dct_coff + v * 64);
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
unsigned long Yos_JPEGGetMemorySize(unsigned long width, unsigned long height, unsigned long sampling)
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
unsigned long SSP_GetJpegEncoderBufferSize(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option)
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
    mainSize = Yos_JPEGGetMemorySize(width, height, sampling);
    thumbSize = Yos_JPEGGetMemorySize(160, 120, 1);
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

    if (((unsigned long *)&gBitLen)[2] < 0x17)
        return 0;

    offset = dst[0x13] + 0xc;
    if (offset + 2 > ((unsigned long *)&gBitLen)[2])
        return 0;
    p = dst + offset;
    registrationNumber = (u16)((p[1] + (dst[offset] << 8)));
    offset += 2;
    if (registrationNumber * 0xc + offset > ((unsigned long *)&gBitLen)[2])
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

    if (offset + 2 > ((unsigned long *)&gBitLen)[2])
        return 0;
    p = dst + offset;
    registrationNumber = (u16)((p[1] + (dst[offset] << 8)));
    offset += 2;
    if (registrationNumber * 0xc + offset > ((unsigned long *)&gBitLen)[2])
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

    if (offset + 4 > ((unsigned long *)&gBitLen)[2])
        return 0;
    p = dst + offset;
    if (p[2] != 0x10 || p[3] != 0)
        return 0;
    if (offset + 0xe > ((unsigned long *)&gBitLen)[2])
        return 0;

    offset = (((u32)p[0xa] << 24) + ((u32)p[0xb] << 16) +
              ((u32)p[0xc] << 8) + p[0xd]) + 0xc;
    if (offset + 0x1c > ((unsigned long *)&gBitLen)[2])
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






/*
 * closed (lane 09, 2026-10-01): DWARF homes `src` in r6, so the running pointer is the
 *           parameter (`pRgb = src` each pass, `src = pRgb + 1`): that settles the
 *           {width, src, x} = {r5, r6, r7} tie. Then gg/rr in that statement order with
 *           the Y sum written rr*0x4c9 first, and the Cr base as
 *           `(u8 *)(y + (u32)(ybuf + y))` (inner add pointer-first, outer integer add
 *           y-first, per a-pointer-plus-integer-add-is-normalised...).
 * sdk:      SSP_RGB555ToYUV888 (libssp.TWL.HYB.a jpegenc.o)
 *
 * RGB555 -> planar YCbCr (three padded planes, stride (w+7)&~7).
 *
 * Lane U28 (2026-09-30): rewritten from the vendor DWARF, replacing the flat
 * `i % stride` draft.  DWARF locals, in source declaration order (the reverse
 * of sdkobj.py's print): j, x, y, pRgb, ybuf, crbuf, image_width, rr, gg, bb.
 * Measured against the image (332 bytes):
 *   222 concrete bytes  flat draft (`u32 i`, `i % stride`, d0/d1/d2[], r/g/b)
 *   260 concrete bytes  + the DWARF locals but with an explicit
 *                       `if (y == 0) return;`   (344 bytes: the guard and the
 *                       `for` entry test both survive -> cmp+addls+popls)
 *    37 concrete bytes  this file (332 bytes, size EXACT)
 * The one lever that mattered: do NOT write the `y == 0` guard.  The `for`
 * entry test is rotated and folds straight into the `muls r8, sl, r1` flags,
 * which is exactly the image's `addeq sp, sp, #0x10 / popeq {...}`.  The four
 * literal-pool words (0x1d3, 0x4c9, 0x964, 0x80800) and the whole constant
 * setup (+0x3C..+0x64) now match the image byte for byte.
 *
 * Residue (one allocation tie, three registers + its knock-ons):
 *   +0x0008  image `mov r5, r1`   | ours `mov r6, r1`   (width)
 *   +0x0028  image `mov r6, r0`   | ours `mov r7, r0`   (pRgb)
 *   +0x0030  image `mov r7, #0`   | ours `mov r5, #0`   (x)
 * i.e. the image colours {width, pRgb, x} = {r5, r6, r7} in declaration order,
 * ours = {r6, r7, r5}; x gets the lowest register here.  Everything else in
 * the 37 bytes follows from it (+0x0068/0x0074/0x0078/0x00BC/0x00EC/0x011C/
 * 0x0124/0x0128/0x012C and the gg/rr mask pair at +0x0084..0x0090).
 * Also differing: +0x0020 image `add r4, r3, r8` | ours `add r4, r8, r3` (the
 * Cb-plane base; same encoding, different canonical operand order).
 *
 * Tried this lane, none below 37 (all 332 bytes unless noted): 9 local
 * declaration orders (x before j, pointers first), `j = x % image_width;` as a
 * separate statement, crbuf = ybuf + y * 2 (336), y = hpad * image_width,
 * ybuf[x + y], `((u16 *)((u8 *)ybuf + y))[x]` (340), a while loop (284), and
 * the three store orders (Cb first, Cr first).
 *
 * Wave 8 (2026-10-01): swapped the two mask/shift temporaries — `rr` first,
 * then `gg` (both read `bb` before line 106, so inert) — 37 -> 34 bytes.
 * It moves the low scratch (r0) to the temp written first and the next (r2)
 * to the temp written second, and the instruction schedule follows source
 * order; see docs/idioms/statement-order-of-scratch-temporaries-decides-their-registers.md.
 * `unsigned long x` instead of `u32 x` (idiom a-long-index...) is 48 (worse).
 * Inert at 34 too — `const u32 width`, `const void *src` + `const u16 *pRgb`,
 * `ybuf` assigned before `pRgb`, `pRgb` declared before `x`, `x` declared
 * last with `u32 x = 0;` as a declaration initialiser, and reusing the dead
 * `height` parameter as the loop index (285, much worse).  The 3-cycle is
 * unforced by any source lever tried across two lanes; see
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md
 * (its shape matches, but this function's index is a genuine fresh local).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/SSP_RGB555ToYUV888.c \
 *     --func SSP_RGB555ToYUV888 --addr 0x021C1F04 --region ov172 --arm --cc 1.1p1 \
 *     --lang c99 --diff
 */
void SSP_RGB555ToYUV888(void *src, unsigned long width, unsigned long height, void *dst)
{
    unsigned long j;
    unsigned long x;
    unsigned long y;
    unsigned short *pRgb;
    unsigned char *ybuf;
    unsigned char *crbuf;
    unsigned long image_width;
    unsigned long rr;
    unsigned long gg;
    unsigned long bb;

    image_width = (width + 7) & ~7;
    y = image_width * ((height + 7) & ~7);
    ybuf = (u8 *)dst;
    crbuf = (u8 *)(y + (u32)(ybuf + y));
    for (x = 0; x < y; x++) {
        pRgb = (u16 *)src;
        bb = (x % image_width < width) ? *pRgb : 0;
        rr = (bb & 0x1f) << 3;
        gg = (bb & 0x3e0) >> 2;
        bb = (bb & 0x7c00) >> 7;
        ybuf[x] = (u8)((rr * 0x4c9 + gg * 0x964 + bb * 0x1d3 + 0x800) >> 12);
        j = (0x80800 - rr * 0x2b3 - gg * 0x54d + (bb << 11)) >> 12;
        if (j > 0xff)
            j = 0xff;
        ybuf[y + x] = (u8)j;
        j = ((rr << 11) + 0x80800 - gg * 0x6b3 - bb * 0x14d) >> 12;
        if (j > 0xff)
            j = 0xff;
        crbuf[x] = (u8)j;
        if (x % image_width < width)
            src = pRgb + 1;
    }
}





void SSP_YUV422ToYUV888(void *src, unsigned long width, unsigned long height, void *dst)
{
    unsigned long yuyv;
    unsigned long x;
    unsigned long y;
    unsigned long *pYuyv;
    unsigned short *ybuf;
    unsigned short *cbbuf;
    unsigned short *crbuf;

    pYuyv = (unsigned long *)src;
    ybuf = (unsigned short *)dst;
    y = (width * height) >> 1;
    crbuf = ybuf + y + y;
    cbbuf = ybuf + y;
    for (x = 0; x < y; x++) {
        yuyv = *pYuyv++;
        ybuf[x] = (yuyv & 0xff) | ((yuyv & 0xff0000) >> 8);
        cbbuf[x] = (yuyv & 0xff00) | ((yuyv & 0xff00) >> 8);
        crbuf[x] = (yuyv >> 24) | ((yuyv & 0xff000000) >> 16);
    }
}













static void Yos_JpegEncoderHuffmanEncoderBuildTable(
    Yos_JpegEncoderHuffmanEncoderBuildTableWork *pWork, huffman_structure *hf, unsigned long idx);















static int Yos_JpegEncoderComponentSequential(huffman_structure *dc, huffman_structure *ac,
                                              component_structure *component, u8 *dst,
                                              unsigned long *ptr, unsigned long col, unsigned long row);



static int SSPi_JpegEncoderDoSign(u8 *dst, unsigned long ptr);




static unsigned long Yos_JPEGEncode(void *src, u8 *dst, unsigned long limit, u8 *wrk,
                                    unsigned long width, unsigned long height, unsigned long quality,
                                    unsigned long sampling, int thumb, u8 *thumb_src,
                                    unsigned long thumb_size,
                                    void (*func)(void *, unsigned long, unsigned long, void *))
{
    unsigned long j, x, y, cx, cy, ptr, mcu_cols, mcu_rows, samplingx = 1, samplingy = 1;
    long *QuantizeTable;
    u8 *ybuf, *cbbuf, *crbuf, *dqttbl;
    component_structure Component[3];
    huffman_structure *hf[4];
    Yos_JpegEncoderHuffmanEncoderBuildTableWork *pBuildTableWork;

    switch (sampling) {
    case 1:
        break;
    case 2:
        samplingx = samplingy = 2;
        break;
    case 3:
        samplingx = 2;
        break;
    }

    gWriteLimit = limit;
    mcu_cols = width / (samplingx * 8);
    mcu_rows = height / (samplingy * 8);
    cx = width >> 3;
    cy = height >> 3;

    QuantizeTable = (long *)wrk;
    dqttbl = wrk + 0x200;
    hf[0] = (huffman_structure *)(wrk + 0x280);
    hf[1] = (huffman_structure *)(wrk + 0xab0);
    hf[2] = (huffman_structure *)(wrk + 0x12e0);
    hf[3] = (huffman_structure *)(wrk + 0x1b10);
    pBuildTableWork = (Yos_JpegEncoderHuffmanEncoderBuildTableWork *)(wrk + 0x2340);

    x = cx / samplingx;
    y = cy / samplingy;

    Component[0].mCols = cx;
    Component[0].mRows = cy;
    Component[1].mCols = Component[2].mCols = x;
    Component[1].mRows = Component[2].mRows = y;
    Component[0].mCofficients = (short *)(wrk + 0x2b40);
    j = cx * cy * 128 + 0x2b40;
    x = x * y;
    Component[1].mCofficients = (short *)&wrk[j];
    Component[2].mCofficients = (short *)&wrk[j + x * 128];
    j += x * 256;
    ybuf = &wrk[j];
    Component[0].mLastDcValue = Component[1].mLastDcValue = Component[2].mLastDcValue = 0;

    ptr = width * height;
    cbbuf = &wrk[j + ptr];
    crbuf = &wrk[j + ptr * 2];

    if (quality >= 50) quality = 200 - quality * 2; else quality = 5000 / quality;
    for (y = 0; y < 64; y++) {
        x = (luminance_quantization_table[y] * quality + 50) / 100;
        if (x == 0) x = 1;
        if (x > 255) x = 255;
        dqttbl[y] = x;
        QuantizeTable[y] = scaleTable[y] / (long)x;
        x = (chrominance_quantization_table[y] * quality + 50) / 100;
        if (x == 0) x = 1;
        if (x > 255) x = 255;
        dqttbl[64 + y] = x;
        QuantizeTable[64 + y] = scaleTable[y] / (long)x;
    }

    if (func != 0)
        func(src, width, height, ybuf);

    Yos_JpegEncodeSample1to1Component(ybuf, QuantizeTable, &Component[0], width);

    if (sampling == 1) Yos_JpegEncodeSample1to1Component(cbbuf, QuantizeTable + 64, &Component[1], width);
    else if (sampling == 2) Yos_JpegEncodeSample2to2Component(cbbuf, QuantizeTable + 64, &Component[1], width);
    else Yos_JpegEncodeSample2to1Component(cbbuf, QuantizeTable + 64, &Component[1], width);

    if (sampling == 1) Yos_JpegEncodeSample1to1Component(crbuf, QuantizeTable + 64, &Component[2], width);
    else if (sampling == 2) Yos_JpegEncodeSample2to2Component(crbuf, QuantizeTable + 64, &Component[2], width);
    else Yos_JpegEncodeSample2to1Component(crbuf, QuantizeTable + 64, &Component[2], width);

    if (thumb) {
        if (gWriteLimit <= 25)
            return 0;
        MI_CpuCopy8(thumbnail, dst, 25);
        dst[7] = 0;
        dst[8] = 0x78;
        dst[9] = 0;
        dst[10] = 0xa0;
        dst[0xd] = samplingy | (samplingx << 4);
        ptr = 25;
    } else {
        ptr = SSP_ExifEncode(dst, width, height, thumb_src, thumb_size);
        if (ptr + 0x17 >= gWriteLimit)
            return 0;
        MI_CpuCopy8(jfif, dst + ptr, 0x17);
        dst[ptr + 5] = height >> 8;
        dst[ptr + 6] = (u8)height;
        dst[ptr + 7] = width >> 8;
        dst[ptr + 8] = (u8)width;
        dst[ptr + 0xb] = samplingy | (samplingx << 4);
        ptr += 0x17;
    }

    if (ptr + 0x82 >= gWriteLimit)
        return 0;
    dst[ptr++] = 0;
    for (j = 0; j < 64; j++) {
        dst[ptr] = dqttbl[JpegZigZagInputOrderCodes[j]];
        ptr++;
    }
    dst[ptr++] = 1;
    for (j = 0; j < 64; j++) {
        dst[ptr] = dqttbl[0x40 + JpegZigZagInputOrderCodes[j]];
        ptr++;
    }

    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, hf[0], 0);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, hf[2], 2);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, hf[1], 1);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, hf[3], 3);

    x = Yos_JpegEncoderHuffmanEncoderOutputSize((unsigned char *)hf[3])
          + (Yos_JpegEncoderHuffmanEncoderOutputSize((unsigned char *)hf[2])
          + (Yos_JpegEncoderHuffmanEncoderOutputSize((unsigned char *)hf[0]) + 2
          + Yos_JpegEncoderHuffmanEncoderOutputSize((unsigned char *)hf[1])));

    if (ptr + 4 >= gWriteLimit)
        return 0;
    dst[ptr] = 0xff;
    dst[ptr + 1] = 0xc4;
    dst[ptr + 2] = (u8)(x >> 8);
    dst[ptr + 3] = (u8)x;
    ptr += 4;
    dst[ptr++] = 0;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable((u8 *)hf[0], dst, (u32 *)&ptr))
        return 0;
    dst[ptr++] = 1;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable((u8 *)hf[1], dst, (u32 *)&ptr))
        return 0;
    dst[ptr++] = 0x10;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable((u8 *)hf[2], dst, (u32 *)&ptr))
        return 0;
    dst[ptr++] = 0x11;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable((u8 *)hf[3], dst, (u32 *)&ptr))
        return 0;

    for (j = 0; j < 3; j++)
        Component[j].mLastDcValue = 0;
    Yos_BitInit();

    if (ptr + 0xe > gWriteLimit)
        return 0;
    for (j = 0; j < 14; j++) {
        dst[ptr] = jsos[j];
        ptr++;
    }

    for (x = 0; x < mcu_rows; x++) {
        for (y = 0; y < mcu_cols; y++) {
            if (sampling == 1) {
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y, x))
                    return 0;
            } else if (sampling == 2) {
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y * 2, x * 2))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y * 2 + 1, x * 2))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y * 2, x * 2 + 1))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y * 2 + 1, x * 2 + 1))
                    return 0;
            } else {
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y * 2, x))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(hf[0], hf[2], &Component[0], dst, &ptr, y * 2 + 1, x))
                    return 0;
            }

            if (!Yos_JpegEncoderComponentSequential(hf[1], hf[3], &Component[1], dst, &ptr, y, x))
                return 0;
            if (!Yos_JpegEncoderComponentSequential(hf[1], hf[3], &Component[2], dst, &ptr, y, x))
                return 0;
        }
    }

    if (gBitLen != 8) {
        if (!Yos_BitWrite(dst, &ptr, 0, 7))
            return 0;
    }

    if (ptr + 2 >= gWriteLimit)
        return 0;
    dst[ptr] = 0xff;
    dst[ptr + 1] = 0xd9;
    ptr += 2;

    if (thumb) {
        if ((ptr & 1) == 1) {
            dst[ptr] = 0;
            ptr++;
        }
        return ptr;
    }
    if (SSPiEncodeSignCheckMode == 1 && OS_IsRunOnTwl() == 1) {
        if (SSPi_JpegEncoderDoSign(dst, ptr))
            return ptr;
        return 0;
    }
    return ptr;
}




/*
 * Range/alignment validator for a transfer pair: both addresses must be
 * non-zero and inside 0x10000, then the mode picks which of the two has to be
 * 8- or 16-byte aligned (1: both 8, 2: both 16, 3: first 16 and second 8).
 * Returns 1 when the pair is legal, 0 otherwise.  The three cases share the
 * out-of-line "return 1" tail and each keeps its own "return 0" as the
 * fall-through of its second test.
 *
 * Addresses are Black-image addresses.
 */
int SSPi_JpegEncoderCheckWidthHeight(u32 width, u32 height, u32 samplingFormat)
{
    if (width == 0 || width > 0xffff || height == 0 || height > 0xffff)
        return 0;
    switch (samplingFormat) {
    case 1:
        if ((width & 7) != 0 || (height & 7) != 0)
            return 0;
        break;
    case 2:
        if ((width & 0xf) != 0 || (height & 0xf) != 0)
            return 0;
        break;
    case 3:
        if ((width & 0xf) != 0 || (height & 7) != 0)
            return 0;
        break;
    default:
        return 0;
    }
    return 1;
}




/*
 * sdk:      SSP_StartJpegEncoder (jpegenc.o)
 */
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
