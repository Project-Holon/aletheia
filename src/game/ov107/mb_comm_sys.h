#ifndef OV107_MB_COMM_SYS_H
#define OV107_MB_COMM_SYS_H

/* Message/menu work block defined in mb_util_msg.c (see MbMsgWork there). */
struct MbMsgWork;
/*
 * Download Play parent system (ov107, mb_comm_sys): the screen flow that
 * recruits children over wireless, offers the file, and receives their data.
 * gMbParentSys (gMbParentSys) is the record the MB parent callbacks keep up to
 * date; the other types are the work blocks of the screen flow.
 * Plain C types only, so the header can be included before or after the
 * typedefs of the including file.
 */

/* Per-child state masks, one bit per AID (bit 1 to 15); bit 0 is the parent. */
typedef struct MbParentSys {
    void *fileBuffer;                   /* 0x00: 64 KiB image buffer, freed on end */
    void *mbWork;                       /* 0x04: aligned MB library work, 45312 bytes */
    unsigned short state;               /* 0x08: MB_PARENT_STATE_* value */
    unsigned short connectedMask;       /* 0x0A: children connected */
    unsigned short requestedMask;       /* 0x0C: children that asked to download */
    unsigned short waitToSendMask;      /* 0x0E: requests accepted, waiting to send */
    unsigned short sendingMask;         /* 0x10: children receiving the file */
    unsigned short sendCompleteMask;    /* 0x12: children whose transfer finished */
    unsigned short bootStartableMask;   /* 0x14: children that can boot the file */
    /* 2 bytes of alignment padding at 0x16 */
    int registered;                     /* 0x18: file registered with the MB library */
} MbParentSys;

/* Parent progress values kept in MbParentSys.state. */
enum {
    MB_PARENT_STATE_IDLE = 0,
    MB_PARENT_STATE_INIT = 1,
    MB_PARENT_STATE_RECRUITING = 2,
    MB_PARENT_STATE_STARTING = 4,
    MB_PARENT_STATE_ENDED_STARTED = 5,
    MB_PARENT_STATE_CANCELING = 6,
    MB_PARENT_STATE_FAILED = 7
};

/* Screen state shared by the VBlank hooks and the main loop (gMbParentUi). */
typedef struct MbParentUi {
    unsigned char vblankDivider;        /* 0x00: counts frames, wraps after 3 */
    unsigned char unused01;             /* 0x01: never read or written */
    unsigned short vblankCounter;       /* 0x02: counts frames in standalone mode */
    unsigned int textOnSubScreen;       /* 0x04: 1 when the text plane is on the sub screen */
    int wmEndDone;                      /* 0x08: set by the WM end callback */
} MbParentUi;

/* Which children are in which stage; one mask per stage 2 to 6 (see MB_COMM_SYS_GetChildStage). */
typedef union MbChildStageMasks {
    unsigned int words[5];              /* cleared as words */
    unsigned short stageMask[10];       /* only [2] to [6] are read */
} MbChildStageMasks;

/* One connected child, 30 bytes, indexed by AID - 1. */
typedef struct MbChildEntry {
    unsigned char user[22];             /* 0x00: MBUserInfo copy */
    unsigned char mac[6];               /* 0x16: bytes 10 to 15 of the connect event */
    unsigned short aid;                 /* 0x1C */
} MbChildEntry;

/* Argument of the proc. */
typedef struct MbParentArg {
    unsigned char standalone;           /* 0 when started from the game, 1 when booted alone */
    unsigned char pad01[3];             /* alignment before the pointer */
    void *gameData;                     /* 0x04 */
} MbParentArg;

/* Message flags of MbNetState (halfwords at 0x18 and 0x1A): one bit per message kind seen. */
typedef union MbNetFlagsA {
    unsigned short raw;
    struct {
        unsigned short headerReceived : 1;  /* callback 021F13AC */
        unsigned short monsReceived : 1;    /* callback 021F13E8 */
        unsigned short rxKind0 : 1;
        unsigned short rxKind11 : 1;
        unsigned short rxKind12 : 1;
        unsigned short rxKind13 : 1;
        unsigned short rxKind14 : 1;
        unsigned short rxKind1 : 1;
        unsigned short rxKind2 : 1;
        unsigned short rxKind3 : 1;
        unsigned short rxKind4 : 1;
        unsigned short lowerDataActive : 1; /* lower data layer initialized */
        unsigned short rxKind5 : 1;
        unsigned short rxKind15 : 1;
        unsigned short rxKind19 : 1;
        unsigned short rxKind20 : 1;
    } bits;
} MbNetFlagsA;

typedef union MbNetFlagsB {
    unsigned short raw;
    struct {
        unsigned short rxKind21 : 1;
        unsigned short kind21Value : 1;
        unsigned short rxKind16 : 1;
        unsigned short kind16Value : 1;
        unsigned short rxKind17 : 1;
        unsigned short rxKind18 : 1;
        unsigned short unusedBits : 10;     /* never touched */
    } bits;
} MbNetFlagsB;

