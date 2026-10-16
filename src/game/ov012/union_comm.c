/*
 * file:     union_comm.c
 * unit:     yes
 * function: UNION_COMM_Create, UNION_COMM_Delete, UNION_COMM_InitComm, UNION_COMM_InitWait, UNION_COMM_SessionStartCallback, UNION_COMM_Exit, UNION_COMM_ExitWait, UNION_COMM_ExitCallback, UNION_COMM_RequestRestart, UNION_COMM_RequestShutdown, UNION_COMM_RequestStart, UNION_COMM_IsResetting, UNION_COMM_UpdateReset, UNION_COMM_Update, UNION_COMM_StartConnectSync, UNION_COMM_UpdateConnectSync, UNION_COMM_SendEntryReplies, UNION_COMM_UpdateColosseum, UNION_COMM_UpdateBeaconScan, UNION_COMM_StoreBeacon, UNION_COMM_IsNotGroupMember, UNION_COMM_GetBeacon, UNION_COMM_BuildBeacon, UNION_COMM_GetBeaconSize, UNION_COMM_CompareBeacon, UNION_COMM_StateChangeCallback, UNION_COMM_ConnectEndCallback, UNION_COMM_ClearBeaconPcs, UNION_COMM_ReleaseWorks, UNION_COMM_SetSituationParam, UNION_COMM_InitSituation, UNION_COMM_ClearPartnerSelects, UNION_COMM_InitConnectInfo, UNION_COMM_AddMember, UNION_COMM_AddMemberFromBeaconPc, UNION_COMM_RemoveMember, UNION_COMM_RemoveMemberOfBeaconPc, UNION_COMM_InitChatLog, UNION_COMM_SetChatPms, UNION_COMM_SetChatType, UNION_COMM_SetGameKindByStatus
 * address:  0x02172BC0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from union_comm.c, unit_0217422C.c, colosseum.c, ov012_func_02175358.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   REGULATION_Create  0x0200ADF0  thumb
 *   sUnionCommFile   0x02175600  data  ov012  a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   sUnionNetInit 0x02175380 data ov012 a4
 *   GFL_NET_EndDeviceWrapper 0x0203D0FC arm
 *   GFL_NET_SetErrorCheckEnabled  0x0203D8C4  arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_ResetState 0x0200FBA0 thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   NET_WHPIPE_PublishBeacon  0x0217778C  thumb  ov014
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   MATH_CountPopulation  0x02080D24  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   COMM_PLAYER_Update  0x02167590  thumb  ov010
 *   COMM_PLAYER_UpdateMyPackage  0x0216786C  thumb  ov010
 *   COLOSSEUM_SendPackage  0x02174C90  thumb  ov012
 *   COLOSSEUM_UpdateCommPlayers  0x0217FF78  thumb  ov019
 *   COLOSSEUM_FlushChoiceReplies  0x02175110  thumb  ov012
 *   COLOSSEUM_UpdateReadyState  0x02175144  thumb  ov012
 *   GFL_NET_GetScanResult 0x0203CF10 arm
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm
 *   NET_WHPIPE_ReleaseEntry 0x02177BF4 thumb ov014
 *   memcmp            0x0203EFC8  arm
 *   MI_CpuCopy8       0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   WIFILIST_MakeExchangeToken  0x02009CB0  thumb
 *   UNION_APP_IsClosed  0x021840C8  thumb  ov022
 *   UNION_APP_Delete  0x02183BE0  thumb  ov022
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   func_020056EC 0x020056EC thumb
 *   GFL_NET_SetGameKind  0x0203D5AC  arm
 *   UNION_COMM_SetGameKindByStatus  0x021736E0  thumb  ov012
 *   UNION_MAIN_IsFieldReady 0x02173840 thumb ov012
 *   UNION_COMMAND_SendConnectSync 0x021739CC thumb ov012
 *   UNION_COMMAND_SendAppEntryRefused 0x02173D88 thumb ov012
 *   UNION_COMMAND_SendAppEntryAccepted 0x02173DBC thumb ov012
 */
typedef struct { int x, y, z; } VecFx32;

#include "union_comm_types.h"
#include "../arm9/net_types.h"

extern void GFL_HEAP_CreateChildHeap(u32 parentHeapId, u32 heapId, u32 size);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern struct Regulation *REGULATION_Create(u32 heapId);

