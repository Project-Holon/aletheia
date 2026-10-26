#ifndef LIVEBATTLEMATCH_SHARED_TYPES_H
#define LIVEBATTLEMATCH_SHARED_TYPES_H

/* Types shared by the ov176 live battle match files: livebattlematch_flow.c,
 * livebattlematch_irc.c and digitalcardcheck.c. Base C types only, so this
 * header can be included next to the primitive typedefs each file keeps. */

struct GfFont;
struct MsgBank;
struct PrintQueue;
struct GameData;
struct WifibattlematchCallback;
struct WifibattlematchUtilWork;
struct WifibattlematchMenu;
struct WifibattlematchGraphic;
struct WordSet;
struct BattleRecord;
struct Party;
struct RegulationCard;
struct WifiBattleMatchViewAnimState;

/* The live battle match work (0x1DC bytes) created by LIVEBATTLEMATCH_FLOW_Create. */
struct LiveBattleMatchWork {
    struct WifibattlematchCallback *proc; /* 00 sub proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    struct WifibattlematchMenu *window; /* 04 window returned by WIFIBATTLEMATCH_UTIL_CreateMenu */
    int   mode;               /* 08 menu mode last drawn */
    struct LiveBattleMatchIrcWork *irc; /* 0C IRC delivery work created by LIVEBATTLEMATCH_IRC_Create */
    void *record;             /* 10 print record (WIFIBATTLEMATCH_VIEW_CreateDateWindow / WIFIBATTLEMATCH_VIEW_StepMainWindow) */
    void *record2;            /* 14 second print record (WIFIBATTLEMATCH_VIEW_CreateRecordWindow / WIFIBATTLEMATCH_VIEW_DeleteRecordWindow) */
    void *record3;            /* 18 third print record (WIFIBATTLEMATCH_VIEW_CreatePartyWindow / WIFIBATTLEMATCH_VIEW_DeletePartyWindow) */
    void **viewObj;           /* 1C view object built by WIFIBATTLEMATCH_VIEW_CreateActorArray */
    struct MsgBank *menuValue; /* 20 message bank copied into the menu descriptor */
    struct MsgBank *mgr;      /* 24 second message bank handed to the print helpers */
    struct GfFont *partyFont; /* 28 font argument for WIFIBATTLEMATCH_VIEW_CreatePartyWindow */
    struct WordSet *arg2C;    /* 2C word set handed to the view windows */
    struct Party *party;      /* 30 pokemon party created by POKEPARTY_Create */
    unsigned char *saveBlock; /* 34 save record base (LIVEBATTLEMATCH_SAVE_GetRecord) */
    struct RegulationCard *card; /* 38 regulation card (REGULATION_GetCard) */
    unsigned char card_3C[0x160]; /* 3C local regulation card */
    int   flowResult;         /* 19C flow result read by LIVEBATTLEMATCH_FLOW_GetResult */
    int   initMode;           /* 1A0 LiveBattleMatchInit.words[0] */
    struct WifibattlematchUtilWork *printSys; /* 1A4 words[1] */
    struct GfFont *font;      /* 1A8 words[2] */
    struct PrintQueue *printQue; /* 1AC words[3] */
    struct WifiBattleMatchViewAnimState *view; /* 1B0 words[4] */
    struct WifibattlematchGraphic *graphic; /* 1B4 words[5] */
    struct GameData *save;    /* 1B8 words[6] game data */
    struct BattleRecord *battleData; /* 1BC words[7] battle record */
    struct BattleRecord *partyData; /* 1C0 words[8] party record */
    void *stateObj;           /* 1C4 words[9] caller state object */
    unsigned short heap;      /* 1C8 heap id */
    unsigned char pad_1CA[2]; /* 1CA */
    unsigned int timer;       /* 1CC result-wait counter */
    int   hasExtraOption;     /* 1D0 selects an extra menu option */
    unsigned int syncFlag;    /* 1D4 timing-sync result flag */
    unsigned int syncValue;   /* 1D8 timing-sync received value */
};

/* The battle record pointed to by LiveBattleMatchWork.battleData (1BC) and
 * partyData (1C0). Only the fields this region reads are named. */
