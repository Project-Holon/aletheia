/*
 * file:     unit_021C0C20_p05.c
 * unit:     yes
 * function: func_021C20B0, func_021C2AD0, func_021C2B74
 * address:  0x021C20B0
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
 *   _u32_div_f                       0x0209C2B0  arm
 *   _s32_div_f                       0x0209C0A4  arm
 *   Yos_JpegEncodeSample1to1Component 0x021C1868 arm
 *   Yos_JpegEncodeSample2to2Component 0x021C1500 arm
 *   Yos_JpegEncodeSample2to1Component 0x021C1710 arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   SSP_ExifEncode                   0x021C4B9C  arm
 *   Yos_JpegEncoderHuffmanEncoderBuildTable 0x021C104C arm
 *   Yos_JpegEncoderHuffmanEncoderOutputSize 0x021C12F4 arm
 *   Yos_JpegEncoderHuffmanEncoderPrintTable 0x021C1248 arm
 *   Yos_BitInit                      0x021C0C20  arm
 *   Yos_JpegEncoderComponentSequential 0x021C131C arm
 *   Yos_BitWrite                     0x021C0C3C  arm
 *   OS_IsRunOnTwl                    0x02085D3C  arm
 *   SSPi_JpegEncoderDoSign           0x021C1AE4  arm
 *   gBitLen                          0x021CADE4  data
 *   gBitCode                         0x021CADE8  data
 *   gWriteLimit                      0x021CADEC  data
 *   luminance_quantization_table     0x021C853C  data
 *   scaleTable                       0x021C8774  data
 *   chrominance_quantization_table   0x021C857C  data
 *   thumbnail                        0x021C84E5  data
 *   jfif                             0x021C84CE  data
 *   JpegZigZagInputOrderCodes        0x021C85BC  data
 *   jsos                             0x021C84C0  data
 *   SSPiEncodeSignCheckMode          0x021CADF8  data
 *   func_021C1D8C  0x021C1D8C  arm  ov172
 *   func_021C20B0  0x021C20B0  arm  ov172
 *   func_021C2050  0x021C2050  arm  ov172
 *   func_021C1F04  0x021C1F04  arm  ov172
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021C20B0;

typedef struct component_structure {
    short *mCofficients;
    u32_021C20B0 mCols;
    u32_021C20B0 mRows;
    long mLastDcValue;
} component_structure;

typedef struct huffman_structure {
    u32_021C20B0 mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[264];
} huffman_structure;

typedef struct Yos_JpegEncoderHuffmanEncoderBuildTableWork {
    u32_021C20B0 huffsizes[256];
    u32_021C20B0 huffcodes[256];
} Yos_JpegEncoderHuffmanEncoderBuildTableWork;

typedef unsigned int u32_021C2AD0;

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned long SSP_ExifEncode(u8 *l_dst, unsigned long width, unsigned long height,
                                    u8 *thumb_src, unsigned long thumb_size);
extern int OS_IsRunOnTwl(void);
extern void func_021C1D8C(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
extern unsigned long func_021C20B0(void *src, unsigned char *dst, unsigned long limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, int thumb, unsigned char *thumb_src, unsigned long thumb_size, void (*func)(void *, unsigned long, unsigned long, void *));
extern void func_021C2050(void *src, unsigned long width, unsigned long height, void *dst);
extern void func_021C1F04(void *src, unsigned long width, unsigned long height, void *dst);
int func_021C2AD0(u32_021C2AD0 a0, u32_021C2AD0 a1, u32_021C2AD0 a2);
unsigned long func_021C2B74(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);
extern u8 luminance_quantization_table[64];
extern u8 chrominance_quantization_table[64];
extern long scaleTable[256];
extern u8 thumbnail[25];
extern u8 jfif[23];
extern u8 JpegZigZagInputOrderCodes[64];
extern u8 jsos[14];
extern int SSPiEncodeSignCheckMode;

static unsigned long gBitCode = 0;

static unsigned long gBitLen = 0;

static unsigned long gWriteLimit = 0;


static void Yos_JpegEncodeSample1to1Component(u8 *buffer, long *qTable,
                                              component_structure *component, unsigned long dx);

static void Yos_JpegEncodeSample2to2Component(u8 *buffer, long *qTable,
                                              component_structure *component, unsigned long dx);

static void Yos_JpegEncodeSample2to1Component(u8 *buffer, long *qTable,
                                              component_structure *component, unsigned long dx);

static void Yos_JpegEncoderHuffmanEncoderBuildTable(
    Yos_JpegEncoderHuffmanEncoderBuildTableWork *pWork, huffman_structure *hf, unsigned long idx);

static unsigned long Yos_JpegEncoderHuffmanEncoderOutputSize(huffman_structure *hf);

static int Yos_JpegEncoderHuffmanEncoderPrintTable(huffman_structure *hf, u8 *dst, unsigned long *ptr);

static void Yos_BitInit(void);

static int Yos_BitWrite(u8 *dst, unsigned long *ptr, unsigned long num, unsigned long size);

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

    x = Yos_JpegEncoderHuffmanEncoderOutputSize(hf[3])
          + (Yos_JpegEncoderHuffmanEncoderOutputSize(hf[2])
          + (Yos_JpegEncoderHuffmanEncoderOutputSize(hf[0]) + 2
          + Yos_JpegEncoderHuffmanEncoderOutputSize(hf[1])));

    if (ptr + 4 >= gWriteLimit)
        return 0;
    dst[ptr] = 0xff;
    dst[ptr + 1] = 0xc4;
    dst[ptr + 2] = (u8)(x >> 8);
    dst[ptr + 3] = (u8)x;
    ptr += 4;
    dst[ptr++] = 0;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(hf[0], dst, &ptr))
        return 0;
    dst[ptr++] = 1;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(hf[1], dst, &ptr))
        return 0;
    dst[ptr++] = 0x10;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(hf[2], dst, &ptr))
        return 0;
    dst[ptr++] = 0x11;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(hf[3], dst, &ptr))
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
int func_021C2AD0(u32_021C2AD0 a0, u32_021C2AD0 a1, u32_021C2AD0 a2)
{
    if (a0 == 0 || a0 > 0xffff || a1 == 0 || a1 > 0xffff)
        return 0;
    switch (a2) {
    case 1:
        if ((a0 & 7) != 0 || (a1 & 7) != 0)
            return 0;
        break;
    case 2:
        if ((a0 & 0xf) != 0 || (a1 & 0xf) != 0)
            return 0;
        break;
    case 3:
        if ((a0 & 0xf) != 0 || (a1 & 7) != 0)
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
unsigned long func_021C2B74(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option)
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
