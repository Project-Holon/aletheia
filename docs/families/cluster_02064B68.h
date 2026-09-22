/*
 * docs/families/cluster_02064B68.h -- shared declarations for the
 * pseudo-family cluster_02064B68 (0x02064B68..0x02066620 in the ARM9 image).
 *
 * PSEUDO-FAMILY.  The upper half of the ARM9 image carries no __FILE__
 * anchors, so this cluster was formed by address adjacency plus shared
 * callees and data objects, NOT by a string anchor.  Three objects hold it
 * together and are the whole basis of the grouping:
 *
 *   g_02147B88  the "manager": a control block whose first four words are
 *               { u16 slotCount, u16 slotLimit }, an enable/mode word at
 *               +0x04, the live object pointer at +0x08 and the current
 *               matrix-slot index at +0x0c.  Read by almost every function
 *               in the range; the ABS32 to it appears in 100 literal pools
 *               image-wide.
 *   g_02147D18 / g_02147D28 / g_02147D2C / g_02148018
 *               four parallel 0x18-stride matrix tables indexed by the
 *               manager's +0x0c slot.  func_02064E3C builds one entry of
 *               them and is the evidencing function for the stride and the
 *               six-word MtxFx23 payload.
 *   the 0x5c / 0x28 stride pair
 *               the multi-cell bank's two record layouts.  Every walker in
 *               the range (sub_02064B68, func_02064C10, func_02064CBC,
 *               func_02064D70) branches on a kind word and picks one.
 *
 * WHAT THE SUBSYSTEM IS.  A 2D CELL-ACTOR / SPRITE ANIMATION MANAGER with an
 * attached affine-matrix stack, sitting one layer above the OAM/G2D composer
 * of docs/families/cluster_02066740.h and one layer below the clact.c public
 * API (src/pending/func_0204CB44.c, func_0204CC6C.c and the chain behind
 * them, whose relocations this cluster's EXACT entries witness).  Three
 * cooperating parts:
 *
 *   PART 1, 0x02064B68..0x02064E3C -- the BANK WALKERS.  Each takes the
 *     actor object, branches on its kind word, and sweeps every record of
 *     the multi-cell bank calling one per-record worker from the
 *     src/matched/unit_020640B0.c / 0x020643xx family.  Kind 1 is the
 *     0x5c-stride node array whose count is the header's halfword at +2;
 *     anything else is the 0x28-stride cell array whose count is the
 *     header's halfword at +0 and whose record pointer is its word 0.
 *     sub_02064B68 advances with an argument, func_02064C10 single-steps,
 *     func_02064CBC resets, func_02064D70 walks name records.
 *
 *   PART 2, 0x02064EDC..0x020653A4 -- the VTABLE DISPATCHERS.  The manager's
 *     live object carries a jump table at +0x74 whose slots +0x34, +0x38,
 *     +0x3c and +0x44 are callbacks.  Each dispatcher loads its slot, returns
 *     at once if it is null, selects the affine matrix to hand the callback
 *     (the manager's own slot of g_02147D18 when g_02147B88.f04 is zero, or
 *     the scratch matrix at g_020A8200 after refreshing its +0x18/+0x1c words
 *     from g_02147D28 / g_02147D2C at the same 0x18 stride), and tail-calls
 *     through `blx`.  The predicated `mlaeq rD, rIdx, #0x18, rBase` that
 *     computes &g_02147D18[i] in the selected arm is this part's signature
 *     instruction and appears in all four.
 *
 *   PART 3, 0x02065438..0x02066620 -- the DRAW AND RESET PATH.
 *     func_02065AA8 / func_02065BD0 reset the module and its 0x20-stride
 *     slot table at g_02148318; func_02065B74 builds one 0x48-byte actor
 *     with its four-entry in-object vtable; func_02065C78 tears the actor
 *     down; func_02065CE4 and func_02065D4C are byte-twins that bracket a
 *     draw in a secondary-render-surface save/restore; func_020659D4 and
 *     func_02066080 apply a command record's translate / rotate / scale
 *     flags; func_020663D0 / func_020664CC / func_02066620 are the three
 *     matrix builders and func_0206615C / func_02066380 the push and pop of
 *     the matrix slot stack.
 *
 * COMPILER PIN.  This cluster is NOT uniformly dsi/1.1p1.  Five of the ten
 * byte-exact sources in the range carry `compiler: ../2.0/sp2`
 * (func_02064CBC, func_02065AA8, func_02065B74, func_02065CE4,
 * func_02065D4C), and every one of them was pinned on the SAME tell, the
 * "kept constants" row of docs/FRONTEND-PINS.md:
 *
 *   THE RECOGNITION RULE FOR THIS CLUSTER.  If the image re-materialises a
 *   value inside a loop body or at every use -- a stride into a fresh
 *   register (`mov r7, #0x5c`), a small constant between two stores
 *   (`mov r0, #1` / `str` / `mov r0, #3` / `str`), or the SAME pool word
 *   loaded twice in one function (`ldr r1, [pc, ...]` then `ldr r0, [pc,
 *   ...]` naming one address) -- and dsi/1.1p1 -O4,p instead hoists that
 *   value into a callee-saved register and comes out SHORT with a WIDER
 *   push, the front end is ../2.0/sp2, not the C.  The push width is the
 *   fastest check: 1.1p1 buying one extra callee-saved register per hoisted
 *   value is exactly what makes `push {r3, r4, r5, lr}` become
 *   `push {r4, r5, r6, lr}` (func_02065CE4, 4 bytes short) and
 *   `push {r4, lr}` stay put while the body loses 12 bytes (func_02064CBC).
 *   Try the pin BEFORE spending a spelling sweep on such a residue: three of
 *   this wave's exact results came out EXACT on the first compile under the
 *   pin against 31..135 concrete bytes out under 1.1p1.
 *
 *   The pin is NOT universal here.  func_02064C10, func_02064E3C,
 *   func_020659D4, func_02065B64 and func_02065C78 are all EXACT under plain
 *   dsi/1.1p1, and the pin was probed and made things WORSE on
 *   sub_02064B68 (15 -> 16 concrete out), func_02065BD0 (75 -> 84) and
 *   func_02066380 (per docs/notes/pkt_02065D4C.c.txt).  Probe, do not assume.
 *
 *   A second lever travels with the pin: 2.0 will still CSE two reads of one
 *   extern's address unless the source casts each read through `volatile`.
 *   func_02065D4C and func_02065CE4 both spell every read of g_02147B88 as
 *   `((volatile Ctx *)&g_02147B88)->f8`, and that is what reproduces the
 *   image's two separate `ldr rN, [pc, ...]` materialisations.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration is
 * derived from an EXACT/EXACT* file in src/matched, and the evidencing
 * function is named in the comment beside it.  Where the matched sources
 * disagree on a spelling (different lanes wrote them), the spelling kept
 * here is the one the byte evidence constrains.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef CLUSTER_02064B68_H
#define CLUSTER_02064B68_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;
typedef int            fx32;          /* 1.19.12 fixed point; 0x1000 == 1.0 */

