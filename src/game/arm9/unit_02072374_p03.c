/*
 * file:     unit_02072374_p03.c
 * unit:     yes
 * function: func_020726D0, func_02072758
 * address:  0x020726D0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214BAC0     0x0214BAC0  data
 *   func_020728E8  0x020728E8  arm
 *   func_02072920  0x02072920  arm
 *   SND_Init       0x02089848  arm
 *   PM_PrependPostSleepCallback  0x0208C808  arm
 *   PM_AppendPostSleepCallback   0x0208C828  arm
 *   func_02072A28  0x02072A28  arm
 *   func_02073D5C  0x02073D5C  arm
 *   func_0207312C  0x0207312C  arm
 *   func_02089978  0x02089978  arm
 *   func_020731E0  0x020731E0  arm
 *   func_02073D7C  0x02073D7C  arm
 *   func_02075858  0x02075858  arm
 *   func_02089B38  0x02089B38  arm
 */
struct SNDCommand;
typedef unsigned char u8; typedef unsigned int u32;

struct SleepCb { void (*fn)(void *); void *arg; void *p08; void *p0c; };

struct Sys {
    signed char b00;
    u8  p01[3];
    u32 f04;
    u32 p08;
    u32 f0c;
    struct SleepCb cb10;
    struct SleepCb cb20;
};

extern struct Sys g_0214BAC0;

extern void func_020728E8(void);
extern void func_02072920(void *p);
extern void SND_Init(void);
extern void PM_PrependPostSleepCallback(struct SleepCb *cb);
extern void PM_AppendPostSleepCallback(struct SleepCb *cb);
extern void func_02072A28(void);
extern void func_02073D5C(void);
extern void func_0207312C(void);

/*
 * Sound-system one-shot init: take the f0c latch, SND_Init(), register the two
 * post-sleep callbacks whose PMSleepCallbackInfo blocks live at +0x10 and +0x20
 * of the same global, bring up the three subsystems, then seed b00 = -1 and
 * f04 = 1.
 *
 * BYTE-CORRECT under the pin: 136 bytes, 0 concrete mismatches.  PARKED, not
 * filed: three of the eight PC24 sites have no witness outside this function's
 * own 136 bytes --
 *   +0x1C  SND_Init (0x02089848): the `bl` here is the only branch to it
 *          anywhere in the image, arm9 and all overlays.
 *   +0x54  func_02073D5C: only src/pending/func_02073D5C.c names it, and a
 *          `pending` file is never a `matched` witness.
 *   +0x58  func_0207312C: same, src/pending/func_0207312C.c, which is itself
 *          parked for want of a `literal` witness on 0x0214E024 (see its
 *          header and docs/FRONTEND-PINS.md).
 * Promoting either of those two pending files promotes this one with it; there
 * is no split that helps, since all three witnesses would still be inside.
 *
 * Signedness lever: b00 is `signed char`, not `u8`.  The image emits
 * `mvn r1, #0` at 0x02072730; written as `(u8)-1` the compiler materialises
 * `mov r0, #0xff` instead, which is a concrete byte difference, not a
 * relocation one.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * RELOADS the base pool word 0x0214BAC0 three separate times -- `ldr r0,[pc,#0x68]`
 * at 0x020726D4, `ldr r1,[pc,#0x48]` at 0x020726F4 and `ldr r0,[pc,#0x10]` at
 * 0x0207272C, three distinct pool entries at 0x02072744, 0x02072750 and
 * 0x02072754 for one symbol -- and rematerialises the literal 1 twice
 * (`mov r1,#1` at 0x020726E4 and again at 0x02072738), which is why the frame
 * is a bare `push {r3, lr}`.  1.1p1 -O4,p hoists the base into callee-saved r4
 * and the 1 into r5 across all five calls, needing `push {r3, r4, r5, lr}` and
 * folding the pool to two words: 124 bytes against the original's 136, 75
 * concrete bytes out.  Under the pin the same C is 136 bytes, 0 mismatches.
 */
void func_020726D0(void)
{
    if (g_0214BAC0.f0c != 0) {
        return;
    }
    g_0214BAC0.f0c = 1;
    SND_Init();
    g_0214BAC0.cb10.fn = (void (*)(void *))func_020728E8;
    g_0214BAC0.cb10.arg = 0;
    g_0214BAC0.cb20.fn = func_02072920;
    g_0214BAC0.cb20.arg = 0;
    PM_PrependPostSleepCallback(&g_0214BAC0.cb10);
    PM_AppendPostSleepCallback(&g_0214BAC0.cb20);
    func_02072A28();
    func_02073D5C();
    func_0207312C();
    g_0214BAC0.b00 = -1;
    g_0214BAC0.f04 = 1;
}

typedef int s32;

typedef unsigned int   u32;

extern const struct SNDCommand *func_02089978(u32 flags);
extern void func_020731E0(void);
extern void func_02073D7C(void);
extern void func_02075858(void);
extern void func_02089B38(s32 a);
void func_02072758(void);


/*
 * Not a member of the 0x02071CDC constructor family: the subsystem's boot
 * sequence. Spins until func_02089978(0) reports ready, runs the three
 * initialisers, then hands 0 to func_02089B38.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md).
 * The image rematerialises the last call's zero argument, `mov r0, #0`
 * (`00 00 a0 e3`) at 0x0207277C, although the spin loop is still holding a
 * zero live in the callee-saved r4 it set up at 0x0207275C; dsi/1.1p1 -O4,p
 * reuses it and emits `mov r0, r4` (`04 00 a0 e1`) instead, the same 48
 * bytes with exactly those 2 concrete bytes out. Five spellings measured in
 * docs/notes/pkt_02071DD4.c.txt (a `z` local, a bare literal 0, a
 * `for (z = 0; ...)` head, passing the same `z` to the last call, and the
 * truthiness form `while (f(0))`) all share the constant. Under the pin the
 * same C is 48 bytes, 0 mismatches: BYTE-CORRECT, and the 2-byte codegen
 * difference is gone.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three of
 * the five PC24 sites (func_020731E0, func_02073D7C, func_02075858) have no
 * branch anywhere in the image outside this function's own 48 bytes, and
 * nothing under src/matched/ reproduces the ranges that define them, so the
 * `label` and `matched` classes both refuse. There is nothing to split: this
 * is one function, and it is the sole caller of all three. It promotes to
 * EXACT unchanged the moment any one of 0x020731E0, 0x02073D7C, 0x02075858
 * is filed EXACT elsewhere, or a second caller of one is decompiled.
 *
 * 2026-09-21, unblock lane: ONE OF THE THREE BLOCKING SITES IS NOW CLEARED.
 * func_020731E0 (the +0x18 site) was promoted to src/matched/ this pass and
 * resolves `matched x1`; the file is now MATCH* with 3 of 5 relocations
 * resolved.  The two that remain are +0x1C (func_02073D7C, 128 bytes at
 * 0x02073D7C) and +0x20 (func_02075858, 272 bytes at 0x02075858), neither of
 * which has any branch outside this function's own bytes.  Both must be
 * written and filed EXACT in their own right -- there is no second caller to
 * find for either -- and then this file promotes with no change to the C.
 * Verify it with `--cc ../2.0/sp2 --arm`, not the default 1.1p1.
 */
void func_02072758(void)
{
    while (func_02089978(0) != 0)
        ;

    func_020731E0();
    func_02073D7C();
    func_02075858();
    func_02089B38(0);
}
