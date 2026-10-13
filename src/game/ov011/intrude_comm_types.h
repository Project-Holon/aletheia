/*
 * Types of the intrude communication work (ov011): the state of one
 * wireless visit session, shared by intrude_comm.c and the command
 * handlers that follow it. Needs u8, u16, u32, s8, s16 and s32 from the
 * including file.
 */
#ifndef INTRUDE_COMM_TYPES_H
#define INTRUDE_COMM_TYPES_H

struct GameSystem;
struct GameComm;
struct CommPlayerWork;
struct STRBUF;

/* Position package of one player (same layout as CommPlayerPackage in comm_player.c). */
typedef struct IntrudePosition {
    s32 x;
    s32 y;
    s32 z;
} IntrudePosition;

typedef struct IntrudePlayerPackage {
    u32 vanish;             /* 0x00 */
    IntrudePosition pos;    /* 0x04 */
    u16 zoneId;             /* 0x10 */
    u8 dir;                 /* 0x12 */
} IntrudePlayerPackage;

/* Status of one player in the visit, 0x1C bytes. It is sent over the net as command 0x205. */
typedef struct IntrudePeer {
    IntrudePlayerPackage package;   /* 0x00 */
    u16 zoneId;                     /* 0x14 */
    u16 intrudeId : 3;              /* 0x16: net ID of the player whose area this is */
    u16 symbolMapFlag : 6;
    u16 state : 6;
    u16 lidClosed : 1;
    u16 objCode;                    /* 0x18: field object code; 0 default, 0xFFFF picked by gender */
    u8 lookKind : 4;                /* 0x1A: player look kind, 3 male, 4 female by default (ChangePlayerLook) */
    u8 lookFlag : 1;                /* the look's flag, the gender for the default look */
    u8 eventJoined : 1;             /* the player took part in the open request (set when the session is accepted) */
    u8 season : 2;
    u8 statusCode : 6;              /* 0x1B: 0x15 once the player stands in the field */
    u8 startFlag : 1;               /* set by the parent when the visit starts */
    u8 remoteVanish : 1;            /* package.vanish is saved here while the package is resent */
} IntrudePeer;

/* Broadcast header of the session, followed by the owner's MyStatus. */
typedef struct IntrudeBeacon {
    u8 gameKind;                    /* 0x00: 2 */
    u8 connectNum : 4;              /* 0x01: players connected now */
    u8 maxConnect : 4;              /* 0x01: players allowed */
    u8 hasNetError : 1;             /* 0x02 */
    u8 version : 5;
    u8 reserved : 2;
    u8 pad03[5];
    u8 ownerStatus[0x20];           /* 0x08: copy of MyStatus */
} IntrudeBeacon;

/* One member name: eight characters (0x10 bytes). */
typedef struct IntrudeNameChars {
    u16 chars[8];
} IntrudeNameChars;

/* Name object of a member (0x14 bytes): characters, net ID and gender. */
typedef struct IntrudeMemberName {
    IntrudeNameChars name;
    u8 netId;
    u8 gender : 1;
    u8 genderRest : 7;
    u16 pad12;
} IntrudeMemberName;

/* One member slot of the session (0x28 bytes). */
typedef struct IntrudeMemberEntry {
    IntrudeNameChars name;
    u8 filled;                  /* 0x10: 1 once the entry holds a member */
    u8 gender;
    u8 senderNetId;             /* net ID of the player that told us about the member */
    u8 pad13;
    IntrudeMemberName member;   /* 0x14: member.netId is the member's net ID */
} IntrudeMemberEntry;

typedef struct IntrudeParamPair {
    u16 x;
    u16 y;
} IntrudeParamPair;

/* Header of a request (0x18 bytes): bit fields, then the argument block. */
typedef struct IntrudeRequestHead {
    u32 seed : 15;
    u32 count : 7;              /* at most 20 */
    u32 amount : 10;            /* at most 180 */
    u32 kind : 4;               /* 0 to 5 */
    u32 modeBits : 3;
    u32 areaIndex : 11;         /* below 46 */
    u32 pointIndex : 11;        /* below 83 */
    u32 extraBits : 3;
    u16 reserved08;
    u16 ids[3];                 /* each checked by the id validator */
    u8 grades[4];               /* the first three are below 5 */
    IntrudeParamPair param;     /* x: kind 3 id (validated), kinds 0 to 2 number; y: kind 4 id (validated), kind 3 number */
} IntrudeRequestHead;

