/*
 * file:     nns_g3d_anm_calc_9.c
 * unit:     yes
 * function: func_02070D18, func_02070DDC, func_02070F2C, func_02071034, func_02071104, func_02071180, func_020711C8, func_020712A8, func_02071360, func_020713A4, func_020713C8, func_02071510, func_0207163C, func_02071858
 * address:  0x02070D18
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
 *   g_02148DB0  0x02148DB0  data
 *   g_02149BC0  0x02149BC0  data
 *   FX_DivAsync       0x0207C930  arm
 *   FX_GetDivResult   0x0207C86C  arm
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 *   g_dispatch       0x020A8438  data a4
 *   MIi_CpuCopy32  0x02082A90  arm
 *   g_02149BB4     0x02149BB4  data
 */

struct Obj_02070D18;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int    s32_02070D18;

struct Vec { s32_02070D18 a, b, c; };

struct Owner_02070D18 {
    u32 flags;   /* 0x00 */
    s32_02070D18 f04;
    s32_02070D18 f08;
    s32_02070D18 f0c;
    struct Vec v10;   /* 0x10 */
};

struct Desc {
    u8 f00;
    u8 idx;      /* 0x01 */
    u8 slot;     /* 0x02 */
    u8 mode;     /* 0x03 */
};

struct Bank {
    u8  pad_00[0xc4];
    u32 bits[1];  /* 0xc4 */
};

typedef unsigned short u16;

typedef signed short s16_02070D18;

typedef signed long long s64_02070D18;

struct Src { u8 pad_00[0x18]; s32_02070D18 f18; s32_02070D18 f1c; s16_02070D18 f20; s16_02070D18 f22;
             s32_02070D18 f24; s32_02070D18 f28; u16 f2c; u16 f2e; };

struct Dst { s32_02070D18 f00; s32_02070D18 f04; u8 pad_08[8]; s32_02070D18 f10; s32_02070D18 f14;
             u8 pad_18[0x18]; s32_02070D18 f30; s32_02070D18 f34; };

struct Row { struct Vec v; s32_02070D18 pad[3]; };  /* 0x18 bytes */

struct Src71034 {
    u8  pad_00[0x20];
    s16_02070D18 f20;
    s16_02070D18 f22;
    u32 f24;
    u32 f28;
    u16 f2c;
    u16 f2e;
};

struct Dst71034 {
    s32_02070D18 f00;
    s32_02070D18 f04;
    u8  pad_08[8];
    s32_02070D18 f10;
    s32_02070D18 f14;
    u8  pad_18[0x18];
    s32_02070D18 f30;
    s32_02070D18 f34;
};

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

typedef short          s16_02071104;

typedef int            s32_02071104;

struct XformSrc {
    u8  pad_00[0x18];
    s32_02071104 f18;
    s32_02071104 f1c;
    s16_02071104 f20;
    s16_02071104 f22;
    s32_02071104 f24;
    s32_02071104 f28;
    u16 f2c;
    u16 f2e;
};

struct XformDst {
    s32_02071104 f00;
    s32_02071104 f04;
    u8  pad_08[8];
    s32_02071104 f10;
    s32_02071104 f14;
    u8  pad_18[0x18];
    s32_02071104 f30;
    s32_02071104 f34;
};

typedef long long      s64_02071104;

typedef s32_02071104 fx32_020712A8;

typedef struct {
    u32  flag; u32 prmMatColor0; u32 prmMatColor1; u32 prmPolygonAttr; u32 prmTexImage; u32 prmTexPltt;
    fx32_020712A8 scaleS, scaleT; fx16 sinR, cosR; fx32_020712A8 transS, transT; u16 origWidth, origHeight; fx32_020712A8 magW, magH;
} MatAnmResult;

typedef struct { fx32_020712A8 _00,_01,_02,_03,_10,_11,_12,_13,_20,_21,_22,_23,_30,_31,_32,_33; } MtxFx44;

typedef int            s32;

typedef void (*Fn)(int *out, struct Obj_02070D18 *o);

