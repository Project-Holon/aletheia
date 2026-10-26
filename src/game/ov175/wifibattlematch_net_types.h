#ifndef GAME_OV175_WIFIBATTLEMATCH_NET_TYPES_H
#define GAME_OV175_WIFIBATTLEMATCH_NET_TYPES_H

#include "../types.h"
#include "../ov009/dwc_match_ctl_types.h"

struct Proc;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintQueue;
struct MsgBank;
struct Proc;
struct GameData;
struct GameSyncData;
struct CgearSaveBlock;
struct Strbuf;
struct MsgRec;
struct PmsData;
struct MetTrainersSave;
struct MyStatus;
struct WifibattlematchNetRecord;
struct WifiBattleMatchViewPartyWork;
struct GameData;
struct QuadRecord;
struct Party;
struct BattleCompetitionSave;
struct WifibattlematchNetObj;
struct RegulationParty;
struct BattleCompetitionSave;
struct BattleCompetitionSave;
struct GFLNetHandle;
struct GFLNetHandle;
struct MyStatus;
struct GameData;
typedef int (*Callback)(void *,void *,void *,void *);

typedef struct { Callback create,other,close; } WifiBattleMatchNetTable;

#include "../types.h"

typedef struct { u32 w[20]; } Rec80;

typedef struct { Rec80 data; u32 last; } Rec84;

typedef unsigned int ul;

typedef struct { u32 kind; u16 count,pad; u32 name,total; u16 a,b; } BoxWindowDesc;

typedef struct { unsigned char a,b,c,d;u32 id;} WifibattlematchNetRequest;

typedef struct {char pad[0x104];u32 *ctx;u32 aux;} ObjectView;

typedef struct {char pad[0x48];u32 slots[6];} SlotView;

/* The match-key sub-record at WifiBattleMatchParams.sub (0x34).  CompStepF
 * fills Buf16 from it: keyA (stat 10,0), keyB and the two halves of keyD
 * (keyDBase = stat 10,1, keyDDelta = stat 10,2); GetSetCompStat compares the
 * same three words against the BSUBWAY competition stats. */
struct WifibattlematchNetSub {
    u32 head;       /* 0x00 first word of the record handed to GdbRequest */
    u32 keyB;       /* 0x04 match key id 5 */
    u32 keyDBase;   /* 0x08 BSUBWAY stat 10,1, first half of keyD */
    u32 keyDDelta;  /* 0x0C BSUBWAY stat 10,2, second half of keyD */
    u32 keyA;       /* 0x10 BSUBWAY stat 10,0, match key id 3 */
    u32 recSeed;    /* 0x14 seed stored into *recLast */
};

/* The match-parameters object handed to both WIFIBATTLEMATCH_NET_TaskCreate
 * (stored at task+0x40) and WIFIBATTLEMATCH_NET_CompCreate (stored at
 * comp+0x104).  Its caller is WIFIBATTLEMATCH_SYS_BuildMatchCommand
 * (0x02212854, src/game/ov199/wifibattlematch_sys.c), the buildFn of the
 * ov175 step-table entry; it allocates the object with
 * GFL_HEAP_Alloc(heap, 0x44, 0, d_02213D04, tag), MI_CpuFill8(p, 0, 0x44), and
 * fills p[0]..p[16] (17 words, offsets 0x00..0x40).  The size is 0x44 bytes.
 * The offsets below are the union of every view that reads it. */
struct WifiBattleMatchParams {
    int mode;                   /* 0x00 0 = rating match, 1 = free match */
    int netState;               /* 0x04 net sub-state, 3 on cleanup */
    struct WifiBattleMatchSysHead *save; /* 0x08 points at the game data slot of the ov199 work (work + 4) */
    int state;                  /* 0x0C step state (TaskStepA switch) */
    void *bsubwaySave;          /* 0x10 BSUBWAY stat rows for BSUBWAY_SAVEDATA_GetStat */
    u8 *profile;                /* 0x14 profile/save record */
    u8 *record;                 /* 0x18 second record block, byte-addressed */
    char *heap;                 /* 0x1C http source string for CreateNetContext */
    u32 *statPtr;               /* 0x20 points at a stat word */
    Rec80 *recData;      /* 0x24 first half of the result record */
    u32 *recLast;               /* 0x28 second half of the result record */
    struct WifiBattleMatchSaveBlock *saveBlock; /* 0x2C save/regulation block */
    struct WifiBattleMatchSession *session; /* 0x30 session/peer object (byte at +5) */
    struct WifibattlematchNetSub *sub;            /* 0x34 */
    int *statRecord;            /* 0x38 record read by GetSetBsubwayStat */
    struct WifiBattleMatchReportBlock *profileId; /* 0x3C report block handed to CreateNetContext */
    u32 *resultPtr;             /* 0x40 */
};

