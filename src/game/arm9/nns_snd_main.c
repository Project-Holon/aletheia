/*
 * file:     nns_snd_main.c
 * unit:     yes
 * function: NNSi_SndStrmStart, NNSi_SndMainReset, NNS_SndMain, NNSi_SndShutdown, NNS_SndStartTimer, NNSi_SndCaptureReset, NNS_SndArcInit, NNSi_SndArcLoadTables, NNS_SndArcInitOnMemory
 * address:  0x02073CEC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * NitroSystem sound main (snd_main.c) and sound archive (snd_arc.c) pieces:
 * global system init, per-frame update, timer start/stop, the capture reset,
 * and archive open / header load / in-memory relocation.
 *
 * Compiler pins: NNSi_SndCaptureReset and NNS_SndArcInitOnMemory are ../2.0/sp2 (under 1.1p1 the
 * three separate `mov r0,#0` pool into one callee-saved register).
 *
 * symbols:
 *   gNNSSndSystemFlag       0x0214E9B4  data
 *   gNNSSndSystem       0x0214E9FC  data
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   SND_SetChannelVolume  0x02089638  arm
 *   gNNSSndMessageQueue     0x0214E9BC  data
 *   SND_StopTimer  0x020894DC  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   SND_FlushCommand  0x02089B38  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 *   OS_ReceiveMessage  0x02085E50  arm
 *   SND_CHANNEL_ClearClaimedMask  0x020729A4  arm
 *   SND_CHANNEL_UnlockChannels  0x02072974  arm
 *   NNS_SndWaveOutFreeChannel  0x02072A08  arm
 *   SND_SetOutputSelector  0x0208972C  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   DC_FlushRange  0x020862F0  arm
 *   SND_StartTimer  0x020894B4  arm
 *   gNNSSndCurrentArc   0x0214EA50  data
 *   FS_ConvertPathToFileID  0x020788D8  arm
 *   FS_InitFile  0x020788AC  arm
 *   FS_OpenFileFast  0x020789A4  arm
 *   FS_SeekFile  0x02078B44  arm
 *   FS_ReadFile  0x02078B70  arm
 *   NNS_SndHeapAlloc  0x0207482C  arm
 *   NNSi_SndArcDisposeInfo  0x020746C4  arm
 *   NNSi_SndArcDisposeFat  0x020746D0  arm
 *   NNSi_SndArcDisposeSymbol  0x020746DC  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   NNSi_SndStrmUpdate  0x02073BF0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
#include "nns_snd_main_types.h"

struct LerpObj;
struct Obj;

extern void NNSi_SndStrmUpdate(NNSSndStrm *, u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void SND_StartTimer(u32, u32, u32, u32);
extern void NNS_SndFaderUpdate(struct LerpObj *fader);
extern int NNS_SndFaderIsFinished(struct LerpObj *fader);
extern s32 NNS_SndFaderGet(struct Obj *fader);
extern void SND_SetChannelVolume(u32 chBitMask, s32 volume, s32 shift);
extern void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, s32 flags);
extern s32  SND_GetCurrentCommandTag(void);
extern void SND_FlushCommand(s32 flush);
extern void SND_WaitForCommandProc(s32 commandTag);
extern s32  OS_ReceiveMessage(void *messageQueue, s32 message, s32 flags);
extern void SND_CHANNEL_ClearClaimedMask(u32 mask);
extern void SND_CHANNEL_UnlockChannels(u32 chan);
extern void NNS_SndWaveOutFreeChannel(u32 alarmNo);
extern void SND_SetOutputSelector(s32 left, s32 right, s32 mix, s32 flags);
extern void MIi_CpuClear32(u32 value, u32 dst, u32 size);
extern void DC_FlushRange(u32 start, u32 size);
extern u32  FS_ConvertPathToFileID(FSFileID *id, const char *path);
extern void FS_InitFile(FSFile *file);
extern u32  FS_OpenFileFast(FSFile *file, FSFileID id);
extern int   FS_SeekFile(FSFile *file, u32 position, int origin);
extern int   FS_ReadFile(FSFile *file, void *dst, int length);
extern void *NNS_SndHeapAlloc(u32 *heap, u32 size, void (*freeCallback)(void *, u32, NNSSndArc *),
                           NNSSndArc *arc, u32 allocId);
extern void  NNSi_SndArcDisposeInfo(void *block, u32 size, NNSSndArc *arc);
extern void  NNSi_SndArcDisposeFat(void *block, u32 size, NNSSndArc *arc);
extern void  NNSi_SndArcDisposeSymbol(void *block, u32 size, NNSSndArc *arc);
extern void MIi_CpuCopy32(void *dst, void *src, u32 length);
void NNSi_SndStrmStart(NNSSndStrm *strm);
void NNSi_SndMainReset(void);
void NNS_SndMain(void);
void NNSi_SndShutdown(void);
void NNS_SndStartTimer(void);
void NNSi_SndCaptureReset(void);
u32 NNS_SndArcInit(NNSSndArc *arc, const char *path, u32 *heap, u32 loadSymbols);
u32 NNSi_SndArcLoadTables(NNSSndArc *arc, u32 *heap, u32 loadSymbols);
void NNS_SndArcInitOnMemory(NNSSndArc *arc, u8 *base);
extern u32 gNNSSndSystemFlag;
extern NNSSndSystem gNNSSndSystem;
extern u8   gNNSSndMessageQueue[];
extern NNSSndArc *gNNSSndCurrentArc;

/* Drains the pending frames of a stream, then starts its channel timer. */
void NNSi_SndStrmStart(NNSSndStrm *strm) {
    u32 savedIrq;
    if (!strm->isStarted) return;
    while (strm->pendingFrames != 0) {
        savedIrq = OS_DisableInterrupts();
        NNSi_SndStrmUpdate(strm, 1);
        OS_RestoreInterrupts(savedIrq);
    }
    SND_StartTimer(strm->channelMask, 0, 1u << strm->alarmNo, 0);
}

