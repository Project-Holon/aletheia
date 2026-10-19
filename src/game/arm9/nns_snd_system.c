/*
 * file:     nns_snd_system.c
 * unit:     yes
 * function: NNS_SndInit, NNS_SndBoot, NNS_SndSetMasterVolume, NNS_SndSetMasterPan, NNS_SndReadDriverInfo, NNS_SndReadTrackInfo, NNS_SndPrependPostSleepCallback, NNS_SndAppendPostSleepCallback
 * address:  0x020726D0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from nns_snd_system.c by tools/splitfile.py.
 *
 * symbols:
 *   g_0214BAC0     0x0214BAC0  data
 *   SND_Init       0x02089848  arm
 *   PM_PrependPostSleepCallback  0x0208C808  arm
 *   PM_AppendPostSleepCallback   0x0208C828  arm
 *   NNS_SndWaveOutInit  0x02072A28  arm
 *   NNSi_SndMainReset  0x02073D5C  arm
 *   NNS_SndPlayerInit  0x0207312C  arm
 *   SND_RecvCommandReply  0x02089978  arm
 *   NNS_SndPlayerMain  0x020731E0  arm
 *   NNS_SndMain  0x02073D7C  arm
 *   NNSi_SndArcPlayerUpdate  0x02075858  arm
 *   SND_FlushCommand  0x02089B38  arm
 *   SND_SetMasterVolume  0x0208970C  arm
 *   g_0214BB00     0x0214BB00  data
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   SND_ReadDriverInfo        0x02089794  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   DC_InvalidateRange        0x020862B8  arm
 *   SND_ReadTrackInfo 0x0208A0A4  arm
 *   NNSi_SndCaptureReset  0x02073F3C  arm
 *   NNS_SndStartTimer  0x02073EE4  arm
 *   SND_StopTimer  0x020894DC  arm
 *   SND_SetMasterPan  0x02089754  arm
 *   SND_ResetMasterPan  0x02089774  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 */
#include "nns_g3d_tex_mtx_shared_types.h"

struct SNDCommand;

struct SNDDriverInfo;

struct SNDTrackInfo;

struct SleepCb { void (*fn)(void *); void *arg; void *p08; void *p0c; };

struct Sys {
    signed char idx;
    u8  p01[3];
    u32 pending;
    u32 tag;
    u32 initialized;
    struct SleepCb cb10;
    struct SleepCb cb20;
};

typedef signed char s8;

extern void SND_Init(void);

extern void PM_PrependPostSleepCallback(struct SleepCb *cb);

extern void PM_AppendPostSleepCallback(struct SleepCb *cb);

extern void NNS_SndWaveOutInit(void);

extern void NNSi_SndMainReset(void);

extern void NNS_SndPlayerInit(void);

extern const struct SNDCommand *SND_RecvCommandReply(u32 flags);

extern void NNS_SndPlayerMain(void);

extern void NNS_SndMain(void);

extern void NNSi_SndArcPlayerUpdate(void);

extern void SND_SetMasterVolume(int volume);

extern void SND_SetMasterPan(int pan);

extern void SND_ResetMasterPan(void);

extern u32  SND_IsFinishedCommandTag(u32 tag);

extern void SND_ReadDriverInfo(void *dst);

extern u32  SND_GetCurrentCommandTag(void);

extern void DC_InvalidateRange(void *p, u32 n);

extern void SND_FlushCommand(u32 flags);

extern int SND_ReadTrackInfo(struct SNDDriverInfo *, int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);

extern void NNS_SndStartTimer(void);

extern void SND_StopTimer(u32 a, u32 b, u32 c, u32 d);

extern void SND_WaitForCommandProc(u32 a);

extern void NNSi_SndCaptureReset(void);

void NNS_SndInit(void);

void NNS_SndBoot(void);

void NNS_SndSetMasterVolume(int volume);

void NNS_SndSetMasterPan(u32 flag);