/* INV-C: the allocation site fixes the size at 0x44 bytes. */
typedef char WifiBattleMatchParams_size_check[(sizeof(struct WifiBattleMatchParams) == 0x44) ? 1 : -1];

/* The stat record reached through WifiBattleMatchParams.profile (0x14) and
 * .record (0x18).  The first 0x20 bytes are a MyStatus copy (MYSTATUS_Copy in
 * CopyCompSave), so 0x18..0x1D carry the MyStatus language/version/gender/
 * avatar/outfit bytes.  The named tail fields are the ones this file fills and
 * compares.  CopyCompBox zeroes 0xD4 bytes and appends the party data. */
struct WifiBattleMatchStatRecord {
    unsigned char pad_00[0x18];  /* 0x00 MyStatus name and id */
    unsigned char language;      /* 0x18 MyStatus language */
    unsigned char version;       /* 0x19 MyStatus version */
    unsigned char gender;        /* 0x1A MyStatus gender */
    unsigned char avatarId;      /* 0x1B MyStatus avatar id */
    unsigned char outfit;        /* 0x1C MyStatus outfit (clamped below 16) */
    unsigned char outfitVariant; /* 0x1D MyStatus outfit variant (0 or 1) */
    unsigned char pad_1E[0xA];   /* 0x1E..0x27 */
    unsigned int keyDBase;       /* 0x28 copy of Sub.keyDBase (Save.blk[2]) */
    unsigned int keyDDelta;      /* 0x2C copy of Sub.keyDDelta (Save.blk[3]) */
    unsigned char pad_30[4];     /* 0x30 */
    unsigned int keyA;           /* 0x34 copy of Sub.keyA (Save.blk[4]) */
    unsigned char quadRecord[8]; /* 0x38 MISC_SAVEDATA quad record / PMSI sentence */
    unsigned int cardValue;      /* 0x40 REGULATION_Card_GetValue(card, 2) */
    unsigned int boxValue;       /* 0x44 100 written by CopyCompBox */
    unsigned int gsProfileId;    /* 0x48 WIFILIST_GetGsProfileId */
    unsigned int netId;          /* 0x4C WIFIBATTLEMATCH_NET_GetNetId */
    unsigned int crc;            /* 0x50 REGULATION_Card_CalcCrc */
};

/* The save/regulation block reached through WifiBattleMatchParams.saveBlock
 * (0x2C).  Handed to SetupMatchReport as a word array and to SetSaveState. */
struct WifiBattleMatchSaveBlock {
    u32 head;                    /* 0x00 first word, the battle kind handed to IncBsubwayStat */
    unsigned char pad_04[0x10];  /* 0x04..0x13 */
    unsigned int reportState;    /* 0x14 written by GetReportState */
};

/* Head of the ov199 match work, reached through WifiBattleMatchParams.save (work + 4). */
struct WifiBattleMatchSysHead {
    struct GameData *gameData;   /* 0x00 */
    int battleType;              /* 0x04 */
    int commMode;                /* 0x08 */
};

/* The session/peer object reached through WifiBattleMatchParams.session
 * (0x30); only its state byte at +5 is touched here. */
struct WifiBattleMatchSession {
    unsigned char pad_00[4];     /* 0x00..0x03 */
    unsigned char flag4;         /* 0x04 */
    unsigned char subState;      /* 0x05 session sub-state */
    unsigned char flag6;         /* 0x06 */
    unsigned char pad_07;        /* 0x07 */
};