struct Obj_02070D18 {
    u32 flags;   /* +0x00 */
    char pad[0x2c];
    volatile int sx;  /* +0x30 */
    volatile int sy;  /* +0x34 */
};

struct Obj_02071510 {
    u32 flags;            /* +0x00 */
    int a[3];             /* +0x04 */
    int b[3];             /* +0x10 */
    int c[3];             /* +0x1c */
    int pad28[9];         /* +0x28 */
    volatile int s[3];    /* +0x4c */
};

typedef long long      s64;

struct Owner_02071510 {
    u8  pad_00[0xc4];
    u32 bits[1];
};

struct Obj_0207163C {
    u32 flags;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 mtx[6];
};

struct Idx {
    u8 f0;
    u8 a;
    u8 b;
};

struct Obj_02071858 {
    volatile u32 flags;   /* +0x00 */
    u8  pad_04[0x14];
    s32 f18;
    s32 f1c;
    u8  pad_20[4];
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
    s32 f30;
    s32 f34;
};

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void FX_DivAsync(s32_02070D18 num, s32_02070D18 den);
extern s32_02070D18  FX_GetDivResult(void);
extern void func_0207C930(u32 numer, u32 denom);
extern s32_02071104  func_0207C86C(void);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
void func_02070D18(u8 *a);
void func_02070DDC(struct Owner_02070D18 *oo, s32_02070D18 *src, struct Desc *d, u32 f);
void func_02070F2C(struct Dst *d, struct Src *s);
void func_02071034(struct Dst71034 *d, struct Src71034 *s);
void func_02071104(struct Mtx44 *m, const struct MatAnm *anm);
void func_02071180(struct XformDst *d, struct XformSrc *s);
void func_020711C8(struct XformDst *d, struct XformSrc *s);
void func_020712A8(MtxFx44 *m, const MatAnmResult *anm);
void func_02071360(struct XformDst *d, struct XformSrc *s);
void func_020713A4(struct XformDst *d);
void func_020713C8(struct Obj_02070D18 *o);
void func_02071510(struct Obj_02071510 *o);
void func_0207163C(struct Obj_0207163C *o, s32 *m, struct Idx *idx, u32 flags);
void func_02071858(struct Obj_02071858 *o);
extern struct Bank *g_02148DB0;
extern struct Row  g_02149BC0[];
extern Fn   g_dispatch[8];
extern s32 g_02149BB4[][6];








/*
 * The wide sibling of func_02070C5C (docs/notes/pkt_02070C5C.c.txt): the same
 * flag-driven fan-out of func_0206DDA4 commands over one object, with a
 * leading bit-5/bit-3 block and a `first` latch.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md).  The image
 * writes the two arms of the bit-1 fan-out out SEPARATELY, each closing with
 * its own unconditional branch to the join: `bl 0x0206DDA4` / `b 0x02070DBC`
 * at 0x02070D8C/0x02070D90 for the 0x19 arm and `bl 0x0206DDA4` /
 * `b 0x02070DBC` at 0x02070D9C/0x02070DA0 for the 0x1a arm, with the shared
 * `add r1, r5, #0x28` hoisted between the `cmp r4, #0` and the `beq` at
 * 0x02070D78..0x02070D80.  1.1p1 -O4,p cross-jumps the pair into ONE `bl` and
 * one branch, giving 188 bytes against the original's 196.  Under the pin the
 * same C is 196 bytes, 0 mismatches.
 */
void func_02070D18(u8 *a)
{
    u32 f;
    u32 first;

    f = *(u32 *)a;
    first = 0;
    if ((f & 4) == 0)
        first = 1;
    if ((f & 0x20) != 0 && (f & 8) == 0) {
        if (first != 0) {
            func_0206DDA4(0x1c, a + 0x4c, 3);
            first = 0;
        }
        func_0206DDA4(0x1b, a + 0x10, 3);
    }
    f = *(u32 *)a;
    if ((f & 2) == 0) {
        if (first != 0)
            func_0206DDA4(0x19, a + 0x28, 0xc);
        else
            func_0206DDA4(0x1a, a + 0x28, 9);
    } else {
        if (first != 0)
            func_0206DDA4(0x1c, a + 0x4c, 3);
    }
    f = *(u32 *)a;
    if ((f & 1) == 0)
        func_0206DDA4(0x1b, a + 4, 3);
}







