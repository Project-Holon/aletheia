/*
 * file:     delivery_irc.c
 * unit:     yes
 * function: DELIVERY_IRC_SetStep, DELIVERY_IRC_SetStepAtLine, DELIVERY_IRC_StepIdle, DELIVERY_IRC_RecvCrc, DELIVERY_IRC_RecvRequest, DELIVERY_IRC_RecvNotFound, DELIVERY_IRC_GetRecvBuffer, DELIVERY_IRC_StepEnd, DELIVERY_IRC_StepFinish, DELIVERY_IRC_StepExitParent, DELIVERY_IRC_StepExitChild, DELIVERY_IRC_StepWaitEndSync, DELIVERY_IRC_StepStartEndSync, DELIVERY_IRC_StepSendData, DELIVERY_IRC_StepSendCrc, DELIVERY_IRC_StepSearchEntry, DELIVERY_IRC_StepSendRequest, DELIVERY_IRC_StepWaitConnect, DELIVERY_IRC_StepStartChangeover, DELIVERY_IRC_StepWaitInit, DELIVERY_IRC_Create, DELIVERY_IRC_StartNet, DELIVERY_IRC_Start, DELIVERY_IRC_GetResult, DELIVERY_IRC_Main, DELIVERY_IRC_Delete, MYSTERY_GIFT_CreateMon, INTRUDE_COMM_CheckEntryAllowed, INTRUDE_COMM_GetWorkIfRunning, INTRUDE_COMM_GetPlayerNetId, INTRUDE_COMM_TogglePeerFlags, GAME_DATA_GetBattleRecSlotByNetId, GAME_DATA_GetMyStatusByNetId, INTRUDE_COMM_GetMemberEntry, GAME_DATA_GetIntrudeIdByte, INTRUDE_COMM_GetUnionInfoReceived, INTRUDE_COMM_GetReturnSlots, INTRUDE_COMM_GetAreaOwnerVersion, INTRUDE_COMM_GetAreaSlotFlag, INTRUDE_COMM_IsStepToOwnArea, INTRUDE_COMM_NormalizeVersion, INTRUDE_COMM_GetAreaOwnerVersionClass, INTRUDE_COMM_IsListedId, INTRUDE_COMM_HasUnlockFlags, INTRUDE_COMM_IsWarnedWithoutRequest, INTRUDE_COMM_GetVisitProgress, INTRUDE_COMM_SetCompleted, INTRUDE_COMM_GetRequestState, INTRUDE_COMM_CountEventPeers, INTRUDE_COMM_GetRequesterStatus, INTRUDE_COMM_IsSessionEndPending, INTRUDE_COMM_ClearHoldMode
 * address:  0x02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Original file delivery_irc.c (IR delivery of mystery gifts): the create
 * function asserts with "delivery_irc.c". It starts in delivery_beacon.c, whose
 * last function 0x02157948 already uses the delivery IR work, and those two
 * pieces merge at cut time.
 *
 * 0x02157E9C..0x0215874C (gift Pokemon builder, then intrude and game comm
 * helpers) have no file anchor. Their rodata (0x02170068, 0x021700A8,
 * 0x021700AC) lies before the script_sys.c rodata, in the run the tool assigns to
 * delivery_irc.c, and no evidence splits them off, so they stay here for now.
 * They may be one or two separate original files placed between delivery_irc.c
 * and script_sys.c.
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   func_0203F328  0x0203F328  arm
 *   IRCNET_IsLinkAlive 0x02179D3C thumb ov015
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   IRCNET_SetTimeoutLimit  0x0217998C  thumb ov015
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   func_020056EC  0x020056EC  thumb
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   func_02030734 0x02030734 arm
 *   d_02172878 0x02172878 data a1
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 *   func_020307B0  0x020307B0  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetDefaultMoves  0x02017FA8  thumb
 *   POKE_TOOL_AddMove  0x0201808C  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   func_0202F2AC  0x0202F2AC  thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   sGiftRibbonIds     0x02170068  data
 *   GAME_VERSION_Code     0x0209DF08  data  a1
 *   GAME_LANGUAGE_Code     0x0209DF0C  data  a1
 *   gSpeciesNameBank     0x020A7370  data
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetLastBattleRecSlot   0x020127B8  thumb
 *   GAME_DATA_GetBattleRecSlot   0x020127AC  thumb
 *   GAME_DATA_GetPlayerStatus   0x02012950  thumb
 *   GAME_DATA_GetIntrudeId   0x02012B80  thumb
 *   func_0200855C 0x0200855C thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetSlotFlag  0x02012B98  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   sIntrudeListedIds 0x021700AC data a2
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   sIntrudeUnlockFlags 0x021700A8 data a2
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb
 *   INTRUDE_COMM_IsRequestFromSelf  0x02176258  thumb
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb
 *   func_02008500  0x02008500  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 */
struct Entry;
struct Link;
struct Req;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct DeliveryIrcEntry {
    u32 size;               /* 0x00 */
    void *data;             /* 0x04 */
    u32 id;                 /* 0x08 */
    u32 mask;               /* 0x0C */
} DeliveryIrcEntry;

typedef struct DeliveryIrcWork DeliveryIrcWork;
typedef void (*DeliveryIrcStepFunc)(DeliveryIrcWork *work);

/* 8-byte message (command +1): the parent's encryption key and data CRC */
typedef struct DeliveryIrcKeyMsg {
    u32 cryptKey;           /* 0x00 */
    u16 crc;                /* 0x04 */
} DeliveryIrcKeyMsg;

