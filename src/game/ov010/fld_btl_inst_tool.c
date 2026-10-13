/*
 * file:     fld_btl_inst_tool.c
 * unit:     yes
 * function: func_02167EF4, func_02167FB4, func_021680C8, func_02168174, func_021681C8, func_021684E8, func_0216869C, func_02168800, func_0216880C, func_02168824, func_0216883C, func_02168878, func_021688BC, func_02168924, func_02168AC8, func_02168AEC, func_02168B18, func_02168B20, func_02168BBC, func_02168BF0, func_02168C74, func_02168CF4, func_02168D30, func_02168E5C, func_02168EB0, func_02168EEC, func_02168F54, func_02169004, func_02169068, func_021690A4, func_021690B4, func_021690D0, func_021690E0, func_021690F0, func_02169100, func_02169110, func_02169120, func_02169138
 * address:  0x02167EF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from comm_player.c at 0x02167EF4: fld_btl_inst_tool.c __FILE__ anchor at 0x021681C8.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944 0x02012944 thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02039338  0x02039338  arm
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201A364 0x0201A364 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02188C54  0x02188C54  thumb ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0219129C  0x0219129C  thumb ov021
 *   func_02191388  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb
 *   func_021912F8  0x021912F8  thumb
 *   func_02045808  0x02045808  arm
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013644  0x02013644  thumb
 *   func_02013734  0x02013734  thumb
 *   BTL_SETUP_SetupCommAiMulti  0x02013810  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173EC  0x020173EC  thumb
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_02045924  0x02045924  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   BTL_SETUP_ChangeToSubway  0x0201394C  thumb
 *   d_02172A2C     0x02172A2C  data
 *   func_020186C8  0x020186C8  thumb
 *   func_02019C90  0x02019C90  thumb
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   d_02172084     0x02172084  data
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   POKE_TOOL_SetNature  0x020185B0  thumb
 *   func_02045A98  0x02045A98  arm
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   g_0217208C  0x0217208C  data  ov010  a2
 *   g_0217208E  0x0217208E  data  ov010  a2
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag  0x02012158  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_021A0F7C  0x021A0F7C  thumb ov021
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0216E910 0x0216E910 thumb ov010
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_02012444 0x02012444 thumb
 *   d_021BA39C 0x021BA39C data ov220 a4
 *   ov220_id 0x000000DC data
 *   func_02008B14  0x02008B14  thumb
 *   func_0203F49C  0x0203F49C  arm
 *   func_02008BE0  0x02008BE0  thumb
 *   func_02089004  0x02089004  arm
 *   func_02088F58  0x02088F58  arm
 *   func_0201296C  0x0201296C  thumb
 *   ZONEDATA_ClearTimeFlags  0x020143F0  thumb
 *   func_0200D440  0x0200D440  thumb
 *   POKERUS_DecreaseDays  0x0201B100  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008E30  0x02008E30  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200952C  0x0200952C  thumb
 *   func_021862A8  0x021862A8  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E518  0x0200E518  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200AB04  0x0200AB04  thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3C0 0x0200C3C0 thumb
 *   TIMEZONE_GetTimeZoneOfHour  0x020113F0  thumb
 *   func_0203F524 0x0203F524 arm
 *   func_02008BD0  0x02008BD0  thumb
 *   func_0216A2EC  0x0216A2EC  thumb  ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
typedef int fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/* Opaque types owned by other files. */
typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct FieldMap FieldMap;
typedef struct SaveControl SaveControl;
typedef struct GameEvent GameEvent;
typedef struct GameComm GameComm;
typedef struct MyStatus MyStatus;
typedef struct ZukanSave ZukanSave;
typedef struct Strbuf Strbuf;
typedef struct MsgData MsgData;
typedef struct PokemonParam PokemonParam;
typedef struct Party Party;
typedef struct FldMmdl FldMmdl;
typedef struct FldMmdlSys FldMmdlSys;
typedef struct FldMsgBalloon FldMsgBalloon;
typedef struct FldMsgBalloonSys FldMsgBalloonSys;
typedef struct NetHandle NetHandle;
typedef struct TrialHouseSave TrialHouseSave;
typedef struct PartySave PartySave;
typedef struct Regulation Regulation;

typedef int (*GameEventFunc)(GameEvent *event, u32 *seq, void *work);

/* Two PMS sentences back to back (see PmsData in mail.c: type, id, two words each). */
typedef struct PmsSentencePair {
    u16 half[8];
} PmsSentencePair;

typedef struct PmsData {
    u16 sentenceType;   /* 0x00 */
    u16 sentenceId;     /* 0x02 */
    u16 word[2];        /* 0x04 */
} PmsData;

/* ---- Party select event (poke list, then status screen, with field close/open around it) ---- */

/* Status screen parameter (0x28 bytes); same record as in event_poke_status.c. */
typedef struct PStatusParam {
    Party *ppd;             /* 0x00 */
    u8 reserved04[4];
    GameData *config;       /* 0x08 */
    u8 ppt;                 /* 0x0C */
    u8 mode;                /* 0x0D */
    u8 max;                 /* 0x0E */
    u8 pos;                 /* 0x0F */
    u8 page;                /* 0x10 */
    u8 reserved11[7];
    u32 isNationalDex;      /* 0x18 */
    u8 reserved1C[0xC];
} PStatusParam;

#include "field_event_types.h"

typedef struct PartySelectEventWork {
    GameSystem *gameSystem;     /* 0x000 */
    FieldMap *fieldMap;         /* 0x004 */
    PStatusParam statusParam;   /* 0x008 */
    PokeListParam listParam;    /* 0x030 */
    u8 regulationData[0xBC];    /* 0x0C8 */
    u32 *resultCommand;         /* 0x184: gets listParam.command */
    u32 *resultSlot;            /* 0x188: gets listParam.selectedSlot */
    u8 *resultOrder;            /* 0x18C: gets listParam.selectOrder */
    Party *sourceParty;         /* 0x190 */
    Party *resultParty;         /* 0x194: receives the chosen members */
} PartySelectEventWork;

/* ---- Trainer pre-battle message balloon event ---- */

typedef struct TrainerMsgEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    VecFx32 trainerPos;         /* 0x04 */
    FldMsgBalloon *balloon;     /* 0x10 */
    Strbuf *message;            /* 0x14 */
    u8 reserved18[4];
} TrainerMsgEventWork;

/* ---- Battle facility trainer data ---- */

typedef struct BattleMon {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    union {
        u32 ivs;        /* 0x14 */
        struct {
            u32 hpIv : 5;
            u32 atkIv : 5;
            u32 defIv : 5;
            u32 speIv : 5;
            u32 spaIv : 5;
            u32 spdIv : 5;
            u32 ivRest : 2;
        } b;
    } iv;
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 ability;         /* 0x20 */
    u8 friendship;      /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 nature;          /* 0x38 */
} BattleMon;

/* One 16-byte record of archive a/2/1/4. */
typedef struct BtlInstMonData {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} BtlInstMonData;

/* One group list of archive a/2/1/5. */
typedef struct BtlInstGroup {
    u16 trainerType;    /* 0x00 */
    u16 count;          /* 0x02 */
    u16 memberIds[1];   /* 0x04 */
} BtlInstGroup;

/* The first two draws, kept to build the matching record later. */
typedef struct BtlInstDraw {
    u32 otId;           /* 0x00 */
    u16 ids[2];         /* 0x04 */
    u32 pids[2];        /* 0x08 */
    u8 natures[2];      /* 0x10 */
} BtlInstDraw;