extern u32 GFL_HEAP_Free(void *memory);

extern void GFL_HEAP_DeleteChecked(u32 heapId);

extern void GFL_NET_StartSession(const GFLNetInitializeStruct *init, void (*startCallback)(UnionRoomWork *work), UnionRoomWork *work);

extern void GFL_NET_EndDeviceWrapper(int flag);

extern void GFL_NET_SetErrorCheckEnabled(u32 enable);

extern int GFL_NET_Exit(void (*exitCallback)(UnionRoomWork *work));

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern void GFL_NET_ERR_ResetState(void);

extern int GFL_NET_GetRunState(void);

extern void NET_WHPIPE_PublishBeacon(void);

extern u32 GFL_NET_IsParentAid(void);

extern int MATH_CountPopulation(u8 bits);

extern int GFL_NET_GetNegotiationNum(void);

extern void GFL_NET_SetLoginOption(u8 option);

extern int UNION_MAIN_IsScenePending(UnionRoomWork *work);

extern void COMM_PLAYER_Update(struct GameSystem *gameSystem, void *commPlayer);

extern int COMM_PLAYER_UpdateMyPackage(void *commPlayer, CommPlayerPackage *package);

extern u32 COLOSSEUM_SendPackage(const CommPlayerPackage *package);

extern void COLOSSEUM_UpdateCommPlayers(ColosseumWork *colosseum);

extern void COLOSSEUM_FlushChoiceReplies(ColosseumWork *colosseum);

extern void COLOSSEUM_UpdateReadyState(ColosseumWork *colosseum);

extern UnionBeacon *GFL_NET_GetScanResult(int index);

extern const u8 *GFL_NET_GetScanResultMac(int index);

extern void NET_WHPIPE_ReleaseEntry(u32 index);

extern int memcmp(const void *lhs, const void *rhs, int size);

extern void MI_CpuCopy8(const void *src, void *dst, int size);

extern void MI_CpuFill8(void *dst, int value, int size);

extern void OS_GetMacAddress(void *mac);

extern u32 func_020084F8(const struct MyStatus *status, u16 *dest, u32 size);

extern u8 func_02008554(const struct MyStatus *status);

extern u32 func_02008550(const struct MyStatus *status);

extern u32 func_02008530(const struct MyStatus *status);

extern u8 func_0200856C(const struct MyStatus *status);

extern u8 func_02008570(const struct MyStatus *status);

extern struct GameData *ICA_ANIME_GetField1C(struct GameSystem *gameSystem);

extern struct WifiList *GAME_DATA_GetField1A0(struct GameData *gameData);

extern int WIFILIST_MakeExchangeToken(struct WifiList *wifiList, u8 *friendKey);

extern int UNION_APP_IsClosed(struct UnionAppWork *app);

extern void UNION_APP_Delete(struct UnionAppWork *app);

extern void COLOSSEUM_Delete(ColosseumWork *colosseum, struct GameSystem *gameSystem);

extern u32 func_020056EC(u32 range);

extern void GFL_NET_SetGameKind(int gameKind, int option);

UnionRoomWork *UNION_COMM_Create(UnionParentWork *parent);

void UNION_COMM_Delete(UnionParentWork *parent, UnionRoomWork *work);

UnionRoomWork *UNION_COMM_InitComm(int *seq, UnionParentWork *parent);

int UNION_COMM_InitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work);

void UNION_COMM_SessionStartCallback(UnionRoomWork *work);

int UNION_COMM_Exit(int *seq, UnionParentWork *parent, UnionRoomWork *work);

int UNION_COMM_ExitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work);

void UNION_COMM_ExitCallback(UnionRoomWork *work);

void UNION_COMM_RequestRestart(UnionRoomWork *work);

void UNION_COMM_RequestShutdown(UnionRoomWork *work);

void UNION_COMM_RequestStart(UnionRoomWork *work);

int UNION_COMM_IsResetting(UnionRoomWork *work);

int UNION_COMM_UpdateReset(UnionRoomWork *work);

void UNION_COMM_Update(int *seq, UnionParentWork *parent, UnionRoomWork *work);

void UNION_COMM_StartConnectSync(UnionRoomWork *work);

