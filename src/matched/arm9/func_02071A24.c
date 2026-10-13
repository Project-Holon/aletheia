/*
 * function: NNSi_G3dTexMtxScaleRotTrans
 * address:  0x02071A24
 * packet:   pkt_02071360
 * region:   arm9
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 *
 * The full-rotate constructor with the smull quartet: the body of
 * src/matched/NNSi_G3dTexMtxScaleRot.c with its two plain negated multipliers
 * replaced by the translation-weighted pair func_02071C14 uses,
 *   a = (-f2c << 11) - f24 * f2c
 *   b = f28 * f2e + (-f2e << 11)
 * and f30 = (p*a - q*b) >> 8 + f2c << 15, f34 = (bd*a + r*b) >> 8 +
 * f2e << 15.
 *
 * The only residue of the first compile (11 bytes, both front ends) was
 * the cluster rule in docs/families/cluster_02071360.h: in the f34 term
 * the `<< 15` bias is written FIRST, in the f30 term LAST.  With that one
 * change it is 264 bytes, 0 out.
 *
 * Front end: NOT pinned.  EXACT under both dsi/1.1p1 and ../2.0/sp2 with
 * the same C; filed under the project default like NNSi_G3dTexMtxScaleRot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dTexMtxScaleRotTrans.c \
 *       --func NNSi_G3dTexMtxScaleRotTrans --addr 0x02071A24 --arm
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

extern void func_0207C930(u32 numer, u32 denom);
extern u32 func_0207C86C(void);

void NNSi_G3dTexMtxScaleRotTrans(struct DST *d, struct SRC *s)
{
    s32 e12, f12;
    s32 p, q, r, bd, t;
    s32 a, b;
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

    a = ((0 - (s32)s->f2c) << 11) - s->f24 * s->f2c;
    b = s->f28 * s->f2e + ((0 - (s32)s->f2e) << 11);

    m = (s64)p * a - (s64)q * b;
    d->f30 = (s32)(m >> 8) + ((s32)s->f2c << 15);

    m = (s64)bd * a + (s64)r * b;
    d->f34 = ((s32)s->f2e << 15) + (s32)(m >> 8);

    t = func_0207C86C();
    d->f10 = ((0 - q) * t) >> 12;
}
