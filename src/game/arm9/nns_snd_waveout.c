/*
 * file:     nns_snd_waveout.c
 * unit:     yes
 * function: NNSi_SndWaveOutLockChannels, SND_CHANNEL_UnlockChannels, SND_CHANNEL_ClearClaimedMask, NNSi_SndWaveOutAllocSlot, NNS_SndWaveOutFreeChannel, NNS_SndWaveOutInit, NNS_SndWaveOutAllocChannel, NNSi_SndWaveOutUnlockChannel, NNS_SndWaveOutStart, NNS_SndWaveOutStop, NNS_SndWaveOutSetVolume, NNS_SndWaveOutSetSpeed, NNS_SndWaveOutIsPlaying, NNS_SndWaveOutWaitIdle
 * address:  0x0207292C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * NitroSystem wave-out channel allocator (NNS_SndWaveOut*): a global allocator
 * state (claimed mask, used-slot bitmap, locked-channel mask) and a table of
 * eight stride-0x14 wave-out handles.
 *
 * Compiler pins:
 *   - NNSi_SndWaveOutUnlockChannel is built by ../1.2/sp2: the image issues the callee's pool
 *     load into ip before the shift that computes the last argument, an order
 *     dsi/1.1p1 cannot emit.
 *   - NNSi_SndWaveOutLockChannels, NNSi_SndWaveOutAllocSlot, NNS_SndWaveOutStart, NNS_SndWaveOutStop and
 *     NNS_SndWaveOutWaitIdle are pinned to ../2.0/sp2 (the "kept constants" tell,
 *     docs/FRONTEND-PINS.md): the image rematerialises literals 0 and 1 at each
 *     use, while 1.1p1 keeps them in callee-saved registers.
 *   - The period computation is a chained 64-bit division of the constant
 *     0x7FD87F8000 (half the system clock times 0x8000) by the sample rate and
 *     the frequency ratio, clamped to [0x10, 0xFFFF] as exclusive arms of one
 *     if/else (two independent ifs if-convert and no longer match).
 *
 * symbols:
 *   SND_LockChannel  0x020895D8  arm
 *   gNNSSndWaveOutState     0x0214DEC0  data
 *   SND_UnlockChannel    0x020895F8  arm
 *   gNNSSndWaveOutHandles       0x0214DECC  data
 *   SND_SetupChannelPcm  0x02089660  arm
 *   SND_StartTimer  0x020894B4  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   _ll_udiv       0x0209C00C  arm
 *   SND_StopTimer  0x020894DC  arm
 *   SND_SetChannelTimer  0x02089618  arm
 *   SND_IsFinishedCommandTag 0x02089D6C  arm
 *   SND_GetChannelStatus 0x0208A07C  arm
 *   SND_FlushCommand   0x02089B38  arm
 *   SND_WaitForCommandProc   0x02089CD4  arm
 *   SND_SetChannelVolume  0x02089638  arm
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned char  u8;
typedef unsigned short u16;

/* Allocator state at 0x0214DEC0. */
struct NNSSndWaveOutState {
    u32 claimedChannelMask;
    u32 usedSlotMask;
    u32 lockedChannelMask;
};

/* One wave-out channel handle (stride 0x14). */
typedef struct NNSSndWaveOutHandle {
    u32 channelNo;   /* 0x00  hardware channel index; mask is 1u << this */
    int baseRate;    /* 0x04  sample rate latched at start, divisor for speed changes */
    u32 active;      /* 0x08  liveness guard */
    u32 started;     /* 0x0C  start command already acknowledged */
    u32 commandTag;  /* 0x10  SND command tag to wait for */
} NNSSndWaveOutHandle;

