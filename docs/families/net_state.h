/*
 * docs/families/net_state.h -- shared declarations for the net_state.c
 * family (0x0203AD8C..0x0203CB34 in the ARM9 image), the network STATE
 * MACHINE that sits on top of net_system.c (0x02037288..0x020395E0, see
 * docs/families/net_system.h) and net_handle.c (0x020395EC..0x0203A458, see
 * docs/families/net_handle.h).  Edges are fuzzy by a function or two at both
 * ends: the reporting helper func_0203AD80 and the small run at
 * 0x0203AD74..0x0203AD8C ahead of it already belong to this unit, and the
 * packet's tail past 0x0203CB34 continues into the session teardown code.
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

#ifndef NET_STATE_H
#define NET_STATE_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed short       s16;
typedef signed int         s32;
typedef unsigned long long u64;

/* ------------------------------------------------------------------ *
 * THE THREE ACCESSORS EVERY FUNCTION IN THE FAMILY OPENS WITH.
 *
 * This family never reaches its state through a global directly (the one
 * exception is g_021469DC below).  It calls one of three getters, all of
 * them in the neighbouring 0x0203D--- block and all of them ARM:
 *
 *   func_0203D788()  the SESSION object.  By far the most referenced
 *                    symbol in the family (label x371).  Everything that
 *                    dispatches through the vtable goes through it:
 *                    func_0203AF40, func_0203B390, func_0203B5D4.
 *   func_0203D798()  the CURRENT-PEER record.  func_0203AF40 reads its
 *                    +0x65 state byte and +0x56 key; func_0203B5D4 reads
 *                    the same +0x56.
 *   func_0203D788()'s +0x340 is the vtable; see struct NetSession.
 *
 * The matched sources type these three every way C allows (`void *`,
 * `u8 *`, `int *`, `struct Singleton *`).  Nothing in the byte evidence
 * distinguishes them, because every use immediately casts; the shapes below
 * are the ones that make the field offsets readable.
 * ------------------------------------------------------------------ */
struct NetSession *func_0203D788(void);   /* 0x0203D788 */
struct NetPeer    *func_0203D798(void);   /* 0x0203D798 */
u32                func_0203D650(void);   /* 0x0203D650  the value handed to
                                           * a completion callback; see
                                           * THE CALLBACK ARITY RULE */
void               func_0203D700(void);   /* 0x0203D700 */

/* ------------------------------------------------------------------ *
 * THE ONE GLOBAL: 0x021469DC.
 *
 * The reporting context, passed as func_0203AD80's first argument by every
 * function in the family that reports.  It is spelt g_021469DC in every
 * matched source and typed u32, int or u8 pointer interchangeably; only its
 * address is constrained.  It resolves `literal x232`, so it is never an
 * attestation problem.
 *
 * NOTE it is NOT 0x021469D0, net_system.c's system-record pointer (see
 * docs/families/net_system.h).  The two are three words apart and are
 * different objects; do not merge them.
 * ------------------------------------------------------------------ */
extern u32 g_021469DC;      /* 0x021469DC */

/* ------------------------------------------------------------------ *
 * THE REPORTING CALL.
 *
 * func_0203AD80(context, tag, value, line) is this family's assert/report
 * sink and appears at the tail of most state transitions.  Label x244+.
 *
 *   context   always g_021469DC.
 *   tag       A CODE ADDRESS, not a string.  See THE REPORT TAG RULE.
 *   value     usually 0, sometimes a computed result (func_0203B390 passes
 *             func_0203B2FC(p) and func_0203B344(p)).
 *   line      a source line number, and the numbers are consistent with one
 *             single file: 0x12F (func_0203AF40), 0x169 (func_0203B038),
 *             0x245/0x24A (func_0203B390), 0x297/0x2A6 (func_0203B52C),
 *             0x2C1/0x2D3 (func_0203B5D4).  That monotone spread over
 *             ~0x2E0 lines across the whole address range is the best
 *             evidence that 0x0203AD8C..0x0203CB34 really is ONE .c file.
 * ------------------------------------------------------------------ */
void func_0203AD80(u32 context, void *tag, u32 value, u32 line);  /* 0x0203AD80 */