void UNION_COMM_UpdateConnectSync(UnionRoomWork *work);

void UNION_COMM_SendEntryReplies(UnionRoomWork *work);

void UNION_COMM_UpdateColosseum(UnionRoomWork *work);

void UNION_COMM_UpdateBeaconScan(UnionRoomWork *work);

int UNION_COMM_StoreBeacon(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac);

int UNION_COMM_IsNotGroupMember(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac);

UnionBeacon *UNION_COMM_GetBeacon(UnionRoomWork *work);

void UNION_COMM_BuildBeacon(UnionRoomWork *work, UnionBeacon *beacon);

int UNION_COMM_GetBeaconSize(void);

int UNION_COMM_CompareBeacon(u32 myServiceId, u32 beaconServiceId, UnionRoomWork *work);

void UNION_COMM_StateChangeCallback(void);

void UNION_COMM_ConnectEndCallback(void);

void UNION_COMM_ClearBeaconPcs(UnionRoomWork *work);

void UNION_COMM_ReleaseWorks(UnionRoomWork *work);

void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value);

void UNION_COMM_InitSituation(UnionRoomWork *work);

void UNION_COMM_ClearPartnerSelects(UnionConnectInfo *connect);

void UNION_COMM_InitConnectInfo(UnionRoomWork *work, UnionConnectInfo *connect);

int UNION_COMM_AddMember(UnionConnectInfo *connect, const u8 *mac, u8 trainerView, u8 sex);

int UNION_COMM_AddMemberFromBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc);

void UNION_COMM_RemoveMember(UnionConnectInfo *connect, const u8 *mac);

void UNION_COMM_RemoveMemberOfBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc);

void UNION_COMM_InitChatLog(UnionChatLog *log);

void UNION_COMM_SetChatPms(UnionRoomWork *work, const UnionPmsData *pms);

void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType);

void UNION_COMM_SetGameKindByStatus(u32 status);

int UNION_MAIN_IsFieldReady(UnionRoomWork *work);

int UNION_COMMAND_SendConnectSync(void);

int UNION_COMMAND_SendAppEntryRefused(u32 sendMask);

int UNION_COMMAND_SendAppEntryAccepted(int sendMask);

extern char sUnionCommFile[];

extern const GFLNetInitializeStruct sUnionNetInit;

UnionRoomWork *UNION_COMM_Create(UnionParentWork *parent)
{
    UnionRoomWork *work;

    GFL_HEAP_CreateChildHeap(4, UNION_HEAP_ID, 0x8a00);
    work = GFL_HEAP_Alloc(UNION_HEAP_ID, sizeof(UnionRoomWork), 1, sUnionCommFile, 0x89);
    work->parent = parent;
    UNION_COMM_InitSituation(work);
    work->mySituation.chatUpdated = 1;
    UNION_COMM_InitChatLog(&work->chatLog);
    work->regulation = REGULATION_Create(UNION_HEAP_ID);
    work->fieldActive = 1;
    return work;
}

void UNION_COMM_Delete(UnionParentWork *parent, UnionRoomWork *work)
{
    if (work->regulation != 0) GFL_HEAP_Free(work->regulation);
    UNION_COMM_ReleaseWorks(work);
    GFL_HEAP_Free(work);
    GFL_HEAP_DeleteChecked(UNION_HEAP_ID);
    GFL_HEAP_Free(parent);
}

UnionRoomWork *UNION_COMM_InitComm(int *seq, UnionParentWork *parent)
{
    UnionRoomWork *work;

    work = UNION_COMM_Create(parent);
    work->commState = 1;
    GFL_NET_StartSession(&sUnionNetInit, UNION_COMM_SessionStartCallback, work);
    return work;
}

int UNION_COMM_InitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    if (work->commState >= 2) {
        work->commState = 3;
        GFL_NET_EndDeviceWrapper(0);
        return 1;
    }
    return 0;
}

void UNION_COMM_SessionStartCallback(UnionRoomWork *work)
{
    work->commState = 2;
    GFL_NET_SetErrorCheckEnabled(0);
}

int UNION_COMM_Exit(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    work->exitStarted = 1;
    if (work->commState < 3) return 0;
    work->commState = 4;
    if (GFL_NET_Exit(UNION_COMM_ExitCallback) == 0) UNION_COMM_ExitCallback(work);
    return 1;
}

