/*
 * file:     union_app.c
 * unit:     yes
 * function: UNION_APP_Create, UNION_APP_Delete, UNION_APP_TryAcceptMember, UNION_APP_Update, UNION_APP_DropDisconnectedMembers, UNION_APP_SendSetting, UNION_APP_SelectQuitRequester, UNION_APP_SendQuitAccept, UNION_APP_SendOwnEntry, UNION_APP_ConfirmJoins, UNION_APP_UpdateLeaves, UNION_APP_ClearDisconnectedPending, UNION_APP_AddQuitRequest, UNION_APP_SetQuitAccepted, UNION_APP_IsQuitAccepted, UNION_APP_AddSettingTarget, UNION_APP_SetSetting, UNION_APP_AddEntryTarget, UNION_APP_SetMemberEntry, UNION_APP_HasMembers, UNION_APP_IsAllEntriesReceived, UNION_APP_QueueJoinConfirm, UNION_APP_OnMemberDropped, UNION_APP_GetSettingSize, UNION_APP_AddSelfToJoined, UNION_APP_IsClosed, UNION_APP_SetCallbacks, UNION_APP_Close, UNION_APP_Open, UNION_APP_OpenLimited, UNION_APP_SetReady, UNION_APP_RequestReset, UNION_APP_IsResetDone, UNION_APP_GetMemberEntry, UNION_APP_GetJoinedBits, UNION_APP_GetMemberCount
 * address:  0x02183B60
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   sUnionAppFile     0x021841C0  data  a1
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MATH_CountPopulation  0x02080D24  arm
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   UNION_COMMAND_SendAppNotice  0x0217410C  thumb  ov012
 *   UNION_COMMAND_SendAppSetting 0x02173F20 thumb ov012
 *   UNION_COMMAND_SendAppQuitAccept 0x02173E68 thumb ov012
 *   UNION_COMMAND_SendAppData 0x02174010 thumb ov012
 *   UNION_COMM_RemoveMember  0x02173614  thumb  ov012
 *   MI_CpuCopy8  0x02082D44  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   UNION_COMM_AddMember  0x0217357C  thumb  ov012
 *   GFL_NET_SetAcceptConnection  0x0203D1E8  arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;
typedef struct { s32 x, y, z; } VecFx32;

#include "../ov012/union_comm_types.h"
#include "union_app_types.h"

struct Entry;
struct Link;
struct Sub0200852CObj;
extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern u32 GFL_NET_IsParentAid(void);
extern void MI_CpuFill8(void *p, int v, int n);
extern void OS_GetMacAddress(void *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern u32 GFL_HEAP_Free(void *p);
extern u32 MATH_CountPopulation(u32 a);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void UNION_COMM_RequestShutdown(UnionRoomWork *work);
extern int UNION_COMM_IsResetting(UnionRoomWork *work);
extern u32 GFL_NET_IsConnectMember(u32 index);
extern int UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value);
extern u32 UNION_COMMAND_SendAppSetting(void *p, u32 a);
extern u32 UNION_COMMAND_SendAppQuitAccept(u32 a);
extern u32 UNION_COMMAND_SendAppData(u32 a, void *p);
extern void UNION_COMM_RemoveMember(UnionConnectInfo *connect, const u8 *mac);
extern void MI_CpuCopy8(const void *src, void *dst, u32 len);
extern u8 MYSTATUS_GetSex(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetTrainerView(const struct Sub0200852CObj *obj);
extern int UNION_COMM_AddMember(UnionConnectInfo *connect, const u8 *mac, u32 a2, u32 a3);
extern void GFL_NET_SetAcceptConnection(u32 unused, void *arg);
extern int GFL_NET_GetRunState(void);
UnionAppWork *UNION_APP_Create(UnionRoomWork *work, int heapId, int maxMembers, UnionAppStatusCopy *myStatus);
void UNION_APP_Delete(UnionAppWork *app);
int UNION_APP_TryAcceptMember(UnionAppWork *app, int netId);
void UNION_APP_Update(UnionAppWork *app, UnionRoomWork *work);
void UNION_APP_DropDisconnectedMembers(UnionAppWork *app);
void UNION_APP_SendSetting(UnionAppWork *app);
void UNION_APP_SelectQuitRequester(UnionAppWork *app);
void UNION_APP_SendQuitAccept(UnionAppWork *app);
void UNION_APP_SendOwnEntry(UnionAppWork *app);
void UNION_APP_ConfirmJoins(UnionAppWork *app);
void UNION_APP_UpdateLeaves(UnionAppWork *app, UnionRoomWork *work);
void UNION_APP_ClearDisconnectedPending(UnionAppWork *app, UnionRoomWork *work);
void UNION_APP_AddQuitRequest(UnionAppWork *app, u8 netId);
void UNION_APP_SetQuitAccepted(UnionAppWork *app);
u8 UNION_APP_IsQuitAccepted(UnionAppWork *app);
void UNION_APP_AddSettingTarget(UnionAppWork *app, u8 netId);
void UNION_APP_SetSetting(UnionAppWork *app, const void *setting);
void UNION_APP_AddEntryTarget(UnionAppWork *app, u8 netId);
void UNION_APP_SetMemberEntry(UnionAppWork *app, UnionRoomWork *work, u32 netId, const UnionAppEntry *src);
int UNION_APP_HasMembers(UnionAppWork *app);
int UNION_APP_IsAllEntriesReceived(UnionAppWork *app);
void UNION_APP_QueueJoinConfirm(UnionAppWork *app, int netId);
void UNION_APP_OnMemberDropped(UnionAppWork *app, int netId);
unsigned int UNION_APP_GetSettingSize(unsigned int entry);
void UNION_APP_AddSelfToJoined(UnionAppWork *app);
int UNION_APP_IsClosed(UnionAppWork *app);
void UNION_APP_SetCallbacks(UnionAppWork *app, UnionAppMemberCallback joinCallback, UnionAppMemberCallback leaveCallback, void *callbackArg);
int UNION_APP_Close(UnionAppWork *app);
void UNION_APP_Open(UnionAppWork *app);
void UNION_APP_OpenLimited(UnionAppWork *app, int maxCount);
void UNION_APP_SetReady(UnionAppWork *app);
void UNION_APP_RequestReset(UnionAppWork *app);
u32 UNION_APP_IsResetDone(UnionAppWork *app);
UnionAppEntry *UNION_APP_GetMemberEntry(UnionAppWork *app, int netId);
unsigned char UNION_APP_GetJoinedBits(UnionAppWork *app);
int UNION_APP_GetMemberCount(UnionAppWork *app);
extern u8 sUnionAppFile[];


UnionAppWork *UNION_APP_Create(UnionRoomWork *work, int heapId, int maxMembers, UnionAppStatusCopy *myStatus)
{
    UnionAppWork *app;
    UnionAppEntry entry;

    app = GFL_HEAP_Alloc(heapId, UNION_APP_WORK_SIZE, 1, (const char *)sUnionAppFile, 0x4d);
    if (GFL_NET_IsParentAid() == 1) {
        app->joinedBits = 3;
    }
    app->maxMembers = maxMembers;
    app->quitRequester = UNION_APP_NO_MEMBER;
    app->quitAcceptTarget = UNION_APP_NO_MEMBER;
    MI_CpuFill8(&entry, 0, sizeof(UnionAppEntry));
    entry.status = *myStatus;
    OS_GetMacAddress(entry.mac);
    UNION_APP_SetMemberEntry(app, work, GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())), &entry);
    UNION_APP_Close(app);
    UNION_APP_SetReady(app);
    return app;
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3 / pool) in ov022; blocker of
 * ov012 UNION_MAIN_StepGroupActivity.
 */