/*
 * PIN: ../2.0/sp2, the same pin its packet-mate src/matched/func_02070F2C.c
 * carries, here on the "kept branches" tell combined with the re-read tell.
 * The image keeps `beq 0x02070EF4` (`03 00 00 0a`) at 0x02070EE0 over the
 * THREE-instruction guard body at 0x02070EE4..0x02070EEC
 * (`00 00 9c e5` ldr r0,[ip] / `08 00 80 e3` orr r0,r0,#8 /
 * `00 00 8c e5` str r0,[ip]), closing it with `b 0x02070F0C`
 * (`05 00 00 ea`) at 0x02070EF0, and the guard body RE-READS the flags word
 * the `str r1, [ip]` at 0x02070EC0 has just written.  1.1p1 -O4,p predicates
 * the block AND forwards the still-live value, emitting
 * `orrne r0, r3, #8` / `strne r0, [ip]` / `bne`, giving 328 bytes against the
 * original's 336 with every byte before 0x02070EAC identical modulo the
 * eight-byte pool displacement.  Under the pin the same C is 336 bytes,
 * 0 mismatches.
 *
 * The C lever, needed under BOTH front ends: the three-word row copy at
 * 0x02070F04/0x02070F08 (`ldm r0, {r0, r1, r2}` / `stm r3, {r0, r1, r2}`) is
 * a struct assignment, not three field assignments.  Written out field by
 * field, 1.1p1 and 2.0 both emit three `ldr`/`str` pairs off separate pool
 * words: 344 bytes and 298 concrete out.
 */
void func_02070DDC(struct Owner_02070D18 *oo, s32_02070D18 *src, struct Desc *d, u32 f)
{
    struct Owner_02070D18 *o = oo;
    u32 m;

    m = d->mode;

    if (f & 4) {
        o->flags |= 1;
        if (m & 2) {
            u32 i = d->idx;
            g_02148DB0->bits[i >> 5] |= 1U << (i & 0x1f);
        }
    } else {
        o->f04 = src[0];
        o->f08 = src[1];
        o->f0c = src[2];
        if (m & 2) {
            u32 i = d->idx;
            g_02148DB0->bits[i >> 5] &= ~(1U << (i & 0x1f));
            g_02149BC0[i].v.a = src[3];
            g_02149BC0[i].v.b = src[4];
            g_02149BC0[i].v.c = src[5];
        }
    }

    if (m & 1) {
        u32 j = d->slot;
        o->flags |= 0x20;
        if (g_02148DB0->bits[j >> 5] & (1U << (j & 0x1f))) {
            o->flags |= 8;
        } else {
            o->v10 = g_02149BC0[j].v;
        }
    }

    o->flags |= 0x10;
}








/*
 * The 64-bit sibling of src/matched/func_02071034.c (docs/notes/pkt_02070DDC.c.txt),
 * and the member of the 0x02071CDC constructor family that carries the full
 * s32_02070D18 2x2 block AND the f24/f28 cross terms.
 *
 * THE LEVER THE NOTE WAS MISSING, and it closes the 12-byte residue the note
 * records at this address: THE TWO f18 PRODUCTS ARE COMPUTED x7 (f18*f20)
 * FIRST, x6 (f18*f22) SECOND, even though x6 is the one stored first, to
 * d->f00.  Writing them in store order (x6 then x7) gives the allocator's
 * choice, r7 for x6 and r6 for x7, which is exactly the image's pair
 * REVERSED: 14 concrete bytes out, in the six instructions at +0x3C..+0x4C
 * plus `str`/`add`/`mul` at +0x68/+0x94/+0xF8.  Swapping the two statements
 * takes it to 0.  Declaration order (x7,x6), the commutative order of the
 * `x7 + x6` addend, and reversing each smull's operands are all 13-14 out.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md) in its
 * scheduling form.  The image loads the two s16_02070D18 fields in the order f22 then
 * f20 -- `ldrsh r5, [sb, #0x22]` (`f2 52 d9 e1`) at 0x02070F54 and
 * `ldrsh r0, [sb, #0x20]` (`f0 02 d9 e1`) at 0x02070F5C, straddling the
 * `ldr r3, [sb, #0x18]` -- and then consumes them in the OPPOSITE order,
 * f22's product into r6 and f20's into r7.  1.1p1 -O4,p refuses to separate
 * the load from its first use: it swaps the two `ldrsh`es to match the
 * consumption order and carries the swap through both lsr/orr pairs, the same
 * 264 bytes with 8 concrete bytes out.  No source ordering reaches 0 under
 * 1.1p1, because whichever statement order is written, 1.1p1 reorders the
 * loads to follow it.  Under the pin the same C is 264 bytes, 0 mismatches.
 */
