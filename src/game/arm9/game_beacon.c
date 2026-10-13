/*
 * file:     game_beacon.c
 * unit:     yes
 * function: GAME_COMM_CallKindNotify, GAME_COMM_Start, GAME_COMM_RequestExitNoCallback, GAME_COMM_RequestExit, func_02026454, func_02026460, func_02026474, func_02026478, func_0202647C, func_02026484, func_0202648C, GAME_COMM_SetSeqState, GAME_COMM_SetNotifyFlag, GAME_COMM_GetNotifyFlag, GAME_COMM_UpdatePlayerStatus, GAME_COMM_ClearPlayerStatus, GAME_COMM_PushInfoMessage, GAME_COMM_PopInfoMessage, GAME_COMM_ClearInfoMessages, GAME_COMM_PushPairMessage, GAME_COMM_PushPalaceMessage, GAME_COMM_PushPlayerMessage, GAME_BEACON_Create, GAME_BEACON_Update, GAME_BEACON_Setup, GAME_BEACON_GetMyInfo, GAME_BEACON_SendIfRequested, GAME_BEACON_UpdateActionTime, GAME_BEACON_AddLog, GAME_BEACON_ReceiveInfo, GAME_BEACON_GetLogFromWork, GAME_BEACON_GetLog, GAME_BEACON_GetLogByReceiveNoFromWork, GAME_BEACON_GetLogByReceiveNo, GAME_BEACON_GetReceiveCount, GAME_BEACON_GetNextNewLogIndex, GAME_BEACON_ClearNewFlag, GAME_BEACON_SetNewFlagByTrainerId, GAME_BEACON_GetReceivedFramesByTrainerId, GAME_BEACON_BuildMyInfo, GAME_BEACON_RequestSend, GAME_BEACON_CheckActionPriority, GAME_BEACON_IsSpecialPokemon, GAME_BEACON_CopyStrbufCodes, GAME_BEACON_PopQuestionnaireUpdated, GAME_BEACON_SetQuestionnaire, GAME_BEACON_SetNationArea, GAME_BEACON_SetResearchTeamRank, GAME_BEACON_SetPms, GAME_BEACON_SetTrainerView, GAME_BEACON_UpdateGreeting, GAME_BEACON_SetPokeCapture, GAME_BEACON_SetPokeGet, func_02027220, GAME_BEACON_SetSpecialPokeGet, func_02027258, GAME_BEACON_SetPokeLevelUp, func_02027290, GAME_BEACON_SetPokeEvolution, func_020272D0, GAME_BEACON_SetPlayTime, func_02027314, GAME_BEACON_SetItemUse, func_0202734C, GAME_BEACON_SetZone, GAME_BEACON_SetInfoZone, GAME_BEACON_SetDetailsBattleWildPoke, GAME_BEACON_SetDetailsBattleSpecialPoke, GAME_BEACON_SetDetailsBattleTrainer, GAME_BEACON_SetDetailsBattleLeader, GAME_BEACON_SetDetailsBattleBigFour, GAME_BEACON_ResetDetails, GAME_BEACON_WritePms, GAME_BEACON_SetMyPms, GAME_BEACON_RegisterClearCallback, GAME_BEACON_ClearFlags
 * address:  0x020263B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from app_taskmenu.c at 0x0202751C (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   GAME_COMM_KindTable  0x0209FB5C  data
 *   MI_CpuFill8 0x02082BCC  arm
 *   func_02012B58  0x02012B58  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012950  0x02012950  thumb
 *   func_020084BC  0x020084BC  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   GAME_BEACON_Work     0x02146940  data
 *   GAME_BEACON_AssertText     0x020A74BC  data
 *   GAME_BEACON_FileName     0x020A74C0  data
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   func_0200864C  0x0200864C  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0217778C  0x0217778C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E44C  0x0200E44C  thumb
 *   func_02167394  0x02167394  thumb
 *   func_0200E3A4  0x0200E3A4  thumb
 *   func_0200E49C  0x0200E49C  thumb
 *   func_0200E460  0x0200E460  thumb
 *   func_0200E4CC  0x0200E4CC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C33C  0x0200C33C  thumb
 *   func_0200C364  0x0200C364  thumb
 *   func_0200E6E8    0x0200E6E8  thumb
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_020127A4    0x020127A4  thumb
 *   func_02012AC8    0x02012AC8  thumb
 *   func_02013CC8    0x02013CC8  thumb
 *   func_02013CE0    0x02013CE0  thumb
 *   func_02012894    0x02012894  thumb
 *   SYMBOL_MAP_ResolveZoneId    0x02166C7C  thumb
 *   func_02008534    0x02008534  thumb
 *   func_02008554    0x02008554  thumb
 *   func_0200856C    0x0200856C  thumb
 *   func_02008570    0x02008570  thumb
 *   func_0200C224    0x0200C224  thumb
 *   func_0200C1C4    0x0200C1C4  thumb
 *   func_0200C1DC    0x0200C1DC  thumb
 *   func_02008650    0x02008650  thumb
 *   func_0200E3A0    0x0200E3A0  thumb
 *   func_0200E6FC    0x0200E6FC  thumb
 *   STRBUF_GetEosChar    0x02045A98  arm
 *   func_020084F4    0x020084F4  thumb
 *   func_0200C1F4    0x0200C1F4  thumb
 *   GAME_BEACON_ActionTable    0x0209FC20  data
 *   GAME_BEACON_SpecialPokemonTable  0x0209FC04  data
 *   STRBUF_ToChars       0x02045A38  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_021809D8  0x021809D8  thumb ov231
 *   func_02034A5C  0x02034A5C  arm
 *   func_02005624  0x02005624  thumb
 *   ov231_id       0x000000E7  data
 */

struct GameData;
struct MyStatus;
struct PlayerWork;
struct PlayTime;
struct SaveControl;
struct MiscSave;
struct QuestionnaireSave;
struct PmsSave;
struct Strbuf;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * game_comm.c object (0x020263B0..0x020266D4 belong to game_comm.c, see
 * cuts.tsv): the comm request object of the game system.
 * ------------------------------------------------------------------ */

/* Sequence of the running comm kind, at +0xC of GameComm. */
typedef struct GameCommSeq {
    u32 frameCount;     /* cleared by the state machine on a state change */
    u8  state;          /* 0 start, 1 wait, 2 run, 3 exit, 4 end, 5 finish */
    u8  changed;        /* set with every state change */
    u8  reserved[2];
} GameCommSeq;

/* Last callback of the 0x1C-byte per-kind entries of the comm kind table. */
typedef void (*GameCommNotifyFunc)(u32 param, void *work, u32 arg);

/* Callbacks of one comm kind, 0x1C bytes per entry; the table is indexed by
 * GameComm.kind (entry 0 unused). */
typedef struct GameCommKindFuncs {
    void *start;
    void *wait;
    void *run;
    void *exit;
    void *end;
    void *update;               /* 0x14: called by func_02026388 */
    GameCommNotifyFunc notify;  /* 0x18 */
} GameCommKindFuncs;

/* Called when the comm kind has exited. */
typedef void (*GameCommExitFunc)(u32 arg0, u32 arg1);

/* What each connected player is doing, one entry per net id. */
typedef struct GameCommPlayerStatus {
    u16 zoneId;             /* 0x0 */
    u16 prevZoneId;         /* 0x2 */
    u8  fieldStatus;        /* 0x4 */
    u8  palaceNetId;        /* 0x5: net id of the player whose world this player is in */
    u8  prevPalaceNetId;    /* 0x6 */
    u8  reserved;
} GameCommPlayerStatus;

/* One queued information message (two player names and a message id). */
typedef struct GameCommInfoQueueEntry {
    u16 messageId;              /* 0x0 */
    u8  netId;                  /* 0x2 */
    u8  used : 1;               /* 0x3 */
    u8  firstSex : 1;
    u8  secondSex : 1;
    u8  reserved : 5;
    struct Strbuf *name[2];     /* 0x4 */
} GameCommInfoQueueEntry;

typedef struct GameCommInfoQueue {
    GameCommInfoQueueEntry entry[6];    /* 0x00 */
    u8 readIndex;                       /* 0x48: advanced when the writer overruns it */
    u8 writeIndex;                      /* 0x49 */
} GameCommInfoQueue;

