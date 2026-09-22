/*
 * docs/families/cluster_02072A44.h -- shared declarations for the pseudo-family
 * at 0x02072A44..0x02072D20 in the ARM9 image.
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
 * objects.  It is one coherent subsystem all the same: a CHANNEL ALLOCATOR AND
 * VOICE FRONT END sitting on top of the 0x02089xxx audio driver.  Every member
 * operates on one 0x14-byte object (struct Chan below), out of the single
 * stride-0x14 table g_0214DECC, and every member's first act with that object
 * is to turn its +0x00 word into a channel mask `1u << f0`.
 *
 * The ownership bitmask itself lives one step earlier, in g_0214DEC0.flags8
 * (0x0214DEC8), which func_0207292C claims bits in and func_02072974 releases
 * them from; func_02072A44 is the allocator entry point that pairs the two.
 *
 * Derived from the eight matched sources found with
 *   grep -l "address:  0x020729\|address:  0x02072[A-D]" src/matched/*.c
 * and from docs/notes/pkt_02072A44.c.txt, docs/notes/pkt_02072C40.c.txt,
 * docs/notes/pkt_0207292C.c.txt and docs/notes/pkt_020729C0.c.txt.
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
 * THIS CLUSTER IS MIXED, and the mix is not noise -- it is one tell per row.
 * Measured, per function:
 *
 *   ../2.0/sp2   func_0207292C  func_020729C0  func_02072AA0  func_02072BDC
 *                func_02072D20
 *   ../1.2/sp2   func_02072A88
 *   dsi/1.1p1    func_020729A4  func_02072A08  func_02072A44  func_02072C18
 *                func_02072C40  func_02072CC4
 *
 * The 2.0 rows all carry ONE tell, the "kept constants" tell of
 * docs/FRONTEND-PINS.md and
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md:
 * whenever a small literal (0 or 1, and in this cluster it is nearly always
 * BOTH, because every call site here is `f(1 << o->f0, 0, 0, 0)`) is live at
 * more than one point, 1.1p1 hoists it into a callee-saved register and reuses
 * it, which widens the prologue's push list by a slot and shifts every later
 * register.  The image rematerialises the literal at each use.
 *
 * SYMPTOM TO RECOGNISE INSTANTLY: a compile whose instructions and relocations
 * are all correct but whose `push`/`pop` list is one register wider than the
 * image's, with `mov r5, #0` / `mov r4, #1` where the image has `mov r1, #0` /
 * `mov r0, #1`.  Change the compiler, not the source.
 *
 * The single 1.2 row (func_02072A88) is the OTHER tell, and it is a schedule
 * rather than an allocation:
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md.
 * 1.1p1 always puts a tail call's pool load last; the image issues it before
 * the last argument write.  If a one-line tail-call thunk here is size-exact
 * with its instructions in the wrong ORDER, that is 1.2, not a spelling.
 *
 * The 1.1p1 rows are the ones with no repeated small constant live across a
 * call, which is why the default front end still owns half the cluster: pick
 * the pin from the residue, never from the neighbour.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02072A44_H
#define CLUSTER_02072A44_H

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef signed   char       s8;
typedef signed   short      s16;
typedef signed   int        s32;
typedef unsigned long long  u64;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The channel-ownership bitmask.  func_0207292C tests and sets bits in
   +0x08; func_02072974 (0x02072974, the release side) clears them.  The
   struct-with-padding spelling rather than a bare `extern u32` is what
   func_0207292C is byte-exact with: the image reaches the word through the
   object base 0x0214DEC0 with a +8 displacement, which is one pool word for
   the whole object rather than one per field. */
struct Global0214DEC0 {
    char pad_00[8];
    int  flags8;                /* 0x0214DEC8 -- one bit per channel         */
};
extern struct Global0214DEC0 g_0214DEC0;    /* 0x0214DEC0                    */

/* ================================================================== *
 * 1.  struct Chan -- the per-channel object, stride 0x14
 *
 * The table is g_0214DECC and func_02072A44 both allocates out of it and
 * proves its stride: `s = &g_0214DECC[idx]` with idx also stored into +0x00.
 * So +0x00 is the channel's OWN index and the table is indexed by it.
 *
 * Field evidence, one function per line:
 *   +0x00  channel index.  EVERY member spells its mask `1u << o->f0`.
 *          func_02072A44 seeds it with the allocation index.
 *   +0x04  the sample rate last started with.  func_02072AA0 latches its
 *          arg7 here at the very end; func_02072C40 reads it back as the
 *          first divisor of the period computation.  SIGNED (`asr r3, r2,
 *          #0x1f` widens it to s64 before the divide).
 *   +0x08  the liveness guard.  func_02072A44 clears it at allocation,
 *          func_02072AA0 sets it to 1 when the voice starts, and
 *          func_02072BDC / func_02072C18 / func_02072C40 / func_02072CC4 all
 *          open with `if (o->f8 == 0) return;`.  func_02072BDC and
 *          func_02072CC4 clear it again on release.
 *   +0x0c  "the driver handle at +0x10 is stale" latch.  func_02072AA0 clears
 *          it beside setting +0x08; func_02072CC4 and func_02072D20 set it to
 *          1 once they have dealt with the handle.
 *   +0x10  the driver handle from func_02089D40, stored by func_02072AA0 and
 *          handed back to func_02089CD4 / func_02089D6C by the two reapers.
 * ================================================================== */