void func_02070F2C(struct Dst *d, struct Src *s)
{
    s32_02070D18 c, e;
    s32_02070D18 a, b, p, r;
    s32_02070D18 x6, x7, x5, x4;
    s32_02070D18 n;

    c = (s32_02070D18)s->f2c << 12;
    e = (s32_02070D18)s->f2e << 12;
    FX_DivAsync(e, c);

    a = (s32_02070D18)s->f22;
    p = s->f18;
    b = (s32_02070D18)s->f20;
    r = s->f1c;

    x7 = (s32_02070D18)(((s64_02070D18)p * b) >> 12);
    x6 = (s32_02070D18)(((s64_02070D18)p * a) >> 12);
    x5 = (s32_02070D18)(((s64_02070D18)r * b) >> 12);
    x4 = (s32_02070D18)(((s64_02070D18)r * a) >> 12);

    d->f00 = x6;
    d->f14 = x4;
    d->f04 = ((0 - x5) * FX_GetDivResult()) >> 12;

    FX_DivAsync(c, e);

    n = s->f18 - (x7 + x6);
    d->f30 = ((s32_02070D18)s->f2c * n << 3)
           - ((s32_02070D18)s->f2c * (s32_02070D18)(((s64_02070D18)s->f18 * s->f24) >> 8));
    n = ((x5 - x4) - s->f1c) + 0x2000;
    d->f34 = ((s32_02070D18)s->f2e * (s32_02070D18)(((s64_02070D18)s->f1c * s->f28) >> 8))
           + ((s32_02070D18)s->f2e * n << 3);

    d->f10 = (x7 * FX_GetDivResult()) >> 12;
}







