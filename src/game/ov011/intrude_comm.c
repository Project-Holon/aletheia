/*
 * file:     intrude_comm.c
 * unit:     yes
 * function: INTRUDE_COMM_Create, INTRUDE_COMM_StartSession, func_02172D70, INTRUDE_COMM_Shutdown, INTRUDE_COMM_Destroy, INTRUDE_COMM_ScanCallback, INTRUDE_COMM_SyncPlayers, INTRUDE_COMM_SuspendPlayers, INTRUDE_COMM_OnSessionStarted, INTRUDE_COMM_OnSessionExit, INTRUDE_COMM_GetBeacon, INTRUDE_COMM_InitBeacon, INTRUDE_COMM_RefreshBeacon, INTRUDE_COMM_IsEqual, INTRUDE_COMM_RecvQuit, INTRUDE_COMM_Nop
 * address:  0x02172BC0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   str_02177000   0x02177000  data  ov011  a1
 *   COMM_PLAYER_Create  0x02167518  thumb  ov010
 *   INTRUDE_COMM_InitRequest  0x0217538C  thumb  ov011
 *   INTRUDE_COMM_InitSession  0x0217576C  thumb  ov011
 *   EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid  0x02161F54  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_SetExitMode  0x02012B64  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   GAME_DATA_SetEnterMode  0x02012B4C  thumb
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_StartChangeoverParent  0x0203D10C  arm
 *   GFL_NET_ConnectMacAddressParent  0x0203CFF0  arm
 *   d_02177000     0x02177000  data  ov011
 *   d_021768C8     0x021768C8  data  a4
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline  0x02161F74  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   INTRUDE_COMM_AgeFoundList  0x02173658  thumb  ov011
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   INTRUDE_COMM_RefreshSelfRecord  0x02174E3C  thumb  ov011
 *   INTRUDE_COMM_ApplyPlayerBeacon  0x02174EAC  thumb  ov011
 *   INTRUDE_COMM_SendStatusRecord  0x02173828  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAMESYSTEM_IsFieldMapExist  0x02012114  thumb
 *   func_02174978  0x02174978  thumb  ov011
 *   INTRUDE_COMM_IsResultConfirmed  0x02175EB8  thumb  ov011
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 *   INTRUDE_COMM_SendTimeoutWarning  0x021739E0  thumb  ov011
 *   INTRUDE_COMM_GetLeaveFlag  0x02175ED8  thumb  ov011
 *   INTRUDE_COMM_HasConnectedPeers  0x02175628  thumb  ov011
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   INTRUDE_COMM_SendShutdownRequest  0x021736EC  thumb  ov011
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   EVENT_FIELD_PROCLINK_ClearReturnSlots  0x02161F68  thumb  ov010
 *   GAME_DATA_ClearUnionInfo  0x0201281C  thumb
 *   COMM_PLAYER_Delete  0x0216754C  thumb  ov010
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_HasResultReward  0x02175E90  thumb  ov011
 *   INTRUDE_COMM_GetSessionResult  0x02175BCC  thumb  ov011
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_COMM_SetCounter  0x02026480  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAME_COMM_ClearInfoMessages  0x02026680  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WIH_IsMatchingParent  0x0217873C  thumb  ov014
 *   NET_WHPIPE_CheckBeaconFlags  0x02177494  thumb  ov014
 *   NET_WHPIPE_GetEntryBeacon  0x02177BFC  thumb  ov014
 *   INTRUDE_COMM_IsListedId  0x02158570  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetLanguage  0x02165C50  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   INTRUDE_FIELD_IsListedZone  0x0217C11C  thumb  ov018
 *   COMM_PLAYER_ClearPending  0x02167794  thumb  ov010
 *   COMM_PLAYER_Resume  0x021676E4  thumb  ov010
 *   COMM_PLAYER_CheckOccupy  0x021677E4  thumb  ov010
 *   COMM_PLAYER_SetPackage  0x02167848  thumb  ov010
 *   INTRUDE_COMM_StorePlayerRecord  0x02174F54  thumb  ov011
 *   COMM_PLAYER_Suspend 0x02167688 thumb ov010
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   NET_WHPIPE_PublishBeacon  0x0217778C  thumb  ov014
 */
