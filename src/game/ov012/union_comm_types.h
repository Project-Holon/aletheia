/*
 * Types of the union room communication work (ov012 union_comm.c,
 * union_main.c and the union command table).  The same work is passed to
 * ov019 (union_oneself.c), ov022 (union_app.c) and ov031 (union_subdisp.c).
 * Defines the base integer types itself so the ov012 sources do not repeat
 * them; VecFx32 still comes from the including file, since the includers use
 * distinct anonymous or named definitions of it.
 */
#ifndef UNION_COMM_TYPES_H
#define UNION_COMM_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

/* Sources in a subdirectory (unplaced/) include the ov010 header themselves,
 * since this relative path is resolved from the source file's directory. */
#ifndef ALETHEIA_OV010_COMM_PLAYER_TYPES_H
#include "../version.h"
#include "../ov010/comm_player_types.h"
#endif

struct MyStatus;
struct GameComm;
struct GameData;
struct GameSystem;
struct Regulation;
struct TrainerCardProfile;
struct Party;
struct UnionAppWork;
struct WordSet;
struct MsgBank;
struct Strbuf;

#define UNION_HEAP_ID            0x41
#define UNION_MEMBER_MAX         5
#define UNION_CHARA_MAX          50
#define UNION_BEACON_PC_MAX      10
#define UNION_CHAT_LOG_MAX       30
#define UNION_RECV_BUFFER_SIZE   0x800
#define UNION_BEACON_PC_LIFE     450
#define UNION_PM_VERSION         PM_VERSION_ID
#define UNION_LANGUAGE           2
#define UNION_STATUS_NONE        0x1B
#define UNION_PLAY_CATEGORY_COLOSSEUM 0x2A

/* Easy chat sentence (8 bytes). */
typedef struct UnionPmsData {
    u16 word[4];
} UnionPmsData;

/* Parameters the field gives the union comm (0x10 bytes, UNION_MAIN_StartComm). */
typedef struct UnionParentWork {
    struct MyStatus *myStatus;      /* 0x00 */
    struct GameComm *gameComm;      /* 0x04 */
    struct GameData *gameData;      /* 0x08 */
    struct GameSystem *gameSystem;  /* 0x0C */
} UnionParentWork;

/* One member of a connected group (8 bytes). */
typedef struct UnionMember {
    u8 mac[6];         /* 0x00 */
    u8 trainerView;    /* 0x06 */
    u8 sex : 1;        /* 0x07 bit 0 */
    u8 valid : 1;      /* 0x07 bit 1 */
} UnionMember;

/* The members of one group, as a struct so beacons can copy it whole. */
typedef struct UnionMemberGroup {
    UnionMember member[UNION_MEMBER_MAX];
} UnionMemberGroup;

/* Beacon of one union room player (0x64 bytes, sent by GFL_NET). */
typedef struct UnionBeacon {
    u8  mac[6];               /* 0x00 own MAC, or the parent's MAC when a child */
    u8  connectNum : 3;       /* 0x06 */
    u8  appActive : 1;        /* 0x06 union app (ov022) is running */
    u8  trainerView : 4;      /* 0x06 */
    u8  chatType : 3;         /* 0x07 */
    u8  sex : 1;              /* 0x07 */
    u8  valid : 1;            /* 0x07 */
    u8  appealNo : 3;         /* 0x07 */
    u8  pmVersion;            /* 0x08 */
    u8  language;             /* 0x09 */
    u8  playCategory;         /* 0x0A */
    u8  status;               /* 0x0B */
    u16 name[8];              /* 0x0C */
    UnionPmsData chatPms;     /* 0x1C */
    u16 chatCount;            /* 0x24 */
    u8  nation;               /* 0x26 */
    u8  area;                 /* 0x27 */
    UnionMemberGroup group;   /* 0x28 */
    u8  friendKey[0xC];       /* 0x50 */
    u32 trainerId;            /* 0x5C */
    u32 reserved60;           /* 0x60 never written by union_comm.c */
} UnionBeacon;

/* The avatar (field object) of one member of a beacon group (12 bytes,
 * UNION_CHARA_MAX entries at work + 0x2E88; created by ov019). */
