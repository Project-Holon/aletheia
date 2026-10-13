/*
 * file:     nns_g3d_tex_mtx_5.c
 * unit:     yes
 * function: func_02071F20, func_02072068, func_020721BC, func_0207229C
 * address:  0x02071F20
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *   data_020A8458  0x020A8458  data
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 */
typedef unsigned char u8;

typedef signed int   s32_02071F20;

typedef unsigned int u32;

typedef signed long long s64_02071F20;

typedef struct Obj {
    u32 f00;
    u8  pad04[0x2c];
    s32_02071F20 f30;
    s32_02071F20 f34;
} Obj;

typedef struct Rec {
    u32 hdr;
    s32_02071F20 f04;
    s32_02071F20 f08;
    s32_02071F20 f0c;
    s32_02071F20 f10;
    s32_02071F20 f14;
    s32_02071F20 f18;
    s32_02071F20 f1c;
    s32_02071F20 f20;
    s32_02071F20 f24;
    s32_02071F20 f28;
    s32_02071F20 f2c;
    s32_02071F20 f30;
    s32_02071F20 f34;
    s32_02071F20 f38;
    s32_02071F20 f3c;
    s32_02071F20 f40;
    s32_02071F20 f44;
    s32_02071F20 f48;
} Rec;

typedef void (*Fill)(s32_02071F20 *out, Obj *o);

typedef unsigned short u16;

typedef short          s16;

typedef int            s32_02072068;

typedef long long      s64_02072068;

struct SRC_02072068 {
    u8  pad_00[0x18];
    s32_02072068 f18;
    s32_02072068 f1c;
    s16 f20;
    s16 f22;
    s32_02072068 f24;
    s32_02072068 f28;
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32_02072068 f00;
    s32_02072068 f04;
    u8  pad_08[8];
    s32_02072068 f10;
    s32_02072068 f14;
    u8  pad_18[0x18];
    s32_02072068 f30;
    s32_02072068 f34;
};

typedef int            s32_020721BC;

typedef long long      s64_020721BC;

struct SRC_020721BC {
    u8  pad_00[0x18];
    s32_020721BC f18;
    s32_020721BC f1c;
    s16 f20;
    s16 f22;
    s32_020721BC f24;
    s32_020721BC f28;
    u16 f2c;
    u16 f2e;
};

typedef int            s32_0207229C;

typedef long long      s64_0207229C;

struct SRC_0207229C {
    u8  pad_00[0x18];
    s32_0207229C f18;
    s32_0207229C f1c;
    u8  pad_20[4];
    s32_0207229C f24;
    s32_0207229C f28;
    u16 f2c;
    u16 f2e;
};

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0207C930(u32 numer, u32 denom);
extern s32_02072068  func_0207C86C(void);
void func_02071F20(Obj *o);
extern Fill data_020A8458[];


/*
 * One of the two CALLERS of the 0x02071CDC constructor family
 * (docs/notes/pkt_02071DD4.c.txt).  It builds a 0x4c-byte command record
 * on the stack, fills the record's 2x3 matrix block by dispatching on the
 * low three bits of the object's flag word through a pointer table, then
 * applies the object's f30/f34 scales to the two rows -- each through the
 * family's `>> 12` on an s64 product, which folds to `lsr #0xc` +
 * `orr ..., lsl #20` -- and hands the record to func_0206DDA4.
 *
 * Each scale is skipped outright when it is already the unit 0x1000, so
 * both are guarded compares against 0x1000 rather than multiplies by one.
 *
 * Three levers, all measured, and all needed:
 *
 * L1  f30/f34 are plain fields.  The image RE-READS the scale from the
 *     object before the second and third multiply of each block
 *     (`ldr r2,[r4,#0x30]` at 0x02071FC4, `ldr r1,[r4,#0x30]` at
 *     0x02071FDC); the NITRO 2.0 compiler keeps those loads, so the source
 *     reads o->f30 for each multiply and binds only the guard's load to a
 *     local `s`.
 * L2  THE CALL'S BASE IS A POINTER LOCAL.  The image spends two
 *     instructions on the argument, `add r1, sp, #0` then
 *     `add r1, r1, #4` (0x02072040/0x02072048); `&r.f04` folds to a
 *     single `add r1, sp, #4` and loses 4 bytes.  `(s32 *)&r` bound
 *     first, then `base + 1`, reproduces the pair.
 * L3  THE FOUR HEADER CONSTANTS ARE ORDERED BY THE STORES, NOT THE
 *     DECLARATIONS.  mwcc emits the constant movs in order of the first
 *     store that uses each, and sinks any constant whose store sits
 *     after the zero run.  `f04, f48, f40, f44` is the only one of the
 *     orderings measured that gives the image's `mov r1,#0 / mov r3,#3 /
 *     mov r2,#2 / mov r0,#0x1000`; f44-first is 27 bytes out and
 *     f48-first 8, differing by a pure rotation of the three non-zero
 *     constants.  Declaration order and binding the constants to locals
 *     at all are both insensitive.
 */