/*
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
void func_02071034(struct Dst71034 *d, struct Src71034 *s)
{
    s32_02070D18 c = (u16)s->f2c << 12;
    s32_02070D18 e = (u16)s->f2e << 12;
    s32_02070D18 n;
    s32_02070D18 q;

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
void func_02071180(struct XformDst *d, struct XformSrc *s)
{
    s32_02071104 t;

    d->f00 = 0x1000;
    d->f14 = 0x1000;
    d->f04 = 0;

    t = s->f24 * (s32_02071104)s->f2c;
    d->f30 = (0 - t) << 4;

    t = s->f28 * (s32_02071104)s->f2e;
    d->f34 = t << 4;

    d->f10 = 0;
}








/*
 * THE FULL smull 2x2 MEMBER of the (DST_02070D18, SRC_02070D18) matrix-constructor family
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
 *      `temp(tmp1=(s32_02071104) ((((s64_02071104) p) * b) >)`, 632 compiles, 35 -> 12 -- after
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
void func_020711C8(struct XformDst *d, struct XformSrc *s)
{
    s32_02071104 f12, e12;
    s32_02071104 a, b, p, r;
    s32_02071104 x6, x7, x5, x4;
    s32_02071104 n;
    s32_02071104 t, u;

    f12 = (s32_02071104)s->f2c << 12;
    e12 = (s32_02071104)s->f2e << 12;
    func_0207C930(e12, f12);

    a = (s32_02071104)s->f22;
    p = s->f18;
    b = (s32_02071104)s->f20;
    r = s->f1c;

    t  = (s32_02071104)(((s64_02071104)p * b) >> 12);
    x6 = (s32_02071104)(((s64_02071104)p * a) >> 12);
    x7 = t;
    x5 = (s32_02071104)(((s64_02071104)r * b) >> 12);
    x4 = (s32_02071104)(((s64_02071104)r * a) >> 12);

    d->f00 = x6;
    d->f14 = x4;
    d->f04 = ((0 - x5) * func_0207C86C()) >> 12;

    func_0207C930(f12, e12);

    u = s->f18 - (x7 + x6);
    n = u;
    d->f30 = ((s32_02071104)s->f2c * n) << 3;

    n = (x5 - x4) - s->f1c;
    n = n + 0x2000;
    d->f34 = ((s32_02071104)s->f2e * n) << 3;

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





/*
 * The 68-byte member of the cluster_02071360 constructor family: copies
 * the source's f18/f1c straight into the destination's diagonal slots
 * f00/f14, zeroes f04/f10/f30 and derives f34 from f1c and the angle
 * halfword f2e.
 *
 * The f34 term is the whole difficulty.  The image forms it as
 * `lsl r1, r2, #1; rsb r1, r1, #0; add r1, r1, #0x2000; mul; lsl #3`,
 * i.e. -(2*f1c) + 0x2000 with the constant added LAST.  Every factored
 * spelling folds it: `(0x1000 - f1c) * f2e * 16` is 60 bytes (rsb #0x1000,
 * lsl #4), `(0x2000 - f1c * 2) * f2e * 8` is 64 (rsb #0x2000).  Only the
 * doubled operand written out twice, `0x1000 - f1c + 0x1000 - f1c` (a
 * macro argument expanded twice, by the look of it), keeps the negate and
 * the separate add.
 *
 * Front end: NOT pinned.  EXACT under both dsi/1.1p1 and ../2.0/sp2 with
 * the same C (the zero is materialised early, at +0x04, in the image, so
 * there is no "kept constants" tell for 2.0 to bite on); filed under the
 * project default.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02071360.c \
 *       --func func_02071360 --addr 0x02071360 --arm
 */
void func_02071360(struct XformDst *d, struct XformSrc *s)
{
    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;
    d->f30 = 0;
    d->f34 = (0x1000 - s->f1c + 0x1000 - s->f1c) * s->f2e * 8;
    d->f10 = 0;
}




/*
 * Unlabelled leaf of the 0x02071104 family (saves no lr, so disasm.py
 * never labels it): the identity constructor. Writes the 0x1000 unit
 * scale into f00/f14 and zeroes f04/f10/f30/f34.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell: the image materialises
 * the unit scale FIRST, `mov r2, #0x1000` (`01 2a a0 e3`) at 0x020713A4
 * followed by `str r2, [r0]`, and only then `mov r1, #0` (`00 10 a0 e3`)
 * at 0x020713AC. 1.1p1 -O4,p schedules the zero first for the same 36
 * bytes, 9 concrete bytes out; binding both constants to locals declared
 * in either order, and writing f14 immediately after f00, all keep the
 * zero-first schedule. Under the pin the same C is 36 bytes, 0 mismatches.
 */
void func_020713A4(struct XformDst *d)
{
    d->f00 = 0x1000;
    d->f04 = 0;
    d->f10 = 0;
    d->f14 = 0x1000;
    d->f30 = 0;
    d->f34 = 0;
}



/*
 * Builds a 0x4c-byte descriptor on the stack, fills its transform slots
 * through a dispatch handler selected by the low three bits of the object's
 * flag word, then applies the object's two fixed-point (1.12) scale factors
 * to the three components of each of the two vectors when the factor is not
 * unity, and hands the finished descriptor to func_0206DDA4.
 *
 * The two scale fields are declared volatile because the image re-reads
 * [r4,#0x30] / [r4,#0x34] before each of the three smulls in its block,
 * where 1.1p1 -O4,p otherwise caches the field in a register and batches
 * the three multiplies together (308 bytes against the original's 328).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020713C8.c \
 *       --func func_020713C8 --addr 0x020713C8 --cc 1.1p1 --arm
 */
