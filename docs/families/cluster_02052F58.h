/*
 * docs/families/cluster_02052F58.h -- shared declarations for the
 * pseudo-family cluster_02052F58, 0x02052F58..0x02057E68 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * WHAT SUBSYSTEM THIS IS.  The **3D billboard / particle rig renderer**: the
 * per-frame walk of a rig's render lists and the geometry-engine (GX)
 * submission that each list node performs.  The upper half of the ARM9 image
 * carries no __FILE__ anchors, so this cluster is address adjacency plus
 * shared callees and data objects, not a proven translation unit; but the
 * evidence that it is one subsystem is strong and concrete:
 *
 *   - Two per-frame dispatchers at the low edge, func_02053044 and
 *     func_0205312C, each walk one of the rig block's two singly linked node
 *     lists and call a per-node handler chosen from a 2-bit field of the
 *     descriptor.  Between them their two pool runs name EIGHT handler rows
 *     (0x02053E1C, 0x0205429C, 0x02054718, 0x02054A68, 0x02054DB8,
 *     0x02055498, 0x02055B80, 0x02055FD4) and the shared setup row
 *     func_02053D30.  Every one of those addresses is inside this cluster.
 *   - Every handler row that is already EXACT (func_0205429C, func_02054718,
 *     func_02054A68) has the same skeleton: read the rig's scale word, poke
 *     0x040004A4 (POLYGON_ATTR), build a basis matrix through the hook table
 *     at 0x020A7FE4, concat with MTX_Concat43 (func_0207B9F0), push the
 *     result, mix two RGB555 colours into 0x04000480, and finish through the
 *     second hook table at 0x020A7FDC.
 *   - The two hook tables and the vertex table are shared cluster-wide:
 *       0x020A1B38  Verts   const s16[]  sin/cos pairs, indexed 2*i / 2*i+1
 *       0x020A7FE4  Hooks   { 0x02056420, 0x02056460 }   basis builders
 *       0x020A7FDC  Hooks2  { func_020565C8, func_0205650C }  quad emitters
 *     (main.s 277874..277877; the words are in the image, not guessed).
 *   - func_02053A60 initialises one emitter instance from a resource
 *     descriptor, and func_02053D30 sets TEXIMAGE_PARAM/PLTT_BASE and the
 *     texture matrix for one 0x14-byte texture row of the same descriptor.
 *
 * COMPILER PIN, cluster-wide: `compiler: ../1.2/sp2`, `flags: -O4,p -proc
 * arm946e`.  Documented in docs/FRONTEND-PINS.md as "the 3D rig unit"; the
 * tell is a register `blx rN` beside an ARMv4T-style `pop {..., lr}; bx lr`
 * return, a pair no dsi front end emits under -proc arm946e.
 *
 * *** THE PIN IS LOAD-BEARING AND TWO EXISTING NOTES MISSED IT. ***
 * Every docs/notes/*.c.txt covering this address range was measured under
 * `1.1p1` only, and two of them recorded a wrong conclusion because of it:
 *   - docs/notes/pkt_02053A60.c.txt declared 0x02053A60 an unresolvable
 *     "arm7tdmi epilogue versus ARMv5TE smulbb" conflict.  Under the pin the
 *     conflict does not exist: ../1.2/sp2 -proc arm946e emits BOTH the v4T
 *     return and the four smulbb, and the note's own source went from
 *     708 bytes / 66 out to 716/716 with 17 out at a single flag change.
 *     That row is now EXACT (src/matched/func_02053A60.c).
 *   - docs/notes/pkt_02057C9C.c.txt pinned 0x02057C9C to -proc arm7tdmi from
 *     its four v4T epilogues.  Under ../1.2/sp2 that proc gives 468 bytes
 *     against 460; -proc arm946e gives 460/460 (118 concrete out, then 73
 *     after a permuter pass).  Same correction, same cause.
 * Re-measure the proc per row under the PIN before trusting any note in this
 * range.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x0205[2-7]" src/matched/*.c
 * (func_02052F58, func_02052F90, func_02052FC8, func_02053044, func_0205312C,
 * func_02053A60, func_02053D2C, func_0205429C, func_02054718, func_02054A68,
 * func_02056460, func_020576D0, func_02057830, func_02057AB8, func_02057B10,
 * func_02057B5C, func_02057BC0, func_02057E68) and from the DIFF write-ups in
 * docs/notes/ (pkt_02053218, pkt_02053A60, pkt_02055498, pkt_02056460,
 * pkt_02057830, pkt_02057C9C).
 *
 * ADJUDICATION RULES USED THROUGHOUT.
 *   - A load or store instruction constrains a field; a name does not.  An
 *     `ldrh` proves u16; a plain `ldr` with a following `lsl`/`lsr` pair
 *     proves a 32-bit field narrowed at the use.
 *   - An EQUAL-amount `lsl #n` / `lsr #n` pair on a 32-bit load is a
 *     BITFIELD, not a mask: a mask folds to `ands`.  Every selector in this
 *     cluster is written that way (docs/idioms/shift-pair-with-no-matching-
 *     type-is-a-bitfield.md).  `lsr` says unsigned, `asr` says signed.
 *   - The hardware registers are written as casts of absolute addresses, not
 *     as relocations: `*(volatile u32 *)0x04000480 = ...`.  They carry no
 *     relocation site and never need attestation.
 */

