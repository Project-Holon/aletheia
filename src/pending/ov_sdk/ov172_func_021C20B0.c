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
 * blocker: stack-slot / spill-order residue (693 of ~2430 concrete bytes
 *   differ, down from 2209; compiled 2592 B == listing extent, 51/51
 *   relocations resolved, ~27 aligned instrs off). The 0x74 frame, clean
 *   {r4..fp,lr} push, callee-saved assignment of width/quality/cx/cy/dqttbl/
 *   acY-base, sampling switch, ptr memory traffic, thumb/sign epilogue and
 *   Huffman total expression all match. Everything after +0x418 matches
 *   except the mcu_rows slot number.
 *   Spill-slot findings (this lane): the slot order is NOT driven by use counts
 *   (extra real uses of ofs/ofs2/ofs3/sy/sx/cols/rows, statement reordering of
 *   the whole setup region, self-assignments, pointer temps, block scoping of
 *   chroma_cols all leave it unchanged). It IS driven by the order of the
 *   local declarations: among the ordinary spilled ints a LATER declaration
 *   gets a LOWER slot (declare ofs3, ofs2, ofs, [chroma_cols], mcu_cols,
 *   mcu_rows, samplingx, samplingy in that order: sy 0x1c, sx 0x20, rows 0x24,
 *   cols 0x28, ofs 0x2c, ofs2 0x30, ofs3 0x34), with samplingy/samplingx a
 *   pair that comes out first-declared-lowest; acC is always the top slot
 *   (declare the huffman pointers first). The remaining slot error is
 *   chroma_cols: the original has it at 0x2c between mcu_cols (0x28) and ofs
 *   (0x30), ours always parks it at 0x38 above ofs3 whatever its declaration
 *   position, scope, type (int/long change code) or expression (width>>3
 *   instead of cx); giving it extra uses moves it to the LOWEST slot instead.
 *   Its position is the last unsolved slot fact; once it lands at 0x2c, ofs*
 *   move to 0x30/0x34/0x38 and most remaining byte diffs (the ofs store/
 *   Component[1].mCofficients scheduling at +0xFC..+0x160, the quant-loop
 *   j/&dqttbl[j] swap r7/r6, ptr flush after the thumb/JFIF join) may fall
 *   away or show their true shape. tools/permuter.py cannot run this function
 *   (it rejects SSP_ExifEncode as thumb from the ov111 label despite
 *   --region ov172).
 *   Lane 2 (00:16): exhaustive probe shows ALL 8 permutation orders of
 *   {ofs3,ofs2,ofs,chroma_cols,mcu_cols,mcu_rows,samplingx,samplingy} give
 *   byte-identical 693, so chroma_cols is immovable by declaration order.
 *   Narrowing it to u16/u8 or widening to long/int is strictly worse
 *   (2140/1582/2123/2123). Original slots read off the ov172 listing:
 *   sy 0x1c, sx 0x20, mcu_rows 0x24, mcu_cols 0x28, chroma_cols 0x2c,
 *   ofs 0x30, ofs2 0x34, ofs3 0x38; ours parks chroma_cols at 0x38 and
 *   shifts ofs/ofs2/ofs3 down one. Reverse-declaration predicts the
 *   original exactly, yet mwcc overrides chroma_cols to the newest slot,
 *   so source declaration position is not the driver for this variable.
 *   Reconstruction facts established (keep): gBitLen is a struct {len, code,
 *   limit} pinned at 0x021CADE4 (limit = +8); quality is reused as the scale
 *   (no scale local); ofs/ofs2/ofs3 are integer offsets, wrk+ofs is formed at
 *   each call; `ptr = width * height` is used as the plane-size temp before
 *   ofs2/ofs3; chroma_cols/chroma_rows/luma_size/blocks are real locals and
 *   Component stores are ordered group 0,2,1; declare cx before cy; sampling
 *   is a switch; huffman_structure is 0x830 bytes (mEhufsi[264]).
 *   Lane 3 (DWARF, new): `python tools/sdkobj.py 0x021C20B0 --brief` prints
 *   the defining object's DWARF local list (printed order = reverse
 *   declaration): pBuildTableWork, Component, dqttbl, crbuf, cbbuf, ybuf,
 *   QuantizeTable, samplingy, samplingx, mcu_rows, mcu_cols, ptr, cy, cx, y,
 *   x, j. The image's named locals are exactly those frame homes: samplingy
 *   0x1c, samplingx 0x20, mcu_rows 0x24, mcu_cols 0x28, ptr 0x40, cx r7,
 *   cy r6. chroma_cols, chroma_rows, luma_size, blocks, ofs, ofs2, ofs3 are
 *   NOT DWARF locals -- they are unnamed compiler temporaries, and the slots
 *   the image has for them (0x2c..0x3c) cannot be reproduced by declaring
 *   them (any declaration/order gives chroma 0x38). The object names
 *   crbuf/cbbuf/ybuf where this file uses dcY/acY/dcC/acC. Next step: rebuild
 *   the setup from the DWARF-named set only (ybuf/crbuf/cbbuf pointers,
 *   ptr/cx/cy, j/x/y) and let mwcc place the cursors/offsets as temps.
 *   Inlining chroma_cols as cx/samplingx inline made it strictly worse
 *   (2608 B, 2131 diff), so the temp shape comes from expression structure.
 *   2026-10-01: listing shows every Component/ybuf address is wrk + an integer
 *   sum (C1 = wrk + (cx*cy<<7 + 0x2b40), ofs = that + cc*cr<<8), and ybuf etc.
 *   are rematerialised as wrk + spilled-offset, so ofs/ofs2/ofs3/chroma are CSE
 *   temps. DWARF-only locals with inline sums (chained C1/C2 mCols/mRows) give
 *   cx r7/cy r6 and the image's temp shape but chroma lands at 0x34 not 0x2c
 *   and the frame shifts: 1974-2116 B, so this body (693 B) is kept.
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
    u8  mEhufsi[264];
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
extern struct { unsigned long len; unsigned long code; unsigned long limit; } gBitLen;

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
    Yos_JpegEncoderHuffmanEncoderBuildTableWork *pBuildTableWork;
    component_structure Component[3];
    u8 *dqttbl;
    long *QuantizeTable;
    huffman_structure *dcY, *acY, *dcC, *acC;
    unsigned long ofs3;
    unsigned long ofs2;
    unsigned long ofs;
    unsigned long chroma_cols;
    unsigned long mcu_cols;
    unsigned long mcu_rows;
    unsigned long samplingx;
    unsigned long samplingy;
    unsigned long cx;
    unsigned long cy;
    unsigned long ptr;
    unsigned long y;
    unsigned long x;
    unsigned long j;
    unsigned long total, size, v, i;
    unsigned long chroma_rows, luma_size, blocks;

    samplingy = 1;
    samplingx = 1;
    switch (sampling) {
    case 1:
        break;
    case 2:
        samplingy = 2;
        samplingx = 2;
        break;
    case 3:
        samplingx = 2;
        break;
    }

    gBitLen.limit = limit;
    mcu_cols = width / (samplingx * 8);
    mcu_rows = height / (samplingy * 8);
    cx = width >> 3;
    cy = height >> 3;

    dcY = (huffman_structure *)(wrk + 0x280);
    dcC = (huffman_structure *)(wrk + 0xab0);
    acY = (huffman_structure *)(wrk + 0x12e0);
    acC = (huffman_structure *)(wrk + 0x1b10);
    dqttbl = wrk + 0x200;
    pBuildTableWork = (Yos_JpegEncoderHuffmanEncoderBuildTableWork *)(wrk + 0x2340);
    QuantizeTable = (long *)wrk;

    chroma_cols = cx / samplingx;
    chroma_rows = cy / samplingy;
    luma_size = cx * cy * 128 + 0x2b40;
    blocks = chroma_cols * chroma_rows;
    Component[0].mCofficients = (short *)(wrk + 0x2b40);
    Component[0].mCols = cx;
    Component[0].mRows = cy;
    Component[2].mCofficients = (short *)(wrk + luma_size + blocks * 128);
    Component[2].mCols = chroma_cols;
    Component[2].mRows = chroma_rows;
    Component[1].mCofficients = (short *)(wrk + luma_size);
    Component[1].mCols = chroma_cols;
    Component[1].mRows = chroma_rows;
    Component[0].mLastDcValue = Component[1].mLastDcValue = Component[2].mLastDcValue = 0;
    ofs = luma_size + blocks * 256;
    ptr = width * height;
    ofs2 = ofs + ptr;
    ofs3 = ofs + ptr * 2;

    if (quality >= 50)
        quality = 200 - quality * 2;
    else
        quality = 5000 / quality;

    for (j = 0; j < 64; j++) {
        v = (luminance_quantization_table[j] * quality + 50) / 100;
        if (v == 0)
            v = 1;
        if (v > 255)
            v = 255;
        dqttbl[j] = v;
        QuantizeTable[j] = scaleTable[j] / (long)v;

        v = (chrominance_quantization_table[j] * quality + 50) / 100;
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
        if (gBitLen.limit <= 25)
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
        if (ptr + 0x17 >= gBitLen.limit)
            return 0;
        MI_CpuCopy8(jfif, dst + ptr, 0x17);
        dst[ptr + 5] = height >> 8;
        dst[ptr + 6] = (u8)height;
        dst[ptr + 7] = width >> 8;
        dst[ptr + 8] = (u8)width;
        dst[ptr + 0xb] = samplingy | (samplingx << 4);
        ptr += 0x17;
    }

    if (ptr + 0x82 >= gBitLen.limit)
        return 0;
    dst[ptr++] = 0;
    for (i = 0; i < 64; i++) {
        dst[ptr] = dqttbl[JpegZigZagInputOrderCodes[i]];
        ptr++;
    }
    dst[ptr++] = 1;
    for (i = 0; i < 64; i++) {
        dst[ptr] = dqttbl[0x40 + JpegZigZagInputOrderCodes[i]];
        ptr++;
    }

    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, dcY, 0);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, acY, 2);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, dcC, 1);
    Yos_JpegEncoderHuffmanEncoderBuildTable(pBuildTableWork, acC, 3);

    total = Yos_JpegEncoderHuffmanEncoderOutputSize(acC)
          + (Yos_JpegEncoderHuffmanEncoderOutputSize(acY)
          + (Yos_JpegEncoderHuffmanEncoderOutputSize(dcY) + 2
          + Yos_JpegEncoderHuffmanEncoderOutputSize(dcC)));

    if (ptr + 4 >= gBitLen.limit)
        return 0;
    dst[ptr] = 0xff;
    dst[ptr + 1] = 0xc4;
    dst[ptr + 2] = (u8)(total >> 8);
    dst[ptr + 3] = (u8)total;
    ptr += 4;
    dst[ptr++] = 0;
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

    if (ptr + 0xe > gBitLen.limit)
        return 0;
    for (i = 0; i < 14; i++) {
        dst[ptr] = jsos[i];
        ptr++;
    }

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

    if (gBitLen.len != 8) {
        if (!Yos_BitWrite(dst, &ptr, 0, 7))
            return 0;
    }

    if (ptr + 2 >= gBitLen.limit)
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
