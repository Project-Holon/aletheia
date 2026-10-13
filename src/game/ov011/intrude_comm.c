/*
 * file:     intrude_comm.c
 * unit:     yes
 * function: INTRUDE_COMM_Create, INTRUDE_COMM_StartSession, func_02172D70, INTRUDE_COMM_Shutdown, INTRUDE_COMM_Destroy, INTRUDE_COMM_ScanCallback, INTRUDE_COMM_SyncPlayers, INTRUDE_COMM_SuspendPlayers, INTRUDE_COMM_OnSessionStarted, INTRUDE_COMM_OnSessionExit, INTRUDE_COMM_GetBeacon, INTRUDE_COMM_InitBeacon, func_021735FC, INTRUDE_COMM_IsEqual, INTRUDE_COMM_RecvQuit, INTRUDE_COMM_Nop
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
 *   func_02026478  0x02026478  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   str_02177000   0x02177000  data  ov011  a1
 *   func_02167518  0x02167518  thumb  ov010
 *   func_0217538C  0x0217538C  thumb  ov011
 *   INTRUDE_COMM_InitSession  0x0217576C  thumb  ov011
 *   func_02161F54  0x02161F54  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_StartChangeoverParent  0x0203D10C  arm
 *   GFL_NET_ConnectMacAddressParent  0x0203CFF0  arm
 *   d_02177000     0x02177000  data  ov011
 *   d_021768C8     0x021768C8  data  a4
 *   func_020127C4  0x020127C4  thumb
 *   func_02161F74  0x02161F74  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   INTRUDE_COMM_AgeFoundList  0x02173658  thumb  ov011
 *   func_020392B8  0x020392B8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02012984  0x02012984  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   INTRUDE_COMM_RefreshSelfRecord  0x02174E3C  thumb  ov011
 *   INTRUDE_COMM_ApplyPlayerBeacon  0x02174EAC  thumb  ov011
 *   INTRUDE_COMM_SendStatusRecord  0x02173828  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_02012B70  0x02012B70  thumb
 *   func_02012114  0x02012114  thumb
 *   func_02174978  0x02174978  thumb  ov011
 *   INTRUDE_COMM_IsResultConfirmed  0x02175EB8  thumb  ov011
 *   func_0203D378  0x0203D378  arm
 *   func_02175B14  0x02175B14  thumb  ov011
 *   INTRUDE_COMM_SendTimeoutWarning  0x021739E0  thumb  ov011
 *   INTRUDE_COMM_GetLeaveFlag  0x02175ED8  thumb  ov011
 *   INTRUDE_COMM_HasConnectedPeers  0x02175628  thumb  ov011
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   INTRUDE_COMM_SendShutdownRequest  0x021736EC  thumb  ov011
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02161F68  0x02161F68  thumb  ov010
 *   GAME_DATA_ClearUnionInfo  0x0201281C  thumb
 *   func_0216754C  0x0216754C  thumb  ov010
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   GAME_COMM_SetCounter  0x02026480  thumb
 *   func_02012124  0x02012124  thumb
 *   GAME_COMM_ClearInfoMessages  0x02026680  thumb
 *   func_02045808  0x02045808  arm
 *   WIH_IsMatchingParent  0x0217873C  thumb  ov014
 *   func_02177494  0x02177494  thumb  ov014
 *   func_02177BFC  0x02177BFC  thumb  ov014
 *   func_02158570  0x02158570  thumb  ov010
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C50  0x02165C50  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0217C11C  0x0217C11C  thumb  ov018
 *   func_02167794  0x02167794  thumb  ov010
 *   func_021676E4  0x021676E4  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   INTRUDE_COMM_StorePlayerRecord  0x02174F54  thumb  ov011
 *   func_02167688 0x02167688 thumb ov010
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   func_0217778C  0x0217778C  thumb  ov014
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

extern struct GameData *func_02026478(struct GameComm *gameComm);
extern u8 *func_02012944(struct GameData *gameData);
extern int   func_02158590(struct GameData *gameData);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern struct CommPlayerWork *func_02167518(int playerNum, void *gameSystem, u16 heapId, int mode);
extern void func_0217538C(u8 *work, int arg);
extern void INTRUDE_COMM_InitSession(IntrudeSession *session);
extern int func_02161F54(void *returnSlots);
extern struct STRBUF *func_020457B0(u32 capacity, u32 heapId);
extern void func_02012B64(struct GameData *gameData, u32 exitMode);
extern void func_02012B8C(struct GameData *gameData, u32 intrudeId);
extern void func_02012B4C(struct GameData *gameData, u8 enterMode);
extern struct PlayerStatus *func_02012950(struct GameData *gameData, u32 index);
extern void  func_02008494(void *src, void *dst);
extern u8 func_02012E40(const u8 *gameData);
extern void func_0203CBAC(GFLNetInitializeStruct *init, u32 callback, u32 userArg);
extern u32 func_020307B0(void *memory);
extern int GFL_NET_StartChangeoverParent(int arg);
extern void GFL_NET_ConnectMacAddressParent(void *macAddress);
extern u8 *func_020127C4(struct GameData *gameData);
extern void func_02161F74(void *returnSlots, int unionInfo, int peerMask);
extern u32 func_0200FB24(void);
extern void func_02026400(struct GameComm *gameComm);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern void INTRUDE_COMM_AgeFoundList(IntrudeCommSys *work);
extern int   func_020392B8(void);
extern void func_0203D7BC(u8 loginOption);
extern int func_02039ACC(void);
extern u16 func_02039338(void);
extern void func_02175710(u8 *work, u32 netId);
extern u8 func_02012984(const struct GameData *gameData);
extern GFLNetHandle *func_020399A8(void);
extern u32 func_020399B8(GFLNetHandle *handle);
extern void INTRUDE_COMM_RefreshSelfRecord(u8 *work);
extern void INTRUDE_COMM_ApplyPlayerBeacon(u8 *work, int netId, u8 *record);
extern int INTRUDE_COMM_SendStatusRecord(IntrudeCommSys *work);
extern u32 func_0203F4FC(void);
extern int func_02012B70(const struct GameData *gameData);
extern u32   func_02012114(const struct GameSystem *gameSystem);
extern void func_02174978(u8 *work);
extern int   INTRUDE_COMM_IsResultConfirmed(void *session);
extern u32 func_0203D378(void);
extern int func_02175B14(IntrudeSession *session);
extern int   INTRUDE_COMM_SendTimeoutWarning(void);
extern int INTRUDE_COMM_GetLeaveFlag(void *session);
extern int   INTRUDE_COMM_HasConnectedPeers(void);
extern int func_0203CEAC(void (*exitCallback)(IntrudeCommSys *work));
extern int   func_0203D1B4(void);
extern void func_02039C68(GFLNetHandle *handle, u32 timingNo, u32 option);
extern u32 func_02039CB4(GFLNetHandle *handle, u32 timingNo, u32 option);
extern int func_0203CDBC(void);
extern int INTRUDE_COMM_SendShutdownRequest(IntrudeCommSys *work);
extern void func_0200FBA0(void);
extern void *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const void *myPlayerWork);
extern u32 func_02013D5C(u32 zoneId);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern int func_02188BE8(void *fieldMap);
extern void func_02161F68(void *returnSlots);
extern void GAME_DATA_ClearUnionInfo(u8 *gameData);
extern void func_0216754C(void *gameSystem, struct CommPlayerWork *commPlayer);
extern int func_02175DA8(IntrudeSession *session);
extern int func_02175E90(void *work, IntrudeSession *session);
extern u8 *func_02175BCC(IntrudeSession *session);
extern u8 func_02012B58(const struct GameData *gameData);
extern void GAME_COMM_SetCounter(struct GameComm *gameComm, u32 counter);
extern void func_02012124(struct GameSystem *gameSystem, u32 state);
extern void GAME_COMM_ClearInfoMessages(struct GameComm *gameComm);
extern void func_02045808(struct STRBUF *buf);
extern int WIH_IsMatchingParent(void *whPipe);
extern int func_02177494(void *whPipe, u32 flags);
extern IntrudeScanRecord *func_02177BFC(void *whPipe, u8 *kind);
extern int func_02158570(u16 zoneId);
extern void func_02165C34(const GameBeaconInfo *info, struct STRBUF *name);
extern u8 func_02165D08(const GameBeaconInfo *info);
extern u8 func_02165C50(const GameBeaconInfo *info);
extern u16 func_02188C9C(u8 *fieldObject);
extern int func_0217C11C(u32 value);
extern void func_02167794(struct CommPlayerWork *commPlayer);
extern void func_021676E4(struct CommPlayerWork *commPlayer);
extern int func_021677E4(struct CommPlayerWork *commPlayer, int index);
extern void func_02167848(struct CommPlayerWork *commPlayer, int index, IntrudePlayerPackage *package);
extern void INTRUDE_COMM_StorePlayerRecord(u8 *work, int netId, const IntrudePeer *peer, int arg);
extern void func_02167688(struct CommPlayerWork *commPlayer);
extern void WIH_SetBeaconFoundCallback(u32 callback);
extern u32 GFL_NET_SYSTEM_CheckError(void);
extern void func_0217778C(void);
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
int func_021735FC(struct GameData *gameData, IntrudeBeacon *beacon);
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

    gameData = func_02026478(param->gameComm);
    myStatus = func_02012944(gameData);
    maxConnect = 3;
    if (param->isParent == 1 && func_02158590(gameData) == 0) {
        maxConnect = 2;
    }
    work = func_02030734(5, sizeof(IntrudeCommSys), 1, str_02177000, 0x9a);
    work->gameSystem = param->gameSystem;
    work->gameComm = param->gameComm;
    work->step = 1;
    work->commPlayer = func_02167518(3, param->gameSystem, 5, 0);
    work->memberCount = 1;
    work->lastAreaIndex = 1;
    func_0217538C((u8 *)work, 4);
    INTRUDE_COMM_InitSession(&work->session);
    INTRUDE_COMM_InitBeacon(gameData, &work->beacon, maxConnect);
    func_02161F54(work->returnSlots);
    for (i = 0; i < 2; i++) {
        work->foundNames[i] = func_020457B0(8, 5);
    }
    func_02012B64(gameData, 0);
    func_02012B8C(gameData, 0);
    func_02012B4C(gameData, 1);
    for (netId = 0; netId < 3; netId++) {
        func_02008494(myStatus, func_02012950(gameData, netId));
    }
    return work;
}







/*
 * recoup 2026-10-05: the old draft (196 B, work as u8* with work[0x8fd]) failed on register
 * colours and a second pool load of 0x8fd. Typed parameters closed it to 192 B, all bytes equal:
 * param as a struct with the byte at 0x0E, work as a struct with the step byte at 0x8FD (written
 * work->step = 3 / 4 in each arm, no local), callee types from matched twins (func_02026478 and
 * func_02030734 return u32, func_02012E40 takes const u8 *). The only open item is the pool
 * word INTRUDE_COMM_OnSessionStarted: the leaf is filed at src/matched/ov/ov011_func_02173568.c (EXACT);
 * the integrator needs a shard for it, then this file is EXACT.
 */
