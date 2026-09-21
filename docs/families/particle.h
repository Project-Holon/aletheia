/*
 * docs/families/particle.h -- shared declarations for the particle.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * Family: original source file **particle.c**, 0x02050B80..0x02051B0C in the
 * ARM9 image (edges fuzzy by a function or two; 0x02051B84 onward is already a
 * different object).  The file name comes from the __FILE__ pool word
 * 0x020A7FC0 that the family's two allocations carry
 * (src/matched/func_02050B80.c line 190, func_02050C30 line 285, the note in
 * docs/notes/pkt_02050C30.c.txt); the line numbers are monotone in address,
 * the usual second check that this is one translation unit.
 *
 * Derived from the 28 matched sources found with
 *   grep -l "address:  0x02050[B-F]\|address:  0x02051[0-9A-B]" src/matched/*.c
 * and from the six DIFF write-ups in docs/notes/ that cover the open residues
 * (pkt_02050C30, func_02050DB8, pkt_02051394, pkt_02051414, func_02051648,
 * pkt_02051838).
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  A plain `ldr` followed by an `lsl #16`/`lsr #16`
 * pair proves the FIELD (or the parameter) is 32-bit and the narrowing happens
 * at the USE -- an `ldrh` is what a u16 would produce, and it is cheaper.  This
 * exact tell is recorded twice in this family, in docs/notes/pkt_02050C30.c.txt
 * (declaring func_02052DC8's last three parameters u16 costs 24 bytes) and in
 * docs/notes/func_02051648.c.txt (a6 as u16 emits `ldrh`, 2 bytes short).
 * `ldrh; lsl #31; lsrs #31` proves a 1-bit BITFIELD, not a mask (a mask folds
 * to `ands`) -- docs/notes/func_02050DB8.c.txt on the +0x32 flags halfword.
 */

#ifndef PARTICLE_H
#define PARTICLE_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * 1.  The globals
 * ------------------------------------------------------------------ */

/* The module singleton: a POINTER VARIABLE at 0x02146A88, not an array.
 * Every use re-dereferences it, because a store through the pointer could
 * overwrite the pointer itself (evidence: func_02050B80's four separate
 * `ldr` of the global, func_02050ED4's `ldr r0, [r4]` at the top of the
 * loop).  0x02146A88 is the strongest-attested word in the family
 * (`literal x40..x50`).
 *
 *   symbols:  g_02146A88  0x02146A88  data
 *
 * Spelled `struct Ctx *` in func_02050B80/func_02051A54/func_02051AB8,
 * `u32 *` in func_02050ED4/func_02051504/func_02051534/func_02051574,
 * `int *` in func_020515CC: four spellings of one object.  The u32*/int*
 * spellings are the SLOT TABLE view -- slots 0..15 are the sixteen emitter
 * pointers, and `g_02146A88[0x10]` (func_020515CC) is the +0x40 word.
 */
extern struct ParticleCtx *g_02146A88;

/* The __FILE__ string, an ABS32 into the packed string area; never written
 * `__FILE__`.  See docs/idioms/file-string-is-an-abs32-into-the-string-area.md.
 *   symbols:  sParticleFile  0x020A7FC0  data
 * Spelled `pkt_02050A70_File` in src/matched/func_02050B80.c.
 */
extern const char sParticleFile[];          /* 0x020A7FC0 -- "particle.c" */

/* Three three-word default blocks, copied wholesale into a fresh emitter at
 * +0x34, +0x40 and +0x4C by func_02050C30, and used as the defaulted
 * pointer arguments 9/10/11 of func_02048A24 by func_02051648.  They are
 * STRUCT ASSIGNMENTS of a three-word type, not nine field stores: written
 * field by field the compiler emits nine ldr/str pairs off three separate
 * pool bases (docs/notes/pkt_02050C30.c.txt; the
 * aggregate-assignment-is-ldm-stm idiom).
 *   symbols:  g_020A1590 / g_020A1584 / g_020A1578  data
 */
typedef struct { u32 x, y, z; } VecFx32;

