/*
 * function: SND_DestroyBank
 * address:  0x0208A38C
 * packet:   pkt_0208A38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_DestroyBank (snd_bank.o)
 *
 * symbols:
 *   SNDi_LockMutex    0x02089880  arm
 *   DC_StoreRange     0x020862D4  arm
 *   SNDi_UnlockMutex  0x02089894  arm
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
