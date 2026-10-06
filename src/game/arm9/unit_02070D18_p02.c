/*
 * file:     unit_02070D18_p02.c
 * unit:     yes
 * function: func_02071104, func_02071180, func_020711C8, func_020712A8
 * address:  0x02071104
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
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 *   FX_DivAsync      0x0207C930  arm
 *   FX_GetDivResult  0x0207C86C  arm
 */
typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          fx16;

typedef int            fx32_02070D18;

typedef long long      fx64;

struct MatAnm {
    u32  flag;
    u32  matColor0;
    u32  matColor1;
    u32  polygonAttr;
    u32  texImage;
    u32  texPltt;
    fx32_02070D18 scaleS;
    fx32_02070D18 scaleT;
    fx16 sinR;
    fx16 cosR;
    fx32_02070D18 transS;
    fx32_02070D18 transT;
    u16  origWidth;
    u16  origHeight;
    fx32_02070D18 magW;
    fx32_02070D18 magH;
};

struct Mtx44 {
    fx32_02070D18 _00, _01, _02, _03;
    fx32_02070D18 _10, _11, _12, _13;
    fx32_02070D18 _20, _21, _22, _23;
    fx32_02070D18 _30, _31, _32, _33;
};

typedef unsigned char  u8;

typedef short          s16;

typedef int            s32;

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

typedef long long      s64;

typedef s32 fx32_020712A8;

typedef struct {
    u32  flag; u32 prmMatColor0; u32 prmMatColor1; u32 prmPolygonAttr; u32 prmTexImage; u32 prmTexPltt;
    fx32_020712A8 scaleS, scaleT; fx16 sinR, cosR; fx32_020712A8 transS, transT; u16 origWidth, origHeight; fx32_020712A8 magW, magH;
} MatAnmResult;

typedef struct { fx32_020712A8 _00,_01,_02,_03,_10,_11,_12,_13,_20,_21,_22,_23,_30,_31,_32,_33; } MtxFx44;

extern void func_0207C930(u32 numer, u32 denom);
extern s32  func_0207C86C(void);
extern void FX_DivAsync(fx32_020712A8 numer, fx32_020712A8 denom);
extern fx32_020712A8 FX_GetDivResult(void);
void func_02071104(struct Mtx44 *m, const struct MatAnm *anm);
void func_02071180(struct DST *d, struct SRC *s);
void func_020711C8(struct DST *d, struct SRC *s);
void func_020712A8(MtxFx44 *m, const MatAnmResult *anm);



/*
 * NitroSystem g3d, the texture-SRT matrix builder for a material with scale
 * and translation but no rotation: fills the scale diagonal and the two
 * translation terms of a 4x4 fx32 matrix from a material animation result.
 * Same family as func_02071180 / func_020711C8 / func_020712A8 /
 * func_020713A4, which carry the same ../2.0/sp2 pin (docs/FRONTEND-PINS.md).
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 6.  The lever is the _31
 * term's aspect factor written as two subtractions of the same field,
 * `-scaleT - scaleT + 0x1000 * 2`, rather than `-(scaleT << 1)` or a
 * multiply by 2; with it scaleT lands in r4 and transT in ip as in the
 * image.  Every spelling in docs/notes/pkt_02071104.c.txt used a shift or a
 * multiply and tied at 6.
 *
 * Pin evidence: under the default dsi/1.1p1 this exact source is 116 bytes
 * against the image's 124 (SIZE, 103 concrete out); ../2.0/sp2, sp2p2 and
 * sp1 are all 124 bytes, 0 out; ../1.2/sp2 is 128 bytes.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071104.c \
 *       --func func_02071104 --addr 0x02071104 --arm --cc ../2.0/sp2
 */
void func_02071104(struct Mtx44 *m, const struct MatAnm *anm)
{
    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    m->_30 = -(fx32_02070D18)((fx64)anm->scaleS * anm->transS >> 8) * anm->origWidth;
    m->_31 = ((-anm->scaleT - anm->scaleT + 0x1000 * 2) * anm->origHeight << 3) +
             (fx32_02070D18)((fx64)anm->scaleT * anm->transT >> 8) * anm->origHeight;

    m->_10 = 0;
}




/*
 * Unlabelled leaf of the 0x02071104 family (saves no lr): the unit-scale
 * translate-only constructor. f00/f14 take the 0x1000 unit scale, f04/f10
 * are zero, and f30/f34 are the plain `-(f24 * f2c) << 4` form.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell: the image materialises
 * the zero LATE, `mov ip, #0` (`00 c0 a0 e3`) at 0x0207118C, AFTER the
 * `str r2, [r0]` at 0x02071184, so the f00 and f04 stores stay separate.
 * 1.1p1 -O4,p hoists the zero above the f00 store and merges the pair
 * into one `stm r0, {r2, ip}`, giving 68 bytes against the image 72 with
 * the whole body shifted by four (57 concrete bytes out). Under the pin
 * the same C is 72 bytes, 0 mismatches. Same stall as the 0x02072320
 * near miss recorded in docs/notes/pkt_02071DD4.c.txt.
 */
void func_02071180(struct DST *d, struct SRC *s)
{
    s32 t;

    d->f00 = 0x1000;
    d->f14 = 0x1000;
    d->f04 = 0;

    t = s->f24 * (s32)s->f2c;
    d->f30 = (0 - t) << 4;

    t = s->f28 * (s32)s->f2e;
    d->f34 = t << 4;

    d->f10 = 0;
}



/*
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

/*
 * NitroSystem g3d texture-SRT matrix, the rotation-only member: build a
 * texture MtxFx44 from a material animation result (NNSG3dMatAnmResult:
 * sinR/cosR fx16 at +0x20/+0x22, origWidth/origHeight u16 at +0x2c/+0x2e),
 * with the aspect correction from two hardware divides h/w and w/h.
 *
 * docs/notes/pkt_02071104.c.txt held this at 4 bytes (an r1/r2 swap on the
 * _30 term).  Two changes close it: the real structure types (MtxFx44 and
 * the MatAnmResult layout) under ../2.0/sp2, and the _30 factor's negation
 * done in u32, `(fx32)-(u32)(sinR + cosR) + 0x1000`.  A signed negation folds
 * with the + 0x1000 into one rsb (180 bytes); the three-statement spelling
 * keeps the size but swaps the registers.  The permuter's anneal found the
 * unsigned negation (`temp(tmp=-t) ; cast(u32)`); this is its readable form.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020712A8.c \
 *       --func func_020712A8 --addr 0x020712A8 --arm --cc ../2.0/sp2
 */
void func_020712A8(MtxFx44 *m, const MatAnmResult *anm)
{
    fx32_020712A8 w = anm->origWidth << 12;
    fx32_020712A8 h = anm->origHeight << 12;
    FX_DivAsync(h, w);
    m->_00 = anm->cosR;
    m->_11 = anm->cosR;
    m->_01 = (-anm->sinR * FX_GetDivResult()) >> 12;
    FX_DivAsync(w, h);
    m->_30 = (anm->origWidth * ((fx32_020712A8)-(u32)(anm->sinR + anm->cosR) + 0x1000)) << 3;
    m->_31 = (anm->origHeight * (anm->sinR - anm->cosR + 0x1000)) << 3;
    m->_10 = (anm->sinR * FX_GetDivResult()) >> 12;
}
