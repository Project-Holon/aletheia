/*
 * file:     unit_0208A2BC.c
 * unit:     yes
 * function: func_0208A2BC, func_0208A38C, func_0208A424, func_0208A46C, func_0208A48C
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
typedef struct SNDWaveArc_0208A2BC SNDWaveArc_0208A2BC;

typedef struct SNDWaveArcLink_0208A2BC {
    SNDWaveArc_0208A2BC *waveArc;
    struct SNDWaveArcLink_0208A2BC *next;
} SNDWaveArcLink_0208A2BC;

struct SNDWaveArc_0208A2BC {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink_0208A2BC *topLink;
    unsigned long reserved[7];
    unsigned long waveCount;
    unsigned long waveOffset[];
};

typedef struct SNDBankData_0208A2BC {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink_0208A2BC waveArcLink[4];
    unsigned long instCount;
    unsigned long instOffset[];
} SNDBankData_0208A2BC;

typedef struct SNDWaveArc_0208A38C SNDWaveArc_0208A38C;

typedef struct SNDWaveArcLink_0208A38C {
    SNDWaveArc_0208A38C *waveArc;
    struct SNDWaveArcLink_0208A38C *next;
} SNDWaveArcLink_0208A38C;

struct SNDWaveArc_0208A38C {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink_0208A38C *topLink;
    unsigned long reserved[7];
    unsigned long waveCount;
    unsigned long waveOffset[];
};

typedef struct SNDBankData_0208A38C {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink_0208A38C waveArcLink[4];
    unsigned long instCount;
    unsigned long instOffset[];
} SNDBankData_0208A38C;

typedef struct SNDWaveData SNDWaveData;

typedef struct SNDWaveArcLink_0208A424 {
    void *waveArc;
    struct SNDWaveArcLink_0208A424 *next;
} SNDWaveArcLink_0208A424;

typedef struct SNDWaveArc_0208A424 {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink_0208A424 *topLink;
    unsigned long reserved[7];
    unsigned long waveCount;
    unsigned long waveOffset[];
} SNDWaveArc_0208A424;

typedef struct {
    unsigned int prgNo;
    unsigned int index;
} SNDInstPos_0208A46C;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef int BOOL;

typedef struct {
    u16 wave[2];
    u8 original_key;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 pan;
} SNDInstParam;

typedef struct {
    u8 type;
    u8 padding_;
    SNDInstParam param;
} SNDInstData;

typedef struct {
    u32 prgNo;
    u32 index;
} SNDInstPos_4;

typedef struct {
    u8 fileHeader[0x10];
    u8 blockHeader[0x8];
    u8 waveArcLink[0x20];
    u32 instCount;
    u32 instOffset[1];
} SNDBankData_4;

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
void func_0208A2BC(SNDBankData_0208A2BC *bank, int index, SNDWaveArc_0208A2BC *waveArc);
void func_0208A38C(SNDBankData_0208A38C *bank);
void func_0208A424(SNDWaveArc_0208A424 *waveArc);
SNDInstPos_0208A46C func_0208A46C(const void *bank);
BOOL SND_GetNextInstData(const SNDBankData_4 *bank, SNDInstData *inst, SNDInstPos_4 *pos);


/*
 * sdk:      SND_AssignWaveArc (snd_bank.o)
 */
void func_0208A2BC(SNDBankData_0208A2BC *bank, int index, SNDWaveArc_0208A2BC *waveArc)
{
    SNDWaveArcLink_0208A2BC *prev;
    SNDWaveArcLink_0208A2BC *next;

    SNDi_LockMutex();

    if (bank->waveArcLink[index].waveArc != 0) {
        if (waveArc == bank->waveArcLink[index].waveArc) {
            SNDi_UnlockMutex();
            return;
        }
        if (&bank->waveArcLink[index] == bank->waveArcLink[index].waveArc->topLink) {
            bank->waveArcLink[index].waveArc->topLink = bank->waveArcLink[index].next;
            DC_StoreRange(bank->waveArcLink[index].waveArc, sizeof(SNDWaveArc_0208A2BC));
        } else {
            for (prev = bank->waveArcLink[index].waveArc->topLink; prev != 0; prev = prev->next) {
                if (&bank->waveArcLink[index] == prev->next) {
                    break;
                }
            }
            prev->next = bank->waveArcLink[index].next;
            DC_StoreRange(prev, sizeof(SNDWaveArcLink_0208A2BC));
        }
    }

    next = waveArc->topLink;
    waveArc->topLink = &bank->waveArcLink[index];
    bank->waveArcLink[index].next = next;
    bank->waveArcLink[index].waveArc = waveArc;

    SNDi_UnlockMutex();

    DC_StoreRange(bank, sizeof(SNDBankData_0208A2BC));
    DC_StoreRange(waveArc, sizeof(SNDWaveArc_0208A2BC));
}


/*
 * sdk:      SND_DestroyBank (snd_bank.o)
 */
void func_0208A38C(SNDBankData_0208A38C *bank)
{
    SNDWaveArc_0208A38C *waveArc;
    SNDWaveArcLink_0208A38C *prev;
    int i;

    SNDi_LockMutex();

    for (i = 0; i < 4; i++) {
        waveArc = bank->waveArcLink[i].waveArc;
        if (waveArc == 0) {
            continue;
        }
        if (&bank->waveArcLink[i] == waveArc->topLink) {
            waveArc->topLink = bank->waveArcLink[i].next;
            DC_StoreRange(waveArc, sizeof(SNDWaveArc_0208A38C));
        } else {
            for (prev = waveArc->topLink; prev != 0; prev = prev->next) {
                if (&bank->waveArcLink[i] == prev->next) {
                    break;
                }
            }
            prev->next = bank->waveArcLink[i].next;
            DC_StoreRange(prev, sizeof(SNDWaveArcLink_0208A38C));
        }
    }

    SNDi_UnlockMutex();
}


/*
 * sdk:      SND_DestroyWaveArc (snd_bank.o)
 */
void func_0208A424(SNDWaveArc_0208A424 *waveArc)
{
    SNDWaveArcLink_0208A424 *link;
    SNDWaveArcLink_0208A424 *next;

    SNDi_LockMutex();
    link = waveArc->topLink;
    while (link != 0) {
        next = link->next;
        link->waveArc = 0;
        link->next = 0;
        DC_StoreRange(link, sizeof(SNDWaveArcLink_0208A424));
        link = next;
    }
    SNDi_UnlockMutex();
}


/*
 * note:     snd_bank.o SND_GetFirstInstDataPos.
 */
SNDInstPos_0208A46C func_0208A46C(const void *bank)
{
    SNDInstPos_0208A46C pos;

    pos.prgNo = 0;
    pos.index = 0;

    return pos;
}


BOOL SND_GetNextInstData(const SNDBankData_4 *bank, SNDInstData *inst, SNDInstPos_4 *pos)
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