#ifndef CLUSTER_02052F58_H
#define CLUSTER_02052F58_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;
typedef int                fx32;
typedef long long          fx64;

/* ------------------------------------------------------------------ *
 * Geometry-engine registers (cast constants, never relocations)
 * Evidenced by: func_02053D30 (texture block), func_0205650C /
 * func_020565C8 (quad block), func_0205429C / func_02054718 (attr block).
 * ------------------------------------------------------------------ */
#define GX_MTX_MODE        (*(volatile u32 *)0x04000440)  /* func_02053D30 */
#define GX_MTX_IDENTITY    (*(volatile u32 *)0x04000454)  /* func_02053D30, func_0205429C */
#define GX_MTX_SCALE       (*(volatile u32 *)0x0400046C)  /* func_02053D30, 3 words */
#define GX_MTX_TRANS_FIFO  (*(volatile u32 *)0x04000470)  /* func_02054718, 3 words */
#define GX_COLOR           (*(volatile u32 *)0x04000480)  /* func_02054718 */
#define GX_TEXCOORD        (*(volatile u32 *)0x04000488)  /* func_0205650C */
#define GX_VTX_10          (*(volatile u32 *)0x04000490)  /* func_0205650C */
#define GX_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)  /* func_02054718 */
#define GX_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)  /* func_02053D30 */
#define GX_PLTT_BASE       (*(volatile u32 *)0x040004AC)  /* func_02053D30 */
#define GX_BEGIN_VTXS      (*(volatile u32 *)0x04000500)  /* func_0205650C */
#define GX_END_VTXS        (*(volatile u32 *)0x04000504)  /* func_0205650C */

/* ------------------------------------------------------------------ *
 * Fixed-point helper.  The +0x800 / >>12 rounding quartet is the single
 * most common shape in the cluster.  Evidenced by func_020576D0 (where it
 * is written out three times per row) and func_02056460.
 * ------------------------------------------------------------------ */
static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((fx64)a * b + 0x800) >> 12);
}

/* ------------------------------------------------------------------ *
 * Vector / matrix types.  MtxFx43 is a flat s32[12]; the translation row
 * is m[9..11].  Evidenced by func_0205429C, func_02054718, func_02056460.
 * ------------------------------------------------------------------ */
struct VecFx32 { s32 x, y, z; };          /* func_0205429C */
struct Vec16   { s16 x, y, z; };          /* func_020576D0, func_02057830 */
struct MtxFx43 { s32 m[12]; };            /* func_02056460 */
struct MtxFx33 { s32 m[9]; };             /* func_02054718 */

