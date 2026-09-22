/*
 * docs/families/cluster_020637F4.h -- shared declarations for the pseudo-family
 * at 0x020637F4..0x020640B0 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit; it was formed by address adjacency plus shared callees and data
 * objects.  It is nevertheless one subsystem with no seam in it: a VRAM
 * RESOURCE UPLOADER.  Every non-accessor member does the same four things in
 * the same order --
 *
 *   1. optionally repoint one of the two VRAM bank-control words
 *      (0x04000000 for the main engine, 0x04001000 for the sub engine) by
 *      masking out 0xFFCFFFEF and OR-ing in the resource's own control word;
 *   2. DC_FlushRange the source range, because the GX loaders read through
 *      the bus and not the cache;
 *   3. hand the range to the matching GX loader, chosen by the same `mode`
 *      value the bank write was chosen by -- 0 = 3D texture
 *      (GX_BeginLoadTex / GX_LoadTex / GX_EndLoadTex), 1 = main-engine OBJ
 *      (GX_LoadOBJ), 2 = sub-engine OBJ (GXS_LoadOBJ);
 *   4. fill the caller's out-descriptor and tail into func_020637AC or
 *      func_020637F4.
 *
 * The three accessors at the head of the range (func_020637F4, func_02063800,
 * func_0206380C) are the slot getters/setters for the descriptor those
 * functions fill: a word array at descriptor + 8, indexed by `mode`, whose
 * empty value is the sentinel -1.
 *
 * Derived from the seven matched sources found with
 *   grep -l "address:  0x020637\|address:  0x020638\|address:  0x02063[A-F]" src/matched/*.c
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing happens
 * at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * SIX of this cluster's eight functions are byte-exact only under
 * `--cc ../2.0/sp2` and are DIFF (and short) under the project default
 * dsi/1.1p1:
 *
 *   func_0206380C  func_02063828  func_02063A54  func_02063C80  func_02063F4C
 *
 * The two that are NOT are func_020637F4 and func_02063800, both one-line
 * accessors with no repeated constant in them at all, plus func_02063E54
 * which is 1.1p1 (measured; its shard entry says so).  So this is a cluster
 * where the pin must be read off the residue and never assumed from the
 * neighbour -- both front ends own rows here.
 *
 * The tell for the 2.0 rows is
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md and
 * the "kept constants" row of docs/FRONTEND-PINS.md: every function here has
 * a shared zero (the `case 0:` of two switches on the same `mode`, and the
 * default of the size-code translation), and 1.1p1 CSEs it into a
 * callee-saved register, costing an extra pushed register, and then
 * cross-jumps the two VRAM-control arms.  It comes out 24 bytes SHORT every
 * time: 532 against 556 for func_02063828, 444 against 468 for func_02063C80.
 *
 * SYMPTOM TO RECOGNISE INSTANTLY: a compile 24 bytes short of the image whose
 * frame is one register wider.  Change the compiler, not the source.
 *
 * func_02063F4C is the exception worth knowing, because it looks nothing like
 * the above: with the body fully correct, 1.1p1 is SIZE-EXACT at 356 bytes
 * with exactly ONE concrete byte out, and the permuter cannot move it
 * (`--explain` reports no register substitution, hill exhausts 271 singles,
 * anneal plateaus at 2000 compiles).  The byte is a predicate: the image
 * writes the element-size selection as `moveq r8, #0x20` / `movne r8, #0x200`,
 * two predicated arms, and 1.1p1 drops the first predicate because the
 * variable is provably dead beforehand.  No C spelling restores it -- not the
 * ternary, not the spelled-out if/else, not initialise-then-override.  ONE
 * unmovable predicated byte is as much a front-end tell in this cluster as a
 * 24-byte frame is.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_020637F4_H
#define CLUSTER_020637F4_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Hardware
 *
 * The two VRAM bank-control words, reached as cast constants and not as
 * relocations -- see docs/idioms/volatile-reread-needs-two-locals.md for why
 * these are `*(volatile u32 *)` and never externs.  The mask 0xFFCFFFEF is
 * what func_02063828 / func_02063A54 / func_02063C80 all clear before OR-ing
 * the resource's own control word in.
 * ================================================================== */
#define VRAMCNT_MAIN  (*(volatile u32 *)0x04000000)
#define VRAMCNT_SUB   (*(volatile u32 *)0x04001000)
#define VRAMCNT_MASK  0xFFCFFFEF

/* ================================================================== *
 * 1.  struct Res -- the VRAM resource descriptor
 *
 * Field evidence, one function per line:
 *   +0x00, +0x02  two HALFWORD dimensions (`ldrh`).  When f8 == 0 each is
 *                 translated from a pixel size (1, 2, 4, 8, 0x10, 0x20) to a
 *                 GX size code 0..5 by a switch with an explicit default of 0;
 *                 when f8 != 0 both are stored raw.  The dense-from-1 switch
 *                 is a compare chain and not a table because the cases are
 *                 powers of two, not consecutive.
 *   +0x04         copied to the out-descriptor untouched.
 *   +0x08         the VRAM BANK CONTROL WORD.  Zero has two meanings at once
 *                 and both are used: "do not repoint a bank" and "the
 *                 dimensions are pixel sizes that need translating".
 *   +0x0c         copied out untouched.
 *   +0x10         the byte LENGTH of the source range, handed to
 *                 DC_FlushRange and to the GX loader as its third argument.
 *   +0x14         the SOURCE POINTER, first argument of both.
 * ================================================================== */