#include "../arm9/game_beacon_types.h"

typedef int            s32;

#include "../arm9/net_types.h"
#include "intrude_comm_types.h"

struct GameData;
struct GameComm;
struct GameSystem;
struct CommPlayerWork;
struct STRBUF;
struct FieldMap;
struct MyPlayerWork;
struct PlayerStatus;
struct MyStatus;

/* Parameter of the session procs: filled by the caller, read by every step. */
typedef struct IntrudeCommParam {
    void *gameSystem;       /* 0x00: GameSystem * */
    void *gameComm;         /* 0x04: GameComm * */
    u8    parentMac[6];     /* 0x08: MAC address of the parent to join */
    u8    isParent;         /* 0x0E: 1 = open the session, else join parentMac */
} IntrudeCommParam;

/* Record the wireless scan returns for one nearby player. */
typedef struct IntrudeScanRecord {
    u8 header[3];
    u8 inUse : 1;
    u8 excluded : 1;        /* skipped by the scan callback */
    u8 flags : 6;
    u32 trainerId;
    GameBeaconInfo info;
} IntrudeScanRecord;

extern struct GameData *GAME_COMM_GetGameData(struct GameComm *gameComm);
extern u8 *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern int   INTRUDE_COMM_HasUnlockFlags(struct GameData *gameData);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern struct CommPlayerWork *COMM_PLAYER_Create(int playerNum, void *gameSystem, u16 heapId, int mode);
extern void INTRUDE_COMM_InitRequest(u8 *work, int arg);
extern void INTRUDE_COMM_InitSession(IntrudeSession *session);
extern int EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(void *returnSlots);
extern struct STRBUF *STRBUF_Create(u32 capacity, u32 heapId);
extern void GAME_DATA_SetExitMode(struct GameData *gameData, u32 exitMode);
extern void GAME_DATA_SetIntrudeId(struct GameData *gameData, u32 intrudeId);
extern void GAME_DATA_SetEnterMode(struct GameData *gameData, u8 enterMode);
extern struct PlayerStatus *GAME_DATA_GetPlayerStatus(struct GameData *gameData, u32 index);
extern void  MYSTATUS_Copy(void *src, void *dst);
extern u8 GAME_DATA_IsSaving(const u8 *gameData);
extern void GFL_NET_StartSession(GFLNetInitializeStruct *init, u32 callback, u32 userArg);
extern u32 func_020307B0(void *memory);
extern int GFL_NET_StartChangeoverParent(int arg);
extern void GFL_NET_ConnectMacAddressParent(void *macAddress);
extern u8 *GAME_DATA_GetSecondUnionInfo(struct GameData *gameData);
extern void EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline(void *returnSlots, int unionInfo, int peerMask);
extern u32 func_0200FB24(void);
extern void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern void INTRUDE_COMM_AgeFoundList(IntrudeCommSys *work);
extern int   GFL_NET_SYSTEM_GetConnectNum(void);
extern void GFL_NET_SetLoginOption(u8 loginOption);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void INTRUDE_COMM_SetIntrudeId(u8 *work, u32 netId);
extern u8 GAME_DATA_GetSeason(const struct GameData *gameData);
extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(GFLNetHandle *handle);
extern void INTRUDE_COMM_RefreshSelfRecord(u8 *work);
extern void INTRUDE_COMM_ApplyPlayerBeacon(u8 *work, int netId, u8 *record);
extern int INTRUDE_COMM_SendStatusRecord(IntrudeCommSys *work);
extern u32 func_0203F4FC(void);
extern int GAME_DATA_GetIntrudeCount(const struct GameData *gameData);
extern u32   GAMESYSTEM_IsFieldMapExist(const struct GameSystem *gameSystem);
extern void func_02174978(u8 *work);
extern int   INTRUDE_COMM_IsResultConfirmed(void *session);
extern u32 GFL_NET_IsParentAid(void);
extern int INTRUDE_COMM_IsSessionActive(IntrudeSession *session);
extern int   INTRUDE_COMM_SendTimeoutWarning(void);
extern int INTRUDE_COMM_GetLeaveFlag(void *session);
extern int   INTRUDE_COMM_HasConnectedPeers(void);
extern int GFL_NET_Exit(void (*exitCallback)(IntrudeCommSys *work));
extern int   GFL_NET_GetNegotiationNum(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(GFLNetHandle *handle, u32 timingNo, u32 option);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(GFLNetHandle *handle, u32 timingNo, u32 option);
extern int GFL_NET_IsSessionNull(void);
extern int INTRUDE_COMM_SendShutdownRequest(IntrudeCommSys *work);
extern void func_0200FBA0(void);
extern void *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern u16 GAME_DATA_GetPlayerZoneId(const void *myPlayerWork);
extern u32 ZONEDATA_IsZone117(u32 zoneId);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern int FIELDMAP_IsReady(void *fieldMap);
extern void EVENT_FIELD_PROCLINK_ClearReturnSlots(void *returnSlots);
extern void GAME_DATA_ClearUnionInfo(u8 *gameData);
extern void COMM_PLAYER_Delete(void *gameSystem, struct CommPlayerWork *commPlayer);
extern int INTRUDE_COMM_HasResult(IntrudeSession *session);
extern int INTRUDE_COMM_HasResultReward(void *work, IntrudeSession *session);
extern u8 *INTRUDE_COMM_GetSessionResult(IntrudeSession *session);
extern u8 GAME_DATA_GetExitMode(const struct GameData *gameData);
extern void GAME_COMM_SetCounter(struct GameComm *gameComm, u32 counter);
extern void GAMESYSTEM_SetFieldMapState(struct GameSystem *gameSystem, u32 state);
extern void GAME_COMM_ClearInfoMessages(struct GameComm *gameComm);
extern void STRBUF_Delete(struct STRBUF *buf);
extern int WIH_IsMatchingParent(void *whPipe);
extern int NET_WHPIPE_CheckBeaconFlags(void *whPipe, u32 flags);
extern IntrudeScanRecord *NET_WHPIPE_GetEntryBeacon(void *whPipe, u8 *kind);
extern int INTRUDE_COMM_IsListedId(u16 zoneId);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(const GameBeaconInfo *info, struct STRBUF *name);
extern u8 GAME_BEACON_ACCESSOR_GetSex(const GameBeaconInfo *info);
extern u8 GAME_BEACON_ACCESSOR_GetLanguage(const GameBeaconInfo *info);
extern u16 FIELDMAP_GetZoneId(u8 *fieldObject);
extern int INTRUDE_FIELD_IsListedZone(u32 value);
extern void COMM_PLAYER_ClearPending(struct CommPlayerWork *commPlayer);
extern void COMM_PLAYER_Resume(struct CommPlayerWork *commPlayer);
extern int COMM_PLAYER_CheckOccupy(struct CommPlayerWork *commPlayer, int index);
extern void COMM_PLAYER_SetPackage(struct CommPlayerWork *commPlayer, int index, IntrudePlayerPackage *package);
extern void INTRUDE_COMM_StorePlayerRecord(u8 *work, int netId, const IntrudePeer *peer, int arg);
extern void COMM_PLAYER_Suspend(struct CommPlayerWork *commPlayer);
extern void WIH_SetBeaconFoundCallback(u32 callback);
extern u32 GFL_NET_SYSTEM_CheckError(void);
extern void NET_WHPIPE_PublishBeacon(void);
IntrudeCommSys *INTRUDE_COMM_Create(void *proc, IntrudeCommParam *param);
int INTRUDE_COMM_StartSession(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
void func_02172D70(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
int INTRUDE_COMM_Shutdown(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
int INTRUDE_COMM_Destroy(int unused, void **proc, IntrudeCommSys *work);
void INTRUDE_COMM_ScanCallback(void *whPipe, IntrudeCommSys *work);
void INTRUDE_COMM_SyncPlayers(IntrudeCommSys *work, IntrudeCommSys *peerWork, int fieldObjectAddr);
void INTRUDE_COMM_SuspendPlayers(int arg, IntrudeCommSys *work);
void INTRUDE_COMM_OnSessionStarted(IntrudeCommSys *work);
void INTRUDE_COMM_OnSessionExit(IntrudeCommSys *work);
IntrudeBeacon *INTRUDE_COMM_GetBeacon(IntrudeCommSys *work);
void INTRUDE_COMM_InitBeacon(struct GameData *gameData, IntrudeBeacon *beacon, int maxConnect);
int INTRUDE_COMM_RefreshBeacon(struct GameData *gameData, IntrudeBeacon *beacon);
extern char  str_02177000[];
extern char d_02177000[];
extern const GFLNetInitializeStruct d_021768C8;


IntrudeCommSys *INTRUDE_COMM_Create(void *proc, IntrudeCommParam *param)
{
    struct GameData *gameData;
    u8 *myStatus;
    u32 maxConnect;
    IntrudeCommSys *work;
    int i;
    u8 netId;

    gameData = GAME_COMM_GetGameData(param->gameComm);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    maxConnect = 3;
    if (param->isParent == 1 && INTRUDE_COMM_HasUnlockFlags(gameData) == 0) {
        maxConnect = 2;
    }
    work = func_02030734(5, sizeof(IntrudeCommSys), 1, str_02177000, 0x9a);
    work->gameSystem = param->gameSystem;
    work->gameComm = param->gameComm;
    work->step = 1;
    work->commPlayer = COMM_PLAYER_Create(3, param->gameSystem, 5, 0);
    work->memberCount = 1;
    work->lastAreaIndex = 1;
    INTRUDE_COMM_InitRequest((u8 *)work, 4);
    INTRUDE_COMM_InitSession(&work->session);
    INTRUDE_COMM_InitBeacon(gameData, &work->beacon, maxConnect);
    EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(work->returnSlots);
    for (i = 0; i < 2; i++) {
        work->foundNames[i] = STRBUF_Create(8, 5);
    }
    GAME_DATA_SetExitMode(gameData, 0);
    GAME_DATA_SetIntrudeId(gameData, 0);
    GAME_DATA_SetEnterMode(gameData, 1);
    for (netId = 0; netId < 3; netId++) {
        MYSTATUS_Copy(myStatus, GAME_DATA_GetPlayerStatus(gameData, netId));
    }
    return work;
}







/*
 * recoup 2026-10-05: the old draft (196 B, work as u8* with work[0x8fd]) failed on register
 * colours and a second pool load of 0x8fd. Typed parameters closed it to 192 B, all bytes equal:
 * param as a struct with the byte at 0x0E, work as a struct with the step byte at 0x8FD (written
 * work->step = 3 / 4 in each arm, no local), callee types from matched twins (GAME_COMM_GetGameData and
 * func_02030734 return u32, GAME_DATA_IsSaving takes const u8 *). The only open item is the pool
 * word INTRUDE_COMM_OnSessionStarted: the leaf is filed at src/matched/ov/ov011_func_02173568.c (EXACT);
 * the integrator needs a shard for it, then this file is EXACT.
 */
int INTRUDE_COMM_StartSession(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    u8 *gameData;
    GFLNetInitializeStruct *init;

    gameData = (u8 *)GAME_COMM_GetGameData(param->gameComm);
    if (GAME_DATA_IsSaving(gameData) == 1)
        return 0;
    switch (*state) {
    case 0:
        init = (GFLNetInitializeStruct *)func_02030734(0x8005, 0x70, 0, d_02177000, 0xcf);
        *init = d_021768C8;
        if (param->isParent == 1) {
            if (INTRUDE_COMM_HasUnlockFlags((struct GameData *)gameData) == 0)
                init->maxConnectNum = 2;
        }
        GFL_NET_StartSession(init, (u32)INTRUDE_COMM_OnSessionStarted, (u32)work);
        func_020307B0(init);
        *state = *state + 1;
        break;
    case 1:
        if (work->step >= 2) {
            if (param->isParent == 1) {
                GFL_NET_StartChangeoverParent(0);
                work->step = 3;
            } else {
                GFL_NET_ConnectMacAddressParent(param->parentMac);
                work->step = 4;
            }
            return 1;
        }
        break;
    }
    return 0;
}







/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =MI_CpuCopy8; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void func_02172D70(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    struct GameData *gameData;
    struct PlayerStatus *playerStatus;
    s32 startTime;
    s32 now;

    gameData = GAME_COMM_GetGameData(param->gameComm);
    if (work != 0 && work->step >= 7) {
        EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline(work->returnSlots, (int)GAME_DATA_GetSecondUnionInfo(gameData), work->peerMask);
    }
    if (func_0200FB24() != 0 || work->quit == 1) {
        if (work->lock) {
            return;
        }
        work->step = 11;
        work->quit = 1;
        GAME_COMM_RequestExitNoCallback(work->gameComm);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1 && work->lock == 0) {
        GAME_COMM_RequestExitNoCallback(work->gameComm);
        return;
    }
    if (work->step == 7 && work->shutdownRequested == 1) {
        GAME_COMM_RequestExitNoCallback(work->gameComm);
        return;
    }
    INTRUDE_COMM_RefreshBeacon(gameData, &work->beacon);
    INTRUDE_COMM_AgeFoundList(work);
    switch (*state) {
    case 0:
        if (GFL_NET_SYSTEM_GetConnectNum() > 1 && work->step < 5) {
            work->step = 5;
            GFL_NET_SetLoginOption(1);
        }
        if (work->step == 5) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                GAME_DATA_SetExitMode(gameData, GFL_NET_SYSTEM_GetCurrentAid());
                playerStatus = GAME_DATA_GetPlayerStatus(gameData, GFL_NET_SYSTEM_GetCurrentAid());
                MYSTATUS_Copy(GAME_DATA_GetMyStatus(gameData), playerStatus);
                INTRUDE_COMM_SetIntrudeId((u8 *)work, GFL_NET_SYSTEM_GetCurrentAid());
                work->localPeer.statusCode = 0x15;
                work->localPeer.season = GAME_DATA_GetSeason(gameData);
                if (INTRUDE_COMM_HasUnlockFlags(gameData) == 0) {
                    work->localPeer.startFlag = 1;
                }
                GFL_NET_SetLoginOption(1);
                (*state)++;
            }
        } else if (work->step == 4) {
            work->waitFrames++;
            if (work->waitFrames > 600) {
                work->waitFrames = 0;
                GAME_COMM_RequestExitNoCallback(work->gameComm);
                return;
            }
        }
        break;
    case 1:
        if (GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle()) == 1) {
            work->step = 6;
            (*state)++;
        }
        break;
    case 2:
        EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(work->returnSlots);
        INTRUDE_COMM_RefreshSelfRecord((u8 *)work);
        INTRUDE_COMM_ApplyPlayerBeacon((u8 *)work, GFL_NET_SYSTEM_GetCurrentAid(), work->ownMyStatus);
        (*state)++;
        break;
    case 3:
        if (INTRUDE_COMM_SendStatusRecord(work) == 1) {
            work->step = 7;
            work->startTime = func_0203F4FC();
            (*state)++;
        }
        break;
    case 4:
        if (GAME_DATA_GetIntrudeCount(gameData) == 0 && work->localPeer.season != GAME_DATA_GetSeason(gameData)
            && GAMESYSTEM_IsFieldMapExist(param->gameSystem) == 1) {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
            return;
        }
        func_02174978((u8 *)work);
        if (INTRUDE_COMM_IsResultConfirmed(&work->session) == 1) {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
            return;
        }
        if (GFL_NET_IsParentAid() == 1 && INTRUDE_COMM_IsSessionActive(&work->session) == 0) {
            startTime = work->startTime;
            now = func_0203F4FC();
            if (now < startTime) {
                now += 86399;
            }
            now -= startTime;
            if (now >= 180) {
                GAME_COMM_RequestExitNoCallback(work->gameComm);
                return;
            }
            if (now > 170 && work->warned == 0 && INTRUDE_COMM_SendTimeoutWarning() == 1) {
                work->warned = 1;
            }
        } else if (work->lock == 0 && GFL_NET_IsParentAid() == 1
                   && INTRUDE_COMM_GetLeaveFlag(&work->session) == 1) {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
        } else {
            work->warned = 0;
        }
        if (INTRUDE_COMM_HasConnectedPeers() == 0) {
            work->idleFrames++;
            if (work->idleFrames > 180) {
                GAME_COMM_RequestExitNoCallback(work->gameComm);
                return;
            }
        } else {
            work->idleFrames = 0;
        }
        break;
    }
}







int INTRUDE_COMM_Shutdown(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    if (GAME_DATA_IsSaving((const u8 *)GAME_COMM_GetGameData(param->gameComm)) == 1) {
        return 0;
    }
    if (work->quit == 1 || func_0200FB24() != 0) {
        work->sessionEnded = 1;
        GFL_NET_Exit(INTRUDE_COMM_OnSessionExit);
        return 1;
    }
    switch (*state) {
    case 0:
        work->step = 9;
        if (GFL_NET_GetNegotiationNum() <= 1) {
            *state = 4;
        } else if (INTRUDE_COMM_SendShutdownRequest(work) == 1) {
            (*state)++;
        }
        break;
    case 1:
        work->waitFrames = 0;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 2);
        (*state)++;
        break;
    case 2:
        work->waitFrames++;
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 2) == 1 || work->waitFrames > 300) {
            GFL_NET_SetLoginOption(0);
            (*state)++;
        }
        break;
    case 3:
        work->waitFrames++;
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1 || work->waitFrames > 300) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        work->sessionEnded = 1;
        GFL_NET_Exit(INTRUDE_COMM_OnSessionExit);
        return 1;
    }
    return 0;
}







