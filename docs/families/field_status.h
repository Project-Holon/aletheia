/*
 * field_status.h -- shared declarations for the field_status.c family,
 * 0x02014428..0x02014A80 in the Black ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file and nothing in
 * src/matched or src/pending is edited to use it.  It is the derived
 * ground truth: every field, width, signedness and prototype below is
 * read out of an EXACT source under src/matched, and each entry names
 * the matched function that evidences it.  Where two matched files
 * disagree on a name for the same offset, the offset is what is
 * attested and the name is this file's own.
 *
 * Derived 2026-09-22 from the 19 byte-exact members of the family
 * (17 single-function files plus unit_02014444.c).
 */

#ifndef FIELD_STATUS_H
#define FIELD_STATUS_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * The family's organising shape: the task-step protocol.
 *
 * Nine of the nineteen matched members are two interlocking halves of
 * one idiom, and reading them together is what names everything else.
 *
 *   * a SPAWNER calls func_020122C0(parent, 0, (int)step_fn, argsize)
 *     to create a task whose step function is `step_fn`, then calls
 *     func_020124E8() to get the task's own argument block and writes
 *     the caller's arguments into it as consecutive u32 words.
 *     Evidenced EXACT by func_020146F8 (0x14 = 5 words),
 *     func_02014728 (0x14), func_02014808 (0x1c = 7 words),
 *     func_02014840 (0x1c) and func_02014910 (0x10 = 4 words).
 *
 *   * a STEP FUNCTION has the signature
 *         u32 step(void *obj, u32 *mode, u32 *args)
 *     and is re-entered every frame.  It switches on *mode, does one
 *     stage of work per call, increments *mode to advance, returns 0
 *     to mean "call me again" and 1 to mean "done, tear me down".
 *     Evidenced EXACT by func_02014584, func_02014628, func_02014758
 *     and func_020147B0.
 *
 * The `argsize` a spawner passes to func_020122C0 is therefore the
 * exact size of the `args` block its step function reads, and the two
 * together pin each descriptor's word count.  That pairing is the
 * strongest structural evidence in the family:
 *
 *     spawner        argsize  step function   args words
 *     func_020146F8   0x14    func_02014628   p[0]..p[4]
 *     func_02014728   0x14    func_02014698   p[0]..p[4]
 *     func_02014808   0x1c    func_02014758   f00..f18
 *     func_02014840   0x1c    func_020147B0   f00..f18
 *     func_02014910   0x10    func_02014878   p[0]..p[3]
 * ------------------------------------------------------------------ */

/* The task substrate these files are clients of.  Declared with the
 * exact parameter types the matched sources use. */
extern void *func_020122C0(char *parent, int a1, int step_fn, int argsize);
extern u32  *func_020124E8(void);            /* the task's arg block   */
extern void *func_020120F4(void *a0);
extern void  func_02012374(void *obj, void *out);   /* publish result  */
extern u32   func_020120F0(void);            /* "still busy?" poll     */
extern void  func_020120B4(u32 a0, u32 a1, u32 a2, u32 a3);
extern void  func_020120C0(int v);
extern int   func_0201210C(int v);

/* ------------------------------------------------------------------ *
 * struct StepDesc -- the 0x1c-byte descriptor, 7 words.
 *
 * Written by func_02014808 and func_02014840 (both EXACT) as seven
 * consecutive u32 stores into the block func_020124E8 returns; read
 * back by func_02014758 and func_020147B0 (both EXACT), which are the
 * files that give the last two words their real types.  The first five
 * words are forwarded verbatim to a spawner, so they are opaque here.
 * ------------------------------------------------------------------ */
struct StepDesc {
    int    f00;             /* +0x00  func_02014758: forwarded arg 0   */
    int    f04;             /* +0x04  func_02014758: forwarded arg 1   */
    int    f08;             /* +0x08  func_02014758: forwarded arg 2   */
    int    f0c;             /* +0x0c  func_02014758: forwarded arg 3   */
    int    f10;             /* +0x10  func_02014758: forwarded arg 4,
                             *        the one passed on the stack.     */
    void (*f14)(void *);    /* +0x14  func_02014758 state 1 calls it
                             *        through the slot when non-null,
                             *        with f18 as its only argument:
                             *        that call shape is what makes it
                             *        a one-argument function pointer
                             *        rather than a plain word.        */
    void  *f18;             /* +0x18  func_02014758 state 2 frees it
                             *        with func_020307B0 when non-null,
                             *        so it is an owned heap pointer.  */
};

