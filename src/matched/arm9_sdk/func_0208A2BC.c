/*
 * function: SND_AssignWaveArc
 * address:  0x0208A2BC
 * packet:   pkt_0208A2BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_AssignWaveArc (snd_bank.o)
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

extern void SNDi_LockMutex(void);
extern void SNDi_UnlockMutex(void);
extern void DC_StoreRange(const void *startAddr, unsigned long nBytes);

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