/* ------------------------------------------------------------------ *
 * THE REPORT TAG RULE.  *** READ THIS BEFORE DECLARING ANY SITE ***
 *
 * func_0203AD80's second argument is the address of a FUNCTION, not a
 * module-name string.  Three separate parked files in this family were
 * blocked at MATCH for months because their headers declared these sites
 * `data` with names like `str_0203B4DC`, concluded no evidence class could
 * attest them, and wrote that conclusion into the header as fact.  Two of
 * the three were simply wrong.  Declared `arm` and passed as `(void *)`:
 *
 *   0x0203B4DC  in func_0203B52C  -> `matched x1` (func_0203B4DC is EXACT)
 *   0x0203B52C  in func_0203B5D4  -> `sole-ref x1` (sole-ref/code: the
 *                                    address is exactly a traced ARM
 *                                    function start, which needs no outside
 *                                    branch).  This promoted the file.
 *   0x0203C00C  in func_0203AF40  -> `literal x20`
 *   0x0203B950  in func_0203B390  -> `literal x8`
 *   0x0203B48C  in func_0203B5D4  -> `literal x8`
 *
 * So: when a site in this family is an ABS32 whose target lands in the
 * 0x0203----  code range, declare it `arm` and cast at the call.  Only then
 * ask whether it has a witness.
 *
 * THE TWO "GENUINE EXCEPTIONS" THIS HEADER USED TO LIST ARE BOTH CLOSED
 * (wave 14, 2026-09-23):
 *   0x0203B018  the 4-byte `bx lr` no-op func_0203B038 passes.  Now filed
 *               with the unlabelled leaf after it as
 *               src/matched/unit_0203B018.c (func_0203B018 + func_0203B01C),
 *               so `matched` attests it.
 *   0x0203B40C  was a MISREAD.  func_0203B52C's second tag word (pool
 *               0x0203B5CC) is 0x0203C00C, not 0x0203B40C; it resolves
 *               `literal` and func_0203B52C is EXACT.  Read pool words from
 *               the bytes (`match.py show`), never from an old header.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE CALLBACK ARITY RULE.  *** THE FAMILY'S MOST EXPENSIVE IDIOM ***
 *
 * Completion callbacks in net_state.c TAKE AN ARGUMENT.  Declaring one
 * `void (*)(void)` is the single most costly mistake available here,
 * because it does not change the size and does not change any instruction:
 * it changes ONE REGISTER, and so it presents as a tiny, irreducible-looking
 * 2-3 byte allocation tie that survives thousands of permuter compiles.
 *
 * The tell in the disassembly:
 *
 *     ldr rN, [base, #off]
 *     cmp rN, #0
 *     blx rN              <-- if N is NOT r0, the callback takes an argument
 *
 * A void-arity call lets the allocator load the pointer into r0 (lowest
 * legal colour, base dead after the load).  Giving the callback a parameter
 * pins r0 to the ARGUMENT, which forces the pointer up into r1.  The thing
 * passed is whatever r0 already holds at that point:
 *
 *   func_0203B1D8   `void (*f08)(u32)`, called `s->f08((u32)s)` -- the
 *                   system object itself.  Closed a 3-byte residue that
 *                   docs/notes/pkt_0203B1D8.c.txt had written off as an
 *                   unbreakable Chaitin tie; 776 distinct permuter compiles
 *                   had scored perfectly flat on it.
 *   func_0203AF40   `void (*f2c)(u32)`, called `p->f2c(func_0203D650())` --
 *                   the result of the call immediately before it, which
 *                   looks discarded and is not.  Closed a 2-byte residue
 *                   that docs/notes/pkt_0203AF40.c.txt had written off as an
 *                   r4/r5 swap; 1020 permuter compiles flat.
 *   func_0203B52C   same shape, recorded in prose in that file's header
 *                   ("takes func_0203D650's return value in r0, which is why
 *                   the function pointer is loaded into r1").
 *
 * WHY NO SEARCH FINDS THIS: every tools/permuter.py mutation except `type`
 * is value-preserving, and `type` changes the integer type of a local or
 * parameter, never a function pointer's SIGNATURE.  A flat anneal proves
 * that no rearrangement of the existing statements helps; it proves nothing
 * about whether the declarations are right.  When the permuter plateaus on a
 * small residue in this family, re-read the TYPES first.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * struct NetVtable -- the dispatch table at NetSession +0x340.
 *
 * Only the slots the matched sources actually call are named.  Every call
 * is `ldr rX, [session, #0x340] / ldr rY, [rX, #slot] / blx rY`.
 * ------------------------------------------------------------------ */