struct Res {
    u16   f0_w;                 /* 0x00  dimension / GX size code            */
    u16   f2_h;                 /* 0x02  dimension / GX size code            */
    int   f4;                   /* 0x04                                      */
    u32   f8_bank;              /* 0x08  VRAM bank control word, 0 = none    */
    int   fc;                   /* 0x0c                                      */
    u32   f10_len;              /* 0x10  byte length                         */
    void *f14_src;              /* 0x14  source pointer                      */
};

/* The out-descriptor every uploader fills.  Its +0x08 word array is what the
   three accessors at the head of the cluster index, so the `int f8` below and
   `*(int *)(p + i * 4 + 8)` are the same storage seen two ways -- the
   accessors are byte-exact spelled as raw pointer arithmetic on a `char *`,
   which is how they are filed. */
struct Out {
    int f0, f4, f8;
    int fc;                     /* 0x0c  GX size code for f0_w               */
    int f10;                    /* 0x10  GX size code for f2_h               */
    int f14;
    int f18;
    int f1c;
    u32 f20;
};

/* The smaller descriptor pair func_02063E54 and func_02063F4C fill before
   their tail call; only two words of it are written, so it is recorded as its
   own view rather than merged with struct Out above. */
struct Out2 {
    u32 f0;
    u32 f4;
};

/* The object func_02063E54 and func_02063F4C are called ON.  f0 is a format
   code (compared against 3 to pick the element size, then copied out), f4 is
   an optional handle whose non-zero value selects the "wrapped" upload path,
   f8 and fC are the flush range handed to DC_FlushRange. */
struct Self {
    u32 f0_fmt;                 /* 0x00  format code; == 3 selects step 0x20 */
    u32 f4_handle;              /* 0x04  0 = use the plain loader            */
    u32 f8_len;                 /* 0x08  DC_FlushRange length                */
    u32 fC_addr;                /* 0x0c  DC_FlushRange address, and the base
                                         of the per-entry destination        */
};

/* func_02063F4C's second argument: a count and a u16 index array.  The count
   is read once with `ldrh r0, [r0]` and spilled; the array is re-read from
   +0x04 on every iteration (`ldr r1, [r0, #4]` inside the loop), which is why
   the pointer is NOT kept in a register. */
struct IdxList {
    u16  count;                 /* 0x00                                      */
    u16 *items;                 /* 0x04                                      */
};

/* ================================================================== *
 * 2.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the SDK layer, named (these are real SDK entry points) -------------- */
extern void DC_FlushRange(void *p, u32 n);          /* 0x020862F0            */
extern void GX_BeginLoadTex(void);                  /* 0x0207F7A0            */
extern void GX_LoadTex(void *src, u32 off, u32 n);  /* 0x0207F7FC            */
extern void GX_EndLoadTex(void);                    /* 0x0207F9B4            */
extern void GX_LoadOBJ(void *src, u32 off, u32 n);  /* 0x0207E780            */
extern void GXS_LoadOBJ(void *src, u32 off, u32 n); /* 0x0207E804            */

/* The second family of loaders, used by func_02063E54 / func_02063F4C.  The
   begin/load/end triples are the same GX shape as above at three other slot
   kinds; the two bare loaders are the unwrapped forms taken when
   Self.f4_handle is zero. */
extern void func_0207F47C(u32 handle);              /* begin, kind 1         */
extern void func_0207F4C4(u32 dst, u32 src, u32 n); /* load,  kind 1         */
extern void func_0207F560(void);                    /* end,   kind 1         */
extern void func_0207E51C(u32 dst, u32 src, u32 n); /* plain, kind 1         */
extern void func_0207F6A8(u32 handle);              /* begin, kind 2         */
extern void func_0207F6C0(u32 dst, u32 src, u32 n); /* load,  kind 2         */
extern void func_0207F754(void);                    /* end,   kind 2         */
extern void func_0207E5D0(u32 dst, u32 src, u32 n); /* plain, kind 2         */
extern void func_0207FA0C(void);                    /* begin, kind 0         */
extern void func_0207FA40(u32 dst, u32 src, u32 n); /* load,  kind 0         */
extern void func_0207FADC(void);                    /* end,   kind 0         */

/* --- this cluster's own -------------------------------------------------- */
extern void func_020637AC(struct Out *out, int mode, u32 dst);
extern void func_020637F4(char *p, int i, int v);   /* p[i] = v, base +8     */
extern int  func_02063800(char *p, int i);          /* return p[i], base +8  */
extern int  func_0206380C(char *p, int i);          /* p[i] != -1            */
extern void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063E54(struct Self *self, u32 base, int sel,
                          struct Out2 *out);        /* one entry             */
extern void func_02063F4C(struct Self *self, struct IdxList *list, u32 base,
                          int sel, struct Out2 *out);   /* a list of them    */

/* ================================================================== *
 * 3.  Constants
 * ================================================================== */
#define RES_SLOT_BASE     8     /* the accessors' +8 displacement            */
#define RES_SLOT_EMPTY    (-1)  /* func_0206380C's sentinel                  */
#define RES_STEP_SMALL    0x20  /* func_02063F4C, when Self.f0_fmt == 3      */
#define RES_STEP_LARGE    0x200 /* func_02063F4C, otherwise                  */

/* The pixel-size to GX-size-code translation both uploader families carry.
   Written as a switch with an explicit `default: 0`, which is what makes the
   compare chain exist; a table lookup or a count-trailing-zeros spelling is a
   whole-function diff. */
#define RES_SIZECODE_CASES  /* 1->0  2->1  4->2  8->3  0x10->4  0x20->5 */

#endif /* CLUSTER_020637F4_H */
