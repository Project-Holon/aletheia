/*
 * function: SNDi_GetFinishedCommandTag
 * address:  0x0208A1AC
 * packet:   pkt_0208A1AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SNDi_GetFinishedCommandTag (snd_work.o)
 *
 * symbols:
 *   DC_InvalidateRange  0x020862B8  arm
 *   SNDi_SharedWork     0x02152FA0  data
 */

typedef struct SNDSharedWork {
    unsigned long finishCommandTag;
    unsigned long playerStatus;
    unsigned short channelStatus;
} SNDSharedWork;

extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern SNDSharedWork *SNDi_SharedWork;

unsigned long SNDi_GetFinishedCommandTag(void)
{
    DC_InvalidateRange(&SNDi_SharedWork->finishCommandTag, 4);
    return SNDi_SharedWork->finishCommandTag;
}