void UNION_APP_Delete(UnionAppWork *app)
{
    GFL_HEAP_Free(app);
}


/*
 * Addresses are Black-image addresses.
 */
int UNION_APP_TryAcceptMember(UnionAppWork *app, int netId)
{
    u32 memberCount;
    u32 limitedCount;

    if (app->phase == UNION_APP_PHASE_CLOSED) {
        return 0;
    }
    memberCount = MATH_CountPopulation(app->joinedBits);
    if (app->phase == UNION_APP_PHASE_LIMITED) {
        limitedCount = app->limitedCount;
        if (limitedCount + 1 > app->limitedMax) {
            return 0;
        }
    }
    if (memberCount + 1 <= app->maxMembers) {
        app->pendingBits = app->pendingBits | (u8)(1 << netId);
        if (app->phase == UNION_APP_PHASE_LIMITED) {
            app->limitedCount = app->limitedCount + 1;
        }
        return 1;
    }
    return 0;
}


void UNION_APP_Update(UnionAppWork *app, UnionRoomWork *work)
{
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        return;
    }
    if (app->resetDone == 1) {
        return;
    }
    if (app->resetRequest == 1) {
        UNION_COMM_RequestShutdown(work);
        app->resetRequest = 0;
        app->resetRunning = 1;
        return;
    }
    if (app->resetRunning == 1) {
        if (UNION_COMM_IsResetting(work) == 0) {
            app->resetRunning = 0;
            app->resetDone = 1;
        }
        return;
    }
    if (GFL_NET_IsParentAid() == 1) {
        UNION_APP_ClearDisconnectedPending(app, work);
        UNION_APP_SendSetting(app);
        UNION_APP_DropDisconnectedMembers(app);
        UNION_APP_SelectQuitRequester(app);
        UNION_APP_SendQuitAccept(app);
    }
    UNION_APP_SendOwnEntry(app);
    UNION_APP_ConfirmJoins(app);
    UNION_APP_UpdateLeaves(app, work);
}