typedef struct UnionCharaSlot {
    struct UnionBeaconPc *beaconPc; /* 0x00 beacon the member belongs to */
    u8 trainerView;            /* 0x04 */
    u8 sex;                    /* 0x05 */
    u8 memberIndex;            /* 0x06 slot in the group, 0 is the parent */
    u8 inUse;                  /* 0x07 */
    u8 action;                 /* 0x08 UNION_CHARA_ACTION_* now running */
    u8 nextAction;             /* 0x09 runs when the current one ends */
    u8 phase;                  /* 0x0A 0 start, 1 main, 2 end */
    u8 step;                   /* 0x0B step inside the phase function */
} UnionCharaSlot;

/* A beacon received from another player (0x8C bytes). */
typedef struct UnionBeaconPc {
    UnionBeacon beacon;       /* 0x00 */
    u8  mac[6];               /* 0x64 sender MAC */
    u8  updateState;          /* 0x6A 1 new, 2 updated */
    u8  index;                /* 0x6B slot in beaconPc[] */
    u16 life;                 /* 0x6C frames until the entry expires */
    u8  pad6e[2];
    UnionCharaSlot *charaSlot[UNION_MEMBER_MAX]; /* 0x70 avatar of each member (ov019) */
    u8  pad84[8];
} UnionBeaconPc;

/* MAC packet of command 0x1403 (8 bytes). */
typedef struct UnionMacPacket {
    u8 mac[6];      /* 0x00 */
    u8 enabled;     /* 0x06 */
    u8 pad07;
} UnionMacPacket;

/* Connection state of the player (0x4C bytes, mySituation + 0x14). */
typedef struct UnionConnectInfo {
    UnionBeacon *talkParam;        /* 0x00 (UNION_COMM_SetSituationParam id 0) beacon of the player being talked to */
    UnionBeaconPc *talkPc;         /* 0x04 (id 1) */
    UnionBeaconPc *connectParam;   /* 0x08 (id 2) */
    UnionBeaconPc *connectPc;      /* 0x0C (id 3) parent of the group */
    UnionMacPacket partnerMac;     /* 0x10 command 0x1403 */
    u8  pad18;
    u8  partnerSelectA;            /* 0x19 command 0x1401 (0xFF none) */
    u8  partnerSelectB;            /* 0x1A command 0x1402 (0xFF none) */
    u8  partnerSelectC;            /* 0x1B (0xFF none) */
    UnionMemberGroup group;        /* 0x1C, slot 0 is the player */
    u16 requestId;                 /* 0x44 (0xFFFF none) */
    u8  serviceLocked : 1;         /* 0x46 bit 0: accept only the own service id */
    u8  serviceFlag : 1;           /* 0x46 bit 1 */
    u8  partnerMode : 2;           /* 0x46 bits 2-3, command 0x1404 */
    u8  modeExtra : 4;             /* 0x46 bits 4-7 */
    u8  myStatusRecvBits;          /* 0x47 command 0x1405, one bit per netId */
    u8  talkCount;                 /* 0x48 how often the parent talk menu was shown */
    u8  trainerCardReceived;       /* 0x49 command 0x1406 */
    u8  syncReadyBits;             /* 0x4A command 0x1400, one bit per netId */
    u8  syncStep : 7;              /* 0x4B */
    u8  syncActive : 1;            /* 0x4B bit 7 */
} UnionConnectInfo;

/* The player's own state in the union room (0x7C bytes, work + 0x2830). */
typedef struct UnionMySituation {
    u8  status;               /* 0x00 sub-event status, beacon status */
    u8  playCategory;         /* 0x01 */
    u8  appealNo;             /* 0x02 */
    u8  pad03;
    UnionPmsData chatPms;     /* 0x04 easy chat sentence */
    u16 chatCount;            /* 0x0C */
    u8  chatUpdated;          /* 0x0E */
    u8  chatType;             /* 0x0F */
    u8  pad10[4];
    UnionConnectInfo connect; /* 0x14 */
    u32 subMenuArg;           /* 0x60 list argument of UNION_MSG_SetupSubMenu */
    u32 partyFailMask;        /* 0x64 regulation violations of my party */
    u32 teamFailMask;         /* 0x68 regulation violations of the battle team */
    s16 waitTimer;            /* 0x6C connect timeout in frames */
    s16 subState;             /* 0x6E menu kind, refusal reason or retry flag of the current action */
    u8  prevPlayCategory;     /* 0x70 action that ended last */
    u8  nextPlayCategory;     /* 0x71 action that starts when this one ends */
    u8  phase;                /* 0x72 */
    u8  step;                 /* 0x73 */
    u8  focusMac[6];          /* 0x74 member the chat log asked the field to show */
    u8  pad7a[2];
} UnionMySituation;

