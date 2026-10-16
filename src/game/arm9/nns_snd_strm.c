/*
 * file:     nns_snd_strm.c
 * unit:     yes
 * function: NNS_SndStrmInit, NNS_SndStrmAllocChannel, NNS_SndStrmFreeChannel, NNS_SndStrmSetup, NNS_SndStrmStart, NNSi_SndStrmStopIfSetup, NNS_SndStrmSetVolume, NNS_SndStrmStop, NNSi_SndStrmReleaseTimer, NNSi_SndStrmTimerCallback, NNSi_SndStrmUpdate, NNSi_SndStrmAlarmHandler
 * address:  0x020737C0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem sound stream object (NNSSndStrm shape): a PCM stream played
 * through a group of hardware channels, refilled by a callback on a timer.
 * These twelve functions are the stream's init, channel allocation, setup,
 * start, stop, volume and timer step; they are not part of the sequence
 * player in nns_snd_player.c.
 *
 * symbols:
 *   gSndStrmListReady     0x0214E8E4  data
 *   gSndStrmList     0x0214E8E8  data
 *   gSndStrmBufferTable     0x0214E8F4  data
 *   gSndStrmChannels     0x0214E934  data
 *   NNSi_SndStrmStart  0x02073CEC  arm
 *   NNS_FndInitList  0x02060468  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   NNSi_SndWaveOutAllocSlot  0x020729C0  arm
 *   SND_SetupChannelPcm  0x02089660  arm
 *   SND_SetupAlarm  0x02089540  arm
 *   NNS_FndAppendListObject  0x020604AC  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SND_CalcChannelVolume  0x0208A24C  arm
 *   SND_SetChannelVolume  0x02089638  arm
 *   SND_StopTimer  0x020894DC  arm
 *   SND_StartTimer  0x020894B4  arm
 *   PM_PrependPreSleepCallback  0x0208C808  arm
 *   PM_AppendPostSleepCallback  0x0208C828  arm
 *   PM_DeletePreSleepCallback  0x0208C86C  arm
 *   func_0208C884  0x0208C884  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   SND_FlushCommand  0x02089B38  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 *   NNSi_SndWaveOutLockChannels  0x0207292C  arm
 *   SND_CHANNEL_UnlockChannels  0x02072974  arm
 *   NNS_SndWaveOutFreeChannel  0x02072A08  arm
 *   NNS_FndRemoveListObject  0x020605B4  arm
 */
#include "nns_snd_types.h"

/* Per hardware channel of a stream: the buffer address and a volume offset. */
typedef struct SndStrmChannel {
    u32 bufferAddr;
    s32 volumeOffset;
} SndStrmChannel;

extern void NNS_FndInitList(NNSFndList *list, int offset);
extern void NNSi_SndStrmStart(void);
extern int NNSi_SndWaveOutLockChannels(int mask);
extern void SND_CHANNEL_UnlockChannels(u32 mask);
extern u32  func_0209C2B0(u32 a, s32 b);
extern s32  NNSi_SndWaveOutAllocSlot(void);
extern void SND_SetupChannelPcm(u32 chan, int fmt, u32 data, int loopmode,
                          int a, int b, int vol, int pan, u32 period, int e);
