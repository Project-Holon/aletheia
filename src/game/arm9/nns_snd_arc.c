/*
 * file:     nns_snd_arc.c
 * unit:     yes
 * function: NNS_SndArcSetCurrent, NNS_SndArcGetCurrent, NNS_SndArcGetSeqParam, NNS_SndArcGetSeqInfo, NNS_SndArcGetSeqArcInfo, NNS_SndArcGetBankInfo, NNS_SndArcGetWaveArcInfo, NNS_SndArcGetPlayerInfo, NNS_SndArcGetGroupInfo, NNS_SndArcGetFileSize, NNS_SndArcReadFile, NNS_SndArcGetFileAddress, NNS_SndArcSetFileAddress, NNS_SndArcSetReadChunkSize, NNSi_SndArcDisposeInfo, NNSi_SndArcDisposeFat, NNSi_SndArcDisposeSymbol, NNS_SndHeapCreate, NNS_SndHeapDestroy, NNS_SndHeapClear, NNS_SndHeapAlloc, NNS_SndHeapSaveState, NNS_SndHeapLoadState, NNSi_SndHeapLevelInit, NNSi_SndHeapInit, NNSi_SndHeapAllocLevel, NNSi_SndHeapFlushCommands, NNS_SndArcLoadGroup, NNS_SndArcLoadSeq, NNS_SndArcLoadWaveArc, NNS_SndArcLoadSeqEx, NNSi_SndArcLoadGroup, NNSi_SndArcLoadSeq, NNSi_SndArcLoadSeqArc, NNSi_SndArcLoadBank, NNSi_SndArcLoadWaveArc, NNSi_SndArcLoadFile, NNSi_SndArcLoadSeqFile, NNSi_SndArcLoadSeqArcFile, NNSi_SndArcLoadBankFile, NNSi_SndArcLoadWaveArcFile, NNSi_SndArcLoadWaveArcTable, NNSi_SndArcForgetFileAddress, NNSi_SndArcDisposeSeq, NNSi_SndArcDisposeBank, NNSi_SndArcDisposeWaveArc, NNSi_SndArcDisposeWaveArcTable, NNSi_SndArcDisposeWave, NNSi_SndArcLoadWave, NNSi_SndArcLoadBankWaves, NNS_SndArcPlayerSetup
 * address:  0x020742E4
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem sound archive (SDAT) access, the sound heap and the group,
 * sequence, bank and wave archive loaders. Most functions are pinned to
 * ../2.0/sp2: the image rematerialises small constants at each use, where
 * dsi/1.1p1 keeps them in callee-saved registers.
 *
 * symbols:
 *   gNNSSndCurrentArc  0x0214EA50  data
 *   FS_SeekFile  0x02078B44  arm
 *   FS_ReadFile  0x02078B70  arm
 *   NNS_FndCreateFrmHeap  0x020610E0  arm
 *   NNS_FndDestroyFrmHeap  0x02061118  arm
 *   NNS_FndGetPrevListObject  0x0206062C  arm
 *   NNS_FndRemoveListObject  0x020605B4  arm
 *   NNS_FndFreeToFrmHeap  0x02061158  arm
 *   NNS_FndRecordStateForFrmHeap  0x02061184  arm
 *   NNS_FndFreeByStateToFrmHeap  0x020611D4  arm
 *   NNS_FndInitList  0x02060468  arm
 *   NNS_FndAllocFromFrmHeapEx  0x02061124  arm
 *   NNS_FndAppendListObject  0x020604AC  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   SND_FlushCommand  0x02089B38  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 *   SND_AssignWaveArc  0x0208A2BC  arm
 *   DC_StoreRange  0x020862D4  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   gNNSSndArcWaveArcHeader     0x0214EA54  data  a4
 *   d_0214EA54_hdr 0x0214EA54  data  a4
 *   SND_InvalidateSeqData    0x020896AC  arm
 *   SND_InvalidateBankData    0x020896CC  arm
 *   SND_DestroyBank    0x0208A38C  arm
 *   SNDi_GetBankWaveArcTable  0x0208A638  arm
 *   SND_SetWaveDataAddress  0x0208A640  arm
 *   SND_GetWaveDataAddress  0x0208A674  arm
 *   SND_GetFirstInstDataPos  0x0208A46C  arm
 *   SND_GetNextInstData  0x0208A48C  arm
 *   NNS_SndPlayerSetPlayableSeqCount  0x02072DB0  arm
 *   NNS_SndPlayerSetAllocatableChannel  0x02072DD0  arm
 *   NNS_SndPlayerCreateHeap  0x02072DE8  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SND_InvalidateWaveData  0x020896EC  arm
 *   SND_DestroyWaveArc  0x0208A424  arm
 */
#include "nns_snd_arc_types.h"

#include "fs_file.h"
#include "nns_fnd_frameheap.h"
struct DList;
#include "nns_fnd_expheap.h"
#include "snd_command.h"
#include "os_cache.h"
#include "mi_memory.h"
#include "os_system.h"
#include "snd_interface.h"
extern u32  SND_GetNextInstData(u32 bank, SNDBankWaveRecord *record, SNDInstPos *pos);
#include "nns_snd_player.h"
struct NNSSndHeap;

extern NNSSndArc *gNNSSndCurrentArc;
extern SNDWaveArc gNNSSndArcWaveArcHeader;
extern SNDWaveArc d_0214EA54_hdr;

