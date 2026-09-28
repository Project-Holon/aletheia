/*
 * function: func_0208A0A4
 * address:  0x0208A0A4
 * packet:   pkt_0208A0A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_ReadTrackInfo (snd_work.o)
 */

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

static inline SNDExChannel *ConvAddr(const SNDExChannel *p, const SNDWork *base, const SNDDriverInfo *info)
{
    if (p == 0) {
        return 0;
    }
    return (SNDExChannel *)((unsigned char *)info + ((unsigned long)p - (unsigned long)base));
}

BOOL func_0208A0A4(SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo)
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
