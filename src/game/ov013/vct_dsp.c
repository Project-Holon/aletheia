/*
 * file:     vct_dsp.c
 * unit:     yes
 * function: VCT_DSP_ResetVoiceGate, VCT_DSP_GetVoiceGateConfig, VCT_DSP_UpdateVoiceGate, VCT_DSP_InitVoiceGateDefaults, VCT_DSP_HighPassFilter, VCT_DSP_InitEchoState, VCT_DSP_SetEchoReference, VCT_DSP_SuppressEcho, VCT_DSP_SuppressEchoWithReference, VCT_DSP_MixSaturated
 * address:  0x021B3018
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vct_main.c, vct_audio.c, vct_session.c, vct_dsp.c by tools/splitfile.py.
 *
 * symbols:
 *   VCT_DSP_GetVoiceGateConfig  0x021B3064  arm ov013
 *   VCT_DSP_InitVoiceGateDefaults  0x021B3250  arm ov013
 *   VCT_DSP_InitEchoState  0x021B3364  arm ov013
 *   VCT_DSP_ResetVoiceGate  0x021B3018  arm ov013
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   VCT_DSP_MixSaturated  0x021B3624  arm ov013
 *   VCT_DSP_SetEchoReference  0x021B33E0  arm ov013
 *   VCT_DSP_HighPassFilter  0x021B3278  arm  ov013
 *   VCT_DSP_SuppressEchoWithReference  0x021B3604  arm  ov013
 *   VCT_DSP_UpdateVoiceGate  0x021B3084  arm  ov013
 *   MI_CpuCopy8  0x02082D44  arm
 *   gVoiceGateEnergyRing     0x021B4C38  data a4
 *   gVoiceGateState     0x021B4C2C  data a4
 *   gVoiceGateConfig     0x021B3C50  data a4
 *   gEchoState     0x021B4C48  data ov013
 *   gEchoDefaultCoeffs     0x021B3C60  data a2
 *   gEchoRing     0x021B50CC  data a2
 *   gEchoFirDelayAlias     0x021B4C74  data a4
 *   gEchoFirCoeffsAlias     0x021B4C5C  data a4
 *   gEchoReferenceFrame     0x021B4C8C  data a4
 */
#include "vct_types.h"

#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)

#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)

#define reg_CP_SQRT_PARAM   (*(u32 *)0x040002B8)

#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)

#define reg_CP_DIV_NUMER    (*(u64 *)0x04000290)

#define reg_CP_DIV_DENOM    (*(u64 *)0x04000298)

#define reg_CP_DIV_RESULT_L (*(volatile u32 *)0x040002A0)

/* Lever: the enum constant gives the hangover count its own type, so the cast to short keeps the smulbb. */
typedef enum { HangoverFramesDefault } HangoverFrames;

#include "../arm9/mi_memory.h"


void VCT_DSP_ResetVoiceGate(void);

void VCT_DSP_GetVoiceGateConfig(void *config);

u32 VCT_DSP_UpdateVoiceGate(u32 energy, u32 level, u8 *levelOut);

void VCT_DSP_InitVoiceGateDefaults(void);

s32 VCT_DSP_HighPassFilter(s16 *samples, u32 byteCount);

void VCT_DSP_InitEchoState(void);

void VCT_DSP_SetEchoReference(void *frame, u32 byteCount);

void VCT_DSP_SuppressEcho(s16 *mic, s16 *reference, u32 byteCount, u32 threshold);

void VCT_DSP_SuppressEchoWithReference(short *mic, unsigned int byteCount, unsigned int threshold);

void VCT_DSP_MixSaturated(s16 *srcA, s16 *srcB, s16 *dst, u32 byteCount);

extern u32 gVoiceGateEnergyRing[];

extern VoiceGateState gVoiceGateState;

extern struct EchoState gEchoState;

extern s16 gEchoDefaultCoeffs[];

extern s16 gEchoRing[];