/* ------------------------------------------------------------------ *
 * The rig object graph.
 *
 *   Obj  (the per-frame object, argument 1 of every handler row)
 *     +0x2c  void *          texture-row array base; a row is 0x14 bytes
 *                            (func_02053044: `f2c + desc[0x0f] * 0x14`)
 *     +0x3c  u32             polygon-attr low bits (func_02054718)
 *     +0x40  SubB *          the rig block
 *     +0x44  MtxFx43 *       the current matrix (func_02054718)
 *
 *   SubB (the rig block, Obj+0x40)
 *     +0x08  Node *          render list B  (func_0205312C walks this one)
 *     +0x14  Node *          render list A  (func_02053044 walks this one)
 *     +0x20  SubX *
 *     +0x72  u16             modulation colour, RGB555 (func_02054718)
 *     +0x78/+0x7a  s16 s16   final-hook args, variant 1 (func_0205429C)
 *     +0x7c/+0x7e  s16 s16   final-hook args, variant 2 (func_02054718)
 *
 *   SubX (SubB+0x20)
 *     +0x00  SubC *          the numeric descriptor
 *     +0x14  SubD *          the halfword descriptor
 *
 *   SubC (SubX+0x00) -- read as bitfields throughout
 *     +0x00  bitfield word.  bit 16 gates the whole dispatch
 *            (func_02053044: `(w << 15) >> 31`); bits 17..18 are a hook
 *            selector (func_02054A68); bit 19 a second hook selector; bit 23
 *            the translate/identity flag (func_02054718 Bf23.sel).
 *     +0x04/+0x08/+0x0c  u32 x3   translation, pushed to GX_MTX_TRANS_FIFO
 *     +0x30  s16             scale numerator (func_02054718)
 *     +0x48  bitfield word.  bits 28..30 are the three-way x/y scale
 *            selector (func_02054718 Bf28.sel, five arms with 3 and 4 empty)
 *     +0x50/+0x52  s16 s16   final-hook args (func_0205429C)
 *
 *   SubD (SubX+0x14)
 *     +0x00  u16 bitfield.  bits 9..10 hook selector, bit 11 second
 *            selector (func_02054718 BfHw)
 *     +0x10  u32 bitfield.  bit 6 a selector (BfSel.sel)
 *
 *   Node (a render-list element)
 *     +0x00  Node *next
 *     +0x2c  u8              the node's own texture-row index
 *                            (func_0205312C)
 * ------------------------------------------------------------------ */

/* The per-node scratch record, argument 2 of every handler row.
 * Evidenced identically by func_0205429C, func_02054718, func_02054A68. */
struct RigBf16 {                       /* the u16 at S+0x2e */
    u16 b0  : 5;                       /* tile count X */
    u16 b5  : 5;                       /* tile count Y, less one */
    u16 b10 : 6;                       /* attr byte for 0x040004A4 bits 24.. */
};

struct RigS {
    u8             pad00[0x08];
    struct VecFx32 p1;                 /* +0x08 position */
    struct VecFx32 p2;                 /* +0x14 direction (func_0205429C) */
    u16            f20;                /* vertex-table index, >> 4 */
    u8             pad22[0x0c];
    struct RigBf16 w;                  /* +0x2e */
    s32            f30;                /* base scale */
    s16            f34;                /* scale multiplier */
    u16            f36;                /* RGB555 colour */
    u32            f38, f3c, f40;      /* translation offset */
};

/* ------------------------------------------------------------------ *
 * The shared tables.  Declare them as externs pinned by address in the
 * source's `symbols:` block; the words are in the image at 020A7FDC..E8.
 * ------------------------------------------------------------------ */
extern const s16 Rig_Verts[];                              /* 0x020A1B38 */
extern u32 (*const Rig_Hooks [])(s32 sn, s32 cs, void *m); /* 0x020A7FE4 */
extern u32 (*const Rig_Hooks2[])(s32, s32, s32, s32);      /* 0x020A7FDC */

