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

/* Parameters of one bank instrument (wave number and wave archive number in wave[]). */
typedef struct SNDInstParam {
    u16 wave[2];
    u8 originalKey;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 pan;
} SNDInstParam;

/* One instrument record of a bank (12 bytes). */
typedef struct SNDInstData {
    u8 type;
    SNDInstParam param;
} SNDInstData;

typedef struct SNDInstPos {
    u32 prgNo;
    u32 index;
} SNDInstPos;

void SND_AssignWaveArc(SNDBankData *bank, int index, SNDWaveArc *waveArc);
void SND_DestroyBank(SNDBankData *bank);
void SND_DestroyWaveArc(SNDWaveArc *waveArc);
SNDInstPos SND_GetFirstInstDataPos(const void *bank);
u32 SNDi_GetBankWaveArcTable(char *bank);
void SND_SetWaveDataAddress(SNDWaveArc *waveArc, int index, const SNDWaveData *address);
const SNDWaveData *SND_GetWaveDataAddress(const SNDWaveArc *waveArc, int index);

struct SNDWaveData;
BOOL SND_GetNextInstData(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos);

#endif