/* A popped message, as the message window wants it. */
typedef struct GameCommInfoMessage {
    struct Strbuf *name[2];     /* 0x0 */
    u8  wordSetIndex[2];        /* 0x8 */
    u8  sex[2];                 /* 0xA */
    u16 messageId;              /* 0xC */
    u8  reserved[2];
} GameCommInfoMessage;

typedef struct GameComm {
    struct GameData *gameData;  /* 0x00 */
    u8  exitRequest : 1;        /* 0x04: exit asked before the kind runs */
    u8  exitPending : 1;        /*       exit asked while the kind ends */
    u8  notifyFlag : 1;
    u8  reservedBits : 5;
    u8  kind;                   /* 0x05: index into the kind table, 0 = idle */
    u8  lastKind;               /* 0x06 */
    u8  reserved;
    u32 counter;                /* 0x08 */
    GameCommSeq seq;            /* 0x0C */
    u32 param;                  /* 0x14: the start request argument */
    void *work;                 /* 0x18: the start callback's result */
    u32 exitArg;                /* 0x1C */
    GameCommExitFunc exitFunc;  /* 0x20 */
    GameCommPlayerStatus playerStatus[3];   /* 0x24 */
    GameCommInfoQueue infoQueue;            /* 0x3C */
} GameComm;

/* ------------------------------------------------------------------ *
 * game_beacon.c: the wireless beacon (C-Gear) information.
 * ------------------------------------------------------------------ */

#include "game_beacon_types.h"


/* Per-action priority and display time. */
typedef struct GameBeaconActionInfo {
    u32 priority : 8;
    u32 frames : 24;
} GameBeaconActionInfo;

/* Only the zone id of the location func_02012894 answers is read here. */
struct WarpLocation {
    u32 locationType;
    s16 zoneId;
};

typedef struct {
    u8  language;
    u8  favoriteColor;
    u8  month;
    u8  day;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
extern void OS_GetOwnerInfo(OSOwnerInfo *info);
extern u8 func_02012B58(const struct GameData *gameData);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern struct MyStatus *func_02012950(struct GameData *gameData, u32 netId);
extern int func_020084BC(const struct MyStatus *status);
extern void func_02008500(const struct MyStatus *status, struct Strbuf *dst);
extern u32 func_02008550(const struct MyStatus *status);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern int  GFL_NET_GetRunState(void);
extern struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gameData);
extern u16 func_0200864C(const struct PlayTime *playTime);
extern u8 func_02008650(const struct PlayTime *playTime);
extern void func_0217778C(void);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct QuestionnaireSave *func_0200E394(struct SaveControl *save);
extern int   func_0200E44C(struct QuestionnaireSave *questionnaire, int slot);
extern u32   func_02167394(u8 questionId);
extern u32   func_0200E3A4(const u8 *answers, u8 questionId);
extern u32 func_0200E49C(struct QuestionnaireSave *questionnaire, u32 questionId, u32 answer);
extern void func_0200E460(struct QuestionnaireSave *questionnaire, int questionId, int counted);
extern void func_0200E4CC(struct QuestionnaireSave *questionnaire, u32 questionId, u32 answer, int count);
extern const u8 *func_0200E3A0(struct QuestionnaireSave *questionnaire);
extern struct MiscSave *func_0200C0F0(struct SaveControl *save);
extern int func_0200C33C(struct MiscSave *misc, u8 slot);
extern void func_0200C364(struct MiscSave *misc, u8 slot, int value);
extern u8 func_0200C224(struct MiscSave *misc);
extern u32 func_0200C1C4(struct MiscSave *misc);
extern u32 func_0200C1DC(struct MiscSave *misc);
extern u16 *func_0200C1F4(struct MiscSave *misc);
extern struct PmsSave *func_0200E6E8(struct SaveControl *save);
extern void func_0200E6FC(struct PmsSave *pmsSave, int index, GameBeaconPms *dst);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *player);
extern u32 func_02013CC8(u16 zoneId);
extern u32 func_02013CE0(u16 zoneId);
extern struct WarpLocation *func_02012894(const struct GameData *gameData);
extern u32 SYMBOL_MAP_ResolveZoneId();
extern u16 func_02008534(const struct MyStatus *status);
extern u8 func_02008554(const struct MyStatus *status);
extern u8 func_0200856C(const struct MyStatus *status);
extern u8 func_02008570(const struct MyStatus *status);
extern u16 *func_020084F4(const struct MyStatus *status);
extern u16   STRBUF_GetEosChar(void);
extern void STRBUF_ToChars(const struct Strbuf *str, u16 *codes, u32 count);
extern int   func_02034AC4(signed int overlayId);
extern int   func_021809D8(void);
extern void  func_02034A5C(int overlayId);
extern void *func_02005624(void (*func)(void), u32 arg, u32 priority);
void GAME_COMM_CallKindNotify(GameComm *comm, u32 arg);
void GAME_COMM_Start(GameComm *comm, u32 kind, u32 param);
void GAME_COMM_RequestExitNoCallback(GameComm *comm);
void GAME_COMM_RequestExit(GameComm *comm, GameCommExitFunc exitFunc, u32 exitArg);
u32 GAME_COMM_GetKind(const GameComm *comm);
u32 GAME_COMM_IsTransition(const GameComm *comm);
void *GAME_COMM_GetWork(const GameComm *comm);
struct GameData *GAME_COMM_GetGameData(const GameComm *comm);
u32 GAME_COMM_GetLastKind(const GameComm *comm);
void GAME_COMM_SetCounter(GameComm *comm, u32 value);
void GAME_COMM_ClearCounter(GameComm *comm);
u32 GAME_COMM_GetCounter(const GameComm *comm);
void GAME_COMM_SetSeqState(GameCommSeq *seq, u32 state);
void GAME_COMM_SetNotifyFlag(GameComm *comm, u32 flag);
u32 GAME_COMM_GetNotifyFlag(const GameComm *comm);
void GAME_COMM_UpdatePlayerStatus(GameComm *comm, int netId, u16 zoneId, u8 palaceNetId, u32 fieldStatus, int quiet);
void GAME_COMM_ClearPlayerStatus(GameComm *comm);
void GAME_COMM_PushInfoMessage(GameComm *comm, u32 netId0, u32 netId1, u32 messageId);
int GAME_COMM_PopInfoMessage(GameComm *comm, GameCommInfoMessage *message);
void GAME_COMM_ClearInfoMessages(GameComm *comm);
void GAME_COMM_PushPairMessage(GameComm *comm, u32 netId0, u32 netId1);
void GAME_COMM_PushPalaceMessage(GameComm *comm, u32 netId, u32 palaceNetId);
void GAME_COMM_PushPlayerMessage(GameComm *comm, u32 netId);
void GAME_BEACON_Create(u32 heapId);
void GAME_BEACON_Update(void);
void GAME_BEACON_Setup(struct GameData *gameData);
void GAME_BEACON_GetMyInfo(GameBeaconInfo *dst);
void GAME_BEACON_SendIfRequested(void);
void GAME_BEACON_UpdateActionTime(GameBeaconRecord *own);
void GAME_BEACON_AddLog(GameBeaconWork *work, const GameBeaconInfo *info);
int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info);
GameBeaconRecord *GAME_BEACON_GetLogFromWork(GameBeaconWork *work, int index);
GameBeaconRecord *GAME_BEACON_GetLog(int index);
GameBeaconRecord *GAME_BEACON_GetLogByReceiveNoFromWork(GameBeaconWork *work, int receiveNo);
GameBeaconRecord *GAME_BEACON_GetLogByReceiveNo(int receiveNo);
u32 GAME_BEACON_GetReceiveCount(void);
int GAME_BEACON_GetNextNewLogIndex(int *cursor);
void GAME_BEACON_ClearNewFlag(u32 index);
int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info);
u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 trainerId);
void GAME_BEACON_BuildMyInfo(GameBeaconInfo *info, struct GameData *gameData);
void GAME_BEACON_RequestSend(GameBeaconRecord *record);
u32 GAME_BEACON_CheckActionPriority(u32 action);
int GAME_BEACON_IsSpecialPokemon(u16 monsNo);
void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest);
u8 GAME_BEACON_PopQuestionnaireUpdated(void);
void GAME_BEACON_SetQuestionnaire(const u8 *answers);
void GAME_BEACON_SetNationArea(u8 nation, u8 area);
void GAME_BEACON_SetResearchTeamRank(u32 rank);
void GAME_BEACON_SetPms(const GameBeaconPms *pms);
void GAME_BEACON_SetTrainerView(u32 trainerView);
void GAME_BEACON_UpdateGreeting(void);
void GAME_BEACON_SetPokeCapture(u16 monsNo);
void GAME_BEACON_SetPokeGet(u16 monsNo);
void GAME_BEACON_SetSpecialPokeGet(u16 monsNo);
void GAME_BEACON_SetPokeLevelUp(u16 nickname);
void GAME_BEACON_SetPokeEvolution(u16 monsNo, u16 nickname);
void GAME_BEACON_SetPlayTime(u32 playHours);
void GAME_BEACON_SetItemUse(u16 itemNo);
void GAME_BEACON_SetZone(u32 zoneId, u32 zoneSource);
void GAME_BEACON_SetInfoZone(GameBeaconInfo *info, u32 zoneId, u32 zoneSource);
void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u16 monsNo);
void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u16 monsNo);
void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u16 trainerId);
void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u16 trainerId);
void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u16 trainerId);
void GAME_BEACON_ResetDetails(GameBeaconInfo *info);
void GAME_BEACON_WritePms(GameBeaconInfo *info, const GameBeaconPms *pms);
void GAME_BEACON_SetMyPms(const GameBeaconPms *pms);
void GAME_BEACON_RegisterClearCallback(void);
void GAME_BEACON_ClearFlags(void);
extern const GameCommKindFuncs GAME_COMM_KindTable[];
extern GameBeaconWork *GAME_BEACON_Work;
extern char   GAME_BEACON_AssertText[];
extern char   GAME_BEACON_FileName[];
extern const GameBeaconActionInfo GAME_BEACON_ActionTable[];
extern const u16 GAME_BEACON_SpecialPokemonTable[];
extern char  ov231_id[];