/* One 0x68-byte player record of the DWC report block reached through
 * WifiBattleMatchNetCtx.netIdPtr (0x1464).  SubmitReport receives record 0
 * (netIdPtr+4) as ctx and record 1 (netIdPtr+0x6c) as other.  The fields are
 * the arguments of DWC_ScReportSetPlayerData (dwc_sc.c): report handle,
 * login certificate, connection id block and auth hash. */
struct WifiBattleMatchReportPlayer {
    void *certificate;           /* 0x00 GSLoginCertificate (DWC_ScGetLoginCertificate) */
    struct SCIReport *report;    /* 0x04 SCIReport handle (DWC_ScCreateReport) */
    unsigned char pad_08[0x28];  /* 0x08..0x2F */
    unsigned char connectionId[0x28]; /* 0x30 player connection id block */
    unsigned char authHash[0x10];     /* 0x58..0x67 player auth hash */
};

/* The three-word team record at WifiBattleMatchNetCtx + 0x180, handed to
 * SubmitReport as its peer argument. */
struct WifiBattleMatchTeam {
    unsigned int arg;            /* 0x00 */
    unsigned int rec0;           /* 0x04 */
    unsigned int rec4;           /* 0x08 */
};

/* The DWC report block reached through WifiBattleMatchNetCtx.netIdPtr
 * (0x1464): a header word followed by two 0x68-byte player records. */
struct WifiBattleMatchReportBlock {
    unsigned int head;                                 /* 0x00 */
    struct WifiBattleMatchReportPlayer players[2];     /* 0x04, 0x6C */
};

struct Buf16 {
    u32 keyA;   /* 0x00 */
    u32 keyB;   /* 0x04 */
    u32 keyC;   /* 0x08 */
    u32 keyD;   /* 0x0C */
};

#include "../sdk_rtc.h"

struct Profile {
    u8 name[0x94];
    u32 date1;         /* 0x94 card values 4,5,6 packed */
    u32 date2;         /* 0x98 card values 7,8,9 packed */
    u32 statusFlag;    /* 0x9C MYSTATUS_GetTrainerView */
    u16 hA0;           /* 0xA0 BSUBWAY stat 10,0 (default 1500) */
    u16 hA2;           /* 0xA2 */
    u32 uA4;           /* 0xA4 stat 10,1 + stat 10,2 */
    u16 hA8;           /* 0xA8 */
    u16 hAA;           /* 0xAA REGULATION_Card_GetValue(card, 11) */
};

typedef struct WifiBattleMatchViewPartyWork Work;

#include "../ov177/wifibattlematch_menu_types.h"

typedef enum { RES_NONE, RES_1, RES_2, RES_3, RES_4 } WifibattlematchNetRes;

typedef int (*EvalFn)(int index, void *param);

struct MatchKey {
    int  value;
    u8   id;
    u8   pad_05;
    char name[3];
    u8   term;
    u8   pad_0a[2];
};

typedef int (*ReportFn)(u32 *ctx);

typedef int (*RoundFn)(struct WifiBattleMatchReportPlayer *ctx, const u32 *peer, int dir, int flag);

typedef void (*StepFn)(void);

#include "../ov175/sake_types.h"
typedef void (*RecordsFn)(int count, SAKEField **recs, void *a, int nfields);

struct WifibattlematchNetRecord {u32 words[21];};


typedef struct {u32 a,b;} WifibattlematchNetPair;

typedef struct { char pad[0x1220]; u32 a,b; } WifibattlematchNetObj;

typedef struct { u32 a, b; } W;

