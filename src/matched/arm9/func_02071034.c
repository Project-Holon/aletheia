/*
 * function: NNSi_G3dTexMtxRotTrans4x4
 * address:  0x02071034
 * packet:   pkt_02070DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_DivAsync      0x0207C930  arm
 *   FX_GetDivResult  0x0207C86C  arm
 *
 * Builds the six 4.12 fixed-point terms of a rotation-matrix record from a
 * source record: two FX_DivAsync/FX_GetDivResult scale pairs (the async
 * divider is started, the destination words are written, and the quotient is
 * read back) plus the two shear terms at +0x30/+0x34.
 *
 * Two spelling facts earned this one (see
 * docs/idioms/a-two-statement-negation-blocks-the-rsb-fold.md and
 * docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md):
 *   - the negated sum must be TWO statements (`n = f20 + f22; n = 0 - n;`).
 *     Written as one expression, `-(f20 + f22) + 0x1000` folds to a single
 *     `rsb r2, r1, #0x1000` and loses four bytes and the whole register plan.
 *   - the two-sided term at +0x34 is written with the `<< 4` product as the
 *     SECOND operand of the `+`, because the accumulator of a commutative
 *     chain is its second operand; writing it first puts the `<< 3` product in
 *     the accumulator and swaps every register in the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Src71034 {
    u8  pad_00[0x20];
    s16 f20;
    s16 f22;
    u32 f24;
    u32 f28;
    u16 f2c;
    u16 f2e;
};

struct Dst71034 {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

extern void FX_DivAsync(s32 num, s32 den);
extern s32  FX_GetDivResult(void);

void NNSi_G3dTexMtxRotTrans4x4(struct Dst71034 *d, struct Src71034 *s)
{
    s32 c = (u16)s->f2c << 12;
    s32 e = (u16)s->f2e << 12;
    s32 n;
    s32 q;

    FX_DivAsync(e, c);
    d->f00 = s->f22;
    d->f14 = s->f22;
    q = FX_GetDivResult();
    d->f04 = (-s->f20 * q) >> 12;
    FX_DivAsync(c, e);
    n = s->f20 + s->f22;
    n = 0 - n;
    d->f30 = ((u16)s->f2c * (n + 0x1000) << 3)
           - (s->f24 * (u16)s->f2c << 4);
    n = s->f20 - s->f22;
    d->f34 = ((u16)s->f2e * (n + 0x1000) << 3)
           + (s->f28 * (u16)s->f2e << 4);
    q = FX_GetDivResult();
    d->f10 = (s->f20 * q) >> 12;
}