/* Rig_Hooks[0] = 0x02056420 (unlabelled leaf): the rotation about +Y,
 *   { cs, 0, -sn ; 0, 0x1000, 0 ; sn, 0, cs ; 0, 0, 0 }.
 * Rig_Hooks[1] = func_02056460: the rotation about the diagonal axis
 *   (1,1,1)/sqrt(3), with the two pooled constants 0x555 = 4096/3 (k*k)
 *   and 0x93D = 4096/sqrt(3) (k).  NOTE: both rows are declared u32 in the
 *   table type but func_02056460 actually returns VOID -- a `return 0`
 *   costs it four bytes.  A mixed-prototype table.
 * Rig_Hooks2[0] = func_020565C8, [1] = func_0205650C: the two textured-quad
 *   emitters, identical but for which VTX_10 field the second coordinate
 *   lands in (bits 10..19 for 020565C8, bits 20..29 for 0205650C).
 *   CORRECTED wave 8: both rows return VOID and are EXACT
 *   (src/matched/func_0205650C.c, func_020565C8.c).  The earlier "they DO
 *   return u32" was an artefact of the hand-inlined spelling; see shape 8.
 */

/* ------------------------------------------------------------------ *
 * External callees the cluster shares (all ARM, all `label`-attested).
 * ------------------------------------------------------------------ */
extern void func_0207B598(void *);                                  /* MTX_Identity43 */
extern u32  func_0207B5F4(void *m, s32 x, s32 y, s32 z);            /* MTX_Scale43, THUMB */
extern void func_0207B9F0(const void *a, const void *b, void *out); /* MTX_Concat43 */
extern s32  func_0207CA68(const void *a, const void *b);            /* VEC_DotProduct */
extern fx32 func_0207CAA4(const struct Vec16 *a, const struct Vec16 *b);
extern void func_0207CAE8(const void *a, const void *b, void *out); /* VEC_CrossProduct */
extern void func_0207CB68(const struct Vec16 *a, const struct Vec16 *b,
                          struct Vec16 *out);                       /* VEC_Fx16CrossProduct */
extern void func_0207CCA4(const void *v, void *out);                /* VEC_Normalize */
extern void func_0207CDB8(struct Vec16 *v, struct Vec16 *w);        /* VEC_Fx16Normalize; the
                                                                     * caller MUST pass the
                                                                     * vector TWICE even though
                                                                     * the callee ignores r1
                                                                     * (func_020576D0) */
extern void func_0207D8E0(const void *m);                           /* MTX push identity */
extern void func_0207D918(const void *m);                           /* MTX push */
extern s32  _s32_div_f(s32 a, s32 b);                               /* 0x0209C0A4, func_02057C9C */

/* ------------------------------------------------------------------ *
 * The dispatchers and the setup rows.
 * ------------------------------------------------------------------ */
extern void func_02053044(void *obj);   /* list A dispatch */
extern void func_0205312C(void *obj);   /* list B dispatch */
extern void func_02053D2C(void);        /* the do-nothing handler, four bytes */
extern void func_02053D30(void *texrow);/* set TEXIMAGE_PARAM/PLTT_BASE + tex matrix */
extern void func_02053A60(volatile void *inst, void *cfg, const struct VecFx32 *pos);

/* THE FIVE SOURCE SHAPES THIS CLUSTER'S EXACT ROWS ALL DEPEND ON.
 * Each was measured, and each is worth tens of bytes if got wrong.
 *
 *  1. 0x040004A4: the `|` chain order.  The b10 term FIRST:
 *       v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
 *     (func_02054718 header, shape 1.)
 *  2. The scale multiply is `(s64)a * res->f30`, `a` on the LEFT.
 *     (func_02054718, shape 2.)
 *  3. In the three-way scale switch, `case 0` runs the x assignment BEFORE
 *     the y assignment.  (func_02054718, shape 3.)
 *  4. The three 0x04000470 FIFO stores go through named locals loaded in
 *     REVERSE field order (`qc = p->f0c; q8 = p->f08; q4 = p->f04;`) and
 *     stored forward.  (func_02054718, shape 4.)
 *  5. A field re-read across a call to a same-file static needs `volatile`:
 *     func_0205312C reads the descriptor's first word TWICE and both reads
 *     must be spelled `*(volatile u32 *)&d->flags`.  The same lever, on a
 *     cached pointer rather than a field, is what takes func_02053A60 from
 *     17 concrete bytes out to 13 (`volatile struct Res0 *r`).
 *
 * TWO ALLOCATOR LEVERS, both measured this wave on func_02056460 and
 * func_02053A60 and both found by tools/permuter.py --mode anneal:
 *  6. A value used at three sites is written out at all three, NOT bound to
 *     one local, when the image keeps it in a parameter's own register.
 *     (func_02056460: `d + cos` at all three diagonal sites; a shared local
 *     puts it in lr where the image has r1, 8 bytes out.)
 *  7. Splitting a parameter's live range with a plain copy (`cs2 = cs;`)
 *     before a later group of uses is sometimes the only thing that moves a
 *     stuck residue.  (func_02056460.)
 */

