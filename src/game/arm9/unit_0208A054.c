/*
 * file:     unit_0208A054.c
 * unit:     yes
 * function: func_0208A054, func_0208A07C, func_0208A0A4, func_0208A1AC, func_0208A1D0
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
 *   func_020862B8  0x020862B8  arm
 *   g_02152FA0     0x02152FA0  data
 *   DC_InvalidateRange  0x020862B8  arm
 *   SNDi_SharedWork     0x02152FA0  data
 *   DC_FlushRange  0x020862F0  arm
 */
typedef unsigned int u32;

struct Obj {
    u32 f00;
    u32 f04;
};

typedef struct SNDSharedWork_0208A07C {
    unsigned long finishCommandTag;
    unsigned long playerStatus;
    unsigned short channelStatus;
} SNDSharedWork_0208A07C;

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

typedef struct SNDSharedWork_0208A1AC {
    unsigned long finishCommandTag;
    unsigned long playerStatus;
    unsigned short channelStatus;
} SNDSharedWork_0208A1AC;

typedef struct SNDSharedWork_0208A1D0 {
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
} SNDSharedWork_0208A1D0;

extern void func_020862B8(void *p, u32 n);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern void DC_FlushRange(const void *startAddr, unsigned long nBytes);
u32 func_0208A054(void);
unsigned long func_0208A07C(void);
BOOL func_0208A0A4(SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo);
unsigned long func_0208A1AC(void);
void func_0208A1D0(SNDSharedWork_0208A1D0 *work);
extern struct Obj *g_02152FA0;
extern SNDSharedWork_0208A07C *SNDi_SharedWork;


u32 func_0208A054(void)
{
    func_020862B8(&g_02152FA0->f04, 4);
    return g_02152FA0->f04;
}


/*
 * sdk:      SND_GetChannelStatus (snd_work.o)
 */
unsigned long func_0208A07C(void)
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


/*
 * sdk:      SNDi_GetFinishedCommandTag (snd_work.o)
 */
unsigned long func_0208A1AC(void)
{
    DC_InvalidateRange(&SNDi_SharedWork->finishCommandTag, 4);
    return SNDi_SharedWork->finishCommandTag;
}


/*
 * sdk:      SNDi_InitSharedWork (snd_work.o)
 */
void func_0208A1D0(SNDSharedWork_0208A1D0 *work)
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
    DC_FlushRange(work, sizeof(SNDSharedWork_0208A1D0));
}