/* One line of the chat log (0x24 bytes). */
typedef struct UnionChatEntry {
    u16 name[8];              /* 0x00 sender name */
    UnionPmsData chatPms;     /* 0x10 easy chat sentence */
    u16 chatCount;            /* 0x18 */
    u8 senderMac[6];          /* 0x1A 0xFF when empty */
    u8 sex;                   /* 0x20 picks the line colour in ov031 */
    u8 chatType;              /* 0x21 0 = sentence, 1..5 = fixed message */
    u8 relation;              /* 0x22 0 stranger, 1 wifi friend, 2 known trainer */
    u8 pad23;
} UnionChatEntry;

/* Chat log (0x448 bytes, work + 0x30E0, drawn by ov031). */
typedef struct UnionChatLog {
    UnionChatEntry entry[UNION_CHAT_LOG_MAX]; /* 0x000 */
    u8  pad438[4];
    s32 newestIndex;          /* 0x43C -1 empty */
    s32 scrollIndex;          /* 0x440 -1 empty */
    s32 drawnIndex;           /* 0x444 -1 empty */
} UnionChatLog;

/* Sub-event request run by UNION_MAIN_SubEventMain (work + 0x3548). */
typedef struct UnionSubEvent {
    int active;     /* 0x00 */
    int id;         /* 0x04 index in the sub-event table */
    int param;      /* 0x08 */
    u8  seq;        /* 0x0C */
} UnionSubEvent;

/* What a colosseum player tells the others (0x2C bytes, names from colosseum.c). */
typedef struct ColosseumPlayer {
    u8 myStatus[0x20];  /* 0x00 MyStatus copy */
    u8 statusExtra[6];  /* 0x20 */
    u8 isEntered;       /* 0x26 */
    u8 modeFlag;        /* 0x27 */
    u8 levelLimit;      /* 0x28 */
    u8 pad29[3];
} ColosseumPlayer;

/* Colosseum work as union_comm.c sees it (0x170 bytes; field names follow
 * src/game/ov012/colosseum.c). */
typedef struct ColosseumWork {
    void *commPlayer;                  /* 0x000 */
    CommPlayerPackage myPackage;       /* 0x004 */
    ColosseumPlayer player[4];         /* 0x018 */
    u8 startFlag : 1;                  /* 0x0C8 bit 0 */
    u8 leaveSent : 1;                  /* 0x0C8 bit 1 */
    u8 exitRequested;                  /* 0x0C9 delete the colosseum when the field closes */
    u8 entryCancelled;                 /* 0x0CA command 0x1409 */
    u8 allReady;                       /* 0x0CB */
    u8 choice[4];                      /* 0x0CC */
    u8 choiceReply[4];                 /* 0x0D0 */
    u8 readyReceived[4];               /* 0x0D4 */
    u8 readyCancelled[4];              /* 0x0D8 */
    u8 myChoice;                       /* 0x0DC */
    u8 myChoiceReply;                  /* 0x0DD */
    u8 parentSetting;                  /* 0x0DE command 0x1408 */
    u8 readySent;                      /* 0x0DF */
    CommPlayerPackage package[4];      /* 0x0E0 */
    u8 packageReceived[4];             /* 0x130 */
    struct TrainerCardProfile *trainerCard[4]; /* 0x134 */
    u8 trainerCardReceived[4];         /* 0x144 */
    struct Party *party[4];            /* 0x148 */
    u8 partyReceived[4];               /* 0x158 */
    u8 battlePosition[4];              /* 0x15C */
    u8 positionsReceived;              /* 0x160 */
    u8 confirmCount;                   /* 0x161 */
    u8 finished[4];                    /* 0x162 */
    u8 pad166[2];
    void *entryMenu;                   /* 0x168 ov021 comm entry menu */
    u8 talkPlayer;                     /* 0x16C colosseum player being talked to */
    u8 partySource;                    /* 0x16D 0 party, 1 battle team */
    u8 entryBits;                      /* 0x16E result bits of the comm entry menu */
    u8 packageChanged;                 /* 0x16F */
} ColosseumWork;