struct Chan {
    u32 f0_index;               /* 0x00  channel index; mask is 1u << this   */
    s32 f4_rate;                /* 0x04  last sample rate, SIGNED            */
    u32 f8_live;                /* 0x08  liveness guard                      */
    u32 fC_handled;             /* 0x0c  handle-consumed latch               */
    u32 f10_handle;             /* 0x10  driver handle (func_02089D40)       */
};
extern struct Chan g_0214DECC[];            /* 0x0214DECC, stride 0x14       */

/* ================================================================== *
 * 2.  The period computation, spelled out once
 *
 * func_02072AA0 and func_02072C40 both compute the channel's timer period
 * the same way, and so does the far caller sub_020067E0 in
 * src/matched/unit_020067E0.c.  It is ONE chained 64-bit division, never two
 * 32-bit ones: `_ll_udiv` (0x0209C00C) takes the dividend in r0:r1 and
 * returns it in r0:r1, so a second call that sets only r2:r3 consumes the
 * first call's quotient.  Both divisors are `int`s, which is what the
 * `asr r3, rX, #0x1f` in front of each call is.
 *
 * The dividend never appears whole in a pool: the low word 0xD87F8000 is the
 * pool entry and the high word 0x7F fits a `mov r1, #0x7f`.
 *
 * The clamp is EXCLUSIVE ARMS, `if (t < LO) t = LO; else if (t > HI) t = HI;`.
 * Two independent `if`s if-convert into one predicated run where the image
 * branches out of the low arm with a `blo` over the whole high arm -- 24
 * concrete bytes in func_02072C40, which is its entire residue.  The `else`
 * is the only thing that proves the two bounds are one clamp in the original.
 * ================================================================== */
#define SND_PERIOD_DIVIDEND 0x7FD87F8000ULL /* 16756991 * 0x8000             */
#define SND_PERIOD_MIN      0x10            /* pool word, e.g. `mov r2,#0x10`*/
#define SND_PERIOD_MAX      0xFFFF          /* pool word 0x0000FFFF          */

/* u64 t = SND_PERIOD_DIVIDEND / rate / freq;
   if (t < SND_PERIOD_MIN) t = SND_PERIOD_MIN;
   else if (t > SND_PERIOD_MAX) t = SND_PERIOD_MAX;                          */

extern u64 _ll_udiv(u64 a, u64 b);          /* 0x0209C00C, arm, runtime      */

/* ================================================================== *
 * 3.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the 0x02089xxx audio driver layer ---------------------------------- */
extern void func_020895D8(int mask, int a);            /* claim  (0207292C)  */
extern void func_02089618(u32 chan, u32 period);       /* set period         */
extern void func_02089638(u32 chan, u32 lo, u32 hi);   /* set parameter      */
extern void func_02089660(u32 chan, int fmt, void *data, int loopmode,
                          int start, int len, int vol, int pan,
                          u32 period, int e);          /* start the voice    */
extern void func_020894B4(u32 chan, int a, int b, int c);
extern void func_020894DC(u32 chan, int a, int b, int c);
extern u32  func_02089D40(void);                       /* take a handle      */
extern u32  func_02089D6C(u32 handle);                 /* poll a handle      */
extern void func_02089CD4(u32 handle);                 /* give one back      */
extern void func_02089B38(int v);
extern u32  func_0208A07C(void);                       /* live-channel mask  */

/* --- this cluster's own -------------------------------------------------- */
extern int          func_0207292C(int mask);           /* claim the bits     */
extern void         func_02072974(u32 mask);           /* release the bits   */
extern struct Chan *func_02072A44(u32 idx);            /* allocate channel   */
extern void         func_02072A88(u32 *p);             /* release *p's chan  */
extern int          func_02072AA0(struct Chan *s, int fmt, void *data,
                                  int loop, int start, int end, int rate,
                                  int vol, int freq, int e);  /* start       */
extern void         func_02072BDC(struct Chan *s);     /* stop the voice     */
extern void         func_02072C18(struct Chan *s, u32 v);
extern void         func_02072C40(struct Chan *s, int v);  /* retune         */
extern int          func_02072CC4(struct Chan *s);     /* poll / reap        */
extern void         func_02072D20(struct Chan *s);     /* wait / reap        */

/* ================================================================== *
 * 4.  Constants
 * ================================================================== */
#define CHAN_STRIDE     0x14    /* g_0214DECC, from func_02072A44            */
#define CHAN_MASK(o)    (1u << (o)->f0_index)

/* func_02072AA0's `fmt` argument, from the three switch arms; the value is
   the element shift of the sample data, so the arm bodies are shifts and not
   divisions (`asr` with no rounding correction). */
#define SND_FMT_PCM8    0       /* start >> 2, end >> 2                      */
#define SND_FMT_PCM16   1       /* start >> 1, end >> 1                      */
#define SND_FMT_ADPCM   2       /* start >> 3, end >> 3                      */

#endif /* CLUSTER_02072A44_H */