/* One facility trainer with the four Pokemon (0x120 bytes). */
typedef struct BtlInstTrainer {
    u32 trainerId;              /* 0x00 */
    u16 trainerType;            /* 0x04 */
    u8 reserved06[2];
    u16 name[8];                /* 0x08 */
    PmsData introMsg;           /* 0x18: type 0xFFFF = take the text from message bank 0xB8 at id */
    PmsSentencePair battleMsgs; /* 0x20 */
    BattleMon mons[4];          /* 0x30 */
} BtlInstTrainer;

/* Battle request of the facility (0x130 bytes). */
typedef enum { BTL_INST_REQUEST_MODE_OFFSET = 0x12c } BtlInstRequestOffset;

typedef struct BtlInstBattleRequest {
    u8 trainerData[0x124];      /* BtlInstTrainer, see review.tsv */
    int monCount;               /* 0x124 */
    Party *playerParty;         /* 0x128 */
    BtlInstRequestOffset mode;  /* 0x12C */
} BtlInstBattleRequest;

/* ---- Battle setup built for the facility ---- */

typedef struct BtlFieldSituation {
    u32 bgGround;       /* 0x00 */
    u32 bgAttr;         /* 0x04 */
    u8 weather;         /* 0x08 */
    u8 season;          /* 0x09 */
    u16 zoneId;         /* 0x0A */
    u8 timeZone;        /* 0x0C */
    u8 reserved0D[3];
} BtlFieldSituation;

typedef struct BtlTrainerData {
    u32 trainerId;              /* 0x00 */
    u32 trainerType;            /* 0x04 */
    u32 aiBits;                 /* 0x08 */
    u8 reserved0C[8];
    Strbuf *name;               /* 0x14 */
    PmsSentencePair battleMsgs; /* 0x18 */
} BtlTrainerData;

typedef struct BtlSetup {
    u8 reserved00[0x22];
    u8 battleRule;              /* 0x22: 0 single, 3 multi */
    u8 reserved23;
    Party *parties[4];          /* 0x24 */
    MyStatus *myStatus[4];      /* 0x34 */
    u8 reserved44[4];
    BtlTrainerData *trainers[4];/* 0x48 */
} BtlSetup;

typedef enum {
    BTL_CLIENT_PLAYER,
    BTL_CLIENT_ENEMY1,
    BTL_CLIENT_PARTNER,
    BTL_CLIENT_ENEMY2
} BtlClient;

/* ---- Party select wrapper event ---- */

typedef struct PartySelectStepWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    u8 reserved08[4];
    u16 *resultOk;              /* 0x0C: set to 1 when the player confirmed a party */
    u32 listArg;                /* 0x10 */
    u32 regulationId;           /* 0x14 */
    Party *party;               /* 0x18 */
    Party *tempParty;           /* 0x1C: freed when done, may be 0 */
    u32 resultSlot;             /* 0x20 */
    u32 resultCommand;          /* 0x24 */
    u8 selectOrder[8];          /* 0x28 */
    BtlInstBattleRequest *request; /* 0x30 */
} PartySelectStepWork;

/* ---- Tally record ---- */

typedef struct BtlInstRecord {
    u8 reserved000[0x134];
    u16 tally[10];              /* 0x134 */
    u16 scoreShare;             /* 0x148 */
    u16 lastTally;              /* 0x14A */
} BtlInstRecord;

typedef struct BtlInstResult {
    u8 reserved00[0x24];
    Party *party;               /* 0x24 */
    u8 reserved28[0xB4 - 0x28];
    u16 score;                  /* 0xB4 */
    u8 tally[11];               /* 0xB6 */
} BtlInstResult;

/* ---- Comm reset event ---- */

typedef struct CommResetWork {
    int done;                   /* 0x00: set by the callback */
    int restoreAutoComm;        /* 0x04 */
    GameSystem *gameSystem;     /* 0x08 */
} CommResetWork;

typedef enum {
    COMM_RESET_REQUEST_EXIT,
    COMM_RESET_WAIT_EXIT,
    COMM_RESET_RESTORE_AUTO_COMM,
    COMM_RESET_REQUEST_FIELD_RESET,
    COMM_RESET_WAIT_DONE,
    COMM_RESET_END
} CommResetStep;

/* ---- Trial house award event ---- */

typedef struct TrialHouseAwardParam {
    u8 playerSex;               /* 0x00 */
    u8 reserved01[3];
    TrialHouseSave *trialHouse; /* 0x04 */
    int arg0;                   /* 0x08 */
    int arg1;                   /* 0x0C */
} TrialHouseAwardParam;

typedef struct TrialHouseAwardEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    TrialHouseAwardParam param; /* 0x08 */
} TrialHouseAwardEventWork;

/* ---- Field clock ---- */

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

