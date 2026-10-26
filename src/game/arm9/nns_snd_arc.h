#ifndef GAME_ARM9_NNS_SND_ARC_H
#define GAME_ARM9_NNS_SND_ARC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_arc.c, prototypes copied from their definitions. */

#include "../arm9/nns_snd_arc_types.h"
#include "../arm9/nns_snd_arc_types.h"
#include "../types.h"
#include "../arm9/nns_fnd_types.h"
#include "../arm9/snd_bank.h"

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
void *NNS_SndArcGetFileAddress(u32 fileId);
void NNS_SndArcSetFileAddress(u32 fileId, void *address);
void NNS_SndArcSetReadChunkSize(int chunkSize);
void NNSi_SndArcDisposeInfo(void *buffer, u32 size, uptr arcAddr, u32 fileId);
void NNSi_SndArcDisposeFat(void *buffer, u32 size, uptr arcAddr, u32 fileId);
void NNSi_SndArcDisposeSymbol(void *buffer, u32 size, uptr arcAddr, u32 fileId);
NNSSndHeap *NNS_SndHeapCreate(void *start, u32 size);
void NNS_SndHeapDestroy(NNSSndHeap *heap);
void NNS_SndHeapClear(NNSSndHeap *heap);
void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, uptr data1, u32 data2);
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
u32 NNSi_SndArcLoadSeq(u32 seqNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, void **outAddress);
u32 NNSi_SndArcLoadSeqArc(u32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, void **outAddress);
u32 NNSi_SndArcLoadBank(u32 bankNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, void **outAddress);
u32 NNSi_SndArcLoadWaveArc(u32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, u32 isSetAddress, void **outAddress);
void *NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, uptr arc, u32 callbackFileId, NNSSndHeap *heap);
void *NNSi_SndArcLoadSeqFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
void *NNSi_SndArcLoadSeqArcFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
void *NNSi_SndArcLoadBankFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
void *NNSi_SndArcLoadWaveArcFile(u32 fileId, NNSSndHeap *heap, u32 isSetAddress);
void *NNSi_SndArcLoadWaveArcTable(u32 fileId, NNSSndHeap *heap, int isSetAddress);
void NNSi_SndArcForgetFileAddress(void *buffer, NNSSndArc *arc, u32 fileId);
void NNSi_SndArcDisposeSeq(void *bufferPtr, u32 size, uptr arcAddr, u32 fileId);
void NNSi_SndArcDisposeBank(void *bufferPtr, u32 size, uptr arcAddr, u32 fileId);
void NNSi_SndArcDisposeWaveArc(void *bufferPtr, u32 sizeArg, uptr arcAddr, u32 fileIdArg);
void NNSi_SndArcDisposeWaveArcTable(void *bufferPtr, u32 sizeArg, uptr arcAddr, u32 fileIdArg);
void NNSi_SndArcDisposeWave(void *bufferPtr, u32 size, uptr waveArcAddr, u32 waveNo);
u32 NNSi_SndArcLoadWave(SNDWaveArc *waveArc, u32 waveNo, u32 fileId, NNSSndHeap *heap);
u32 NNSi_SndArcLoadBankWaves(SNDWaveArc *waveArc, void *bank, u32 waveArcNo, u32 fileId, NNSSndHeap *heap);
u32 NNS_SndArcPlayerSetup(NNSSndHeap *heap);
/* END mkheaders: generated region */

#endif