/*
 * Parked: every concrete byte is right; the only unresolved site is the
 * data table base 0x0209FB74, whose word has no witness outside this range
 * (`literal` has nothing to stand on, and no branch anywhere names it).
 */
void GAME_COMM_CallKindNotify(GameComm *comm, u32 arg)
{
    if (comm->seq.state != 5) {
        GameCommNotifyFunc func = GAME_COMM_KindTable[comm->kind].notify;

        if (func != 0) {
            func(comm->param, comm->work, arg);
        }
    }
}













/*
 * A whole translation unit, matched as one byte range.
 *
 * game_comm.c, 0x020263D8..0x02026454: start a request, the unlabelled
 * forwarding leaf GAME_COMM_RequestExitNoCallback (GAME_COMM_RequestExit(p, 0, 0) as a pool-word tail
 * call), and the request update.  The byte at +4 of the comm object and of
 * its 8-byte sub-object at +0xC is a set of one-bit flags; every clear is a
 * `bics` and every set an `orrs`, which only bitfield stores give
 * (docs/families/game_comm.h).  GAME_COMM_Start clears bit 1 between its two
 * plain stores: f14, bit, f05 is the one order whose flag load lands after
 * the f14 store (the other two schedule the f05 store first).
 *
 * Integrator: seed 0x02026400 (unlabelled follower, member of this unit).
 */
void GAME_COMM_Start(GameComm *comm, u32 kind, u32 param)
{
    comm->param = param;
    comm->exitPending = 0;
    comm->kind = kind;
    comm->exitFunc = 0;
    comm->exitArg = 0;
    MI_CpuFill8(&comm->seq, 0, sizeof(GameCommSeq));
    GAME_COMM_ClearPlayerStatus(comm);
}













void GAME_COMM_RequestExitNoCallback(GameComm *comm)
{
    GAME_COMM_RequestExit(comm, 0, 0);
}













void GAME_COMM_RequestExit(GameComm *comm, GameCommExitFunc exitFunc, u32 exitArg)
{
    if (comm->seq.state == 2) {
        GAME_COMM_SetSeqState(&comm->seq, 3);
        comm->exitFunc = exitFunc;
        comm->exitArg = exitArg;
    } else if (comm->seq.state < 2) {
        comm->exitRequest = 1;
        comm->exitFunc = exitFunc;
        comm->exitArg = exitArg;
    } else {
        comm->exitPending = 1;
        if (comm->exitFunc == 0) {
            comm->exitFunc = exitFunc;
            comm->exitArg = exitArg;
        }
    }
}
















/*
 * A whole translation unit, matched as one byte range.
 *
 *           GAME_COMM_GetLastKind, GAME_COMM_SetCounter, GAME_COMM_ClearCounter, GAME_COMM_GetCounter
 *
 * Eight two-to-five-instruction accessors on one object, none of them
 * pushing a register: only the first is a real label in the generated
 * listing (a `func_starts` seed reached it some other way), and the other
 * seven print as `.word` runs between the two named functions this range
 * sits between, the same gap docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md describes.
 *
 * GAME_COMM_GetKind returns byte field +5 unconditionally: the original's
 * `bne`-around-a-redundant-`movs r0,#0` is what a plain `return v;`
 * compiles to when `v` is already known nonzero on one path, not a
 * guard. GAME_COMM_IsTransition is a genuine conjunction, `field5 != 0 &&
 * field0x10 != 2`, and only that phrasing (not two early-return `if`s)
 * produces the shared branch target both comparisons jump to
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * The rest are plain word/byte getters and setters on fields +0x18, +0,
 * +6 and +8, one of them (GAME_COMM_ClearCounter) a "clear to zero" specialisation
 * of the setter that immediately follows it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026454.c \
 *       --addr 0x02026454 --thumb
 */
u32 GAME_COMM_GetKind(const GameComm *comm)
{
    u8 kind = comm->kind;
    if (kind != 0) {
        return kind;
    }
    return 0;
}
















u32 GAME_COMM_IsTransition(const GameComm *comm)
{
    if (comm->kind != 0 && comm->seq.state != 2) {
        return 1;
    }
    return 0;
}
















void *GAME_COMM_GetWork(const GameComm *comm)
{
    return comm->work;
}
















struct GameData *GAME_COMM_GetGameData(const GameComm *comm)
{
    return comm->gameData;
}
















u32 GAME_COMM_GetLastKind(const GameComm *comm)
{
    return comm->lastKind;
}
















void GAME_COMM_SetCounter(GameComm *comm, u32 value)
{
    comm->counter = value;
}
















void GAME_COMM_ClearCounter(GameComm *comm)
{
    comm->counter = 0;
}
















u32 GAME_COMM_GetCounter(const GameComm *comm)
{
    return comm->counter;
}
















/*
 * A whole translation unit, matched as one byte range.
 *
 * The labelled GAME_COMM_SetSeqState (8 bytes) is followed immediately by two more
 * unlabelled leaves reaching to the next real label at 0x020264B4, the
 * same shape as src/matched/unit_02026454.c just above it in the image.
 *
 * GAME_COMM_SetSeqState sets byte field +4 to its argument and unconditionally
 * sets byte field +5 to 1. GAME_COMM_SetNotifyFlag and GAME_COMM_GetNotifyFlag are a
 * setter/getter pair on bit 2 of field +4: the setter narrows its 32-bit
 * argument to a byte before taking bit 0 of it
 * (`u8 f = (u8)flag;` is what produces the `lsls #0x18`/`lsrs #0x18`
 * truncation pair, not a mask, per the halfword-narrowing case in
 * docs/MATCHING.md), and the getter's `lsls #0x1d`/`lsrs #0x1f` pair is a
 * bitfield extraction rather than a type conversion (32 - 0x1d is 3, not
 * 8/16/32), which only reproduces from an actual bitfield member
 * declaration: docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026490.c \
 *       --addr 0x02026490 --thumb
 */
void GAME_COMM_SetSeqState(GameCommSeq *seq, u32 state)
{
    seq->state = state;
    seq->changed = 1;
}
















void GAME_COMM_SetNotifyFlag(GameComm *comm, u32 flag)
{
    u8 value = (u8)flag;

    comm->notifyFlag = value;
}
