extern void SND_LockChannel(u32 chBitMask, u32 flags);
extern void SND_UnlockChannel(u32 channelMask, u32 flags);
extern void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan);
extern void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
extern u32  SND_GetCurrentCommandTag(void);
extern void SND_StopTimer(u32 chan, u32 a, u32 b, u32 c);
extern void SND_SetChannelVolume(u32 chBitMask, int volume, int shift);
extern void SND_SetChannelTimer(u32 chBitMask, int timer);
extern int SND_IsFinishedCommandTag(u32 tag);
extern u32 SND_GetChannelStatus(void);
extern void SND_FlushCommand(int v);
extern void SND_WaitForCommandProc(u32 tag);
int NNSi_SndWaveOutLockChannels(int mask);
void SND_CHANNEL_UnlockChannels(u32 channelMask);
void SND_CHANNEL_ClearClaimedMask(u32 channelMask);
int NNSi_SndWaveOutAllocSlot(void);
void NNS_SndWaveOutFreeChannel(u32 slotNo);
void NNS_SndWaveOutInit(void);
NNSSndWaveOutHandle *NNS_SndWaveOutAllocChannel(u32 slotNo);
void NNSi_SndWaveOutUnlockChannel(u32 *channelNoPtr);
int NNS_SndWaveOutStart(NNSSndWaveOutHandle *handle, int format, void *waveData, int loopFlag, int loopStart, int loopEnd, int sampleRate, int volume, int playFreq, int pan);
void NNS_SndWaveOutStop(NNSSndWaveOutHandle *handle);
void NNS_SndWaveOutSetVolume(NNSSndWaveOutHandle *handle, u32 volume);
void NNS_SndWaveOutSetSpeed(NNSSndWaveOutHandle *handle, int speed);
int NNS_SndWaveOutIsPlaying(NNSSndWaveOutHandle *handle);
void NNS_SndWaveOutWaitIdle(NNSSndWaveOutHandle *handle);
extern struct NNSSndWaveOutState gNNSSndWaveOutState;
extern NNSSndWaveOutHandle gNNSSndWaveOutHandles[];

/* Locks every channel in mask; 0 if any is already locked, 1 on success. */
int NNSi_SndWaveOutLockChannels(int mask)
{
    if (mask == 0) return 1;
    if ((mask & gNNSSndWaveOutState.lockedChannelMask) != 0) return 0;
    SND_LockChannel(mask, 0);
    gNNSSndWaveOutState.lockedChannelMask |= mask;
    return 1;
}

/* Unlocks the channels in mask and drops them from the locked mask (+0x08). */
void SND_CHANNEL_UnlockChannels(u32 channelMask)
{
    if (channelMask == 0) {
        return;
    }
    SND_UnlockChannel(channelMask, 0);
    gNNSSndWaveOutState.lockedChannelMask &= ~channelMask;
}

/*
 * Clears a mask (not an index) from the claimed-channel word at +0x00.  The
 * image complements the parameter itself (`mvn r0, r0`).  Matches under both
 * 1.1p1 and 2.0/sp2.
 */
void SND_CHANNEL_ClearClaimedMask(u32 channelMask)
{
    gNNSSndWaveOutState.claimedChannelMask &= ~channelMask;
}

/*
 * Allocates the first free slot of the 8-bit bitmap at +0x04 and returns its
 * index, or -1.  The hit arm re-reads usedSlotMask (a separate copy plus a
 * plain |= store); the loop bound is the literal 8.
 */
int NNSi_SndWaveOutAllocSlot(void)
{
    int bit = 1;
    int usedMask = gNNSSndWaveOutState.usedSlotMask;
    int slotNo;
    for (slotNo = 0; slotNo < 8; slotNo++) {
        if ((usedMask & bit) == 0) {
            gNNSSndWaveOutState.usedSlotMask |= bit;
            return slotNo;
        }
        bit <<= 1;
    }
    return -1;
}

/*
 * Frees one slot of the bitmap at +0x04.  The parameter is an index: the shift
 * happens inside the complement, `~(1u << slotNo)`, as one expression.
 */
void NNS_SndWaveOutFreeChannel(u32 slotNo)
{
    gNNSSndWaveOutState.usedSlotMask &= ~(1U << slotNo);
}

void NNS_SndWaveOutInit(void)
{
    struct NNSSndWaveOutState *state = (struct NNSSndWaveOutState *)0x0214DEC0;
    state->lockedChannelMask = 0;
    state->claimedChannelMask = 0;
    state->usedSlotMask = 0;
}

/* Locks channel slotNo, seeds its handle in the table and returns it (0 if the channel is taken). */
NNSSndWaveOutHandle *NNS_SndWaveOutAllocChannel(u32 slotNo)
{
    NNSSndWaveOutHandle *handle;

    if (NNSi_SndWaveOutLockChannels(1 << slotNo) == 0) {
        return 0;
    }
    handle = &gNNSSndWaveOutHandles[slotNo];
    handle->channelNo = slotNo;
    handle->active = 0;
    return handle;
}

