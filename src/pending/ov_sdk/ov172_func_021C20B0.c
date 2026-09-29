/*
 * function: Yos_JPEGEncode
 * address:  0x021C20B0
 * packet:   pkt_ov172_021C20B0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen/register pressure (2209 of 2430 concrete bytes differ;
 *   compiled 2512 B vs original 2548 B / listing extent 2592 B, first
 *   divergence at +0x0000: 0x70 frame and a tail `push {r3,...}`, the
 *   original 0x74 and a clean {r4..fp,lr}). Full JPEG encoder body is
 *   reconstructed from the ov172 listing plus the DWARF parameter/variable
 *   map (sdkobj): quality->quant-table scaling, Y/Cb/Cr resample, EXIF/JFIF/
 *   thumbnail/SOF/DQT/DHT/SOS header emission, Huffman-table build, the
 *   per-sampling MCU loop (ComponentSequential), EOI and optional TWL sign.
 *   Logic and call order match; the whole function does not reproduce because
 *   the original keeps ~15 live values in one 0x74 frame and recycles the
 *   callee-saved set across phases (fp=width, then fp=1; r7/r6 = cx/cy then
 *   loop counters), which a first-principles declaration order cannot pin.
 *   Relocations: 49/52 resolved. Unresolved and unwitnessed: gWriteLimit
 *   (declared 0x021CADEC), thumbnail (0x021C84E5), jfif (0x021C84CE) - all
 *   ABS32 data whose only image referrer is inside this range.
 *   Residue to attack next: (1) the original references the write limit as
 *   pool base gBitLen +8 (0x021CADE4+8 = 0x021CADEC), NOT a standalone symbol;
 *   declare it as a field of a struct pinned at gBitLen, or the site can
 *   never be a `sole-ref`/`label` witness; (2) `v` is unsigned for the
 *   0..255 clamp but the quant divide is _s32_div_f, so the source casts
 *   (long)v - keep that cast; (3) declare the locals in the DWARF offsets'
 *   order (src 0xc, samplingy 0x1c, samplingx 0x20, mcu_rows 0x24,
 *   mcu_cols 0x28, ... ptr 0x40, Component 0x44) to recover the frame and
 *   the callee-saved assignment; (4) the sampling discrimination is an
 *   `if (sampling == 1) {} else { if (==2) ... else if (==3) ... }`, not a
 *   switch, and quality is compared <= 0x32 with `scale = 200 - 2*q`.
 *
 * sdk:      Yos_JPEGEncode (libssp.TWL.HYB.a jpegenc.o)
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
 *   gWriteLimit                      0x021CADEC  data
 *   luminance_quantization_table     0x021C853C  data
 *   scaleTable                       0x021C8774  data
 *   chrominance_quantization_table   0x021C857C  data
 *   thumbnail                        0x021C84E5  data
 *   jfif                             0x021C84CE  data
 *   JpegZigZagInputOrderCodes        0x021C85BC  data
 *   jsos                             0x021C84C0  data
 *   SSPiEncodeSignCheckMode          0x021CADF8  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct component_structure {
    short *mCofficients;
    u32 mCols;
    u32 mRows;
    long mLastDcValue;
} component_structure;

typedef struct huffman_structure {
    u32 mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[260];
} huffman_structure;

typedef struct Yos_JpegEncoderHuffmanEncoderBuildTableWork {
    u32 huffsizes[256];
    u32 huffcodes[256];
} Yos_JpegEncoderHuffmanEncoderBuildTableWork;

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned long SSP_ExifEncode(u8 *l_dst, unsigned long width, unsigned long height,
                                    u8 *thumb_src, unsigned long thumb_size);
extern int OS_IsRunOnTwl(void);

extern u8 luminance_quantization_table[64];
extern u8 chrominance_quantization_table[64];
extern long scaleTable[256];
extern u8 thumbnail[25];
extern u8 jfif[23];
extern u8 JpegZigZagInputOrderCodes[64];
extern u8 jsos[14];
extern unsigned long gBitLen;
extern unsigned long gWriteLimit;
extern int SSPiEncodeSignCheckMode;

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
    component_structure Component[3];
    Yos_JpegEncoderHuffmanEncoderBuildTableWork *pBuildTableWork;
    u8 *dqttbl;
    long *QuantizeTable;
    huffman_structure *dcY, *acY, *dcC, *acC;
    unsigned long samplingx;
    unsigned long samplingy;
    unsigned long mcu_cols;
    unsigned long mcu_rows;
    unsigned long chroma_cols;
    unsigned long chroma_rows;
    unsigned long cx;
    unsigned long cy;
    unsigned long luma_size;
    unsigned long blocks;
    unsigned long ofs;
    unsigned long ofs2;
    unsigned long ofs3;
    unsigned long ptr;
    unsigned long total;
    unsigned long size;
    unsigned long table_size;
    unsigned long scale;
    unsigned long v;
    unsigned long i;
    unsigned long j;
    unsigned long x;
    unsigned long y;

    samplingy = 1;
    samplingx = 1;
    if (sampling == 2) {
        samplingy = 2;
        samplingx = 2;
    } else if (sampling == 3) {
        samplingx = 2;
    }

    gWriteLimit = limit;
    mcu_cols = width / (samplingx * 8);
    mcu_rows = height / (samplingy * 8);
    cx = width >> 3;
    cy = height >> 3;
    chroma_cols = cx / samplingx;
    chroma_rows = cy / samplingy;

    dcY = (huffman_structure *)(wrk + 0x280);
    dcC = (huffman_structure *)(wrk + 0xab0);
    acY = (huffman_structure *)(wrk + 0x12e0);
    acC = (huffman_structure *)(wrk + 0x1b10);
    dqttbl = wrk + 0x200;
    pBuildTableWork = (Yos_JpegEncoderHuffmanEncoderBuildTableWork *)(wrk + 0x2340);
    QuantizeTable = (long *)wrk;

    luma_size = cx * cy * 128 + 0x2b40;
    blocks = chroma_cols * chroma_rows;

    Component[0].mCofficients = (short *)(wrk + 0x2b40);
    Component[0].mCols = cx;
    Component[0].mRows = cy;
    Component[0].mLastDcValue = 0;
    Component[1].mCofficients = (short *)(wrk + luma_size);
    Component[1].mCols = chroma_cols;
    Component[1].mRows = chroma_rows;
    Component[1].mLastDcValue = 0;
    Component[2].mCofficients = (short *)(wrk + luma_size + blocks * 128);
    Component[2].mCols = chroma_cols;
    Component[2].mRows = chroma_rows;
    Component[2].mLastDcValue = 0;

    ofs = luma_size + blocks * 256;
    ofs2 = ofs + width * height;
    ofs3 = ofs + 2 * width * height;

    if (quality <= 50)
        scale = 200 - quality * 2;
    else
        scale = 5000 / quality;

    for (j = 0; j < 64; j++) {
        v = (luminance_quantization_table[j] * scale + 50) / 100;
        if (v == 0)
            v = 1;
        if (v > 255)
            v = 255;
        dqttbl[j] = v;
        QuantizeTable[j] = scaleTable[j] / (long)v;

        v = (chrominance_quantization_table[j] * scale + 50) / 100;
        if (v == 0)
            v = 1;
        if (v > 255)
            v = 255;
        dqttbl[0x40 + j] = v;
        QuantizeTable[64 + j] = scaleTable[j] / (long)v;
    }

    if (func != 0)
        func(src, width, height, wrk + ofs);

    Yos_JpegEncodeSample1to1Component(wrk + ofs, (long *)wrk, &Component[0], width);

    if (sampling == 1) {
        Yos_JpegEncodeSample1to1Component(wrk + ofs2, (long *)(wrk + 0x100), &Component[1], width);
    } else if (sampling == 2) {
        Yos_JpegEncodeSample2to2Component(wrk + ofs2, (long *)(wrk + 0x100), &Component[1], width);
    } else {
        Yos_JpegEncodeSample2to1Component(wrk + ofs2, (long *)(wrk + 0x100), &Component[1], width);
    }

    if (sampling == 1) {
        Yos_JpegEncodeSample1to1Component(wrk + ofs3, (long *)(wrk + 0x100), &Component[2], width);
    } else if (sampling == 2) {
        Yos_JpegEncodeSample2to2Component(wrk + ofs3, (long *)(wrk + 0x100), &Component[2], width);
    } else {
        Yos_JpegEncodeSample2to1Component(wrk + ofs3, (long *)(wrk + 0x100), &Component[2], width);
    }

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
        size = SSP_ExifEncode(dst, width, height, thumb_src, thumb_size);
        ptr = size;
        if (size + 0x17 >= gWriteLimit)
            return 0;
        MI_CpuCopy8(jfif, dst + size, 0x17);
        dst[size + 5] = height >> 8;
        dst[size + 6] = (u8)height;
        dst[size + 7] = width >> 8;
        dst[size + 8] = (u8)width;
        dst[size + 0xb] = samplingy | (samplingx << 4);
        ptr = size + 0x17;
    }

    if (ptr + 0x82 >= gWriteLimit)
        return 0;
    dst[ptr++] = 0;
    for (i = 0; i < 64; i++)
        dst[ptr++] = dqttbl[JpegZigZagInputOrderCodes[i]];
    dst[ptr++] = 1;
    for (i = 0; i < 64; i++)
        dst[ptr++] = dqttbl[0x40 + JpegZigZagInputOrderCodes[i]];

    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, dcY, 0);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, acY, 2);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, dcC, 1);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, acC, 3);

    total = Yos_JpegEncoderHuffmanEncoderOutputSize(acC)
          + Yos_JpegEncoderHuffmanEncoderOutputSize(acY)
          + Yos_JpegEncoderHuffmanEncoderOutputSize(dcY) + 2
          + Yos_JpegEncoderHuffmanEncoderOutputSize(dcC);

    if (ptr + 4 >= gWriteLimit)
        return 0;
    dst[ptr] = 0xff;
    dst[ptr + 1] = 0xc4;
    dst[ptr + 2] = (u8)(total >> 8);
    dst[ptr + 3] = (u8)total;
    dst[ptr + 4] = 0;
    ptr += 5;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(dcY, dst, &ptr))
        return 0;
    dst[ptr++] = 1;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(dcC, dst, &ptr))
        return 0;
    dst[ptr++] = 0x10;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(acY, dst, &ptr))
        return 0;
    dst[ptr++] = 0x11;
    if (!Yos_JpegEncoderHuffmanEncoderPrintTable(acC, dst, &ptr))
        return 0;

    for (j = 0; j < 3; j++)
        Component[j].mLastDcValue = 0;
    Yos_BitInit();

    if (ptr + 0xe > gWriteLimit)
        return 0;
    for (i = 0; i < 14; i++)
        dst[ptr++] = jsos[i];

    for (y = 0; y < mcu_rows; y++) {
        for (x = 0; x < mcu_cols; x++) {
            if (sampling == 1) {
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x, y))
                    return 0;
            } else if (sampling == 2) {
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x * 2, y * 2))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x * 2 + 1, y * 2))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x * 2, y * 2 + 1))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x * 2 + 1, y * 2 + 1))
                    return 0;
            } else {
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x * 2, y))
                    return 0;
                if (!Yos_JpegEncoderComponentSequential(dcY, acY, &Component[0], dst, &ptr, x * 2 + 1, y))
                    return 0;
            }

            if (!Yos_JpegEncoderComponentSequential(dcC, acC, &Component[1], dst, &ptr, x, y))
                return 0;
            if (!Yos_JpegEncoderComponentSequential(dcC, acC, &Component[2], dst, &ptr, x, y))
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
    } else {
        if (SSPiEncodeSignCheckMode == 1 && OS_IsRunOnTwl() == 1) {
            if (!SSPi_JpegEncoderDoSign(dst, ptr))
                return 0;
        }
    }
    return ptr;
}