int UNION_COMM_ExitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    if (work->commState == 5) {
        UNION_COMM_Delete(parent, work);
        if (GFL_NET_ERR_GetErrorLevel() != 0) GFL_NET_ERR_ResetState();
        return 1;
    }
    return 0;
}

void UNION_COMM_ExitCallback(UnionRoomWork *work) { work->commState = 5; }

void UNION_COMM_RequestRestart(UnionRoomWork *work)
{
    if (work->resetSeq == 0) {
        work->resetSeq = 1;
        work->resetMode = 0;
    }
}

void UNION_COMM_RequestShutdown(UnionRoomWork *work)
{
    if (work->resetSeq == 0) {
        work->resetSeq = 1;
        work->resetMode = 1;
    }
}

void UNION_COMM_RequestStart(UnionRoomWork *work)
{
    if (work->resetSeq == 0) {
        work->resetSeq = 1;
        work->resetMode = 2;
    }
}

int UNION_COMM_IsResetting(UnionRoomWork *work)
{
    if (work->resetSeq != 0)
        return 1;
    return 0;
}

int UNION_COMM_UpdateReset(UnionRoomWork *work)
{
    switch (work->resetSeq) {
    case 0:
        if (work->resetMode == 1) {
            return 1;
        }
        return 0;
    case 1:
        switch (work->resetMode) {
        case 0:
        case 1:
            work->resetSeq = 2;
            break;
        case 2:
            work->resetSeq = 4;
            break;
        default:
            work->resetSeq = 0;
            break;
        }
        break;
    case 2:
        work->commState = 4;
        if (GFL_NET_Exit(UNION_COMM_ExitCallback) == 0) {
            UNION_COMM_ExitCallback(work);
        }
        work->resetSeq++;
        break;
    case 3:
        if (work->commState == 5) {
            if (work->resetMode == 1) {
                work->resetSeq = 0;
            } else {
                work->resetSeq++;
            }
        }
        break;
    case 4:
        work->commState = 1;
        GFL_NET_StartSession(&sUnionNetInit, UNION_COMM_SessionStartCallback, work);
        work->resetSeq++;
        break;
    case 5:
        if (work->commState >= 2) {
            work->commState = 3;
            GFL_NET_EndDeviceWrapper(0);
            work->resetSeq = 0;
        }
        break;
    }
    return 1;
}

void UNION_COMM_Update(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    if (UNION_COMM_UpdateReset(work) == 1) {
        return;
    }
    if (GFL_NET_GetRunState() == 0) {
        return;
    }
    if (work->beaconChanged == 1) {
        NET_WHPIPE_PublishBeacon();
        work->beaconChanged = 0;
    }
    UNION_COMM_UpdateBeaconScan(work);
    UNION_COMM_UpdateColosseum(work);
    UNION_COMM_SendEntryReplies(work);
    UNION_COMM_UpdateConnectSync(work);
    if (GFL_NET_ERR_GetErrorLevel() != 0 && GFL_NET_IsParentAid() == 1 && work->colosseum != 0
        && work->colosseum->startFlag == 1
        && work->mySituation.playCategory == UNION_PLAY_CATEGORY_COLOSSEUM
        && work->colosseum->leaveSent == 0) {
        UNION_COMM_RequestShutdown(work);
        work->colosseum->leaveSent = 1;
    }
}

void UNION_COMM_StartConnectSync(UnionRoomWork *work) { work->mySituation.connect.syncActive = 1; }

void UNION_COMM_UpdateConnectSync(UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (situation->connect.syncActive == 0) {
        return;
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        return;
    }
    switch (situation->connect.syncStep) {
    case 0:
        if (UNION_COMMAND_SendConnectSync() == 1) {
            situation->connect.syncStep++;
        }
        break;
    case 1:
        if (MATH_CountPopulation(situation->connect.syncReadyBits) >= GFL_NET_GetNegotiationNum()) {
            GFL_NET_SetLoginOption(0);
            situation->connect.syncStep++;
        }
        break;
    case 2:
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1) {
                UNION_COMM_RequestShutdown(work);
                situation->connect.syncStep++;
            }
        } else {
            UNION_COMM_RequestShutdown(work);
            situation->connect.syncStep++;
        }
        break;
    }
}

