/*
 * docs/families/gf_standard.h -- shared declarations for the gf_standard.c
 * family (0x0203EF5C..0x0203F8F4 in the ARM9 image).  The span is named by
 * the allocation-site string at 0x020A7E4C, which reads "gf_standard.c" and
 * is referenced exactly once image-wide, by the constructor func_0203EF5C
 * (src/matched/func_0203EF5C.c).  The tail boundary is equally firm: the
 * next unit, bg_sys.c, starts at 0x0203F8F4 with its own site string at
 * 0x020A7E5C.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT (or, where noted, from
 * a src/pending file at MATCH or a docs/notes DIFF), and the evidencing
 * function is named in the comment beside it.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.  Note
 * that the file's only content constants are the MT19937 parameters and the
 * calendar tables, neither of which is expected to differ between versions.
 *
 * WHAT THE FILE IS.  Four unrelated services that share one "standard
 * library" unit, which is why the address range looks miscellaneous:
 *
 *   1. 0x0203EF5C..0x0203F258  the random-number generator: an MT19937 in a
 *      heap block behind 0x021469F8, plus a small string/byte-compare set
 *      (memcmp, strlen, strcmp) and the entropy funnel at 0x0203F1FC.
 *   2. 0x0203F258..0x0203F3B4  hashing and the LCG: the 0x60-byte hash state
 *      builder at 0x0203F258, an additive checksum, and the classic
 *      0x41c64e6d LCG used to XOR-mask buffers.
 *   3. 0x0203F3B4..0x0203F684  the real-time clock service: a 0x48-byte
 *      request block at 0x021469FC driven by an asynchronous read, the two
 *      cached copies at 0x02146A0C / 0x02146A1C, and the calendar helpers.
 *   4. 0x0203F684..0x0203F8F4  fixed-point geometry: a sine/cosine table
 *      lookup pair and the point-to-segment signed distance at 0x0203F7C4.
 */

#ifndef GF_STANDARD_H
#define GF_STANDARD_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef signed   long long s64;

typedef s32 fx32;   /* 20.12 fixed point, the SDK's own convention. */

/* ------------------------------------------------------------------ *
 * 1.  THE RANDOM-NUMBER BLOCK
 *
 * One 0xbcc-byte heap object, reached through the pointer at 0x021469F8.
 * Its size is evidenced directly: func_0203EF5C passes the literal 0xbcc to
 * the allocator (src/matched/func_0203EF5C.c).
 *
 * `index` is SIGNED.  func_0203F0A8's exhaustion guard is `blt`, not `blo`
 * (docs/notes/func_0203F0A8.c.txt), and func_0203F034 counts up to 624 on
 * the same field.
 *
 * `mag01` is the MT19937 { 0, MATRIX_A } pair indexed by `y & 1`; the
 * constructor writes mag01[0] = 0 and mag01[1] = 0x9908b0df explicitly,
 * which is what identifies the two words as one array rather than two
 * scalars.  Older sources in src/matched spell them unk_9c4 / unk_9c8.
 * ------------------------------------------------------------------ */
struct Mt {
    u32 mt[624];      /* +0x000  the state vector, N = 624.
                       *         src/matched/func_0203F034.c seeds it. */
    s32 index;        /* +0x9C0  the generator cursor, "mti" in the
                       *         reference implementation.  625 means
                       *         untouched: the constructor writes exactly
                       *         that, and func_0203F0A8 tests for it before
                       *         self-seeding with 5489. */
    u32 mag01[2];     /* +0x9C4  { 0, 0x9908B0DF }. */
    u8  entropy[0x200];
                      /* +0x9CC  the 0x200-byte entropy buffer
                       *         func_020819B8 initialises with tag 4129 and
                       *         func_0203F1FC feeds through func_02081B8C
                       *         (src/matched/func_0203F1FC.c).  0x9CC is out
                       *         of reach of a single ARM rotated immediate,
                       *         so every access to it costs two `add`s,
                       *         +0x1CC then +0x800: that is an encoding
                       *         artefact, not a second pointer. */
};

extern struct Mt *g_021469F8;

/* The packed __FILE__ string for gf_standard.c, the fourth argument to the
 * unit's only allocation (src/matched/func_0203EF5C.c). */
extern char g_020A7E4C[];

