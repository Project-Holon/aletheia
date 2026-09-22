/*
 * docs/families/wipe_sub.h -- shared declarations for the wipe_sub.c family
 * (0x020229A4..0x02023FD8 in the ARM9 image: the screen-wipe and blend
 * transition effects).  The __FILE__ anchor at 0x020A7450 is what all four
 * constructors in the range load (func_020229A4 line 0x09AC, func_02023464
 * line 0xC7C, func_020238B4 line 0x1354, func_020235F0 line 0x0D63), which
 * is the evidence that they are one translation unit; the line numbers run
 * 0x09AC..0x1354 in address order with no gaps large enough for another
 * file, so the unit's extent is the packet's.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT or EXACT*, and
 * the matched function that evidences each field or parameter is named in
 * the comment beside it.  Where two matched sources spell the same field
 * differently (they were written by different lanes) the spelling recorded
 * here is the one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef WIPE_SUB_H
#define WIPE_SUB_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE TASK BLOCK.  The family runs four independent wipe effects, and
 * every one of them is driven by the same two-function pair over the
 * same task block: a constructor that allocates the effect's own object
 * into the task's +0x14 slot, and a per-frame step that advances a phase
 * counter at +0x0c.  The four pairs are
 *
 *   constructor       step              object    evidenced by
 *   func_020229A4     func_02022A44     0x24      both EXACT
 *   func_02023464     func_020234C0     0x4c      step EXACT*
 *   func_020238B4     func_0202390C     0x334     both EXACT/EXACT*
 *   func_020235F0     func_0202363C     0x38      both EXACT (matched
 *                                                 before this wave)
 *
 * Only the first six words are used identically by all four; the tail
 * from +0x18 on is per-effect and is described with each constructor.
 * ------------------------------------------------------------------ */
struct WipeTask {
    u32   f00;      /* +0x00  unread by anything in the family */
    u32   f04;      /* +0x04  handed to the object as its first word;
                     *        func_020229A4 stores it to obj+0x00 and also
                     *        passes it as func_0202290C's third argument,
                     *        which is what fixes it as a word and not a
                     *        pair of halfwords. */
    u32   f08;      /* +0x08  second object word (func_020229A4 obj+0x04,
                     *        func_02023768 reads it back at +0x08). */
    u32   phase;    /* +0x0c  THE PHASE COUNTER, and the family's spine.
                     *        Every constructor ends `t->phase += 1` and
                     *        every step switches on it.  It is a full
                     *        word: func_02022A44 loads it with `ldr` and
                     *        compares against 1, 2 and 3 with `cmp #imm`,
                     *        so it is neither a byte nor a halfword. */
    u32   f10;      /* +0x10  the effect's colour/target word; passed to
                     *        func_020222CC by func_020229A4 and to
                     *        func_02022DCC as the third argument by
                     *        func_020234C0 and func_0202390C. */
    void *obj;      /* +0x14  the allocated sub-object, cleared to 0 by
                     *        phase 2 of every step function.  Declared
                     *        `struct Obj *` in func_02022A44 and
                     *        func_0202390C where the step dereferences it,
                     *        plain `void *` in func_020234C0 where it only
                     *        forwards it. */
    u32   f18;      /* +0x18  func_02023464 and func_020238B4 pass it on;
                     *        func_020234C0 hands it to func_02022DCC. */
    u32   f1c;      /* +0x1c  func_020238B4 only. */
    u32   f20;      /* +0x20  THE HEAP ID, and it is a u16 in a u32 slot:
                     *        every constructor spells the argument
                     *        `(u16)t->f20` and the `lsls #0x10 / lsrs
                     *        #0x10` pair that produces is in all four
                     *        (func_020229A4 +0x0e, func_020238B4 +0x08,
                     *        func_02023464, func_020235F0).  Writing the
                     *        field itself as u16 does NOT reproduce it:
                     *        the load is `ldr`, not `ldrh`. */
    u16   f24;      /* +0x24  func_020229A4 only, read with `ldrh` and
                     *        compared against 0x7FFF.  See the sentinel
                     *        note below. */
};