extern int gEchoFirDelayAlias[];

extern int gEchoFirCoeffsAlias[];

extern short gEchoReferenceFrame[];

void VCT_DSP_ResetVoiceGate(void)
{
    int i;
    for (i = 0; i < 4; i++) gVoiceGateEnergyRing[i] = 0x1000000;
    gVoiceGateState.ringIndex = 0;
    gVoiceGateState.threshold = 0;
    VAD_CFG.voiceActive = 0;
    VAD_CFG.lastLevel = 0;
    gVoiceGateState.quietFrames = 0;
}

void VCT_DSP_GetVoiceGateConfig(void *config)
{
    if (!config)
        return;
    MI_CpuCopy8(&gVoiceGateConfig, config, 0x10);
}

static inline void CP_SetSqrt32(u32 param)
{
    reg_CP_SQRTCNT = 0;
    reg_CP_SQRT_PARAM = param;
}

static inline void CP_WaitSqrt(void)
{
    while (reg_CP_SQRTCNT & 0x8000) {
    }
}

/*
 * Voice-activity gate. gVoiceGateEnergyRing is a 4-entry ring of energies; the hardware
 * sqrt of the ring mean is compared with a threshold (gVoiceGateState.threshold). Returns
 * 0/1 (idle: start), 2 (active), 3 (active timed out).
 * Lever: gVoiceGateConfig is declared u8 (under four bytes), so every access to it is
 * in the compiler's unknown-memory set and the ringIndex store of gVoiceGateState stays
 * before the gVoiceGateConfig store, as in the original. VadCfg is the view of it.
 */
#pragma opt_propagation off

u32 VCT_DSP_UpdateVoiceGate(u32 energy, u32 level, u8 *levelOut)
{
    u32 result;
    u32 energySum;
    int i;
    u32 rootMean;

    VAD_CFG.lastLevel = level >> 8;
    if (levelOut != 0)
        *levelOut = level >> 8;
    if (VAD_CFG.voiceActive == 0) {
        i = energySum = 0;
        do {
            energySum += gVoiceGateEnergyRing[i];
            i++;
        } while (i < 4);
        CP_SetSqrt32(energySum >> 2);
        CP_WaitSqrt();
        rootMean = reg_CP_SQRT_RESULT;
        if (level != 0 && level >= (rootMean << 1)) {
            u32 energySum2;
            u32 j;
            VoiceGateState *state;
            u32 threshold;

            j = energySum2 = 0;
            do {
                energySum2 += gVoiceGateEnergyRing[j];
                j++;
            } while (j < 4);
            CP_SetSqrt32(energySum2 >> 2);
            CP_WaitSqrt();
            threshold = (reg_CP_SQRT_RESULT * 3) >> 1;
            state = &gVoiceGateState;
            state->threshold = threshold;
            gVoiceGateState.ringIndex = 0;
            VAD_CFG.voiceActive = 1;
            result = 1;
        } else {
            result = 0;
        }
        gVoiceGateEnergyRing[gVoiceGateState.ringIndex] = energy;
        gVoiceGateState.ringIndex = (gVoiceGateState.ringIndex + 1) & 3;
    } else {
        gVoiceGateEnergyRing[gVoiceGateState.ringIndex] = energy;
        gVoiceGateState.ringIndex = (gVoiceGateState.ringIndex + 1) & 3;
        i = energySum = 0;
        do {
            energySum += gVoiceGateEnergyRing[i];
            i++;
        } while (i < 4);
        CP_SetSqrt32(energySum >> 2);
        CP_WaitSqrt();
        if (reg_CP_SQRT_RESULT <= gVoiceGateState.threshold) {
            gVoiceGateState.quietFrames++;
            if (gVoiceGateState.quietFrames > VAD_CFG.hangoverFrames) {
                VAD_CFG.voiceActive = 0;
                gVoiceGateState.quietFrames = 0;
                gVoiceGateState.ringIndex = 0;
                return 3;
            }
        } else {
            gVoiceGateState.quietFrames = 0;
        }
        result = 2;
    }
    return result;
}