void UNION_COMM_SendEntryReplies(UnionRoomWork *work)
{
    if (GFL_NET_GetNegotiationNum() > 1) {
        if (work->entryRefuseBits != 0 && UNION_COMMAND_SendAppEntryRefused(work->entryRefuseBits) == 1) {
            work->entryRefuseBits = 0;
        }
        if (work->entryAcceptBits != 0 && UNION_COMMAND_SendAppEntryAccepted(work->entryAcceptBits) == 1) {
            work->entryAcceptBits = 0;
        }
    } else {
        work->entryRefuseBits = 0;
        work->entryAcceptBits = 0;
    }
}

void UNION_COMM_UpdateColosseum(UnionRoomWork *work)
{
    if (work->colosseum != 0 && work->colosseum->startFlag) {
        if (UNION_MAIN_IsFieldReady(work) == 1) {
            if (UNION_MAIN_IsScenePending(work) == 0) {
                COMM_PLAYER_Update(work->parent->gameSystem, work->colosseum->commPlayer);
                if (work->colosseum->packageChanged == 0) {
                    if (COMM_PLAYER_UpdateMyPackage(work->colosseum->commPlayer, &work->colosseum->myPackage) == 1) {
                        work->colosseum->packageChanged = 1;
                    }
                }
                if (work->colosseum->packageChanged == 1) {
                    if (COLOSSEUM_SendPackage(&work->colosseum->myPackage) == 1) {
                        work->colosseum->packageChanged = 0;
                    }
                }
            }
            COLOSSEUM_UpdateCommPlayers(work->colosseum);
        }
        COLOSSEUM_FlushChoiceReplies(work->colosseum);
        COLOSSEUM_UpdateReadyState(work->colosseum);
    }
}

void UNION_COMM_UpdateBeaconScan(UnionRoomWork *work)
{
    int i;
    UnionBeacon *beacon;
    const u8 *mac;

    for (i = 0; i < UNION_BEACON_PC_MAX; i++) {
        beacon = GFL_NET_GetScanResult(i);
        if (beacon) {
            mac = GFL_NET_GetScanResultMac(i);
            if (mac) UNION_COMM_StoreBeacon(work, beacon, mac);
            NET_WHPIPE_ReleaseEntry(i);
        }
    }
}

int UNION_COMM_StoreBeacon(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac)
{
    int i;
    UnionBeaconPc *pcs;
    pcs = work->beaconPc;
    if (beacon->valid != 1)
        return 0;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++) {
        UnionBeaconPc *pc = &pcs[i];
        if (pc->beacon.valid == 1 && memcmp(mac, pc->mac, 6) == 0) {
            MI_CpuCopy8(beacon, pc, sizeof(UnionBeacon));
            if (pcs[i].updateState != 1)
                pcs[i].updateState = 2;
            pcs[i].life = UNION_BEACON_PC_LIFE;
            return 1;
        }
    }
    if (UNION_COMM_IsNotGroupMember(work, beacon, mac) == 0)
        return 0;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++) {
        if (pcs[i].beacon.valid != 1) {
            u8 *dst = (u8 *)&pcs[i];
            MI_CpuCopy8(beacon, dst, sizeof(UnionBeacon));
            dst += sizeof(UnionBeacon);
            MI_CpuCopy8(mac, dst, 6);
            pcs[i].index = i;
            pcs[i].updateState = 1;
            pcs[i].life = UNION_BEACON_PC_LIFE;
            return 1;
        }
    }
    return 0;
}

int UNION_COMM_IsNotGroupMember(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac)
{
    int i;
    UnionBeaconPc *pc;
    int j;
    pc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, pc++) {
        if (pc->beacon.valid == 1) {
            for (j = 0; j < UNION_MEMBER_MAX; j++) {
                if (pc->beacon.group.member[j].valid == 1 && memcmp(mac, pc->beacon.group.member[j].mac, 6) == 0) {
                    if (pc->life != 0) {
                        pc->life = 1;
                    }
                    return 0;
                }
            }
        }
    }
    return 1;
}

UnionBeacon *UNION_COMM_GetBeacon(UnionRoomWork *work) { UNION_COMM_BuildBeacon(work, &work->myBeacon); return &work->myBeacon; }