/* 0x7FFF in WipeTask.f24 is a "no explicit extent" sentinel, not a
 * coordinate: func_020229A4 tests for it before choosing which of its four
 * start/end pairs to use.  Evidenced by the pool word at 0x02022A3C and
 * the `cmp r1, r0` against it at 0x020229D4/0x020229E2. */
#define WIPE_EXTENT_NONE  0x7FFF

/* ------------------------------------------------------------------ *
 * THE PHASE PROTOCOL.  Every step function in the family has the same
 * four-arm switch and the same return convention, and two spellings in it
 * are load-bearing.  func_0202363C (matched before this wave) is the
 * reference; func_02022A44, func_020234C0 and func_0202390C were all two
 * bytes out until they were written to match it.
 *
 *   u32 step(struct WipeTask *t) {
 *       obj = t->obj;  ret = 0;             <- ret FIRST, then obj, or
 *                                              every arm duplicates its
 *                                              own return
 *       switch (t->phase) {
 *       case 1:  if (poll(obj) == 1) { ...; t->phase += 1; }  break;
 *       case 2:  release(obj); free(t->obj); t->phase += 1;
 *                t->obj = 0;  ret = 1;      <- SEMANTICALLY DEAD, load-
 *                                              bearing: see below
 *                break;
 *       case 3:  ret = 1;  break;
 *       default: break;
 *       }
 *       return ret;
 *   }
 *
 * The `ret = 1` in case 2 is what makes case 2's `break` compile to a
 * branch onto case 3's own `movs r4, #1` rather than onto the shared
 * tail: the compiler cross-jumps the two identical assignments and case
 * 2's exit lands on the surviving copy.  Without it the function is right
 * in every other byte and that one branch displacement is two too large.
 * Nothing else reaches it -- on func_02022A44, 131 single mutations and
 * 3000 annealing compiles of tools/permuter.py left the residue untouched,
 * because it is a cross-jumping decision rather than an allocation one,
 * and goto-into-case-3, a reordered case set, default-before-case-3, an
 * if/else-if chain and an added empty case are all the same two bytes out
 * or worse.  The caller cannot observe the difference (phase 3 answers 1
 * on the next frame anyway), so this is a fact about the original source,
 * not about the effect.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE 0x334-BYTE SCANLINE OBJECT (func_020238B4 / func_0202390C /
 * func_02023964 / func_02023A50 / func_0202384C).  The largest of the
 * four effect objects and the only one with per-scanline tables.
 * ------------------------------------------------------------------ */
struct WipeScan {
    u8  pad000[0x300];
    s16 left[0xC0];    /* +0x300  per-scanline left edge, 0xC0 rows, one
                        *         per screen line.  func_0202384C writes
                        *         both arrays with `strh` and reads them
                        *         back with `ldrsh`, and ldrsh only exists
                        *         in the register-offset form, which is
                        *         the evidence that these are SIGNED
                        *         (docs/idioms/ldrsh-register-offset-is-
                        *         signedness.md). */
    s16 right[0xC0];   /* +0x480  per-scanline right edge, same shape. */
    u8  pad600[0x314 - 0x600];
    s32 step_bound;    /* +0x314  a FLOOR, not a ceiling: func_02023A50
                        *         retires the object while step+1 is <=
                        *         this and keeps redrawing once it is
                        *         past.  The comparison is the function's
                        *         only real decision and getting it
                        *         backwards is exactly one wrong byte. */
    s32 step;          /* +0x318 */
    s32 frame_limit;   /* +0x31c */
    s32 frame;         /* +0x320  ticked every call, cleared on expiry. */
    s32 f324;          /* +0x324  func_0202390C hands it to func_02022DCC
                        *         as the first argument. */
    s32 f328;          /* +0x328  func_02023A50 passes it to func_02022F24
                        *         as the third argument. */
    s32 f32c;          /* +0x32c  func_0202390C's second func_02022DCC
                        *         argument. */
    s32 f330;          /* +0x330  func_02023A50's func_02022F24 first
                        *         argument. */
};

