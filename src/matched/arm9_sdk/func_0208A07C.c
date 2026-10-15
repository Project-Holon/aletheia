/*
 * function: SND_GetChannelStatus
 * address:  0x0208A07C
 * packet:   pkt_0208A07C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_GetChannelStatus (snd_work.o)
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

unsigned long SND_GetChannelStatus(void)
{
    DC_InvalidateRange(&SNDi_SharedWork->channelStatus, 2);
    return SNDi_SharedWork->channelStatus;
}