/* Marks the sound system as not initialized. */
void NNSi_SndMainReset(void)
{
    gNNSSndSystemFlag = 0;
    gNNSSndSystem.initialized = 0;
}

/*
 * Per-frame update: advances the master-volume fader and pushes a changed
 * volume to the timer channels; when the fade has finished it shuts the system
 * down through NNSi_SndShutdown.
 */
void NNS_SndMain(void)
{
    NNSSndSystem *sndSystem;
    s32 volume;

    sndSystem = &gNNSSndSystem;
    if (sndSystem->initialized == 0) {
        return;
    }
    if (sndSystem->mode != 0) {
        return;
    }

    NNS_SndFaderUpdate((struct LerpObj *)sndSystem->fader);

    if (sndSystem->fadeFinishCheck != 0 && NNS_SndFaderIsFinished((struct LerpObj *)sndSystem->fader) != 0) {
        NNSi_SndShutdown();
        return;
    }

    volume = NNS_SndFaderGet((struct Obj *)sndSystem->fader) >> 8;
    if (volume == sndSystem->lastVolume) {
        return;
    }
    SND_SetChannelVolume(sndSystem->timerChannelMask, volume, 0);
    sndSystem->lastVolume = volume;
}

/*
 * Shutdown of the global sound system: stop the timer, and when it owns an
 * alarm save/mute/restore the command driver and spin until the message queue
 * reports idle; then free the capture mask, the locked channels and the alarm,
 * reset the output selector in mode 1, and clear the initialized flag.
 *
 * The two extern signatures are load-bearing: SND_CHANNEL_ClearClaimedMask and
 * SND_CHANNEL_UnlockChannels each take the field their guard just tested
 * (`u32 mask`, `u32 chan`); declared void(void) the three callee-saved locals
 * rotate.
 */
