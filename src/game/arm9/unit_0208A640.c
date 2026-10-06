/*
 * file:     unit_0208A640.c
 * unit:     yes
 * function: func_0208A640, func_0208A674
 * address:  0x0208A640
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
 *   DC_StoreRange     0x020862D4  arm
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
void func_0208A640(SNDWaveArc *waveArc, int index, const SNDWaveData *address);
const SNDWaveData *func_0208A674(const SNDWaveArc *waveArc, int index);


/*
 * sdk:      SND_SetWaveDataAddress (snd_bank.o)
 */
void func_0208A640(SNDWaveArc *waveArc, int index, const SNDWaveData *address)
{
    SNDi_LockMutex();
    waveArc->waveOffset[index] = (unsigned long)address;
    DC_StoreRange(&waveArc->waveOffset[index], sizeof(unsigned long));
    SNDi_UnlockMutex();
}


/*
 * sdk:      SND_GetWaveDataAddress (snd_bank.o)
 */
const SNDWaveData *func_0208A674(const SNDWaveArc *waveArc, int index)
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