/* Masks of MbNetFlagsA.raw and MbNetFlagsB.raw. */
enum {
    MB_FLAGA_MONS_RECEIVED = 0x2,
    MB_FLAGA_KIND0 = 0x4,
    MB_FLAGA_KIND11 = 0x8,
    MB_FLAGA_KIND12 = 0x10,
    MB_FLAGA_KIND13 = 0x20,
    MB_FLAGA_KIND14 = 0x40,
    MB_FLAGA_KIND1 = 0x80,
    MB_FLAGA_KIND2 = 0x100,
    MB_FLAGA_KIND3 = 0x200,
    MB_FLAGA_KIND4 = 0x400,
    MB_FLAGA_KIND5 = 0x1000,
    MB_FLAGA_KIND15 = 0x2000,
    MB_FLAGA_KIND19 = 0x4000,
    MB_FLAGA_KIND20 = 0x8000,
    MB_FLAGB_KIND21 = 0x1,
    MB_FLAGB_KIND21_VALUE = 0x2,
    MB_FLAGB_KIND16 = 0x4,
    MB_FLAGB_KIND16_VALUE = 0x8,
    MB_FLAGB_KIND17 = 0x10,
    MB_FLAGB_KIND18 = 0x20
};

/* Parent-to-child link state, 40 bytes. Allocated by MB_COMM_SYS_CreateNetState. */
typedef struct MbNetState {
    unsigned short heapId;              /* 0x00 */
    /* 2 bytes of alignment padding at 0x02 */
    int netStage;                       /* 0x04: bring-up stage 0 to 6 */
    unsigned int nextCommStage;         /* 0x08: stage to announce to the peer */
    unsigned int commStage;             /* 0x0C: last announced or received stage */
    unsigned char *monBuffer;           /* 0x10: count byte, u16 at +2, then 6 box params from +4 */
    void *headerBuffer;                 /* 0x14: 8 byte message buffer, allocated on first use */
    MbNetFlagsA flagsA;                 /* 0x18 */
    MbNetFlagsB flagsB;                 /* 0x1A */
    unsigned char count;                /* 0x1C: value of message kinds 2 and 3 */
    /* 1 byte of alignment padding at 0x1D */
    unsigned short childSaveCount;      /* 0x1E: value of message kind 5 */
    unsigned char result;               /* 0x20: value of message kind 15 */
    /* 3 bytes of alignment padding at 0x21 */
    unsigned int offer;                 /* 0x24: value of message kind 19, see MB_OFFER_* */
} MbNetState;

/* Bit fields of MbNetState.offer. */
#define MB_OFFER_COUNT_MASK 0xFFFF
#define MB_OFFER_EXTRA_MASK 0x3FFF0000
#define MB_OFFER_EXTRA_SHIFT 16
#define MB_OFFER_FLAG_A 0x40000000
#define MB_OFFER_FLAG_B 0x80000000

/* Message sent to the child as kind 1 on channel 0x401 (8 bytes). */
typedef struct MbPayloadHeader {
    unsigned int msgSpeed;              /* 0x00 */
    unsigned short savedCount;          /* 0x04 */
    unsigned char configCode;           /* 0x06 */
    /* 1 byte of alignment padding at 0x07 */
} MbPayloadHeader;

/* Game registry block handed to the MB library (60 bytes copied from ROM data). */
typedef struct MbRegistryBlock {
    const char *romPath;                /* 0x00 */
    unsigned short *gameName;           /* 0x04 */
    unsigned short *gameIntro;          /* 0x08 */
    const char *iconCharPath;           /* 0x0C */
    const char *iconPalettePath;        /* 0x10 */
    unsigned int rest[10];              /* 0x14: ggid, player count and the other registry words */
} MbRegistryBlock;

