/*
 * function: SND_GetWaveDataAddress
 * address:  0x0208A674
 * packet:   pkt_0208A674
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_GetWaveDataAddress (snd_bank.o)
 *
 * symbols:
 *   SNDi_LockMutex    0x02089880  arm
 *   SNDi_UnlockMutex  0x02089894  arm
 */

typedef struct SNDWaveData SNDWaveData;

typedef struct SNDWaveArcLink {
    void *waveArc;
    struct SNDWaveArcLink *next;
} SNDWaveArcLink;

typedef struct SNDWaveArc {
    unsigned char fileHeader[0x10];
    unsigned char blockHeader[0x8];
    SNDWaveArcLink *topLink;
    unsigned long reserved[7];
    unsigned long waveCount;
    unsigned long waveOffset[];
} SNDWaveArc;

extern void SNDi_LockMutex(void);
extern void SNDi_UnlockMutex(void);
extern void DC_StoreRange(const void *startAddr, unsigned long nBytes);

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