struct WifiBattleMatchCompWork {
    struct WifibattlematchGraphic *sprite;               /* 0x00 */
    struct WifiBattleMatchViewAnimState *anim;          /* 0x04 */
    struct GfFont *font;          /* 0x08 */
    struct GfFont *fontAlt;                /* 0x0C */
    struct PrintQueue *printQue;      /* 0x10 */
    struct MsgBank *msgBank;       /* 0x14 */
    struct WordSet *wordSet;       /* 0x18 */
    struct WifibattlematchViewWork *tradeIcon;     /* 0x1C */
    struct WifiBattleMatchViewRecordWork *regCard;       /* 0x20 */
    struct WifiBattleMatchViewPartyWork *window;               /* 0x24 */
    void **animMgr;       /* 0x28 */
    struct WifibattlematchUtilWork *textObj;       /* 0x2C */
    struct WifibattlematchMenu *compSprite;    /* 0x30 */
    struct WifiBattleMatchNetCtx *net;                  /* 0x34 */
    struct WifibattlematchCallback *proc2;         /* 0x38 */
    struct WifibattlematchCallback *waitStream;    /* 0x3C */
    unsigned int waitResult;    /* 0x40 */
    unsigned char responseFlag; /* 0x44 */
    unsigned char pad_45[3];    /* 0x45 */
    unsigned char pad_48[0x98]; /* 0x48..0xDF nothing reads it here */
    unsigned int timer;         /* 0xE0 */
    unsigned int regFlag;       /* 0xE4 */
    unsigned int timeout;       /* 0xE8 */
    unsigned int stepCounter;   /* 0xEC */
    unsigned int rapFlag;       /* 0xF0 */
    unsigned int reportState;   /* 0xF4 */
    unsigned int reportResult;  /* 0xF8 */
    struct Party *party;         /* 0xFC */
    unsigned int gdbFlag;       /* 0x100 */
    struct WifiBattleMatchParams *ctx; /* 0x104 */
    struct RegulationCard *card;          /* 0x108 */
    unsigned char cardRecord[0x160]; /* 0x10C..0x26B downloaded regulation card record */
    int boxLocked;              /* 0x26C BATTLE_BOX_IsLocked result */
};

/* WIFIBATTLEMATCH_NET_CompCreate allocates 0x270 bytes. */
typedef char WifiBattleMatchComp_size_check[
    (sizeof(struct WifiBattleMatchCompWork) == 0x270) ? 1 : -1];

/* The 0x100-byte net task work object created by
 * WIFIBATTLEMATCH_NET_TaskCreate (PROCSYS_AllocProcWork(sys, 0x100, 87)).
 * It holds the graphics, fonts, the net context and the task's own state. */
struct WifiBattleMatchNetTask {
    struct WifibattlematchGraphic *graphic;              /* 0x00 */
    struct WifiBattleMatchViewAnimState *view;                 /* 0x04 */
    struct GfFont *font;                 /* 0x08 */
    struct PrintQueue *printQue;             /* 0x0C */
    struct MsgBank *msgBank;       /* 0x10 message bank handle */
    struct WordSet *wordSet;              /* 0x14 */
    struct WifibattlematchViewWork *boxWindow;     /* 0x18 main window handle released by DeleteBoxRecord */
    struct WifiBattleMatchViewRecordWork *recordWindow;  /* 0x1C record window handle released by DeleteRegCard */
    void **actorArray;           /* 0x20 */
    struct WifibattlematchUtilWork *util;                 /* 0x24 */
    struct WifibattlematchMenu *menu;          /* 0x28 menu handle released by DeleteSprite */
    int menuMode;               /* 0x2C mode of the open choice menu */
    struct WifiBattleMatchNetCtx *net;                  /* 0x30 the net context */
    struct WifibattlematchCallback *callbackA;            /* 0x34 */
    struct WifibattlematchCallback *waitStream;    /* 0x38 callback stream handle for GetWaitResult */
    unsigned int waitResult;    /* 0x3C */
    struct WifiBattleMatchParams *ctx;                  /* 0x40 the match-parameters object */
    unsigned char postFlag;     /* 0x44 first byte of the HTTP post buffer */
    unsigned char postData[0x9B]; /* 0x45..0xDF */
    unsigned int postTimer;     /* 0xE0 frame counter (TIMER macro) */
    unsigned int cancelStep;    /* 0xE4 step of the cancel sequence */
    unsigned int timeout;       /* 0xE8 timeout counter (TIMEOUT macro) */
    unsigned int pad_EC;        /* 0xEC nothing reads it here */
    int statValue;              /* 0xF0 BSUBWAY stat read by GetSetBsubwayStat */
    unsigned int reportResult;  /* 0xF4 WIFIBATTLEMATCH_NET_ScProcess output */
    unsigned int reportFlag;    /* 0xF8 set once a report result was taken */
    unsigned int processState;  /* 0xFC WIFIBATTLEMATCH_NET_ScProcess return */
};