/* ================================================================== *
 * The manager block at 0x02147B88
 * ================================================================== *
 *
 * Every field below is constrained by at least one EXACT source.  The
 * matched files model it three different ways (a byte array in
 * func_02065AA8, a three-word struct in func_02065C78, an 8-byte pad plus
 * one pointer in func_02065D4C); the union of them is:
 */

struct Actor;                         /* the 0x48-byte cell actor, below */

struct Manager {
    u16            slotCount;         /* +0x00  func_02065AA8 (strh 0)     */
    u16            slotLimit;         /* +0x02  func_02065AA8 (strh 0)     */
    u32            unk_04;            /* +0x04  mode flag; 0 selects the
                                       *        g_02147D18 arm in every
                                       *        dispatcher of PART 2, and
                                       *        func_02064E3C branches on it */
    struct Actor  *obj;               /* +0x08  func_02065C78, func_02065D4C */
    u32            slot;              /* +0x0c  the current 0x18-stride
                                       *        matrix index; func_02064E3C  */
};

extern struct Manager g_02147B88;

/*
 * The matrix tables, all indexed by g_02147B88.slot at a 0x18 stride.
 * func_02064E3C is the evidencing function for the payload: the six words
 * (0x1000, 0, 0, 0x1000, 0, 0) it writes into g_02147D18[i] and then copies
 * whole into g_02148018[i] are the 24-byte aggregate assignment its ldm/stm
 * pair reproduces.  g_02147D28 and g_02147D2C are the +0x00 words of two
 * further 0x18-stride tables (func_02064E3C clears them, and every PART 2
 * dispatcher reads them into the scratch matrix's +0x18 / +0x1c).
 */