extern void SND_SetupAlarm(s32 chan, u32 a, u32 b, void (*cb)(void *), void *arg);
extern void NNS_FndAppendListObject(NNSFndList *list, void *node);
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 tok);
extern void SND_StartTimer(u32, u32, u32, u32);
extern void PM_PrependPreSleepCallback(void *);
extern void PM_AppendPostSleepCallback(void *);
extern unsigned short SND_CalcChannelVolume(int dB);
extern void SND_SetChannelVolume(u32 chBitMask, int volume, int shift);
extern void SND_StopTimer(u32 a, u32 b, u32 c, u32 d);
extern void PM_DeletePreSleepCallback(void *p);
extern void func_0208C884(void *p);
extern u32  SND_GetCurrentCommandTag(void);
extern void SND_FlushCommand(u32 a);
extern void SND_WaitForCommandProc(u32 a);
extern void NNS_SndWaveOutFreeChannel(u32 timerNo);
extern void NNS_FndRemoveListObject(volatile NNSFndList *list, void *elem);
void NNS_SndStrmInit(SndStrm *strm);
int NNS_SndStrmAllocChannel(SndStrm *strm, int numChannels, const u8 *channelList);
void NNS_SndStrmFreeChannel(SndStrm *strm);
int NNS_SndStrmSetup(SndStrm *strm, int format, u32 bufferAddr, u32 length, u32 rate, s32 frames, NNSSndStrmCallback callback, u32 userData);
void NNS_SndStrmStart(SndStrm *strm);
void NNSi_SndStrmStopIfSetup(SndStrm *strm);
void NNS_SndStrmSetVolume(SndStrm *strm, s32 volume);
void NNS_SndStrmStop(SndStrm *strm);
void NNSi_SndStrmReleaseTimer(SndStrm *strm);
void NNSi_SndStrmTimerCallback(SndStrm *strm);
void NNSi_SndStrmUpdate(SndStrm *strm, u32 isTimerCall);
void NNSi_SndStrmAlarmHandler(SndStrm *strm);

/* Set once the list of streams exists. */
extern u32  gSndStrmListReady;
/* The list of set-up streams. */
extern NNSFndList gSndStrmList;
/* Table of buffer addresses handed to the callback. */
extern u32 gSndStrmBufferTable[];
/* Per hardware channel records, indexed by channel number. */
extern SndStrmChannel gSndStrmChannels[];

/*
 * Constructor: lazily initialise the stream list behind the one-shot latch
 * gSndStrmListReady, install the two alarm handlers (NNSi_SndStrmAlarmHandler and NNSi_SndStrmStart)
 * each with the stream itself as argument, clear the channel mask and count,
 * and clear the setup and started bits of the flags word.
 *
 * PINNED ../2.0/sp2: under dsi/1.1p1 the read-modify-write of the flags word is
 * hoisted above the six stores and the two `bic` immediates collapse (116 bytes
 * against 120).  The two 1-bit clears must stay two statements: `&= ~3` folds
 * to one `bic` and loses four bytes, which proves the source clears two
 * separate 1-bit fields.
 */
void NNS_SndStrmInit(SndStrm *strm)
{
    if (gSndStrmListReady == 0) {
        NNS_FndInitList(&gSndStrmList, 0);
        gSndStrmListReady = 1;
    }
    strm->alarm[0].handler = (void (*)(void *))NNSi_SndStrmAlarmHandler;
    strm->alarm[0].arg = strm;
    strm->alarm[1].handler = (void (*)(void *))NNSi_SndStrmStart;
    strm->alarm[1].arg = strm;
    strm->channelMask = 0;
    strm->numChannels = 0;
    strm->flags &= ~1;
    strm->flags &= ~2;
}

/*
 * Locks the numChannels hardware channels named in channelList for the stream
 * and records them; returns 0 when the lock fails.
 */
int NNS_SndStrmAllocChannel(SndStrm *strm, int numChannels, const u8 *channelList)
{
    u32 mask = 0;
    int i;
    for (i = 0; i < numChannels; i++) {
        strm->channel[i] = channelList[i];
        mask |= 1u << channelList[i];
    }
    if (NNSi_SndWaveOutLockChannels(mask) == 0) return 0;
    strm->numChannels = numChannels;
    strm->channelMask = mask;
    return 1;
}

/*
 * Releases the locked channels when the stream holds any: the mask to drop is
 * the value in channelMask itself, and the same zero then clears the mask and
 * the count out of one `mov r0, #0`.
 */
void NNS_SndStrmFreeChannel(SndStrm *strm)
{
    if (strm->channelMask == 0) return;
    SND_CHANNEL_UnlockChannels(strm->channelMask);
    strm->channelMask = 0;
    strm->numChannels = 0;
}

