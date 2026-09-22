/*
 * docs/families/cluster_020726D0.h -- shared declarations for the
 * pseudo-family at 0x020726D0..0x02072A28 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.  Never edit src/matched from this file; the
 * matched sources are the evidence and this is the summary.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit.  It was formed by address adjacency plus shared callees and data
 * objects.  What it actually holds is the SOUND SUBSYSTEM FRONT DOOR: the
 * boot/one-shot init (func_020726D0, func_02072758), the driver-info
 * double-buffer pump (func_020727B4, func_02072894), the post-sleep callbacks
 * (func_020728E8, func_02072920), and -- the part this pass closed -- a small
 * CHANNEL ALLOCATOR over the three-word global g_0214DEC0.
 *
 * Two distinct globals are in play and they must not be confused:
 *   g_0214BAC0   the driver control block (idx / pending / tag / two
 *                PMSleepCallbackInfo blocks).  Used by 0x020726D0-0x020728E8.
 *   g_0214DEC0   the channel allocator's three words.  Used by
 *                0x0207292C-0x02072A28 and by func_02072974 / func_02072DB0.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02072[6-9A]" src/matched/*.c
 * and from the four notes docs/notes/pkt_0207292C.c.txt,
 * docs/notes/pkt_020729C0.c.txt, docs/notes/pkt_02071DD4.c.txt and
 * docs/notes/pkt_020727B4.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  A plain `ldr r1,[r1,#8]` fixes a 32-bit field at
 * +8 and says nothing about its signedness; `mvn`/`ldrsb` do.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * SIX of this cluster's functions are byte-exact only under `--cc ../2.0/sp2`
 * and are DIFF (or a push-list wide) under the project default dsi/1.1p1:
 *
 *   func_020726D0  func_02072758  func_020727B4  func_0207312C
 *   func_0207292C  func_020729C0
 *
 * The tell is always the same one and it is the "kept constants" tell of
 * docs/FRONTEND-PINS.md, i.e.
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md:
 * whenever a value is live at more than one point -- a small literal (0 or 1),
 * or, in this cluster far more often, THE POOL WORD FOR THE GLOBAL'S BASE --
 * 1.1p1 -O4,p hoists it into a callee-saved register and reuses it, which
 * widens the prologue's push list by one or two slots and shifts every later
 * register.  The image instead RELOADS the base pool word at each use, which
 * is why these functions have a bare `push {r4, lr}` and several distinct pool
 * entries for one symbol.
 *
 * Symptom to recognise instantly: a compile whose instructions and relocations
 * are ALL correct but whose `push`/`pop` lists are one or two registers wider
 * than the image's, and which is four or more bytes SHORT because the pool
 * folded.  func_0207292C is the canonical measurement (2026-09-22): under
 * 1.1p1 it is 68 bytes against the original's 72 with 26 concrete bytes out,
 * `push {r3,r4,r5,lr}` for the image's `push {r4,lr}` and a hoisted
 * `ldr r4,[pc,#0x28]`; under ../2.0/sp2 THE SAME C, unchanged, is 72 bytes and
 * EXACT.  func_020729C0 is the same story at 46 bytes out.
 *
 * DO NOT RESPELL THE C WHEN YOU SEE THIS.  Both of the DIFF files in this
 * cluster carried correct C for a day and were demoted as codegen failures;
 * changing only the `--cc` flag closed both.
 *
 * NOT every function here needs the pin.  func_020729A4 and func_02072A08 are
 * EXACT under BOTH compilers (each is a single read-modify-write with no value
 * live across two points, so there is nothing for 1.1p1 to hoist), as are
 * func_02072794, func_02072894, func_020728E8, func_02072974 and func_02072A28.
 * The rule is mechanical: one use of the base, either compiler; two or more
 * uses of the base or of a literal, the pin.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_020726D0_H
#define CLUSTER_020726D0_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The driver control block.  func_020726D0 fixes the two PMSleepCallbackInfo
   blocks at +0x10 and +0x20 (their addresses are taken and handed to
   PM_PrependPostSleepCallback / PM_AppendPostSleepCallback, so they are
   EMBEDDED, not pointers); func_020727B4 and func_02072894 fix b00 as SIGNED
   (`if (idx < 0)`, and func_020726D0's `mvn r1,#0` for the -1 seed, which a
   (u8)-1 would spell as `mov r0,#0xff`). */
struct SleepCb { void (*fn)(void *); void *arg; void *p08; void *p0c; };

struct SndCtl {
    s8  b00_idx;            /* 0x00  buffer index, SIGNED, -1 = none          */
    u8  p01[3];
    u32 f04;                /* 0x04  "pending" / initialised flag             */
    u32 p08;
    u32 f0c_latch;          /* 0x0c  one-shot init latch                      */
    struct SleepCb cb10;    /* 0x10  PM_PrependPostSleepCallback's argument   */
    struct SleepCb cb20;    /* 0x20  PM_AppendPostSleepCallback's argument    */
};
extern struct SndCtl g_0214BAC0;        /* 0x0214BAC0                         */

/* The two 0x11E0-byte driver-info buffers func_020727B4 alternates between and
   func_02072894 indexes with SndCtl.b00_idx. */