void func_02071F20(Obj *o)
{
    Rec r;
    s32_02071F20 z;
    s32_02071F20 three = 3;
    s32_02071F20 two = 2;
    s32_02071F20 unit = 0x1000;

    z = 0;
    if (o->f00 & 8) {
        r.hdr = 0x00101610;
    } else {
        r.hdr = 0x00101810;
    }
    r.f04 = three;
    r.f48 = two;
    r.f40 = z;
    r.f44 = unit;
    r.f34 = z;
    r.f30 = z;
    r.f2c = z;
    r.f28 = z;
    r.f24 = z;
    r.f20 = z;
    r.f14 = z;
    r.f10 = z;

    data_020A8458[o->f00 & 7](&r.f08, o);

    {
        s32_02071F20 s = o->f30;
        if (s != 0x1000) {
            r.f08 = (s32_02071F20)(((s64_02071F20)s * r.f08) >> 12);
            r.f0c = (s32_02071F20)(((s64_02071F20)o->f30 * r.f0c) >> 12);
            r.f38 = (s32_02071F20)(((s64_02071F20)o->f30 * r.f38) >> 12);
        }
    }
    {
        s32_02071F20 s = o->f34;
        if (s != 0x1000) {
            r.f18 = (s32_02071F20)(((s64_02071F20)s * r.f18) >> 12);
            r.f1c = (s32_02071F20)(((s64_02071F20)o->f34 * r.f1c) >> 12);
            r.f3c = (s32_02071F20)(((s64_02071F20)o->f34 * r.f3c) >> 12);
        }
    }

    {
        s32_02071F20 *base = (s32_02071F20 *)&r;
        func_0206DDA4(r.hdr, base + 1, 0x12);
    }
}


/*
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
void func_02072068(struct DST *d, struct SRC_02072068 *s)
{
    s32_02072068 f12, e12;
    s32_02072068 a, b, p, r;
    s32_02072068 x4, x5;
    s64_02072068 h1, h2;
    s32_02072068 n, m, c;
    s32_02072068 t;

    f12 = (s32_02072068)s->f2c << 12;
    e12 = (s32_02072068)s->f2e << 12;
    func_0207C930(e12, f12);

    a = (s32_02072068)s->f22;
    p = s->f18;
    b = (s32_02072068)s->f20;
    r = s->f1c;

    d->f00 = (s32_02072068)(((s64_02072068)p * a) >> 12);
    t  = (s32_02072068)(((s64_02072068)p * b) >> 12);
    x4 = (s32_02072068)(((s64_02072068)r * a) >> 12);
    x5 = t;
    d->f14 = x4;
    d->f04 = ((s32_02072068)(((s64_02072068)r * b) >> 12) * func_0207C86C()) >> 12;

    func_0207C930(f12, e12);

    c  = (s32_02072068)s->f2c;
    h2 = (((s64_02072068)s->f24 * (s32_02072068)s->f22) + ((s64_02072068)s->f28 * (s32_02072068)s->f20)) >> 12;
    h1 = (((s64_02072068)s->f24 * (s32_02072068)s->f20) - ((s64_02072068)s->f28 * (s32_02072068)s->f22)) >> 12;

    m = x4 + (s32_02072068)((h1 * s->f1c) >> 12);
    n = x5 - (s32_02072068)((h2 * s->f18) >> 12);
    m = m - 0x1000;
    d->f30 = (c * n) << 4;
    d->f34 = ((0 - (s32_02072068)s->f2e) * m) << 4;

    d->f10 = ((0 - x5) * func_0207C86C()) >> 12;
}


/*
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
 */
void func_020721BC(struct DST *d, struct SRC_020721BC *s)
{
    s32_020721BC e12, f12, t, h1, h2;

    e12 = (s32_020721BC)((u32)s->f2c << 12);
    f12 = (s32_020721BC)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    d->f00 = s->f22;
    d->f14 = s->f22;

    t = func_0207C86C();
    d->f04 = (s->f20 * t) >> 12;

    func_0207C930(e12, f12);

    h1 = (s32_020721BC)((((s64_020721BC)s->f24 * s->f22) + ((s64_020721BC)s->f28 * s->f20)) >> 12);
    h2 = (s32_020721BC)((((s64_020721BC)s->f24 * s->f20) - ((s64_020721BC)s->f28 * s->f22)) >> 12);

    d->f30 = ((s32_020721BC)s->f2c * (s->f20 - h1)) << 4;
    d->f34 = ((0 - (s32_020721BC)s->f2e) * (s->f22 + h2 - 0x1000)) << 4;

    t = func_0207C86C();
    d->f10 = ((0 - (s32_020721BC)s->f20) * t) >> 12;
}


/*
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
void func_0207229C(struct DST *d, struct SRC_0207229C *s)
{
    s32_0207229C a, b, nb, hi;

    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;

    a = 0 - (s32_0207229C)(((s64_0207229C)s->f24 * s->f18) >> 12);
    nb = 0 - s->f28;
    hi = (s32_0207229C)(((s64_0207229C)nb * s->f1c) >> 12);
    d->f30 = ((s32_0207229C)s->f2c * a) << 4;
    b = s->f1c + hi - 0x1000;
    d->f34 = ((0 - (s32_0207229C)s->f2e) * b) << 4;

    d->f10 = 0;
}
