/*
 * function: func_0208A424
 * address:  0x0208A424
 * packet:   pkt_0208A424
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_DestroyWaveArc (snd_bank.o)
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

void func_0208A424(SNDWaveArc *waveArc)
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