int INTRUDE_COMM_StartSession(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    u8 *gameData;
    GFLNetInitializeStruct *init;

    gameData = (u8 *)func_02026478(param->gameComm);
    if (func_02012E40(gameData) == 1)
        return 0;
    switch (*state) {
    case 0:
        init = (GFLNetInitializeStruct *)func_02030734(0x8005, 0x70, 0, d_02177000, 0xcf);
        *init = d_021768C8;
        if (param->isParent == 1) {
            if (func_02158590((struct GameData *)gameData) == 0)
                init->maxConnectNum = 2;
        }
        func_0203CBAC(init, (u32)INTRUDE_COMM_OnSessionStarted, (u32)work);
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
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
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

    gameData = func_02026478(param->gameComm);
    if (work != 0 && work->step >= 7) {
        func_02161F74(work->returnSlots, (int)func_020127C4(gameData), work->peerMask);
    }
    if (func_0200FB24() != 0 || work->quit == 1) {
        if (work->lock) {
            return;
        }
        work->step = 11;
        work->quit = 1;
        func_02026400(work->gameComm);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1 && work->lock == 0) {
        func_02026400(work->gameComm);
        return;
    }
    if (work->step == 7 && work->shutdownRequested == 1) {
        func_02026400(work->gameComm);
        return;
    }
    func_021735FC(gameData, &work->beacon);
    INTRUDE_COMM_AgeFoundList(work);
    switch (*state) {
    case 0:
        if (func_020392B8() > 1 && work->step < 5) {
            work->step = 5;
            func_0203D7BC(1);
        }
        if (work->step == 5) {
            if (func_02039ACC() == 1) {
                func_02012B64(gameData, func_02039338());
                playerStatus = func_02012950(gameData, func_02039338());
                func_02008494(func_02012944(gameData), playerStatus);
                func_02175710((u8 *)work, func_02039338());
                work->localPeer.statusCode = 0x15;
                work->localPeer.season = func_02012984(gameData);
                if (func_02158590(gameData) == 0) {
                    work->localPeer.startFlag = 1;
                }
                func_0203D7BC(1);
                (*state)++;
            }
        } else if (work->step == 4) {
            work->waitFrames++;
            if (work->waitFrames > 600) {
                work->waitFrames = 0;
                func_02026400(work->gameComm);
                return;
            }
        }
        break;
    case 1:
        if (func_020399B8(func_020399A8()) == 1) {
            work->step = 6;
            (*state)++;
        }
        break;
    case 2:
        func_02161F54(work->returnSlots);
        INTRUDE_COMM_RefreshSelfRecord((u8 *)work);
        INTRUDE_COMM_ApplyPlayerBeacon((u8 *)work, func_02039338(), work->ownMyStatus);
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
        if (func_02012B70(gameData) == 0 && work->localPeer.season != func_02012984(gameData)
            && func_02012114(param->gameSystem) == 1) {
            func_02026400(work->gameComm);
            return;
        }
        func_02174978((u8 *)work);
        if (INTRUDE_COMM_IsResultConfirmed(&work->session) == 1) {
            func_02026400(work->gameComm);
            return;
        }
        if (func_0203D378() == 1 && func_02175B14(&work->session) == 0) {
            startTime = work->startTime;
            now = func_0203F4FC();
            if (now < startTime) {
                now += 86399;
            }
            now -= startTime;
            if (now >= 180) {
                func_02026400(work->gameComm);
                return;
            }
            if (now > 170 && work->warned == 0 && INTRUDE_COMM_SendTimeoutWarning() == 1) {
                work->warned = 1;
            }
        } else if (work->lock == 0 && func_0203D378() == 1
                   && INTRUDE_COMM_GetLeaveFlag(&work->session) == 1) {
            func_02026400(work->gameComm);
        } else {
            work->warned = 0;
        }
        if (INTRUDE_COMM_HasConnectedPeers() == 0) {
            work->idleFrames++;
            if (work->idleFrames > 180) {
                func_02026400(work->gameComm);
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
    if (func_02012E40((const u8 *)func_02026478(param->gameComm)) == 1) {
        return 0;
    }
    if (work->quit == 1 || func_0200FB24() != 0) {
        work->sessionEnded = 1;
        func_0203CEAC(INTRUDE_COMM_OnSessionExit);
        return 1;
    }
    switch (*state) {
    case 0:
        work->step = 9;
        if (func_0203D1B4() <= 1) {
            *state = 4;
        } else if (INTRUDE_COMM_SendShutdownRequest(work) == 1) {
            (*state)++;
        }
        break;
    case 1:
        work->waitFrames = 0;
        func_02039C68(func_020399A8(), 0x14, 2);
        (*state)++;
        break;
    case 2:
        work->waitFrames++;
        if (func_02039CB4(func_020399A8(), 0x14, 2) == 1 || work->waitFrames > 300) {
            func_0203D7BC(0);
            (*state)++;
        }
        break;
    case 3:
        work->waitFrames++;
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1 || work->waitFrames > 300) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        work->sessionEnded = 1;
        func_0203CEAC(INTRUDE_COMM_OnSessionExit);
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
 *   +0076 func_02161F68 (ov010, unlabelled 12-byte memset stub)
 *   +0168 GAME_COMM_ClearInfoMessages (arm9, unlabelled; the integrator's)
 * Because an arm9 leaf is among the blockers, the ov010 leaf is not filed.
 * Levers from the DIFF note (wave 82): the `b` to the next instruction at
 * +0x136 is the shared func_02012B4C(h, 1) call written in both arms of the
 * func_02012B70(h) == 0 test (cross-jumped, see
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
    gameData = (u32)func_02026478(gameComm);
    ok = 0;
    if (func_02012E40((const u8 *)gameData) == 1) {
        return ok;
    }
    if (work->step == 10 || func_0203CDBC() == 1) {
        if (func_02012B70((struct GameData *)gameData) == 0) {
            func_0200FBA0();
            ok = 1;
        } else if (func_02013D5C(func_02012AC8(func_020127A4((struct GameData *)gameData))) == 1
                   && func_02012114(proc[0]) == 1
                   && func_02188BE8(func_0201210C(proc[0])) == 1) {
            ok = 1;
        }
    }
    if (ok == 1) {
        func_02161F68(work->returnSlots);
        GAME_DATA_ClearUnionInfo((u8 *)gameData);
        func_0216754C(proc[0], work->commPlayer);
        if (work->quit == 1 || func_0200FB24() != 0) {
            GAME_COMM_SetCounter(gameComm, 5);
        } else if (func_02175DA8(&work->session) == 1) {
            if (work->abortFlag == 1) {
                GAME_COMM_SetCounter(gameComm, 4);
            } else if (func_02175E90(work, &work->session) == 1) {
                GAME_COMM_SetCounter(gameComm, 2);
            } else {
                palaceList = func_02175BCC(&work->session);
                myNetId = func_02012B58((struct GameData *)gameData);
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
        if (func_02012B70((struct GameData *)gameData) == 0) {
            func_02012B64((struct GameData *)gameData, 0);
            func_02012B8C((struct GameData *)gameData, 0);
            func_02012B4C((struct GameData *)gameData, 1);
        } else {
            func_02012B4C((struct GameData *)gameData, 1);
        }
        if ((work->quit == 1 || func_0200FB24() != 0) && func_02012B70((struct GameData *)gameData) == 1) {
            func_02012124(proc[0], 1);
        }
        GAME_COMM_ClearInfoMessages(gameComm);
        for (i = 0; i < 2; i++) {
            func_02045808(work->foundNames[i]);
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
    if (func_0203D1B4() > 1) {
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
    if (func_02177494(whPipe, ~0x10) == 0) {
        return;
    }
    record = func_02177BFC(whPipe, &recordKind);
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
    if ((int)func_02013D5C((u16)record->info.zoneId) == 1) {
        return;
    }
    if (func_02158570(record->info.zoneId) == 0) {
        return;
    }
    func_02165C34(&record->info, work->foundNames[work->foundCount]);
    work->foundSex[work->foundCount] = func_02165D08(&record->info);
    work->foundLanguage[work->foundCount] = func_02165C50(&record->info);
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
    gameData = func_02026478(work->gameComm);
    myNetId = func_02012B58(gameData);
    if (func_02012B70(gameData) == 0) {
        if (func_0217C11C(func_02188C9C((u8 *)fieldObjectAddr)) == 1) {
            func_021676E4(peerWork->commPlayer);
        } else {
            func_02167794(peerWork->commPlayer);
        }
    } else {
        func_021676E4(peerWork->commPlayer);
    }
    for (i = 0; i < 3; i++) {
        if (i != myNetId && func_021677E4(peerWork->commPlayer, i) == 1) {
            peerWork->peers[i].package.vanish = peerWork->peers[i].remoteVanish;
            package = peerWork->peers[i].package;
            package.vanish = 1;
            func_02167848(peerWork->commPlayer, i, &package);
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
        func_02167688(work->commPlayer);
}






void INTRUDE_COMM_OnSessionStarted(IntrudeCommSys *work)
{
    work->step = 2;
    WIH_SetBeaconFoundCallback((u32)INTRUDE_COMM_ScanCallback);
}




/*
 * Callback leaf: sets the state byte at 0x8FD to 10.  It saves nothing, so
 * disasm.py left it as .word data; its only reference is the function
 * pointer INTRUDE_COMM_Shutdown hands to func_0203CEAC, which is why it is filed
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
    beacon->connectNum = func_0203D1B4();
    if (maxConnect != -1)
        beacon->maxConnect = maxConnect;
    beacon->hasNetError = GFL_NET_SYSTEM_CheckError();
    beacon->version = 1;
    func_02008494(func_02012944(gameData), beacon->ownerStatus);
}




int func_021735FC(struct GameData *gameData, IntrudeBeacon *beacon)
{
    if (beacon->connectNum != func_0203D1B4() || beacon->hasNetError != GFL_NET_SYSTEM_CheckError()) {
        INTRUDE_COMM_InitBeacon(gameData, beacon, -1);
        func_0217778C();
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