/*
 * 2026-10-05 (D8 lane19): re-verified, MATCH; unresolved relocations are arm9 0x02026680 and ov010 0x02161F68 (leaf witnesses in the note). Needs label seeds. Source is byte-correct; no C change possible.
 *
 * Byte-correct (416/416), 29 of 31 relocations resolved. The two
 * unresolved sites are leaves whose only caller image-wide is this
 * function (tu --suggest-split: not cuttable):
 *   +0076 EVENT_FIELD_PROCLINK_ClearReturnSlots (ov010, unlabelled 12-byte memset stub)
 *   +0168 GAME_COMM_ClearInfoMessages (arm9, unlabelled; the integrator's)
 * Because an arm9 leaf is among the blockers, the ov010 leaf is not filed.
 * Levers from the DIFF note (wave 82): the `b` to the next instruction at
 * +0x136 is the shared GAME_DATA_SetEnterMode(h, 1) call written in both arms of the
 * GAME_DATA_GetIntrudeCount(h) == 0 test (cross-jumped, see
 * docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md);
 * the register permutation disappeared once every callee took its matched
 * prototype (h a u32 cast at each call, me a u8, o a void ** parameter).
 *
 *   0x02026680 arm9 thumb, verified EXACT with
 *     `one --thumb --lang c99` (no --region):
 *     typedef unsigned char u8;
 *     typedef struct { u8 b0 : 1; u8 rest : 7; u8 pad[0xb]; } E;
 *     void GAME_COMM_ClearInfoMessages(u8 *p)
 *     {
 *         int i;
 *         for (i = 0; i < 6; i++) {
 *             ((E *)(p + 0x3f))[i].b0 = 0;
 *         }
 *         p[0x85] = 0;
 *         p[0x84] = 0;
 *     }
 *   0x02161F68 ov010 thumb (overlay leaf, not filed while the arm9 leaf
 *     blocks), verified EXACT with `one --thumb --region ov010 --lang c99`:
 */