#pragma opt_propagation reset

/*
 * lever: enum count cast to short preserves the smulbb; short local folded 15*68.
 */
void VCT_DSP_InitVoiceGateDefaults(void)
{
    HangoverFrames hangover=15;
    short frameBytes=68;
    VAD_CFG.hangoverFrames=hangover;
    VAD_CFG.hangoverBytes=(short)hangover*frameBytes;
    VCT_DSP_ResetVoiceGate();
}

static inline void CP_SetDiv64_32(u64 numer, u32 denom)
{
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = numer;
    reg_CP_DIV_DENOM = denom;
}

static inline void CP_WaitDiv(void)
{
    while (reg_CP_DIVCNT & 0x8000) {
    }
}

s32 VCT_DSP_HighPassFilter(s16 *samples, u32 length)
{
    s32 prevInput;
    u32 i;
    s64 energy;
    s32 output;
    s32 scaled;

    scaled = samples[0] * 0xE9F;
    output = (scaled + gEchoState.highPassPrevInput + gEchoState.highPassPrevOutput * 0xD3E) >> 12;
    gEchoState.highPassPrevOutput = output;
    gEchoState.highPassPrevInput = prevInput = -scaled;
    energy = output * output;
    length >>= 1;
    i = 1;
    if (length > 1) {
        do {
            scaled = samples[i] * 0xE9F;
            samples[i - 1] = output;
            output = (scaled + prevInput + output * 0xD3E) >> 12;
            energy += output * output;
            prevInput = -scaled;
        } while (++i < length);
        gEchoState.highPassPrevInput = prevInput;
        gEchoState.highPassPrevOutput = output;
    }
    (samples + length)[-1] = output;
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = energy;
    reg_CP_DIV_DENOM = length;
    CP_WaitDiv();
    return reg_CP_DIV_RESULT_L;
}

void VCT_DSP_InitEchoState(void)
{
    int i;
    s16 *defaultCoeffs;

    defaultCoeffs = gEchoDefaultCoeffs;
    gEchoState.ringWriteIndex = 0;
    gEchoState.ringReadIndex = 0x19D;
    for (i = 0; i < 0x800; i++)
        gEchoRing[i] = 0;
    for (i = 0; i < 6; i++) {
        gEchoFirDelayAlias[i] = 0;
        gEchoFirCoeffsAlias[i] = defaultCoeffs[i];
    }
}

void VCT_DSP_SetEchoReference(void *frame, u32 byteCount)
{
    MIi_CpuCopyFast(frame, gEchoReferenceFrame, byteCount);
}

#pragma opt_common_subs off

