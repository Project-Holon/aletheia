/*
 * function: func_02072068
 * address:  0x02072068
 * packet:   pkt_02072068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 *
 * THE GENERAL MEMBER of the (DST, SRC) matrix-constructor family
 * (docs/families/cluster_02071EAC.h, docs/families/cluster_02070B64.h): the
 * full s32 2x2 block from f18/f1c x f20/f22 AND the f24/f28 cross terms, both
 * carried at 64-bit width all the way through.  docs/notes/pkt_02071104.c.txt
 * listed it as NOT ATTEMPTED and docs/notes/pkt_02071DD4.c.txt names it as the
 * shape 0x02071A24 shares.
 *
 * FOUR LEVERS, in the order they were needed.  The first three are the family's
 * known ones re-applied; the fourth is what the permuter found and is new.
 *
 * L-A  h1 AND h2 ARE `s64`, NOT `s32`.  The two cross terms are NOT narrowed
 *      to 32 bits before they multiply f1c/f18: the image shows the full
 *      64x64 shape -- `asr fp, lr, #0x1f` sign-extending f1c to a pair, then
 *      `umull sl, r2, sb, lr` / `mla r2, sb, fp, r2` / `mla r2, r8, lr, r2`
 *      at 0x02072140..0x0207214C -- which only appears when BOTH operands are
 *      64-bit.  Declared `s32`, each product is a single `smull` and the
 *      function is 300 bytes against the image's 340.  With `s64` it is 332.
 *
 * L-B  L1 OF THE FAMILY, on h2: the additive term is written SECOND, so the
 *      `smull` goes to `f28 * f20` and the `smlal` to `f24 * f22`
 *      (0x020720A4 / 0x0207211C).  h1's subtraction has no such freedom.
 *
 * L-C  THE f34 VALUE IS COMPUTED BEFORE THE f30 VALUE, THOUGH f30 IS STORED
 *      FIRST.  This is the remaining eight bytes of the 332.  The image
 *      interleaves them: `add r2, r4, r8` (the f34 sum) at 0x0207215C, then
 *      the whole f30 umull/mla block, then `sub r2, r2, #0x1000` at
 *      0x02072180 and the f30 store at 0x0207218C, and only then the f34
 *      store at 0x020721A0.  Writing the two arms in store order gives 332
 *      bytes; binding `m` (the f34 value) first, with the `- 0x1000`
 *      deferred past the f30 multiply, gives the image's 340.
 *
 * L-D  THE LIVE RANGE OF x5 IS SPLIT BY A TEMPORARY.  `t = (f18*f20) >> 12;`
 *      computed BEFORE x4, then `x5 = t;` after it.  Written in place, x4 and
 *      x5 exchange r4 and r5 across twelve instructions (16 concrete bytes,
 *      every one of them an `lsr`/`orr` narrowing pair, a `umull`/`mla`
 *      triple, a `sub` or an `rsb`, i.e. the multiply-class allocation swap
 *      L8 of the cluster header records as this family's residue floor).
 *      THE SPLIT IS WHAT REACHES IT: a fresh copy gives the value its own
 *      definition point, so it is numbered after x4 instead of before, and
 *      the two colours come out the image's way round.  tools/permuter.py
 *      found this in one hill pass (`temp(tmp=(s32) ((((s64) p) * b) >)`,
 *      352 compiles, 16 -> 0); the hand sweep before it had exhausted
 *      statement order, operand order and the f2c binding at 16.
 *
 * Not a pin: ../2.0/sp2 is not better on this source, and the default 1.1p1
 * produces the bytes.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
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

void func_02072068(struct DST *d, struct SRC *s)
{
    s32 f12, e12;
    s32 a, b, p, r;
    s32 x4, x5;
    s64 h1, h2;
    s32 n, m, c;
    s32 t;

    f12 = (s32)s->f2c << 12;
    e12 = (s32)s->f2e << 12;
    func_0207C930(e12, f12);

    a = (s32)s->f22;
    p = s->f18;
    b = (s32)s->f20;
    r = s->f1c;

    d->f00 = (s32)(((s64)p * a) >> 12);
    t  = (s32)(((s64)p * b) >> 12);
    x4 = (s32)(((s64)r * a) >> 12);
    x5 = t;
    d->f14 = x4;
    d->f04 = ((s32)(((s64)r * b) >> 12) * func_0207C86C()) >> 12;

    func_0207C930(f12, e12);

    c  = (s32)s->f2c;
    h2 = (((s64)s->f24 * (s32)s->f22) + ((s64)s->f28 * (s32)s->f20)) >> 12;
    h1 = (((s64)s->f24 * (s32)s->f20) - ((s64)s->f28 * (s32)s->f22)) >> 12;

    m = x4 + (s32)((h1 * s->f1c) >> 12);
    n = x5 - (s32)((h2 * s->f18) >> 12);
    m = m - 0x1000;
    d->f30 = (c * n) << 4;
    d->f34 = ((0 - (s32)s->f2e) * m) << 4;

    d->f10 = ((0 - x5) * func_0207C86C()) >> 12;
}