/* WIFIBATTLEMATCH_NET_TaskCreate allocates 0x100 bytes. */
typedef char WifiBattleMatchNetTask_size_check[
    (sizeof(struct WifiBattleMatchNetTask) == 0x100) ? 1 : -1];

/* One 0x10-byte entry of the storage-server description buffer at
 * WifiBattleMatchNetCtx.recBuf (offset 0x190). */
struct GdbUploadEntry {
    const char *name;           /* 0x00 */
    unsigned int type;          /* 0x04 */
    unsigned int value;         /* 0x08 */
    unsigned int size;          /* 0x0C */
};

/* The 0x5c-byte registration data block filled by
 * WIFIBATTLEMATCH_NET_GdbCopyFieldsA; the words hold the GDB fields that
 * WIFIBATTLEMATCH_NET_LookupFieldEntry names. */
struct RegDataA {
    unsigned int regField20;    /* 0x00 */
    unsigned int regField21;    /* 0x04 */
    unsigned int regField23;    /* 0x08 */
    unsigned int regField19;    /* 0x0C */
    unsigned int regField22;    /* 0x10 */
    unsigned int pad_14;        /* 0x14 */
    unsigned int regField24;    /* 0x18 */
    unsigned int pad_1C;        /* 0x1C */
    unsigned int regField3;     /* 0x20 */
    unsigned int regField11;    /* 0x24 */
    unsigned int regField12;    /* 0x28 */
    unsigned int regField14;    /* 0x2C */
    unsigned int regField13;    /* 0x30 */
    unsigned int regField18;    /* 0x34 */
    unsigned int regField17;    /* 0x38 */
    unsigned int regField10;    /* 0x3C */
    unsigned int regField9;     /* 0x40 */
    unsigned int regField16;    /* 0x44 */
    unsigned int regField15;    /* 0x48 */
    unsigned int regExtraA;     /* 0x4C */
    unsigned int regExtraB;     /* 0x50 */
    unsigned int regExtraC;     /* 0x54 */
    unsigned int regExtraD;     /* 0x58 */
};

/* The 0x18-byte sibling block filled by WIFIBATTLEMATCH_NET_GdbCopyFieldsB. */
struct RegDataB {
    unsigned int regField39;    /* 0x00 */
    unsigned int regField40;    /* 0x04 */
    unsigned int regField37;    /* 0x08 */
    unsigned int regField38;    /* 0x0C */
    unsigned int regField36;    /* 0x10 */
    unsigned int regField35;    /* 0x14 */
};

/* One 0x10-byte record field, as read back by
 * WIFIBATTLEMATCH_NET_GdbCopyFieldC. */
struct RegField {
    const char *name;           /* 0x00 */
    unsigned int pad_04;        /* 0x04 */
    unsigned int value;         /* 0x08 */
};

/* The error/result record at WifiBattleMatchNetCtx.err (offset 0x18).  The
 * WIFIBATTLEMATCH_NET_SetError/SetResult setters are handed the address of
 * this record (context + 0x18). */
struct NetErrRecord {
    unsigned int errValue;      /* 0x00 */
    unsigned int resultA;       /* 0x04 */
    unsigned int resultB;       /* 0x08 */
    unsigned int resultC;       /* 0x0C */
    unsigned int pad_10;        /* 0x10 */
    unsigned int resultD;       /* 0x14 */
    unsigned int errCode;       /* 0x18 */
    int errKind;                /* 0x1C */
};

/* The 0x149c matchmaking and storage-server context created by
 * WIFIBATTLEMATCH_NET_CreateNetContext. */