void NNSi_SndShutdown(void)
{
    NNSSndSystem *sndSystem;
    s32  hasAlarm;
    s32  commandTag;
    s32  zero;

    sndSystem = &gNNSSndSystem;
    if (sndSystem->initialized == 0) {
        return;
    }

    hasAlarm = (sndSystem->timerAlarmNo >= 0);
    SND_StopTimer(sndSystem->timerChannelMask, sndSystem->timerCaptureMask, hasAlarm ? (u32)(1 << sndSystem->timerAlarmNo) : 0, 0);

    if (hasAlarm) {
        commandTag = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(commandTag);
        zero = 0;
        while (OS_ReceiveMessage(gNNSSndMessageQueue, zero, zero) != 0)
            ;
    }

    if (sndSystem->timerCaptureMask != 0) {
        SND_CHANNEL_ClearClaimedMask(sndSystem->timerCaptureMask);
    }
    if (sndSystem->lockedChannelMask != 0) {
        SND_CHANNEL_UnlockChannels(sndSystem->lockedChannelMask);
    }
    if (hasAlarm) {
        NNS_SndWaveOutFreeChannel(sndSystem->timerAlarmNo);
    }
    if (sndSystem->mode == 1) {
        SND_SetOutputSelector(0, 0, 0, 0);
    }
    sndSystem->initialized = 0;
}

void NNS_SndStartTimer(void) {
    NNSSndSystem *sndSystem = &gNNSSndSystem;
    u32 alarmMask;
    u32 commandTag;
    if (sndSystem->initialized == 0) return;
    if ((int)sndSystem->timerAlarmNo >= 0) alarmMask = 1u << sndSystem->timerAlarmNo;
    else alarmMask = 0;
    SND_StopTimer(sndSystem->timerChannelMask, sndSystem->timerCaptureMask, alarmMask, 0);
    commandTag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(commandTag);
}

/*
 * Capture reset: clears the capture flag, zero-fills and flushes both effect
 * buffers, then restarts the timer with the alarm mask built from timerAlarmNo.
 *
 * The mask arm must be written condition-first (`if (alarmNo >= 0) mask = 1u <<
 * alarmNo; else mask = 0;`), which gives `movge r0,#1` / `lslge` / `movlt`;
 * timerAlarmNo is therefore signed.  Pinned ../2.0/sp2.
 */
void NNSi_SndCaptureReset(void)
{
    NNSSndSystem *sndSystem = &gNNSSndSystem;
    u32 alarmMask;

    if (sndSystem->initialized == 0) return;
    sndSystem->captureActive = 0;
    MIi_CpuClear32(0, sndSystem->effectBufferL, sndSystem->effectBufferSize);
    MIi_CpuClear32(0, sndSystem->effectBufferR, sndSystem->effectBufferSize);
    DC_FlushRange(sndSystem->effectBufferL, sndSystem->effectBufferSize);
    DC_FlushRange(sndSystem->effectBufferR, sndSystem->effectBufferSize);
    if (sndSystem->timerAlarmNo >= 0) alarmMask = 1u << sndSystem->timerAlarmNo;
    else alarmMask = 0;
    SND_StartTimer(sndSystem->timerChannelMask, sndSystem->timerCaptureMask, alarmMask, 0);
}

/*
 * Opens a sound archive by path.  The path is forwarded untouched to
 * FS_ConvertPathToFileID; keeping it live across the four zero stores is what
 * parks the zero in ip.
 */
u32 NNS_SndArcInit(NNSSndArc *arc, const char *path, u32 *heap, u32 loadSymbols)
{
    arc->infoBlock = 0;
    arc->fatBlock = 0;
    arc->symbolBlock = 0;
    arc->readChunkSize = 0;
    if (FS_ConvertPathToFileID(&arc->fileId, path) == 0) return 0;
    FS_InitFile(&arc->file);
    if (FS_OpenFileFast(&arc->file, arc->fileId) == 0) return 0;
    arc->fileOpen = 1;
    if (NNSi_SndArcLoadTables(arc, heap, loadSymbols) == 0) return 0;
    gNNSSndCurrentArc = arc;
    return 1;
}

/*
 * Loads the archive header: seek to 0 and read the 0x30-byte header over the
 * object, then (only with a heap) allocate and read the info, FAT and, when
 * loadSymbols is set and the symbol block is non-empty, the symbol block.  Each
 * allocation goes through NNS_SndHeapAlloc with a release callback that nulls the
 * matching pointer.
 *
 * The heap test is a wrapping `if (heap != 0) { ... }` so the null case
 * branches to the shared `return 1`, and each read length is a named local,
 * which puts it in cmp's left slot.
 */