int INTRUDE_COMM_Destroy(int unused, void **proc, IntrudeCommSys *work)
{
    struct GameComm *gameComm;
    int ok;
    u32 gameData;
    u8 *palaceList;
    u8 myNetId;
    int i;

    gameComm = proc[1];
    gameData = (u32)GAME_COMM_GetGameData(gameComm);
    ok = 0;
    if (GAME_DATA_IsSaving((const u8 *)gameData) == 1) {
        return ok;
    }
    if (work->step == 10 || GFL_NET_IsSessionNull() == 1) {
        if (GAME_DATA_GetIntrudeCount((struct GameData *)gameData) == 0) {
            func_0200FBA0();
            ok = 1;
        } else if (ZONEDATA_IsZone117(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct GameData *)gameData))) == 1
                   && GAMESYSTEM_IsFieldMapExist(proc[0]) == 1
                   && FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(proc[0])) == 1) {
            ok = 1;
        }
    }
    if (ok == 1) {
        EVENT_FIELD_PROCLINK_ClearReturnSlots(work->returnSlots);
        GAME_DATA_ClearUnionInfo((u8 *)gameData);
        COMM_PLAYER_Delete(proc[0], work->commPlayer);
        if (work->quit == 1 || func_0200FB24() != 0) {
            GAME_COMM_SetCounter(gameComm, 5);
        } else if (INTRUDE_COMM_HasResult(&work->session) == 1) {
            if (work->abortFlag == 1) {
                GAME_COMM_SetCounter(gameComm, 4);
            } else if (INTRUDE_COMM_HasResultReward(work, &work->session) == 1) {
                GAME_COMM_SetCounter(gameComm, 2);
            } else {
                palaceList = INTRUDE_COMM_GetSessionResult(&work->session);
                myNetId = GAME_DATA_GetExitMode((struct GameData *)gameData);
                for (i = 0; i < 3; i++) {
                    if (palaceList[0x34 + i] != 4 && myNetId != palaceList[0x34 + i]) {
                        break;
                    }
                }
                if (i < 3) {
                    GAME_COMM_SetCounter(gameComm, 3);
                } else {
                    GAME_COMM_SetCounter(gameComm, 4);
                }
            }
        } else if (work->peerMask > 1) {
            GAME_COMM_SetCounter(gameComm, 1);
        }
        if (GAME_DATA_GetIntrudeCount((struct GameData *)gameData) == 0) {
            GAME_DATA_SetExitMode((struct GameData *)gameData, 0);
            GAME_DATA_SetIntrudeId((struct GameData *)gameData, 0);
            GAME_DATA_SetEnterMode((struct GameData *)gameData, 1);
        } else {
            GAME_DATA_SetEnterMode((struct GameData *)gameData, 1);
        }
        if ((work->quit == 1 || func_0200FB24() != 0) && GAME_DATA_GetIntrudeCount((struct GameData *)gameData) == 1) {
            GAMESYSTEM_SetFieldMapState(proc[0], 1);
        }
        GAME_COMM_ClearInfoMessages(gameComm);
        for (i = 0; i < 2; i++) {
            STRBUF_Delete(work->foundNames[i]);
        }
        func_020307B0(work);
        func_020307B0(proc);
        return 1;
    }
    return 0;
}







