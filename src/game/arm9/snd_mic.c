/*
 * file:     snd_mic.c
 * unit:     yes
 * function: SND_MIC_Init, SND_MIC_Exit, SND_MIC_AddElapsed, SND_MIC_IsLimitReached, SND_MIC_StartSampling, SND_MIC_StartRecording, SND_MIC_StoreRecording, SND_MIC_GetBufferAligned
 * address:  0x02006CBC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pm_voice.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc       0x02030734  arm
 *   GFL_HEAP_Free       0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   PM_SetAmp  0x0208BEF0  arm
 *   PM_SetAmpGain  0x0208BF38  arm
 *   MIC_Init  0x0208B24C  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   SNDEXi_SetIirFilter  0x027047C0  arm  twl
 *   _SndMicFile         0x020A703C  data
 *   _MicIirFilter       0x020A7030  data
 *   _SndMic             0x02146164  data
 *   PERAPVOICE_Pack  0x02007BD0  thumb
 *   MIC_StartLimitedSampling    0x0208B500  arm
 */
#include "pm_voice_shared_types.h"

#include "mic.h"

/* Microphone work area (0x28 bytes) allocated by SND_MIC_Init. */
struct SndMic {
    struct MICAutoParam param;  /* 00 */
    u32 sampling;               /* 1C: set once sampling was requested */
    union {                     /* 20 */
        u32 word;
        struct {
            u32 recording : 1;
            u32 elapsed : 31;   /* ticks recorded so far */
        } bits;
    } status;
    void *sampleBuffer;         /* 24 */
};

/* Calls into the voice channel layer and the other data readers. */
#include "gfl_heap_wrap.h"


#include "mi_memory.h"

#include "pm.h"



#include "os_emulator.h"

#include "../twl/sndex.h"

struct PerapVoice;

#include "perapvoice.h"

/* microphone (snd_mic.c part of this file) */
void SND_MIC_Init(u16 heapId);

void SND_MIC_Exit(void);

void SND_MIC_AddElapsed(u32 ticks);

u32 SND_MIC_IsLimitReached(void);

u32 SND_MIC_StartSampling(const struct MICAutoParam *param);

u32 SND_MIC_StartRecording(MICCallback callback, void *arg);

void SND_MIC_StoreRecording(struct PerapVoice *perapVoice);

void *SND_MIC_GetBufferAligned(void);

extern char _SndMicFile[];

extern u8 _MicIirFilter[];

extern struct SndMic *_SndMic;

/*
 * Allocate the microphone work area (0x28 bytes) and its 0x2014 byte sample
 * buffer, both with the file name "snd_mic.c" as the site (lines 0x59 and
 * 0x5f). The buffer is linked in at +0x24 before the hardware is set up:
 * amplifier on with gain 2, microphone init, and on a DSi the IIR filter
 * table. The recording bit is cleared and set again (bics for the clear).
 */
void SND_MIC_Init(u16 heapId)
{
    struct SndMic *mic;
    void *sampleBuffer;

    mic = GFL_HEAP_Alloc(heapId, 0x28, 0, _SndMicFile, 0x59);
    MI_CpuFill8(mic, 0, 0x28);
    sampleBuffer = GFL_HEAP_Alloc(heapId, 0x2014, 0, _SndMicFile, 0x5f);
    MI_CpuFill8(sampleBuffer, 0, 0x2014);
    mic->sampleBuffer = sampleBuffer;
    PM_SetAmp(1);
    PM_SetAmpGain(2);
    mic->status.word = (mic->status.word & ~1u) | 1u;
    MIC_Init();
    if (OS_IsRunOnTwl() == 1) {
        SNDEXi_SetIirFilter(0, (u16 *)_MicIirFilter);
    }
    _SndMic = mic;
}

/*
 * Tail of the microphone code. The word at +0x20 is two bitfields (bit 0 and
 * a 31 bit counter), and all of D44..D94 turn on that declaration: the
 * counter is read with a bare `lsrs r0, r0, #1` (correct only because the
 * field runs to the top of the word) and written back with a read modify
 * write that keeps bit 0; the one bit is tested with lsls #0x1f / lsrs #0x1f.
 * The range starts at 0x02006D44 because 0x02006D3C is a linker veneer
 * (ldr pc, [pc, #-4]) over 0x027047C0.
 */
void SND_MIC_Exit(void)
{
    PM_SetAmp(0);
    GFL_HEAP_Free(_SndMic->sampleBuffer);
    GFL_HEAP_Free(_SndMic);
}

/* Add `ticks` to the recorded time while recording and below the limit. */
void SND_MIC_AddElapsed(u32 ticks)
{
    struct SndMic *mic = _SndMic;

    if (mic->status.bits.recording) {
        if (SND_MIC_IsLimitReached() == 0) {
            mic->status.bits.elapsed += ticks;
        }
    }
}

/* 1 once more than 180 ticks were recorded. */
u32 SND_MIC_IsLimitReached(void)
{
    if (_SndMic->status.bits.elapsed > 0xB4) {
        return 1;
    }
    return 0;
}

/*
 * Start sampling with a request (the SDK call is MIC_StartLimitedSampling)
 * and keep a copy of the request. The global pointer is read twice, once for
 * the flag word and once for the copy, because the store through the first
 * load can alias the pointer itself. The copy is the unrolled aggregate
 * assignment of the seven word request (three ldm/stm pairs and a trailing
 * ldr/str).
 */
u32 SND_MIC_StartSampling(const struct MICAutoParam *param)
{
    u32 result = MIC_StartLimitedSampling((MICAutoParam *)param);

    _SndMic->sampling = 1;
    _SndMic->param = *param;
    return result;
}

/*
 * Record into the work buffer with a full-buffer callback. The size is
 * rounded down to a multiple of 32 by a live test and mask (movs r0, #0x1f;
 * tst r0, r1; beq; movs r0, #0x1f; bics r1, r0): the mask is materialised
 * twice because Thumb has no immediate bic, and the compiler does not fold
 * it, so the guard is in the source.
 */
u32 SND_MIC_StartRecording(MICCallback callback, void *arg)
{
    struct MICAutoParam param;

    param.type = 2;
    param.buffer = SND_MIC_GetBufferAligned();
    param.size = 0x1FF4;
    if (param.size & 0x1F) {
        param.size &= ~0x1Fu;
    }
    param.rate = 0x1001;
    param.loop_enable = 0;
    param.full_callback = callback;
    param.full_arg = arg;
    return SND_MIC_StartSampling(&param);
}

/* Copy the recorded buffer into a Perap voice (Chatot) record. */
void SND_MIC_StoreRecording(struct PerapVoice *perapVoice)
{
    void *buffer = SND_MIC_GetBufferAligned();

    PERAPVOICE_Pack(perapVoice, buffer);
}

/*
 * The sample buffer address rounded up to a multiple of 32. The mask is
 * materialised in r1 and applied with bics (Thumb has no immediate bic);
 * the compiler hoists the movs above both loads.
 */
void *SND_MIC_GetBufferAligned(void)
{
    return (void *)(((u32)_SndMic->sampleBuffer + 0x1F) & ~0x1Fu);
}