u32 NNSi_SndArcLoadTables(NNSSndArc *arc, u32 *heap, u32 loadSymbols)
{
    int bytesRead;

    if (FS_SeekFile(&arc->file, 0, 0) == 0) return 0;
    if (FS_ReadFile(&arc->file, arc, 0x30) != 0x30) return 0;
    if (heap != 0) {
        arc->infoBlock = NNS_SndHeapAlloc(heap, arc->infoSize, NNSi_SndArcDisposeInfo, arc, 0);
        if (arc->infoBlock == 0) return 0;
        if (FS_SeekFile(&arc->file, arc->infoOffset, 0) == 0) return 0;
        bytesRead = FS_ReadFile(&arc->file, arc->infoBlock, arc->infoSize);
        if (bytesRead != arc->infoSize) return 0;

        arc->fatBlock = NNS_SndHeapAlloc(heap, arc->fatSize, NNSi_SndArcDisposeFat, arc, 0);
        if (arc->fatBlock == 0) return 0;
        if (FS_SeekFile(&arc->file, arc->fatOffset, 0) == 0) return 0;
        bytesRead = FS_ReadFile(&arc->file, arc->fatBlock, arc->fatSize);
        if (bytesRead != arc->fatSize) return 0;

        if (loadSymbols != 0 && arc->symbolSize != 0) {
            arc->symbolBlock = NNS_SndHeapAlloc(heap, arc->symbolSize, NNSi_SndArcDisposeSymbol, arc, 0);
            if (arc->symbolBlock == 0) return 0;
            if (FS_SeekFile(&arc->file, arc->symbolOffset, 0) == 0) return 0;
            bytesRead = FS_ReadFile(&arc->file, arc->symbolBlock, arc->symbolSize);
            if (bytesRead != arc->symbolSize) return 0;
        }
    }
    return 1;
}

/*
 * Relocates a freshly loaded archive image in place and publishes it (the
 * in-memory counterpart of NNSi_SndArcLoadTables): copy the 0x30-byte header to the
 * start of the image buffer, turn the three stored section offsets into
 * absolute pointers (a zero offset stays null), clear readChunkSize, relocate
 * each FAT record data word the same way, clear fileOpen and store the object
 * into gNNSSndCurrentArc.  Pinned ../2.0/sp2.
 *
 * Levers: the null arms are written null-first (`if (off == 0) p = 0; else p =
 * base + off;`); the record address is derived from the counter
 * (`(u8 *)fatBlock + 0xc + i * 0x10`) so only one zero is materialised; and the
 * relocated value is bound to a local and stored once after the if.
 */
void NNS_SndArcInitOnMemory(NNSSndArc *arc, u8 *base)
{
    u32 recordNo;

    MIi_CpuCopy32(base, arc, 0x30);

    if (arc->infoOffset == 0) arc->infoBlock = 0; else arc->infoBlock = (void *)(base + arc->infoOffset);
    if (arc->fatOffset == 0) arc->fatBlock = 0; else arc->fatBlock = (NNSSndArcFatTable *)(base + arc->fatOffset);
    if (arc->symbolOffset == 0) arc->symbolBlock = 0; else arc->symbolBlock = (void *)(base + arc->symbolOffset);
    arc->readChunkSize = 0;

    for (recordNo = 0; recordNo < arc->fatBlock->count; recordNo++) {
        u8 *record = (u8 *)arc->fatBlock + 0xc + recordNo * 0x10;
        u32 fileOffset = ((NNSSndArcFatRecord *)record)->offset;
        u32 filePtr;
        if (fileOffset == 0) filePtr = 0;
        else                 filePtr = (u32)(base + fileOffset);
        ((NNSSndArcFatRecord *)record)->data = filePtr;
    }

    arc->fileOpen = 0;
    gNNSSndCurrentArc = arc;
}