/* ------------------------------------------------------------------ *
 * 2.  THE RTC REQUEST BLOCK at 0x021469FC, 0x48 bytes
 *
 * The size is evidenced as the literal passed to the memset in
 * func_0203F3B4 (src/matched/func_0203F3B4.c).  The two halves matter: the
 * LIVE date/time at +0x10/+0x20, which readers copy out, and the STAGING
 * date/time at +0x2C/+0x3C, which the asynchronous read fills and the
 * completion callback promotes into the live pair in one go
 * (src/matched/func_0203F46C.c, src/matched/func_0203F42C.c).
 *
 * Both promotions are whole-structure assignments, so each is one inlined
 * ldm/stm pair; spelling them field by field is a different instruction
 * sequence (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 * ------------------------------------------------------------------ */
struct RtcDate {
    s32 year;         /* +0x00  SIGNED: all three leap-year divisions in
                       *        func_0203F540 are the signed magic-multiply
                       *        shapes (src/pending/func_0203F540.c). */
    u32 month;        /* +0x04  UNSIGNED: the `month >= 3` guard in
                       *        func_0203F540 compiles to `blo`, not `blt`,
                       *        and a signed field is exactly one byte out. */
    s32 day;          /* +0x08 */
    s32 week;         /* +0x0C  day of week; func_02088F58 fills it. */
};

struct RtcTime {
    u32 hour;         /* +0x00  src/matched/func_0203F4FC.c reads the three
                       *        as one `ldm`, which is what says they are
                       *        members of one struct. */
    u32 minute;       /* +0x04 */
    u32 second;       /* +0x08 */
};

struct RtcRequest {
    u32            unk_00;     /* +0x00  set to 1 by the completion callback;
                                *        the "a result has arrived" flag. */
    u32            unk_04;     /* +0x04  the busy flag: raised by
                                *        func_0203F46C before the read and
                                *        cleared by func_0203F42C after the
                                *        promotion.  func_0203F3F0 refuses to
                                *        tick while it is set. */
    s32            unk_08;     /* +0x08  the frame counter.  SIGNED: the
                                *        every-eleventh-frame guard is `ble`
                                *        (src/matched/func_0203F3F0.c). */
    u32            result;     /* +0x0C  the return code of the request. */
    struct RtcDate date;       /* +0x10  the live date. */
    struct RtcTime time;       /* +0x20  the live time. */
    struct RtcDate stagedDate; /* +0x2C  the read target. */
    struct RtcTime stagedTime; /* +0x3C  the read target. */
};

extern struct RtcRequest g_021469FC;

/* The two cached copies the readers hand out.  They are SEPARATE objects,
 * not fields of the block above: func_0203F524 passes their addresses to
 * func_02089004 as two independent pointers, and func_0203F4FC reads
 * 0x02146A1C as a bare cast constant with no relocation at all
 * (src/matched/func_0203F4FC.c). */
extern struct RtcDate g_02146A0C;
extern struct RtcTime g_02146A1C;

/* The cumulative days-before-month table, twelve (or thirteen) halfwords.
 * NOTE THE ALIGNMENT: 0x020A08B6 is HALFWORD aligned, not word aligned.
 * That is why src/pending/func_0203F540.c is capped at MATCH: every
 * sole-ref sub-kind asks in_data_section() first, and that predicate works
 * at word granularity, so a 2-aligned data start is refused before the
 * ROM-word check is reached. */
extern u16 tbl_020A08B6[];   /* src/pending/func_0203F540.c */

/* The fixed-point sine/cosine table: a flat signed-halfword array of
 * interleaved pairs, 4096 entries, indexed 2*i (sine) and 2*i+1 (cosine).
 * A `struct { s16 a, b; }` spelling is NOT the same code
 * (docs/notes/pkt_0203F540.c.txt). */
extern s16 tbl_020A1B38[];   /* src/matched/func_0203F684.c */

/* ------------------------------------------------------------------ *
 * 3.  FIXED-POINT VECTORS
 *
 * The SDK's VecFx32, used by the geometry tail.  Declared here because
 * func_0203F7C4 builds five of them on its own stack.
 * ------------------------------------------------------------------ */
struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
};

/* ------------------------------------------------------------------ *
 * PROTOTYPES.  Parameter types are the ones the byte evidence pins, and the
 * evidencing file is named for each.
 * ------------------------------------------------------------------ */

/* --- the random-number generator --- */
void func_0203EF5C(u32 heapId);
                        /* 0x0203EF5C  src/matched/func_0203EF5C.c: the
                         * constructor.  The allocation tag 49 stays live in
                         * r5 afterwards and BOTH later constants (625 and
                         * 4129) are derived from it with a single `add`,
                         * which is why neither costs a pool word. */