void UNION_COMM_BuildBeacon(UnionRoomWork *work, UnionBeacon *beacon)
{
    UnionMySituation *situation = &work->mySituation;
    MI_CpuFill8(beacon, 0, sizeof(UnionBeacon));
    if (situation->connect.connectPc != 0) {
        if (GFL_NET_IsParentAid() == 1)
            OS_GetMacAddress(beacon->mac);
        else
            MI_CpuCopy8(situation->connect.connectPc->mac, beacon->mac, 6);
    } else if (situation->connect.talkPc != 0) {
        MI_CpuCopy8(situation->connect.talkPc->mac, beacon->mac, 6);
    }
    beacon->connectNum = GFL_NET_GetNegotiationNum();
    beacon->pmVersion = UNION_PM_VERSION;
    beacon->language = UNION_LANGUAGE;
    beacon->playCategory = situation->playCategory;
    beacon->appealNo = situation->appealNo;
    beacon->status = situation->status;
    func_020084F8(work->parent->myStatus, beacon->name, 8);
    beacon->trainerView = func_02008554(work->parent->myStatus);
    beacon->sex = func_02008550(work->parent->myStatus);
    beacon->trainerId = func_02008530(work->parent->myStatus);
    beacon->chatType = situation->chatType;
    beacon->chatPms = situation->chatPms;
    beacon->chatCount = situation->chatCount;
    beacon->nation = func_0200856C(work->parent->myStatus);
    beacon->area = func_02008570(work->parent->myStatus);
    beacon->group = situation->connect.group;
    WIFILIST_MakeExchangeToken(GAME_DATA_GetField1A0(ICA_ANIME_GetField1C(work->parent->gameSystem)), beacon->friendKey);
    if (work->app != 0)
        beacon->appActive = UNION_APP_IsClosed(work->app);
    else
        beacon->appActive = 0;
    beacon->valid = 1;
    work->beaconChanged = 1;
}

int UNION_COMM_GetBeaconSize(void) { return sizeof(UnionBeacon); }

int UNION_COMM_CompareBeacon(u32 myServiceId, u32 beaconServiceId, UnionRoomWork *work)
{
    if (work->mySituation.connect.serviceLocked == 1) {
        if (myServiceId == 0x14 || beaconServiceId == 0x14)
            return 0;
        if (myServiceId == beaconServiceId)
            return 1;
        return 0;
    }
    if (beaconServiceId >= 0x14 && beaconServiceId <= 0x1b)
        return 1;
    return 0;
}

void UNION_COMM_StateChangeCallback(void) {}

void UNION_COMM_ConnectEndCallback(void) {}

void UNION_COMM_ClearBeaconPcs(UnionRoomWork *work)
{
    MI_CpuFill8(work->beaconPc, 0, sizeof(work->beaconPc));
}

void UNION_COMM_ReleaseWorks(UnionRoomWork *work)
{
    work->partnerCard = 0;
    if (work->myTrainerCard != 0) {
        GFL_HEAP_Free(work->myTrainerCard);
        work->myTrainerCard = 0;
    }
    if (work->recvTrainerCard != 0) {
        GFL_HEAP_Free(work->recvTrainerCard);
        work->recvTrainerCard = 0;
    }
    if (work->partySelectParam != 0) {
        GFL_HEAP_Free(work->partySelectParam);
        work->partySelectParam = 0;
    }
    if (work->partySelect != 0) {
        GFL_HEAP_Free(work->partySelect);
        work->partySelect = 0;
    }
    if (work->app != 0) {
        UNION_APP_Delete(work->app);
        work->app = 0;
    }
    if (work->colosseum != 0) {
        COLOSSEUM_Delete(work->colosseum, work->parent->gameSystem);
        work->colosseum = 0;
    }
}

void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value)
{
    UnionMySituation *situation;
    situation = &work->mySituation;
    switch (id) {
    case 0:
        situation->connect.talkParam = (UnionBeacon *)value;
        return;
    case 1:
        situation->connect.talkPc = (UnionBeaconPc *)value;
        return;
    case 2:
        situation->connect.connectParam = (UnionBeaconPc *)value;
        return;
    case 3:
        situation->connect.connectPc = (UnionBeaconPc *)value;
        return;
    case 4:
        situation->status = value;
    }
}