void func_020713C8(struct Obj_02070D18 *o)
{
    int buf[0x13];
    int sc;

    if (o->flags & 8) buf[0] = 0x00101610;
    else              buf[0] = 0x00101810;

    buf[1] = 3;
    buf[0x12] = 2;
    buf[0x10] = 0;
    buf[13] = 0;
    buf[12] = 0;
    buf[11] = 0;
    buf[10] = 0;
    buf[9] = 0;
    buf[8] = 0;
    buf[5] = 0;
    buf[4] = 0;
    buf[0x11] = 0x1000;

    g_dispatch[o->flags & 7](&buf[2], o);

    sc = o->sx;
    if (sc != 0x1000) {
        buf[2] = (int)(((long long)sc * buf[2]) >> 12);
        buf[3] = (int)(((long long)o->sx * buf[3]) >> 12);
        buf[14] = (int)(((long long)o->sx * buf[14]) >> 12);
    }
    sc = o->sy;
    if (sc != 0x1000) {
        buf[6] = (int)(((long long)sc * buf[6]) >> 12);
        buf[7] = (int)(((long long)o->sy * buf[7]) >> 12);
        buf[15] = (int)(((long long)o->sy * buf[15]) >> 12);
    }

    {
        char *q = (char *)buf;
        func_0206DDA4((u32)buf[0], (int *)(q + 4), 0x12);
    }
}



/*
 * Flushes the object's dirty transform components to func_0206DDA4, one
 * call per component group, each gated by a bit of the flag word at +0x00.
 * Bits 3/4 (mask 0x18) select whether the rotation block is sent raw or the
 * translation is pre-scaled by the 1.12 factors at +0x4c; bit 2 suppresses
 * the scaled translation, bit 1 selects the long (0xc) over the short (9)
 * matrix push, and bit 0 suppresses the final component push.
 *
 * Pinned to ../2.0/sp2: see docs/FRONTEND-PINS.md, the "kept branches" tell.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071510.c \
 *       --func func_02071510 --addr 0x02071510 --cc ../2.0/sp2 --arm
 */
void func_02071510(struct Obj_02071510 *o)
{
    int tmp[3];
    int flag = 0;
    int m;

    m = o->flags & 0x18;
    if (m == 0)
        func_0206DDA4(0x1b, &o->c[0], 3);

    if (!(o->flags & 4)) {
        if (m != 0) {
            flag = 1;
        } else {
            tmp[0] = (int)(((long long)o->s[0] * o->b[0]) >> 12);
            tmp[1] = (int)(((long long)o->s[1] * o->b[1]) >> 12);
            tmp[2] = (int)(((long long)o->s[2] * o->b[2]) >> 12);
            func_0206DDA4(0x1c, tmp, 3);
        }
    }

    if (!(o->flags & 2)) {
        if (flag) func_0206DDA4(0x19, &o->pad28[0], 0xc);
        else      func_0206DDA4(0x1a, &o->pad28[0], 9);
    } else if (flag) {
        func_0206DDA4(0x1c, (void *)&o->s[0], 3);
    }

    if (m == 0)
        func_0206DDA4(0x1b, &o->b[0], 3);

    if (!(o->flags & 1))
        func_0206DDA4(0x1b, &o->a[0], 3);
}




