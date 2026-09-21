/*
 * docs/families/net_system.h -- shared declarations for the net_system.c
 * family (0x02037288..0x020395E0 in the ARM9 image).  The __FILE__ anchor
 * these functions load is 0x020A7A24 and the companion message area starts
 * at 0x020A7A34; str_020A7A50/str_020A7A54 are the two assert texts used by
 * func_02038A90 and func_020385C4.  Edges are fuzzy by a function or two at
 * both ends: net_handle.c begins at 0x020395EC (see
 * docs/families/net_handle.h) and net_state.c at 0x0203AD8C.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field or parameter is named in the comment
 * beside it.  Where two matched sources spell the same field differently
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef NET_SYSTEM_H
#define NET_SYSTEM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE ONE GLOBAL.
 *
 * 0x021469D0 holds a POINTER to a single 0x1F0-byte system record,
 * allocated once by func_02037288 (src/matched/func_02037288.c:
 * func_02030734(heap, 0x1F0, 1, __FILE__, 0xDD)).  Every function in the
 * family reaches its state through `*(struct NetSystem **)0x021469D0`, and
 * a NULL pointer is the "not yet initialised" state that func_02037288
 * tests on entry and func_02037C10 tests before dispatching (both files).
 *
 * The matched sources spell the symbol three ways -- g_021469D0,
 * lbl_021469D0, unk_021469D0 -- and type it three ways (u8 *, u32 *,
 * struct LinkState *).  They are one object; the spelling below is the one
 * the layout constrains, a pointer to the record.
 *
 * NOTE ON DECLARED TYPE.  In func_02037288 the seven allocation-result
 * fields MUST be declared `void *`, not u32: with them u32 the file does
 * not compile, and with a cast at each site the argument scheduling shifts
 * and the file is 4 bytes out.  See that file's header.
 * ------------------------------------------------------------------ */
extern struct NetSystem *g_NetSystem;   /* 0x021469D0 */

#define NET_SYSTEM_SIZE     0x1F0   /* func_02037288's allocation size */
#define NET_SLOT_COUNT      8       /* func_02037478's and func_02037680's
                                     * bound; func_02037680 asserts i < 8
                                     * at line 0x155 before touching a slot */
#define NET_SLOT_STRIDE     0x10    /* the per-slot stride of the 0x4C,
                                     * 0x11C and 0x54 arrays; func_02037680,
                                     * func_020387A0, func_02037478 */

/* ------------------------------------------------------------------ *
 * struct NetSystem -- the 0x1F0-byte record at *0x021469D0.
 *
 * Only the fields the matched sources actually touch are named; the gaps
 * are padding of the size the byte evidence forces and nothing more.
 * ------------------------------------------------------------------ */