/* ------------------------------------------------------------------ *
 * struct Sub02014444Obj -- the small settings object, 0x14 bytes.
 *
 * The whole of unit_02014444.c (EXACT as one tu range) is fourteen
 * accessors on this one object, and each field below is evidenced by
 * the getter/setter pair that touches it.  The total size is fixed
 * independently by func_02014428 (EXACT), which allocates 0x14 bytes
 * and clears the u16 at +0x12 -- the same offset sub_02014474 and
 * sub_02014478 spell as a u16.
 *
 * The seven bytes between +0x09 and +0x10 are padding, not a guess:
 * nothing in the family or its callers reads them.
 * ------------------------------------------------------------------ */
struct Sub02014444Obj {
    u32 f00;                /* +0x00  sub_0201444C / sub_02014450      */
    u8  f04;                /* +0x04  sub_02014458 / sub_02014454      */
    u8  f05;                /* +0x05  sub_02014460 / sub_0201445C      */
    u8  f06;                /* +0x06  sub_02014468 / sub_02014464      */
    u16 f08;                /* +0x08  sub_02014470 / sub_0201446C      */
    u8  pad0A[7];           /*        unattested padding               */
    u8  f11;                /* +0x11  reached two ways: sub_02014484 is
                             *        a plain getter, sub_0201447C is a
                             *        set-and-return-old accessor.     */
    u16 f12;                /* +0x12  sub_02014478 / sub_02014474;
                             *        func_02014428 zeroes it at
                             *        construction.                    */
};

/* Constructor and the SDK trampoline that opens the unit. */
extern void func_02014428(u32 heap);   /* allocs 0x14, clears +0x12    */
extern void sub_02014444(u32 a, u32 b, u32 c);  /* -> ENV_SetResourceSet */

/* ------------------------------------------------------------------ *
 * The 0x34-byte time-of-day record.
 *
 * Both func_02014A20 and func_02014A80 (both EXACT) walk the same
 * table with the same 0x34 stride, and between them they attest every
 * field this family touches.  func_02014A20 divides the sub-file's
 * byte size by 0x34 to get the record count, which is what fixes the
 * stride as the record size rather than merely a step.
 * ------------------------------------------------------------------ */
struct TodRecord {                  /* stride 0x34 */
    u16 hour;       /* +0x00  func_02014A80 passes it to func_02011400
                     *        and scales the result by 0xe10 (3600), so
                     *        it is an hour index.                     */
    s16 minute;     /* +0x02  func_02014A80 reads it with a REGISTER-
                     *        offset ldrsh and scales by 0x3c (60).
                     *        The register-offset form is the only
                     *        evidence of signedness available (see
                     *        docs/idioms/ldrsh-register-offset-is-
                     *        signedness.md), and it is why both
                     *        comparisons on the running value are bgt. */
    u8  pad04[0xc];
    u16 vec[4][3];  /* +0x10  func_02014A20 normalizes four 6-byte
                     *        VecFx16 triples in place per record,
                     *        stepping j * 6 from +0x10.               */
    u8  pad28_a[0]; /*        (the four triples end at +0x28)          */
    u16 outA[4];    /* +0x08  func_02014A80 copies four halfwords from
                     *        +0x08..+0x0e into out[0..3].  NOTE: this
                     *        overlaps pad04 in offset terms; the two
                     *        views are reconciled below.              */
    u16 outB[4];    /* +0x28  func_02014A80 copies four halfwords from
                     *        +0x28..+0x2e into out[4..7].             */
};

/*
 * Reconciliation note for struct TodRecord.  The two matched readers
 * disagree about what lives between +0x08 and +0x28, and neither is
 * wrong -- they simply read the same bytes through different windows:
 *
 *   * func_02014A80 (EXACT) treats +0x08..+0x0e and +0x28..+0x2e as
 *     eight plain u16 fields, which it copies out verbatim.
 *   * func_02014A20 (EXACT) treats +0x10..+0x27 as four consecutive
 *     6-byte vectors and normalizes them.
 *
 * So the attested layout is: two time fields at +0x00/+0x02, four
 * halfwords at +0x08, four VecFx16 triples at +0x10 (ending at +0x28),
 * and four more halfwords at +0x28, with +0x04..+0x07 and +0x30..+0x33
 * unread by anything in this family.  The C struct above cannot
 * express the overlap cleanly; the OFFSETS are what is attested, and
 * a writer should reach the fields by offset as the matched sources do
 * rather than trusting the member order here.
 */

extern void *func_02014A20(u32 archive, u32 member, u32 *count_out, u32 heap);
extern void  func_02014A80(u8 *table, u32 count, s32 now, u32 a3, u16 *out);
extern u16   func_02014A10(u32 i);   /* sub_0209E054_Map[i] */
extern u8    func_0201441C(int i);   /* sub_0209E050_Map[i] */

