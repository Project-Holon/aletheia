/*
 * function: func_020721BC
 * address:  0x020721BC
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The shear member of the 0x02071CDC constructor family: the 2x2 block is
 * the s16 f20/f22 pair, but the f30/f34 translation pair carries the extra
 * f24/f28 cross terms, so each is a 64-bit smull/smlal pair reduced by the
 * family's `>> 12` (which folds to `lsr #0xc` + `orr ..., lsl #20`).
 *
 * The one lever: in `h1` the additive term is written SECOND
 * (`f24*f22 + f28*f20`). mwcc gives the smull to the SECOND operand and the
 * smlal to the first, so the other spelling emits `smull ip,r0` /
 * `smlal r4,lr` and reverses all four loads at 0x02072214..0x02072220:
 * 12 concrete bytes, no other difference.
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

extern void func_0207C930(s32 a, s32 b);
extern s32  func_0207C86C(void);

void func_020721BC(struct DST *d, struct SRC *s)
{
    s32 e12, f12, t, h1, h2;

    e12 = (s32)((u32)s->f2c << 12);
    f12 = (s32)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    d->f00 = s->f22;
    d->f14 = s->f22;

    t = func_0207C86C();
    d->f04 = (s->f20 * t) >> 12;

    func_0207C930(e12, f12);

    h1 = (s32)((((s64)s->f24 * s->f22) + ((s64)s->f28 * s->f20)) >> 12);
    h2 = (s32)((((s64)s->f24 * s->f20) - ((s64)s->f28 * s->f22)) >> 12);

    d->f30 = ((s32)s->f2c * (s->f20 - h1)) << 4;
    d->f34 = ((0 - (s32)s->f2e) * (s->f22 + h2 - 0x1000)) << 4;

    t = func_0207C86C();
    d->f10 = ((0 - (s32)s->f20) * t) >> 12;
}