u32  func_0203F0A8(void);
                        /* 0x0203F0A8  DIFF, docs/notes/func_0203F0A8.c.txt:
                         * MT19937 genrand_int32 with the regeneration
                         * inlined.  Returns u32. */
void func_0203F034(u32 seed);
                        /* 0x0203F034  src/matched/func_0203F034.c:
                         * init_genrand.  Every step re-reads both the global
                         * pointer and the index out of memory, so the index
                         * is a real field and not a local. */
void func_0203F1FC(const u8 *src, u32 len);
                        /* 0x0203F1FC  src/matched/func_0203F1FC.c: push
                         * bytes into the entropy buffer; a length below two
                         * is padded to two through a stack pair. */

/* --- the small string/byte helpers --- */
s32  func_0203EFC8(const u8 *a, const u8 *b, u32 n);
                        /* 0x0203EFC8  src/matched/func_0203EFC8.c: memcmp
                         * over UNSIGNED bytes.  The count is tested and
                         * decremented in ONE expression, `n-- != 0`, which is
                         * what puts the `sub` between the `cmp` and the
                         * branch. */
u32  func_0203F004(const u8 *s);
                        /* 0x0203F004  src/matched/func_0203F004.c: strlen
                         * over unsigned char.  Written as an unconditional
                         * loop with the test and the return inside it. */
int  func_0203F028(const char *s1, const char *s2);
                        /* 0x0203F028  src/matched/func_0203F028.c: a
                         * one-line forward to STD_CompareString at
                         * 0x0208CD94 (reached through the 12-byte ARM
                         * long-branch veneer at 0x0203F028 itself). */

/* --- hashing, checksum and the LCG --- */
struct Lcg64 {
    u64 x;            /* +0x00  the state, seeded from an 8-byte digest */
    u64 mul;          /* +0x08  0x5D588B656C078965 */
    u64 add;          /* +0x10  0x269EC3 */
};
void func_0203F258(struct Lcg64 *out);
                        /* 0x0203F258  src/matched/func_0203F258.c (EXACT,
                         * wave 12): hashes fresh entropy into an 8-byte
                         * digest and seeds a 64-bit LCG with it.  The record
                         * is THREE u64s: written as six u32 stores the two
                         * constant pairs colour r1/r0 the wrong way round. */
u32  func_0203F2FC(const u8 *p, u32 len);
                        /* 0x0203F2FC  src/matched/func_0203F2FC.c: additive
                         * byte checksum.  The accumulator is declared BEFORE
                         * the index, so it takes r3 and the index is
                         * rematerialised from it. */
void func_0203F328(u16 *p, u32 size, u32 seed);
                        /* 0x0203F328  src/matched/func_0203F328.c: XOR a
                         * halfword buffer against the LCG stream.  `size` is
                         * in BYTES and the loop runs size >> 1 times.  The
                         * function really starts at 0x0203F328, not the
                         * 0x0203F32C disasm.py labels: the first word is the
                         * `push {r0,r1,r2,r3}` home area that taking &seed
                         * forces.
                         * (docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) */
u16  func_0203F388(u32 *seed);
                        /* 0x0203F388  src/matched/func_0203F388.c: the
                         * standard 32-bit LCG, multiplier 0x41c64e6d and
                         * increment 0x6073, returning the TOP halfword.
                         * 0x6073 is not an ARM rotated immediate, so the
                         * increment is two `add`s. */

/* --- the real-time clock service --- */
void func_0203F3B4(void);
                        /* 0x0203F3B4  src/matched/func_0203F3B4.c: reset.
                         * The three explicit word stores after the memset
                         * are REDUNDANT and are in the source anyway. */
void func_0203F3F0(void);
                        /* 0x0203F3F0  src/matched/func_0203F3F0.c: the
                         * per-frame tick; every eleventh frame re-runs the
                         * read. */
void func_0203F42C(u32 result, struct RtcRequest *req);
                        /* 0x0203F42C  src/matched/func_0203F42C.c: the
                         * completion callback.  Its address reaches the image
                         * ONLY as the pool word at 0x0203F498 inside
                         * func_0203F46C, never as a branch target. */
void func_0203F46C(struct RtcRequest *req);
                        /* 0x0203F46C  src/matched/func_0203F46C.c: start the
                         * asynchronous read into the staging pair. */