NNSSndArc *NNS_SndArcSetCurrent(NNSSndArc *newArc);
NNSSndArc *NNS_SndArcGetCurrent(void);
u8 *NNS_SndArcGetSeqParam(int entryNo);
NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(int entryNo);
void *NNS_SndArcGetSeqArcInfo(int entryNo);
NNSSndArcBankInfo *NNS_SndArcGetBankInfo(int entryNo);
NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(int entryNo);
void *NNS_SndArcGetPlayerInfo(int entryNo);
void *NNS_SndArcGetGroupInfo(int entryNo);
u32 NNS_SndArcGetFileSize(u32 fileId);
int NNS_SndArcReadFile(u32 fileId, void *dst, int length, u32 offset);
u32 NNS_SndArcGetFileAddress(u32 fileId);
void NNS_SndArcSetFileAddress(u32 fileId, u32 address);
void NNS_SndArcSetReadChunkSize(int chunkSize);
void NNSi_SndArcDisposeInfo(void *buffer, u32 size, NNSSndArc *arc);
void NNSi_SndArcDisposeFat(void *buffer, u32 size, NNSSndArc *arc);
void NNSi_SndArcDisposeSymbol(void *buffer, u32 size, NNSSndArc *arc);
NNSSndHeap *NNS_SndHeapCreate(u32 start, u32 size);
void NNS_SndHeapDestroy(NNSSndHeap *heap);
void NNS_SndHeapClear(NNSSndHeap *heap);
void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2);
s32 NNS_SndHeapSaveState(NNSSndHeap *heap);
void NNS_SndHeapLoadState(NNSSndHeap *heap, s32 level);
void NNSi_SndHeapLevelInit(NNSiSndHeapLevel *level);
int NNSi_SndHeapInit(NNSSndHeap *heap, NNSFndHeapHandle handle);
int NNSi_SndHeapAllocLevel(NNSSndHeap *heap);
void NNSi_SndHeapFlushCommands(void);
BOOL NNS_SndArcLoadGroup(u32 groupNo, NNSSndHeap *heap);
u32 NNS_SndArcLoadSeq(u32 seqNo, NNSSndHeap *heap);
u32 NNS_SndArcLoadWaveArc(u32 waveArcNo, NNSSndHeap *heap);
u32 NNS_SndArcLoadSeqEx(u32 seqNo, u32 loadFlag, NNSSndHeap *heap);
int NNSi_SndArcLoadGroup(u32 groupNo, NNSSndHeap *heap);
u32 NNSi_SndArcLoadSeq(u32 seqNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress);
u32 NNSi_SndArcLoadSeqArc(u32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress);
u32 NNSi_SndArcLoadBank(u32 bankNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress);
u32 NNSi_SndArcLoadWaveArc(u32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress);
void *NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, u32 arc, u32 callbackFileId, NNSSndHeap *heap);
u32 NNSi_SndArcLoadSeqFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
u32 NNSi_SndArcLoadSeqArcFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
u32 NNSi_SndArcLoadBankFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
u32 NNSi_SndArcLoadWaveArcFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
u32 NNSi_SndArcLoadWaveArcTable(u32 fileId, NNSSndHeap *heap, int isSetAddress);
void NNSi_SndArcForgetFileAddress(u32 buffer, NNSSndArc *arc, u32 fileId);
void NNSi_SndArcDisposeSeq(u8 *buffer, u32 size, NNSSndArc *arc, u32 fileId);
void NNSi_SndArcDisposeBank(u8 *buffer, u32 size, NNSSndArc *arc, u32 fileId);
void NNSi_SndArcDisposeWaveArc(int buffer, int size, NNSSndArc *arc, int fileId);
void NNSi_SndArcDisposeWaveArcTable(int buffer, int size, NNSSndArc *arc, int fileId);
void NNSi_SndArcDisposeWave(u32 buffer, u32 size, SNDWaveArc *waveArc, u32 waveNo);
u32 NNSi_SndArcLoadWave(SNDWaveArc *waveArc, u32 waveNo, u32 fileId, NNSSndHeap *heap);
u32 NNSi_SndArcLoadBankWaves(SNDWaveArc *waveArc, u32 bank, u32 waveArcNo, u32 fileId, NNSSndHeap *heap);
u32 NNS_SndArcPlayerSetup(NNSSndHeap *heap);

NNSSndArc *NNS_SndArcSetCurrent(NNSSndArc *newArc)
{
    NNSSndArc *previous = gNNSSndCurrentArc;
    gNNSSndCurrentArc = newArc;
    return previous;
}

NNSSndArc *NNS_SndArcGetCurrent(void)
{
    return gNNSSndCurrentArc;
}

u8 *NNS_SndArcGetSeqParam(int entryNo)
{
    void *ptr = NNS_SndArcGetSeqInfo(entryNo);
    if (ptr == 0) {
        return 0;
    }
    return (u8 *)ptr + 4;
}

NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(int entryNo)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcInfoHeader *infoHeader = arc->infoBlock;
    NNSSndArcInfoTable *infoTable;
    u32 offset = infoHeader->seqTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (NNSSndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoBlock;
    if (offset == 0) {
        return 0;
    }
    return (NNSSndArcSeqInfo *)((char *)infoBase + offset);
}

