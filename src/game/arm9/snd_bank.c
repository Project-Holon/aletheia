/*
 * file:     snd_bank.c
 * unit:     yes
 * function: SND_AssignWaveArc, SND_DestroyBank, SND_DestroyWaveArc, SND_GetFirstInstDataPos, SND_GetNextInstData, SNDi_GetBankWaveArcTable, SND_SetWaveDataAddress, SND_GetWaveDataAddress
 * address:  0x0208A2BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SNDi_LockMutex    0x02089880  arm
 *   SNDi_UnlockMutex  0x02089894  arm
 *   DC_StoreRange     0x020862D4  arm
 */

typedef struct SNDWaveArc SNDWaveArc;

typedef struct SNDWaveArcLink {
    SNDWaveArc *waveArc;
    struct SNDWaveArcLink *next;
} SNDWaveArcLink;

struct SNDWaveArc {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink *topLink;
    unsigned long reserved[7];
    unsigned long waveCount;
    unsigned long waveOffset[];
};

typedef struct SNDBankData {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink waveArcLink[4];
    unsigned long instCount;
    unsigned long instOffset[];
} SNDBankData;

typedef struct SNDWaveData SNDWaveData;

typedef struct SNDInstPos {
    unsigned int prgNo;
    unsigned int index;
} SNDInstPos;

#include "../types.h"

typedef struct {
    u16 wave[2];
    u8 originalKey;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 pan;
} SNDInstParam;

typedef struct {
    u8 type;
    SNDInstParam param;
} SNDInstData;

typedef struct {
    u8 key[8];
    SNDInstData instOffset[1];
} SNDKeySplit;

typedef struct {
    u8 min;
    u8 max;
    SNDInstData instOffset[1];
} SNDDrumSet;

extern void SNDi_LockMutex(void);
extern void SNDi_UnlockMutex(void);
extern void DC_StoreRange(const void *startAddr, unsigned long nBytes);
void SND_AssignWaveArc(SNDBankData *bank, int index, SNDWaveArc *waveArc);
void SND_DestroyBank(SNDBankData *bank);
void SND_DestroyWaveArc(SNDWaveArc *waveArc);
SNDInstPos SND_GetFirstInstDataPos(const void *bank);
BOOL SND_GetNextInstData(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos);
void *SNDi_GetBankWaveArcTable(char *bank);
void SND_SetWaveDataAddress(SNDWaveArc *waveArc, int index, const SNDWaveData *address);
const SNDWaveData *SND_GetWaveDataAddress(const SNDWaveArc *waveArc, int index);

/*
 * sdk:      SND_AssignWaveArc (snd_bank.o)
 */
void SND_AssignWaveArc(SNDBankData *bank, int index, SNDWaveArc *waveArc)
{
    SNDWaveArcLink *prev;
    SNDWaveArcLink *next;

    SNDi_LockMutex();

    if (bank->waveArcLink[index].waveArc != 0) {
        if (waveArc == bank->waveArcLink[index].waveArc) {
            SNDi_UnlockMutex();
            return;
        }
        if (&bank->waveArcLink[index] == bank->waveArcLink[index].waveArc->topLink) {
            bank->waveArcLink[index].waveArc->topLink = bank->waveArcLink[index].next;
            DC_StoreRange(bank->waveArcLink[index].waveArc, sizeof(SNDWaveArc));
        } else {
            for (prev = bank->waveArcLink[index].waveArc->topLink; prev != 0; prev = prev->next) {
                if (&bank->waveArcLink[index] == prev->next) {
                    break;
                }
            }
            prev->next = bank->waveArcLink[index].next;
            DC_StoreRange(prev, sizeof(SNDWaveArcLink));
        }
    }

    next = waveArc->topLink;
    waveArc->topLink = &bank->waveArcLink[index];
    bank->waveArcLink[index].next = next;
    bank->waveArcLink[index].waveArc = waveArc;

    SNDi_UnlockMutex();

    DC_StoreRange(bank, sizeof(SNDBankData));
    DC_StoreRange(waveArc, sizeof(SNDWaveArc));
}

/*
 * sdk:      SND_DestroyBank (snd_bank.o)
 */