/* Clock checkpoint kept in the save (reached through the save control). */
typedef struct FieldClock {
    int valid;                  /* 0x00 */
    RTCDate date;               /* 0x04 */
    RTCTime time;               /* 0x14 */
    int dayNumber;              /* 0x20 */
    u8 reserved24[8];
    u8 timestamp[8];            /* 0x2C: u64 stored unaligned */
} FieldClock;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern PokemonParam *func_02030734(u32 heapKind, u32 size, int unused, const char *file, u16 line);
extern void func_020307B0(void *p);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern void func_02082BCC(void *p, int v, int n);
extern GameData *func_020120F4(GameSystem *gameSystem);
extern MyStatus *func_02012944(GameData *gameData);
extern NetHandle *func_020399A8(void);
extern u8 func_02008550(const MyStatus *myStatus);
extern PokemonParam *func_0201AB28(Party *party, u32 pos);
extern u32 func_02017E1C(PokemonParam *mon, u32 id, u32 v);
extern u16 func_02039338(void);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, GameEventFunc main, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void func_0201A364(int regulationId, Regulation *dest);
extern ZukanSave *func_0200CA1C(GameData *gameData);
extern u32 func_0201AA18(Party *party);
extern u32 func_0200CA38(ZukanSave *zukan);
extern GameEvent *func_021BE8D4(GameSystem *gameSystem, FieldMap *fieldMap, int a, int b);
extern void func_02012374(GameEvent *event, GameEvent *child);
extern GameEvent *FIELD_STATUS_CreateFieldCloseEvent(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *func_02014910(GameSystem *gameSystem, FieldMap *fieldMap, PokeListParam *listParam, PStatusParam *statusParam);
extern GameEvent *FIELD_STATUS_CreateFieldOpenEvent(GameSystem *gameSystem);
extern GameEvent *func_021BE92C(GameSystem *gameSystem, FieldMap *fieldMap, int a, int b, int c, u8 d, u8 e);
extern u32 func_0201AA14(Party *party);
extern u32 func_0201A98C(Party *party, const PokemonParam *mon);
extern FldMsgBalloonSys *func_02188C54(FieldMap *fieldMap);
extern Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(MsgData *msgData, u32 index, Strbuf *dest);
extern void func_02045C04(MsgData *msgData);
extern Strbuf *PMSI_PARAM_ToString(PmsData *pms, unsigned int heapId);
extern FldMmdlSys *func_02012964(GameData *gameData);
extern FldMmdl *func_0216DE94(FldMmdlSys *mmdlSys, u32 id);
extern void func_0216D88C(const FldMmdl *mmdl, VecFx32 *pos);
extern FldMsgBalloon *func_0219129C(FldMsgBalloonSys *sys, int a, VecFx32 *pos, Strbuf *msg, u32 b, u32 c);
extern int func_02191388();
extern u32 func_020362DC(void);
extern int func_021912D8();
extern int func_021912F8();
extern int func_02045808();
extern void func_021AA304(BtlFieldSituation *out, GameData *gameData, FieldMap *fieldMap);
extern BtlSetup *func_02013090(u32 heapId);
extern void func_02013610(BtlSetup *bs, GameData *gameData, BtlFieldSituation *situation, u32 a, u16 heapId);
extern void func_02013644(BtlSetup *bs, GameData *gameData, BtlFieldSituation *situation, u32 a, u16 heapId);
extern void func_02013734(BtlSetup *bs, GameData *gameData, BtlFieldSituation *situation, u32 a, u32 b, u32 c, u32 heapId);
extern void BTL_SETUP_SetupCommAiMulti(BtlSetup *bs, GameData *gameData, NetHandle *handle, u32 a, u8 playerPos, u32 b, u32 c, u16 heapId);
extern void BTL_SETUP_AllocRecordBuffer(BtlSetup *bs, u32 heapId);
extern void func_0201A954(Party *party, int capacity);
extern u32 func_020173EC(void);
extern void POKE_TOOL_ClearPartyParam(PokemonParam *mon);
extern void func_02019CE0(const PokemonParam *src, PokemonParam *dest);
extern void func_02019CA0(PokemonParam *mon, u32 level);
extern void func_02045924(Strbuf *dest, const u16 *src);
extern void PMSI_PARAM_ClearSentence(PmsData *pms);
extern void BTL_SETUP_ChangeToSubway(BtlSetup *bs);
extern u32 func_020186C8(u32 otId, int species, int form, int a, int b, int c);
extern u32 func_02019C90(u16 species, u16 form, u32 paramId);
extern MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadUnits(MsgData *msgData, u32 msgIndex, u16 *dest, u32 maxLen);
extern void func_02017588(PokemonParam *mon, u16 species, u16 level, unsigned long long otId, u32 ivs, unsigned long long pid);
extern void func_02017E40(PokemonParam *mon, u32 id, u32 v);
extern void POKE_TOOL_SetNature(PokemonParam *mon, u32 nature);
extern u16 func_02045A98(void);
extern u32 POKE_TOOL_CalcLevel(PokemonParam *mon);
extern void func_02048F4C(void *dest, u32 archiveId, u32 member);
extern void *func_0204A1BC(int archiveId, int member, int flag, int heapId);
extern u32 func_020056EC(u32 range);
extern int func_0209C2B0();
extern Strbuf *func_02045EC0(MsgData *msgData, u32 index);
extern void func_02045A38(Strbuf *strbuf, u16 *dest, u32 maxLen);
extern GameEvent *func_021A0F7C(FieldMap *fieldMap, u32 a, u32 callback, u32 callbackArg);
extern int func_02188CCC(FieldMap *fieldMap);
extern GameComm *func_02012138(GameSystem *gameSystem);
extern u32 func_02026454(GameComm *gameComm);
extern void func_02026400(GameComm *gameComm);
extern void GAMESYSTEM_SetAlwaysNetFlag(GameSystem *gameSystem, unsigned int flag);
extern u32 func_020121CC(GameSystem *gameSystem);
extern Party *func_02012934(GameData *gameData);
extern SaveControl *func_02012EBC(GameData *gameData);
extern void *func_0200BAC8(SaveControl *saveControl);
extern Party *func_0200BAF4(void *a, int b);
extern int func_0216E910(GameSystem *gameSystem, FieldMap *fieldMap, BtlSetup *bs);
extern TrialHouseSave *func_0200E8F8(SaveControl *saveControl);
extern void func_02012444(GameEvent *event, u32 overlayId, u32 procTemplate, void *procParam);
extern FieldClock *func_02008B14(SaveControl *saveControl);
extern void func_0203F49C(RTCDate *date, RTCTime *time);
extern void func_02008BE0(FieldClock *clock, u32 minutes);
extern long long func_02089004(RTCDate *date, RTCTime *time);
extern int func_02088F58(RTCDate *date);
extern u32 func_0201296C(GameData *gameData);
extern void ZONEDATA_ClearTimeFlags(u32 eventWork);
extern void func_0200D440(SaveControl *saveControl);
extern void POKERUS_DecreaseDays(Party *party, int days);
extern void *func_02012F2C(GameData *gameData);
extern void func_02008E30(void *trainerRecord);
extern void *func_02009470(SaveControl *saveControl);
extern void func_0200952C(void *obj);
extern void func_021862A8(GameData *gameData, int days, int a);
extern void *func_0200E394(SaveControl *saveControl);
extern void func_0200E518(void *obj);
extern void *func_0200A8A0(SaveControl *saveControl);
extern void func_0200AB04(void *obj);
extern PartySave *func_0201AD0C(SaveControl *saveControl);
extern u8 func_02012984(GameData *gameData);
extern void *func_0200C0F0(SaveControl *saveControl);
extern void func_0200C3C0(void *obj, u16 v);
extern int TIMEZONE_GetTimeZoneOfHour(int season, int hour);
extern u64 func_0203F524(void);
extern int func_02008BD0(const FieldClock *clock);
int func_0216A2EC(GameData *gameData, PartySave *partySave, int minutes, RTCTime *time, int season);

extern const char d_02172A2C[];
extern const u16 d_02172084[];
extern u16 g_0217208C[];
extern u16 g_0217208E[];
extern const unsigned int d_021BA39C[];
extern unsigned char ov220_id[];

GameEvent *func_02167EF4(GameSystem *gameSystem, int listArg, int listMode, int regulationId, Party *party, u8 *resultOrder, u32 *resultSlot, u32 *resultCommand, Party *resultParty);
int func_02167FB4(GameEvent *event, u32 *seq, PartySelectEventWork *work);
GameEvent *func_021680C8(GameSystem *gameSystem, BtlInstTrainer *trainers, int index, int mmdlId);
int func_02168174(GameEvent *event, int *seq, TrainerMsgEventWork *work);
BtlSetup *func_021681C8(GameSystem *gameSystem, Party *playerParty, u32 battleMode, BtlInstTrainer *trainerA, BtlInstTrainer *trainerB, int monCount);
u32 func_021684E8(BattleMon *out, u32 memberId, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useTableItem, u16 heapId);
void func_0216869C(const BattleMon *src, PokemonParam *mon);
void func_02168800(void *dest, u32 memberId);
void *func_0216880C(u32 group, u32 heapId);
int func_02168824(void);
u8 func_0216883C(u32 rank);
int func_02168878(BtlInstTrainer *trainer, u16 trainerIndex, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId);
BtlInstGroup *func_021688BC(BtlInstTrainer *trainer, int trainerIndex, int heapId);
int func_02168924(BtlInstGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId);
int func_02168AC8(BtlInstTrainer *trainer);
u16 func_02168AEC(u16 key);
void func_02168B18(int *doneFlag);
int func_02168B20(GameEvent *event, int *step, CommResetWork *work);
GameEvent *func_02168BBC(GameSystem *gameSystem, int restoreAutoComm);
GameEvent *func_02168BF0(GameSystem *gameSystem, BtlInstBattleRequest *request, int regulationId, int useTempParty, u16 *resultOk);
int func_02168C74(GameEvent *event, int *step, PartySelectStepWork *work);
GameEvent *func_02168CF4(GameSystem *gameSystem, BtlInstBattleRequest *request);
void func_02168D30(BtlInstRecord *record, BtlInstResult *result);
GameEvent *func_02168E5C(GameSystem *gameSystem, int arg0, int arg1);
int func_02168EB0(GameEvent *event, int *step);
void func_02168EEC(GameData *gameData);
int func_02168F54(FieldClock *clock, RTCDate *date, RTCTime *time, int *outDays, int *outMinutes);
void func_02169004(GameData *gameData, int days);
void func_02169068(GameData *gameData, int minutes, RTCTime *time);
RTCDate *func_021690A4(GameData *gameData);
int func_021690B4(GameData *gameData);
int func_021690D0(GameData *gameData);
int func_021690E0(GameData *gameData);
int func_021690F0(GameData *gameData);
int func_02169100(GameData *gameData);
int func_02169110(GameData *gameData);
void func_02169120(GameData *gameData);
int func_02169138(GameData *gameData);

/*
 * Creates the party select event: a Pokemon list screen followed by the
 * status screen, with the field closed before and opened after. The chosen
 * slot, command and order are copied to the caller's outputs when the
 * event ends.
 *
 * lever: named temporaries keep the list parameter address live across the
 * regulation load; bounded permuter47 compiles found byte-correct192.
 * Interface evidence: ov019_func_0217BA10.c records r0->r2, r1->r0, r1=0x69, jump via02048F4C. Original caller supplies d in r0 and p->buf in r1.
 * TU: MATCH192,9/10 relocations; suggest-split leaves sole function OUT.
 * checks: 1 020124E8 takes live hd from122C0, own matched accessor reads+0xc; 2 family/neighbours reread, no full twin; 3 unsigned b/c each retain31 before search; 4 pointer-copy idiom read; 5 neighbours/idioms reread, frame is scalar spills, no stack aggregate.
 * permuter: once budget300 types, emitted baseline agreed31/192; stopped at47 with MATCH; fixed one confirmsMATCH192.
 */
GameEvent *func_02167EF4(GameSystem *gameSystem, int listArg, int listMode, int regulationId, Party *party, u8 *resultOrder, u32 *resultSlot, u32 *resultCommand, Party *resultParty)
{
    PartySelectEventWork *work;
    PokeListParam *listParam;
    PStatusParam *statusParam;
    GameData *gameData;
    ZukanSave *zukan;
    FieldMap *fieldMap;
    GameEvent *event;
    PokeListParam *listTmp;
    u8 maxCount;

    fieldMap = func_0201210C(gameSystem);
    event = func_020122C0(gameSystem, 0, (GameEventFunc)func_02167FB4, 0x198);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->resultOrder = resultOrder;
    work->resultSlot = resultSlot;
    work->resultCommand = resultCommand;
    work->sourceParty = party;
    listTmp = &work->listParam;
    work->resultParty = resultParty;
    func_0201A364(regulationId, (Regulation *)work->regulationData);
    listParam = listTmp;
    listParam->party = party;
    listParam->regulation = (Regulation *)work->regulationData;
    listParam->listArg = listArg;
    listParam->listMode = listMode;
    statusParam = &work->statusParam;
    gameData = func_020120F4(gameSystem);
    zukan = func_0200CA1C(gameData);
    func_02082BCC(statusParam, 0, 0x28);
    statusParam->ppd = party;
    statusParam->ppt = 1;
    maxCount = func_0201AA18(party);
    statusParam->max = maxCount;
    statusParam->mode = 0;
    statusParam->page = 0;
    statusParam->config = gameData;
    statusParam->isNationalDex = func_0200CA38(zukan);
    return event;
}






/*
 * Sub-process sequence: runs five child processes one after another
 * (two from ov021, three from arm9), copying the result of the fifth
 * back and re-adding the chosen party members.
 *
 * First draft plus one lever (2026-09-28 tree_ov010_4): w->heap read into
 * a local before the switch. The member index is taken before the range
 * fix-up, so a reset slot still passes its old index (the image does not
 * reload it).
 */
int func_02167FB4(GameEvent *event, u32 *seq, PartySelectEventWork *work)
{
    int count;
    int i;
    int slot;
    GameSystem *gameSystem;

    gameSystem = work->gameSystem;
    switch (*seq) {
    case 0:
        func_02012374(event, func_021BE8D4(gameSystem, work->fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, work->fieldMap));
        (*seq)++;
        break;
    case 2:
        func_02012374(event, func_02014910(gameSystem, work->fieldMap, &work->listParam, &work->statusParam));
        (*seq)++;
        break;
    case 3:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_021BE92C(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        MI_CpuCopy8(work->listParam.selectOrder, work->resultOrder, 6);
        *work->resultSlot = work->listParam.selectedSlot;
        *work->resultCommand = work->listParam.command;
        if (*work->resultSlot != 7 && *work->resultSlot != 8 && work->resultParty != 0) {
            count = func_0201AA14(work->resultParty);
            for (i = 0; i < count; i++) {
                slot = work->resultOrder[i] - 1;
                if (slot >= 6)
                    work->resultOrder[i] = 1;
                func_0201A98C(work->resultParty, func_0201AB28(work->sourceParty, slot));
            }
        }
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}






/*
 * Creates the balloon event for a trainer's pre-battle message.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =PMSI_PARAM_ToStringWords; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */
GameEvent *func_021680C8(GameSystem *gameSystem, BtlInstTrainer *trainers, int index, int mmdlId)
{
    GameEvent *event;
    GameData *gameData;
    FldMsgBalloonSys *balloonSys;
    TrainerMsgEventWork *work;

    gameData = func_020120F4(gameSystem);
    balloonSys = func_02188C54(func_0201210C(gameSystem));
    event = func_020122C0(gameSystem, 0, (GameEventFunc)func_02168174, 0x1c);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    if (trainers->introMsg.sentenceType == 0xFFFF) {
        MsgData *msgData;
        work->message = func_020457B0(0x5c, 4);
        msgData = func_02045B38(0, 2, 0xb8, 4);
        func_02045CAC(msgData, trainers->introMsg.sentenceId, work->message);
        func_02045C04(msgData);
    } else {
        work->message = PMSI_PARAM_ToString(&trainers[index].introMsg, 4);
    }
    func_0216D88C(func_0216DE94(func_02012964(gameData), mmdlId), &work->trainerPos);
    work->balloon = func_0219129C(balloonSys, 1, &work->trainerPos, work->message, 0, 0);
    return event;
}






/*
 * Message balloon state machine: wait until the balloon is up, wait for a
 * confirm or cancel press, close the balloon and free the text.
 */
int func_02168174(GameEvent *event, int *seq, TrainerMsgEventWork *work)
{
    switch (*seq) {
    case 0:
        if (func_02191388(work->balloon) == 1)
            (*seq)++;
        break;
    case 1:
        if ((func_020362DC() & 3) != 0) {
            func_021912D8(work->balloon);
            (*seq)++;
        }
        break;
    case 2:
        if (func_021912F8(work->balloon) == 1) {
            func_02045808(work->message);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * Builds the battle-intro sprite set: a func_02013090 object, one party
 * list per side filled from 0x3C-byte records through func_0216869C.
 * Levers: side ids are an enum (an int index folds to a constant offset);
 * the mode truncation is a u16 local copied from a u32 parameter; the
 * mode==4 and func_02168AC8 arms each carry their own copy of the eight
 * halfword stores (the cross-jump leaves the `b` into the second copy);
 * one party local per side block sets the spill slots; the sprite pointer
 * of the third block is read before the record pointer moves.
 */
BtlSetup *func_021681C8(GameSystem *gameSystem, Party *playerParty, u32 battleMode, BtlInstTrainer *trainerA, BtlInstTrainer *trainerB, int monCount)
{
    u16 mode;
    BtlFieldSituation situation;
    BtlSetup *bs;
    GameData *gameData;
    PokemonParam *tempMon;
    Party *party;
    Party *enemy1Party;
    Party *enemy2Party;
    Party *partnerParty;
    BtlTrainerData *trainerData;
    int i;
    BtlClient client;
    int playerPos;
    NetHandle *netHandle;
    PokemonParam *srcMon;
    MyStatus *myStatus;
    BtlInstTrainer *trainerC;

    gameData = func_020120F4(gameSystem);
    mode = battleMode;
    func_021AA304(&situation, gameData, func_0201210C(gameSystem));
    bs = func_02013090(4);
    switch (mode) {
    case 0:
    case 4:
    case 5:
        func_02013610(bs, gameData, &situation, 0, 4);
        break;
    case 1:
    case 6:
        func_02013644(bs, gameData, &situation, 0, 4);
        break;
    case 2:
    case 7:
        func_02013734(bs, gameData, &situation, 0, 0, 0, 4);
        break;
    case 3:
    case 8:
        netHandle = func_020399A8();
        playerPos = 0;
        if (func_02039338() != 0)
            playerPos = 2;
        BTL_SETUP_SetupCommAiMulti(bs, gameData, netHandle, 1, playerPos, 0, 0, 4);
        break;
    }
    BTL_SETUP_AllocRecordBuffer(bs, 4);

    client = BTL_CLIENT_PLAYER;
    i = 0;
    myStatus = func_02012944(gameData);
    bs->myStatus[client] = myStatus;
    party = bs->parties[client];
    func_0201A954(party, 6);
    tempMon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x253);
    POKE_TOOL_ClearPartyParam(tempMon);
    for (; i < monCount; i++) {
        srcMon = func_0201AB28(playerParty, i);
        func_02019CE0(srcMon, tempMon);
        if (func_02017E1C(srcMon, 0x9E, 0) != 0x32)
            func_02019CA0(tempMon, 0x32);
        func_0201A98C(party, tempMon);
    }
    func_020307B0(tempMon);

    client = BTL_CLIENT_ENEMY1;
    trainerData = bs->trainers[client];
    trainerData->trainerId = trainerA->trainerId;
    trainerData->trainerType = trainerA->trainerType;
    trainerData->aiBits = 0x87;
    func_02045924(trainerData->name, trainerA->name);
    PMSI_PARAM_ClearSentence((PmsData *)&trainerData->battleMsgs.half[0]);
    PMSI_PARAM_ClearSentence((PmsData *)&trainerData->battleMsgs.half[4]);
    if (mode == 4) {
        trainerData->battleMsgs.half[0] = trainerA->battleMsgs.half[0];
        trainerData->battleMsgs.half[1] = trainerA->battleMsgs.half[1];
        trainerData->battleMsgs.half[2] = trainerA->battleMsgs.half[2];
        trainerData->battleMsgs.half[3] = trainerA->battleMsgs.half[3];
        trainerData->battleMsgs.half[4] = trainerA->battleMsgs.half[4];
        trainerData->battleMsgs.half[5] = trainerA->battleMsgs.half[5];
        trainerData->battleMsgs.half[6] = trainerA->battleMsgs.half[6];
        trainerData->battleMsgs.half[7] = trainerA->battleMsgs.half[7];
    } else if (func_02168AC8(trainerA) != 0) {
        trainerData->battleMsgs.half[0] = trainerA->battleMsgs.half[0];
        trainerData->battleMsgs.half[1] = trainerA->battleMsgs.half[1];
        trainerData->battleMsgs.half[2] = trainerA->battleMsgs.half[2];
        trainerData->battleMsgs.half[3] = trainerA->battleMsgs.half[3];
        trainerData->battleMsgs.half[4] = trainerA->battleMsgs.half[4];
        trainerData->battleMsgs.half[5] = trainerA->battleMsgs.half[5];
        trainerData->battleMsgs.half[6] = trainerA->battleMsgs.half[6];
        trainerData->battleMsgs.half[7] = trainerA->battleMsgs.half[7];
    }
    enemy1Party = bs->parties[client];
    func_0201A954(enemy1Party, 6);
    tempMon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x29E);
    for (i = 0; i < monCount; i++) {
        func_0216869C(&trainerA->mons[i], tempMon);
        func_0201A98C(enemy1Party, tempMon);
    }
    func_020307B0(tempMon);

    if (bs->battleRule != 0) {
        client = BTL_CLIENT_ENEMY2;
        trainerData = bs->trainers[client];
        trainerC = trainerA + 1;
        trainerData->trainerId = trainerC->trainerId;
        trainerData->trainerType = trainerC->trainerType;
        trainerData->aiBits = 0x87;
        func_02045924(trainerData->name, trainerC->name);
        enemy2Party = bs->parties[client];
        func_0201A954(enemy2Party, 6);
        tempMon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2C4);
        for (i = 0; i < monCount; i++) {
            func_0216869C(&trainerC->mons[i], tempMon);
            func_0201A98C(enemy2Party, tempMon);
        }
        func_020307B0(tempMon);
    }
    if (bs->battleRule == 3) {
        client = BTL_CLIENT_PARTNER;
        trainerData = bs->trainers[client];
        trainerData->trainerId = trainerB->trainerId;
        trainerData->trainerType = trainerB->trainerType;
        trainerData->aiBits = 0x87;
        func_02045924(trainerData->name, trainerB->name);
        PMSI_PARAM_ClearSentence((PmsData *)&trainerData->battleMsgs.half[0]);
        PMSI_PARAM_ClearSentence((PmsData *)&trainerData->battleMsgs.half[4]);
        partnerParty = bs->parties[client];
        func_0201A954(partnerParty, 6);
        tempMon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2F3);
        for (i = 0; i < monCount; i++) {
            func_0216869C(&trainerB->mons[i], tempMon);
            func_0201A98C(partnerParty, tempMon);
        }
        func_020307B0(tempMon);
    }
    BTL_SETUP_ChangeToSubway(bs);
    return bs;
}






/*
 * Build a battle-facility Pokemon from its a/2/1/4 record (the reader is
 * func_02168800). Levers: the pid store in both arms of an if/else, the
 * ability as a nested if storing in all three arms, and (2026-09-28
 * tree_ov010_4) the EV share as an int local computed straight from the
 * division with the count reused as the second loop's counter.
 */
u32 func_021684E8(BattleMon *out, u32 memberId, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useTableItem, u16 heapId)
{
    BtlInstMonData data;
    int i;
    int evStatCount;
    u8 friendship;
    int evPerStat;
    u32 ability;
    MsgData *speciesNames;

    MI_CpuFill8(out, 0, sizeof(BattleMon));
    func_02168800(&data, memberId);
    out->species = data.species;
    out->form = data.form;
    if (useTableItem)
        out->item = d_02172084[itemIdx];
    else
        out->item = data.item;
    friendship = 0xFF;
    for (i = 0; i < 4; i++) {
        out->moves[i] = data.moves[i];
        if (data.moves[i] == 0xDA)
            friendship = 0;
    }
    out->otId = otId;
    if (pid == 0) {
        pid = func_020186C8(otId, data.species, data.form, 2, 2, 0);
        out->pid = pid;
    } else {
        out->pid = pid;
    }
    out->nature = data.nature;
    out->iv.b.hpIv = iv;
    out->iv.b.atkIv = iv;
    out->iv.b.defIv = iv;
    out->iv.b.speIv = iv;
    out->iv.b.spaIv = iv;
    out->iv.b.spdIv = iv;
    evStatCount = 0;
    for (i = 0; i < 6; i++) {
        if (data.evMask & (1 << i))
            evStatCount++;
    }
    evPerStat = 510 / evStatCount;
    if (evPerStat > 255)
        evPerStat = 255;
    for (evStatCount = 0; evStatCount < 6; evStatCount++) {
        if (data.evMask & (1 << evStatCount))
            out->ev[evStatCount] = evPerStat;
    }
    out->ppUps = 0;
    out->lang = 0;
    ability = func_02019C90(out->species, 0, 0x1B);
    if (ability != 0) {
        if (out->pid & 1)
            out->ability = ability;
        else
            out->ability = func_02019C90(out->species, 0, 0x1A);
    } else {
        out->ability = func_02019C90(out->species, 0, 0x1A);
    }
    out->friendship = friendship;
    speciesNames = MSGDATA_CreateFromArchive(0, 2, 0x46, heapId);
    MSGDATA_ReadUnits(speciesNames, out->species, out->nick, 11);
    func_02045C04(speciesNames);
    return pid;
}






/*
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through func_02017E1C goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 */
void func_0216869C(const BattleMon *src, PokemonParam *mon)
{
    u16 name[11];
    Strbuf *nickBuf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *nick;

    POKE_TOOL_ClearPartyParam(mon);
    func_02017588(mon, src->species, 50, (u64)-1, src->iv.ivs & 0x3FFFFFFF, src->pid);
    func_02017E40(mon, 0x6F, (u8)src->form);
    func_02017E40(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        func_02017E40(mon, 0x36 + i, src->moves[i]);
        func_02017E40(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = func_02017E1C(mon, 0x42 + i, 0);
        func_02017E40(mon, 0x3A + i, pp);
    }
    func_02017E40(mon, 7, src->otId);
    func_02017E40(mon, 0xD, src->ev[0]);
    func_02017E40(mon, 0xE, src->ev[1]);
    func_02017E40(mon, 0xF, src->ev[2]);
    func_02017E40(mon, 0x10, src->ev[3]);
    func_02017E40(mon, 0x11, src->ev[4]);
    func_02017E40(mon, 0x12, src->ev[5]);
    func_02017E40(mon, 0xA, src->ability);
    func_02017E40(mon, 9, src->friendship);
    POKE_TOOL_SetNature(mon, src->nature);
    nickBuf = func_020457B0(11, 4);
    eos = func_02045A98();
    nick = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = nick[i];
    name[i - 1] = eos;
    func_02045924(nickBuf, name);
    func_02017E40(mon, 0x73, (u32)nickBuf);
    func_02045808(nickBuf);
    func_02017E40(mon, 0xC, src->lang);
    func_02017E40(mon, 0x9E, POKE_TOOL_CalcLevel(mon));
}






/*
 * The reader for a/2/1/4: copy one 16-byte record into the caller's buffer.
 * 214 is the archive id and it never appears as an immediate at any call to
 * the arc_tool.c entry points, because this accessor reaches func_02048F4C
 * by pool word and `bx` rather than by `bl`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): a plain scan of `bl`
 * sites misses it entirely.
 *
 * The record is a battle-facility Pokemon: func_021684E8, three functions
 * up in the same file (fld_btl_inst_tool.c, by the __FILE__ anchors either
 * side of this address), reads the buffer field by field into a party
 * slot: +0 species (masked to 11 bits), +2/+4/+6/+8 the four move ids,
 * +10 a six-bit "which stats are EV-invested" mask (the caller divides 510
 * EVs between the set bits), +11 the nature (0..24 over the whole archive),
 * +12 the held item and +14 the form (five bits, always zero here).  The
 * member ids come from a/2/1/5, whose own reader is func_0216880C
 * immediately below this one.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02168800.c \
 *       --func func_02168800 --addr 0x02168800 --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void func_02168800(void *dest, u32 memberId)
{
    func_02048F4C(dest, 214, memberId);
}






/*
 * The reader for a/2/1/5: allocate a buffer and load one group record.
 * func_0204A1BC(archive_id, member, flag, heap) is arc_util.c's
 * "allocate and read a member" helper, so the returned pointer is the
 * sub-file itself.
 *
 * Two things the bytes pin down.  The member is `group + 1`, truncated to
 * 16 bits before the call, so group 0 is sub-file 1 and sub-file 0 is the
 * usual unused sentinel.  And the record is the group list documented in
 * docs/ASSETS.md, [u16 group_id][u16 count][u16 member_id x count]: its
 * consumer func_02168924 takes `count` from +2, picks a random index below
 * it, reads `member_id` from +4 + 2*index, and hands that id to
 * func_02168800, the a/2/1/4 record reader immediately above this
 * function.  That is the direct evidence that a/2/1/5's member ids index
 * a/2/1/4, which the previous pass could only infer from the id range.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216880C.c \
 *       --func func_0216880C --addr 0x0216880C --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void *func_0216880C(u32 group, u32 heapId)
{
    return func_0204A1BC(215, (u16)(group + 1), 0, heapId);
}






/*
 * Random 16-bit value: a 32-bit random number (full range) reduced by 0xFFFF.
 */
int func_02168824(void)
{
    u32 range;

    range = ~0;
    return (u16)func_0209C2B0(func_020056EC(range), range >> 16);
}






/*
 * IV value for a battle-facility trainer index: a step table over the
 * index (3 below 50, up to 31 from 200). Returns u8: func_02168924
 * stores the result to its u8 local without an extension.
 */
u8 func_0216883C(u32 rank)
{
    if (rank < 50)
        return 3;
    if (rank < 70)
        return 6;
    if (rank < 90)
        return 9;
    if (rank < 110)
        return 12;
    if (rank < 160)
        return 15;
    if (rank < 180)
        return 18;
    if (rank < 200)
        return 21;
    return 31;
}






/*
 * Creates a facility trainer: loads the trainer header, then draws the party.
 */
int func_02168878(BtlInstTrainer *trainer, u16 trainerIndex, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId)
{
    BtlInstGroup *group = func_021688BC(trainer, trainerIndex, heapId);
    int itemRuleDropped = func_02168924(group, trainerIndex, trainer->mons, (u8)count, exclSpecies, exclItems, draw, heapId);
    func_020307B0(group);
    return itemRuleDropped;
}






/*
 * Fills the trainer header: id, type from the a/2/1/5 group, name from
 * message bank 11 and the intro message id (three messages per trainer).
 */
BtlInstGroup *func_021688BC(BtlInstTrainer *trainer, int trainerIndex, int heapId)
{
    MsgData *nameBank = func_02045B38(0, 2, 11, heapId);
    BtlInstGroup *group;
    Strbuf *name;
    func_02082BCC(trainer, 0, 0x120);
    group = func_0216880C(trainerIndex, heapId);
    trainer->trainerId = trainerIndex + 1;
    trainer->introMsg.sentenceType = 0xFFFF;
    trainer->introMsg.sentenceId = trainerIndex * 3;
    trainer->trainerType = group->trainerType;
    name = func_02045EC0(nameBank, trainerIndex);
    func_02045A38(name, trainer->name, 16);
    func_02045808(name);
    func_02045C04(nameBank);
    return group;
}






/*
 * Draws `count` distinct battle-facility Pokemon from an a/2/1/5 group
 * list (func_0216880C's record): no repeated species, none of the
 * excluded species, and for the first 50 tries no repeated or excluded
 * held item. Builds each one with func_021684E8 under one random trainer
 * id and optionally reports the first two draws. Returns 1 when the
 * item rule had to be dropped.
 *
 * Levers: locals declared in reverse of their frame order (the arrays
 * after natures, the scalars from otId down), the IV step as u8 (its
 * reader returns only constants up to 31), and a 16-bit `rank` parameter,
 * which moves the r1 spill ahead of the r3 copy (u8 matches equally; int
 * and u32 are 4 bytes out).
 */
int func_02168924(BtlInstGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId)
{
    u8 natures[4];
    int memberIds[4];
    u32 pids[4];
    BtlInstMonData otherData;
    BtlInstMonData data;
    u32 otId;
    u8 iv;
    int memberId;
    int itemTries;
    int itemRuleDropped;
    int i;
    int drawn;

    itemRuleDropped = 0;
    itemTries = 0;
    drawn = 0;
    while (drawn != count) {
        memberId = group->memberIds[(u8)(func_02168824() % group->count)];
        func_02168800(&data, memberId);
        for (i = 0; i < drawn; i++) {
            func_02168800(&otherData, memberIds[i]);
            if (otherData.species == data.species)
                break;
        }
        if (i != drawn)
            continue;
        if (exclSpecies != 0) {
            for (i = 0; i < count; i++) {
                if (data.species == exclSpecies[i])
                    break;
            }
            if (i != count)
                continue;
        }
        if (itemTries < 50) {
            for (i = 0; i < drawn; i++) {
                func_02168800(&otherData, memberIds[i]);
                if (otherData.item != 0 && otherData.item == data.item)
                    break;
            }
            if (i != drawn) {
                itemTries++;
                continue;
            }
            if (exclItems != 0) {
                for (i = 0; i < count; i++) {
                    if (data.item == exclItems[i] && exclItems[i] != 0)
                        break;
                }
                if (i != count) {
                    itemTries++;
                    continue;
                }
            }
        }
        memberIds[drawn] = memberId;
        natures[drawn] = data.nature;
        drawn++;
    }

    iv = func_0216883C(rank);
    otId = func_02168824() | (func_02168824() << 16);
    if (itemTries >= 50)
        itemRuleDropped = 1;
    for (i = 0; i < drawn; i++)
        pids[i] = func_021684E8(&mons[i], (u16)memberIds[i], otId, 0, iv, i, itemRuleDropped, heapId);
    if (draw == 0)
        return itemRuleDropped;
    draw->otId = otId;
    for (i = 0; i < 2; i++) {
        draw->ids[i] = memberIds[i];
        draw->pids[i] = pids[i];
        draw->natures[i] = natures[i];
    }
    return itemRuleDropped;
}






/*
 * Nonzero when either of the two battle message sentences of the trainer
 * has any word set.
 */
int func_02168AC8(BtlInstTrainer *trainer)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (trainer->battleMsgs.half[i] != 0)
            return 1;
        if (trainer->battleMsgs.half[i + 4] != 0)
            return 1;
    }
    return 0;
}






/*
 * Recursive MATCH unblocker: ABS32 target of func_021D0BCC (ov021) +0008.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 *
 * Looks a key up in a table of 0x35 (key, value) halfword pairs; 0xA when
 * the key is absent.
 */
u16 func_02168AEC(u16 key)
{
    u32 i;

    for (i = 0; i < 0x35; i++) {
        if (g_0217208C[i * 2] == key)
            return g_0217208E[i * 2];
    }
    return 0xA;
}






/*
 * Unlabelled leaf callback (movs r1,#1; str r1,[r0]; bx lr); filed as the
 * sole blocker of func_02168B20 (its pool word). Sets the done flag.
 */
void func_02168B18(int *doneFlag)
{
    *doneFlag = 1;
}






/*
 * Comm reset event step: leave the comm session, optionally restart the
 * automatic comm, then ask the field to reset and wait for its callback.
 *
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 */
int func_02168B20(GameEvent *event, int *step, CommResetWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    int fieldMapId = func_02188CCC(func_0201210C(gameSystem));
    GameComm *gameComm = func_02012138(gameSystem);
    CommResetStep current = (CommResetStep)*step;
    switch (current) {
    case COMM_RESET_REQUEST_EXIT:
        if (func_02026454(gameComm) != 0)
            func_02026400(gameComm);
        (*step)++;
        break;
    case COMM_RESET_WAIT_EXIT:
        if (func_02026454(gameComm) != 0)
            break;
        GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 0);
        (*step)++;
        break;
    case COMM_RESET_RESTORE_AUTO_COMM:
        if (work->restoreAutoComm != 0) {
            GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 1);
            func_020121CC(gameSystem);
        }
        (*step)++;
        break;
    case COMM_RESET_REQUEST_FIELD_RESET:
        func_021A0F7C((FieldMap *)fieldMapId, 8, (u32)func_02168B18, (u32)work);
        (*step)++;
        break;
    case COMM_RESET_WAIT_DONE:
        if (work->done != 0)
            *step = current + 1;
        break;
    case COMM_RESET_END:
        return 1;
    }
    return 0;
}