void *NNS_SndArcGetSeqArcInfo(int entryNo)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcInfoHeader *infoHeader = arc->infoBlock;
    NNSSndArcInfoTable *infoTable;
    u32 offset = infoHeader->seqArcTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (NNSSndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoBlock;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

NNSSndArcBankInfo *NNS_SndArcGetBankInfo(int entryNo)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcInfoHeader *infoHeader = arc->infoBlock;
    NNSSndArcInfoTable *infoTable;
    u32 offset = infoHeader->bankTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (NNSSndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoBlock;
    if (offset == 0) {
        return 0;
    }
    return (NNSSndArcBankInfo *)((char *)infoBase + offset);
}

NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(int entryNo)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcInfoHeader *infoHeader = arc->infoBlock;
    NNSSndArcInfoTable *infoTable;
    u32 offset = infoHeader->waveArcTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (NNSSndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoBlock;
    if (offset == 0) {
        return 0;
    }
    return (NNSSndArcWaveArcInfo *)((char *)infoBase + offset);
}

void *NNS_SndArcGetPlayerInfo(int entryNo)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcInfoHeader *infoHeader = arc->infoBlock;
    NNSSndArcInfoTable *infoTable;
    u32 offset = infoHeader->playerTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (NNSSndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoBlock;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

void *NNS_SndArcGetGroupInfo(int entryNo)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcInfoHeader *infoHeader = arc->infoBlock;
    NNSSndArcInfoTable *infoTable;
    u32 offset = infoHeader->groupTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (NNSSndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoBlock;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

u32 NNS_SndArcGetFileSize(u32 fileId)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcFatTable *fileTable = arc->fatBlock;
    if (fileId >= fileTable->count) {
        return 0;
    }
    return fileTable->entries[fileId].size;
}

int NNS_SndArcReadFile(u32 fileId, void *dst, int length, u32 offset)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcFatTable *fileTable = arc->fatBlock;
    int bytesRead;
    int readChunkSize;
    NNSSndArcFatEntry *fileEntry;

    if (fileId >= fileTable->count) {
        return -1;
    }
    readChunkSize = arc->readChunkSize;
    fileEntry = &fileTable->entries[fileId];
    if (readChunkSize == 0) {
        readChunkSize = length;
    }
    bytesRead = 0;
    if (length > 0) {
        do {
            u32 entryRemaining;
            int chunkLen = length - bytesRead;
            int readResult;
            if (chunkLen > readChunkSize) {
                chunkLen = readChunkSize;
            }
            entryRemaining = fileEntry->size - offset;
            if (chunkLen > entryRemaining) {
                chunkLen = entryRemaining;
            }
            if (chunkLen == 0) {
                break;
            }
            if (!FS_SeekFile((struct FSFile *)&arc->file, fileEntry->offset + offset, 0)) {
                return -1;
            }
            readResult = FS_ReadFile((struct FSFile *)&arc->file, dst, chunkLen);
            if (readResult < 0) {
                return readResult;
            }
            bytesRead += readResult;
            offset += readResult;
            dst = (char *)dst + readResult;
        } while (bytesRead < length);
    }
    return bytesRead;
}

u32 NNS_SndArcGetFileAddress(u32 fileId)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcFatTable *fileTable = arc->fatBlock;
    if (fileId >= fileTable->count) {
        return 0;
    }
    return fileTable->entries[fileId].loadedData;
}

void NNS_SndArcSetFileAddress(u32 fileId, u32 address)
{
    NNSSndArc *arc = gNNSSndCurrentArc;
    NNSSndArcFatTable *fileTable = arc->fatBlock;
    fileTable->entries[fileId].loadedData = address;
}

void NNS_SndArcSetReadChunkSize(int chunkSize)
{
    gNNSSndCurrentArc->readChunkSize = chunkSize;
}

/*
 * Release callbacks of the three archive blocks: the sound heap calls
 * cb(buffer, size, arc, fileId) when it frees the block, and the callback
 * forgets the pointer the archive kept to it.
 */
void NNSi_SndArcDisposeInfo(void *buffer, u32 size, NNSSndArc *arc)
{
    arc->infoBlock = 0;
}

void NNSi_SndArcDisposeFat(void *buffer, u32 size, NNSSndArc *arc)
{
    arc->fatBlock = 0;
}

void NNSi_SndArcDisposeSymbol(void *buffer, u32 size, NNSSndArc *arc)
{
    arc->symbolBlock = 0;
}

/*
 * Creates a sound heap in the window (start, size): the start is rounded up
 * to four, the window is refused if the rounded start is past its end or if
 * fewer than 0x10 bytes remain. The frame heap is made after a 0x10-byte
 * header, which holds the NNSSndHeap. A failed init frees the frame heap
 * again and answers 0.
 *
 * Pinned ../2.0/sp2 (under dsi/1.1p1 the constant 0 would sit in a
 * callee-saved register). The window end must be computed before the rounded
 * start, as the original declared them.
 */
NNSSndHeap *NNS_SndHeapCreate(u32 start, u32 size)
{
    u32 end;
    uptr alignedStart;
    u32 rest;
    NNSFndHeapHandle handle;

    end          = start + size;
    alignedStart = (start + 3) & ~3u;

    if (alignedStart > end) return 0;
    rest = end - alignedStart;
    if (rest < 0x10) return 0;

    handle = NNS_FndCreateFrmHeap((void *)(alignedStart + 0x10), rest - 0x10, 0);
    if (handle == 0) return 0;
    if (NNSi_SndHeapInit((NNSSndHeap *)alignedStart, handle) != 0) return (NNSSndHeap *)alignedStart;

    NNS_FndDestroyFrmHeap(handle);
    return 0;
}

void NNS_SndHeapDestroy(NNSSndHeap *heap)
{
    NNS_SndHeapClear(heap);
    NNS_FndDestroyFrmHeap(heap->handle);
}

void NNS_SndHeapClear(NNSSndHeap *heap)
{
    NNSiSndHeapLevel *level;
    u32 anyCallback;
    NNSiSndHeapBlock *block;

    anyCallback = 0;
    level = NNS_FndGetPrevListObject((struct DList *)(&heap->levelList), 0);
    while (level != 0) {
        block = NNS_FndGetPrevListObject((struct DList *)(&level->blockList), 0);
        while (block != 0) {
            if (block->callback != 0) {
                block->callback((u8 *)block + 0x20, block->size, block->data1, block->data2);
                anyCallback = 1;
            }
            block = NNS_FndGetPrevListObject((struct DList *)(&level->blockList), block);
        }
        NNS_FndRemoveListObject((struct DList *)(&heap->levelList), level);
        level = NNS_FndGetPrevListObject((struct DList *)(&heap->levelList), 0);
    }

    NNS_FndFreeToFrmHeap(heap->handle, 3);
    if (anyCallback != 0) NNSi_SndHeapFlushCommands();
    NNSi_SndHeapAllocLevel(heap);
}

