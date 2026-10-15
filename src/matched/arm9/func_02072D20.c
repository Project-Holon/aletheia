/*
 * function: NNS_SndWaveOutWaitIdle
 * address:  0x02072D20
 * packet:   pkt_02072D20
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SND_GetChannelStatus   0x0208A07C  arm
 *   SND_GetCurrentCommandTag   0x02089D40  arm
 *   func_02089B38   0x02089B38  arm
 *   SND_WaitForCommandProc   0x02089CD4  arm
 *
 * THE `../2.0/sp2` PIN, and why it is not the default front end.
 *
 * The default pin emits the same 120 instructions in the same order with the
 * same six relocation sites, but allocates the literal 1 of the bit test to
 * r5 - obj's own callee-saved register, which is dead on that path - so that
 * the argument of the later `func_02089B38(1)` becomes `mov r0, r5` instead of
 * a fresh `mov r0, #1`:
 *
 *   image   +001C  mov r2, #1        +0030  mov r0, #1
 *   dsi/1.1p1+001C mov r5, #1        +0030  mov r0, r5     (4 concrete bytes)
 *
 * `mwcceppc 2.0` keeps the constant where the image keeps it: it re-materialises
 * the 1 for the call instead of holding it across the `bl`.  Every 1.1p1
 * spelling tried puts the constant in a callee-saved register:
 * the plain call `func_02089B38(1)`, `(int)1`, `1u`, `1U`, `1 << 0`, `!0`,
 * `1 == 1`, `2 - 1`, `1 != 0`, `sizeof(char)`, `(unsigned char)1`, a
 * `u32 one = 1;` local shared by the test and the call, a `u32 bit = 1;` local
 * used by the test only, the mask hoisted to `u32 m = 1 << s->f0`, the
 * comparison bound to `u32 r` and passed as `r != 0`, the plain literal with
 * the arms swapped and with the body guarded instead of early-returned.  All
 * nineteen spellings give the same four bytes (`scratch`-external probes,
 * 2026-09-19).  This is the "kept constants" tell of docs/FRONTEND-PINS.md
 * ("the image rematerialises a constant from the pool where the build keeps it
 * live in a callee-saved register" -> 2.0), measured here as a register choice
 * rather than a pool word, and it is the same family as the pins already in
 * force for src/matched/NNS_SndArcLoadSeq.c and src/matched/NNS_SndArcLoadWaveArc.c.
 *
 * The two arms are one switch of the driver state: +8 zero means "wake the
 * voice once the channel bit is free, then hand it a fresh handle", +8 nonzero
 * means "release the stale handle if it was not released yet, then spin until
 * the channel bit clears".  `h` is a named local because the handle has to
 * survive the `func_02089B38(1)` call between the two uses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndWaveOutWaitIdle.c \
 *       --func NNS_SndWaveOutWaitIdle --addr 0x02072D20 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 120 = original 120, 6 of 6 sites resolved
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
} Obj;

extern unsigned long SND_GetChannelStatus(void);
extern u32 SND_GetCurrentCommandTag(void);
extern void func_02089B38(int v);
extern void SND_WaitForCommandProc(u32 tag);

void NNS_SndWaveOutWaitIdle(Obj *obj)
{
    u32 h;

    if (obj->f8 == 0) {
        if ((SND_GetChannelStatus() & (1 << obj->f0)) == 0)
            return;
        h = SND_GetCurrentCommandTag();
        func_02089B38(1);
        SND_WaitForCommandProc(h);
    } else {
        if (obj->fC == 0) {
            SND_WaitForCommandProc(obj->f10);
            obj->fC = 1;
        }
        while (SND_GetChannelStatus() & (1 << obj->f0))
            ;
    }
}