u32 GAME_COMM_GetNotifyFlag(const GameComm *comm)
{
    return comm->notifyFlag;
}
















void GAME_COMM_UpdatePlayerStatus(GameComm *comm, int netId, u16 zoneId, u8 palaceNetId, u32 fieldStatus, int quiet)
{
    GameCommPlayerStatus *status = &comm->playerStatus[netId];
    u16 oldZoneId;
    u8 oldPalaceNetId;

    status->fieldStatus = fieldStatus;
    oldZoneId = status->zoneId;
    if (oldZoneId == zoneId && status->palaceNetId == palaceNetId) {
        return;
    }
    if (oldZoneId != zoneId) {
        status->prevZoneId = oldZoneId;
        status->zoneId = zoneId;
    }
    oldPalaceNetId = status->palaceNetId;
    if (oldPalaceNetId == palaceNetId) {
        return;
    }
    status->prevPalaceNetId = oldPalaceNetId;
    status->palaceNetId = palaceNetId;
    if (!quiet) {
        GAME_COMM_PushPalaceMessage(comm, netId, palaceNetId);
    }
}
















void GAME_COMM_ClearPlayerStatus(GameComm *comm)
{
    MI_CpuFill8(comm->playerStatus, 0, sizeof(comm->playerStatus));
}
















/*
 * Push one message onto the six-entry info queue at +0x3c of the comm
 * object (func_020261E4 creates it; 0xc bytes per entry, write index at
 * +0x85, read index at +0x84, which is pushed along when the writer
 * overruns it).  Each net id is resolved to a player status: the console's
 * own (func_02012944) when it equals the console's net id, otherwise the
 * by-id lookup (func_02012950).  If either status is unusable
 * (func_020084BC == 1) nothing is written.
 */
void GAME_COMM_PushInfoMessage(GameComm *comm, u32 netId0, u32 netId1, u32 messageId)
{
    GameCommInfoQueue *queue;
    struct MyStatus *status0;
    struct MyStatus *status1;
    GameCommInfoQueueEntry *entry;

    queue = &comm->infoQueue;
    if (netId0 == func_02012B58(comm->gameData)) {
        status0 = func_02012944(comm->gameData);
    } else {
        status0 = func_02012950(comm->gameData, netId0);
    }
    if (netId1 == func_02012B58(comm->gameData)) {
        status1 = func_02012944(comm->gameData);
    } else {
        status1 = func_02012950(comm->gameData, netId1);
    }
    if (func_020084BC(status0) == 1) {
        return;
    }
    if (func_020084BC(status1) == 1) {
        return;
    }
    entry = &queue->entry[queue->writeIndex];
    if (entry->used == 1) {
        queue->readIndex = (u8)(queue->readIndex + 1);
    }
    entry->netId = (u8)netId0;
    entry->messageId = (u16)messageId;
    entry->used = 1;
    func_02008500(status0, entry->name[0]);
    entry->firstSex = (u8)func_02008550(status0);
    func_02008500(status1, entry->name[1]);
    entry->secondSex = (u8)func_02008550(status1);
    queue->writeIndex = (u8)(queue->writeIndex + 1);
    if (queue->writeIndex >= 6) {
        queue->writeIndex = 0;
    }
    if (queue->readIndex >= 6) {
        queue->readIndex = 0;
    }
}













/*
 * EXACT*: the listing extent runs 164 bytes because the follower at
 * 0x0202667E is an unlabelled leaf (`movs r0, r0` / `bx lr`) that saves
 * nothing, so `disasm.py` never labels it.  Byte coverage ends at +0x76.
 *
 * Counted eight-entry bank: pop the next live 12-byte record at
 * base + base[0x48] * 12, publish it as the caller's 0x10-byte snapshot,
 * clear its live flag and advance the cursor with a wrap at six.
 *
 * The publish order is not the source order: the whole-word load of +0x04
 * lands before the `out[8] = 0` store, so the C has to store the word first
 * and the byte second to let the scheduler hoist the load into the store's
 * shadow.  Written with `out[8] = 0` first, the compiled order flips and
 * nine bytes differ.
 */
int GAME_COMM_PopInfoMessage(GameComm *comm, GameCommInfoMessage *message)
{
    GameCommInfoQueue *queue = &comm->infoQueue;
    GameCommInfoQueueEntry *entry = &queue->entry[queue->readIndex];

    if (entry->used == 0) {
        return 0;
    }
    MI_CpuFill8(message, 0, sizeof(GameCommInfoMessage));
    message->name[0] = entry->name[0];
    message->wordSetIndex[0] = 0;
    message->sex[0] = entry->firstSex;
    message->name[1] = entry->name[1];
    message->wordSetIndex[1] = 1;
    message->sex[1] = entry->secondSex;
    message->messageId = entry->messageId;
    entry->used = 0;
    queue->readIndex = queue->readIndex + 1;
    if (queue->readIndex >= 6) {
        queue->readIndex = 0;
    }
    return 1;
}














/*
 * Clears bit 0 of six 12-byte entries at +0x3F and the bytes at +0x85 and +0x84.
 * Caller: ov011 0x021731C8.
 */
void GAME_COMM_ClearInfoMessages(GameComm *comm)
{
    int i;
    for (i = 0; i < 6; i++) {
        comm->infoQueue.entry[i].used = 0;
    }
    comm->infoQueue.writeIndex = 0;
    comm->infoQueue.readIndex = 0;
}














/*
 * A thin wrapper over `GAME_COMM_PushInfoMessage` (258 bytes, still open), forwarding
 * its three arguments unchanged and appending a fourth: 0x27 when the
 * second and third arguments are equal, 0x26 otherwise. The `? :` form,
 * not an `if`/`else` writing the call twice, is what reproduces the
 * single shared `lsls`/`lsrs #0x10` that narrows the chosen constant to
 * the callee's 16-bit fourth parameter after the branch instead of in
 * each arm.
 *
 * `GAME_COMM_PushInfoMessage`'s only three callers in the whole ARM9 image are this
 * function and its two siblings GAME_COMM_PushPalaceMessage and GAME_COMM_PushPlayerMessage
 * (src/matched/GAME_COMM_PushPalaceMessage.c, src/matched/GAME_COMM_PushPlayerMessage.c). Keeping each
 * in its own translation unit is what gives the other two's calls
 * standing as outside evidence for this one; compiled together as a
 * single unit the three calls would attest only each other and the whole
 * range would cap at MATCH (docs/MATCHING.md, "the pairwise case across
 * two files").
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPairMessage.c \
 *       --func GAME_COMM_PushPairMessage --addr 0x020266AC --cc 1.1p1 --thumb
 */
void GAME_COMM_PushPairMessage(GameComm *comm, u32 netId0, u32 netId1)
{
    GAME_COMM_PushInfoMessage(comm, netId0, netId1, (u16)((netId0 == netId1) ? 0x27 : 0x26));
}














/*
 * The same wrapper shape as src/matched/GAME_COMM_PushPairMessage.c, with the constant
 * pair 0x1e/0x1d in place of 0x27/0x26. See that file's header for why it
 * is kept in its own translation unit rather than merged with its two
 * siblings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPalaceMessage.c \
 *       --func GAME_COMM_PushPalaceMessage --addr 0x020266C0 --cc 1.1p1 --thumb
 */
void GAME_COMM_PushPalaceMessage(GameComm *comm, u32 netId, u32 palaceNetId)
{
    GAME_COMM_PushInfoMessage(comm, netId, palaceNetId, (u16)((netId == palaceNetId) ? 0x1e : 0x1d));
}














/*
 * The simplest of the three GAME_COMM_PushInfoMessage wrappers: forwards its first
 * argument, repeats its second as both the second and third callee
 * argument, and appends the literal 0x1f. See
 * src/matched/GAME_COMM_PushPairMessage.c's header for why the three are kept as
 * separate files rather than one unit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPlayerMessage.c \
 *       --func GAME_COMM_PushPlayerMessage --addr 0x020266D4 --cc 1.1p1 --thumb
 */
void GAME_COMM_PushPlayerMessage(GameComm *comm, u32 netId)
{
    GAME_COMM_PushInfoMessage(comm, netId, netId, 0x1f);
}