/*
 * Addresses are Black-image addresses.
 */
void INTRUDE_COMM_ScanCallback(void *whPipe, IntrudeCommSys *work)
{
    u8 recordKind;
    IntrudeScanRecord *record;
    int i;

    if (work->foundCount >= 2) {
        return;
    }
    if (GFL_NET_GetNegotiationNum() > 1) {
        return;
    }
    if (work->quit == 1) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    if (WIH_IsMatchingParent(whPipe) == 0) {
        return;
    }
    if (NET_WHPIPE_CheckBeaconFlags(whPipe, ~0x10) == 0) {
        return;
    }
    record = NET_WHPIPE_GetEntryBeacon(whPipe, &recordKind);
    if (recordKind != 3) {
        return;
    }
    if (record->excluded) {
        return;
    }
    for (i = 0; i < work->foundCount; i++) {
        if (record->trainerId == work->foundTrainerIds[i]) {
            return;
        }
    }
    if ((int)ZONEDATA_IsZone117((u16)record->info.zoneId) == 1) {
        return;
    }
    if (INTRUDE_COMM_IsListedId(record->info.zoneId) == 0) {
        return;
    }
    GAME_BEACON_ACCESSOR_GetPlayerName(&record->info, work->foundNames[work->foundCount]);
    work->foundSex[work->foundCount] = GAME_BEACON_ACCESSOR_GetSex(&record->info);
    work->foundLanguage[work->foundCount] = GAME_BEACON_ACCESSOR_GetLanguage(&record->info);
    work->foundTrainerIds[work->foundCount] = record->trainerId;
    work->foundAge = 0;
    work->foundCount++;
}