/* Message work of the union room (UnionRoomWork 0x2804..0x2827, used by ov019).
 * The byte at 0x2828 is UnionRoomWork.msgTalkPrinting: a trailing byte here
 * would pad the struct to 0x28 and move every later field. */
typedef struct UnionMsgWork {
    struct WordSet *wordSet;       /* 0x00 */
    struct MsgBank *msgData;       /* 0x04 field message archive 200 */
    void *talkWin;                 /* 0x08 stream talk window */
    void *menu;                    /* 0x0C list menu */
    void *yesNo;                   /* 0x10 yes/no menu */
    void *infoWin;                 /* 0x14 title or regulation window */
    u8 pad18[4];
    struct Strbuf *strTemp;        /* 0x1C message before word expansion */
    struct Strbuf *strExpand;      /* 0x20 expanded message */
} UnionMsgWork;

/* Regulation text of POKE_REGULATION_CreateText (0x34 bytes). */
typedef struct UnionRegulationText {
    u32 count;
    struct Strbuf *label[6];
    struct Strbuf *value[6];
} UnionRegulationText;

/* The union room work (0x3570 bytes, heap 0x41). */
typedef struct UnionRoomWork {
    UnionParentWork *parent;                        /* 0x0000 */
    u8  recvBuffer[UNION_MEMBER_MAX][UNION_RECV_BUFFER_SIZE]; /* 0x0004 */
    UnionMsgWork msgWork;                           /* 0x2804 used by ov019 */
    u8  msgTalkPrinting;                            /* 0x2828 */
    u8  beaconChanged;                              /* 0x2829 */
    u8  fieldActive;                                /* 0x282A */
    u8  entryResult;                                /* 0x282B 0 wait, 1 accepted, 2 refused */
    u8  entryAcceptBits;                            /* 0x282C */
    u8  entryRefuseBits;                            /* 0x282D */
    u8  talkCancel;                                 /* 0x282E set by the sub screen (ov031); opens the chat input in ov019 */
    u8  pad282f;
    UnionMySituation mySituation;                   /* 0x2830 */
    UnionBeacon myBeacon;                           /* 0x28AC */
    UnionBeaconPc beaconPc[UNION_BEACON_PC_MAX];    /* 0x2910 */
    UnionCharaSlot charaSlot[UNION_CHARA_MAX];      /* 0x2E88 used by ov019 */
    UnionChatLog chatLog;                           /* 0x30E0 */
    struct UnionAppWork *app;                       /* 0x3528 ov022 union_app */
    struct Regulation *regulation;                  /* 0x352C */
    UnionRegulationText *regulationText;            /* 0x3530 */
    void *partySelect;                              /* 0x3534 ov021 selection work over the party (ov019) */
    void *partySelectParam;                         /* 0x3538 its parameter block (ov019) */
    void *partnerCard;                              /* 0x353C card profile built from recvTrainerCard (ov019) */
    void *myTrainerCard;                            /* 0x3540 sent with command 0x1406 */
    void *recvTrainerCard;                          /* 0x3544 filled by command 0x1406 */
    UnionSubEvent subEvent;                         /* 0x3548 */
    void *sceneParam;                               /* 0x3558 parameter block of the scene requested with UNION_MAIN_RequestScene */
    ColosseumWork *colosseum;                       /* 0x355C */
    u8  commState;                                  /* 0x3560 */
    u8  resetSeq;                                   /* 0x3561 */
    u8  resetMode;                                  /* 0x3562 */
    u8  fieldBusy;                                  /* 0x3563 */
    int fieldRequestArmed;                          /* 0x3564 set while the field request key is not held */
    int fieldRequest;                               /* 0x3568 read by ov021 */
    u32 exitStarted;                                /* 0x356C */
} UnionRoomWork;

#endif