/*
 * note 2026-10-05 (integrator): EXACT. The tail guard tests the counter, `i = 0; if (i < n) { sh = att; do ... while (i < n); }`, which gives the unsigned `ls` exit; `n != 0` gave `eq` (2 B).
 *
 * note (2026-10-05, wave P4 lane S4, pengy share, approved for this function):
 *   Semantics recovered from the listing: a 6-tap FIR over the state at
 *   gEchoState (ring index [2],[3] masked 0x7FF, coefficients [5..10], delay line
 *   [11..16]) that filters b[], leaves b[i] = a[i], sums squares into an s64, then
 *   divides by n/2 (DIVCNT mode 1), takes the hardware sqrt, and scales a[] by an
 *   attenuation shift kept in the halfword at state[0] (0 when 3*rms < 2*thr,
 *   4 when thr < rms, else +1 up to 4).
 *   Residue: 472 bytes against 524. The original keeps the s64 sum e at
 *   [sp+8..0xc], the ring index w at [sp], and a dead store of the delay value at
 *   [sp+4] (frame 0x10, no fp); every spelling here keeps e in fp and r4 instead
 *   and spills the coefficient c4 to [sp]. Same code with the same bytes (472) for:
 *   explicit tap statements, a rolled loop (444, wrong), delay chain in a temp,
 *   tap locals d0..d5 with d5 = d4, u64 e, opt_dead_assignments off (with and
 *   without a dead local), a u32 base local for the ring buffer, and an inline
 *   FIR-step helper. All taps up front as locals gives 564. Tried 14 compiles.
 *   Idea left: e, w and the dead word look like memory-resident locals (address
 *   taken by an inline helper with out parameters).
 *
 * note (2026-10-05, wave P4 lane S4b, pengy share):
 *   Now 512 bytes against 524 (was 472). Two source changes found:
 *   (1) the ring write index is read once into a local (v = state[3]) and reused
 *   for the ring store and for state[3] = (v + 1) & 0x7FF; the original keeps it
 *   in r7 across the whole tap chain and never re-reads it. That alone puts e in
 *   [sp] memory (a spill) and removes fp.
 *   (2) the sqrt start is an inline helper CP_SetSqrt32(u32 param) called with
 *   reg_CP_DIV_RESULT_L as the argument, so the result load comes before the
 *   SQRTCNT store and the pool word is 0x040002A0 as in the original. The whole
 *   tail after the loop now matches except for register numbers.
 *   Residue: the original spills three webs (e at sp+8, w=state[2] at sp, the
 *   delay value d4 at sp+4, never reloaded; frame 0x10, no fp, state in ip, mask
 *   in lr, i in r8). Ours spills e plus one coefficient and keeps w in a register
 *   (frame 0xc plus an r3 pad). The original therefore has about three more live
 *   values in the tap chain than ours; none found.
 *   Tried (17 compiles, none better than 512): struct local for e/w/d5 (scalar
 *   replaced, same bytes), inline AddSq(&e) helper (inlined, same bytes), the six
 *   per-function pragmas on the 512 form (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole: all >= 508 and
 *   worse), declaration order of v/w (first, last), u32 v/w, pointer locals
 *   c = state + 5 and d = state + 11 (552, worse: pointers stay live).
 *
 * final push 2026-10-05 G9L10 (40 compiles, 3 rounds): now 2 bytes off of 524 (was 417). Only the
 *   tail guard differs: original `cmp r2,#0; addls; popls` before a loop-invariant `ldrsh r4,[r1]`
 *   (att hoisted into the preheader after the guard); ours gives `addeq` because the explicit
 *   `if (n != 0) { sh = att; do ... }` form is the only one that put the load after the guard.
 *   Causes found: (1) the state and the ring buffer are ONE object: a struct with s16 buf[] at +0x484
 *   and a local `ring = gEchoState.ringBuf` (pool word sym+0x484 reloaded per use, w load after the ring
 *   store, w spilled at its definition, frame 0x10, push list and slots as the original). Separate
 *   externs let the scheduler hoist the w load above the ring store and raised the pressure.
 *   (2) first tap written `d5 * c10 + d4 * c9` (mwcc fuses the left product into mla). (3) per-function
 *   `#pragma opt_common_subs off` makes d4 (not c10) the spilled web with the original load order;
 *   without it 53 B off. (4) declaration order v then i gives i=r8, v=r7. (5) tail shift amount read
 *   once into a local before the loop. Tried without effect: opt_propagation off do-while, struct
 *   local {w,d,e} (scalar replaced), dead local + opt_dead_assignments off (vanishes), scheduling
 *   pragma (no-op on ARM), pointer locals for state/ring, named products, store before the taps,
 *   in-loop shift read under common_subs off (18 B).
 */
