/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006DAC
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02006DAC, sub_02006DD8
 *
 * symbols:
 *   sub_02006DAC_Ptr           0x02146164  data
 *   sub_02006E2C               0x02006E2C  thumb
 *   MIC_AdjustLimitedSampling  0x0208B500  arm
 *
 * The microphone sampling request and its one caller.  The record both
 * functions pass around is seven words, and the SDK call at 0x0208B500 is
 * MIC_AdjustLimitedSampling in layout/symbols_sdk.txt, so the record is a
 * MICAutoParam: type, buffer, size, rate, loop flag, callback and callback
 * argument, in that order, which is exactly the seven stores sub_02006DD8
 * makes and exactly the 0x1C bytes sub_02006DAC copies.  The fields are
 * still spelled unkXX here because only the SDK call attests the shape, not
 * the meaning of the two constants.
 *
 * sub_02006DAC reads the global pointer at 0x02021664 twice, once for the
 * flag word at +0x1C and once for the copy, because the store through the
 * first load can alias the pointer itself and the compiler has to reload it.
 * That reload is not a second variable in the source.  The copy is the
 * unrolled aggregate assignment of
 * docs/idioms/aggregate-assignment-is-ldm-stm.md: 0x1C bytes is three
 * ldm/stm pairs and a trailing ldr/str, and it says the seven words are one
 * nested struct rather than seven fields.
 *
 * The two constants sub_02006DD8 stores come out of literal pools, and the
 * round down of the first is emitted as a live test and mask rather than
 * folded: `movs r0, #0x1f; tst r0, r1; beq; movs r0, #0x1f; bics r1, r0`,
 * with the mask materialised twice because Thumb has no immediate bic.  The
 * compiler does not constant fold it even though the value is a pool word,
 * so the guard is in the source and not an artefact.
 *
 * What is left out of this range, and why, is sub_02006E18 at
 * 0x02006E18..0x02006E2A, eighteen bytes that reproduce every concrete byte
 * and cap at MATCH.  It is `sub_02007BD0(a, sub_02006E2C());` and the
 * evidence for 0x02007BD0 is the `bl` at 0x02006E24 inside that very
 * the function list: the census is one witness image wide, one of them inside the
 * range, so no cut can free it.  The `literal` class has nothing either,
 * because no pool word anywhere in the image holds 0x02007BD0.  It closes
 * the day a second caller of 0x02007BD0 appears, exactly like 0x02005DE4 and
 * 0x02005A98 in the near-miss register of docs/MATCHING.md.  Note that
 * sub_02006E2C itself is fine either way: it has two callers, 0x02006DE4 in
 * this range and 0x02006E1C in sub_02006E18, so whichever of the two files a
 * range holds, the other is its witness.
 */

typedef unsigned int u32;

struct Sub02006DACParam {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02006DACObj {
    struct Sub02006DACParam unk00;
    u32 unk1C;
};

extern struct Sub02006DACObj *sub_02006DAC_Ptr;

extern u32 sub_02006E2C(void);
extern u32 MIC_AdjustLimitedSampling(const struct Sub02006DACParam *param);

u32 sub_02006DAC(const struct Sub02006DACParam *param)
{
    u32 r = MIC_AdjustLimitedSampling(param);

    sub_02006DAC_Ptr->unk1C = 1;
    sub_02006DAC_Ptr->unk00 = *param;
    return r;
}

u32 sub_02006DD8(void *a, u32 b)
{
    struct Sub02006DACParam param;

    param.unk00 = 2;
    param.unk04 = sub_02006E2C();
    param.unk08 = 0x1FF4;
    if (param.unk08 & 0x1F) {
        param.unk08 &= ~0x1Fu;
    }
    param.unk0C = 0x1001;
    param.unk10 = 0;
    param.unk14 = (u32)a;
    param.unk18 = b;
    return sub_02006DAC(&param);
}