/*
 * Sets the stream up: tear down a stream already set up, size the per-channel
 * buffer (func_0209C2B0 is the divide), claim a timer through NNSi_SndWaveOutAllocSlot
 * (negative = none, answer 0), set up one PCM channel per locked channel with
 * its buffer address recorded in gSndStrmChannels, arm the timer SND_SetupAlarm with
 * NNSi_SndStrmTimerCallback as its callback, link the stream into gSndStrmList, latch the
 * parameters, and prime one step of NNSi_SndStrmUpdate with the frame count forced
 * to 1 inside a OS_DisableInterrupts/OS_RestoreInterrupts bracket.
 *
 * One lever: the first quotient is its own statement (`size = div(...);
 * size = (size * frames) << 5;`).  Folded into one expression the multiply
 * comes out `mul r0, fp, r0` instead of the image's `mul r1, r0, fp`.
 */
int NNS_SndStrmSetup(SndStrm *strm, int format, u32 bufferAddr, u32 length,
                  u32 rate, s32 frames, NNSSndStrmCallback callback, u32 userData)
{
    u32 size;
    u32 period;
    int i;
    u32 tok;
    if (strm->isSetup) NNSi_SndStrmStopIfSetup(strm);
    size = func_0209C2B0(length, strm->numChannels * (frames << 5));
    size = (size * frames) << 5;
    strm->bufferSize = size;
    if (format == 1) size >>= 1;
    period = func_0209C2B0(rate * size, frames);
    strm->timerNo = NNSi_SndWaveOutAllocSlot();
    if (strm->timerNo < 0) return 0;
    for (i = 0; i < strm->numChannels; i++) {
        u8 channelNo = strm->channel[i];
        gSndStrmChannels[channelNo].bufferAddr = strm->bufferSize * i + bufferAddr;
        gSndStrmChannels[channelNo].volumeOffset = 0;
        SND_SetupChannelPcm(channelNo, format, gSndStrmChannels[channelNo].bufferAddr, 1, 0, strm->bufferSize >> 2,
                      0x7f, 0, rate << 5, 0x40);
    }
    SND_SetupAlarm(strm->timerNo, period, period, (void (*)(void *))NNSi_SndStrmTimerCallback, strm);
    NNS_FndAppendListObject(&gSndStrmList, strm);
    strm->format = format;
    strm->frames = frames;
    strm->callback = callback;
    strm->userData = userData;
    strm->frameIdx = 0;
    strm->volume = 0;
    strm->isSetup = 1;
    tok = OS_DisableInterrupts();
    strm->frames = 1;
    NNSi_SndStrmUpdate(strm, 0);
    strm->frames = frames;
    OS_RestoreInterrupts(tok);
    return 1;
}

/*
 * Starts the stream: begins the timer for the stream's channels and, the first
 * time, starts the two alarms and raises the started bit.
 */
void NNS_SndStrmStart(SndStrm *strm) {
    SND_StartTimer(strm->channelMask, 0, 1u << strm->timerNo, 0);
    if (strm->isStarted) return;
    PM_PrependPreSleepCallback(&strm->alarm[0]);
    PM_AppendPostSleepCallback(&strm->alarm[1]);
    strm->flags |= 2u;
}

/*
 * Stops the stream when it is set up.  Guards the call on bit 0 of the flags
 * word, which the original reads as a signed one-bit field (lsl #31 / asrs #31).
 */
void NNSi_SndStrmStopIfSetup(SndStrm *strm)
{
    if (strm->isSetup != 0) {
        NNS_SndStrmStop(strm);
    }
}

/*
 * Sets the stream volume and re-emits every active channel: each channel byte
 * indexes the 8-byte records of gSndStrmChannels, whose second word is added to the
 * base volume, converted by SND_CalcChannelVolume, and handed to SND_SetChannelVolume as
 * (1 << k, low byte, arithmetic high half).
 *
 * PINNED ../2.0/sp2 on the store/load schedule tell: the image stores the
 * volume before loading the loop bound, and 1.1p1 hoists the load above the
 * store at every spelling tried (11 bytes out).
 *
 * Two shape levers: the `numChannels <= 0` guard must NOT be written as a
 * separate early return (that emits a second `cmp r0,#0`; the bare `for` gives
 * the single predicated `pople`), and `u32 k` must be declared BEFORE `s32 i`
 * or the two swap r5/r6.
 */