/* 0x34-byte record exchanged by commands 0x212 to 0x216 and kept in the session. */
typedef struct IntrudeMemberRecord {
    IntrudeRequestHead head;    /* 0x00 */
    IntrudeMemberName name;     /* 0x18 */
    u8 netId;                   /* 0x2C: net ID of the sender; 4 = none */
    u8 nameNetId;
    u8 requestFlag;             /* 0x2E */
    u8 pad2F;
    u16 ticksLeft;              /* 0x30: seconds until the start notice, 0 = none */
    u16 amount;                 /* 0x32: time limit in seconds */
} IntrudeMemberRecord;

/* Join request (command 0x210), 0x30 bytes. */
typedef struct IntrudeJoinRequest {
    IntrudeRequestHead head;
    IntrudeMemberName name;
    u8 requestFlag;
    u8 pad2D[3];
} IntrudeJoinRequest;

/* 0x3C-byte result record of command 0x218. */
typedef struct IntrudeResultRecord {
    IntrudeMemberRecord record;
    u8 partnerIds[3];           /* 0x34: net IDs that took part; 4 = free */
    u8 confirmed;               /* 0x37 */
    u8 pad38[4];
} IntrudeResultRecord;

/* One pending proposal (0x38 bytes). */
typedef struct IntrudeProposalSlot {
    u8 state;
    u8 pad01[3];
    IntrudeMemberRecord record;
} IntrudeProposalSlot;

/* Session state at IntrudeCommSys + 0x1AC (0x1A8 bytes). */
typedef struct IntrudeSession {
    IntrudeMemberEntry members[3];      /* 0x000 */
    IntrudeMemberRecord request;        /* 0x078 */
    IntrudeResultRecord result;         /* 0x0AC */
    IntrudeProposalSlot slots[3];       /* 0x0E8 */
    u32 startTick;                      /* 0x190: seconds of the day when the timer started */
    u8 entrySendPending[3];             /* 0x194: per member entry, send command 0x20E */
    u8 replyToSend[3];                  /* 0x197: 1 accepted, 2 refused, per net ID */
    u8 requestSendPending;              /* 0x19A: send the request record (command 0x212) */
    u8 resultChanged;                   /* 0x19B: send the result record (command 0x218) */
    u8 resultReported;                  /* 0x19C: 1 when ticksLeft ran out, 2 once the notice is sent */
    u8 joinedMask;                      /* 0x19D: bit per net ID that joined */
    u8 joinNoticeMask;                  /* 0x19E: joined net IDs still to announce */
    u8 readyBits[2];                    /* 0x19F, 0x1A0: ready bit per net ID */
    u8 requestReceived;                 /* 0x1A1 */
    u8 pad1A2;
    u8 joinReply;                       /* 0x1A3 */
    u8 joinStatus;                      /* 0x1A4 */
    u8 hasResult : 1;                   /* 0x1A5 */
    u8 timeLimitSet : 1;
    u8 accepted : 1;
    u8 finished : 1;
    u8 leaveFlag : 1;
    u8 noticeState : 2;                 /* 0 none, 1 start, 2 end */
    u8 flagBit7 : 1;
    u8 pad1A6[2];
} IntrudeSession;

/* Message of command 0x207, 0x38 bytes: a request from one player to another. */
typedef struct IntrudeRequestMessage {
    u8 type;
    u8 seq;
    s16 pad02;
    IntrudeMemberRecord data;
} IntrudeRequestMessage;

/* 0x4C-byte record of one player, sent as command 0x203 (ownMyStatus, lastBattleRecSlot, selfSnapshot). */
typedef struct IntrudeStatusRecord {
    u8 myStatus[0x20];              /* 0x00 */
    u8 battleRecSlot[0x10];         /* 0x20 */
    IntrudePeer peer;               /* 0x30 */
} IntrudeStatusRecord;