/* 8-byte message (command +2): the child asks for the gift with this id and mask */
typedef struct DeliveryIrcRequest {
    u32 id;                 /* 0x00 */
    u32 mask;               /* 0x04 */
} DeliveryIrcRequest;

/* 0x7C-byte parameter block copied in by DELIVERY_IRC_Create */
typedef struct DeliveryIrcParam {
    u32 netCommandBase;     /* 0x00: command id high byte and timing sync number */
    u16 reserved;           /* 0x04 */
    u16 heapId;             /* 0x06 */
    DeliveryIrcEntry entries[7]; /* 0x08 */
    u32 entryCount;         /* 0x78 */
} DeliveryIrcParam;

struct DeliveryIrcWork {
    DeliveryIrcParam param;     /* 0x000 */
    u8 recvBuffer[0x5E8];       /* 0x07C */
    DeliveryIrcEntry *sendEntry; /* 0x664 */
    u32 cryptKey;               /* 0x668 */
    int notFound;               /* 0x66C */
    u16 ackFlag;                /* 0x670 */
    u16 crc;                    /* 0x672 */
    u8 result;                  /* 0x674 */
    u8 isParent;                /* 0x675 */
    u8 found;                   /* 0x676 */
    u8 foundIndex;              /* 0x677 */
    DeliveryIrcStepFunc step;   /* 0x678 */
    DeliveryIrcRequest request; /* 0x67C */
};

typedef signed char s8;

typedef short s16;

typedef int s32;

typedef unsigned long long u64;

#include "../ov011/intrude_comm_types.h"

/* Opaque here: only the accessors in arm9 game_beacon.c and game_data.c read these. */
typedef struct GameComm GameComm;
struct GameSystem;
struct GameData;
struct MyStatus;
struct PokemonParam;
struct StrBank;
struct EventWork;
struct BattleRecSlot;

/*
 * Mystery gift Pokemon record (0xB4 bytes). The three Pokemon values at
 * 0x46, 0x47 and 0x48 are named by the slot they take in the packed IV word
 * (speed fourth, special attack fifth, special defense sixth).
 */
typedef struct GiftMon {
    u32 otId;               /* 0x00: 0 = the player's own trainer ID */
    u32 originGame;         /* 0x04: 0 = the running game's version */
    u32 pid;                /* 0x08: 0 = derived from pidType */
    u16 ribbons;            /* 0x0C: bit k set = ribbon sGiftRibbonIds[k] */
    u16 ball;               /* 0x0E: 0 or above 0x19 = ball 4 */
    u16 item;               /* 0x10 */
    u16 moves[4];           /* 0x12 */
    u16 species;            /* 0x1A */
    u8 form;                /* 0x1C */
    u8 language;            /* 0x1D: 0 = the running game's language */
    u16 nickname[11];       /* 0x1E: first char 0 = invalid, EOS = default name */
    u8 nature;              /* 0x34: 0xFF = random */
    u8 gender;              /* 0x35: 0xFF = random (stored as 2) */
    u8 abilityKind;         /* 0x36: 0, 1, 2 (hidden), 3, 4 = random */
    u8 pidType;             /* 0x37 */
    u16 eggLocation;        /* 0x38 */
    u16 metLocation;        /* 0x3A */
    u8 ballExtra;           /* 0x3C: nonzero = set as ball extra value */
    u8 contestStats[6];     /* 0x3D: cool, beauty, cute, smart, tough; entry 4 is also stored as sheen, entry 5 is unread */
    u8 ivHp;                /* 0x43 */
    u8 ivAttack;            /* 0x44 */
    u8 ivDefense;           /* 0x45 */
    u8 ivSlot5;             /* 0x46: packed sixth (special defense slot) */
    u8 ivSlot3;             /* 0x47: packed fourth (speed slot) */
    u8 ivSlot4;             /* 0x48: packed fifth (special attack slot) */
    u8 pad49;
    u16 otName[8];          /* 0x4A: first char EOS = the player's name */
    u8 otGender;            /* 0x5A: above 2 = the player's gender */
    u8 level;               /* 0x5B: 0 = random 1 to 100 */
    u8 isEgg;               /* 0x5C */
    u8 pad5D[0xAC - 0x5D];
    s32 receivedDate;       /* 0xAC: year in bits 16 to 31, month in 8 to 15, day in 0 to 7 */
    u8 padB0[3];
    u8 formatVersion;       /* 0xB3: must be 1 */
} GiftMon;