struct MtxFx23 {                      /* func_02064E3C */
    fx32 m00, m01, m10, m11, tx, ty;
};

extern struct MtxFx23 g_02147D18[];   /* func_02064E3C, PART 2 dispatchers  */
extern u8             g_02147D28[];   /* func_02064E3C, PART 2 (0x18 stride)*/
extern u8             g_02147D2C[];   /* func_02064E3C, PART 2 (0x18 stride)*/
extern u32            g_02147B98[];   /* func_02064E3C (u32 per slot)       */
extern struct MtxFx23 g_02148018[];   /* func_02064E3C                      */

extern u8  g_02147C18[];              /* func_02065AA8: a 0x100-byte block
                                       * cleared at reset; 8-byte records
                                       * indexed by (u16)slot elsewhere     */
extern u8  g_02148318[];              /* func_02065AA8: 0x20-stride slot
                                       * table, 0x20 entries, each entry's
                                       * +0x10..+0x1f wiped to -1 at reset  */
extern u16 g_020A81F8;                /* func_02065AA8: the "no slot"
                                       * sentinel halfword, 0xFFFE when idle.
                                       * NOTE the SAME address is also the
                                       * base of the scratch matrix object
                                       * the PART 2 dispatchers write at
                                       * +0x18 / +0x1c -- one object, read
                                       * as a halfword by PART 3 and as a
                                       * struct by PART 2                   */
extern u8  g_020A8200[];              /* = &g_020A81F8 + 8: the pointer the
                                       * dispatchers hand the callback when
                                       * the scratch matrix is selected     */
extern s16 g_020A1B38[];              /* func_020659D4: sin/cos table, two
                                       * s16 per 1/16 turn                  */

/* ================================================================== *
 * PART 1: the bank walkers, 0x02064B68..0x02064E3C
 * ================================================================== *
 *
 * The two record layouts.  Evidenced by src/matched/func_02064C10.c (EXACT)
 * and src/matched/func_02064CBC.c (EXACT); docs/notes/sub_02064B68.c.txt and
 * docs/notes/func_02064D70.c.txt carry the same shape at a residue.
 */

struct NodeHdr { u16 pad_00; u16 count; };   /* kind 1: count at +2  */
struct CellHdr { u16 count; };               /* else:   count at +0  */

struct Node { u8 pad_00[0x5c]; };            /* kind 1 record, 0x5c stride */
struct Cell { void *unk_00; u8 pad_04[0x24]; }; /* else, 0x28 stride; the
                                                 * worker gets word 0      */

/*
 * The walked object.  func_02064C10 models it from +0x00 (hdr, unk_04, kind,
 * base); sub_02064B68 and func_02064CBC reach the same four fields at +0x34,
 * +0x3c and +0x40 of a larger object, so the four-field block is a NESTED
 * sub-object and the two spellings are the same layout at two offsets.  The
 * spelling kept here is the larger one, which both of the bigger functions
 * need.
 */

struct Bank {
    void *hdr;                        /* +0x00  union of NodeHdr*/CellHdr*  */
    u32   unk_04;
    u32   kind;                       /* +0x08  1 selects the 0x5c layout   */
    void *base;                       /* +0x0c  array base                  */
};