/*
 * The matrix-slot propagation step of the cluster_02071360 transform
 * stage.  `idx` names two slots of the 0x18-byte record table at
 * 0x02149BB4 (a = idx[1], b = idx[2]); the owner at *0x02148DB0 carries
 * a per-slot bitmask at +0xC4.
 *   flags & 4:  set o->flags bit 0; if b's bit is set, set a's bit and
 *               o->flags |= 0x18; otherwise copy record b over record a
 *               and into o->mtx.
 *   otherwise:  copy m[0..2] into o->f04..f0c; if b's bit is set, copy m
 *               into record a, clear a's bit, o->flags |= 0x18; otherwise
 *               clear a's bit, record a = m * record b component-wise in
 *               1.12 ((s64)x*y >> 12, six terms) and copy record b into
 *               o->mtx.
 *
 * THE SIX POOL WORDS.  The image's pool holds 0x02149BB4, ...BB8, ...BBC,
 * ...BC0, ...BC4, ...BC8: not six objects but ONE `s32 [][6]` table,
 * whose column k is addressed as symbol+4k because a register-offset
 * `ldr r, [base, ip]` has no room for a further immediate.  The single
 * 2-D extern reproduces all six words (sole-ref/self per site).
 *
 * The callee is MIi_CpuCopy32 (src, dst, size), SOURCE FIRST: the first
 * argument of every call here is the record being read.
 *
 * Pin evidence (2.0): "kept constants".  The image rematerialises the
 * copy size `mov r2, #0x18` before each call; dsi/1.1p1 keeps 0x18 in a
 * callee-saved register and copies it (`mov r2, r6`), 536 bytes against
 * 540 with 362 concrete bytes out.  Under ../2.0/sp2 the same C is 540
 * bytes, 0 out, first compile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0207163C.c \
 *       --func func_0207163C --addr 0x0207163C --arm --cc ../2.0/sp2
 */
void func_0207163C(struct Obj_0207163C *o, s32 *m, struct Idx *idx, u32 flags)
{
    u32 a = idx->a;
    u32 b = idx->b;

    if (flags & 4) {
        o->flags |= 1;
        if (g_02148DB0->bits[b >> 5] & (1 << (b & 0x1f))) {
            g_02148DB0->bits[a >> 5] |= 1 << (a & 0x1f);
            o->flags |= 0x18;
            return;
        }
        MIi_CpuCopy32(g_02149BB4[b], g_02149BB4[a], 0x18);
        MIi_CpuCopy32(g_02149BB4[b], o->mtx, 0x18);
        return;
    }

    o->f04 = m[0];
    o->f08 = m[1];
    o->f0c = m[2];
    if (g_02148DB0->bits[b >> 5] & (1 << (b & 0x1f))) {
        MIi_CpuCopy32(m, g_02149BB4[a], 0x18);
        g_02148DB0->bits[a >> 5] &= ~(1 << (a & 0x1f));
        o->flags |= 0x18;
        return;
    }
    g_02148DB0->bits[a >> 5] &= ~(1 << (a & 0x1f));
    g_02149BB4[a][0] = (s32)(((s64)m[0] * g_02149BB4[b][0]) >> 12);
    g_02149BB4[a][1] = (s32)(((s64)m[1] * g_02149BB4[b][1]) >> 12);
    g_02149BB4[a][2] = (s32)(((s64)m[2] * g_02149BB4[b][2]) >> 12);
    g_02149BB4[a][3] = (s32)(((s64)m[3] * g_02149BB4[b][3]) >> 12);
    g_02149BB4[a][4] = (s32)(((s64)m[4] * g_02149BB4[b][4]) >> 12);
    g_02149BB4[a][5] = (s32)(((s64)m[5] * g_02149BB4[b][5]) >> 12);
    MIi_CpuCopy32(g_02149BB4[b], o->mtx, 0x18);
}