void INTRUDE_COMM_SyncPlayers(IntrudeCommSys *work, IntrudeCommSys *peerWork, int fieldObjectAddr)
{
    struct GameData *gameData;
    int myNetId;
    int i;
    IntrudePlayerPackage package;

    if (peerWork == 0) {
        return;
    }
    gameData = GAME_COMM_GetGameData(work->gameComm);
    myNetId = GAME_DATA_GetExitMode(gameData);
    if (GAME_DATA_GetIntrudeCount(gameData) == 0) {
        if (INTRUDE_FIELD_IsListedZone(FIELDMAP_GetZoneId((u8 *)fieldObjectAddr)) == 1) {
            COMM_PLAYER_Resume(peerWork->commPlayer);
        } else {
            COMM_PLAYER_ClearPending(peerWork->commPlayer);
        }
    } else {
        COMM_PLAYER_Resume(peerWork->commPlayer);
    }
    for (i = 0; i < 3; i++) {
        if (i != myNetId && COMM_PLAYER_CheckOccupy(peerWork->commPlayer, i) == 1) {
            peerWork->peers[i].package.vanish = peerWork->peers[i].remoteVanish;
            package = peerWork->peers[i].package;
            package.vanish = 1;
            COMM_PLAYER_SetPackage(peerWork->commPlayer, i, &package);
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != myNetId && (peerWork->peerMask & (1 << i))) {
            int remoteVanish = peerWork->peers[i].remoteVanish;
            INTRUDE_COMM_StorePlayerRecord((u8 *)peerWork, i, &peerWork->peers[i], 0);
            peerWork->peers[i].remoteVanish = remoteVanish;
        }
    }
}