struct Walked {                       /* func_02064CBC, sub_02064B68        */
    u8    pad_00[0x0c];
    u32   state;                      /* +0x0c  raised to 1 by func_02064CBC*/
    u8    pad_10[0x0c];
    u32   unk_1c;                     /* +0x1c  passed to func_0206469C     */
    u8    pad_20[0x10];
    u16   unk_30;                     /* +0x30  cleared by func_02064CBC    */
    u8    pad_32[2];
    void *hdr;                        /* +0x34  the Bank's hdr.  MUST be
                                       * read `volatile` under 1.1p1 or the
                                       * two arms' loads are CSE'd and the
                                       * function loses four bytes --
                                       * docs/notes/sub_02064B68.c.txt      */
    u8    pad_38[4];
    u32   kind;                       /* +0x3c                              */
    void *base;                       /* +0x40  MUST be a named local, not
                                       * spelled out at both use sites      */
};

extern void sub_020643C4(void *rec, void *arg);   /* sub_02064B68 */
extern void func_02064384(void *rec, u32 idx);    /* func_02064C10 */
extern void func_020643A4(void *rec);             /* func_02064CBC */
extern void func_0206469C(void *o, u32 a);        /* func_02064CBC */

extern void sub_02064B68 (struct Walked *r, void *arg);   /* DIFF, 15 out */
extern void func_02064C10(struct Bank *x);                /* EXACT        */
extern void func_02064CBC(struct Walked *x);              /* EXACT, 2.0   */
extern void func_02064D70(void *p, int (*fn)(void *, void *, void *, int),
                          void *ctx);                     /* DIFF, 4 short*/
extern void func_02064E3C(void);                          /* EXACT        */

/* ================================================================== *
 * PART 2: the vtable dispatchers, 0x02064EDC..0x020653A4
 * ================================================================== *
 *
 * The jump table at the live object's +0x74.  Slot offsets are evidenced by
 * the `ldr rN, [r1, #0xNN]` that precedes each `blx`: +0x34 and +0x38 in
 * func_02065020, +0x3c in func_02065134, +0x44 in func_020653A4.
 */

typedef int  (*ActorFn34)(void *a1, void *vt, void *mtx);
typedef void (*ActorFn38)(void *obj, void *vt, void *a1, void *mtx);
typedef void (*ActorFn3C)(void *obj, void *vt, void *a1, void *mtx);
typedef void (*ActorFn44)(void *obj, void *vt, void *a1, void *a2,
                          void *mtx);   /* fifth argument goes on the stack */

struct ActorVtbl {
    u8        pad_00[0x34];
    ActorFn34 f34;                    /* +0x34  func_02065020 */
    ActorFn38 f38;                    /* +0x38  func_02065020 */
    ActorFn3C f3c;                    /* +0x3c  func_02065134 */
    u8        pad_40[4];
    ActorFn44 f44;                    /* +0x44  func_020653A4 */
};

struct Actor {
    u8                pad_00[0x74];
    struct ActorVtbl *vtbl;           /* +0x74 */
};

/*
 * THE MATRIX SELECTION, written out once.  Every PART 2 dispatcher contains
 * exactly this block, and getting it byte-right turns on two things that
 * cost this wave real time:
 *
 *   - the slot index g_02147B88.slot must be read in BOTH arms, not hoisted
 *     above the branch, in func_020653A4 and func_02065020 (the image has
 *     `ldreq lr, [lr, #0xc]` in the selected arm and a second `ldr r4, [lr,
 *     #0xc]` in the other), but MUST be hoisted in func_02065134 (one
 *     unconditional `ldr ip, [r3, #0xc]` before the `cmp`).  A `volatile`
 *     cast on the manager pointer is what forces the two-read form.
 *   - the else arm's two loads/stores must be written in source order
 *     D28-then-D2C; any lifting of the second into a temporary reorders the
 *     pool and costs a dozen bytes.
 *
 *       if (g_02147B88.unk_04 == 0) {
 *           m = &g_02147D18[g_02147B88.slot];
 *       } else {
 *           u32 off = g_02147B88.slot * 0x18;
 *           g_020A81F8_as_scratch.f18 = *(u32 *)&g_02147D28[off];
 *           g_020A81F8_as_scratch.f1c = *(u32 *)&g_02147D2C[off];
 *           m = g_020A8200;
 *       }
 */

struct ScratchMtx {                   /* overlays g_020A81F8 */
    u8  pad_00[0x18];
    u32 f18;
    u32 f1c;
};