struct NetSystem {
    void *f00;          /* 0x00  send-id table, n3 bytes; allocated at line
                         * 0xEC, wiped and re-seeded by func_02037478, whose
                         * first byte is set to 0xFF and the rest to 0 */
    void *f04;          /* 0x04  n3 * 15 bytes, line 0xED; the 0x1C mirror */
    void *f08;          /* 0x08  n2 bytes, line 0xEE */
    void *f0C;          /* 0x0C  n2 * 2 bytes, line 0xEF; the 0x3C mirror */
    void *f10;          /* 0x10  n1 * f1E0 bytes, line 0xE9; the per-slot
                         * payload backing store.  func_02037680 and
                         * func_02037478 both address slot i at
                         * f10 + i * f1E0 */
    void *f14;          /* 0x14  f1E0 * 3 bytes, line 0xE6; the 0x2C mirror */
    void *f18;          /* 0x18  f1E0 * 2 bytes, line 0xE8 */
    u8  f1C[0x2C - 0x1C];   /* 0x1C  copy target of f04, func_02037478 */
    u8  f2C[0x3C - 0x2C];   /* 0x2C  copy target of f14, func_02037478 */
    u8  f3C[0x4C - 0x3C];   /* 0x3C  copy target of f0C, func_02037478 */
    u8  f4C[NET_SLOT_COUNT * NET_SLOT_STRIDE];
                        /* 0x4C  eight 0x10-byte per-slot payload headers.
                         * func_02037680 reinitialises slot i through
                         * func_0203640C(f4C + i * 0x10, ...); func_020387A0
                         * copies a received payload into the same slot with
                         * func_02036428 */
    /* 0x54 + i * 0x10 is the "accepted" flag INSIDE the f4C entry:
     * func_020387A0 reads it before accepting a packet and stores 1 after,
     * and the same word is read by func_02038924's own-slot variant. */
    u8  fCC[0xF4 - 0xCC];   /* 0xCC  a 0x64-entry queue; func_02037288 builds
                         * it with func_02036AF4(&fCC, 0x64, &f1C, heap) and
                         * func_02037478 resets it with func_02036B4C */
    u8  fF4[0x11C - 0xF4];  /* 0xF4  a 0xB4-entry queue; same pair of calls
                         * with &f3C as the element source */
    u8  f11C[NET_SLOT_COUNT * NET_SLOT_STRIDE];
                        /* 0x11C  eight 0x10-byte per-slot timers.
                         * func_02037680 and func_02037478 both reset slot i
                         * with func_02037234(f11C + i * 0x10) */
    u8  f19C[0x1AC - 0x19C];/* 0x19C  the own-slot timer; func_02037478
                         * resets it with the same func_02037234 */
    u32 f1AC;           /* 0x1AC  "system is up"; func_02037478 sets it to 1
                         * at the end of init and func_020385C4 tests it */
    u32 f1B0;           /* 0x1B0  the own-slot credit counter.  func_02038924
                         * decrements it per accepted packet; func_02037478
                         * zeroes it; func_02037D98 refuses to send while it
                         * is positive */
    u32 f1B4[NET_SLOT_COUNT];
                        /* 0x1B4  the per-slot credit counters, indexed by
                         * slot.  func_02037680 zeroes slot i, func_02037478
                         * zeroes all eight, func_020387A0 decrements slot i
                         * on every accepted packet */
    u8  pad1D4[0x1D7 - 0x1D4];
    u8  f1D7[NET_SLOT_COUNT];
                        /* 0x1D7  the per-slot last-sequence byte.
                         * func_020387A0 rejects a packet whose p[5] - 1 does
                         * not equal the stored value and then stores p[5];
                         * func_02037680 and func_02037478 zero it.
                         * NOTE: the compiled address of this array is
                         * reached as (base + 0xD7) + 0x100 in both
                         * func_020387A0 and func_02037478 -- the 0x1D7
                         * immediate does not fit an ARM data-processing
                         * operand, so it is split.  This is an encoding
                         * artefact, not two objects. */
    u8  f1D6;           /* 0x1D6  the own-slot sequence byte; func_02038924 */
    u8  pad1DF[0x1E0 - 0x1DF];
    u32 f1E0;           /* 0x1E0  the per-slot payload stride, set once by
                         * func_02037288 to (c ? func_02037258() : a0) + 0x40.
                         * Every slot address in the family scales by it */
    u8  pad1E4[0x1E7 - 0x1E4];
                        /* 0x1E4 is a u16 read by func_02037C10 and written
                         * as 0 by func_02037288; it is reached as
                         * (base + 0x100) + 0xE4 for the same immediate-reach
                         * reason as f1D7 */
    u8  f1E7;           /* 0x1E7  cleared by func_02037288 on every entry,
                         * including the already-initialised path */
    u8  f1E8;           /* 0x1E8  cleared by func_02037478 */
    u8  pad1E9;
    u8  f1EA;           /* 0x1EA  the "suspended" flag.  func_02037C10 bails
                         * out of the whole tick when it is non-zero */
    u8  f1EB;           /* 0x1EB  the "polling accepted" flag.  func_02037F48
                         * sets it to 1 on an accepted poll and 0 on a
                         * refused one; func_02037478 seeds it to 1 */
    u8  pad1EC;
    u8  f1ED;           /* 0x1ED  cleared by func_02037478 */
};

/* ------------------------------------------------------------------ *
 * THE TWO CONTEXT RECORDS the family borrows.
 *
 * Neither is owned here; both come from the 0x0203D7xx accessors.  Only
 * the members this family reaches are named.
 * ------------------------------------------------------------------ */