struct NetVtable {
    u8    pad_00[4];
    void (*f04)(u16 key, void *session, u32 zero, u32 arg);
                            /* +0x04  func_0203AF40's main transition: it
                             * passes the peer's +0x56 key, the session, a
                             * literal 0 and the session's own +0x34C. */
    u8    pad_08[4];
    void (*f0c)(void);      /* +0x0C  named by a matched source's comment
                             * ("the virtual at +0xC of the object at
                             * *(net context + 0x340)"). */
    u8    pad_10[0x28];
    u32  (*f38)(u32 a);     /* +0x38  func_0203B5D4's guard. */
    u8    pad_3c[0x3c];
    u32  (*f78)(void);      /* +0x78  func_0203B390's entry guard. */
};

/* ------------------------------------------------------------------ *
 * struct NetSession -- the object func_0203D788() returns.
 *
 * Large; only +0x340 and +0x34C are constrained by matched bytes.  The
 * vtable pointer at +0x340 is the same offset net_handle.c uses for the end
 * of its nine-entry slot table (0x70 + 9 * 0x50 = 0x340, see
 * docs/families/net_handle.h), which is consistent with ONE record whose
 * table is followed immediately by its dispatch pointer.
 * ------------------------------------------------------------------ */
struct NetSession {
    u8                pad_00[0x340];
    struct NetVtable *vtable;   /* +0x340  func_0203AF40, func_0203B390,
                                 * func_0203B5D4 */
    u8                pad_344[8];
    u32               f34c;     /* +0x34C  func_0203AF40 passes it as the
                                 * vtable call's fourth argument */
};

/* ------------------------------------------------------------------ *
 * struct NetPeer -- the record func_0203D798() returns.
 * ------------------------------------------------------------------ */
struct NetPeer {
    u8  pad_00[0x56];
    u16 f56;        /* +0x56  the peer key.  func_0203AF40 passes it to the
                     * vtable's +0x04 slot; func_0203B5D4 passes the same
                     * halfword to func_0203B2A8.  A HALFWORD: both sites
                     * are `ldrh`. */
    u8  pad_58[0xd];
    u8  f65;        /* +0x65  the peer's state byte.  func_0203AF40 skips
                     * its whole transition when it is 1 or 2, spelt as the
                     * conjunction `f65 != 1 && f65 != 2` so the compiler
                     * emits the `cmp / cmpne` pair the image has. */
};

/* ------------------------------------------------------------------ *
 * struct NetState -- the per-connection state record, the parameter almost
 * every function in the family takes in r0.
 *
 * Reconstructed from the fields the matched sources touch; the gaps are
 * padding of the size the byte evidence forces and nothing more.  The
 * offsets are consistent across func_0203AF40, func_0203B038,
 * func_0203B390 and func_0203B5D4.
 * ------------------------------------------------------------------ */
struct NetState {
    u8    pad_00[0x2c];
    void (*f2c)(u32 arg);   /* +0x2C  the completion callback.  See THE
                             * CALLBACK ARITY RULE.  func_0203AF40 calls it
                             * with func_0203D650()'s result and then CLEARS
                             * it (`p->f2c = 0`), so it is one-shot. */
    u8    pad_30[0x14];
    u16   f44;              /* +0x44 */
    u16   f46;              /* +0x46  a countdown.  func_0203B5D4 decrements
                             * it and returns early while it is non-zero;
                             * the leaf at 0x0203B01C bumps it by 0x3C. */
    u8    pad_48[0xb];
    u8    f53;              /* +0x53  a mode flag.  func_0203B390 takes its
                             * alternate arm when it is 0. */
    u8    pad_54[2];
    u8    f56;              /* +0x56  a second mode flag; func_0203B390's
                             * alternate arm is also taken when it is 1, and
                             * func_0203B5D4 returns early on the same
                             * value. */
    u8    f57;              /* +0x57  the start of the payload buffer.
                             * func_0203B390 passes &f57 to func_02037A6C
                             * with length 0x200; func_0203B038 passes
                             * (state + 0x40) with the same length. */
};