/* Every field of WipeScan from +0x314 on is past every Thumb immediate
 * reach, so the whole group is addressed off ONE register offset that the
 * compiler bumps per access (movs #0x32 / lsls #4 = 0x320, then -4, -8,
 * -0xc, +0x10).  Declaring them as members of one struct is what keeps
 * that single base; four separate far offsets would each cost a pool word
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  The same applies
 * to the two scanline arrays, which are rematerialised per access as
 * movs #3 / lsls #8 and movs #0x12 / lsls #6. */

/* ------------------------------------------------------------------ *
 * THE COUNTDOWN OBJECT (func_02023464 / func_020234C0 / func_0202350C /
 * func_02023768).  0x4c bytes; drives a fixed number of steps and
 * re-arms its own callback each frame.
 * ------------------------------------------------------------------ */
struct WipeCount {
    u32 f00;           /* +0x00 */
    u32 f04;           /* +0x04 */
    u32 f08;           /* +0x08  func_02023768's func_02022568 second
                        *        argument. */
    s32 f0c;           /* +0x0c  the running offset, advanced by f18 on
                        *        every step that keeps going. */
    u32 f10;
    u32 f14;
    s32 f18;           /* +0x18  the per-step stride added to f0c. */
    s32 left;          /* +0x1c  THE COUNTDOWN.  func_02023768 decrements
                        *        it into a LOCAL and stores back only on
                        *        the arm that continues:
                        *          n = w->left - 1;
                        *          if (n > 0) { w->left = n; ... }
                        *        Written as `w->left -= 1` followed by a
                        *        test of the field, the store lands before
                        *        the branch and the ldr/subs/cmp triple
                        *        becomes four instructions. */
    s32 frame_limit;   /* +0x20 */
    s32 frame;         /* +0x24 */
    u32 f28;           /* +0x28  func_02022568's third argument. */
    u32 f2c;
    u32 f30;           /* +0x30  func_02023464 passes it to func_02022E88. */
    u32 f34;           /* +0x34  func_02022568's first argument. */
    u8  pad38[0x44 - 0x38];
    u32 f44;           /* +0x44  func_020234C0 hands it to func_02022DCC;
                        *        func_0202350C stores cfg[0x0b] here and
                        *        reads it back as the tenth argument of
                        *        func_02022E20, which is what proves it is
                        *        one field and not two. */
    u32 f48;           /* +0x48 */
};

/* ------------------------------------------------------------------ *
 * THE INTERPOLATION RECORD (func_02023E9C / func_02023EF4 / func_02023E0C
 * / func_02023F60 / func_02023F98).  0x20 bytes, one per hardware engine,
 * and the only part of the family that is NOT heap-allocated: the two
 * records live at fixed addresses.  Reproduced verbatim from
 * src/matched/func_02023E9C.c, which is where every field role was
 * isolated against the bytes.
 * ------------------------------------------------------------------ */
struct Interp {
    u32 f00;           /* +0x00  the caller's tag, widened from a u8. */
    u32 f04;           /* +0x04  the engine bit (1 or 2). */
    u16 f08;           /* +0x08  step count. */
    u16 f0a;           /* +0x0a  from. */
    u16 f0c;
    u16 f0e;
    signed char f10;   /* +0x10  the sign, +1 or -1. */
    u8  f11;
    s16 f12;           /* +0x12  |to - from|. */
    s16 f14;           /* +0x14  per-step delta (the quotient). */
    s16 f16;           /* +0x16  its remainder. */
    u16 f18;           /* +0x18  the running accumulator. */
    s16 f1a;           /* +0x1a  to. */
    u32 f1c;           /* +0x1c  the active flag, set FIRST by
                        *        func_02023E9C -- written anywhere later
                        *        the whole entry block changes register
                        *        bank. */
};