/*
 * Extent contains followers 02173568, already-filed 02173580, and 0217358C;
 * the lead stays separate to preserve the existing follower file.
 */
void INTRUDE_COMM_SuspendPlayers(int arg, IntrudeCommSys *work)
{
    if (work != 0)
        COMM_PLAYER_Suspend(work->commPlayer);
}






void INTRUDE_COMM_OnSessionStarted(IntrudeCommSys *work)
{
    work->step = 2;
    WIH_SetBeaconFoundCallback((u32)INTRUDE_COMM_ScanCallback);
}




/*
 * Callback leaf: sets the state byte at 0x8FD to 10.  It saves nothing, so
 * disasm.py left it as .word data; its only reference is the function
 * pointer INTRUDE_COMM_Shutdown hands to GFL_NET_Exit, which is why it is filed
 * here, to give that pool word a matched witness.
 */
void INTRUDE_COMM_OnSessionExit(IntrudeCommSys *work)
{
    work->step = 10;
}



IntrudeBeacon *INTRUDE_COMM_GetBeacon(IntrudeCommSys *work) { return &work->beacon; }




void INTRUDE_COMM_InitBeacon(struct GameData *gameData, IntrudeBeacon *beacon, int maxConnect)
{
    beacon->gameKind = 2;
    beacon->connectNum = GFL_NET_GetNegotiationNum();
    if (maxConnect != -1)
        beacon->maxConnect = maxConnect;
    beacon->hasNetError = GFL_NET_SYSTEM_CheckError();
    beacon->version = 1;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus(gameData), beacon->ownerStatus);
}




int INTRUDE_COMM_RefreshBeacon(struct GameData *gameData, IntrudeBeacon *beacon)
{
    if (beacon->connectNum != GFL_NET_GetNegotiationNum() || beacon->hasNetError != GFL_NET_SYSTEM_CheckError()) {
        INTRUDE_COMM_InitBeacon(gameData, beacon, -1);
        NET_WHPIPE_PublishBeacon();
        return 1;
    }
    return 0;
}


int INTRUDE_COMM_IsEqual(int left, int right)
{
    if (left == right)
        return 1;
    return 0;
}


void INTRUDE_COMM_RecvQuit(int netId, int size, IntrudeCommSys *work)
{
    work->quit = 1;
}


void INTRUDE_COMM_Nop(void)
{
}