void SND_DestroyBank(SNDBankData *bank)
{
    SNDWaveArc *waveArc;
    SNDWaveArcLink *prev;
    int i;

    SNDi_LockMutex();

    for (i = 0; i < 4; i++) {
        waveArc = bank->waveArcLink[i].waveArc;
        if (waveArc == 0) {
            continue;
        }
        if (&bank->waveArcLink[i] == waveArc->topLink) {
            waveArc->topLink = bank->waveArcLink[i].next;
            DC_StoreRange(waveArc, sizeof(SNDWaveArc));
        } else {
            for (prev = waveArc->topLink; prev != 0; prev = prev->next) {
                if (&bank->waveArcLink[i] == prev->next) {
                    break;
                }
            }
            prev->next = bank->waveArcLink[i].next;
            DC_StoreRange(prev, sizeof(SNDWaveArcLink));
        }
    }

    SNDi_UnlockMutex();
}

/*
 * sdk:      SND_DestroyWaveArc (snd_bank.o)
 */
void SND_DestroyWaveArc(SNDWaveArc *waveArc)
{
    SNDWaveArcLink *link;
    SNDWaveArcLink *next;

    SNDi_LockMutex();
    link = waveArc->topLink;
    while (link != 0) {
        next = link->next;
        link->waveArc = 0;
        link->next = 0;
        DC_StoreRange(link, sizeof(SNDWaveArcLink));
        link = next;
    }
    SNDi_UnlockMutex();
}

/*
 * note:     snd_bank.o SND_GetFirstInstDataPos.
 */
SNDInstPos SND_GetFirstInstDataPos(const void *bank)
{
    SNDInstPos pos;

    pos.prgNo = 0;
    pos.index = 0;

    return pos;
}

BOOL SND_GetNextInstData(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos)
{
    u32 instOffset;
    const SNDDrumSet *drumSet;
    const SNDKeySplit *keySplit;

    for (; pos->prgNo < bank->instCount; pos->prgNo++, pos->index = 0) {
        instOffset = bank->instOffset[pos->prgNo];
        inst->type = (u8)(instOffset & 0xff);
        instOffset >>= 8;

        switch (inst->type) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            inst->param = *(const SNDInstParam *)((const u8 *)bank + instOffset);
            pos->prgNo++;
            return 1;
        case 0x10:
            drumSet = (const SNDDrumSet *)((const u8 *)bank + instOffset);
            for (; pos->index < drumSet->max - drumSet->min + 1; pos->index++) {
                *inst = drumSet->instOffset[pos->index];
                pos->index++;
                return 1;
            }
            break;
        case 0x11:
            keySplit = (const SNDKeySplit *)((const u8 *)bank + instOffset);
            for (; pos->index < 8; pos->index++) {
                if (keySplit->key[pos->index] == 0) {
                    break;
                }
                *inst = keySplit->instOffset[pos->index];
                pos->index++;
                return 1;
            }
            break;
        }
    }
    return 0;
}

void *SNDi_GetBankWaveArcTable(char *bank)
{
    return (void *)((SNDWaveArc *)bank)->waveCount;
}

/*
 * sdk:      SND_SetWaveDataAddress (snd_bank.o)
 */
void SND_SetWaveDataAddress(SNDWaveArc *waveArc, int index, const SNDWaveData *address)
{
    SNDi_LockMutex();
    waveArc->waveOffset[index] = (unsigned long)address;
    DC_StoreRange(&waveArc->waveOffset[index], sizeof(unsigned long));
    SNDi_UnlockMutex();
}

/*
 * sdk:      SND_GetWaveDataAddress (snd_bank.o)
 */
const SNDWaveData *SND_GetWaveDataAddress(const SNDWaveArc *waveArc, int index)
{
    unsigned long offset;
    const SNDWaveData *wave;

    SNDi_LockMutex();
    offset = waveArc->waveOffset[index];
    if (offset != 0) {
        if (offset < 0x2000000) {
            wave = (const SNDWaveData *)((unsigned long)waveArc + offset);
        } else {
            wave = (const SNDWaveData *)offset;
        }
    } else {
        wave = 0;
    }
    SNDi_UnlockMutex();
    return wave;
}