/* Work area of the proc, 188 bytes. */
typedef struct MbCommSysWork {
    unsigned short heapId;              /* 0x00 */
    /* 2 bytes of alignment padding at 0x02 */
    void *vblankTask;                   /* 0x04 */
    MbParentArg *arg;                   /* 0x08 */
    MbNetState *net;                    /* 0x0C */
    unsigned int errorScreenRequested;  /* 0x10 */
    unsigned int wirelessFailed;        /* 0x14 */
    unsigned int wasSaving;             /* 0x18 */
    unsigned int wmActive;              /* 0x1C: WM initialized and not yet ended */
    unsigned int phase;                 /* 0x20: main loop phase */
    unsigned char subPhase;             /* 0x24 */
    unsigned char childPhase;           /* 0x25: sub-phase of the receive flow (phase 32) */
    unsigned char recruitPhase;         /* 0x26 */
    unsigned char waitCounter;          /* 0x27 */
    unsigned char standalone;           /* 0x28: copy of arg->standalone */
    /* 1 byte of alignment padding at 0x29 */
    unsigned short timeoutFrames;       /* 0x2A */
    unsigned int payloadQueued;         /* 0x2C */
    unsigned int lobbyAccepted;         /* 0x30 */
    int answer;                         /* 0x34 */
    unsigned short bestChildCount;      /* 0x38: stored to event work 16384 on exit */
    unsigned short transferCount;          /* 0x3A: stored to event work 16385 on exit */
    unsigned short receivedTotal;       /* 0x3C */
    /* 2 bytes of alignment padding at 0x3E */
    int notEnoughRoom;                  /* 0x40 */
    int receivedBonus;                  /* 0x44 */
    int gotTrainerKey;                  /* 0x48 */
    void *saveState;                    /* 0x4C */
    unsigned short *gameNameBuf;        /* 0x50 */
    unsigned short *gameIntroBuf;       /* 0x54 */
    MbPayloadHeader header;             /* 0x58 */
    void *payload;                      /* 0x60 */
    unsigned int payloadSize;           /* 0x64 */
    struct MbMsgWork *msg;              /* 0x68: MB_UTIL_MSG work block */
    void *clactUnit;                    /* 0x6C */
    unsigned int paletteId;             /* 0x70 */
    unsigned int charId;                /* 0x74 */
    unsigned int cellAnimId;            /* 0x78 */
    void *actor;                        /* 0x7C */
    MbRegistryBlock registry;           /* 0x80 */
} MbCommSysWork;

#include "../types.h"
#include "../ov107/mb_comm_shared_types.h"
MbNetState *MB_COMM_SYS_CreateNetState(u16 heapId);
void MB_COMM_SYS_DeleteNetState(MbNetState *net);
void MB_COMM_SYS_UpdateNetState(MbNetState *net);
void MB_COMM_SYS_StartNetSession(MbNetState *net);
void MB_COMM_SYS_StopNetSession(MbNetState *net);
int MB_COMM_SYS_GetNetRunState(MbNetState *net);
int MB_COMM_SYS_IsNetSessionNull(MbNetState *net);
void MB_COMM_SYS_StartNet(MbNetState *net);
void MB_COMM_SYS_SetSyncRange(MbNetState *net);
int MB_COMM_SYS_IsSyncDone(MbNetState *net);
int MB_COMM_SYS_IsLoginDone(MbNetState *net);
int MB_COMM_SYS_GetCommStage(MbNetState *net);
void MB_COMM_SYS_ClearRoundFlags(MbNetState *net);
int MB_COMM_SYS_HasKind11(MbNetState *net);
int MB_COMM_SYS_HasKind12(MbNetState *net);
int MB_COMM_SYS_HasKind12Again(MbNetState *net);
int MB_COMM_SYS_HasKind14(MbNetState *net);
int MB_COMM_SYS_HasKind1(MbNetState *net);
int MB_COMM_SYS_HasKind2(MbNetState *net);
int MB_COMM_SYS_HasKind4(MbNetState *net);
int MB_COMM_SYS_GetCount(MbNetState *net);
int MB_COMM_SYS_HasKind19(MbNetState *net);
unsigned short MB_COMM_SYS_GetOfferCount(MbNetState *net);
unsigned short MB_COMM_SYS_GetOfferExtra(MbNetState *net);
int MB_COMM_SYS_GetOfferFlagA(MbNetState *net);
int MB_COMM_SYS_GetOfferFlagB(MbNetState *net);
int MB_COMM_SYS_HasKind20(MbNetState *net);
int MB_COMM_SYS_HasKind21(MbNetState *net);
int MB_COMM_SYS_GetKind21Value(MbNetState *net);
void MB_COMM_SYS_QueuePayload(int a, int payload, int payloadSize);
void MB_COMM_SYS_ClearMonBuffer(MbNetState *net);
int MB_COMM_SYS_HasMonsReceived(MbNetState *net);
u8 MB_COMM_SYS_GetMonCount(MbNetState *net);
void *MB_COMM_SYS_GetMon(MbNetState *net, int i);
int MB_COMM_SYS_GetMaxSeen(MbNetState *net);
int MB_COMM_SYS_HasKind0(MbNetState *net);
int MB_COMM_SYS_SendMessage(void *net, unsigned char kind, unsigned int value);
void MB_COMM_SYS_OnMessage(int a, int b, MbCommMsg *msg, MbNetState *net);
int MB_COMM_SYS_SendHeader(void *net, MbPayloadHeader *header);
void MB_COMM_SYS_OnHeaderReceived(int a, int b, int c, MbNetState *net);
void *MB_COMM_SYS_GetHeaderBuffer(void *a, MbNetState *net);
void MB_COMM_SYS_OnMonsReceived(int a, int b, int c, MbNetState *net);
void *MB_COMM_SYS_GetMonBuffer(int a, MbNetState *net);
int *MB_COMM_SYS_GetChildDataPtr(void);
int MB_COMM_SYS_GetMemberCount(void);

#endif