extern int GFL_NET_GetRunState(void);
extern void MI_CpuCopy8(void *, void *, u32);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern int IRCNET_IsLinkAlive(void);
extern int GFL_NET_Exit(int);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern u32 GFL_NET_IsParentAid(void);
extern void IRCNET_SetTimeoutLimit(int);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_020056EC(u32 range);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_StartChangeoverChild(int a0);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern int func_020307B0();
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern u32 func_02008530(const struct MyStatus *status);
extern const void *func_020084F4(const struct MyStatus *status);
extern void *POKE_TOOL_Create(u16 species, u16 level, u64 id, int heap);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *mon, u16 species, u16 level, unsigned long long id, u32 packedIvs, unsigned long long personalRnd);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_SetDefaultMoves(void *p);
extern u32 POKE_TOOL_AddMove(void *p, u32 move);
extern void POKE_TOOL_PushMove(void *p, int move);
extern void POKE_TOOL_SetAbility(void *p, u32 a, u32 b);
extern void *POKE_TOOL_Dummy(void *p);
extern void POKE_TOOL_RecalcParam(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u16 STRBUF_GetEosChar(void);
extern void *func_02045EC0(struct StrBank *bank, u32 index);
extern int STRBUF_Delete();
extern GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern int GAME_DATA_GetIntrudeCount(const struct GameData *gameData);
extern u32 GAME_COMM_GetCounter(GameComm *comm);
extern IntrudeCommSys *GAME_COMM_GetWork(GameComm *comm);
extern u32 func_0200FB24(void);
extern u32 GAME_COMM_GetKind(GameComm *comm);
extern u32 GAME_COMM_IsTransition(GameComm *comm);
extern struct GameData *GAME_COMM_GetGameData(GameComm *comm);
extern u8 GAME_DATA_GetExitMode(const struct GameData *gameData);
extern struct BattleRecSlot *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData);
extern struct BattleRecSlot *GAME_DATA_GetBattleRecSlot(struct GameData *gameData, u32 netId);
extern struct MyStatus *GAME_DATA_GetPlayerStatus(struct GameData *gameData, u32 netId);
extern u8 GAME_DATA_GetIntrudeId(const struct GameData *gameData);
extern u8 func_0200855C(const struct MyStatus *status);
extern u8 func_02008550(const struct MyStatus *status);
extern u8 GAME_DATA_GetSeason(const struct GameData *gameData);
extern u8 GAME_DATA_GetSlotFlag(const struct GameData *gameData, u32 slot);
extern void *GAME_DATA_GetMoveModelSys(const struct GameData *gameData);
extern u32 FIELD_STATUS_GetMapMode(void *fieldStatus);
extern struct EventWork *GAME_DATA_GetEventWork(const struct GameData *gameData);
extern u32 ZONEDATA_CheckEventFlag(struct EventWork *eventWork, int flag);
extern int INTRUDE_COMM_IsSessionActive(IntrudeSession *session);
extern int INTRUDE_COMM_IsRequestFromSelf(IntrudeCommSys *work);
extern int INTRUDE_COMM_GetRequesterNetId(IntrudeCommSys *work, IntrudeSession *session);
extern void func_02008500(const struct MyStatus *src, struct MyStatus *dst);
extern int GFL_NET_IsSessionNull(void);
void DELIVERY_IRC_SetStep(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line);
void DELIVERY_IRC_SetStepAtLine(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line);
void DELIVERY_IRC_StepIdle(void);
void DELIVERY_IRC_RecvCrc(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work);
void DELIVERY_IRC_RecvRequest(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work);
void DELIVERY_IRC_RecvNotFound(int netId, int size, const int *msg, DeliveryIrcWork *work);
u8 *DELIVERY_IRC_GetRecvBuffer(int netId, DeliveryIrcWork *work);
void DELIVERY_IRC_StepEnd(DeliveryIrcWork *work);
void DELIVERY_IRC_StepFinish(DeliveryIrcWork *work);
void DELIVERY_IRC_StepExitParent(DeliveryIrcWork *work);
void DELIVERY_IRC_StepExitChild(DeliveryIrcWork *work);
void DELIVERY_IRC_StepWaitEndSync(DeliveryIrcWork *work);
void DELIVERY_IRC_StepStartEndSync(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSendData(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSendCrc(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSearchEntry(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSendRequest(DeliveryIrcWork *work);
void DELIVERY_IRC_StepWaitConnect(DeliveryIrcWork *work);
void DELIVERY_IRC_StepStartChangeover(DeliveryIrcWork *work);
void DELIVERY_IRC_StepWaitInit(DeliveryIrcWork *work);
void *DELIVERY_IRC_Create(const DeliveryIrcParam *param);
int DELIVERY_IRC_StartNet(DeliveryIrcWork *work);
int DELIVERY_IRC_Start(DeliveryIrcWork *work);
unsigned char DELIVERY_IRC_GetResult(DeliveryIrcWork *work);
void DELIVERY_IRC_Main(DeliveryIrcWork *work);
int DELIVERY_IRC_Delete(DeliveryIrcWork *work);
struct PokemonParam *MYSTERY_GIFT_CreateMon(const GiftMon *gift, int heapId, struct GameData *gameData);
int INTRUDE_COMM_CheckEntryAllowed(struct GameSystem *gameSystem);
IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(GameComm *comm);
int INTRUDE_COMM_GetPlayerNetId(GameComm *comm);
int INTRUDE_COMM_TogglePeerFlags(IntrudeCommSys *work, int mask, int unused);
struct BattleRecSlot *GAME_DATA_GetBattleRecSlotByNetId(struct GameData *gameData, u32 netId);
struct MyStatus *GAME_DATA_GetMyStatusByNetId(struct GameData *gameData, u32 netId);
IntrudeMemberEntry *INTRUDE_COMM_GetMemberEntry(IntrudeCommSys *work, int index);
u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData);
u8 INTRUDE_COMM_GetUnionInfoReceived(IntrudeCommSys *work);
void *INTRUDE_COMM_GetReturnSlots(IntrudeCommSys *work);
int INTRUDE_COMM_GetAreaOwnerVersion(GameComm *comm);
int INTRUDE_COMM_GetAreaSlotFlag(GameComm *comm);
int INTRUDE_COMM_IsStepToOwnArea(GameComm *comm, struct GameData *gameData, int stepKind);
int INTRUDE_COMM_NormalizeVersion(int version, u32 trainerId);
int INTRUDE_COMM_GetAreaOwnerVersionClass(GameComm *comm, struct GameData *gameData);
int INTRUDE_COMM_IsListedId(u16 value);
int INTRUDE_COMM_HasUnlockFlags(struct GameData *gameData);
int INTRUDE_COMM_IsWarnedWithoutRequest(IntrudeCommSys *work);
int INTRUDE_COMM_GetVisitProgress(GameComm *comm);
void INTRUDE_COMM_SetCompleted(GameComm *comm);
int INTRUDE_COMM_GetRequestState(GameComm *comm);
int INTRUDE_COMM_CountEventPeers(GameComm *comm);
int INTRUDE_COMM_GetRequesterStatus(GameComm *comm, struct MyStatus *out);
int INTRUDE_COMM_IsSessionEndPending(GameComm *comm, int unused);
void INTRUDE_COMM_ClearHoldMode(GameComm *comm);
extern const char d_02172878[];
extern u8 d_02172868[];
extern u8 d_02172808[];
extern const u32 sGiftRibbonIds[15];
extern u8 GAME_VERSION_Code[];
extern u8 GAME_LANGUAGE_Code[];
extern struct StrBank *gSpeciesNameBank;
extern const u16 sIntrudeListedIds[61];
extern const u16 sIntrudeUnlockFlags[2];


/*
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */
void DELIVERY_IRC_SetStep(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line)
{
    work->step = step;
}


void DELIVERY_IRC_SetStepAtLine(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line)
{
    DELIVERY_IRC_SetStep(work, step, line);
}


void DELIVERY_IRC_StepIdle(void) {}


void DELIVERY_IRC_RecvCrc(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work)
{
    work->crc = msg->crc;
    work->cryptKey = msg->cryptKey;
}


void DELIVERY_IRC_RecvRequest(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work)
{
    work->request = *msg;
}


void DELIVERY_IRC_RecvNotFound(int netId, int size, const int *msg, DeliveryIrcWork *work)
{
    work->notFound = *msg;
}


u8 *DELIVERY_IRC_GetRecvBuffer(int netId, DeliveryIrcWork *work)
{
    return work->recvBuffer;
}


/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in DELIVERY_IRC_StepFinish.
 */
void DELIVERY_IRC_StepEnd(DeliveryIrcWork *work)
{
}


void DELIVERY_IRC_StepFinish(DeliveryIrcWork *work)
{
    if (GFL_NET_GetRunState() != 0)
        return;
    if (work->isParent == 0) {
        if (work->notFound == 1) {
            work->result = 3;
        } else {
            work->result = 1;
            MI_CpuCopy8(work->recvBuffer, work->param.entries[0].data, work->param.entries[0].size);
            if (work->crc != GF_STANDARD_SetupCalc(work->param.entries[0].data, work->param.entries[0].size))
                work->result = 2;
            func_0203F328(work->param.entries[0].data, work->param.entries[0].size, work->cryptKey);
        }
    } else {
        if (work->found == 1)
            work->result = 1;
        else
            work->result = 3;
    }
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepEnd, 0xF8);
}


void DELIVERY_IRC_StepExitParent(DeliveryIrcWork *work)
{
    if (IRCNET_IsLinkAlive())
        GFL_NET_Exit(0);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepFinish, 0x102);
}


void DELIVERY_IRC_StepExitChild(DeliveryIrcWork *work)
{
    GFL_NET_Exit(0);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepFinish, 0x10A);
}