extern VecFx32 g_020A1590;                  /* 0x020A1590 */
extern VecFx32 g_020A1584;                  /* 0x020A1584 */
extern VecFx32 g_020A1578;                  /* 0x020A1578 */

/* 0x020A15A8: a sixteen-entry u32 ARRAY indexed by the slot number, whose
 * element is func_02052DC8's first argument.  An ARRAY, not a pointer
 * variable: the image does `ldr r3, [pc, ...]` then `ldr r0, [r3, r4, lsl #2]`,
 * ONE indirection (func_02050C30).  Contrast g_02146A88, which IS a pointer
 * variable and needs its own `ldr`.  0x020A159C: the model vector func_02051414 copies;
 * exactly ONE pool word image-wide, inside func_02051414 itself, so it is a
 * permanent MATCH blocker for that function (docs/notes/pkt_02051414.c.txt).
 */
extern VecFx32 g_020A159C;                  /* 0x020A159C -- MATCH blocker */
extern u32     g_020A15A8[];                /* 0x020A15A8 -- per-slot arg   */

/* The two registered emit handlers, function POINTERS (an indirect `blx`,
 * two arguments forwarded and a literal 0 in r2).  Owned by clact.c.
 *   symbols:  g_020A8140 / g_020A8148  data
 */
extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);   /* 0x020A8140 */
extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);   /* 0x020A8148 */

/* 3D scratch areas the setup half writes (func_02051414). */
extern u32 g_02148B4C[];                    /* word 63 has bits 0xa4 cleared */
extern u32 g_02148B98[];
extern u32 g_02148C08[];                    /* MI_Copy36B destination        */

/* ------------------------------------------------------------------ *
 * 2.  struct ParticleCtx -- the module singleton, 0x48 bytes
 *     Evidence: func_02050B80 allocates 0x48 and zeroes words 0..15 then
 *     +0x40 and +0x44 separately; func_020515CC writes index 0x10 (= +0x40);
 *     func_02051A54 / func_02051AB8 read +0x44 as the CURRENT emitter.
 * ------------------------------------------------------------------ */
struct ParticleCtx {
    struct ParticleEmitter *slots[16];      /* 0x00 -- sixteen emitter slots */
    u32                     f40;            /* 0x40 -- func_020515CC's [0x10] */
    struct ParticleEmitter *cur;            /* 0x44 -- current emitter        */
};                                          /* 0x48 */

/* ------------------------------------------------------------------ *
 * 3.  struct ParticleEmitter -- the per-slot object, 0x260 bytes
 *     Size from func_02050C30's allocation (0x260 through func_02030734,
 *     particle.c line 285).  Offsets below are each carried by a load or a
 *     store in a matched source or a note; the function that evidences each
 *     is named.
 * ------------------------------------------------------------------ */