u32 NNS_SndReadDriverInfo(void);

int NNS_SndReadTrackInfo(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);

void NNS_SndPrependPostSleepCallback(void);

void NNS_SndAppendPostSleepCallback(void *p);

extern struct Sys g_0214BAC0;

extern u8 g_0214BB00[];

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
 *   +0x54  NNSi_SndMainReset: only src/pending/NNSi_SndMainReset.c names it, and a
 *          `pending` file is never a `matched` witness.
 *   +0x58  NNS_SndPlayerInit: same, src/pending/NNS_SndPlayerInit.c, which is itself
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
void NNS_SndInit(void)
{
    if (g_0214BAC0.initialized != 0) {
        return;
    }
    g_0214BAC0.initialized = 1;
    SND_Init();
    g_0214BAC0.cb10.fn = (void (*)(void *))NNS_SndPrependPostSleepCallback;
    g_0214BAC0.cb10.arg = 0;
    g_0214BAC0.cb20.fn = NNS_SndAppendPostSleepCallback;
    g_0214BAC0.cb20.arg = 0;
    PM_PrependPostSleepCallback(&g_0214BAC0.cb10);
    PM_AppendPostSleepCallback(&g_0214BAC0.cb20);
    NNS_SndWaveOutInit();
    NNSi_SndMainReset();
    NNS_SndPlayerInit();
    g_0214BAC0.idx = -1;
    g_0214BAC0.pending = 1;
}

/*
 * Not a member of the 0x02071CDC constructor family: the subsystem's boot
 * sequence. Spins until SND_RecvCommandReply(0) reports ready, runs the three
 * initialisers, then hands 0 to SND_FlushCommand.
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
 * the five PC24 sites (NNS_SndPlayerMain, NNS_SndMain, NNSi_SndArcPlayerUpdate) have no
 * branch anywhere in the image outside this function's own 48 bytes, and
 * nothing under src/matched/ reproduces the ranges that define them, so the
 * `label` and `matched` classes both refuse. There is nothing to split: this
 * is one function, and it is the sole caller of all three. It promotes to
 * EXACT unchanged the moment any one of 0x020731E0, 0x02073D7C, 0x02075858
 * is filed EXACT elsewhere, or a second caller of one is decompiled.
 *
 * 2026-09-21, unblock lane: ONE OF THE THREE BLOCKING SITES IS NOW CLEARED.
 * NNS_SndPlayerMain (the +0x18 site) was promoted to src/matched/ this pass and
 * resolves `matched x1`; the file is now MATCH* with 3 of 5 relocations
 * resolved.  The two that remain are +0x1C (NNS_SndMain, 128 bytes at
 * 0x02073D7C) and +0x20 (NNSi_SndArcPlayerUpdate, 272 bytes at 0x02075858), neither of
 * which has any branch outside this function's own bytes.  Both must be
 * written and filed EXACT in their own right -- there is no second caller to
 * find for either -- and then this file promotes with no change to the C.
 * Verify it with `--cc ../2.0/sp2 --arm`, not the default 1.1p1.
 */
void NNS_SndBoot(void)
{
    while (SND_RecvCommandReply(0) != 0)
        ;

    NNS_SndPlayerMain();
    NNS_SndMain();
    NNSi_SndArcPlayerUpdate();
    SND_FlushCommand(0);
}

void NNS_SndSetMasterVolume(int volume)
{
    SND_SetMasterVolume(volume);
}

void NNS_SndSetMasterPan(u32 flag)
{
    if (flag != 0) {
        SND_SetMasterPan(0x40);
    } else {
        SND_ResetMasterPan();
    }
}