/*
 * Allocates one block of the current level: size rounded up to 32 bytes plus
 * the 0x20-byte block header, linked into the newest level's block list.
 * Answers the buffer behind the header, or 0.
 */
void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2)
{
    NNSiSndHeapBlock *block;
    NNSFndList *blockList;
    block = (struct NNSiSndHeapBlock *)NNS_FndAllocFromFrmHeapEx((char *)heap->handle, ((size + 0x1f) & ~0x1fu) + 0x20, 0x20);
    if (block == 0) return 0;
    blockList = NNS_FndGetPrevListObject((struct DList *)(&heap->levelList), 0);
    block->size = size;
    block->callback = callback;
    block->data1 = data1;
    block->data2 = data2;
    NNS_FndAppendListObject(blockList, block);
    return (u8 *)block + 0x20;
}

/*
 * Saves the heap state: records a frame heap state tagged with the level
 * count (0 when the tag is not live) and opens a new level. Answers the
 * saved level number, or -1.
 *
 * Pinned ../2.0/sp2: under dsi/1.1p1 the constant 0 of the free call is
 * shared with the -1 return and parked in a callee-saved register.
 */
s32 NNS_SndHeapSaveState(NNSSndHeap *heap)
{
    if (NNS_FndRecordStateForFrmHeap(heap->handle, heap->levelList.numObjects) == 0) {
        return -1;
    }
    if (NNSi_SndHeapAllocLevel(heap) != 0) {
        return heap->levelList.numObjects - 1;
    }
    NNS_FndFreeByStateToFrmHeap(heap->handle, 0);
    return -1;
}

/*
 * Restores a saved state: drains the levels newer than level, running each
 * block's dispose callback (level 0 is the same as a full clear), frees the
 * frame heap back to that state, flushes the sound command queue once if any
 * callback ran, and opens a fresh level.
 *
 * The null cursor of the second list walk of each outer iteration is the
 * block cursor itself (0 at entry and 0 whenever the inner walk ends), not a
 * literal 0. Declaration order list, anyCallback, block puts the registers
 * where the image has them.
 */
void NNS_SndHeapLoadState(NNSSndHeap *heap, s32 level)
{
    NNSiSndHeapLevel *curLevel;
    u32 anyCallback;
    NNSiSndHeapBlock *block;

    block       = 0;
    anyCallback = 0;
    if (level == 0) { NNS_SndHeapClear(heap); return; }

    while (level < heap->levelList.numObjects) {
        curLevel = NNS_FndGetPrevListObject((struct DList *)(&heap->levelList), 0);
        block = NNS_FndGetPrevListObject((struct DList *)(&curLevel->blockList), block);
        while (block != 0) {
            if (block->callback != 0) {
                block->callback((u8 *)block + 0x20, block->size, block->data1, block->data2);
                anyCallback = 1;
            }
            block = NNS_FndGetPrevListObject((struct DList *)(&curLevel->blockList), block);
        }
        NNS_FndRemoveListObject((struct DList *)(&heap->levelList), curLevel);
    }

    NNS_FndFreeByStateToFrmHeap(heap->handle, level);
    if (anyCallback != 0) NNSi_SndHeapFlushCommands();
    NNS_FndRecordStateForFrmHeap(heap->handle, heap->levelList.numObjects);
    NNSi_SndHeapAllocLevel(heap);
}

void NNSi_SndHeapLevelInit(NNSiSndHeapLevel *level)
{
    NNS_FndInitList((sptr)(&level->blockList), 0);
}

int NNSi_SndHeapInit(NNSSndHeap *heap, NNSFndHeapHandle handle)
{
    NNS_FndInitList((sptr)(&heap->levelList), 0xc);
    heap->handle = handle;
    if (NNSi_SndHeapAllocLevel(heap)) {
        return 1;
    }
    return 0;
}

int NNSi_SndHeapAllocLevel(NNSSndHeap *heap)
{
    NNSiSndHeapLevel *level = (struct NNSiSndHeapLevel *)NNS_FndAllocFromFrmHeapEx((char *)heap->handle, 0x14, 4);
    if (!level) {
        return 0;
    }
    NNSi_SndHeapLevelInit(level);
    NNS_FndAppendListObject(&heap->levelList, level);
    return 1;
}

void NNSi_SndHeapFlushCommands(void)
{
    u32 tag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(tag);
}

BOOL NNS_SndArcLoadGroup(u32 groupNo, NNSSndHeap *heap)
{
    return NNSi_SndArcLoadGroup(groupNo, heap) == 0;
}

/*
 * One-line wrapper: call the sequence loader over a 0xff load flag mask and
 * invert the result.
 *
 * Pinned ../2.0/sp2: the image materialises the fourth and fifth arguments
 * at the call and rebuilds the boolean from immediates, where dsi/1.1p1
 * keeps the two constants live in callee-saved r4/r5 across the call.
 */
u32 NNS_SndArcLoadSeq(u32 seqNo, NNSSndHeap *heap)
{
    return NNSi_SndArcLoadSeq(seqNo, 0xff, heap, 1, 0) == 0;
}

/* Same wrapper over the wave archive loader; same ../2.0/sp2 pin. */
u32 NNS_SndArcLoadWaveArc(u32 waveArcNo, NNSSndHeap *heap)
{
    return NNSi_SndArcLoadWaveArc(waveArcNo, 0xff, heap, 1, 0) == 0;
}

/* Same wrapper with the load flags passed through; same ../2.0/sp2 pin. */
u32 NNS_SndArcLoadSeqEx(u32 seqNo, u32 loadFlag, NNSSndHeap *heap)
{
    return NNSi_SndArcLoadSeq(seqNo, loadFlag, heap, 1, 0) == 0;
}

