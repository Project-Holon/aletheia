/*
 * function: NNSi_G3dTexMtxScaleRot
 * address:  0x02071CDC
 * packet:   pkt_02071B2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The smull/FX constructor for 0x02071B2C's family. Every quartet is
 * `((s64)field * field) >> 12`: the sign comes from the FIELD TYPE (f18/f1c
 * are the `ldr` s32 pair, f20/f22 the `ldrsh` s16 pair), never from a cast -
 * spell either as u32 and `umull` comes out. The `>> 12` folds to
 * `lsr #0xc` + `orr ..., lsl #20` because only the low word is live.
 *
 * The 0x30/0x34 pair is ONE chained term per statement: the smull/smlal
 * split names the operand order, so the additive term is written SECOND
 * (`bd * ne11 + r * nf11`): mwcc gives the smull to the second operand and
 * the smlal to the first, and swapping them swaps the two instructions.
 * The two negations are the two-statement form (`n = 0 - x`) - folding them
 * into the multiply re-associates and loses both `rsb`s.
 *
 * symbols:
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
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
    s16 f20;
    s16 f22;
    u8  pad_24[8];
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

extern void func_0207C930(u32 numer, u32 denom);
extern u32 func_0207C86C(void);

void NNSi_G3dTexMtxScaleRot(struct DST *d, struct SRC *s)
{
    s32 e12, f12;
    s32 p, q, r, bd, t;
    s32 ne, nf;
    s64 m;

    e12 = (s32)((u32)s->f2c << 12);
    f12 = (s32)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    p  = (s32)(((s64)s->f18 * s->f22) >> 12);
    q  = (s32)(((s64)s->f18 * s->f20) >> 12);
    r  = (s32)(((s64)s->f1c * s->f22) >> 12);
    bd = (s32)(((s64)s->f1c * s->f20) >> 12);

    d->f00 = p;
    d->f14 = r;
    t = func_0207C86C();
    d->f04 = (bd * t) >> 12;

    func_0207C930(e12, f12);

    ne = 0 - (s32)s->f2c;
    nf = 0 - (s32)s->f2e;

    m = (s64)p * (ne << 11) - (s64)q * (nf << 11);
    d->f30 = (s32)(m >> 8) + ((s32)s->f2c << 15);

    m = (s64)bd * (ne << 11) + (s64)r * (nf << 11);
    d->f34 = (s32)(m >> 8) + ((s32)s->f2e << 15);

    t = func_0207C86C();
    d->f10 = ((0 - q) * t) >> 12;
}