extern void func_02064EDC(void);                    /* open, 292 bytes    */
extern void func_02065020(void *host, void *a1);    /* DIFF, 35 out       */
extern void func_02065134(void *a0, void *a1);      /* DIFF, 2 out        */
extern void func_020651B8(void *a0, void *a1, void *a2); /* open, 468 b   */
extern void func_020653A4(void *a0, void *a1, void *a2); /* DIFF, 31 out  */

/* ================================================================== *
 * PART 3: the draw and reset path, 0x02065438..0x02066620
 * ================================================================== */

/*
 * The 0x48-byte cell actor func_02065B74 builds.  Its four function
 * pointers are laid out IN THE OBJECT, in pool order, not as an array of
 * addresses; all four resolve by sole-ref/code (each is exactly a traced
 * func_ label and this table is their only reference image-wide).
 */

struct ActorObj {
    u8  pad_00[0x10];
    u32 state;                        /* +0x10  = 1 */
    u32 mode;                         /* +0x14  = 3 */
    u32 fn18;                         /* +0x18  = func_02065020 */
    u32 fn1c;                         /* +0x1c  = func_02065134 */
    u32 fn20;                         /* +0x20  = func_020651B8 */
    u32 fn24;                         /* +0x24  = func_020653A4 */
};                                    /* cleared to 0x48 bytes first  */

/* The secondary-render-surface bracket, func_02065CE4 / func_02065D4C. */

struct Surface {
    u8  pad_00[0x80];
    int f80;                          /* +0x80  non-zero == bracket the draw */
};

/* The animation command record func_020659D4 and func_02066080 apply. */

struct DrawCmd {
    int  unk_00;                      /* the handle re-passed to func_02065878 */
    u8   pad_04[4];
    int  unk_08;                      /* 0 == nothing to draw                  */
    u8   pad_0c[4];
    fx32 scaleX;                      /* +0x10  flag 2 */
    fx32 scaleY;                      /* +0x14  flag 2 */
    s16  transX;                      /* +0x18  flag 8, shifted <<12 */
    s16  transY;                      /* +0x1a  flag 8, shifted <<12 */
    u16  angle;                       /* +0x1c  flag 4, >>4 indexes g_020A1B38 */
    u16  flags;                       /* +0x1e  bit 8 translate, 4 rotate,
                                       *        2 scale                       */
};

extern void  MIi_CpuClear16(u32 val, void *dst, u32 size); /* 0x02082A48 */
extern void  func_02082AC0(int val, void *dst, int size);  /* fill        */

extern int   func_02067B50(int a);    /* func_020659D4: flip-X query */
extern int   func_02067B64(int a);    /* func_020659D4: flip-Y query */
extern void  func_02067A60(void *o);  /* func_02065AA8               */
extern void  func_02067CB0(void);     /* func_02065C78               */

extern int   func_02066E20(void);     /* save render surface   */
extern void  func_02066DEC(int mode); /* switch render mode    */
extern void  func_02066E10(int surf); /* bind render surface   */
extern void  func_02066DFC(void);     /* close the bracket     */

extern void  func_0206615C(int a);            /* push a matrix slot      */
extern void  func_020663D0(fx32 x, fx32 y, fx32 z);   /* translate       */
extern void  func_020664CC(fx32 sx, fx32 sy, fx32 sz);/* scale           */
extern void  func_02066620(fx32 sn, fx32 cs);         /* rotate          */
extern void  func_02066380(void);             /* pop a matrix slot       */

extern void  func_02065438(void *actor);      /* the plain draw          */
extern void  func_02065878(void *actor);      /* the other plain draw    */

extern void  func_020659D4(struct DrawCmd *c);            /* EXACT       */
extern void  func_02065AA8(u8 *o);                        /* EXACT, 2.0  */
extern void  func_02065B64(int p0, int p1, int p2, int p3); /* EXACT     */
extern void  func_02065B74(struct ActorObj *p);           /* EXACT, 2.0  */
extern void  func_02065BD0(int a0);                       /* DIFF, 53 out*/
extern void  func_02065C78(void);                         /* EXACT       */
extern void  func_02065CE4(void *actor);                  /* EXACT, 2.0  */
extern void  func_02065D4C(void *actor);                  /* EXACT, 2.0  */

