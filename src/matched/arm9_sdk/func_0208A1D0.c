/*
 * function: SNDi_InitSharedWork
 * address:  0x0208A1D0
 * packet:   pkt_0208A1D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SNDi_InitSharedWork (snd_work.o)
 *
 * symbols:
 *   DC_FlushRange  0x020862F0  arm
 */

typedef struct SNDSharedWork {
    unsigned long finishCommandTag;
    unsigned long playerStatus;
    unsigned short channelStatus;
    unsigned short captureStatus;
    unsigned long padding[5];
    struct {
        short variable[16];
        unsigned long tickCounter;
    } player[16];
    short globalVariable[16];
} SNDSharedWork;

extern void DC_FlushRange(const void *startAddr, unsigned long nBytes);

void SNDi_InitSharedWork(SNDSharedWork *work)
{
    int playerNo;
    int variableNo;

    work->playerStatus = 0;
    work->channelStatus = 0;
    work->captureStatus = 0;
    work->finishCommandTag = 0;

    for (playerNo = 0; playerNo < 16; playerNo++) {
        work->player[playerNo].tickCounter = 0;
        for (variableNo = 0; variableNo < 16; variableNo++) {
            work->player[playerNo].variable[variableNo] = -1;
        }
    }
    for (variableNo = 0; variableNo < 16; variableNo++) {
        work->globalVariable[variableNo] = -1;
    }
    DC_FlushRange(work, sizeof(SNDSharedWork));
}