/* Tail-call wrapper: SND_CHANNEL_UnlockChannels(1 << *channelNoPtr). Pinned ../1.2/sp2. */
void NNSi_SndWaveOutUnlockChannel(u32 *channelNoPtr)
{
    SND_CHANNEL_UnlockChannels(1 << *channelNoPtr);
}

/*
 * Starts one PCM channel: converts the loop points to sample units for the
 * format (0 = PCM8: >>2, 1 = PCM16: >>1, 2 = ADPCM: >>3), computes the timer
 * period, sets the channel up, starts it and records the command tag.  The
 * three format arms are a switch with an explicit empty default (an if/else
 * chain gets if-converted).  Pinned ../2.0/sp2.
 */
int NNS_SndWaveOutStart(NNSSndWaveOutHandle *handle, int format, void *waveData, int loopFlag,
                  int loopStart, int loopEnd, int sampleRate, int volume, int playFreq, int pan)
{
    int loopStartUnits;
    int loopLength;
    u64 timer;

    switch (format) {
    case 0:
        loopStartUnits = loopStart >> 2;
        loopLength = (loopEnd >> 2) - loopStartUnits;
        break;
    case 1:
        loopStartUnits = loopStart >> 1;
        loopLength = (loopEnd >> 1) - loopStartUnits;
        break;
    case 2:
        loopStartUnits = loopStart >> 3;
        loopLength = (loopEnd >> 3) - loopStartUnits;
        break;
    default:
        break;
    }
    timer = 0x7FD87F8000ULL / sampleRate / playFreq;
    if (timer < 0x10) {
        timer = 0x10;
    } else if (timer > 0xFFFF) {
        timer = 0xFFFF;
    }
    SND_SetupChannelPcm(handle->channelNo, format, waveData, loopFlag != 0 ? 1 : 2,
                  loopStartUnits, loopLength, volume, 0, (u32)timer, pan);
    SND_StartTimer(1 << handle->channelNo, 0, 0, 0);
    handle->active = 1;
    handle->started = 0;
    handle->commandTag = SND_GetCurrentCommandTag();
    handle->baseRate = sampleRate;
    return 1;
}

/* Stops the channel if the handle is active and clears the guard. Pinned ../2.0/sp2. */
void NNS_SndWaveOutStop(NNSSndWaveOutHandle *handle)
{
    if (handle->active == 0) {
        return;
    }
    SND_StopTimer(1 << handle->channelNo, 0, 0, 0);
    handle->active = 0;
}

void NNS_SndWaveOutSetVolume(NNSSndWaveOutHandle *handle, u32 volume)
{
    if (handle->active == 0) return;
    SND_SetChannelVolume(1 << handle->channelNo, volume, 0);
}

/* Writes the channel timer period: 0x7FD87F8000 / baseRate / speed, clamped (see file header). */
void NNS_SndWaveOutSetSpeed(NNSSndWaveOutHandle *handle, int speed)
{
    u64 timer;

    if (handle->active == 0) {
        return;
    }
    timer = 0x7FD87F8000ULL / handle->baseRate / speed;
    if (timer < 0x10) {
        timer = 0x10;
    }
    else if (timer > 0xFFFF) {
        timer = 0xFFFF;
    }
    SND_SetChannelTimer(1 << handle->channelNo, (u32)timer);
}

int NNS_SndWaveOutIsPlaying(NNSSndWaveOutHandle *handle)
{
    u32 channelStatus;

    if (handle->active == 0) return 0;
    if (handle->started == 0) {
        if (SND_IsFinishedCommandTag(handle->commandTag) == 0) return 1;
        handle->started = 1;
    }
    channelStatus = SND_GetChannelStatus();
    if (channelStatus & (1u << handle->channelNo)) return 1;
    handle->active = 0;
    return 0;
}

/*
 * Waits for the channel to go idle.  Handle inactive: wake the voice once its
 * channel bit is set and flush.  Handle active: acknowledge the start command
 * if not yet done, then spin until the channel bit clears.  Pinned ../2.0/sp2.
 */
void NNS_SndWaveOutWaitIdle(NNSSndWaveOutHandle *handle)
{
    u32 commandTag;

    if (handle->active == 0) {
        if ((SND_GetChannelStatus() & (1 << handle->channelNo)) == 0)
            return;
        commandTag = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(commandTag);
    } else {
        if (handle->started == 0) {
            SND_WaitForCommandProc(handle->commandTag);
            handle->started = 1;
        }
        while (SND_GetChannelStatus() & (1 << handle->channelNo))
            ;
    }
}
