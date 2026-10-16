/*
 * file:     snd_work.c
 * unit:     yes
 * function: SND_GetPlayerStatus, SND_GetChannelStatus, SND_ReadTrackInfo, SNDi_GetFinishedCommandTag, SNDi_InitSharedWork
 * address:  0x0208A054
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
 *   DC_InvalidateRange  0x020862B8  arm
 *   g_02152FA0     0x02152FA0  data
 *   DC_InvalidateRange  0x020862B8  arm
 *   SNDi_SharedWork     0x02152FA0  data
 *   DC_FlushRange  0x020862F0  arm
 */
typedef unsigned int u32;

#include "snd_shared_types.h"

typedef int BOOL;

typedef struct SNDExChannel {
    unsigned char myNo;
    unsigned char pad[0x4f];
    struct SNDExChannel *nextLink;
} SNDExChannel;

typedef struct SNDTrack {
    unsigned char flags;
    unsigned char pan_range;
    unsigned short prgNo;
    unsigned char volume;
    unsigned char volume2;
    signed char pitch_bend;
    unsigned char bend_range;
    signed char pan;
    unsigned char pad9[0x13 - 0x9];
    signed char transpose;
    unsigned char pad14[0x3c - 0x14];
    SNDExChannel *channel_list;
} SNDTrack;

typedef struct SNDPlayer {
    unsigned char pad0[8];
    unsigned char tracks[16];
    unsigned char pad18[0x24 - 0x18];
} SNDPlayer;

typedef struct SNDWork {
    SNDExChannel channel[16];
    SNDPlayer player[16];
    SNDTrack track[32];
    unsigned char pad[0x1180 - 0xf80];
} SNDWork;

typedef struct SNDDriverInfo {
    SNDWork work;
    unsigned long chCtrl[16];
    SNDWork *workAddress;
    unsigned long lockedChannels;
    unsigned long padding[6];
} SNDDriverInfo;

typedef struct SNDTrackInfo {
    unsigned short prgNo;
    unsigned char volume;
    unsigned char volume2;
    signed char pitchBend;
    unsigned char bendRange;
    unsigned char pan;
    signed char transpose;
    unsigned char pad_;
    unsigned char chCount;
    unsigned char channel[16];
} SNDTrackInfo;

extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern void DC_FlushRange(const void *startAddr, unsigned long nBytes);
u32 SND_GetPlayerStatus(void);
unsigned long SND_GetChannelStatus(void);
BOOL SND_ReadTrackInfo(SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo);
unsigned long SNDi_GetFinishedCommandTag(void);
void SNDi_InitSharedWork(SNDSharedWork *work);
extern SNDSharedWork *SNDi_SharedWork;


/* sdk:      SND_GetPlayerStatus (snd_work.o) */
u32 SND_GetPlayerStatus(void)
{
    DC_InvalidateRange(&SNDi_SharedWork->playerStatus, 4);
    return SNDi_SharedWork->playerStatus;
}


/*
 * sdk:      SND_GetChannelStatus (snd_work.o)
 */
unsigned long SND_GetChannelStatus(void)
{
    DC_InvalidateRange(&SNDi_SharedWork->channelStatus, 2);
    return SNDi_SharedWork->channelStatus;
}


static inline SNDExChannel *ConvAddr(const SNDExChannel *p, const SNDWork *base, const SNDDriverInfo *info)
{
    if (p == 0) {
        return 0;
    }
    return (SNDExChannel *)((unsigned char *)info + ((unsigned long)p - (unsigned long)base));
}


/*
 * sdk:      SND_ReadTrackInfo (snd_work.o)
 */
BOOL SND_ReadTrackInfo(SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo)
{
    SNDExChannel *chp;
    unsigned char trackID;
    SNDTrack *track;

    if (playerNo < 0 || playerNo > 15) {
        return 0;
    }
    if (trackNo < 0 || trackNo > 15) {
        return 0;
    }
    trackID = driverInfo->work.player[playerNo].tracks[trackNo];
    if (trackID == 0xff) {
        return 0;
    }
    track = &driverInfo->work.track[trackID];

    trackInfo->prgNo = track->prgNo;
    trackInfo->volume = track->volume;
    trackInfo->volume2 = track->volume2;
    trackInfo->pitchBend = track->pitch_bend;
    trackInfo->bendRange = track->bend_range;
    trackInfo->pan = (unsigned char)(track->pan + 0x40);
    trackInfo->transpose = track->transpose;
    chp = ConvAddr(track->channel_list, driverInfo->workAddress, driverInfo);
    trackInfo->chCount = 0;
    while (chp != 0) {
        trackInfo->channel[trackInfo->chCount] = chp->myNo;
        trackInfo->chCount++;
        chp = ConvAddr(chp->nextLink, driverInfo->workAddress, driverInfo);
    }
    return 1;
}


/*
 * sdk:      SNDi_GetFinishedCommandTag (snd_work.o)
 */
unsigned long SNDi_GetFinishedCommandTag(void)
{
    DC_InvalidateRange(&SNDi_SharedWork->finishedTag, 4);
    return SNDi_SharedWork->finishedTag;
}


/*
 * sdk:      SNDi_InitSharedWork (snd_work.o)
 */
void SNDi_InitSharedWork(SNDSharedWork *work)
{
    int playerNo;
    int variableNo;

    work->playerStatus = 0;
    work->channelStatus = 0;
    work->captureStatus = 0;
    work->finishedTag = 0;

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
