/*
 * function: Yos_JpegEncoderComponentSequential
 * address:  0x021C131C
 * packet:   pkt_ov172_021C131C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen. Closest draft is byte-identical in shape/logic (476 vs
 *   484 bytes) but mwcc spills the `du` pointer (str [sp] / ldr [sp]) and
 *   assigns the row*mCols+col offset to r7 instead of r8, so du[0] lands in
 *   r6 not r7.  Tried: separate `offset` local (r7, still spills), `du[0]`
 *   vs `mCofficients[offset*64]` (loses the ldm r2,{r4,r5}), and computing
 *   du via `du += offset*64` (still r7).  Original keeps du=r6, value=r7.
 *
 * sdk:      Yos_JpegEncoderComponentSequential (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   Yos_BitWrite                    0x021C0C3C  arm  ov172
 *   JpegZigZagInputOrderCodes       0x021C85BC  data  ov172
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct huffman_structure {
    u32 mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[260];
} huffman_structure;

typedef struct component_structure {
    short *mCofficients;
    u32 mCols;
    u32 mRows;
    long mLastDcValue;
} component_structure;

extern int Yos_BitWrite(u8 *dst, u32 *ptr, u32 num, u32 size);
extern u8 JpegZigZagInputOrderCodes[64];

static int Yos_JpegEncoderComponentSequential(huffman_structure *dc, huffman_structure *ac,
                                              component_structure *component, u8 *dst,
                                              u32 *ptr, u32 col, u32 row)
{
    long diff;
    long value;
    short *du;
    u32 bits;
    u32 zerorun;
    u32 ssss;
    u32 index;
    u32 offset;

    offset = row * component->mCols + col;
    du = component->mCofficients + offset * 64;
    value = du[0];
    diff = value - component->mLastDcValue;
    component->mLastDcValue = value;

    if (diff < 0) {
        diff = -diff;
        value = ~diff;
    } else {
        value = diff;
    }
    for (index = 0; diff != 0; index++)
        diff >>= 1;

    if (!Yos_BitWrite(dst, ptr, dc->mEhufco[index], dc->mEhufsi[index]))
        return 0;
    if (index != 0) {
        if (!Yos_BitWrite(dst, ptr, value, index))
            return 0;
    }

    zerorun = 0;
    index = 1;
    for (; index < 64; index++) {
        value = du[JpegZigZagInputOrderCodes[index]];
        if (value == 0) {
            zerorun++;
        } else {
            while (zerorun >= 16) {
                if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0xF0], ac->mEhufsi[0xF0]))
                    return 0;
                zerorun -= 16;
            }
            if (value < 0) {
                value = -value;
                bits = ~value;
            } else {
                bits = value;
            }
            for (ssss = 0; value != 0; ssss++)
                value >>= 1;
            if (!Yos_BitWrite(dst, ptr, ac->mEhufco[ssss | (zerorun << 4)],
                              ac->mEhufsi[ssss | (zerorun << 4)]))
                return 0;
            if (ssss != 0) {
                if (!Yos_BitWrite(dst, ptr, bits, ssss))
                    return 0;
            }
            zerorun = 0;
        }
    }
    if (zerorun != 0) {
        if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0], ac->mEhufsi[0]))
            return 0;
    }
    return 1;
}
