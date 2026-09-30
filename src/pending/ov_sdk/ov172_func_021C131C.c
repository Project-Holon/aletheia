/*
 * function: Yos_JpegEncoderComponentSequential
 * address:  0x021C131C
 * packet:   pkt_ov172_021C131C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (size-exact 484/484, 33 concrete bytes, one register exchange)
 *
 * sdk:      Yos_JpegEncoderComponentSequential (libssp.TWL.HYB.a jpegenc.o)
 *
 * Lane U57 (2026-09-30): rewritten against the vendor object's own DWARF and
 * instruction listing.  476/282 -> 484/33 with three fixes:
 *   - the object has NO `offset` local.  `row*mCols + col` is spelled inline,
 *     `du = component->mCofficients + (row * component->mCols + col) * 64;`;
 *     with a named `offset` mwcc keeps it in r7 and never materialises du.
 *   - `value` is read TWICE from `du[JpegZigZagInputOrderCodes[index]]`, once
 *     in the zero test and again inside the else arm (the image reloads zz[]
 *     and the halfword at +0x108/+0x114 - three instructions, the 8 bytes the
 *     old draft was short).
 *   - the arms are SWAPPED in the vendor's source: `if (du[...] != 0) { big }
 *     else { zerorun++; }`.  With the small arm first mwcc if-converts it to
 *     `addeq r5,r5,#1` plus a branch; with the big arm first the small arm is
 *     left as the loop-tail block at +0x14b8, which is the image's shape.
 * Declarations and types are the object's DWARF, which lists locals in reverse
 * source order: rrrrssss, value(int), diff, du(short *), bits, zerorun, ssss,
 * index.  `rrrrssss` is a real vendor local (`orr r1, r7, r5, lsl #4`, the
 * ssss|zerorun<<4 code used for both mEhufco and mEhufsi).
 *
 * Lane 04 (2026-09-30): the declaration block was in DWARF order (rrrrssss
 *   first); DWARF lists locals in reverse source order, so writing them in
 *   SOURCE order (index, ssss, zerorun, bits, du, diff, value, rrrrssss) is
 *   the faithful spelling and drops the diff from 58 to 46.  With it phase 1
 *   gets the image's value=r7 and du=r6.
 *
 * Residue (parked, register allocation only, 46 concrete bytes): phase 2 still
 *   swaps index and the `ac + 0x700` table temporary - image index=r4 /
 *   temp=r7, ours index=r7 / temp=r4 - and phase 1 schedules a few
 *   mutually-independent instructions in the other order (`add r6` vs `subs`,
 *   `movpl/rsbmi/mvnmi`).  No declaration order (15 measured), loop spelling,
 *   or fresh phase-2 variable moves it; it is the same
 *   two-simultaneously-live-values tie as 021B87F0 / 021C84BC.
 *
 * symbols:
 *   Yos_BitWrite                    0x021C0C3C  arm  ov172
 *   JpegZigZagInputOrderCodes       0x021C85BC  data
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
    unsigned long index;
    unsigned long ssss;
    unsigned long zerorun;
    long bits;
    short *du;
    long diff;
    int value;
    unsigned long rrrrssss;

    du = component->mCofficients + (row * component->mCols + col) * 64;
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
        if (du[JpegZigZagInputOrderCodes[index]] != 0) {
            while (zerorun >= 16) {
                if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0xF0], ac->mEhufsi[0xF0]))
                    return 0;
                zerorun -= 16;
            }
            value = du[JpegZigZagInputOrderCodes[index]];
            if (value < 0) {
                value = -value;
                bits = ~value;
            } else {
                bits = value;
            }
            for (ssss = 0; value != 0; ssss++)
                value >>= 1;
            rrrrssss = ssss | (zerorun << 4);
            if (!Yos_BitWrite(dst, ptr, ac->mEhufco[rrrrssss], ac->mEhufsi[rrrrssss]))
                return 0;
            if (ssss != 0) {
                if (!Yos_BitWrite(dst, ptr, bits, ssss))
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