struct NetCtx {                 /* func_0203D788()'s record */
    u8   pad00[0x340];
    u32 *f340;                  /* 0x340  a vtable.  The family calls four
                                 * slots of it:
                                 *   +0x0C  void (*)(u16)  -- the tick's
                                 *          "done" callback; func_02037C10
                                 *          calls it in all three exits
                                 *   +0x58  u32  (*)(void) -- "is polling
                                 *          enabled"; func_02037F48's gate
                                 *   +0x5C  u32  (*)(u32)  -- the poll
                                 *          itself; func_02037F48 passes
                                 *          g_NetSystem->f00 and accepts
                                 *          only the answer 1
                                 *   +0x60  u32  (*)(u32)  -- per-index poll
                                 *          result; func_02037F48's loop
                                 *   +0x64  the send entry; func_020385C4
                                 *   +0x70  u32  (*)(void); func_02037E60
                                 *   +0x84  void (*)(void) -- an optional
                                 *          pre-tick hook; func_02037C10
                                 *          calls it only when non-NULL and
                                 *          follows it with func_020370F4 */
};

struct NetMode {                /* func_0203D798()'s record */
    u8 pad00[0x64];
    u8 f64;                     /* 0x64  "is host".  func_02037C10 and
                                 * func_020385C4 both branch on it */
    u8 f65;                     /* 0x65  the link mode.  func_02037C10
                                 * dispatches on it:
                                 *   0 or 5 (with f64 == 0) -> func_02037F48
                                 *   (u8)(f65 + 0xFD) <= 1, i.e. 3 or 4
                                 *                          -> func_0203802C
                                 *   (u8)(f65 + 0xFF) <= 1, i.e. 1 or 2
                                 *                          -> func_02038298
                                 *   anything else -> the full host path
                                 * and skips the +0x0C callback for 1 and 2 */
};

/* ------------------------------------------------------------------ *
 * PROTOTYPES.
 *
 * Exact parameter types, as the matched sources constrain them.  A
 * prototype that a matched source contradicts is called out in the
 * comment; the family has three such disagreements, all of them the same
 * kind -- a caller declared a callee with narrower or fewer parameters
 * than the callee's own EXACT file needs.
 * ------------------------------------------------------------------ */

/* Initialisation and teardown. */
int  func_02037288(u32 a0, u32 heap, u32 c);
        /* src/matched/func_02037288.c.  RETURNS int, not void: the tail's
         * `mov r0, #1` is a `return 1` and without it the file is 38 bytes
         * out.  src/matched/func_02037700.c declares it
         * `void func_02037288(u32, u32, u32)` and other callers declare the
         * first two parameters u16; both are WRONG -- the original passes
         * `mov r0, r8` with no narrowing at any of the nine allocation
         * sites.  Those callers are EXACT anyway because the declaration
         * only affects their own argument setup, which happens to agree. */
void func_02037478(void);
        /* the second half of init: wipes and re-seeds every buffer
         * func_02037288 allocated.  Not yet EXACT -- see the appended
         * section of docs/notes/pkt_02037288_wave25.c.txt (size-exact at
         * 520 bytes, 135 bytes of colouring residue). */
void func_02037680(int i);
        /* resets ONE slot.  The parameter is signed: the entry guard is
         * `cmp r5, #8; blt`, a signed compare, and the assert at line 0x155
         * fires for i >= 8 only.  Not yet EXACT -- 8 bytes of colouring
         * residue, same note. */

/* The tick. */
int  func_02037C10(void);
        /* src/matched/func_02037C10.c.  The dispatcher; see struct NetMode
         * above for the f65 decision table. */
void func_02037F48(void);
        /* src/matched/func_02037F48.c.  The polling pass. */

/* Packet receive. */
int  func_020387A0(u32 i, u8 *p, s32 n);
        /* src/matched/func_020387A0.c.  The per-slot variant. */
int  func_02038924(u32 a0, u8 *p, s32 n);
        /* src/matched/func_02038924.c.  The own-slot twin; identical
         * shape without the i-scaling and without the 0x1D7 sequence
         * check.  Read the two side by side. */