/*
 * Creates the comm reset event.
 */
GameEvent *func_02168BBC(GameSystem *gameSystem, int restoreAutoComm)
{
    GameEvent *event;
    CommResetWork *work;
    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, (GameEventFunc)func_02168B20, 0xc);
    work = func_020124E8(event);
    func_02082BCC(work, 0, 0xc);
    work->gameSystem = gameSystem;
    work->restoreAutoComm = restoreAutoComm;
    return event;
}






/*
 * Creates the party select wrapper event. With useTempParty the party is a
 * fresh five-slot party that the event frees at its end, otherwise it is
 * the player's own party.
 */
GameEvent *func_02168BF0(GameSystem *gameSystem, BtlInstBattleRequest *request, int regulationId, int useTempParty, u16 *resultOk)
{
    GameEvent *event;
    GameData *gameData;
    PartySelectStepWork *work;
    int listArg;
    Party *party;
    gameData = func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, (GameEventFunc)func_02168C74, 0x34);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = func_0201210C(gameSystem);
    work->resultOk = resultOk;
    work->request = request;
    if (regulationId == 0x14 || regulationId == 0x15) {
        if (regulationId == 0x14) {
            work->listArg = 0;
            listArg = 0x14;
        } else {
            work->listArg = 1;
            listArg = 0x15;
        }
    } else {
        work->listArg = 0;
        listArg = 0x14;
    }
    work->regulationId = listArg;
    if (useTempParty == 0) {
        work->tempParty = 0;
        party = func_02012934(gameData);
    } else {
        party = func_0200BAF4(func_0200BAC8(func_02012EBC(gameData)), 5);
        work->tempParty = party;
    }
    work->party = party;
    return event;
}