struct BattleRecord {
    unsigned char data[0x28];   /* 00 status, mac and copy target */
    unsigned int stat1;         /* 28 save stat 1 */
    unsigned int stat2;         /* 2C save stat 2 */
    unsigned int stat0;         /* 30 save stat 0 */
    unsigned char pad_34[0xC];  /* 34 */
    unsigned int cardValue;     /* 40 regulation card value (rule id) */
    unsigned int version;       /* 44 version read by BATTLE_REC_IsVersionSupported */
    unsigned char pad_48[0x8C]; /* 48 */
    unsigned char pokeData[0xE8]; /* D4 regulation data copy */
};

/* The caller state object pointed to by LiveBattleMatchWork.stateObj (1C4). */
struct LiveMatchState {
    unsigned int kind;           /* 00 */
    unsigned char pad_4[4];      /* 04 */
    unsigned char byte8, byte9;  /* 08, 09 stored into the save record */
    unsigned char pad_A[2];      /* 0A */
    int flag;                    /* 0C extra option gate */
};

/* The IRC delivery work (0x1020 bytes) created by LIVEBATTLEMATCH_IRC_Create. It wraps the
 * DELIVERY_IRC handle and four received-command flags. */
struct LiveBattleMatchIrcWork {
    unsigned int state;            /* 00 state machine step */
    unsigned short heap;           /* 04 heap id */
    unsigned char data[0x1002];    /* 06 send/receive data buffer */
    int recvFlag0;                 /* 1008 command 1F00 payload size */
    int recvFlag1;                 /* 100C command 1F01 payload ready */
    int recvFlag2;                 /* 1010 command 1F02 payload ready */
    int recvFlag3;                 /* 1014 command 1F03 payload ready */
    void *delivery;                /* 1018 DELIVERY_IRC handle */
    int deliveryResult;            /* 101C DELIVERY_IRC result */
};

/* The digital card check work (0x38 bytes), created by DIGITALCARDCHECK_Create. Shared by
 * livebattlematch_irc.c and digitalcardcheck.c (there named Request). */
typedef struct {
    int   slot;       /* 14 card slot index */
    struct WifibattlematchUtilWork *printSys; /* 18 message window */
    struct GfFont *font; /* 1C font */
    struct MsgBank *msgBank; /* 20 message bank */
    struct PrintQueue *printQue; /* 24 print queue */
    struct WifiBattleMatchViewAnimState *view; /* 28 view root */
    struct WifibattlematchGraphic *graphic; /* 2C graphics */
    struct GameData *save; /* 30 game data */
} RequestConfig;

typedef struct {
    struct MsgBank *msgBank; /* 00 message bank (MSGDATA_CreateFromArchive) */
    void *wordSet;          /* 04 word set (WORDSET_Create) */
    void *record;           /* 08 print record handle */
    struct WifibattlematchMenu *window; /* 0C menu window returned by WIFIBATTLEMATCH_UTIL_CreateMenu */
    struct WifibattlematchCallback *callback; /* 10 sub proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    RequestConfig config;   /* 14 slot and seven parameters copied from the caller */
    unsigned short heap;    /* 34 heap id */
} LivebattlematchRequest;

struct GfFont;

struct MsgBank;

struct Rec;

struct Big;

#include "../types.h"

/* Partial view of the arm9 regulation card (0x160 bytes); only the BGM byte
 * at 0x15B is read here. The arm9 owner is src/game/arm9/regulation.c. */
#include "../arm9/regulation_types.h"

/* Callback descriptor used by the ov177 flow helpers. */

/* Menu descriptor handed to WIFIBATTLEMATCH_UTIL_CreateMenu (0x30 bytes).
 * Same object as ov177 WifibattlematchMenuDesc, so the fields keep one name. */
#include "../ov177/wifibattlematch_menu_types.h"

/* 40-byte init block copied into the live battle match object. */
typedef struct LiveBattleMatchInit {
    int mode;                                               /* 00 */
    struct WifibattlematchUtilWork *printSys;               /* 04 */
    struct GfFont *font;                                    /* 08 */
    struct PrintQueue *printQue;                            /* 0C */
    struct WifiBattleMatchViewAnimState *view;              /* 10 */
    struct WifibattlematchGraphic *graphic;                 /* 14 */
    struct GameData *save;                                  /* 18 */
    struct BattleRecord *battleData;                        /* 1C */
    struct BattleRecord *partyData;                         /* 20 */
    void *stateObj;                                         /* 24 */
} LiveBattleMatchInit;

#endif