void DELIVERY_IRC_StepWaitEndSync(DeliveryIrcWork *work)
{
    int k = 0x23;
    void *link = GFL_NET_HANDLE_GetCurrentHandle();

    if (GFL_NET_HANDLE_IsTimingSyncRange(link, 0x23, (u8)work->param.netCommandBase) != 0) {
        if (GFL_NET_IsParentAid() != 0) {
            k = 0x12C;
            IRCNET_SetTimeoutLimit(k);
            k -= 0x19;
            DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepExitParent, k);
            return;
        }
        k += 0xF3;
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepExitChild, k);
    }
}


void DELIVERY_IRC_StepStartEndSync(DeliveryIrcWork *work)
{
    int k = 0x23;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), k, (u8)work->param.netCommandBase);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepWaitEndSync, k + 0xFC);
}


void DELIVERY_IRC_StepSendData(DeliveryIrcWork *work)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase) == 0)
        return;
    if (work->isParent != 0) {
        if (work->found == 1) {
            DeliveryIrcEntry *entry = &work->param.entries[work->foundIndex];
            int k = 0xFF;
            if (GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, (unsigned)(work->param.netCommandBase << 24) >> 16, entry->size, (u32)entry->data, 0, 0, 1) == 0)
                return;
            DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartEndSync, k + 0x2F);
            return;
        }
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartEndSync, 0x133);
        return;
    }
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartEndSync, 0x137);
}


void DELIVERY_IRC_StepSendCrc(DeliveryIrcWork *work)
{
    if (work->found == 1) {
        DeliveryIrcKeyMsg msg;
        DeliveryIrcEntry *entry = work->sendEntry;
        msg.crc = GF_STANDARD_SetupCalc(entry->data, entry->size);
        msg.cryptKey = work->cryptKey;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((work->param.netCommandBase << 8) + 1), (u16)8, (u32)&msg) == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase);
        work->ackFlag = 0;
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendData, 0x152);
        return;
    }
    work->notFound = 1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((work->param.netCommandBase << 8) + 3), (u16)4, (u32)&work->notFound) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase);
    work->ackFlag = 0;
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendData, 0x162);
}


/*
 * levers: the RNG result is the third argument to func_0203F328, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 */
