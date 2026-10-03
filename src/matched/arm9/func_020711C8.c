/*
 * function: func_020711C8
 * address:  0x020711C8
 * packet:   pkt_02071104
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 *
 * THE FULL smull 2x2 MEMBER of the (DST, SRC) matrix-constructor family
 * (docs/families/cluster_02070B64.h): all four products of f18/f1c x f20/f22
 * carried at 64-bit width and reduced by the family's `>> 12`, both FX
 * divisions, and an f30/f34 pair whose operands are SUMS AND DIFFERENCES OF
 * THE FOUR PRODUCTS rather than the f24/f28 cross terms.  Listed as NOT
 * ATTEMPTED in docs/notes/pkt_02071104.c.txt.
 *
 * THREE THINGS WERE NEEDED, and the third is the one that closed it.
 *
 * L-1  THE TWO `<< 12` SHIFTED ANGLE VALUES ARE NAMED LOCALS (L4 of the
 *      cluster header).  The image computes `lsl r8, r2, #0xc` /
 *      `lsl fp, r1, #0xc` ONCE at 0x020711DC/0x020711E0 and re-feeds the same
 *      two registers to the second func_0207C930 with the arguments swapped
 *      (`mov r1, fp` / `mov r0, r8` at 0x0207123C/0x02071250).  That is what
 *      forces the ten-register push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}.
 *      Spelled inline, the compiler re-reads f2c/f2e and re-shifts, frees two
 *      callee-saved registers and narrows the push list.
 *
 * L-2  TWO LIVE RANGES ARE SPLIT BY A FRESH TEMPORARY (L-F of
 *      docs/families/cluster_02071EAC.h).  `t` holds the f18*f20 narrowing,
 *      computed BEFORE x6 and only assigned to x7 after it; `u` holds the f30
 *      operand, computed and only then copied into `n`.  Each gives its value
 *      its own definition point, so it is numbered on the far side of its
 *      neighbour and the two colours come out the image's way round.  Without
 *      the pair the same source is 35 concrete bytes out (measured under the
 *      pin, so it is not a front-end effect); with it, 12.  tools/permuter.py
 *      found both in one hill pass -- `temp(tmp=s->f18 - (x7 + x6))` then
 *      `temp(tmp1=(s32) ((((s64) p) * b) >)`, 632 compiles, 35 -> 12 -- after
 *      a hand sweep had exhausted statement order and operand order at 35.
 *
 * L-3  PIN ../2.0/sp2.  The remaining 12 bytes under the default dsi/1.1p1
 *      are a straight exchange of r5/r0 on the two `ldrsh`es at
 *      0x020711F0/0x020711F8 and of r6/r7 on the two narrowing pairs that
 *      consume them (0x0207123C..0x0207124C): 1.1p1 loads f20 before f22 and
 *      colours the first product r7, where the image loads f22 first
 *      (`ldrsh r5, [sb, #0x22]`, f2 52 d9 e1) and colours it r6.  This is the
 *      family's usual tell in its scheduling form -- 1.1p1 refuses to separate
 *      a load from its first use and reorders the pair to follow the
 *      consumption order, exactly as measured for func_02070F2C at
 *      0x02070F54/0x02070F5C.  Four further spellings were measured against
 *      it under 1.1p1 (splitting x6's range instead of x7's: 28; both ranges
 *      split: 28; x5 hoisted between the two f18 products: 19; the f00 store
 *      moved below the f14 store: 16) and 2000 anneal compiles plateaued at
 *      12, so no source order reaches it.  Under the pin the SAME source is
 *      224 bytes, 0 mismatches.
 *
 * Note the f34 operand is `(x5 - x4) - s->f1c` with the `+ 0x2000` as a
 * SEPARATE statement (L-H): the image's `sub r0, r1, r0` at 0x02071280 and
 * `add r0, r0, #0x2000` at 0x02071284 are two instructions, not a folded one.
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

typedef unsigned int   u32;
extern void func_0207C930(u32 numer, u32 denom);
extern s32  func_0207C86C(void);

void func_020711C8(struct DST *d, struct SRC *s)
{
    s32 f12, e12;
    s32 a, b, p, r;
    s32 x6, x7, x5, x4;
    s32 n;
    s32 t, u;

    f12 = (s32)s->f2c << 12;
    e12 = (s32)s->f2e << 12;
    func_0207C930(e12, f12);

    a = (s32)s->f22;
    p = s->f18;
    b = (s32)s->f20;
    r = s->f1c;

    t  = (s32)(((s64)p * b) >> 12);
    x6 = (s32)(((s64)p * a) >> 12);
    x7 = t;
    x5 = (s32)(((s64)r * b) >> 12);
    x4 = (s32)(((s64)r * a) >> 12);

    d->f00 = x6;
    d->f14 = x4;
    d->f04 = ((0 - x5) * func_0207C86C()) >> 12;

    func_0207C930(f12, e12);

    u = s->f18 - (x7 + x6);
    n = u;
    d->f30 = ((s32)s->f2c * n) << 3;

    n = (x5 - x4) - s->f1c;
    n = n + 0x2000;
    d->f34 = ((s32)s->f2e * n) << 3;

    d->f10 = (x7 * func_0207C86C()) >> 12;
}
