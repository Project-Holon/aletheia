/*
 * function: func_020726D0
 * address:  0x020726D0
 * packet:   pkt_02072548
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *
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

extern void func_020728E8(void *p);
extern void func_02072920(void *p);
extern void SND_Init(void);
extern void PM_PrependPostSleepCallback(struct SleepCb *cb);
extern void PM_AppendPostSleepCallback(struct SleepCb *cb);
extern void func_02072A28(void);
extern void func_02073D5C(void);
extern void func_0207312C(void);

void func_020726D0(void)
{
    if (g_0214BAC0.f0c != 0) {
        return;
    }
    g_0214BAC0.f0c = 1;
    SND_Init();
    g_0214BAC0.cb10.fn = func_020728E8;
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