/* Four bytes sent as command 0x20B. */
typedef struct IntrudeNoticeBytes {
    u8 value[4];
} IntrudeNoticeBytes;

/* 16-byte record received as command 0x20D. */
typedef struct IntrudeRemoteRecord {
    u32 words[4];
} IntrudeRemoteRecord;

/* Result counts of a session, sent as command 0x21D. */
typedef struct IntrudeTally {
    u8 countA;
    u8 countB;
    u8 valid;
    u8 pad03;
} IntrudeTally;

/* Symbol map page (0x54 bytes, commands 0x228 and 0x229): 20 entries, then the page header. */
typedef struct IntrudeSymbolPage {
    u32 entries[20];                /* 0x00: filled by func_0216749C */
    u32 count : 6;                  /* 0x50 */
    u32 levelSmall : 4;
    u32 levelLarge : 4;
    u32 netId : 4;
    u32 page : 6;
} IntrudeSymbolPage;

/* Page request from one player (command 0x228). */
typedef struct IntrudePageRequest {
    u8 page;
    u8 pending;
    u8 arg2;
    u8 arg3;
} IntrudePageRequest;

/* Trainer profile of one player (command 0x222). */
typedef struct IntrudeProfile {
    u8 data[0x10];
    u16 code;                       /* 0x10: checked against the valid profile codes, default 0x11 */
    u16 pad12;
} IntrudeProfile;