/*
 * Group loader: looks the group up by number, then runs each 8-byte item
 * through one of four loaders chosen by a dense 4-way switch, returning the
 * first non-zero loader result. A null group is 1.
 *
 *  - The arms are in the order 0, 3, 1, 2 (read off the branch table); the
 *    emitted arms run in source order.
 *  - The arms return the loader's own result (`result = f(..); if (result)
 *    return result;`), not a literal 1.
 *  - The empty-count exit shares the last epilogue, so the loop is
 *    `if (i < count) { do { .. } while (i < count); }` with `i = 0` assigned
 *    first.
 *  - Declaration order `i` before `item` puts the counter in r7 and the
 *    cursor in r8.
 *
 * Pinned ../2.0/sp2: the fifth argument is a literal 0 at all four call sites
 * and the image materialises it four separate times, one register per arm,
 * which forces the ten-register push; dsi/1.1p1 CSEs them into one.
 */
int NNSi_SndArcLoadGroup(u32 groupNo, NNSSndHeap *heap)
{
    NNSSndArcGroupInfo *group;
    u32 i;
    NNSSndArcGroupItem *item;
    u32 result;

    group = NNS_SndArcGetGroupInfo(groupNo);
    if (group == 0) {
        return 1;
    }
    i = 0;
    if (i < group->count) {
        item = group->items;
        do {
        switch (item->type) {
        case NNS_SND_ARC_GROUP_SEQ:
            result = NNSi_SndArcLoadSeq(item->itemNo, item->loadFlag, heap, 1, 0);
            if (result != 0) {
                return result;
            }
            break;
        case NNS_SND_ARC_GROUP_SEQARC:
            result = NNSi_SndArcLoadSeqArc(item->itemNo, item->loadFlag, heap, 1, 0);
            if (result != 0) {
                return result;
            }
            break;
        case NNS_SND_ARC_GROUP_BANK:
            result = NNSi_SndArcLoadBank(item->itemNo, item->loadFlag, heap, 1, 0);
            if (result != 0) {
                return result;
            }
            break;
        case NNS_SND_ARC_GROUP_WAVEARC:
            result = NNSi_SndArcLoadWaveArc(item->itemNo, item->loadFlag, heap, 1, 0);
            if (result != 0) {
                return result;
            }
            break;
        }
            i++;
            item++;
        } while (i < group->count);
    }
    return 0;
}

/*
 * Sequence loader: loads the sequence's bank (flag bits as in the group
 * loader), then the sequence file when NNS_SND_ARC_LOAD_SEQ is set, else
 * just looks its address up. Error 2: no such sequence; 6: file load failed.
 */
u32 NNSi_SndArcLoadSeq(u32 seqNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress)
{
    NNSSndArcSeqInfo *seqInfo = NNS_SndArcGetSeqInfo(seqNo);
    u32 result;

    if (seqInfo == 0) return 2;
    result = NNSi_SndArcLoadBank(seqInfo->bankNo, loadFlag, heap, isSetAddress, 0);
    if (result != 0) return result;
    if (loadFlag & NNS_SND_ARC_LOAD_SEQ) {
        result = NNSi_SndArcLoadSeqFile(seqInfo->fileId, heap, isSetAddress);
        if (result == 0) return 6;
    } else {
        result = NNS_SndArcGetFileAddress(seqInfo->fileId);
    }
    if (outAddress != 0) *outAddress = result;
    return 0;
}

/* Sequence archive loader. Error 3: no such entry; 7: file load failed. */
u32 NNSi_SndArcLoadSeqArc(u32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress) {
    NNSSndArcSeqArcInfo *seqArcInfo = NNS_SndArcGetSeqArcInfo(seqArcNo);
    u32 result;
    if (seqArcInfo == 0) return 3;
    if (loadFlag & NNS_SND_ARC_LOAD_SEQARC) {
        result = NNSi_SndArcLoadSeqArcFile(seqArcInfo->fileId, heap, isSetAddress);
        if (result == 0) return 7;
    } else {
        result = NNS_SndArcGetFileAddress(seqArcInfo->fileId);
    }
    if (outAddress != 0) *outAddress = result;
    return 0;
}

/*
 * Bank loader: looks the bank up (error 4), loads or looks up its bank file
 * (flag NNS_SND_ARC_LOAD_BANK; error 8), then for each of its four wave
 * archive slots that is not 0xffff resolves the wave archive info (error 5),
 * loads the wave archive through NNSi_SndArcLoadWaveArc (its error code is returned
 * as is), loads the bank's individual waves through NNSi_SndArcLoadBankWaves when the
 * info's individual bit and NNS_SND_ARC_LOAD_WAVE are both set (error 9), and
 * finally assigns the wave archive to the bank slot.
 *
 * SND_AssignWaveArc takes three arguments (bank, slot, waveArc); the image's
 * `ldrne r2, [sp, #4]` loads the wave archive straight into the third
 * argument register. The body is exact under dsi/1.1p1 and ../2.0/sp2.
 */