#define SND_INFO_STRIDE     0x11E0
extern u8 g_0214BB00[];                 /* 0x0214BB00, stride 0x11E0          */

/* ------------------------------------------------------------------------ *
 * THE CHANNEL ALLOCATOR GLOBAL.  Three consecutive words at 0x0214DEC0.
 *
 * Field evidence, one function per line (this is the whole of it -- nothing in
 * the cluster touches any other offset of this object):
 *
 *   +0x00   a mask, cleared bit by bit.  func_020729A4 is the only writer:
 *           `ldr r2,[r1] / and r0,r2,r0 / str r0,[r1]` after an `mvn r0,r0`,
 *           i.e. `f00 &= ~mask` where MASK IS ALREADY A MASK, not an index.
 *           The `mvn` of the PARAMETER (not of a shifted 1) is what separates
 *           this function from func_02072A08 below.
 *   +0x04   the channel-in-use bitmap, 8 bits wide.  func_020729C0 is the
 *           allocator: it walks i = 0..7 with a running `bit` that starts at 1
 *           and doubles, returns the first i whose bit is clear (setting it),
 *           and returns -1 (`mvn r0,#0`) when all eight are taken.  The loop
 *           bound is a literal 8 (`cmp r0,#8` / `blt`), SIGNED.
 *           func_02072A08 is the matching free: `f04 &= ~(1u << bit)`, where
 *           the `mvn r0, r2, lsl r0` proves the shift happens INSIDE the
 *           complement and that the parameter is an INDEX, not a mask.
 *   +0x08   a second mask, the one the hardware channels live in.
 *           func_0207292C claims bits (`if (f08 & mask) return 0;` then
 *           `f08 |= mask`) and matched func_02072974 releases them
 *           (`f08 &= ~chan`).  Both take a MASK.
 *
 * SO THE OBJECT IS ONE (u32, u32, u32) AND +0x04 IS INDEX-ADDRESSED WHILE
 * +0x00 AND +0x08 ARE MASK-ADDRESSED.  Matched func_02072A28 zeroes all three,
 * and notably zeroes them in the order f08, f00, f04 -- source order, since
 * this compiler never reorders stores; writing them 0,4,8 is a byte difference.
 * ------------------------------------------------------------------------ */
struct SndChan {
    u32 f00_mask;           /* 0x00  cleared by mask (func_020729A4)          */
    u32 f04_bitmap;         /* 0x04  8-bit alloc bitmap, index-addressed      */
    u32 f08_mask;           /* 0x08  claimed/released by mask                 */
};
extern struct SndChan g_0214DEC0;       /* 0x0214DEC0                         */

#define SND_CHAN_COUNT      8   /* func_020729C0's `cmp r0, #8`               */

/* ================================================================== *
 * 1.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the audio driver layer (0x02089xxx / 0x0208Cxxx / SDK) --------------- */
extern void SND_Init(void);                             /* 0x02089848        */
extern u32  SND_RecvCommandReply(u32 mode);             /* 0x02089978        */
extern u32  SND_IsFinishedCommandTag(u32 tag);          /* 0x02089D6C        */
extern void SND_ReadDriverInfo(void *dst);              /* 0x02089794        */
extern u32  SND_GetCurrentCommandTag(void);             /* 0x02089D40        */
extern void SND_FlushCommand(u32 flags);                /* 0x02089B38        */
extern void DC_InvalidateRange(void *p, u32 n);         /* 0x020862B8        */
extern void PM_PrependPostSleepCallback(struct SleepCb *cb);  /* 0x0208C808  */
extern void PM_AppendPostSleepCallback(struct SleepCb *cb);   /* 0x0208C828  */
extern void func_02089754(u32 v);
extern void func_02089774(void);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02089D40(void);
extern void func_02089CD4(u32 token);
extern void func_020895D8(u32 mask, u32 flag);   /* claim   -- func_0207292C */
extern void func_020895F8(u32 mask, u32 flag);   /* release -- func_02072974 */
extern u32  func_0208A0A4(u8 *info, u32 a, u32 b, u32 c);

/* --- this cluster's own --------------------------------------------------- */
extern void func_020726D0(void);                /* one-shot init              */
extern void func_02072758(void);                /* boot sequence              */
extern u32  func_020727B4(void);                /* driver-info pump           */
extern void func_02072794(u32 flag);
extern u32  func_02072894(u32 a, u32 b, u32 c);
extern void func_020728E8(void);                /* post-sleep, prepended      */
extern void func_02072920(void *p);             /* post-sleep, appended       */
extern int  func_0207292C(u32 mask);            /* claim by mask,  1 = ok     */
extern void func_02072974(u32 mask);            /* release by mask (+0x08)    */
extern void func_020729A4(u32 mask);            /* clear by mask   (+0x00)    */
extern int  func_020729C0(void);                /* allocate, -1 = full        */
extern void func_02072A08(u32 index);           /* free by index   (+0x04)    */
extern void func_02072A28(void);                /* zero all three words       */

/* --- reached from the boot sequence, outside this cluster ----------------- */
extern void func_020731E0(void);
extern void func_0207312C(void);
extern void func_02073D5C(void);
extern void func_02073D7C(void);
extern void func_02073EE4(void);
extern void func_02075858(void);

#endif /* CLUSTER_020726D0_H */