struct ParticleEmitter {
    u32  f00;               /* 0x00  func_02052DC8's result (func_02050C30);
                               the value handed to func_02052A50 and to
                               func_020526A8 (func_02051230, func_02051414) */
    u32  f04;               /* 0x04  func_02051230 stores a1 here           */
    u8   pad_08[0x04];
    u32  f0c;               /* 0x0C  span fields, wired by func_02050C30    */
    u32  f10;               /* 0x10   */
    u32  f14;               /* 0x14   */
    u8   pad_18[0x08];
    u32  f18;               /* 0x18  handler word: func_02051A3C or
                               func_02051A54 (func_02051230); func_02051394
                               routes on it being null                      */
    u32  f1c;               /* 0x1C  ditto: func_02051AA0 / func_02051AB8   */
    struct ParticleBlk *f20;/* 0x20  the private 3D block: func_02048A24's
                               result (func_02051648), released by
                               func_02051758, walked by func_020518AC and
                               func_02051838, gates func_02051414           */
    u32  f24;               /* 0x24  zeroed by func_02051648                */
    u32  f28;               /* 0x28  three-word vector rebuilt by           */
    u32  f2c;               /* 0x2C  func_02051838 from q[0..2] plus the    */
    u32  f30;               /* 0x30  inner block; f30 also takes the id a2  */
    u16  flags;             /* 0x32  1-BIT BITFIELD at bit 0: cleared by
                               func_02050C30, set by func_02051360, tested
                               by func_02050DB8 as `ldrh; lsl #31; lsrs #31`
                               -- a mask would fold to `ands`               */
    VecFx32 f34;            /* 0x34  the three default blocks copied in by  */
    VecFx32 f40;            /* 0x40  func_02050C30 as STRUCT ASSIGNMENTS    */
    VecFx32 f4c;            /* 0x4C   */
    u16  x, y, z;           /* 0x50/0x52/0x54  func_02051880's 16-bit vector;
                               field-by-field, NOT a struct assignment (the
                               three loads precede the three stores)        */
    u8   pad_56[0x02];
    u32  tableA[0x40];      /* 0x58  func_02051230 zeroes 0x40 words with a
                               SIGNED int counter (`blt`, not `blo`);
                               func_02051A54 appends at +0x58 + n*4         */
    u32  tableB[0x40];      /* 0x158 the parallel table, func_02051AB8      */
    u8   pad_258[0x01];     /* 0x258 func_02051230 stores the flag byte     */
    /* 0x25A  slot index byte, written by func_02050C30                     */
    /* 0x25B  id byte, `strb` of the WORD field src->f00 cast to u8, never
              an `ldrb` at the source (func_02051648)                       */
    /* 0x25C  u16 count for tableA (func_02051A54, pre-increment indexed)   */
    /* 0x25E  u16 count for tableB (func_02051AB8)                          */
    u32  f6c_alias;         /* see func_0205189C / func_020518A4 below      */
};                          /* 0x260 */

/* func_0205189C stores a u32 at +0x6C and func_020518A4 a u16 at +0x70 on
 * the SAME object as func_020518AC, i.e. on the block at +0x20, not on the
 * emitter; the two setters were filed against a local `struct Obj` with a
 * char pad and carry no other constraint. */

/* ------------------------------------------------------------------ *
 * 4.  struct ParticleBlk -- the block at emitter+0x20 (func_02048A24's)
 *     Evidence: func_020518AC reads a pointer at +0x18 and a u16 count at
 *     +0x1C; func_02051838 reads the inner pointer at +0x00 and sums its
 *     words +4/+8/+0xC.
 * ------------------------------------------------------------------ */
struct ParticleEnt {
    void *fn;                               /* +0 the handler address       */
    void *data;                             /* +4 the payload               */
};

struct ParticleBlk {
    VecFx32 *inner;         /* 0x00  RE-READ per statement in func_02051838:
                               a store through the emitter may alias it, the
                               mirror of const-pointer-lets-a-field-load-
                               survive-a-store.md                           */
    u8   pad_04[0x14];
    struct ParticleEnt *ents;   /* 0x18 */
    u16  count;                 /* 0x1C */
    /* 0x6C u32, 0x70 u16 -- func_0205189C / func_020518A4 setters          */
};

/* ------------------------------------------------------------------ *
 * 5.  Prototypes -- exact parameter types as the matched sources carry
 *     them.  Where a note settled a signedness or a width, the note is
 *     named beside the line.
 * ------------------------------------------------------------------ */

/* Module lifecycle */
extern void  func_02050B14(u32 idx);            /* EXACT, engine cfg repack  */
extern void  func_02050B80(u32 heap);           /* EXACT, ctor of the ctx    */
extern void  func_02050BE8(void);               /* EXACT                     */
extern int   func_02050C04(int a, int b, int c, int d);   /* EXACT, forwards */
extern void  func_02050ED4(void);               /* EXACT, ctx teardown       */

/* Emitter lifecycle.  func_02050C30's LAST THREE parameters are u32 truncated
 * with (u16) casts at the use, NOT u16 parameters (docs/notes/pkt_02050C30). */
extern void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                           u32 heap);          /* OPEN, size EXACT at 392,
                                                   37 bytes out, permuter
                                                   exhausted (3000 anneal)   */
