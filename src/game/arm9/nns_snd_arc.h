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
/* END mkheaders: generated region */

#endif
