#ifndef LIVEBATTLEMATCH_SHARED_TYPES_H
#define LIVEBATTLEMATCH_SHARED_TYPES_H

/* Types shared by the ov176 live battle match files: livebattlematch_flow.c,
 * livebattlematch_irc.c and digitalcardcheck.c. Base C types only, so this
 * header can be included next to the primitive typedefs each file keeps. */

struct GfFont;

/* The live battle match work (0x1DC bytes) created by LIVEBATTLEMATCH_FLOW_Create.
 * One object, viewed through Obj00053 / Obj00241 / Obj01271 / Obj14362 / Obj14364 /
 * Obj14365 / Obj02889 / Obj10701 / Obj10702 / Obj10703 before this fold. */
struct LiveBattleMatchWork {
    void *proc;               /* 00 sub proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    void *window;             /* 04 window returned by WIFIBATTLEMATCH_UTIL_CreateMenu */
    int   mode;               /* 08 menu mode last drawn */
    void *irc;                /* 0C IRC delivery work created by LIVEBATTLEMATCH_IRC_Create */
    void *record;             /* 10 print record (WIFIBATTLEMATCH_VIEW_CreateDateWindow / WIFIBATTLEMATCH_VIEW_StepMainWindow) */
    void *record2;            /* 14 second print record (WIFIBATTLEMATCH_VIEW_CreateRecordWindow / WIFIBATTLEMATCH_VIEW_DeleteRecordWindow) */
    void *record3;            /* 18 third print record (WIFIBATTLEMATCH_VIEW_CreatePartyWindow / WIFIBATTLEMATCH_VIEW_DeletePartyWindow) */
    void *viewObj;            /* 1C view object built by WIFIBATTLEMATCH_VIEW_CreateActorArray */
    unsigned int menuValue;   /* 20 copied into the menu descriptor x0 */
    void *mgr;                /* 24 manager pointer handed to the print helpers */
    int   arg28;              /* 28 int argument for WIFIBATTLEMATCH_VIEW_CreatePartyWindow */
    int   arg2C;              /* 2C int argument for WIFIBATTLEMATCH_VIEW_CreateDateWindow */
    void *party;              /* 30 pokemon party created by POKEPARTY_Create */
    void *saveBlock;          /* 34 save record base (MISC_SAVEDATA_GetRecordBase) */
    void *card;               /* 38 regulation card (REGULATION_GetCard) */
    unsigned char card_3C[0x160]; /* 3C local regulation card */
    int   flowResult;         /* 19C flow result read by LIVEBATTLEMATCH_FLOW_GetResult */
    int   initMode;           /* 1A0 LiveBattleMatchInit.words[0] */
    void *printSys;           /* 1A4 words[1] */
    int   font;               /* 1A8 words[2] font handle, read as int */
    void *printQue;           /* 1AC words[3] */
    int   view;               /* 1B0 words[4], read as int by the print helpers */
    void *graphic;            /* 1B4 words[5] */
    void *save;               /* 1B8 words[6] save control */
    void *battleData;         /* 1BC words[7] battle record */
    void *partyData;          /* 1C0 words[8] party record */
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
    unsigned char pad_6[0x1002];   /* 06 send/receive data buffer */
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
    void *menuObj;    /* 18 menu record object */
    int   param1C;    /* 1C */
    int   reserved20; /* 20 */
    void *mgr;        /* 24 manager pointer */
    int   view;       /* 28 view handle */
    int   param2C;    /* 2C */
    void *save;       /* 30 save control */
} RequestConfig;

typedef struct {
    void *msgBank;          /* 00 message bank (func_02045B38) */
    void *wordSet;          /* 04 word set (WORDSET_Create) */
    void *record;           /* 08 print record handle */
    void *window;           /* 0C menu window returned by WIFIBATTLEMATCH_UTIL_CreateMenu */
    int   callback;         /* 10 sub proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    RequestConfig config;   /* 14 slot and seven parameters copied from the caller */
    unsigned short heap;    /* 34 heap id */
} Request;


struct GfFont;

struct MsgBank;

struct Rec;

struct Big;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed char    s8;

typedef unsigned short u16;

typedef signed int     s32;

/* Partial view of the arm9 regulation card (0x160 bytes); only the BGM byte
 * at 0x15B is read here. The arm9 owner is src/game/arm9/regulation.c. */
struct RegulationCard {
    u8 pad_0[0x15B];
    s8 bgm;
};

/* Callback descriptor used by the ov177 flow helpers. */
typedef struct {void (*fn)(void *,int *,int);int a;int b;} FlowCallback;

/* Menu descriptor handed to WIFIBATTLEMATCH_UTIL_CreateMenu (ov177 names this type Desc). */
typedef struct {
    u32 x0,x1,x2;
    u32 items[4];
    u32 count;
    u16 a,b,c,d;
    u32 enabled;
    u16 kind,pad;
} Desc;

/* 40-byte init block copied into the live battle match object. */
typedef struct { u32 words[10]; } LiveBattleMatchInit;

#endif
