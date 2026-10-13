/*
 * function: NNSi_G3dTexMtxScaleTrans_Max
 * address:  0x0207229C
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The s32 (f18/f1c) member of the 0x02071CDC constructor family, without
 * the FX calls: the 2x2 block is copied straight through and only the
 * f30/f34 translation pair is scaled.
 *
 * TWO levers, both about where the high half of the smull is bound:
 *  - `hi` must be a NAMED LOCAL computed BEFORE the `d->f30` store. Folded
 *    into the f34 expression, the compiler CSEs the two `s->f1c` reads and
 *    the function comes out 128 bytes against the image's 132 - the image
 *    reads f1c three times (the f14 store, the smull operand, the add).
 *  - the addend order is `s->f1c + hi`, not `hi + s->f1c`: the commutative
 *    tell, 2 bytes out the other way round.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

struct SRC {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    u8  pad_20[4];
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

void NNSi_G3dTexMtxScaleTrans_Max(struct DST *d, struct SRC *s)
{
    s32 a, b, nb, hi;

    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;

    a = 0 - (s32)(((s64)s->f24 * s->f18) >> 12);
    nb = 0 - s->f28;
    hi = (s32)(((s64)nb * s->f1c) >> 12);
    d->f30 = ((s32)s->f2c * a) << 4;
    b = s->f1c + hi - 0x1000;
    d->f34 = ((0 - (s32)s->f2e) * b) << 4;

    d->f10 = 0;
}