void VCT_DSP_SuppressEcho(s16 *mic, s16 *reference, u32 count, u32 threshold)
{
    s16 *ring = gEchoState.ringBuf;
    s64 energy;
    u32 rms;
    s32 sum;
    s32 readIndex;
    s32 writeIndex;
    u32 i;
    s32 filtered;
    s32 shift;
    s32 tap0, tap1, tap2, tap3, tap4, tap5;

    energy = 0;
    count >>= 1;
    for (i = 0; i < count; i++) {
        writeIndex = gEchoState.ringWriteIndex;
        ring[writeIndex] = reference[i];
        readIndex = gEchoState.ringReadIndex;
        gEchoState.firDelay[0] = ring[readIndex];
        tap5 = gEchoState.firDelay[5];
        sum = tap5 * gEchoState.firCoeffs[5] + gEchoState.firDelay[4] * gEchoState.firCoeffs[4];
        gEchoState.firDelay[5] = gEchoState.firDelay[4];
        tap3 = gEchoState.firDelay[3];
        sum += tap3 * gEchoState.firCoeffs[3];
        gEchoState.firDelay[4] = tap3;
        tap2 = gEchoState.firDelay[2];
        sum += tap2 * gEchoState.firCoeffs[2];
        gEchoState.firDelay[3] = tap2;
        tap1 = gEchoState.firDelay[1];
        sum += tap1 * gEchoState.firCoeffs[1];
        gEchoState.firDelay[2] = tap1;
        tap0 = gEchoState.firDelay[0];
        sum += tap0 * gEchoState.firCoeffs[0];
        gEchoState.firDelay[1] = tap0;
        if (sum > 0x3FFF8000)
            sum = 0x3FFF8000;
        else if (sum < (s32)0xC0000000)
            sum = (s32)0xC0000000;
        gEchoState.ringWriteIndex = (writeIndex + 1) & (0x3FFF8000 >> 19);
        gEchoState.ringReadIndex = (readIndex + 1) & (0x3FFF8000 >> 19);
        reference[i] = sum >> 15;
        filtered = reference[i];
        reference[i] = mic[i];
        energy += filtered * filtered;
    }
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = energy;
    reg_CP_DIV_DENOM = count;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    CP_SetSqrt32(reg_CP_DIV_RESULT_L);
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    rms = reg_CP_SQRT_RESULT;
    if (rms * 3 < threshold * 2) {
        gEchoState.attenuationShift = 0;
        return;
    }
    if (threshold < rms)
        gEchoState.attenuationShift = 4;
    if (gEchoState.attenuationShift < 4)
        gEchoState.attenuationShift = gEchoState.attenuationShift + 1;
    i = 0;
    if (i < count) {
        shift = gEchoState.attenuationShift;
        do {
            mic[i] >>= shift;
            i++;
        } while (i < count);
    }
}

#pragma opt_common_subs reset

void VCT_DSP_SuppressEchoWithReference(short *mic, unsigned int byteCount, unsigned int threshold)
{
    VCT_DSP_SuppressEcho(mic,gEchoReferenceFrame,byteCount,threshold);
}

void VCT_DSP_MixSaturated(s16 *srcA, s16 *srcB, s16 *dst, u32 byteCount)
{
    u32 i;
    u32 count;
    s32 sum;

    count = byteCount >> 1;
    for (i = 0; i < count; i += 4) {
        sum = srcA[i] + srcB[i];
        if (sum > 0x7fff) sum = 0x7fff; else if (sum < -0x8000) sum = -0x8000;
        dst[i] = sum;
        sum = srcA[i + 1] + srcB[i + 1];
        if (sum > 0x7fff) sum = 0x7fff; else if (sum < -0x8000) sum = -0x8000;
        dst[i + 1] = sum;
        sum = srcA[i + 2] + srcB[i + 2];
        if (sum > 0x7fff) sum = 0x7fff; else if (sum < -0x8000) sum = -0x8000;
        dst[i + 2] = sum;
        sum = srcA[i + 3] + srcB[i + 3];
        if (sum > 0x7fff) sum = 0x7fff; else if (sum < -0x8000) sum = -0x8000;
        dst[i + 3] = sum;
    }
}