void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
                        /* 0x0203F49C  src/matched/func_0203F49C.c: copy both
                         * cached values out.  Four words and three words, so
                         * two ldm/stm pairs, which is why the two out
                         * pointers have to be parked in lr and ip. */
void func_0203F4CC(struct RtcTime *time);
                        /* 0x0203F4CC  src/matched/func_0203F4CC.c */
void func_0203F4E4(struct RtcDate *date);
                        /* 0x0203F4E4  src/matched/func_0203F4E4.c */
u32  func_0203F4FC(void);
                        /* 0x0203F4FC  src/matched/func_0203F4FC.c: seconds
                         * since midnight.  The sum is spelled
                         * minutes-before-hours, `m * 60 + h * 3600`, and that
                         * order is what makes the hours term the `mul` and
                         * the minutes term the `mla`.  The global is read as
                         * a BARE CAST CONSTANT, (u32 *)0x2146A1C, with no
                         * relocation at all. */
void func_0203F524(void);
                        /* 0x0203F524  src/matched/func_0203F524.c: refresh
                         * both cached values.  A tail call, so the callee's
                         * address is a pool word and the transfer is `bx ip`
                         * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). */
s32  func_0203F540(struct RtcDate *d);
                        /* 0x0203F540  MATCH, src/pending/func_0203F540.c:
                         * day of year.  Every concrete byte reproduces; the
                         * file is capped for lack of a witness for the
                         * halfword-aligned table at 0x020A08B6.  See that
                         * file's header for the full attestation analysis. */

/* --- fixed-point geometry --- */
s16  func_0203F684(s32 x);
                        /* 0x0203F684  src/matched/func_0203F684.c: sine.
                         * `x` is SIGNED (the unsigned spelling compiles to
                         * `umull` against a different magic and is a
                         * whole-function diff) and the trailing scale is the
                         * SHIFT `>> 4`, not `/ 16`. */
s16  func_0203F6D8(s32 x);
                        /* 0x0203F6D8  src/matched/func_0203F6D8.c: cosine,
                         * the odd-halfword twin at index 2*i + 1. */
int  func_0203F768(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
                        /* 0x0203F768  src/matched/func_0203F768.c: the
                         * six-argument forwarder to func_0203F7C4, dividing
                         * the result by a 20.12 product of a6 with 0x323d. */
s32  func_0203F7C4(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy);
                        /* 0x0203F7C4  src/matched/func_0203F7C4.c (EXACT,
                         * wave 12; the sign test is f.x + f.y + f.z):
                         * the SIGNED distance from point C to the line
                         * through A and B, all six coordinates arriving as
                         * plain integers and shifted into 20.12 on entry.
                         * The sign is the 2D cross product's, and the last
                         * two parameters arrive on the stack at sp+0x58 and
                         * sp+0x5c. */

/* --- the SDK and runtime routines this unit calls --- */
void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                   u16 tag);                       /* 0x02030734 */
void  func_020819B8(void *buf, u32 tag);           /* 0x020819B8 */
void  func_02081B8C(void *buf, const u8 *src, u32 len);
                                                   /* 0x02081B8C */
void  func_02082BCC(void *dst, u32 value, u32 size);
                                                   /* 0x02082BCC  memset */
void  func_02088788(void);                         /* 0x02088788 */
u32   func_02088944(struct RtcDate *date, struct RtcTime *time,
                    void (*done)(u32, struct RtcRequest *),
                    struct RtcRequest *arg);       /* 0x02088944 */
void  func_02088F58(struct RtcDate *d);            /* 0x02088F58 */
void  func_02089004(struct RtcDate *date, struct RtcTime *time);
                                                   /* 0x02089004 */
int   STD_CompareString(const char *s1, const char *s2);
                                                   /* 0x0208CD94 */
int   _s32_div_f(int n, int d);                    /* 0x0209C0A4  runtime */

/* The SDK vector routines the geometry tail calls.  VEC_Subtract computes
 * a - b into out (verified by reading 0x0207CA00 itself); the other two are
 * pinned by src/matched/func_0205429C.c and src/matched/unit_0205841C.c. */
void  VEC_Subtract(const struct VecFx32 *a, const struct VecFx32 *b,
                   struct VecFx32 *out);           /* 0x0207CA00 */
fx32  VEC_DotProduct(const struct VecFx32 *a, const struct VecFx32 *b);
                                                   /* 0x0207CA68 */
void  VEC_Normalize(const struct VecFx32 *a, struct VecFx32 *out);
                                                   /* 0x0207CCA4 */

#endif /* GF_STANDARD_H */