/*
 * Party select wrapper step: state 0 starts the party select event and moves to state 1;
 * state 1 frees the temporary party and stores whether the player confirmed (a command of 0
 * and a slot other than 7 and 8). The flag store is written in each arm of the if/else
 * (2026-10-05 recoup), which keeps the store before the epilogue add sp.
 */
int func_02168C74(GameEvent *event, int *step, PartySelectStepWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    switch (*step) {
    case 0: {
        GameEvent *child = func_02167EF4(gameSystem, work->listArg, 0x17, work->regulationId, work->party, work->selectOrder, &work->resultSlot, &work->resultCommand, work->request->playerParty);
        func_02012374(event, child);
        *step = 1;
        break;
    }
    case 1:
        if (work->tempParty != 0)
            func_020307B0(work->tempParty);
        if (work->resultCommand != 0 || work->resultSlot - 7 <= 1)
            *work->resultOk = 0;
        else
            *work->resultOk = 1;
        return 1;
    }
    return 0;
}






/*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * recoup 2026-10-05 (P21L10): extent 60 B includes a 2-byte pad (movs r0,r0); code is 58 B.
 * The old draft (12 B off, only the ldr r2 position and the lsls/adds r6 order) closed by
 * dropping const from the record pointer and the byte-pointer casts: EXACT* in c99 and c.
 * Not filed as matched: the offset enum local (off = BTL_INST_REQUEST_MODE_OFFSET, then off - 4, off - 8) is only
 * there to stop mwcc folding 0x12c into the load offsets. With int k or a plain int typedef,
 * literals, struct fields or a named kind local the compiler folds to a 0x49 base (40 B off).
 * A human reason for the held 0x12c is not known; integrator decides. Callee func_021681C8
 * has u8 kind/n params in the ov021 twin caller but this caller passes full words (no
 * truncation), so the prototype here is int. pragmas scheduling/peephole/opt_lifetimes off:
 * no change on the old const form (12 B). unsigned kind: 15 B.
 *
 * Creates the facility trainer battle event from a battle request.
 */