/*
 * Double-buffered SND_ReadDriverInfo pump over the 0x0214BAC0 control block
 * (the same base src/pending/NNS_SndInit.c initialises) and the pair of
 * 0x11E0-byte info buffers at 0x0214BB00.
 *
 * BYTE-CORRECT at 212 bytes, 0 concrete mismatches.  PARKED, NOT FILED: the two
 * PC24 sites at +0x68 and +0xB8 both name SND_ReadDriverInfo (0x02089794),
 * whose ONLY branches anywhere in the image are those two `bl`s, both inside
 * this one function.  `label` refuses a witness that lives inside the compared
 * range, and the two calls sit in mutually exclusive arms of the same function,
 * so no --suggest-split cut can separate them.  Capped at MATCH until some
 * other caller of SND_ReadDriverInfo is filed.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * RELOADS the 0x0214BAC0 base pool word FOUR separate times -- `ldr r0,[pc,#0xc8]`
 * at 0x020727B8, `ldr r0,[pc,#0xa4]` at 0x020727DC, `ldr r0,[pc,#0x8c]` at
 * 0x020727F4 and `ldr r1,[pc,#0x5c]` at 0x02072824, plus a fifth at 0x02072844
 * and a sixth at 0x02072874 -- all resolving to the single pool word at
 * 0x02072888, which is why the frame is a bare `push {r4, lr}` (`10 40 2d e9`).
 * 1.1p1 -O4,p hoists the base into callee-saved r4 and CSEs the `mov r0, #0`
 * arguments into r5, needing `push {r3, r4, r5, lr}`: the same 212 bytes with
 * 45 concrete bytes out.  Under the pin the same C is 212 bytes, 0 mismatches.
 *
 * One lever needed only under the pin: the index toggle must be written as an
 * explicit if/else pair of stores (`if (idx == 0) idx = 1; else idx = 0;`).
 * The boolean form `idx = (s8)(idx == 0);` schedules the third base reload one
 * instruction late and is 6 bytes out; `volatile` on the struct and on the
 * field alone are both 6 out as well.
 */
u32 NNS_SndReadDriverInfo(void)
{
    if (g_0214BAC0.pending == 0) {
        while (SND_RecvCommandReply(0) != 0)
            ;

        if (SND_IsFinishedCommandTag(g_0214BAC0.tag) == 0)
            return 0;

        if (g_0214BAC0.idx < 0)
            g_0214BAC0.idx = 1;

        SND_ReadDriverInfo(&g_0214BB00[g_0214BAC0.idx * 0x11E0]);
        g_0214BAC0.tag = SND_GetCurrentCommandTag();
        if (g_0214BAC0.idx == 0)
            g_0214BAC0.idx = 1;
        else
            g_0214BAC0.idx = 0;
        DC_InvalidateRange(&g_0214BB00[g_0214BAC0.idx * 0x11E0], 0x11E0);
        SND_FlushCommand(0);
        return 1;
    }

    SND_ReadDriverInfo(&g_0214BB00[0]);
    g_0214BAC0.tag = SND_GetCurrentCommandTag();
    g_0214BAC0.pending = 0;
    return 0;
}

/*
 *           and it is this function, so no branch outside 0x02072894..0x020728E8
 *           witnesses it.  Every concrete byte reproduces.
 *
 * r1 (b) is parked in lr as soon as it is read, because the predicated
 * `ldrge r1, [pc]` that materialises the table base clobbers r1 before the
 * call; the fourth argument (c) is copied into r3 first for the same reason,
 * r2 being needed for b again at the call.
 */
int NNS_SndReadTrackInfo(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo)
{
    s8 idx = g_0214BAC0.idx;
    u8 *p;

    if (idx < 0) p = 0;
    else         p = g_0214BB00 + idx * 0x11E0;
    if (p == 0) return 0;
    return SND_ReadTrackInfo((struct SNDDriverInfo *)p, playerNo, trackNo, trackInfo);
}

void NNS_SndPrependPostSleepCallback(void)
{
    u32 res;

    NNS_SndStartTimer();
    SND_StopTimer(0, 0, 0, 0);
    res = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(res);
}

void NNS_SndAppendPostSleepCallback(void *p)
{
    NNSi_SndCaptureReset();
}