/*
 * Allocates the 0xbb4-byte beacon system block on the caller's heap and
 * publishes it through GAME_BEACON_Work, after releasing any previous one.
 *
 * The two spellings that decided it:
 *   - the third argument (1) is bound to a NAMED local `one`, which keeps
 *     it alive in the callee-saved r4 across the call to func_02030734;
 *     the trailing -1 store is then derived from it as `subs r2, r4, #2`.
 *     Written as a plain -1 / 0xff / (u8)-1, the compiler folds it to
 *     `movs r2, #0xff` before the call and the r4/r5 assignment flips.
 *   - 0xbb4 stays a plain integer literal: the compiler pools it of its
 *     own accord, so no absolute linker symbol is needed (an earlier
 *     attempt that declared it as `extern char sBeaconSize[]` produced
 *     the same 72 bytes but capped at MATCH on that unattestable ABS32).
 *
 * 0x020A74BC resolves through sole-ref; 0x020A74C0 is the __FILE__ string.
 */
void GAME_BEACON_Create(u32 heapId)
{
    u32 one = 1;

    if (GAME_BEACON_Work != 0) {
        func_02034714(GAME_BEACON_AssertText, 0, GAME_BEACON_AssertText);
    }
    GAME_BEACON_Work = func_02030734(heapId, sizeof(GameBeaconWork), one, GAME_BEACON_FileName, 0x5a);
    GAME_BEACON_Work->newestIndex = (u8)(one - 2);
}














void GAME_BEACON_Update(void)
{
    GameBeaconWork *work;
    s32 playHours;
    s32 i;

    work = GAME_BEACON_Work;
    if (work == 0) {
        return;
    }
    if (GFL_NET_GetRunState() == 0) {
        return;
    }
    if (work->gameData != 0) {
        playHours = func_0200864C(GAME_DATA_GetPlayTime(work->gameData));
        if (work->lastPlayHours != playHours) {
            switch (playHours) {
            case 10:
            case 30:
            case 50:
            case 100:
                GAME_BEACON_SetPlayTime(playHours);
                break;
            }
        }
        work->lastPlayHours = (u16)playHours;
    }
    GAME_BEACON_UpdateActionTime(&work->own);
    for (i = 0; i < 30; i++) {
        if (work->log[i].info.versionBit != 0) {
            if (work->log[i].elapsed.receivedFrames < 0xffff) {
                work->log[i].elapsed.receivedFrames += 1;
            }
        }
    }
}












void GAME_BEACON_Setup(struct GameData *gameData)
{
    GameBeaconWork *work = GAME_BEACON_Work;

    work->gameData = gameData;
    GAME_BEACON_BuildMyInfo(&work->own.info, gameData);
    GAME_BEACON_Work->lastPlayHours = func_0200864C(GAME_DATA_GetPlayTime(gameData));
}












void GAME_BEACON_GetMyInfo(GameBeaconInfo *dst)
{
    MI_CpuCopy8(&GAME_BEACON_Work->own.info, dst, sizeof(GameBeaconInfo));
}












void GAME_BEACON_SendIfRequested(void)
{
    if (GAME_BEACON_Work->own.sendRequest == 1) {
        if (GFL_NET_GetRunState() == 1) {
            func_0217778C();
            GAME_BEACON_Work->own.sendRequest = 0;
        }
    }
}












void GAME_BEACON_UpdateActionTime(GameBeaconRecord *own)
{
    u16 action = own->info.action;

    if (action == 1) {
        return;
    }
    own->elapsed.actionFrames += 1;
    if ((u32)own->elapsed.actionFrames > GAME_BEACON_ActionTable[action].frames) {
        own->elapsed.actionFrames = 0;
        own->info.action = 1;
    }
}











static inline u32 GAME_BEACON_GetAnswer(const GameBeaconInfo *info, int questionId)
{
    u32 answer;

    if (questionId == 0x1d) {
        answer = info->playHours / 10 + 1;
        if (answer > func_02167394(questionId))
            answer = func_02167394(questionId);
    } else {
        answer = func_0200E3A4(info->questionnaire, questionId);
    }
    return answer;
}










/*
 * The ring insert: advance hi with a wrap at 30 (pushing lo along when the
 * ring is full), grant the record's items through the bag (0x0200E394
 * family), mark matching entries in the 0x0200C0F0 table, then clear the
 * slot, struct-copy the 92-byte payload in, zero +0x5c, set the live bit
 * and bump the +0xBAE fill count.
 *
 * `bl 0x02167394` sites are the only references to that address in the
 * whole image, all inside this range, and no overlay listing labels a
 * function there (ov009 and ov010 both cover the address, interior to
 * code), so no class attests it and no cut helps (--suggest-split).
 *
 * Two spellings the bytes need: the item-amount helper takes an INT id
 * (the `cmp r,#0x1d` is on the untruncated value; the callees' u8
 * parameters produce the lsls/lsrs at each call), and the slot is one
 * pointer `&slots[hi]` which the compiler keeps as base+0x64 and
 * hi*0x60 in two stack slots.
 */
void GAME_BEACON_AddLog(GameBeaconWork *work, const GameBeaconInfo *info)
{
    struct QuestionnaireSave *questionnaire;
    struct SaveControl *save;
    struct QuestionnaireSave *researchQuestionnaire;
    struct MiscSave *misc;
    int i;
    int j;
    int questionId;
    u32 answer;
    GameBeaconRecord *record;

    work->newestIndex++;
    if (work->newestIndex >= 30)
        work->newestIndex = 0;
    record = &work->log[work->newestIndex];
    if (work->logCount > 0 && work->newestIndex == work->oldestIndex) {
        work->oldestIndex++;
        if (work->oldestIndex >= 30)
            work->oldestIndex = 0;
    }
    questionnaire = func_0200E394(GAME_DATA_GetSaveControl(work->gameData));
    for (i = 0; i < 3; i++) {
        questionId = func_0200E44C(questionnaire, i);
        if (questionId != 0xff) {
            answer = GAME_BEACON_GetAnswer(info, questionId);
            if (answer != 0 && func_0200E49C(questionnaire, questionId, answer) == 0) {
                func_0200E460(questionnaire, questionId, 1);
                func_0200E4CC(questionnaire, questionId, answer, 1);
                work->questionnaireUpdated = 1;
            }
        }
    }
    save = GAME_DATA_GetSaveControl(work->gameData);
    researchQuestionnaire = func_0200E394(save);
    misc = func_0200C0F0(save);
    for (i = 0; i < 3; i++) {
        questionId = func_0200C33C(misc, i);
        if (questionId != 0xff) {
            for (j = 0; j < 3; j++) {
                if (questionId == func_0200E44C(researchQuestionnaire, j)) {
                    if (GAME_BEACON_GetAnswer(info, questionId) != 0)
                        func_0200C364(misc, i, 1);
                }
            }
        }
    }
    MI_CpuFill8(record, 0, sizeof(GameBeaconRecord));
    record->info = *info;
    record->elapsed.receivedFrames = 0;
    work->newMask |= 1 << work->newestIndex;
    if (work->logCount < 30)
        work->logCount++;
}














/*
 * The duplicate/accept scan over the receive ring.  Closed 2026-09-23 by
 * writing the ring walk as the plain two-case shape: `if (lo <= hi)` one
 * loop over lo..hi, `else` a loop over lo..29 THEN a loop over 0..hi, each
 * hit doing `hit = 1; break;`.  The compiler itself cross-jumps loop 3's hit
 * block into loop 1's (both continue at the tail) and keeps loop 2's, whose
 * break lands on loop 3's `i = 0`; the earlier goto/label construction in
 * docs/notes/GAME_BEACON_ReceiveInfo.c.txt only imitated that and left a duplicated
 * `blt`.  EXACT* because the follower at 0x02026BFC has no label.
 */