GameEvent *func_02168CF4(GameSystem *gameSystem, BtlInstBattleRequest *request)
{
    FieldMap *fieldMap;
    BtlInstRequestOffset mode;
    BtlInstRequestOffset off;
    fieldMap = func_0201210C(gameSystem);
    off = BTL_INST_REQUEST_MODE_OFFSET;
    mode = (BtlInstRequestOffset)*(int *)((u8 *)request + off);
    return (GameEvent *)func_0216E910(gameSystem, fieldMap, func_021681C8(gameSystem, *(Party *const *)((u8 *)request + (off - 4)), mode, (BtlInstTrainer *)request, 0, *(int *)((u8 *)request + (off - 8))));
}






/*
 * Add one battle's tallies into the running record and credit the
 * score share against the party's summed stat 0xA1. First draft.
 */
void func_02168D30(BtlInstRecord *record, BtlInstResult *result)
{
    Party *party;
    int count;
    int i;
    int statSum;

    record->tally[0] += (u16)(result->tally[0] + 1);
    record->tally[1] += result->tally[1];
    record->tally[2] += result->tally[2];
    record->tally[3] += result->tally[3];
    record->tally[4] += result->tally[4];
    record->tally[5] += result->tally[5];
    record->tally[6] += result->tally[6];
    record->tally[7] += result->tally[7];
    record->tally[8] += result->tally[8];
    record->tally[9] += result->tally[9];
    record->lastTally += result->tally[10];
    party = result->party;
    count = func_0201AA18(party);
    statSum = 0;
    for (i = 0; i < count; i++)
        statSum += func_02017E1C(func_0201AB28(party, i), 0xA1, 0);
    record->scoreShare += (u16)(result->score * 100 / statSum);
}