void DELIVERY_IRC_StepSearchEntry(DeliveryIrcWork *work)
{
    DeliveryIrcEntry *entry;
    u32 i;
    unsigned long count;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, (u8)work->param.netCommandBase) == 0)
        return;
    if (work->isParent != 0) {
        entry = 0;
        work->found = 0;
        count = work->param.entryCount;
        for (i = 0; i < work->param.entryCount; i++) {
            entry = &work->param.entries[i];
            if (entry->id == work->request.id && (entry->mask & work->request.mask)) {
                work->foundIndex = i;
                work->found = 1;
                break;
            }
        }
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendCrc, 0x188);
        if (work->found == 1) {
            u32 key = func_020056EC(0);
            work->cryptKey = key;
            func_0203F328(entry->data, entry->size, key);
            work->sendEntry = entry;
        }
        return;
    }
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendData, 0x193);
}


void DELIVERY_IRC_StepSendRequest(DeliveryIrcWork *work)
{
    if (work->isParent == 0) {
        work->request.id = work->param.entries[0].id;
        work->request.mask = work->param.entries[0].mask;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((work->param.netCommandBase << 8) + 2), (u16)8, (u32)&work->request) == 0)
            return;
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSearchEntry, 0x1A2);
        return;
    }
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSearchEntry, 0x1A6);
}


void DELIVERY_IRC_StepWaitConnect(DeliveryIrcWork *work)
{
    if (GFL_NET_GetNegotiationNum() > 1) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, (u8)work->param.netCommandBase);
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendRequest, 0x1AF);
    }
}


void DELIVERY_IRC_StepStartChangeover(DeliveryIrcWork *work)
{
    GFL_NET_StartChangeoverChild(0);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepWaitConnect, 0x1B7);
}


void DELIVERY_IRC_StepWaitInit(DeliveryIrcWork *work)
{
    if (GFL_NET_GetRunState() == 1)
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartChangeover, 0x1BE);
}


void *DELIVERY_IRC_Create(const DeliveryIrcParam *param)
{
    void *work = func_02030734(param->heapId, 0x684, 1, d_02172878, 0x1CD);
    MI_CpuCopy8((void *)param, work, 0x7C);
    return work;
}


int DELIVERY_IRC_StartNet(DeliveryIrcWork *work)
{
    if (GFL_NET_GetRunState() != 0)
        return 0;
    d_02172868[7] = work->param.netCommandBase;
    GFL_NET_StartSession((struct Req *)d_02172808, 0, (u32)work);
    return 1;
}


int DELIVERY_IRC_Start(DeliveryIrcWork *work)
{
    int started = DELIVERY_IRC_StartNet(work);
    work->isParent = 0;
    work->found = 0;
    work->foundIndex = 0;
    work->notFound = 0;
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepWaitInit, 0x231);
    return started;
}


/*
 * extent: Accessor ends at 02157E78, followed by labelled callback function.
 */
unsigned char DELIVERY_IRC_GetResult(DeliveryIrcWork *work)
{
    return work->result;
}


void DELIVERY_IRC_Main(DeliveryIrcWork *work)
{
    DeliveryIrcStepFunc step = work->step;
    if (step != 0)
        step(work);
}


int DELIVERY_IRC_Delete(DeliveryIrcWork *work)
{
    func_020307B0(work);
    return GFL_NET_Exit(0);
}


/*
 * Builds a Pokemon from a mystery gift record, or returns 0 when the record
 * is invalid (wrong format version, species above 649, level above 100, item
 * above 626, bad ability kind, empty nickname or OT name) or the finished
 * Pokemon fails its final value check. The Pokemon is allocated in heap
 * heapId. A random value is taken for every field the record leaves open.
 *
 * Lever: gender is a u8 local, loaded from GiftMon.gender and remapped from
 * 0xFF to 2; the form argument of the personality call is cast to u8.
 */
struct PokemonParam *MYSTERY_GIFT_CreateMon(const GiftMon *gift, int heapId, struct GameData *gameData)
{
    u16 moves[4];
    u8 ivValues[6];
    u32 month;
    u32 abilityKind;
    u8 gender;
    u64 personalRnd;
    u32 species;
    u32 otId;
    u64 otId64;
    u16 level;
    u32 abilitySlot;
    struct PokemonParam *result;
    u32 packedIvs;
    int i;
    u32 ribbonBit;
    u16 move;
    struct PokemonParam *mon;
    void *eggName;
    u32 nature;
    u8 day;
    u16 year;
    u32 metLocation;

    level = gift->level;
    otId = gift->otId;
    species = gift->species;
    gender = gift->gender;
    abilityKind = gift->abilityKind;
    ivValues[0] = gift->ivHp;
    ivValues[1] = gift->ivAttack;
    ivValues[2] = gift->ivDefense;
    ivValues[3] = gift->ivSlot3;
    ivValues[4] = gift->ivSlot4;
    ivValues[5] = gift->ivSlot5;
    moves[0] = gift->moves[0];
    moves[1] = gift->moves[1];
    moves[2] = gift->moves[2];
    moves[3] = gift->moves[3];

    if (gift->formatVersion != 1) {
        result = 0;
        goto out;
    }
    if (species > 649) {
        result = 0;
        goto out;
    }
    if (species == 0) {
        result = 0;
        goto out;
    }
    if (level > 100) {
        result = 0;
        goto out;
    }
    if (gift->item > 626) {
        result = 0;
        goto out;
    }

    if (level == 0)
        level = func_020056EC(100) + 1;
    if (gift->otId == 0)
        otId = func_02008530(GAME_DATA_GetMyStatus(gameData));
    if (gender == 0xFF)
        gender = 2;
    for (i = 0; i < 6; i++) {
        if (ivValues[i] == 0xFF)
            ivValues[i] = func_020056EC(32);
    }