int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    int hit = 0;
    int i;
    u16 action;
    signed char newest;
    signed char oldest;

    if ((info->versionBit & 2) == 0) {
        return hit;
    }
    action = info->action;
    if (action == 0 || action >= 0x33) {
        return 0;
    }
    if (action == 0x18) {
        if (work->own.info.trainerId != info->actionData.special.targetTrainerId) {
            return hit;
        }
    }
    newest = work->newestIndex;
    oldest = work->oldestIndex;
    if (oldest <= newest) {
        for (i = oldest; i <= newest; i++) {
            if (info->trainerId == work->log[i].info.trainerId) {
                if (action == 1 || info->serialNo == work->log[i].info.serialNo) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    } else {
        for (i = oldest; i < 30; i++) {
            if (info->trainerId == work->log[i].info.trainerId) {
                if (action == 1 || info->serialNo == work->log[i].info.serialNo) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
        for (i = 0; i <= newest; i++) {
            if (info->trainerId == work->log[i].info.trainerId) {
                if (action == 1 || info->serialNo == work->log[i].info.serialNo) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    }
    if (action == 0x19) {
        if (info->actionData.special.eventKey != 0x2932013A) return 0;
    } else if (action == 0x1A) {
        if (info->actionData.special.eventKey != 0x48841DC1) return 0;
    } else if (action == 0x1B) {
        if (info->actionData.special.eventKey != 0x701DDC92) return 0;
    } else if (action == 0x32) {
        if (info->actionData.special.eventKey != 0xFEE48201) return 0;
    }
    if (hit == 1) {
        work->log[i].info = *info;
        work->log[i].elapsed.receivedFrames = 0;
        work->newMask |= (u32)(1 << i);
    } else {
        GAME_BEACON_AddLog(work, info);
        work->receiveCount = work->receiveCount + 1;
    }
    return 1;
}
















/*
 * Five unlabelled leaves between GAME_BEACON_ReceiveInfo and GAME_BEACON_GetNextNewLogIndex
 * (0x02026BFC..0x02026CA0), tu-verified: two ring-slot accessors, their
 * GAME_BEACON_Work tail-call wrappers, and the +0xBA8 count getter.
 *   GAME_BEACON_GetLogFromWork  slot n of the ring if n is below the s8 at +0xBAE
 *   GAME_BEACON_GetLog  GAME_BEACON_GetLogFromWork(GAME_BEACON_Work, n)
 *   GAME_BEACON_GetLogByReceiveNoFromWork  the slot n records back from the hi cursor, wrapped at 30;
 *                 the zero test on count - n is `c - n == 0` (a `subs`),
 *                 not `c == n` (a `cmp`)
 *   GAME_BEACON_GetLogByReceiveNo  GAME_BEACON_GetLogByReceiveNoFromWork(GAME_BEACON_Work, n)
 *   GAME_BEACON_GetReceiveCount  the +0xBA8 insert count
 * None has an lr save, so the integrator should seed all five starts.
 */
GameBeaconRecord *GAME_BEACON_GetLogFromWork(GameBeaconWork *work, int index)
{
    int count = work->logCount;
    if (count == 0 || count - index <= 0)
        return 0;
    return &work->log[index];
}
















GameBeaconRecord *GAME_BEACON_GetLog(int index)
{
    return GAME_BEACON_GetLogFromWork(GAME_BEACON_Work, index);
}
















GameBeaconRecord *GAME_BEACON_GetLogByReceiveNoFromWork(GameBeaconWork *work, int receiveNo)
{
    u32 count = work->receiveCount;
    int index;
    if (count == 0 || count - receiveNo == 0)
        return 0;
    index = work->newestIndex - (int)(count - 1 - receiveNo);
    if ((index < 0 ? -index : index) >= 30)
        return 0;
    if (index < 0)
        index += 30;
    return &work->log[index];
}
















GameBeaconRecord *GAME_BEACON_GetLogByReceiveNo(int receiveNo)
{
    return GAME_BEACON_GetLogByReceiveNoFromWork(GAME_BEACON_Work, receiveNo);
}
















u32 GAME_BEACON_GetReceiveCount(void)
{
    return GAME_BEACON_Work->receiveCount;
}
















int GAME_BEACON_GetNextNewLogIndex(int *cursor)
{
    int index = *cursor;
    while (index < 30) {
        if (GAME_BEACON_Work->newMask & (1 << index)) {
            *cursor = *cursor + 1;
            return *cursor - 1;
        }
        index = *cursor + 1;
        *cursor = index;
    }
    return 30;
}














/*
 * Clears bit `n` of the ring live mask at +0xba4 of the game beacon block.
 * The earlier MATCH park read the pool word as 0x02021440; the word at
 * 0x02026CFC is 0x02146940, GAME_BEACON_Work, attested by 77 other pools.
 * EXACT* because the follower at 0x02026D04 is an unlabelled leaf.
 */
void GAME_BEACON_ClearNewFlag(u32 index)
{
    GAME_BEACON_Work->newMask = ((1 << index) ^ 0xffffffff) & GAME_BEACON_Work->newMask;
}













/*
 * Finds the ring slot whose +0x10 id equals the record's, sets its live-mask
 * bit and answers 1; 0 when none does.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D04 into
 * layout/function_starts.txt.
 */
int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    int i;
    for (i = 0; i < 30; i++) {
        if (info->trainerId == work->log[i].info.trainerId) {
            work->newMask |= 1 << i;
            return 1;
        }
    }
    return 0;
}













/*
 * Answers the +0x5c halfword of the first live ring slot whose +0x10 id
 * equals v, or 0xffff.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D48 into
 * layout/function_starts.txt.
 */
u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 trainerId)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    int i;
    for (i = 0; i < 30; i++) {
        if (work->log[i].info.versionBit != 0 && work->log[i].info.trainerId == trainerId)
            return work->log[i].elapsed.receivedFrames;
    }
    return 0xffff;
}













/*
 * The own-beacon builder: fills a GameBeaconInfo from the player profile, the
 * save blocks and the DS owner info.  Layout it proves beyond the family
 * header: word +0 is four BYTES (+0 = 0xff, +1/+2 from 0x0200856C and
 * 0x02008570, +3 split 7:1 as u8 bitfields -- strb/ldrb, not word RMW);
 * word +0xC is 6:3:3:4:10:6 (bits 0..5 = 0x15, 6..8 from 0x02008554,
 * 9..11 from 0x0200C224, 12..15 the owner's favoriteColor, then the
 * trainer and top fields); +0x12 is seven halfwords filled like +0x20;
 * +0x50 takes ten bytes via MI_CpuCopy8; the scratch at sp+0x14 is the
 * 0x54-byte OSOwnerInfo.  Levers that mattered: stack order (save, tbl,
 * bag declared in that order) and func_02008550 answering a word that is
 * narrowed with an explicit (u8) before the 1-bit store.
 */
void GAME_BEACON_BuildMyInfo(GameBeaconInfo *info, struct GameData *gameData)
{
    struct SaveControl *save;
    struct MiscSave *misc;
    struct PmsSave *pmsSave;
    struct MyStatus *myStatus;
    struct PlayTime *playTime;
    GameBeaconPms pms;
    OSOwnerInfo ownerInfo;
    u16 *codes;
    u16 eomCode;
    int i;

    myStatus = func_02012944(gameData);
    save = GAME_DATA_GetSaveControl(gameData);
    misc = func_0200C0F0(save);
    pmsSave = func_0200E6E8(save);
    OS_GetOwnerInfo(&ownerInfo);
    info->versionBit = 0xff;
    info->zoneId = func_02012AC8(func_020127A4(gameData));
    if (func_02013CC8(info->zoneId) == 1 || func_02013CE0(info->zoneId) == 1) {
        info->zoneId = func_02012894(gameData)->zoneId;
    }
    info->townmapRootZoneId = SYMBOL_MAP_ResolveZoneId(gameData, (u16)info->zoneId);
    info->infoVersion = 0x30;
    info->trainerId = func_02008534(myStatus);
    info->favoriteColor = ownerInfo.favoriteColor;
    info->sex = (u8)func_02008550(myStatus);
    if (info->sex == 0) {
        info->trainerView = func_02008554(myStatus);
    } else {
        info->trainerView = func_02008554(myStatus) - 8;
    }
    info->pmVersion = 0x15;
    info->language = 2;
    info->nation = func_0200856C(myStatus);
    info->area = func_02008570(myStatus);
    info->researchTeamRank = func_0200C224(misc);
    info->passCount = func_0200C1C4(misc);
    info->thanksCount = func_0200C1DC(misc);
    playTime = GAME_DATA_GetPlayTime(gameData);
    info->playHours = func_0200864C(playTime);
    info->playMinutes = func_02008650(playTime);
    MI_CpuCopy8(func_0200E3A0(func_0200E394(save)), info->questionnaire, sizeof(info->questionnaire));
    func_0200E6FC(pmsSave, 0, &pms);
    GAME_BEACON_SetMyPms(&pms);
    eomCode = STRBUF_GetEosChar();
    codes = func_020084F4(myStatus);
    for (i = 0; i < 7; i++) {
        info->name[i] = codes[i];
        if (eomCode == codes[i])
            break;
    }
    codes = func_0200C1F4(misc);
    for (i = 0; i < 8; i++) {
        info->greeting[i] = codes[i];
        if (eomCode == codes[i])
            break;
    }
    GAME_BEACON_ResetDetails(info);
    info->action = 0;
}


















void GAME_BEACON_RequestSend(GameBeaconRecord *record)
{
    struct SaveControl *save;
    struct PlayTime *playTime;
    struct MiscSave *misc;

    save = GAME_DATA_GetSaveControl(GAME_BEACON_Work->gameData);
    playTime = GAME_DATA_GetPlayTime(GAME_BEACON_Work->gameData);
    misc = func_0200C0F0(save);
    record->info.playHours = func_0200864C(playTime);
    record->info.playMinutes = func_02008650(playTime);
    record->info.passCount = func_0200C1C4(misc);
    record->info.thanksCount = func_0200C1DC(misc);
    record->info.serialNo = record->info.serialNo + 1;
    record->elapsed.actionFrames = 0;
    record->sendRequest = 1;
}


















/*
 * The priority gate: answers 1 when id `a`'s priority is at least that of
 * the current mode at +0x34 of the block.  The table at 0x0209FC20 is a
 * word of BITFIELDS, { prio : 8; frames : 24; } -- GAME_BEACON_UpdateActionTime reads the
 * same word `>> 8`.  Spelled as `(u8)tbl[i]` on a u32 array the compiler
 * ties the lsrs order to the cmp order and stays 4 bytes out (see
 * docs/notes/pkt_02027060.GAME_BEACON_CheckActionPriority.c.txt); the bitfield read frees
 * the schedule.  Also EXACT under ../2.0/sp2.
 */
u32 GAME_BEACON_CheckActionPriority(u32 action)
{
    if (GAME_BEACON_ActionTable[action].priority >= GAME_BEACON_ActionTable[GAME_BEACON_Work->own.info.action].priority)
        return 1;
    return 0;
}


















int GAME_BEACON_IsSpecialPokemon(u16 monsNo)
{
    u32 i = 0;

    while (i < 14) {
        if (monsNo == GAME_BEACON_SpecialPokemonTable[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}


















void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest)
{
    u16 codes[12];
    u16 eomCode;
    int i;

    eomCode = STRBUF_GetEosChar();
    STRBUF_ToChars(str, codes, 12);
    for (i = 0; i < 10; i++) {
        dest[i] = codes[i];
        if (eomCode == codes[i]) {
            break;
        }
    }
}


















u8 GAME_BEACON_PopQuestionnaireUpdated(void)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    u8 updated;

    if (work == 0) {
        return 0;
    }
    updated = work->questionnaireUpdated;
    work->questionnaireUpdated = 0;
    return updated;
}


















void GAME_BEACON_SetQuestionnaire(const u8 *answers)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    MI_CpuCopy8(answers, own->info.questionnaire, sizeof(own->info.questionnaire));
    own->sendRequest = 1;
}
















/*
 * 20 bytes. Stores two bytes at +5 and +6 of the block that GAME_BEACON_Work points
 * to and sets the flag byte at +0x62 (reached as +4 then +0x5E: a nested
 * record at +4, written through a pointer local `q = &s->sub`; direct
 * `s->sub.flag` folds to +0x62). Filed in wave D6 as the unlabelled leaf that ov219
 * func_02183D14 calls.
 */
void GAME_BEACON_SetNationArea(u8 nation, u8 area)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    own->info.nation = nation;
    own->info.area = area;
    own->sendRequest = 1;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (9..11) into
 * the word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * The inner-object pointer is what pins the two-step `adds r0, r1, #4` /
 * `adds r0, #0x5e` address form (see GAME_BEACON_SetPms).
 *
 * Addresses are Black-image addresses.
 */
void GAME_BEACON_SetResearchTeamRank(u32 rank)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    own->info.researchTeamRank = rank;
    own->sendRequest = 1;
}














/*
 * EXACT*: the listing extent runs 60 bytes to the next label; only the
 * first 24 bytes belong to this function (the follower at 0x02027174 is
 * an unlabelled leaf).
 *
 * The original splits the address arithmetic into `adds r0, r4, #4` then
 * `adds r0, #0x5e`, which a flat `*(u8 *)(p + 0x62)` folds into one
 * `adds r4, #0x62`.  Taking a pointer to a NESTED struct member (the
 * inner object starts at +4) before the call is what pins the two-step
 * form: `&g->own` is its own value, materialised at +0x0A, and the field
 * offset is added separately at +0x0E.
 */
void GAME_BEACON_SetPms(const GameBeaconPms *pms)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    GAME_BEACON_SetMyPms(pms);
    own->sendRequest = 1;
}