/*
 * Creates the trial house award event: reads the player's sex and the
 * trial house save and hands them to the ov220 award screen.
 */
GameEvent *func_02168E5C(GameSystem *gameSystem, int arg0, int arg1)
{
    GameData *gameData = func_020120F4(gameSystem);
    GameEvent *event = func_020122C0(gameSystem, 0, (GameEventFunc)func_02168EB0, 0x18);
    TrialHouseAwardEventWork *work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = func_0201210C(gameSystem);
    work->param.playerSex = func_02008550(func_02012944(gameData));
    work->param.trialHouse = func_0200E8F8(func_02012EBC(gameData));
    work->param.arg0 = arg0;
    work->param.arg1 = arg1;
    return event;
}






/*
 * former blocker: pooled ov220_id is passed to func_02012444 r1, missing from
 * OVERLAY_ID_CONSUMERS. Its matched body stores a1 to payload[0]; matched
 * GAME_EVENT_CallProcSeq forwards item[0] as GAMESYSTEM_CallProc r1 (known consumer).
 * The ov220 table hint is supported by that load chain; matcher refuses
 * it as contested until the ID site resolves. No code leaf blocks this.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_02168EB0(GameEvent *event, int *step)
{
    TrialHouseAwardEventWork *work;
    work = func_020124E8(event);
    switch (*step) {
    case 0:
        func_02012444(event, (unsigned int)ov220_id, (unsigned int)d_021BA39C, &work->param);
        (*step)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






/*
 * Field clock update (called from the field map on every day or minute
 * change check): compares the RTC with the saved checkpoint and runs the
 * minute and day updates for the time that has passed.
 */
