#ifndef GAME_ARM9_SND_BANK_H
#define GAME_ARM9_SND_BANK_H

#include "../types.h"

/* Wave archive and the sound binary file headers. */

typedef struct SNDBinaryFileHeader {
    char signature[4];
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} SNDBinaryFileHeader;

typedef struct SNDBinaryBlockHeader {
    u32 kind;
    u32 size;
} SNDBinaryBlockHeader;

typedef struct SNDWaveArc SNDWaveArc;

typedef struct SNDWaveArcLink {
    SNDWaveArc *waveArc;
    struct SNDWaveArcLink *next;
} SNDWaveArcLink;

struct SNDWaveArc {
    SNDBinaryFileHeader fileHeader;
    SNDBinaryBlockHeader blockHeader;
    SNDWaveArcLink *topLink;
    u32 reserved[7];
    u32 waveCount;
    u32 waveOffset[];
};

typedef struct SNDBankData {
    u8 fileHeader[0x10];
    u8 blockHeader[0x8];
    SNDWaveArcLink waveArcLink[4];
    u32 instCount;
    u32 instOffset[];
} SNDBankData;

typedef struct SNDWaveData SNDWaveData;

typedef struct SNDInstPos {
    u32 prgNo;
    u32 index;
} SNDInstPos;

void SND_AssignWaveArc(SNDBankData *bank, int index, SNDWaveArc *waveArc);
void SND_DestroyBank(SNDBankData *bank);
void SND_DestroyWaveArc(SNDWaveArc *waveArc);
SNDInstPos SND_GetFirstInstDataPos(const void *bank);
void *SNDi_GetBankWaveArcTable(char *bank);
void SND_SetWaveDataAddress(SNDWaveArc *waveArc, int index, const SNDWaveData *address);
const SNDWaveData *SND_GetWaveDataAddress(const SNDWaveArc *waveArc, int index);

#endif