/*
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (6..8) into the
 * word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * Pairs with GAME_BEACON_SetResearchTeamRank; the inner-object pointer pins the two-step
 * address form (see GAME_BEACON_SetPms).
 *
 * Addresses are Black-image addresses.
 */
void GAME_BEACON_SetTrainerView(u32 trainerView)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    own->info.trainerView = trainerView;
    own->sendRequest = 1;
}













void GAME_BEACON_UpdateGreeting(void)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    GameBeaconRecord *own;
    u16 *codes;
    u32 eomCode;
    struct MiscSave *misc;
    int i;

    own = &work->own;
    misc = func_0200C0F0(GAME_DATA_GetSaveControl(work->gameData));
    eomCode = STRBUF_GetEosChar();
    codes = func_0200C1F4(misc);
    for (i = 0; i < 8; i++) {
        own->info.greeting[i] = codes[i];
        if (codes[i] == eomCode) {
            break;
        }
    }
    own->sendRequest = 1;
}












void GAME_BEACON_SetPokeCapture(u16 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        GAME_BEACON_SetSpecialPokeGet(monsNo);
    } else {
        GAME_BEACON_SetPokeGet(monsNo);
    }
}














static void GAME_BEACON_WritePokeGet(GameBeaconRecord *own, u16 monsNo);














/*
 * A whole translation unit, matched as one byte range.
 *
 *           GAME_BEACON_SetPokeLevelUp, sub_02027290, GAME_BEACON_SetPokeEvolution, sub_020272D0,
 *           GAME_BEACON_SetPlayTime, sub_02027314, GAME_BEACON_SetItemUse, sub_0202734C
 *
 * Six checker/writer pairs, one per beacon action (0xe pokemon caught,
 * 0xf special pokemon caught, 0x10 level up, 0x11 evolution, 0x14 play
 * time, 0x23 item used), all writing the console's own beacon record.
 * Every checker asks GAME_BEACON_CheckActionPriority(action) (the priority gate against the
 * action now shown) whether the action may replace it, and if so writes
 * the action through the matching static writer and hands the record to
 * GAME_BEACON_RequestSend, which refreshes the counters and requests a send.
 *
 * The record address is written out twice, `&GAME_BEACON_Work->own`, once for
 * the writer and once for the send: the global is re-read across the
 * writer call.  (An earlier version reached this only with a second,
 * volatile name for the global; the plain repeated expression gives the
 * same bytes.)
 *
 * The writers store the action number at +0x30 and, for 0xe, 0xf, 0x14
 * and 0x23, one 16-bit argument at +0x32 or +0x34, then tail-call
 * GAME_BEACON_ResetDetails (details type back to 5).  The 0x10 writer instead
 * tail-calls GAME_BEACON_CopyStrbufCodes(nickname, +0x34) and skips GAME_BEACON_ResetDetails; the
 * 0x11 writer does both.  The nickname argument is declared u16 although
 * it is a string pointer; the caller's narrowing is in the bytes, so the
 * cast stays.  The play time setter takes a u32: GAME_BEACON_Update passes its
 * s32 without narrowing.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020271F8.c \
 *       --addr 0x020271F8 --thumb
 */