void func_02168EEC(GameData *gameData)
{
    RTCDate date;
    RTCTime time;
    int days;
    int minutes;
    FieldClock *clock = func_02008B14(func_02012EBC(gameData));
    if (clock->valid == 0)
        return;
    func_0203F49C(&date, &time);
    if (func_02168F54(clock, &date, &time, &days, &minutes) == 0)
        return;
    if (minutes == 0 && days != 0)
        return;
    if (minutes != 0) {
        func_02008BE0(clock, minutes);
        func_02169068(gameData, minutes, &time);
    }
    if (days != 0)
        func_02169004(gameData, days);
}






/*
 * Compares the RTC with the checkpoint. Returns 0 when the clock went
 * backwards (the checkpoint is reset to now), otherwise 1 with the whole
 * minutes passed and the day number difference (0 when the day is the same).
 */
int func_02168F54(FieldClock *clock, RTCDate *date, RTCTime *time, int *outDays, int *outMinutes)
{
    s64 savedSeconds = func_02089004(&clock->date, &clock->time);
    s64 nowSeconds = func_02089004(date, time);
    int dayNumber = func_02088F58(date);
    int minutes;
    *outDays = 0;
    *outMinutes = 0;
    if (nowSeconds < savedSeconds) {
        clock->date = *date;
        clock->time = *time;
        clock->dayNumber = dayNumber;
        return 0;
    }
    minutes = (int)((nowSeconds - savedSeconds) / 60);
    if (minutes > 0) {
        int dayDiff;
        *outMinutes = minutes;
        clock->date = *date;
        clock->time = *time;
        dayDiff = dayNumber - clock->dayNumber;
        if (dayDiff != 0) {
            *outDays = dayDiff;
            clock->dayNumber = dayNumber;
        }
    }
    return 1;
}






/*
 * Day update: clears the day flags and ages the party and the other
 * per-day state.
 *
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/func_0200E518.c), so +0x52 attests as
 * `matched`.
 */
void func_02169004(GameData *gameData, int days)
{
    SaveControl *saveControl;
    func_02169138(gameData);
    saveControl = func_02012EBC(gameData);
    ZONEDATA_ClearTimeFlags(func_0201296C(gameData));
    func_0200D440(saveControl);
    POKERUS_DecreaseDays(func_02012934(gameData), days);
    func_02008E30(func_02012F2C(gameData));
    func_0200952C(func_02009470(saveControl));
    func_021862A8(gameData, days, 4);
    func_0200E518(func_0200E394(saveControl));
    func_0200AB04(func_0200A8A0(saveControl));
}






/*
 * Minute update: runs the Shaymin form check with the current time and
 * passes the current time on to the save.
 *
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 */
void func_02169068(GameData *gameData, int minutes, RTCTime *time) { PartySave *partySave=func_0201AD0C(func_02012EBC(gameData)); func_0216A2EC(gameData,partySave,minutes,time,func_02012984(gameData)); func_0200C3C0(func_0200C0F0(func_02012EBC(gameData)),minutes); }






/*
 * Date of the clock checkpoint.
 */
RTCDate *func_021690A4(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return &clock->date;
}






/*
 * Time zone of the day (by season and hour of the checkpoint).
 */
int func_021690B4(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;

    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return TIMEZONE_GetTimeZoneOfHour(func_02012984(gameData), clock->time.hour);
}






int func_021690D0(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return clock->date.month;
}






int func_021690E0(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return clock->date.day;
}






int func_021690F0(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return clock->date.week;
}






int func_02169100(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return clock->time.hour;
}






int func_02169110(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return clock->time.minute;
}






void func_02169120(GameData *gameData) { FieldClock *clock = func_02008B14(func_02012EBC(gameData)); *(u64 *)(clock->timestamp) = func_0203F524(); }






int func_02169138(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = func_02012EBC(gameData);
    clock = func_02008B14(saveControl);
    return func_02008BD0(clock);
}