typedef struct IntrudeCommSys {
    struct GameSystem *gameSystem;              /* 0x000 */
    struct GameComm *gameComm;                  /* 0x004 */
    struct CommPlayerWork *commPlayer;          /* 0x008 */
    IntrudeBeacon beacon;                       /* 0x00C */
    u8 afterBeacon[0x70 - 0x34];                /* 0x034 */
    IntrudePeer localPeer;                      /* 0x070: this player's status, sent to the others */
    IntrudePeer peers[3];                       /* 0x08C: one per net ID */
    IntrudePlayerPackage packages[3];           /* 0x0E0: copies of the peers' packages */
    IntrudeRequestMessage receivedRequest;      /* 0x11C */
    u8 requestTarget;                           /* 0x154: net ID the open request went to, 4 = none */
    u8 replyFrom;                               /* 0x155: net ID that answered the request, 4 = none */
    u8 requestActive;                           /* 0x156 */
    u8 replyResult;                             /* 0x157 */
    u8 sentRequestSeq;                          /* 0x158 */
    u8 expectedReplySeq;                        /* 0x159 */
    u8 pad15A[2];
    IntrudeNoticeBytes notice;                  /* 0x15C */
    u8 ownMyStatus[0x20];                       /* 0x160: MyStatus of this player */
    u8 lastBattleRecSlot[0x10];                 /* 0x180 */
    IntrudePeer selfSnapshot;                   /* 0x190: with ownMyStatus, the record sent as command 0x203 */
    IntrudeSession session;                     /* 0x1AC */
    IntrudeTally ownTally;                      /* 0x354 */
    IntrudeTally partnerTally;                  /* 0x358: received as command 0x21D */
    u8 returnSlots[0x3A4 - 0x35C];              /* 0x35C */
    u8 sendBuffer[0x4C];                        /* 0x3A4: copy of the 0x160 record that goes out */
    IntrudeMemberRecord recordCopy;             /* 0x3F0: send copy of session.request */
    IntrudeResultRecord resultCopy;             /* 0x424: send copy of session.result */
    u8 unionInfoBuffer[0x1E8];                  /* 0x460: send copy of the union info (command 0x225) */
    u8 statusArea[0x670 - 0x648];               /* 0x648 */
    IntrudeStatusRecord statusRecords[3];       /* 0x670 */
    IntrudeMemberRecord memberRecords[3];       /* 0x754 */
    u8 workArea[0x82C - 0x7F0];                 /* 0x7F0 */
    IntrudeSymbolPage peerSymbolPage;           /* 0x82C: page received from a partner */
    IntrudeSymbolPage ownSymbolPage;            /* 0x880: page built for a partner */
    IntrudePageRequest pageRequests[3];         /* 0x8D4: per net ID */
    u8 areaNoticeValue;                         /* 0x8E0 */
    u8 areaNoticePending;                       /* 0x8E1 */
    u8 pad8E2[2];
    IntrudeProfile profile;                     /* 0x8E4: partner profile received */
    u8 profilePending : 1;                      /* 0x8F8 */
    u8 pageReceived : 1;
    u8 areaNoticeSeen : 1;
    u8 flagBit3 : 1;
    u8 requestOpen : 1;
    u8 flagBit5 : 1;
    u8 sessionEnded : 1;
    u8 flagBit7 : 1;
    u8 pad8F9;
    u8 shutdownRequested;                       /* 0x8FA: set by command 0x200 */
    u8 peerMask;                                /* 0x8FB: one bit per net ID that is in the visit */
    u8 pad8FC;
    u8 step;                                    /* 0x8FD: state of the session */
    u8 resendRequested;                         /* 0x8FE: set by command 0x202, cleared when the record is sent */
    u8 joinRetryWait;                           /* 0x8FF: frames before the next join retry */
    u8 peerStatusDirty;                         /* 0x900 */
    u8 lastAreaIndex;                           /* 0x901: highest area index in the map, 0 = own area only; one more area is added per member, up to memberCount - 1 */
    u8 memberCount;                             /* 0x902: players in the visit */
    u8 memberCountDirty;                        /* 0x903: memberCount has to be sent */
    u8 abortFlag : 1;                           /* 0x904 */
    u8 suspended : 1;
    u8 zoneCheck : 2;                           /* 0 not checked, 1 zone is in the zone list, 2 not in it (field handling is skipped); cleared by map change */
    u8 reserved904 : 4;
    u8 reserved905;
    u8 profileUpdated;                          /* 0x906 */
    u8 resultUpdated;                           /* 0x907 */
    u8 unionInfoRequestMask;                    /* 0x908 */
    u8 reserved909;
    u16 idleFrames;                             /* 0x90A */
    u8 unionInfoReceived;                       /* 0x90C */
    u8 entryReceived;                           /* 0x90D */
    s16 waitFrames;                             /* 0x90E */
    u8 specialZoneEntered;                      /* 0x910: set once the player enters a zone of ZONEDATA_IsZone117 */
    u8 ownNetId;                                /* 0x911: own net ID, the value INTRUDE_COMM_GetPlayerNetId answers while the work exists */
    u8 pad912[2];
    IntrudeRemoteRecord remoteRecord;           /* 0x914 */
    u8 readyMask;                               /* 0x924: bit per net ID that answered command 0x20C */
    u8 foundCount;                              /* 0x925: players seen in the scan */
    u8 foundAge;                                /* 0x926 */
    u8 dirtyPeerMask;                           /* 0x927: peers whose field object must be updated */
    struct STRBUF *foundNames[2];               /* 0x928 */
    u32 foundTrainerIds[2];                     /* 0x930 */
    u8 foundSex[2];                             /* 0x938 */
    u8 foundLanguage[2];                        /* 0x93A */
    s8 busyLock;                                /* 0x93C: set when a join request holds the busy state */
    s8 busyCount;                               /* 0x93D: busy begin minus busy end commands */
    u8 tallyPending;                            /* 0x93E: ownTally has to be sent */
    u8 startFlag : 1;                           /* 0x93F: the parent's record had startFlag */
    u8 quit : 1;
    u8 gearReported : 1;                        /* bit 2: set once the C-Gear took the pending state 2 of INTRUDE_COMM_GetVisitProgress */
    u8 infoShown : 1;                           /* bit 3: set when the info event starts, tested by the script command */
    u8 peerFlags : 2;                           /* set by command 0x220 */
    u8 lock : 1;
    u8 reserved93F : 1;
    u32 startTime : 31;                         /* 0x940: seconds of the day at the start */
    u32 warned : 1;
    u8 nextRequestSeq;                          /* 0x944 */
    u8 busyReplies[3];                          /* 0x945: per net ID, sequence of a request still to refuse as busy */
    u8 pendingReplies[4];                       /* 0x948: per net ID, sequence of a reply that came early */
} IntrudeCommSys;

#endif