/*
 * The 0x4c-byte display-descriptor builder of the 0x020713C8 family: fills a
 * 15-word descriptor on the stack, selects the translation source out of the
 * flag word's bits 3 / 2 / 0, applies the object's two 1.12 scale factors at
 * +0x30 / +0x34 when they are not unity, and hands the whole thing to
 * func_0206DDA4 with a count of 0xe.
 *
 * PINNED ../2.0/sp2 on the "kept branches" tell, the same pin its family-mate
 * src/matched/func_02071510.c carries (see docs/FRONTEND-PINS.md).  The image
 * emits REAL branches for the three-way translation select: `beq 0x20718f0`
 * at +0x5C, `beq 0x20718dc` at +0x70, `b 0x2071990` at +0x80 and again at
 * +0x94.  dsi/1.1p1 -O4,p if-converts the two inner arms into predicated
 * `movne`/`strne` + `ldreq`/`streq` runs and drops both `b`s, giving 440
 * bytes against the original's 452 with everything after +0x60 shifted.  No
 * source shape recovers them under 1.1p1: measured with the arms written as
 * `goto`-terminated blocks (440), with the second test reading a cached local
 * (436), and with each arm carrying its own tail (440).  Under the pin the
 * same C is 460 bytes including the two trailing pool words, 0 mismatches.
 *
 * TWO FIELD TELLS, both `volatile`, both needed:
 *   +0x00 flags   the INNER test at +0x68 re-reads the flag word
 *                 (`ldr r1, [r0]`) although +0x54 has it in r1 already.
 *   +0x30, +0x34  each scale factor is loaded TWICE, once for the `cmp`
 *                 against 0x1000 and again for the second `smull`
 *                 (`ldr r2, [r0, #0x30]` at +0x15C).  Non-volatile, 1.1p1
 *                 and 2.0 both cache the field and batch the two multiplies,
 *                 which is 8 bytes short.  This is the same re-read the
 *                 family-mate func_020713C8 documents for its own +0x30/+0x34
 *                 pair.
 *
 * AND ONE NON-VOLATILE READ.  The OUTER else-branch at +0x98 reuses the flag
 * value already in r1 rather than re-reading it, so `o->flags & 1` cannot be
 * written against the volatile field there: it is cached in the local `fl`
 * taken before the `& 4` test.  Spelling that test volatile too costs exactly
 * one `ldr r1, [r0]` and shifts the whole tail by four bytes -- this was the
 * last four bytes of the function, and the only difference between 448 and
 * EXACT.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02071858.c \
 *       --func func_02071858 --addr 0x02071858 --arm --cc ../2.0/sp2
 */
void func_02071858(struct Obj_02071858 *o)
{
    int buf[0x0f];
    s32 sc;
    u32 fl;

    if (o->flags & 8) buf[0] = 0x00101710;
    else              buf[0] = 0x00101910;

    buf[1] = 3;
    buf[0x0d] = 0;
    buf[0x0a] = 0;
    buf[9] = 0;
    buf[8] = 0;
    buf[7] = 0;
    buf[5] = 0;
    buf[4] = 0;
    buf[3] = 0;
    buf[0x0e] = 2;

    fl = o->flags;
    if (fl & 4) {
        buf[0x0b] = 0;
        buf[0x0c] = 0;
        if (o->flags & 1) {
            buf[2] = 0x1000;
            buf[6] = 0x1000;
        } else {
            buf[2] = o->f18;
            buf[6] = o->f1c;
        }
    } else if (fl & 1) {
        buf[0x0b] = (0 - (o->f24 << 4)) * (s32)o->f2c;
        buf[0x0c] = (0 - (o->f28 << 4)) * (s32)o->f2e;
        buf[2] = 0x1000;
        buf[6] = 0x1000;
    } else {
        buf[0x0b] = (s32)o->f2c * (0 - (s32)(((s64)o->f18 * o->f24) >> 8));
        buf[0x0c] = (s32)o->f2e * (0 - (s32)(((s64)o->f1c * o->f28) >> 8));
        buf[2] = o->f18;
        buf[6] = o->f1c;
    }

    sc = o->f30;
    if (sc != 0x1000) {
        buf[2]    = (s32)(((s64)sc * buf[2]) >> 12);
        buf[0x0b] = (s32)(((s64)o->f30 * buf[0x0b]) >> 12);
    }
    sc = o->f34;
    if (sc != 0x1000) {
        buf[6]    = (s32)(((s64)sc * buf[6]) >> 12);
        buf[0x0c] = (s32)(((s64)o->f34 * buf[0x0c]) >> 12);
    }

    {
        char *q = (char *)buf;
        func_0206DDA4((u32)buf[0], (int *)(q + 4), 0x0e);
    }
}