void UNION_APP_DropDisconnectedMembers(UnionAppWork *app)
{
    int netId;
    u32 bit;
    u32 stillConnected;
    u8 stillConnectedBits;

    stillConnected = app->joinedBits;
    if (app->quitRequester == UNION_APP_NO_MEMBER) {
        for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
            bit = 1 << netId;
            if (app->joinedBits & bit) {
                if (GFL_NET_IsConnectMember((u8)netId) == 0) {
                    stillConnected ^= bit;
                }
            }
        }
        if (stillConnected != app->joinedBits) {
            stillConnectedBits = stillConnected;
            for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
                bit = 1 << netId;
                if (app->joinedBits & bit) {
                    if (!(stillConnected & bit)) {
                        if (UNION_COMMAND_SendAppNotice(stillConnectedBits, netId & 0xff) == 1) {
                            UNION_APP_OnMemberDropped(app, (u8)netId);
                            app->joinedBits = app->joinedBits ^ (u8)bit;
                        }
                    }
                }
            }
        }
    }
}


void UNION_APP_SendSetting(UnionAppWork *app)
{
    if (app->settingSendBits != 0 && UNION_COMMAND_SendAppSetting(app, app->settingSendBits) == 1) app->settingSendBits = 0;
}


void UNION_APP_SelectQuitRequester(UnionAppWork *app)
{
    int netId;
    u8 bits;

    if (app->quitRequester != UNION_APP_NO_MEMBER) {
        if (GFL_NET_IsConnectMember(app->quitRequester) != 0) {
            return;
        }
        app->quitRequester = UNION_APP_NO_MEMBER;
        app->quitAcceptTarget = UNION_APP_NO_MEMBER;
    }
    bits = app->quitRequestBits;
    if (bits != 0) {
        for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
            if (bits & (1 << netId)) {
                app->quitRequester = netId;
                app->quitAcceptTarget = netId;
                app->quitRequestBits = app->quitRequestBits ^ (u8)(1 << netId);
                return;
            }
        }
    }
}


/*
 * Callee's filed definition says void; original caller reads r0 at
 * 02183DA2, and ov012 callee leaves GFL_NET_SendData result live.
 */
void UNION_APP_SendQuitAccept(UnionAppWork *app)
{
    if (app->quitAcceptTarget != 255 && UNION_COMMAND_SendAppQuitAccept(app->quitAcceptTarget) == 1) app->quitAcceptTarget = 255;
}


void UNION_APP_SendOwnEntry(UnionAppWork *app)
{
    u32 myNetId;
    if (app->dataSendBits != 0) {
        myNetId = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
        if (UNION_COMMAND_SendAppData(app->dataSendBits, &app->entry[myNetId]) == 1) app->dataSendBits = 0;
    }
}


void UNION_APP_ConfirmJoins(UnionAppWork *app)
{
    int netId;
    u32 bit;
    UnionAppEntry *entries;
    UnionAppMemberCallback callback;

    if (app->confirmBits != 0) {
        netId = 0;
        entries = app->entry;
        for (; netId < UNION_APP_MEMBER_MAX; netId++) {
            bit = 1 << netId;
            if (app->confirmBits & bit) {
                if ((app->entryReceivedBits & bit) && (app->pendingBits & bit)) {
                    app->pendingBits ^= (u8)bit;
                    app->joinedBits |= (u8)bit;
                    callback = app->joinCallback;
                    if (callback != 0) {
                        callback((u8)netId, entries + netId, app->callbackArg);
                    }
                    app->quitRequester = 0xff;
                }
                app->confirmBits = app->confirmBits ^ (u8)bit;
            }
        }
    }
}