void GAME_BEACON_SetPokeGet(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0xe)) {
        GAME_BEACON_WritePokeGet(&GAME_BEACON_Work->own, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}














static void GAME_BEACON_WritePokeGet(GameBeaconRecord *own, u16 monsNo)
{
    own->info.action = 0xe;
    own->info.actionArg = monsNo;
    GAME_BEACON_ResetDetails(&own->info);
}














static void GAME_BEACON_WriteSpecialPokeGet(GameBeaconRecord *own, u16 monsNo);














void GAME_BEACON_SetSpecialPokeGet(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0xf)) {
        GAME_BEACON_WriteSpecialPokeGet(&GAME_BEACON_Work->own, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}














static void GAME_BEACON_WriteSpecialPokeGet(GameBeaconRecord *own, u16 monsNo)
{
    own->info.action = 0xf;
    own->info.actionArg = monsNo;
    GAME_BEACON_ResetDetails(&own->info);
}














static void GAME_BEACON_WritePokeLevelUp(GameBeaconRecord *own, u16 nickname);














void GAME_BEACON_SetPokeLevelUp(u16 nickname)
{
    if (GAME_BEACON_CheckActionPriority(0x10)) {
        GAME_BEACON_WritePokeLevelUp(&GAME_BEACON_Work->own, nickname);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}














static void GAME_BEACON_WritePokeLevelUp(GameBeaconRecord *own, u16 nickname)
{
    own->info.action = 0x10;
    GAME_BEACON_CopyStrbufCodes((const struct Strbuf *)nickname, own->info.actionData.nickname);
}














static void GAME_BEACON_WritePokeEvolution(GameBeaconRecord *own, u16 monsNo, u16 nickname);














void GAME_BEACON_SetPokeEvolution(u16 monsNo, u16 nickname)
{
    if (GAME_BEACON_CheckActionPriority(0x11)) {
        GAME_BEACON_WritePokeEvolution(&GAME_BEACON_Work->own, monsNo, nickname);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}














static void GAME_BEACON_WritePokeEvolution(GameBeaconRecord *own, u16 monsNo, u16 nickname)
{
    own->info.action = 0x11;
    own->info.actionArg = monsNo;
    GAME_BEACON_CopyStrbufCodes((const struct Strbuf *)nickname, own->info.actionData.nickname);
    GAME_BEACON_ResetDetails(&own->info);
}














static void GAME_BEACON_WritePlayTime(GameBeaconRecord *own, u32 playHours);














void GAME_BEACON_SetPlayTime(u32 playHours)
{
    if (GAME_BEACON_CheckActionPriority(0x14)) {
        GAME_BEACON_WritePlayTime(&GAME_BEACON_Work->own, playHours);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}














static void GAME_BEACON_WritePlayTime(GameBeaconRecord *own, u32 playHours)
{
    own->info.action = 0x14;
    own->info.actionData.value = playHours;
    GAME_BEACON_ResetDetails(&own->info);
}














static void GAME_BEACON_WriteItemUse(GameBeaconRecord *own, u16 itemNo);














void GAME_BEACON_SetItemUse(u16 itemNo)
{
    if (GAME_BEACON_CheckActionPriority(0x23)) {
        GAME_BEACON_WriteItemUse(&GAME_BEACON_Work->own, itemNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}














static void GAME_BEACON_WriteItemUse(GameBeaconRecord *own, u16 itemNo)
{
    own->info.action = 0x23;
    own->info.actionData.value = itemNo;
    GAME_BEACON_ResetDetails(&own->info);
}














void GAME_BEACON_SetZone(u32 zoneId, u32 zoneSource)
{
    GAME_BEACON_SetInfoZone(&GAME_BEACON_Work->own.info, zoneId, zoneSource);
    GAME_BEACON_Work->own.sendRequest = 1;
}














void GAME_BEACON_SetInfoZone(GameBeaconInfo *info, u32 zoneId, u32 zoneSource)
{
    info->zoneId = zoneId;
    info->townmapRootZoneId = SYMBOL_MAP_ResolveZoneId(zoneSource);
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 5;
    GAME_BEACON_ResetDetails(info);
}














/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u16 monsNo)
{
    info->detailsPms.bits.detailsType = 0;
    info->detailsValue = monsNo;
}














void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u16 monsNo)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 1;
    info->detailsValue = monsNo;
}














void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u16 trainerId)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 2;
    info->detailsValue = trainerId;
}














void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u16 trainerId)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 3;
    info->detailsValue = trainerId;
}














void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u16 trainerId)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 4;
    info->detailsValue = trainerId;
}














/*
 * Sets the low byte of the halfword at +0x48 of its argument to the
 * constant 5, leaving the high byte untouched. Called from every
 * trampoline of src/matched/unit_020271F8.c as a shared "mark this event
 * object pending" step, independent of which event id was just written.
 *
 * `disasm.py` measures this function's extent to the next label at
 * 0x020274B4, 104 bytes away, but only the first 20 bytes belong to it;
 * what follows is a second, unlabelled function (the same
 * "half the accessors are printed as .word data" gap
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md describes)
 * that packs several bitfields of the same object from a small argument
 * struct. It is out of scope for this file and still open. The mismatched
 * extent is why this entry is EXACT* rather than EXACT.
 *
 * Writing the mask as `~0xffu` rather than building 0xff00 directly is
 * what keeps the mask in the `movs r1, #0xff` / `bics r2, r1` shape the
 * original uses; the equivalent `& 0xff00` immediate has no Thumb
 * encoding and this compiler rematerialises it as `lsls`/`ands` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_BEACON_ResetDetails.c \
 *       --func GAME_BEACON_ResetDetails --addr 0x0202744C --cc 1.1p1 --thumb
 */
void GAME_BEACON_ResetDetails(GameBeaconInfo *info)
{
    u16 word = info->detailsPms.word;
    word = (word & ~0xffu) | 5;
    info->detailsPms.word = word;
}














/*
 * Copies four halfwords into the console's own beacon record (+4 of the
 * block): two BITFIELDS of the u16 at rec+0x48 (bits 8..10 and 11..15,
 * masks 0xF8FF / 0x07FF, the low byte being the one GAME_BEACON_ResetDetails sets),
 * then rec+0x4a and rec+0x4c.  The caller GAME_BEACON_SetMyPms passes &own in r0
 * but this body ignores it and recomputes; the two-step `adds r,r0,#4;
 * adds r,#0x48` at every access is a pointer local `o = &g->own`, not a
 * held `g` (which folds to one `adds #0x4c`).
 * Unlabelled leaf (no lr save): the integrator should seed 0x02027460.
 */
void GAME_BEACON_WritePms(GameBeaconInfo *info, const GameBeaconPms *pms)
{
    GameBeaconInfo *own = &GAME_BEACON_Work->own.info;

    own->detailsPms.bits.pmsSentenceType = pms->sentenceType;
    own->detailsPms.bits.pmsSentenceId = pms->sentenceId;
    own->pmsWord[0] = pms->word[0];
    own->pmsWord[1] = pms->word[1];
}













void GAME_BEACON_SetMyPms(const GameBeaconPms *pms)
{
    GAME_BEACON_WritePms(&GAME_BEACON_Work->own.info, pms);
}













/*
 * note:     wave 17 (overlay_id class): EXACT*. The pooled overlay-id site
 *           ov231_id (231) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * The ABS32 pool word 0x000000E7 is an absolute overlay-id symbol (ov231,
 * matching the bl into func_021809D8 in asm/overlays/ov231.s), per
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * EXACT* because the listing extent (84 bytes) runs over the follower
 * GAME_BEACON_ClearFlags.
 */
void GAME_BEACON_RegisterClearCallback(void)
{
    int result;

    func_02034AC4((int)ov231_id);
    result = func_021809D8();
    func_02034A5C((int)ov231_id);
    if (result == 0) {
        func_02005624(GAME_BEACON_ClearFlags, 0, 3);
    }
}














void GAME_BEACON_ClearFlags(void)
{
    if (GAME_BEACON_Work != 0) {
        GAME_BEACON_Work->newMask = 0;
        GAME_BEACON_Work->own.sendRequest = 0;
        GAME_BEACON_Work->newMask = 0;
    }
}