/* The two small maps the accessors above index.  Both are attested
 * only by their single reader (blocker lines in func_0201441C.c and
 * func_02014A10.c), so their extents are unknown and they are declared
 * as open arrays. */
extern u8  sub_0209E050_Map[];       /* 0x0209E050  data */
extern u32 sub_0209E054_Map[];       /* 0x0209E054  data */

/* ------------------------------------------------------------------ *
 * The spawner / step-function pairs, with the types the matched
 * sources actually use.  The step functions all share one signature;
 * the spawners differ only in arity and in the step they install.
 * ------------------------------------------------------------------ */
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4,
                           int a5, int a6);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4,
                           int a5, int a6);
extern void *func_02014910(char *a0, int a1, int a2, int a3);

extern int   func_02014584(int a0, int *mode, int *args);
extern u32   func_02014628(void *obj, u32 *mode, u32 *args);
extern int   func_02014758(int a0, int *mode, struct StepDesc *d);
extern int   func_020147B0(int a0, int *mode, struct StepDesc *d);

/* The four members that are byte-correct but capped at MATCH, and the
 * two that are still DIFF, are declared here for completeness because
 * matched members call them.  Their sources are under src/pending and
 * docs/notes; see docs/notes/wave6 write-ups for the blocking class of
 * each. */
extern int   sub_02014488(void *a0, u32 *mode, u8 *args);   /* MATCH  */
extern int   func_0201450C(int a0, int *mode, int *args);   /* MATCH  */
extern void *func_020145CC(void *a0);                       /* MATCH  */
extern u32   func_02014878(u32 a0, u32 *mode, u32 *args);   /* MATCH  */
extern u32   func_02014698(void *obj, u32 *mode, u32 *args);/* EXACT  */
extern void  func_0201493C(u32 id, u32 a1, u32 a2, u32 a3,
                           u32 b0, u16 *b1, u16 heap);      /* EXACT  */

/* ------------------------------------------------------------------ *
 * Constants attested by the family.
 * ------------------------------------------------------------------ */
#define TOD_RECORD_SIZE   0x34   /* func_02014A20: size / 0x34 = count */
#define TOD_SECS_PER_HOUR 0xe10  /* func_02014A80, func_0201493C       */
#define TOD_SECS_PER_MIN  0x3c   /* func_02014A80, func_0201493C       */

/* Archive member ids func_0201493C passes to func_02014A20, in the
 * order it tries them.  These are content constants and may well
 * differ in White; see docs/AGENT-BRIEF.md section 8. */
#define ARCHIVE_TOD_EXPLICIT 0x3e
#define ARCHIVE_TOD_MAPPED   0x52
#define ARCHIVE_TOD_BUILT    0x3d

/* The "no mapping" sentinel func_02013F2C returns, and the tag the
 * heap argument is OR'd with.  func_0201493C materialises 0x10000000
 * as this sentinel plus one, which is the residue documented in
 * docs/notes/pkt_0201493C.c.txt. */
#define TOD_NO_MAPPING    0x0fffffff
#define TOD_HEAP_MASK     0x7fff
#define TOD_HEAP_TAG      0x8000

/* ------------------------------------------------------------------ *
 * ADDED 2026-09-23 (wave 13).  Both DIFF members closed:
 *
 *  - func_0201493C's seventh parameter is `u16 heap` (the ov094 caller at
 *    0x021F7702 loads it with ldrh), used as `(heap & 0x7fff) | 0x8000` --
 *    TOD_HEAP_MASK / TOD_HEAP_TAG above -- at every one of its four uses.
 *    The earlier reading through `*(u16 *)((char *)&b0 + 8)` produced both
 *    of that note's "back-end tie-breaks"; neither exists with the real
 *    parameter, so the 0x10000000 tag remark above is obsolete.
 *  - func_02014698 (the step function of func_02014728) needs no labels:
 *    each arm carries its own `(*mode)++; break;`, case 2 is
 *    `if (func_020120F0() == 0) (*mode)++;`, and cross-jumping produces
 *    the image's shared tail jumps.  The goto/label shape that makes the
 *    sibling func_02014628 exact is the wrong reading here.
 *  The remaining open members (func_02014488, func_0201450C,
 *  func_020145CC, func_02014878) are unchanged: overlay-callee or
 *  own-pool evidence walls, re-verified MATCH/MATCH*.
 * ------------------------------------------------------------------ */

#endif /* FIELD_STATUS_H */