/* ================================================================== *
 * WAVE 8 SECOND LANE (2026-09-22): what was proved
 * ================================================================== *
 *
 * Eight more EXACT: func_02066080, func_02066380 (1.1p1), func_02065020
 * (1.1p1), func_020663D0, func_0206615C, func_02065878, func_020651B8,
 * func_02065BD0 (all ../2.0/sp2).  Near misses in docs/notes/pkt_02064B68.c.txt.
 *
 * 1. g_02147D28 / g_02147D2C ARE NOT OBJECTS.  They are &g_02147D18[0].tx and
 *    &g_02147D18[0].ty: a field of table[i] with a run-time i puts the member
 *    offset in the relocation addend.  Declare
 *        typedef struct { fx32 m00, m01, m10, m11, tx, ty; } Mtx;
 *        extern Mtx g_02147D18[];
 *    and write g_02147D18[i].tx; the pool words, their ORDER and the
 *    load/store interleave then come out as the image has them (this is what
 *    closed func_020663D0 and func_0206615C).  Likewise 0x02147C1C is
 *    &g_02147C18[0].state, and 0x020A8200 is the Mtx at g_020A81F8 + 8:
 *        struct Scr { u8 pad_00[8]; Mtx mtx; };  extern struct Scr g_020A81F8;
 *    The ScratchMtx / g_020A8200 / u8[] spellings above are superseded.
 *
 * 2. THE PART 2 MATRIX SELECTION IS AN INLINE HELPER returning Mtx *:
 *        if (unk_04 == 0) m = &g_02147D18[slot];
 *        else { scr.mtx.tx = g_02147D18[slot].tx; scr.mtx.ty = ...ty;
 *               m = &scr.mtx; }
 *    Called as an argument it reproduces both slot-read shapes of
 *    func_02065020 with no volatile.  func_02064EDC's variant selects
 *    g_02148018[slot] in the eq arm.
 *
 * 3. CALLBACK ARITY: vtbl +0x34 is (a1, Mtx *m, vtbl), not (a1, vtbl, m);
 *    +0x38 is (obj, vtbl, a1, m); +0x3c (obj, vtbl, a1, m); +0x40 and +0x44
 *    are (obj, vtbl, a1, a2, m) with m on the stack.
 *
 * 4. A MATERIALISED BOOLEAN (movCC #1 / movCC' #0 / cmp #0) in this cluster is
 *    spelled as a NEGATED comparison: `r = !(x == -1)` (func_02065878),
 *    `r = !(slot > 0)` (func_02066380), `r = !(next >= 0x20)`
 *    (func_0206615C).  The direct comparison folds into a branch.
 *
 * 5. func_0206615C / func_02066380 are the matrix-slot PUSH / POP; both take
 *    one int that neither reads (callers pass the flag word / 1).  The PUSH
 *    copies tx, ty, g_02147B98 (translate mode) or D18, 8018, B98 (full), in
 *    that order, and promotes the g_02147C18 record state 1 -> 2.
 *
 * 6. The shared tail of func_020664CC / func_02066620: the dense switch on
 *    g_02147C18[(u16)slot].state sends states 0, 2 and 3 to the body (state
 *    1 skips): n = slotLimit; slotLimit = n + 1; rec->f2 = n; rec->state = 1.
 *    Under the pin the slotLimit read/write and the rec->f2 store must be
 *    volatile-cast to keep the image's store order.
 *
 * 7. func_02065878 / func_02066080 / func_020659D4 are the same transform
 *    applier with the DrawCmd record at +0x30 / +0x34 / +0x00; func_02065DB4
 *    is the list drawer func_02066080 calls on its +0x34 record; the entry
 *    flip queries func_02067B50/B64 take g_02147B88.obj, never ->f80.
 *
 * 8. Compiler pin tally for the range is now 10 x ../2.0/sp2 against 7 x
 *    1.1p1.  The PART 2 dispatchers that PREDICATE the selection (ldreq /
 *    mlaeq) are 1.1p1 (func_02065020, and the near misses func_02065134,
 *    func_020653A4); func_020651B8's selection is the same C under 2.0.
 */

#endif /* CLUSTER_02064B68_H */
