/*
 * function: NNSi_G3dTexMtxRotTrans
 * address:  0x02071B2C
 * packet:   pkt_02071360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The rotate-and-scale constructor of the 0x02071CDC family, 232 bytes.
 * Brackets the body with the two func_0207C930 mode calls (arguments swapped
 * between them), writes the s16 f22 into f00 and f14, derives f04/f10 from
 * f20 and func_0207C86C's return, and builds the f30/f34 pair out of the
 * f24/f28 vectors biased by the f2c/f2e halfwords.
 *
 * FOUR SPELLING TELLS, each measured (bytes out on the whole function):
 *   33 -> 18  bind the two halfwords to named locals `e`/`f` and read f2c
 *             FIRST: unbound, the compiler emits the f2e ldrh ahead of the
 *             f2c one at +0x58 and reshuffles everything downstream.
 *   18 -> 11  write f34's `<< 15` term FIRST and the shifted product second
 *             (`(f2e << 15) + (m >> 8)`), the operand-order tell already
 *             recorded for this family in src/matched/unit_02071DD4.c; f30
 *             keeps the opposite order, `(m >> 8) + (f2c << 15)`.
 *   11 ->  9  bind f22/f20 to `a`/`bb` before the f34 chain.
 *    9 ->  0  the f34 chain is `bb * (s64)p + a * (s64)q`: BOTH the term
 *             order and each factor's operand order matter. The permuter
 *             (hill, 794 compiles) found it as three commute mutations from
 *             `(s64)q * a + (s64)p * bb`; every hand spelling in between sat
 *             at 9 bytes with the two `ldrsh` at +0xA8/+0xAC swapped.
 *
 * Not pinned: 1.1p1 reproduces it exactly, unlike its neighbours 0x02071360
 * and 0x02071C14.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dTexMtxRotTrans.c \
 *       --func NNSi_G3dTexMtxRotTrans --addr 0x02071B2C --arm --cc 1.1p1
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
    u8  pad_00[0x20];
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

void NNSi_G3dTexMtxRotTrans(struct DST *d, struct SRC *s)
{
    s32 e12, f12, t;
    s32 p, q, e, f, a, bb;
    s64 m;

    e12 = (s32)((u32)s->f2c << 12);
    f12 = (s32)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    d->f00 = s->f22;
    d->f14 = s->f22;
    t = func_0207C86C();
    d->f04 = (s->f20 * t) >> 12;

    func_0207C930(e12, f12);

    e = (s32)s->f2c;
    f = (s32)s->f2e;
    q = s->f28 * f;
    q = q + ((0 - f) << 11);
    p = s->f24 * e;
    p = ((0 - e) << 11) - p;

    m = (s64)s->f22 * p - (s64)s->f20 * q;
    d->f30 = (s32)(m >> 8) + ((s32)s->f2c << 15);

    a  = s->f22;
    bb = s->f20;
    m = bb * (s64)p + a * (s64)q;
    d->f34 = ((s32)s->f2e << 15) + (s32)(m >> 8);

    t = func_0207C86C();
    d->f10 = ((0 - (s32)s->f20) * t) >> 12;
}