void NNS_SndStrmSetVolume(SndStrm *strm, s32 volume)
{
    u32 k;
    s32 i;
    strm->volume = volume;
    for (i = 0; i < strm->numChannels; i++) {
        s32 r;
        k = strm->channel[i];
        r = SND_CalcChannelVolume(strm->volume + gSndStrmChannels[k].volumeOffset);
        SND_SetChannelVolume((u32)(1 << k), (u32)r & 0xff, r >> 8);
    }
}

/*
 * Stops the stream: when it was started, stops its timer channels, stops the
 * two alarms, clears the started bit and brackets SND_FlushCommand(1) with the
 * save/restore pair SND_GetCurrentCommandTag / SND_WaitForCommandProc.  The unguarded tail call to
 * NNSi_SndStrmReleaseTimer runs either way.
 *
 * PINNED ../2.0/sp2 on the repeated-small-constant tell: the literal 1 is live
 * twice (the `1 << timerNo` shift argument and the SND_FlushCommand argument), and
 * 1.1p1 pools it into a callee-saved register where the image rematerialises
 * it.  The guard is a SIGNED one-bit bitfield: the image reads it
 * `lsl #30 / asrs #31`.
 */
void NNS_SndStrmStop(SndStrm *strm)
{
    if (strm->isStarted) {
        u32 saved;
        SND_StopTimer(strm->channelMask, 0, 1u << strm->timerNo, 0);
        PM_DeletePreSleepCallback(&strm->alarm[0]);
        func_0208C884(&strm->alarm[1]);
        strm->isStarted = 0;
        saved = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(saved);
    }
    NNSi_SndStrmReleaseTimer(strm);
}

/*
 * Frees the timer, takes the stream off the list and clears the setup bit.
 * `flags &= ~1` is the bic spelling: the masked-assignment form is what this
 * front end turns into `bic r0, r0, #1` without a materialised mask.
 */
void NNSi_SndStrmReleaseTimer(SndStrm *strm)
{
    NNS_SndWaveOutFreeChannel(strm->timerNo);
    NNS_FndRemoveListObject(&gSndStrmList, strm);
    strm->flags &= ~1;
}

/* The timer callback NNS_SndStrmSetup installs: steps the stream with isTimerCall = 1. */
void NNSi_SndStrmTimerCallback(SndStrm *strm)
{
    NNSi_SndStrmUpdate(strm, 1);
}

/*
 * Per-frame step of the stream: base = bufferSize / frames, fill the address
 * table with each channel's buffer address plus base * frameIdx, hand the table
 * to the callback, then advance the frame counter and wrap it at frames.
 *
 * The callback's argument list is (isTimerCall, numChannels, table, base,
 * format, userData).  Declaration order step, i, base, and the channel's buffer
 * address bound to its own local before the add, close the register choice.
 */
void NNSi_SndStrmUpdate(SndStrm *strm, u32 isTimerCall)
{
    u32 step;
    s32 i;
    u32 base;
    u32 addr;
    base = func_0209C2B0(strm->bufferSize, strm->frames);
    step = base * strm->frameIdx;
    for (i = 0; i < strm->numChannels; i++) {
        addr = gSndStrmChannels[strm->channel[i]].bufferAddr;
        gSndStrmBufferTable[i] = addr + step;
    }
    strm->callback(isTimerCall, strm->numChannels, gSndStrmBufferTable, base, strm->format, strm->userData);
    strm->frameIdx = strm->frameIdx + 1;
    if (strm->frameIdx >= strm->frames) strm->frameIdx = 0;
}

/*
 * Alarm handler: when the stream was started, stops its timer channels and
 * brackets SND_FlushCommand(1) with SND_GetCurrentCommandTag / SND_WaitForCommandProc.  It is
 * NNS_SndStrmStop's tail without the alarm teardowns.
 *
 * PINNED ../2.0/sp2 on the repeated-small-constant tell, as NNS_SndStrmSetVolume and
 * NNS_SndStrmStop are.
 */
void NNSi_SndStrmAlarmHandler(SndStrm *strm)
{
    u32 saved;
    if (!strm->isStarted) return;
    SND_StopTimer(strm->channelMask, 0, 1u << strm->timerNo, 0);
    saved = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(saved);
}