    otId64 = otId;
    mon = POKE_TOOL_Create(species, level, otId64, heapId);
    packedIvs = (ivValues[0] & 0x1F) | ((ivValues[1] & 0x1F) << 5) | ((ivValues[2] & 0x1F) << 10)
        | ((ivValues[3] & 0x1F) << 15) | ((ivValues[4] & 0x1F) << 20) | ((ivValues[5] & 0x1F) << 25);

    if (abilityKind == 4)
        abilityKind = (u8)func_020056EC(3);
    switch (abilityKind) {
    case 0:
        abilitySlot = 0;
        break;
    case 1:
        abilitySlot = 1;
        break;
    case 2:
        abilitySlot = 0;
        break;
    case 3:
        abilitySlot = 2;
        break;
    default:
        result = 0;
        goto out;
    }

    if (gift->pid != 0) {
        personalRnd = gift->pid;
    } else if (gift->pidType == 0) {
        personalRnd = POKE_TOOL_CreatePersonalRnd(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 0);
    } else if (gift->pidType == 1) {
        personalRnd = POKE_TOOL_CreatePersonalRnd(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 2);
    } else if (gift->pidType == 2) {
        personalRnd = POKE_TOOL_CreatePersonalRnd(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 1);
    }

    POKE_TOOL_SetupPartyParamEx(mon, gift->species, level, otId64, packedIvs, personalRnd);
    POKE_TOOL_SetPartyValue(mon, 6, gift->item);
    POKE_TOOL_SetDefaultMoves(mon);
    for (i = 0; i < 4; i++) {
        move = moves[i];
        if (move != 0 && move < 0x230) {
            if (POKE_TOOL_AddMove(mon, move) == 0xFFFF)
                POKE_TOOL_PushMove(mon, move);
        }
    }
    if (gift->pid == 0 && abilityKind == 2)
        POKE_TOOL_SetAbility(mon, species, gift->form);
    POKE_TOOL_SetPartyValue(mon, 0x6F, gift->form);
    if (gift->ball != 0 && gift->ball <= 0x19)
        POKE_TOOL_SetPartyValue(mon, 0x98, gift->ball);
    else
        POKE_TOOL_SetPartyValue(mon, 0x98, 4);
    if (gift->ballExtra != 0)
        POKE_TOOL_SetPartyValue(mon, 0x99, gift->ballExtra);
    POKE_TOOL_SetPartyValue(mon, 0x13, gift->contestStats[0]);
    POKE_TOOL_SetPartyValue(mon, 0x14, gift->contestStats[1]);
    POKE_TOOL_SetPartyValue(mon, 0x15, gift->contestStats[2]);
    POKE_TOOL_SetPartyValue(mon, 0x16, gift->contestStats[3]);
    POKE_TOOL_SetPartyValue(mon, 0x17, gift->contestStats[4]);
    POKE_TOOL_SetPartyValue(mon, 0x18, gift->contestStats[4]);
    for (ribbonBit = 0; ribbonBit < 15; ribbonBit++) {
        if (gift->ribbons & (1 << ribbonBit))
            POKE_TOOL_SetPartyValue(mon, sGiftRibbonIds[ribbonBit], 1);
    }
    if (gift->originGame == 0)
        POKE_TOOL_SetPartyValue(mon, 0x77, GAME_VERSION_Code[0]);
    else
        POKE_TOOL_SetPartyValue(mon, 0x77, gift->originGame);
    if (gift->language == 0)
        POKE_TOOL_SetPartyValue(mon, 0xC, GAME_LANGUAGE_Code[0]);
    else
        POKE_TOOL_SetPartyValue(mon, 0xC, gift->language);
    if (gift->nickname[0] == 0) {
        func_020307B0(mon);
        result = 0;
        goto out;
    }
    if (gift->nickname[0] != STRBUF_GetEosChar())
        POKE_TOOL_SetPartyValue(mon, 0x74, (u32)gift->nickname);
    nature = gift->nature;
    if (nature == 0xFF)
        nature = (u8)func_020056EC(25);
    POKE_TOOL_SetPartyValue(mon, 0x70, nature);
    POKE_TOOL_SetPartyValue(mon, 0x95, gift->eggLocation);
    POKE_TOOL_SetPartyValue(mon, 0x96, gift->metLocation);
    if (gift->otName[0] == 0) {
        func_020307B0(mon);
        result = 0;
        goto out;
    }
    if (gift->otName[0] == STRBUF_GetEosChar())
        POKE_TOOL_SetPartyValue(mon, 0x8E, (u32)func_020084F4(GAME_DATA_GetMyStatus(gameData)));
    else
        POKE_TOOL_SetPartyValue(mon, 0x8E, (u32)gift->otName);
    if (gift->otGender <= 2)
        POKE_TOOL_SetPartyValue(mon, 0x9A, gift->otGender);
    else
        POKE_TOOL_SetPartyValue(mon, 0x9A, func_02008550(GAME_DATA_GetMyStatus(gameData)));
    if (gift->isEgg) {
        POKE_TOOL_SetPartyValue(mon, 0x4C, 1);
        eggName = func_02045EC0(gSpeciesNameBank, 0x28A);
        POKE_TOOL_SetPartyValue(mon, 0x73, (u32)eggName);
        STRBUF_Delete(eggName);
        POKE_TOOL_SetPartyValue(mon, 9, 10);
    }
    year = gift->receivedDate >> 16;
    month = (u8)(gift->receivedDate >> 8);
    day = gift->receivedDate;
    metLocation = gift->isEgg ? gift->eggLocation : gift->metLocation;
    func_0202F2AC(POKE_TOOL_Dummy(mon), metLocation, year - 2000, month, day);
    POKE_TOOL_RecalcParam(mon);
    result = 0;
    if (POKE_TOOL_GetPartyValue(mon, 3, 0) != 0)
        func_020307B0(mon);
    else
        result = mon;
out:
    return result;
}