/* The two records and the flag word they share.  These are the addresses
 * the pool words at 0x02023F54/0x02023F5C (func_02023EF4) and
 * 0x02023FCC/0x02023FD0/0x02023FD4 (func_02023F98) name; both are
 * attested `literal` with six and nine witnesses image-wide.
 *
 * 0x021468FC IS NAMED BY TWO DISTINCT SOURCE SYMBOLS, and that is not a
 * cosmetic point: mwccarm emits one pool word per source SYMBOL in order
 * of first use, so func_02023F98's three-slot pool (0x0214691C,
 * 0x021468FC, 0x021468FC) can only be reproduced by two separate externs
 * at 0x021468FC -- one that both engines' flag stores reach, one that the
 * sub engine's memset base names.  Spelling it as a single object CSEs
 * the two references into one slot and the function comes out with the
 * third slot holding 0x0214691C instead: 64 bytes, every instruction
 * right, two bytes out, and no amount of statement shuffling reaches it
 * because it is a pool-layout decision rather than an allocation one.
 * Whether the original really had two objects at one address or one
 * object declared twice is not decidable from the bytes; what the bytes
 * do fix is that three source-level names were in play, not two. */
#define WIPE_INTERP_MAIN  0x0214691C   /* main engine's 0x20-byte record */
#define WIPE_INTERP_SUB   0x021468FC   /* sub engine's record base; the
                                        * sub record itself is at +0x20,
                                        * main's active flag at +0x3c and
                                        * sub's at +0x1c */

/* ------------------------------------------------------------------ *
 * THE CONFIGURATION BLOCK.  func_0202350C's second parameter, a byte
 * array the caller fills in.  Every offset below is a `ldrb` in
 * func_0202350C or func_02023464, so the whole block is BYTES, and the
 * two functions disagree about nothing.
 * ------------------------------------------------------------------ */
struct WipeCfg {
    u8 x0;             /* +0x00 .. +0x03 are pushed to the stack as
                        * func_02022E20's sixth through ninth arguments,
                        * in order, one `ldrb`/`str` pair each. */
    u8 x1;
    u8 x2;
    u8 x3;
    u8 pad4[4];        /* +0x04  func_0202350C passes `cfg + 4` to
                        * func_02022940 as a separate pointer, which is
                        * the evidence that the block has a second half
                        * rather than a field at +0x04. */
    u8 k8;             /* +0x08  selects the mode: func_02023464 tests it
                        * against zero to choose 1 or 2 for
                        * func_02022E88's second argument, and
                        * func_0202350C stores it to the object's +0x34. */
    u8 k9;             /* +0x09  func_02022E20's second argument. */
    u8 ka;             /* +0x0a  func_02022E20's third argument, and it
                        * must be bound to a NAMED LOCAL: left inline the
                        * compiler schedules its load last and eleven
                        * bytes move (docs/idioms/an-inline-call-argument-
                        * is-scheduled-per-site-a-local-is-not.md). */
    u8 kb;             /* +0x0b  stored to the object's +0x44. */
};

/* ------------------------------------------------------------------ *
 * PROTOTYPES.  Parameter types are as the EXACT sources spell them; where
 * a source uses `void *` for an object it only forwards, the concrete
 * type is given here in the comment instead.
 * ------------------------------------------------------------------ */

/* Constructors and their per-frame steps, in address order. */
void func_020229A4(struct WipeTask *t, u32 dir);      /* 0x020229A4 EXACT */
u32  func_02022A44(struct WipeTask *t);               /* 0x02022A44 EXACT */
void func_02023464(struct WipeTask *t, u8 *cfg);      /* 0x02023464 residue */
u32  func_020234C0(struct WipeTask *t);               /* 0x020234C0 EXACT* */
void func_020238B4(struct WipeTask *t, u32 a1);       /* 0x020238B4 EXACT */
u32  func_0202390C(struct WipeTask *t);               /* 0x0202390C EXACT* */

/* The direction test in func_020229A4 is written `dir == 0` FIRST: the
 * image's `bne` at +0x2e takes the second arm, so the zero case is the
 * fall-through and therefore the source's first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  Written the
 * other way round every byte from +0x2e to +0x4a is wrong -- the four arm
 * bodies come out mirrored and r6/r7 trade roles -- while everything
 * before and after stays identical. */

/* Per-frame polls. */
u32  func_02023768(struct WipeCount *w);              /* 0x02023768 EXACT */
u32  func_02023A50(struct WipeScan *w);               /* 0x02023A50 EXACT */