void UNION_APP_UpdateLeaves(UnionAppWork *app, UnionRoomWork *work)
{
    int netId;
    u32 bit;
    UnionAppMemberCallback callback;

    for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
        bit = 1 << netId;
        if (app->entryReceivedBits & bit) {
            if (GFL_NET_IsConnectMember((u8)netId) == 0) {
                if (GFL_NET_IsParentAid() == 1 || (app->joinedBits & bit)) {
                    callback = app->leaveCallback;
                    if (callback != 0) {
                        callback(netId & 0xff, &app->entry[netId], app->callbackArg);
                    }
                    app->joinedBits &= (u8)(bit ^ 0xff);
                    app->entryReceivedBits &= (u8)(bit ^ 0xff);
                }
                UNION_COMM_RemoveMember(&work->mySituation.connect, app->entry[netId].mac);
            }
        }
    }
}


void UNION_APP_ClearDisconnectedPending(UnionAppWork *app, UnionRoomWork *work)
{
    u8 netId;
    u32 bit;

    for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
        bit = 1 << netId;
        if (app->pendingBits & bit) {
            if (GFL_NET_IsConnectMember(netId) == 0) {
                app->pendingBits ^= (u8)bit;
                if (app->entryReceivedBits & bit) {
                    app->entryReceivedBits &= (u8)(bit ^ 0xff);
                    UNION_COMM_RemoveMember(&work->mySituation.connect, app->entry[netId].mac);
                }
                if (app->phase == UNION_APP_PHASE_LIMITED && app->limitedCount != 0) {
                    app->limitedCount--;
                }
            }
        }
    }
}


void UNION_APP_AddQuitRequest(UnionAppWork *app, u8 netId)
{
    app->quitRequestBits |= (u8)(1 << netId);
}


/*
 * leaf:     Sole game blocker of assigned ov012 caller; root claim granted.
 */
void UNION_APP_SetQuitAccepted(UnionAppWork *app)
{
    app->quitAccepted = 1;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s); blocker of ov012
 * UNION_MAIN_StepGroupActivity.
 */
u8 UNION_APP_IsQuitAccepted(UnionAppWork *app)
{
    return app->quitAccepted;
}


void UNION_APP_AddSettingTarget(UnionAppWork *app, u8 netId)
{
    app->settingSendBits |= (u8)(1 << netId);
}


void UNION_APP_SetSetting(UnionAppWork *app, const void *setting)
{
    MI_CpuCopy8(setting, app, 4);
}


/*
 * Unlabelled bit-set leaf; follower 02183FB8 is separate labelled code.
 */
void UNION_APP_AddEntryTarget(UnionAppWork *app, u8 netId)
{
    app->dataSendBits = app->dataSendBits | (u8)(1 << netId);
}


void UNION_APP_SetMemberEntry(UnionAppWork *app, UnionRoomWork *work, u32 netId, const UnionAppEntry *src)
{
    UnionMySituation *situation = &work->mySituation;
    app->entry[netId] = *src;
    app->entryReceivedBits |= (u8)(1 << netId);
    if (netId != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        u32 trainerView = MYSTATUS_GetTrainerView((const struct Sub0200852CObj *)src);
        u32 sex = MYSTATUS_GetSex((const struct Sub0200852CObj *)src);
        UNION_COMM_AddMember(&situation->connect, src->mac, trainerView, (u8)sex);
    }
}


int UNION_APP_HasMembers(UnionAppWork *app)
{
    if (app->joinedBits != 0)
        return 1;
    return 0;
}


int UNION_APP_IsAllEntriesReceived(UnionAppWork *app)
{
    int netId;
    u32 bit;
    for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
        bit = 1 << netId;
        if ((app->joinedBits & bit) && GFL_NET_IsConnectMember((u8)netId) == 1 && !(app->entryReceivedBits & bit)) return 0;
    }
    return 1;
}