/*
 * Returns 0 while the game data has exactly one visit count and the
 * game comm counter is nonzero, else 1.
 */
int INTRUDE_COMM_CheckEntryAllowed(struct GameSystem *gameSystem)
{
    GameComm *comm = GAMESYSTEM_GetGameComm(gameSystem);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);

    if (GAME_DATA_GetIntrudeCount(gameData) == 1 && GAME_COMM_GetCounter(comm) != 0)
        return 0;
    return 1;
}


/*
 * The intrude comm work of the game comm, or 0 unless the game comm runs
 * kind 2 outside a transition from kind 1 and the work exists.
 */
IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(GameComm *comm)
{
    IntrudeCommSys *work = GAME_COMM_GetWork(comm);

    if (func_0200FB24() != 0 || GAME_COMM_GetKind(comm) != 2 || GAME_COMM_IsTransition(comm) == 1 || work == 0)
        return 0;
    return work;
}


int INTRUDE_COMM_GetPlayerNetId(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0) {
        return GAME_DATA_GetExitMode(GAME_COMM_GetGameData(comm));
    }
    return work->ownNetId;
}


/*
 * When one of the mask bits is set in the 2-bit peer flags, flips the low
 * bit of the flags and answers 1.
 */
int INTRUDE_COMM_TogglePeerFlags(IntrudeCommSys *work, int mask, int unused)
{
    u8 flags = work->peerFlags;

    if (mask & flags) {
        work->peerFlags ^= 1;
        return 1;
    }
    return 0;
}


/*
 * The battle record slot of a net ID: the last-battle slot for the own net
 * ID, the per-ID slot for any other.
 */
struct BattleRecSlot *GAME_DATA_GetBattleRecSlotByNetId(struct GameData *gameData, u32 netId)
{
    if (GAME_DATA_GetExitMode(gameData) == netId)
        return GAME_DATA_GetLastBattleRecSlot(gameData);

    return GAME_DATA_GetBattleRecSlot(gameData, netId);
}


/*
 * The MyStatus of a net ID: the own status for the own net ID, the player
 * status of the net ID for any other.
 */
struct MyStatus *GAME_DATA_GetMyStatusByNetId(struct GameData *gameData, u32 netId)
{
    if (GAME_DATA_GetExitMode(gameData) == netId)
        return GAME_DATA_GetMyStatus(gameData);

    return GAME_DATA_GetPlayerStatus(gameData, netId);
}


/*
 * Address of the member entry (0x28 bytes) of the session at index.
 */
IntrudeMemberEntry *INTRUDE_COMM_GetMemberEntry(IntrudeCommSys *work, int index)
{
    return &work->session.members[index];
}


/*
 * The net ID of the player whose area is visited, as a byte.
 */
u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData)
{
    return (u8)(unsigned)GAME_DATA_GetIntrudeId(gameData);
}


/*
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * GAME_DATA_GetIntrudeIdByte); sole blocker of ov018 INTRUDE_SUBDISP_Update. Followed by another
 * unlabelled leaf at 0x02158434.
 */
u8 INTRUDE_COMM_GetUnionInfoReceived(IntrudeCommSys *work)
{
    return work->unionInfoReceived;
}


/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent.
 */
void *INTRUDE_COMM_GetReturnSlots(IntrudeCommSys *work)
{
    return work->returnSlots;
}


/*
 * Version code (20 or 21) of the owner of the visited area. Answers 21
 * when no visit is running.
 *
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 */
int INTRUDE_COMM_GetAreaOwnerVersion(GameComm *comm)
{
    struct GameData *gameData = GAME_COMM_GetGameData(comm);
    u8 areaOwnerId;

    if (GAME_DATA_GetIntrudeCount(gameData) == 0)
        return 21;
    areaOwnerId = (int)GAME_DATA_GetIntrudeId(gameData);
    return func_0200855C(GAME_DATA_GetMyStatusByNetId(gameData, areaOwnerId));
}


/*
 * The season of the game data when no visit runs or the visited area is the
 * own one, else the slot flag of the visited area's owner.
 */
int INTRUDE_COMM_GetAreaSlotFlag(GameComm *comm)
{
    struct GameData *gameData = GAME_COMM_GetGameData(comm);
    u8 areaOwnerId;

    if (GAME_DATA_GetIntrudeCount(gameData) == 0) {
        return GAME_DATA_GetSeason(gameData);
    }
    areaOwnerId = GAME_DATA_GetIntrudeIdByte(gameData);
    if (areaOwnerId == GAME_DATA_GetExitMode(gameData)) {
        return GAME_DATA_GetSeason(gameData);
    }
    return GAME_DATA_GetSlotFlag(gameData, areaOwnerId);
}


/*
 * Whether stepping the local area owner ID one place back (stepKind 2) or
 * forward, wrapping at the highest net ID, lands on the own net ID. Answers 1
 * when no visit work exists.
 */
int INTRUDE_COMM_IsStepToOwnArea(GameComm *comm, struct GameData *gameData, int stepKind)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);
    int next;
    int current;

    if (work == 0)
        return 1;
    current = work->localPeer.intrudeId;
    if (stepKind == 2) {
        next = current - 1;
        if (next < 0)
            next = work->lastAreaIndex;
    } else {
        next = current + 1;
        if (next >= work->lastAreaIndex + 1)
            next = 0;
    }
    if (next == GAME_DATA_GetExitMode(gameData))
        return 1;
    return 0;
}