/* Packet send. */
int  func_02037D98(int a);
        /* src/matched/func_02037D98.c.  Refuses while f1B0 > 0. */

/* ------------------------------------------------------------------ *
 * CALLEES OUTSIDE THE FAMILY, with the types the family's EXACT files
 * constrain.  Two of these have a per-SITE arity, which is the single
 * most expensive thing to get wrong in this family.
 * ------------------------------------------------------------------ */

void func_0203640C(u8 *dst, u8 *src, u32 n);
        /* PER-SITE ARITY.  The callee is
         *   lsl r2, r2, #0x10 ; asr r2, r2, #0x10 ; stm r0, {r1, r2}
         *   mov r3, #0 ; strh r3, [r0, #0xc] ; strh r3, [r0, #0xe]
         * so it always READS r2, but the ORIGINAL C calls it with only two
         * arguments at some sites and lets r2 fall through as whatever the
         * preceding `mla` left there.  func_02037680's single call and
         * func_02037478's first-loop call are two-argument; the other four
         * calls in func_02037478 are three-argument.  One translation unit
         * cannot declare both, so the two-argument form is written through
         * a cast:
         *   ((void (*)(u8 *, u8 *))func_0203640C)(dst, src)
         * Passing an explicit third argument at a two-argument site costs a
         * `mov r2, ...` and makes the file four bytes long. */
void func_02034714(const u8 *file, int line, const u8 *msg);
        /* the assert.  file is str_020A7A24 throughout this family; msg is
         * str_020A7A34 (func_02037680, line 0x155), str_020A7A50
         * (func_02038A90, line 0x5D8) or str_020A7A54 (func_020385C4,
         * line 0x4D5). */
void *func_02030734(u32 heap, u32 size, u32 align, char *file, u32 line);
        /* the allocator.  The first parameter is u32 HERE, not u16: the
         * original passes `mov r0, r8` with no narrowing at any of
         * func_02037288's nine sites, unlike src/matched/func_0203174C.c
         * where an lsl/lsr pair appears per call. */
void func_02082BCC(u8 *p, u32 v, u32 n);          /* memset */
void func_02036428(u8 *dst, u8 *src, s32 len);    /* bounded copy */
void func_02036AF4(u8 *p, u32 n, u8 *elems, u32 heap);  /* queue build */
void func_02036B4C(u8 *p);                        /* queue reset */
void func_02037234(u8 *p);                        /* slot-timer reset */
void func_02037224(u32 state, u32 line);          /* state transition */
s32  func_0203D680(void);   /* the slot count; SIGNED -- func_02037F48's
                             * `pople` on `cmp r5, #0` and its `blt` loop
                             * test are both signed */
s32  func_02037258(void);   /* the own payload size */
s32  func_0203D6BC(void);   /* the id count */
int  func_0203F1FC(u8 *p, s32 n);                 /* checksum */
void func_02039548(void);                         /* error latch */
u8  *func_0203CA98(void);                         /* error record */
void func_0203C9AC(u32 a, u32 b, u32 c, u32 line);/* error report */
struct NetCtx  *func_0203D788(void);
struct NetMode *func_0203D798(void);

/* ------------------------------------------------------------------ *
 * THE 0x020A7A20 STATUS BYTES.
 *
 * A small data object, not part of the record.  Byte 0 is the send state
 * (func_020385C4 tests it for 4 and 1) and byte 1 is the tick state:
 * func_02037478 seeds it to 4, func_02037D98 clears it to 0 after a
 * successful send, and func_02037F48 sets it back to 4 on an accepted poll.
 * The same address is also the family's __FILE__ anchor neighbourhood --
 * str_020A7A24 is four bytes past it.
 * ------------------------------------------------------------------ */
extern u8 g_020A7A20[];     /* 0x020A7A20 */
extern const u8 str_020A7A24[];  /* 0x020A7A24  "net_system.c" */
extern const u8 str_020A7A34[];  /* 0x020A7A34  func_02037680's assert text */
extern const u8 str_020A7A50[];  /* 0x020A7A50  func_02038A90's */
extern const u8 str_020A7A54[];  /* 0x020A7A54  func_020385C4's */

#endif /* NET_SYSTEM_H */