/* ------------------------------------------------------------------ *
 * THE 0x200 BUFFER LENGTH, AND WHY IT MUST BE A NAMED LOCAL.
 *
 * 0x200 is the transfer length everywhere in the family (func_0203B038,
 * func_0203B390, func_0203C010).  In func_0203B390 it is ALSO the base of
 * the two reported line numbers, which the image spells `add r3, r4, #0x45`
 * and `add r3, r4, #0x4a` off the same register -- 0x245 and 0x24A.
 *
 * That shared register is load-bearing.  Writing 0x200 as a literal at each
 * of its four uses does not reproduce the function: the constant must be
 * bound to ONE local declared BEFORE the guard chain, so its live range
 * spans both arms and the allocator pins it in r4.  That in turn frees r0
 * for the literal `1` to be materialised in the pre-branch block, which is
 * the `mov r0, #1` that docs/notes/pkt_0203B390.c.txt spent a whole note
 * failing to place.  With `u32 n = 0x200;` the function is EXACT on the
 * first compile.
 * ------------------------------------------------------------------ */
#define NET_XFER_LEN    0x200

/* ------------------------------------------------------------------ *
 * NEIGHBOURING CALLEES the family leans on, with the signatures the byte
 * evidence constrains.  All ARM.
 * ------------------------------------------------------------------ */
u32  func_02037A6C(u32 chan, u32 buf, u32 len, u32 callback);  /* 0x02037A6C */
u32  func_02037928(u32 a, u32 len);                            /* 0x02037928 */
void func_02037D78(void);                                      /* 0x02037D78 */
u32  func_020393A8(void);                                      /* 0x020393A8 */
u32  func_020393D0(void);                                      /* 0x020393D0 */
u32  func_020399EC(void);                                      /* 0x020399EC */
u32  func_02039ACC(void);                                      /* 0x02039ACC */
void func_0203B2A8(u32 key);                                   /* 0x0203B2A8 */
u32  func_0203B2FC(char *p);                                   /* 0x0203B2FC */
u32  func_0203B344(char *p);                                   /* 0x0203B344 */
void func_0203C934(void);                                      /* 0x0203C934 */

/* ------------------------------------------------------------------ *
 * THE RNG SEEDER at 0x0203AE20 (EXACT, src/matched/func_0203AE20.c).
 * The record it fills is the NitroSDK MATHRandContext64 {u64 x, mul, add}
 * and the tail is the SDK's MATH_InitRand64 inline; four u32 stores left
 * the 8-byte tie docs/notes/pkt_0203AE20.c.txt describes.
 *
 * Included here because its constants identify the generator and are worth
 * having in one place.  It mixes the console MAC with the RTC date/time,
 * seeds through func_0203F034, draws two 32-bit values from func_0203F0A8
 * into ONE u64 (the image's `adds`/`adc`/`stm` pair is the tell), and then
 * stores the Gen-V multiplier and increment after it.
 * ------------------------------------------------------------------ */
#define NET_RNG_MUL     0x5D588B656C078965ull  /* u64 at +0x08 */
#define NET_RNG_ADD     0x0000000000269EC3ull  /* u64 at +0x10 */

void OS_GetMacAddress(u8 *mac);       /* 0x02087C6C, six bytes */
void func_020889C0(void *date, void *time);  /* 0x020889C0, RTC read.  The
                                       * date struct has FOUR members
                                       * (year, month, day, WEEKDAY) -- with
                                       * three the frame is 0x20 and the
                                       * prologue pushes four registers, not
                                       * the image's 0x24 and five. */
void func_0203F034(u32 seed);         /* 0x0203F034 */
u32  func_0203F0A8(void);             /* 0x0203F0A8 */

#endif /* NET_STATE_H */