void UNION_COMM_InitSituation(UnionRoomWork *work)
{
    UnionMySituation *situation;
    situation = &work->mySituation;
    MI_CpuFill8(situation, 0, sizeof(UnionMySituation));
    situation->chatCount = func_020056EC(0xffff);
    situation->chatType = 1;
    situation->playCategory = 2;
    UNION_COMM_InitConnectInfo(work, &situation->connect);
}

void UNION_COMM_ClearPartnerSelects(UnionConnectInfo *connect)
{
    connect->partnerSelectA = 0xff;
    connect->partnerSelectC = 0xff;
    connect->partnerSelectB = 0xff;
}

void UNION_COMM_InitConnectInfo(UnionRoomWork *work, UnionConnectInfo *connect)
{
    UnionMember *self;
    MI_CpuFill8(connect, 0, sizeof(UnionConnectInfo));
    UNION_COMM_ClearPartnerSelects(connect);
    self = &connect->group.member[0];
    OS_GetMacAddress(self->mac);
    self->trainerView = func_02008554(work->parent->myStatus);
    self->sex = func_02008550(work->parent->myStatus);
    self->valid = 1;
    connect->requestId = 0xFFFF;
}

int UNION_COMM_AddMember(UnionConnectInfo *connect, const u8 *mac, u8 trainerView, u8 sex)
{
    int j;
    UnionMember *member;
    int i;
    UnionMember *slot;
    i = 0;
    member = connect->group.member;
    for (; i < UNION_MEMBER_MAX; i++) {
        if (member[i].valid == 1 && memcmp(mac, member[i].mac, 6) == 0) {
            return i;
        }
    }
    for (j = 0; j < UNION_MEMBER_MAX; j++) {
        slot = connect->group.member + j;
        if (slot->valid == 0) {
            MI_CpuCopy8(mac, slot->mac, 6);
            slot->trainerView = trainerView;
            slot->sex = sex;
            slot->valid = 1;
            return j;
        }
    }
    return 0;
}

int UNION_COMM_AddMemberFromBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc) { return UNION_COMM_AddMember(connect, pc->mac, pc->beacon.trainerView, pc->beacon.sex); }

void UNION_COMM_RemoveMember(UnionConnectInfo *connect, const u8 *mac)
{
    int i;
    UnionMember *member;
    i = 0;
    member = connect->group.member;
    for (; i < UNION_MEMBER_MAX; i++) {
        if (member[i].valid == 1 && memcmp(mac, member[i].mac, 6) == 0) {
            MI_CpuFill8(&member[i], 0, sizeof(UnionMember));
            return;
        }
    }
}

void UNION_COMM_RemoveMemberOfBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc)
{
    UNION_COMM_RemoveMember(connect, pc->mac);
}

void UNION_COMM_InitChatLog(UnionChatLog *log)
{
    int i;
    int empty;

    MI_CpuFill8(log, 0, sizeof(UnionChatLog));
    for (i = 0; i < UNION_CHAT_LOG_MAX; i++) {
        MI_CpuFill8(log->entry[i].senderMac, 0xff, 6);
    }
    empty = -1;
    log->newestIndex = empty;
    log->scrollIndex = empty;
    log->drawnIndex = empty;
}

void UNION_COMM_SetChatPms(UnionRoomWork *work, const UnionPmsData *pms)
{
    UnionMySituation *situation = &work->mySituation;
    situation->chatPms = *pms;
    situation->chatType = 0;
    situation->chatCount++;
    situation->chatUpdated = 1;
}

void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType)
{
    UnionMySituation *situation = &work->mySituation;
    situation->chatType = chatType;
    situation->chatCount++;
    situation->chatUpdated = 1;
}

void UNION_COMM_SetGameKindByStatus(u32 status)
{
    switch (status) {
    case 0x14:
        GFL_NET_SetGameKind(0x17, 5);
        break;
    case 0x15:
        GFL_NET_SetGameKind(0x18, 5);
        break;
    case 0x16:
        GFL_NET_SetGameKind(0x19, 5);
        break;
    case 0x17:
        GFL_NET_SetGameKind(0x1a, 5);
        break;
    case 3:
        GFL_NET_SetGameKind(0x16, 5);
        break;
    case 0x19:
        GFL_NET_SetGameKind(0x1b, 5);
        break;
    }
}