/* Setup and dispatch. */
void func_0202350C(struct WipeCount *obj, u8 *cfg, u32 a2, u32 a3, u32 a4,
                   u32 a5);                           /* 0x0202350C residue */
void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u32 a9);           /* 0x02022E20 EXACT */
/* a9 selects the shape: zero takes the window path (func_02023B74 /
 * func_02023BFC / func_02023C3C), anything else the blend path
 * (func_02023D18 / func_02023D40 / func_02023D60).  Both arms are written
 * out in full, which is what keeps them as two three-call sequences with
 * their own epilogues rather than one tail-merged tail. */

/* Scanline table rebuild. */
void func_0202384C(struct WipeScan *w);               /* 0x0202384C residue */

/* Engine arming and teardown. */
void func_02023E9C(struct Interp *p, u16 steps, s16 from, s16 to, u32 a4,
                   u32 a5);                           /* 0x02023E9C EXACT */
void func_02023EF4(struct Interp *p, u16 steps, s16 from, s16 to,
                   u32 mask);                         /* 0x02023EF4 EXACT */
void func_02023F98(u32 mask);                         /* 0x02023F98 EXACT */

/* ------------------------------------------------------------------ *
 * THE BRIGHTNESS/BLEND INTERPOLATION STEP (func_02023E0C), added
 * 2026-09-22 when it closed to EXACT.  It is the per-frame partner of
 * func_02023E9C above and drives the same struct Interp record.
 *
 * FOUR SHAPE RULES, each measured against the bytes in
 * src/matched/func_02023E0C.c.  They are recorded here because three of
 * the four are the family's own recurring levers and the fourth is new:
 *
 *   1. The two pointer locals for the record's f1a and f18 are HOISTED to
 *      the top of the advance arm, before the accumulate and its test,
 *      not created inside the inner `if`.  This alone is a four-byte size
 *      gap (140 bytes against 144).
 *   2. The delta is `step * p->f14`, step in the accumulator
 *      (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-
 *      operand.md).
 *   3. BOTH `if`s are written with the negated condition so that the arm
 *      the image falls through into is the source's first
 *      (docs/idioms/the-fall-through-arm-is-the-source-order.md).  This is
 *      the same rule func_020229A4's direction test already records above,
 *      and it is worth two separate large steps here (76 -> 24 -> 8 bytes).
 *   4. NEW: the f1a read is bound to its own named local AHEAD of the f0a
 *      read.  The image loads offset 0x1a before offset 0xa; left inline
 *      in the condition, mwcc evaluates the f0a assignment first and the
 *      two `movs #imm`/`ldrsh` pairs come out transposed.  Eight bytes.
 *
 * Statement position of the `flag = 0` initialisation is NOT a lever here:
 * all four positions compile identically, because mwcc sinks the zero to
 * where the image has it.  That was measured, and it is the counterexample
 * to the family's usual "initialise the result first" rule
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md), which governs where a RETURN VALUE is set,
 * not where a plain flag is.
 * ------------------------------------------------------------------ */
void func_02023E0C(struct Interp *p);                 /* 0x02023E0C EXACT */

/* The engine register words func_02023E0C writes through func_0207D658 are
 * the plain constants 0x04000050 and 0x04001050.  The second is NOT
 * 0x04001000 + 0x50 computed at run time; src/pending/func_02023EF4.c's
 * header records the same fact for the sibling, and the two now agree. */

/* Externs the family calls that are defined outside it. */
extern void *func_02030734(u32 heap, u32 size, u32 flag, u32 file,
                           u32 line);                 /* allocator; it is
                                                       * ARM, not Thumb --
                                                       * a `thumb` symbols:
                                                       * line makes match.py
                                                       * refuse the call
                                                       * outright rather than
                                                       * report a byte
                                                       * difference. */
extern void  func_02082BCC(void *p, u32 v, u32 n);    /* memset */
extern void  func_020307B0(void *p);                  /* free */
extern void *sub_020056A0(void *fn, void *arg, u32 prio); /* task register */

#endif /* WIPE_SUB_H */