struct WifiBattleMatchNetCtx {
    struct WifiList *scId;           /* 0x000 WIFILIST_GetWork() */
    struct WifiList *gsProfileId;    /* 0x004 GAME_DATA_GetWifiList(save) */
    struct GameData *save;           /* 0x008 */
    unsigned int statusBuf;          /* 0x00C MYSTATUS_GetProfileId(GAME_DATA_GetMyStatus(save)) */
    char *heap;                      /* 0x010 http source string */
    unsigned int syncRange;          /* 0x014 */
    struct NetErrRecord err;         /* 0x018..0x037 */
    unsigned char dateTime[8];       /* 0x038 WIFIBATTLEMATCH_NET_GetDateTime output */
    unsigned int mmState;            /* 0x040 */
    char filter[0x80];               /* 0x044..0x0C3 matchmaking filter string */
    struct MatchKey matchKeys[8];    /* 0x0C4..0x123 */
    unsigned short heapTag;          /* 0x124 */
    unsigned char pad_126[2];        /* 0x126..0x127 */
    int gdbState;                    /* 0x128 */
    unsigned int state;              /* 0x12C */
    unsigned int nextState;          /* 0x130 */
    unsigned int pendingCount;       /* 0x134 */
    unsigned int recvPlayerData;     /* 0x138 */
    int regDataReady;                /* 0x13C */
    unsigned int sessionResult;      /* 0x140 */
    unsigned int regBufferReady;     /* 0x144 */
    unsigned int regFlagReady;       /* 0x148 */
    unsigned int regValueReady;      /* 0x14C */
    unsigned int regValue;           /* 0x150 */
    unsigned int shutdownState;      /* 0x154 */
    void *reportFn;                  /* 0x158 */
    int reportResult;                /* 0x15C */
    unsigned int reportSlot;         /* 0x160 */
    unsigned int reportFieldA;       /* 0x164 */
    unsigned int reportFieldB;       /* 0x168 */
    unsigned int reportFieldC;       /* 0x16C */
    unsigned int reportState;        /* 0x170 */
    unsigned int postMonCount;       /* 0x174 */
    void *gdbArg;                    /* 0x178 */
    RecordsFn gdbStep;               /* 0x17C */
    unsigned int teamArg;            /* 0x180 */
    unsigned int teamRec0;           /* 0x184 */
    unsigned int teamRec4;           /* 0x188 */
    unsigned int takenRegValue;      /* 0x18C WIFIBATTLEMATCH_NET_TakeRegValue output */
    SAKEField *recBuf;               /* 0x190 0x260-byte field description buffer */
    void *gdbName;                   /* 0x194 */
    int fieldCount;                  /* 0x198 */
    unsigned int initWord;           /* 0x19C written 0x573 by CreateNetContext, no reader */
    unsigned int pollCount;          /* 0x1A0 */
    unsigned int retryCount;         /* 0x1A4 */
    unsigned int reportCount;        /* 0x1A8 */
    int reportKind;                  /* 0x1AC */
    int gdbTarget;                   /* 0x1B0 */
    unsigned char pad_1B4[0x10];     /* 0x1B4..0x1C3 */
    struct WifibattlematchNetRecord uploadRecord; /* 0x1C4 record copy for the GDB upload, its last word (0x214) is the upload kind */
    unsigned char regData[0x1000];   /* 0x218..0x1217 regulation payload */
    DWCEvalCallback evalFn;          /* 0x1218 */
    struct _NHTTPRapSession *rapHandle; /* 0x121C */
    WifibattlematchNetPair rapPair;                    /* 0x1220 matchmaking pair read by GetRapPair */
    W postData;                      /* 0x1228 HTTP post payload posted by HttpRapSend */
    unsigned char regulationCard[0x160]; /* 0x1230..0x138F */
    unsigned char fileList[0xB0];    /* 0x1390..0x143F */
    unsigned int downloadPercent;    /* 0x1440 */
    unsigned int downloadDone;       /* 0x1444 */
    unsigned int downloadTotal;      /* 0x1448 */
    unsigned char ndAttr[0xC];       /* 0x144C..0x1457 */
    int downloadActive;              /* 0x1458 */
    unsigned char pad_145C[8];       /* 0x145C..0x1463 */
    struct WifiBattleMatchReportBlock *netIdPtr; /* 0x1464 */
    unsigned char profanityText[0x18]; /* 0x1468..0x147F 12-character profanity string */
    void *profanityWords;            /* 0x1480 */
    unsigned int profanityResult;    /* 0x1484 DWC_CheckProfanityExAsync result */
    int profanityCount;              /* 0x1488 */
    unsigned short profanityTag;     /* 0x148C */
    unsigned char pad_148E[2];       /* 0x148E..0x148F */
    void *profanityWindow;           /* 0x1490 */
    unsigned int reportFlag;         /* 0x1494 */
    unsigned char pad_1498[4];       /* 0x1498..0x149B, to the 0x149c alloc */
};

#endif