/* ------------------------------------------------------------------ *
 * WAVE 8 ADDITIONS (second lane), each measured to EXACT.
 *
 *  8. THE GX REGISTER WRITES ARE SDK INLINE FUNCTIONS, NOT CASTS IN THE BODY.
 *     func_0205650C / func_020565C8 went from 40 / 50 concrete bytes of
 *     "pure register naming" to EXACT by writing the body as
 *       G3_Begin(1); G3_TexCoord(s, t); G3_Vtx10(x, y, z); G3_End();
 *     with each a static inline taking the SDK's parameter TYPES:
 *       G3_TexCoord(fx32 s, fx32 t)  = (u32)(u16)(s >> 8) | (u32)(u16)(t >> 8) << 16
 *       G3_Vtx10(fx16 x, fx16 y, fx16 z) = (x >> 6 & 0x3ff) | .. << 10 | .. << 20
 *     The fx16 parameter is where the `lsl #16 / asr #22` narrowing comes
 *     from; passing the value through a typed parameter changes the
 *     allocator's value order, which no respelling of the hand-inlined body
 *     reproduced.  (Tried on func_02053D30 as G3_TexImageParam /
 *     G3_TexPlttBase / G3_Scale: no gain there, 43 vs the note's 41.)
 *
 *  9. The emitter/particle rows (func_02056684) are an SPL-style particle
 *     system.  Particle (the list node the free-list pop func_02058380
 *     returns): +0x08 VecFx32 pos, +0x14 VecFx32 vel, +0x20 u16, +0x22 s16,
 *     +0x24 u16 life, +0x26 u16 age, +0x28/+0x2a u16 0xFFFF/(life>>1) and
 *     0xFFFF/life, +0x2c u8, +0x2d u8, +0x2e RigBf16, +0x30 fx32 scale,
 *     +0x34 u16 0x1000, +0x36 u16 colour, +0x38 VecFx32 -- the same layout
 *     struct RigS above describes, so RigS IS the particle.  The RNG is the
 *     LCG g_02146A8C = g * 0x5EEDF715 + 0x1B0CB173, and in func_02056684 the
 *     random term must be a MACRO whose update is an assignment used as a
 *     value: ((v) * (s32)((g = g * A + C) >> 23) - ((v) << 8)) >> 8.  As an
 *     inline function it is 8 bytes short and 534 out.
 *
 * 10. Declaration order of two pointer locals decides r6/r7: in
 *     func_02056684 `struct Ptcl *p;` must be declared BEFORE `d`; the
 *     permuter's hill pass could not move it (222 singles).
 *
 * 11. MTX_Concat43 operand order is per row: func_02053E1C (otherwise a
 *     transcription of func_0205429C) concatenates (m2, m3, m1) where
 *     func_0205429C has (m3, m2, m1) -- the only 2 bytes it had wrong.
 *
 * 12. The billboard rows that build their own 4x3 matrix fill it in
 *     DIFFERENT element orders: func_02055B80 row-major m[0..11];
 *     func_02054DB8 column-wise _00,_10,_01,_11,_20,_21,_02,_12,_22 then the
 *     translation.  The store order in the image is the source order (the
 *     scheduler only hoists the constant and translation stores), and it was
 *     worth 118 bytes on func_02054DB8 (442 -> 324).
 * ------------------------------------------------------------------ */

#endif /* CLUSTER_02052F58_H */