extern void  func_02050DB8(u8 *p);              /* EXACT (wave 4)            */
extern void  func_02051648(struct ParticleEmitter *this,
                           struct ParticleSrc *src, u16 a2,
                           int *a3, int *a4, int *a5, u32 a6);
                                                /* EXACT (wave 4)            */

/* Per-frame passes over the sixteen slots */
extern int   func_02051504(void);               /* EXACT, count live slots   */
extern int   func_02051534(void);               /* EXACT, start pass         */
extern int   func_02051574(void);               /* EXACT, stop pass          */
extern int   func_020514F4(u32 *p);             /* EXACT, 16-byte leaf       */
extern void  func_020515B4(void *p);            /* EXACT                     */
extern int   func_020515CC(int *p, int a, int b, int c);  /* EXACT*          */

extern void  func_02051230(u8 *o, u32 a1, u32 a2, u32 a3);  /* EXACT         */
extern void  func_02051360(void *p);            /* EXACT, sets flags bit 0   */
extern void  func_020513F8(void *p, int a);     /* EXACT                     */
extern void  func_02051394(u32 *p);             /* EXACT (wave 4)            */
extern void  func_02051414(u8 *a0);             /* OPEN, permanent MATCH:
                                                   g_020A159C has no witness
                                                   outside the range (its only
                                                   pool word is inside it);
                                                   func_020526A8 NO LONGER a
                                                   blocker, sole-ref/code     */

/* Geometry / vector setters on the block */
extern void  func_02051838(char *p, volatile u32 *q);
                                                /* OPEN, size EXACT at 72,
                                                   10 bytes out, two swapped
                                                   register pairs, permuter
                                                   exhausted (3000 anneal)   */
extern void  func_02051880(struct ParticleEmitter *o, const VecFx32_16 *v);
extern void  func_0205189C(void *o, u32 v);     /* EXACT, +0x6C              */
extern void  func_020518A4(void *o, u16 v);     /* EXACT, +0x70              */
extern void *func_020518AC(void *obj, int kind);/* EXACT, slot lookup by
                                                   handler address           */
extern void  func_020519C4(void *p, void *q);   /* EXACT, class 2, 12 B copy */
extern void  func_020519E4(void *p, u16 *q);    /* EXACT, class 3, u16 at +2 */
extern void  func_02051A04(void *p, void *q);   /* EXACT, class 5, 12 B copy */

/* Emit handlers, all four the same shape: call out, append to a table, return
 * the low halfword scaled by eight as the fused unequal shift pair
 * lsl #16 / lsr #13 (unequal-shift-pair-is-a-narrowing-cast-folded-with-a-
 * shift.md). */
extern u32   func_02051A3C(int a0, int a1, int a2, int a3);   /* EXACT       */
extern u32   func_02051A54(u32 a, u32 b);                     /* EXACT       */
extern int   func_02051AA0(int a, int b);                     /* EXACT       */
extern u32   func_02051AB8(u32 a, u32 b);                     /* EXACT       */

extern int   func_02051B0C(int i);              /* EXACT, 8-way dispatch, no
                                                   default: label at all     */
extern void  func_02051758(int a0, int a1, int a2, int a3);   /* EXACT       */

/* ------------------------------------------------------------------ *
 * 6.  Externals outside the family that the family depends on
 * ------------------------------------------------------------------ */
extern void *func_02030734(u32 heap, u32 size, u32 align,
                           const char *file, u32 line);  /* 0x02030734 alloc */
extern void  func_020307B0(void *p);                     /* 0x020307B0 free  */
extern void  func_02030DA8(u32 a, u32 b, u8 *c, u32 d);  /* 0x02030DA8       */
extern void  func_02030EAC(void *p);                     /* 0x02030EAC       */
extern void *func_02048A24(/* twelve arguments; see func_02051648 */);
extern void  MI_CpuFill8(void *dst, u8 v, u32 n);        /* SDK              */

#endif /* PARTICLE_H */