u32 NNSi_SndArcLoadBank(u32 bankNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress)
{
    NNSSndArcBankInfo *bankInfo;
    NNSSndArcWaveArcInfo *waveArcInfo;
    uptr bank;
    int i;
    u32 wantIndividual;
    uptr waveArc;
    u32 result;

    bankInfo = NNS_SndArcGetBankInfo(bankNo);
    if (bankInfo == 0) return 4;

    if (loadFlag & NNS_SND_ARC_LOAD_BANK) {
        bank = NNSi_SndArcLoadBankFile(bankInfo->fileId, heap, isSetAddress);
        if (bank == 0) return 8;
    } else {
        bank = NNS_SndArcGetFileAddress(bankInfo->fileId);
    }

    wantIndividual = loadFlag & NNS_SND_ARC_LOAD_WAVE;
    for (i = 0; i < 4; i++) {
        if (bankInfo->waveArcNo[i] != 0xffff) {
            waveArcInfo = NNS_SndArcGetWaveArcInfo(bankInfo->waveArcNo[i]);
            if (waveArcInfo == 0) return 5;
            result = NNSi_SndArcLoadWaveArc(bankInfo->waveArcNo[i], loadFlag, heap, isSetAddress, &waveArc);
            if (result != 0) return result;
            if ((waveArcInfo->word >> 24) & 1 && wantIndividual != 0) {
                if (NNSi_SndArcLoadBankWaves((SNDWaveArc *)waveArc, bank, (u32)i, waveArcInfo->bits.fileId, heap) == 0) return 9;
            }
            if (bank != 0 && waveArc != 0) {
                SND_AssignWaveArc((SNDBankData *)bank, (u32)i, (SNDWaveArc *)waveArc);
            }
        }
    }
    if (outAddress != 0) *outAddress = bank;
    return 0;
}

/*
 * Wave archive loader: resolves the info (error 5); with NNS_SND_ARC_LOAD_WAVE
 * set, the 24-bit file id goes to one of two loaders chosen by the info's
 * individual bit, and a zero result is error 9. Without the flag the file id
 * goes to the plain address lookup and no error check applies.
 *
 * The info word is read through two views, so it is a union. The file id is
 * a 24-bit bitfield (`bits.fileId`): that emits the image's lsl/lsr #8 pair
 * around the branch, where `(word << 8) >> 8` folds to a bic. The individual
 * flag is a plain word read `(word >> 24) & 1`: as a 1-bit member it would
 * give lsl #7 / lsrs #0x1f. The union lets both views share one load.
 *
 * Pinned ../2.0/sp2: the image computes the second and third call arguments
 * separately inside each arm and only hoists the first; dsi/1.1p1 hoists all
 * three and cross-jumps the arms (132 bytes against 140).
 */
u32 NNSi_SndArcLoadWaveArc(u32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress)
{
    NNSSndArcWaveArcInfo *waveArcInfo;
    u32 result;

    waveArcInfo = NNS_SndArcGetWaveArcInfo(waveArcNo);
    if (waveArcInfo == 0) return 5;
    if (loadFlag & NNS_SND_ARC_LOAD_WAVE) {
        if ((waveArcInfo->word >> 24) & 1) result = NNSi_SndArcLoadWaveArcTable(waveArcInfo->bits.fileId, heap, isSetAddress);
        else                               result = NNSi_SndArcLoadWaveArcFile(waveArcInfo->bits.fileId, heap, isSetAddress);
        if (result == 0) return 9;
    } else {
        result = NNS_SndArcGetFileAddress(waveArcInfo->bits.fileId);
    }
    if (outAddress != 0) *outAddress = result;
    return 0;
}

/*
 * Loads one archive file whole: sizes the file, refuses a null heap,
 * allocates size+0x20 on the sound heap with the callback and its two data
 * words, reads the file into it and flushes the range with DC_StoreRange.
 * Each step answers 0 on failure.
 *
 * The read's success test is `!= size` (the image compares the size against
 * the call result), so the size is a named local and the read result is not.
 *
 * Pinned ../2.0/sp2: the image materialises the zero of the four early exits
 * fresh at each, where dsi/1.1p1 CSEs them into one register.
 */
void *NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, u32 arc, u32 callbackFileId, NNSSndHeap *heap)
{
    u32 size;
    void *buffer;

    size = NNS_SndArcGetFileSize(fileId);
    if (size == 0) return 0;
    if (heap == 0) return 0;
    buffer = NNS_SndHeapAlloc(heap, size + 0x20, callback, arc, callbackFileId);
    if (buffer == 0) return 0;
    if (NNS_SndArcReadFile(fileId, buffer, size, 0) != size) return 0;
    DC_StoreRange(buffer, size);
    return buffer;
}

/*
 * The four whole-file loaders below look the file address up and, when it is
 * not loaded yet, load it with their own dispose callback; with
 * isSetAddress set the current archive is tied to the block and the address
 * is stored in the file table.
 */
u32 NNSi_SndArcLoadSeqFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress) {
    u32 arc;
    u32 address = NNS_SndArcGetFileAddress(fileId);
    if (address == 0) {
        if (isSetAddress == 0) arc = 0;
        else arc = (uptr)NNS_SndArcGetCurrent();
        address = (uptr)NNSi_SndArcLoadFile(fileId, (NNSSndHeapDisposeCallback)NNSi_SndArcDisposeSeq, arc, fileId, heap);
        if (isSetAddress != 0 && address != 0) NNS_SndArcSetFileAddress(fileId, address);
    }
    return address;
}

u32 NNSi_SndArcLoadSeqArcFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress) {
    u32 arc;
    u32 address = NNS_SndArcGetFileAddress(fileId);
    if (address == 0) {
        if (isSetAddress == 0) arc = 0;
        else arc = (uptr)NNS_SndArcGetCurrent();
        address = (uptr)NNSi_SndArcLoadFile(fileId, (NNSSndHeapDisposeCallback)NNSi_SndArcDisposeSeq, arc, fileId, heap);
        if (isSetAddress != 0 && address != 0) NNS_SndArcSetFileAddress(fileId, address);
    }
    return address;
}

u32 NNSi_SndArcLoadBankFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress) {
    u32 arc;
    u32 address = NNS_SndArcGetFileAddress(fileId);
    if (address == 0) {
        if (isSetAddress == 0) arc = 0;
        else arc = (uptr)NNS_SndArcGetCurrent();
        address = (uptr)NNSi_SndArcLoadFile(fileId, (NNSSndHeapDisposeCallback)NNSi_SndArcDisposeBank, arc, fileId, heap);
        if (isSetAddress != 0 && address != 0) NNS_SndArcSetFileAddress(fileId, address);
    }
    return address;
}

u32 NNSi_SndArcLoadWaveArcFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress) {
    u32 arc;
    u32 address = NNS_SndArcGetFileAddress(fileId);
    if (address == 0) {
        if (isSetAddress == 0) arc = 0;
        else arc = (uptr)NNS_SndArcGetCurrent();
        address = (uptr)NNSi_SndArcLoadFile(fileId, (NNSSndHeapDisposeCallback)NNSi_SndArcDisposeWaveArc, arc, fileId, heap);
        if (isSetAddress != 0 && address != 0) NNS_SndArcSetFileAddress(fileId, address);
    }
    return address;
}

/*
 * Wave archive loader for individually loaded waves: reads the 0x3c-byte
 * header into gNNSSndArcWaveArcHeader, allocates room for the header plus two tables of
 * waveCount words, reads the file, copies the offset table behind the first
 * and zeroes the first (the loaded wave addresses).
 */
u32 NNSi_SndArcLoadWaveArcTable(u32 fileId, NNSSndHeap *heap, int isSetAddress)
{
    u32 address;
    u32 bytesRead;
    u32 totalSize;
    u32 arc;
    SNDWaveArc *waveArc;
    u32 tableSize;

    address = NNS_SndArcGetFileAddress(fileId);
    if (address == 0) {
        if (NNS_SndArcReadFile(fileId, &gNNSSndArcWaveArcHeader, 0x3c, 0) != 0x3c)
            return 0;
        tableSize = d_0214EA54_hdr.waveCount * 4;
        totalSize = tableSize * 2;
        if (heap == 0)
            return 0;
        if (isSetAddress != 0)
            arc = (uptr)NNS_SndArcGetCurrent();
        else
            arc = 0;
        waveArc = NNS_SndHeapAlloc(heap, totalSize + 0x5c, (NNSSndHeapDisposeCallback)NNSi_SndArcDisposeWaveArcTable, arc, fileId);
        if (waveArc == 0)
            return 0;
        bytesRead = NNS_SndArcReadFile(fileId, waveArc, tableSize + 0x3c, 0);
        if (bytesRead != tableSize + 0x3c)
            return 0;
        MI_CpuCopy8(waveArc->waveOffset, &waveArc->waveOffset[waveArc->waveCount], tableSize);
        MI_CpuFill8(waveArc->waveOffset, 0, tableSize);
        DC_StoreRange(waveArc, totalSize + 0x3c);
        if (isSetAddress != 0)
            NNS_SndArcSetFileAddress(fileId, (uptr)waveArc);
        address = (uptr)waveArc;
    }
    return address;
}

/*
 * Clears the file table address of fileId if it still points at buffer,
 * with the archive that loaded the block made current meanwhile.
 */
void NNSi_SndArcForgetFileAddress(u32 buffer, NNSSndArc *arc, u32 fileId) {
    uptr previousArc; u32 irqState;
    if (arc == 0) return;
    irqState = OS_DisableInterrupts();
    previousArc = (uptr)NNS_SndArcSetCurrent(arc);
    if (NNS_SndArcGetFileAddress(fileId) == buffer) NNS_SndArcSetFileAddress(fileId, 0);
    NNS_SndArcSetCurrent((NNSSndArc *)previousArc);
    OS_RestoreInterrupts(irqState);
}

/* Dispose callback of a sequence file: forget the address, invalidate the range. */
void NNSi_SndArcDisposeSeq(u8 *buffer, u32 size, NNSSndArc *arc, u32 fileId)
{
    NNSi_SndArcForgetFileAddress((uptr)buffer, arc, fileId);
    SND_InvalidateSeqData(buffer, buffer + size);
}

/* Dispose callback of a bank file: the same plus the bank teardown. */
void NNSi_SndArcDisposeBank(u8 *buffer, u32 size, NNSSndArc *arc, u32 fileId)
{
    NNSi_SndArcForgetFileAddress((uptr)buffer, arc, fileId);
    SND_InvalidateBankData(buffer, buffer + size);
    SND_DestroyBank((SNDBankData *)buffer);
}

/*
 * Dispose callback of a wave archive file. It stays a separate function from
 * NNSi_SndArcDisposeWaveArcTable: they are the only callers of SND_DestroyWaveArc, so each is the
 * other's relocation witness.
 */
void NNSi_SndArcDisposeWaveArc(int buffer, int size, NNSSndArc *arc, int fileId)
{
    NNSi_SndArcForgetFileAddress(buffer, arc, fileId);
    SND_InvalidateWaveData((const void *)buffer, (const void *)(buffer + size));
    SND_DestroyWaveArc((SNDWaveArc *)buffer);
}

/* Dispose callback of an individually loaded wave archive. */
void NNSi_SndArcDisposeWaveArcTable(int buffer, int size, NNSSndArc *arc, int fileId)
{
    NNSi_SndArcForgetFileAddress(buffer, arc, fileId);
    SND_DestroyWaveArc((SNDWaveArc *)buffer);
}

/* Dispose callback of one individually loaded wave. */
void NNSi_SndArcDisposeWave(u32 buffer, u32 size, SNDWaveArc *waveArc, u32 waveNo) {
    if ((uptr)SND_GetWaveDataAddress(waveArc, waveNo) == buffer) SND_SetWaveDataAddress(waveArc, waveNo, 0);
    SND_InvalidateWaveData((const void *)buffer, (const void *)(buffer + size));
}