/*
 * Normalizes a version code to 20 or 21: other codes become 20 when bit 16
 * of the trainer ID is set, else 21.
 */
int INTRUDE_COMM_NormalizeVersion(int version, u32 trainerId)
{
    if (version == 21)
        return version;
    if (version == 20)
        return version;
    if (trainerId & 0x10000)
        return 20;
    return 21;
}


/*
 * Version class of the visited area's owner: 0 for the own area or when the
 * field status is not map mode 1, 1 for version 20, 2 for version 21, 3 for
 * any other. The work of the comm is fetched first and not used.
 */
int INTRUDE_COMM_GetAreaOwnerVersionClass(GameComm *comm, struct GameData *gameData)
{
    u8 areaOwnerId;
    struct MyStatus *status;
    int version;

    INTRUDE_COMM_GetWorkIfRunning(comm);
    if (FIELD_STATUS_GetMapMode(GAME_DATA_GetMoveModelSys(gameData)) != 1)
        return 0;
    areaOwnerId = GAME_DATA_GetIntrudeIdByte(gameData);
    if (areaOwnerId == GAME_DATA_GetExitMode(gameData))
        return 0;
    status = GAME_DATA_GetPlayerStatus(gameData, areaOwnerId);
    version = INTRUDE_COMM_NormalizeVersion(func_0200855C(status), func_02008530(status));
    switch (version) {
    case 20:
        return 1;
    case 21:
        return 2;
    default:
        return 3;
    }
}


/*
 * Whether value is one of the 61 ids of the table.
 *
 * lever: The ternary loop condition preserves the branch to the bottom test.
 */
int INTRUDE_COMM_IsListedId(u16 value)
{
    unsigned int i;

    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == sIntrudeListedIds[i])
            return 1;
    }
    return 0;
}


/*
 * Whether both event flags of the table are set.
 */
int INTRUDE_COMM_HasUnlockFlags(struct GameData *gameData)
{
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    unsigned int i;

    for (i = 0; i < 2; i++) {
        if (ZONEDATA_CheckEventFlag(eventWork, sIntrudeUnlockFlags[i]) == 0)
            return 0;
    }
    return 1;
}


/*
 * 1 when the session has been warned but no request is active.
 */
int INTRUDE_COMM_IsWarnedWithoutRequest(IntrudeCommSys *work)
{
    if (work->warned != 0 && INTRUDE_COMM_IsSessionActive(&work->session) == 0)
        return 1;
    return 0;
}


/*
 * Progress of the visit: 0 without work, 3 once the gear reported flag is set,
 * else 2 or 1 from the state of INTRUDE_COMM_GetRequestState (3 gives 2).
 *
 * Callee 02158344 consumes incoming r0.
 */
int INTRUDE_COMM_GetVisitProgress(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0)
        return 0;
    if (work->gearReported == 0) {
        if (INTRUDE_COMM_GetRequestState(comm) == 3)
            return 2;
        return 1;
    }
    return 3;
}


/*
 * Sets the gear reported flag of the work.
 *
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
void INTRUDE_COMM_SetCompleted(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work != 0)
        work->gearReported = 1;
}


/*
 * State of the active request: 0 without work, 1 without an active
 * session, 2 when the request is the player's own, else 1 or 3 by the
 * event flags (3 when both are set).
 */
int INTRUDE_COMM_GetRequestState(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0)
        return 0;
    if (INTRUDE_COMM_IsSessionActive(&work->session) == 1) {
        if (INTRUDE_COMM_IsRequestFromSelf(work) == 1)
            return 2;
        if (INTRUDE_COMM_HasUnlockFlags(GAME_COMM_GetGameData(comm)) == 0)
            return 1;
        return 3;
    }
    return 1;
}


/*
 * Number of peers with the event flag set (at least 1) while a session is
 * active, else 0.
 */
int INTRUDE_COMM_CountEventPeers(GameComm *comm)
{
    int count = 0;
    u8 i;
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0)
        return count;
    if (INTRUDE_COMM_IsSessionActive(&work->session) == 0)
        return count;
    for (i = 0; i < 3; i++) {
        if (work->peers[i].eventJoined == 1)
            count++;
    }
    if (count == 0)
        count = 1;
    return count;
}


/*
 * Copies the status of the requester of the active session to out. Answers 0
 * when no work or no active session exists.
 */
int INTRUDE_COMM_GetRequesterStatus(GameComm *comm, struct MyStatus *out)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);
    struct GameData *gameData = GAME_COMM_GetGameData(comm);

    if (work == 0 || INTRUDE_COMM_IsSessionActive(&work->session) == 0)
        return 0;
    func_02008500(GAME_DATA_GetPlayerStatus(gameData, INTRUDE_COMM_GetRequesterNetId(work, &work->session)), out);
    return 1;
}


/*
 * Three guards (kind == 2, a non-null work, session-ended bit set) then a
 * predicate whose one result is inverted.
 */
int INTRUDE_COMM_IsSessionEndPending(GameComm *comm, int unused)
{
    IntrudeCommSys *work;

    if (GAME_COMM_GetKind(comm) != 2)
        return 0;
    work = GAME_COMM_GetWork(comm);
    if (work == 0)
        return 0;
    if (work->sessionEnded == 0)
        return 0;
    if (GFL_NET_IsSessionNull() == 1)
        return 0;
    return 1;
}


/*
 * Clears the 2-bit zone check of the work.
 */
void INTRUDE_COMM_ClearHoldMode(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work != 0)
        work->zoneCheck = 0;
}