void UNION_APP_QueueJoinConfirm(UnionAppWork *app, int netId)
{
    if (GFL_NET_IsParentAid() == 1) {
        if ((app->entryReceivedBits & (1 << netId)) && (app->pendingBits & (1 << netId))) {
            app->confirmBits |= (u8)(1 << netId);
        }
    } else {
        app->pendingBits |= (u8)(1 << netId);
        app->confirmBits |= (u8)(1 << netId);
    }
}


void UNION_APP_OnMemberDropped(UnionAppWork *app, int netId)
{
}


/*
 * Unlabelled size-return leaf. Extent follower 021840AC already filed separately.
 */
unsigned int UNION_APP_GetSettingSize(unsigned int entry)
{
    return 4;
}


void UNION_APP_AddSelfToJoined(UnionAppWork *app)
{
    app->joinedBits = app->joinedBits | (u8)(1 << GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())));
}


/*
 * Unlabelled leaf (prints as a .word run in asm/overlays/ov022.s); the
 * sole blocker of ov012 UNION_COMM_BuildBeacon's MATCH. Of the five overlays whose
 * window holds 0x021840C8 only ov022 has a function start there.
 */
int UNION_APP_IsClosed(UnionAppWork *app)
{
    if (app == 0)
        return 0;
    switch (app->phase) {
    case UNION_APP_PHASE_OPEN:
        return 0;
    case UNION_APP_PHASE_CLOSED:
        return 1;
    case UNION_APP_PHASE_LIMITED:
        if (app->limitedCount >= app->limitedMax)
            return 1;
        return 0;
    }
    return 0;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): stores the two
 * callbacks and their argument at 0xf4/0xf8/0xfc (the fields
 * UNION_APP_UpdateLeaves reads). Blocker of ov023 OEKAKI_Main.
 */
void UNION_APP_SetCallbacks(UnionAppWork *app, UnionAppMemberCallback joinCallback, UnionAppMemberCallback leaveCallback, void *callbackArg)
{
    app->joinCallback = joinCallback;
    app->leaveCallback = leaveCallback;
    app->callbackArg = callbackArg;
}


int UNION_APP_Close(UnionAppWork *app)
{
    if (app->pendingBits == 0) {
        GFL_NET_SetAcceptConnection((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
        app->phase = UNION_APP_PHASE_CLOSED;
        return 1;
    }
    return 0;
}


/*
 * Original r0 return from 020399A8 flows into unused parameter 0 of
 * 0203D1E8; its r1 argument is literal payload 1. No implicit arguments.
 */
void UNION_APP_Open(UnionAppWork *app)
{
    GFL_NET_SetAcceptConnection((u32)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
    app->phase = UNION_APP_PHASE_OPEN;
}


void UNION_APP_OpenLimited(UnionAppWork *app, int maxCount)
{
    if (GFL_NET_GetRunState()) {
        GFL_NET_SetAcceptConnection((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        app->phase = UNION_APP_PHASE_LIMITED;
        app->limitedMax = maxCount;
        app->limitedCount = 0;
    }
}


/*
 * Extent followers 0x02184174, 0x0218417C and 0x02184180 are matched separately.
 */
void UNION_APP_SetReady(UnionAppWork *app)
{
    app->ready = 1;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): sets the word at
 * 0x20. Blocker of ov023 OEKAKI_Main.
 */
void UNION_APP_RequestReset(UnionAppWork *app)
{
    app->resetRequest = 1;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): returns the word
 * at 0x28. Blocker of ov023 OEKAKI_Main.
 */
u32 UNION_APP_IsResetDone(UnionAppWork *app)
{
    return app->resetDone;
}


/*
 * Unlabelled leaf; callers in ov023 (OEKAKI_UpdateMemberSlots, OEKAKI_UpdateRemoteCursors).
 */
UnionAppEntry *UNION_APP_GetMemberEntry(UnionAppWork *app, int netId)
{
    int bit;

    bit = 1 << netId;
    if (!(app->entryReceivedBits & bit) || !(app->joinedBits & bit))
        return 0;
    return &app->entry[netId];
}


unsigned char UNION_APP_GetJoinedBits(UnionAppWork *app)
{
    return app->joinedBits;
}


int UNION_APP_GetMemberCount(UnionAppWork *app)
{
    return MATH_CountPopulation(app->joinedBits);
}