/*
 * Individual wave loader. Skips the work if the wave is already resident
 * (SND_GetWaveDataAddress), otherwise takes the wave's byte range from the offset
 * table and reads it in: allocates range+0x20 on the sound heap with
 * NNSi_SndArcDisposeWave as dispose callback, reads it with NNS_SndArcReadFile, flushes
 * it with DC_StoreRange and publishes it with SND_SetWaveDataAddress. Answers 1 for
 * "resident on exit" (already resident and success both), 0 for failure.
 *
 * The offset table is a u32 array at +0x3c of the wave archive, indexed by
 * the wave count at +0x38 plus the wave number (the loaded addresses occupy
 * the first waveCount slots). The wave's end is the next slot, except for the
 * last wave (`waveNo < lastWave` unsigned) where it is the file size at +0x08.
 *
 * The dead pointer `entry` is load-bearing: it is assigned the table-entry
 * address and never read; both reads are spelled as fresh
 * `(&waveArc->waveOffset[...])[0]` / `[1]` expressions. Dropping the
 * assignment, or reading through it, moves the whole frame down one
 * callee-saved register and adds an instruction. Likewise
 * `lastWave = SNDi_GetBankWaveArcTable(waveArc); lastWave = lastWave - 1;`
 * must be two statements.
 *
 * Pinned ../2.0/sp2: the image materialises the four failure exits' zero
 * fresh at each.
 */
u32 NNSi_SndArcLoadWave(SNDWaveArc *waveArc, u32 waveNo, u32 fileId, NNSSndHeap *heap)
{
  u32 lastWave;
  u32 offset;
  u32 end;
  u32 length;
  u32 *entry;
  void *buffer;
  u32 startOffset;
  if ((uptr)SND_GetWaveDataAddress(waveArc, waveNo) != 0)
    return 1;
  lastWave = (uptr)SNDi_GetBankWaveArcTable((char *)waveArc);
  lastWave = lastWave - 1;
  entry = &waveArc->waveOffset[waveArc->waveCount + waveNo];
  startOffset = (&waveArc->waveOffset[waveArc->waveCount + waveNo])[0];
  if (waveNo < lastWave)
    end = (&waveArc->waveOffset[waveArc->waveCount + waveNo])[1];
  else
    end = waveArc->fileHeader.fileSize;
  offset = startOffset;
  length = end - offset;
  if (heap == 0)
    return 0;
  buffer = NNS_SndHeapAlloc(heap, length + 0x20, (NNSSndHeapDisposeCallback)NNSi_SndArcDisposeWave, (uptr)waveArc, waveNo);
  if (buffer == 0)
    return 0;
  if (NNS_SndArcReadFile(fileId, buffer, length, offset) != length)
    return 0;
  DC_StoreRange(buffer, length);
  SND_SetWaveDataAddress(waveArc, waveNo, (const SNDWaveData *)buffer);
  return 1;
}

/*
 * Loads every wave of a bank that belongs to one wave archive slot: opens
 * an iterator over the bank (SND_GetFirstInstDataPos), copies it to a working cursor,
 * then steps it (SND_GetNextInstData) and, for every record of type 1 whose wave
 * archive number matches, loads the wave with NNSi_SndArcLoadWave. Any failed load
 * answers 0; a run to exhaustion answers 1. The null-bank guard is emitted
 * after the iterator open, which is why it shares the mid-function epilogue.
 *
 * The frame names both struct sizes. Declaration order is stack order,
 * reversed: `record; iter; firstIter;` puts the iterator at sp+0, the
 * working cursor at sp+8 and the record at sp+0x10. The record is 12 bytes:
 * only its first four bytes are read, the rest is sized by the frame.
 *
 * Pinned ../2.0/sp2.
 */
u32 NNSi_SndArcLoadBankWaves(SNDWaveArc *waveArc, u32 bank, u32 waveArcNo, u32 fileId, NNSSndHeap *heap)
{
    SNDBankWaveRecord record;
    SNDInstPos iter;
    SNDInstPos firstIter;

    firstIter = SND_GetFirstInstDataPos((const void *)bank);
    iter = firstIter;
    if (bank == 0) return 0;
    if (SND_GetNextInstData(bank, &record, &iter) != 0) {
        do {
            if (record.type == 1 && waveArcNo == record.waveArcNo) {
                if (NNSi_SndArcLoadWave(waveArc, record.waveNo, fileId, heap) == 0) return 0;
            }
        } while (SND_GetNextInstData(bank, &record, &iter) != 0);
    }
    return 1;
}

/*
 * Sets up the sound players from the current archive: for each of the 32
 * players that has an info record, applies its playable sequence count and
 * allocatable channel mask, and when its heap size and the heap are both
 * non-null, creates the player heap through NNS_SndPlayerCreateHeap once per playable
 * sequence, failing out on the first refusal.
 *
 * The player index is `int` in the loop and in the callee prototypes
 * (NNS_SndPlayerCreateHeap's first parameter above all); with u32 the implicit
 * conversion reshuffles r4-r7. Declaration order i, info, j.
 */
u32 NNS_SndArcPlayerSetup(NNSSndHeap *heap)
{
    int i;
    NNSSndArcPlayerInfo *info;
    int j;

    NNS_SndArcGetCurrent();
    for (i = 0; i < 32; i++) {
        info = NNS_SndArcGetPlayerInfo(i);
        if (info == 0)
            continue;
        NNS_SndPlayerSetPlayableSeqCount(i, info->playableSeqCount);
        NNS_SndPlayerSetAllocatableChannel(i, info->allocatableChannel);
        if (info->heapSize != 0 && heap != 0) {
            for (j = 0; j < info->playableSeqCount; j++) {
                if ((struct NNSSndHeap *)NNS_SndPlayerCreateHeap(i, (struct NNSSndHeap *)heap, (uptr)info->heapSize) == 0)
                    return 0;
            }
        }
    }
    return 1;
}
