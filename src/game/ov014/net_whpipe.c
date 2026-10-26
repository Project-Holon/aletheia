/*
 * file:     net_whpipe.c
 * unit:     yes
 * function: NET_WHPIPE_SetTask, NET_WHPIPE_Create, NET_WHPIPE_SetEventCallback, NET_WHPIPE_IsBeaconAcceptable, NET_WHPIPE_StoreScannedEntry, NET_WHPIPE_CheckBeaconFlags, NET_WHPIPE_ClearEntries, NET_WHPIPE_ResetState, NET_WHPIPE_ForwardEvent, NET_WHPIPE_StartScan, NET_WHPIPE_TaskBeginFinalize, NET_WHPIPE_TaskWaitFinalize, NET_WHPIPE_RequestFinalize, NET_WHPIPE_Destroy, NET_WHPIPE_NotifyEntryAcceptable, NET_WHPIPE_TickEntryAges, NET_WHPIPE_PublishBeacon, NET_WHPIPE_RefreshBeacon, NET_WHPIPE_UpdateState, NET_WHPIPE_Update, NET_WHPIPE_IsConnected, NET_WHPIPE_IsAidConnected, NET_WHPIPE_GetConnectedNum, NET_WHPIPE_IsWorkAllocated, NET_WHPIPE_IsIdle, NET_WHPIPE_GetChildBitmap, NET_WHPIPE_IsDisconnectDetected, NET_WHPIPE_SetWatchDisconnect, NET_WHPIPE_GetEntryBeaconData, NET_WHPIPE_GetEntryBssid, NET_WHPIPE_GetEntryBeaconKind, NET_WHPIPE_ReleaseEntrySlot, NET_WHPIPE_ReleaseAllEntrySlots, NET_WHPIPE_ReleaseEntry, NET_WHPIPE_GetEntryBeacon, NET_WHPIPE_HasBeaconBeenSent, NET_WHPIPE_IsStateScanning, NET_WHPIPE_SendData, NET_WHPIPE_GetConnectBitmap, NET_WHPIPE_GetOwnAid, NET_WHPIPE_TaskConnectParent, NET_WHPIPE_TaskStartParent, NET_WHPIPE_StartParent, NET_WHPIPE_SetBeaconGameInfo, NET_WHPIPE_TaskConnectChild, NET_WHPIPE_StartChild, NET_WHPIPE_TaskFinishEnd, NET_WHPIPE_RequestEnd, NET_WHPIPE_AcceptChild, NET_WHPIPE_RejectChild, NET_WHPIPE_SetAcceptChild, NET_WHPIPE_TaskParentSearchWait, NET_WHPIPE_TaskParentSearchStart, NET_WHPIPE_TaskChildScanWait, NET_WHPIPE_TaskChildScanStart, NET_WHPIPE_StartAutoSearch, NET_WHPIPE_OnChildDisconnected, NET_WHPIPE_GetEntryKind, NET_WHPIPE_SelectEntry, NET_WHPIPE_StartJoinLock, NET_WHPIPE_SetBeaconStatus, NET_WHPIPE_SetNotifyCallback
 * address:  0x0217727C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from net_devwireless.c, net_whpipe.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   NET_WHPIPE_Create  0x02177280  thumb  ov014
 *   NET_WHPIPE_IsIdle 0x02177AA8 thumb ov014
 *   NET_WHPIPE_Update 0x0217796C thumb ov014
 *   NET_WHPIPE_RequestFinalize 0x021776C4 thumb ov014
 *   GFL_HEAP_Free 0x020307B0 arm
 *   NET_WHPIPE_RequestEnd 0x02177EB0 thumb ov014
 *   NET_WHPIPE_ClearEntries 0x02177560 thumb ov014
 *   NET_WHPIPE_GetEntryBeaconData 0x02177B2C thumb ov014
 *   NET_WHPIPE_GetEntryBssid 0x02177B58 thumb ov014
 *   NET_WHPIPE_HasBeaconBeenSent 0x02177C08 thumb ov014
 *   NET_WHPIPE_StartParent 0x02177D0C thumb ov014
 *   NET_WHPIPE_StartScan 0x021775BC thumb ov014
 *   NET_WHPIPE_StartChild 0x02177E20 thumb ov014
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   NET_WHPIPE_SendData 0x02177C30 thumb ov014
 *   NET_WHPIPE_SetEventCallback  0x02177310  thumb
 *   NET_WHPIPE_IsConnected 0x021779F4 thumb ov014
 *   DWCi_MOV_WH_GetLastError  0x02178E68  thumb  ov014
 *   g_pWhPipeWork  0x021797A4  data   a4
 *   sFileNetWhPipe 0x02179780  data   a1
 *   WM_GetNextTgid  0x0208F1B4  arm
 *   WIH_Initialize  0x021790E4  thumb  ov014
 *   WIH_SetGgid  0x02178E1C  thumb  ov014
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   DWCi_MOV_WH_SetReceiver  0x0217933C  thumb  ov014
 *   DWCi_MOV_WH_StartScan  0x021785B4  thumb  ov014
 *   WIH_Finalize  0x02179498  thumb  ov014
 *   DWCi_MOV_WH_StateInEndKeyShare  0x0217945C  thumb  ov014
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   OS_Terminate  0x02088234  arm
 *   sEmptyString   0x02179790  data   a4
 *   GF_PANIC_Fail  0x02034714  arm
 *   WIH_GetOwnAid  0x021795A4  thumb  ov014
 *   WIH_End  0x02179570  thumb  ov014
 *   GFL_NET_CallErrorStateFunc  0x0203D720  arm
 *   GFL_NET_CallStateChangeFunc  0x0203D754  arm
 *   WIH_SetScanTimerPaused  0x02179664  thumb
 *   WIH_UpdateScanTimer  0x021793F8  thumb
 *   WIH_GetBitmap  0x02178E38  thumb  ov014
 *   WIH_GetBeaconSendCount  0x02179614  thumb  ov014
 *   g_ParentConnectModes     0x0217967C  data   a2
 *   DC_FlushRange  0x020862F0  arm
 *   DWCi_MOV_WH_SetUserGameInfo  0x02178E28  thumb  ov014
 *   g_ChildConnectModes     0x02179680  data  ov014  a2
 *   g_SearchChannels     0x02179678  data  a1
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   DWCi_MOV_WH_ChildConnectAuto 0x02178524 thumb ov014
 *   WIH_SetScanTarget 0x02178714 thumb ov014
 *   DWCi_MOV_WH_EndScan 0x021788FC thumb ov014
 *   WIH_StartMeasureChannel 0x02178E84 thumb ov014
 *   WIH_FinishMeasureChannel 0x02179024 thumb ov014
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   WIH_ParentConnect 0x02179288 thumb ov014
 *   WIH_SetJudgeAcceptFunc 0x02179328 thumb ov014
 *   DWCi_MOV_WH_SendData 0x02179368 thumb ov014
 *   WIH_SetJudgeScanFunc 0x021795C0 thumb ov014
 *   WIH_SetBeaconGameInfo 0x021795D4 thumb ov014
 */
#include "../arm9/net_whpipe_types.h"
#include "../arm9/net.h"
#include "wih.h"

#include "../arm9/gfl_heap_wrap.h"




#include "../types.h"



#include "../arm9/wm_sync.h"



#include "../arm9/gf_standard.h"


#include "../arm9/mi_memory.h"







#include "../arm9/os_terminate_processor.h"

#include "../arm9/gf_panic.h"








/* wih.c: the WH work's beaconSendCount. */

#include "../arm9/os_cache.h"


#include "../arm9/gfl_use.h"

/* The bssid argument is const: that lets the ldrh of b[1] schedule above the strh of b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md). */








/* Guard wrapper: forwards to DWCi_MOV_WH_StateInSetMPData when WIH_GetOwnAid is nonzero or one of bits 1-7 of WIH_GetBitmap is set, else returns 0. */


/* When the state word of the WH work block is 4 or 5, forwards to the arm9 function at 0x02090CD4 (WM_SetGameInfo shape) with (0, a, b, c, d, 1), the halfword arguments truncated. */

void NET_WHPIPE_SetTask(WhPipeWork *work, WhPipeTask task);

int NET_WHPIPE_Create(int heapId, int wmParam, void *userData, int forListening);

void NET_WHPIPE_SetEventCallback(int (*callback)(int a, int b, int c));

int NET_WHPIPE_IsBeaconAcceptable(WhPipeEntry *entry);

int NET_WHPIPE_StoreScannedEntry(void *arg);

int NET_WHPIPE_CheckBeaconFlags(WhPipeEntry *entry, u32 flags);

void NET_WHPIPE_ClearEntries(void);

void NET_WHPIPE_ResetState(WhPipeWork *work);

int NET_WHPIPE_ForwardEvent(u32 a, u32 b, u32 c);

int NET_WHPIPE_StartScan(int clearEntries);

void NET_WHPIPE_TaskBeginFinalize(WhPipeWork *work);

void NET_WHPIPE_TaskWaitFinalize(WhPipeWork *work);

int NET_WHPIPE_RequestFinalize(void);

void NET_WHPIPE_Destroy(void);

int NET_WHPIPE_NotifyEntryAcceptable(void *arg);

void NET_WHPIPE_TickEntryAges(void);

void NET_WHPIPE_PublishBeacon(void);

void NET_WHPIPE_RefreshBeacon(void);

void NET_WHPIPE_UpdateState(u32 tick);

void NET_WHPIPE_Update(u32 tick);

int NET_WHPIPE_IsConnected(void);

int NET_WHPIPE_IsAidConnected(u16 aid);

int NET_WHPIPE_GetConnectedNum(void);

int NET_WHPIPE_IsWorkAllocated(void);

int NET_WHPIPE_IsIdle(void);

unsigned int NET_WHPIPE_GetChildBitmap(void);

int NET_WHPIPE_IsDisconnectDetected(void);

void NET_WHPIPE_SetWatchDisconnect(u8 watch);

u8 *NET_WHPIPE_GetEntryBeaconData(int index);

u8 *NET_WHPIPE_GetEntryBssid(int index);

u8 NET_WHPIPE_GetEntryBeaconKind(int index);

void NET_WHPIPE_ReleaseEntrySlot(u32 index);

void NET_WHPIPE_ReleaseAllEntrySlots(void);

void NET_WHPIPE_ReleaseEntry(unsigned int index);

u8 *NET_WHPIPE_GetEntryBeacon(WhPipeEntry *entry, u8 *outKind);

int NET_WHPIPE_HasBeaconBeenSent(void *unused);

int NET_WHPIPE_IsStateScanning(void);

int NET_WHPIPE_SendData(u16 *data, unsigned int size, WihResultCallback callbackArg);

unsigned int NET_WHPIPE_GetConnectBitmap(void);

int NET_WHPIPE_GetOwnAid(void);

void NET_WHPIPE_TaskConnectParent(WhPipeWork *work);

void NET_WHPIPE_TaskStartParent(WhPipeWork *work);

int NET_WHPIPE_StartParent(int autoChannel);

void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len);

void NET_WHPIPE_TaskConnectChild(WhPipeWork *work);

int NET_WHPIPE_StartChild(u32 unused, u8 *bssid, u32 entryIndex, void (*onConnected)(void));

void NET_WHPIPE_TaskFinishEnd(WhPipeWork *work);

int NET_WHPIPE_RequestEnd(WihEndCallback endCallback);

int NET_WHPIPE_AcceptChild(void *startParentCb, void *userArg);

int NET_WHPIPE_RejectChild(void *startParentCb, void *userArg);

void NET_WHPIPE_SetAcceptChild(int acceptChild);

void NET_WHPIPE_TaskParentSearchWait(WhPipeWork *work);

void NET_WHPIPE_TaskParentSearchStart(WhPipeWork *work);

void NET_WHPIPE_TaskChildScanWait(WhPipeWork *work);

void NET_WHPIPE_TaskChildScanStart(WhPipeWork *work);

int NET_WHPIPE_StartAutoSearch(void);

void NET_WHPIPE_OnChildDisconnected(void);

u8 NET_WHPIPE_GetEntryKind(u8 i);

void NET_WHPIPE_SelectEntry(u32 i);

void NET_WHPIPE_StartJoinLock(int a);

void NET_WHPIPE_SetBeaconStatus(u8 value);

void NET_WHPIPE_SetNotifyCallback(WhPipeNotifyFunc callback, void *value);

extern WhPipeWork *g_pWhPipeWork;

extern char sFileNetWhPipe[];

extern u8 sEmptyString[];

extern u16 g_ParentConnectModes[2];

extern u16 g_ChildConnectModes[2];

extern u8 g_SearchChannels[3];

void NET_WHPIPE_SetTask(WhPipeWork *work, WhPipeTask task)
{
    work->task = task;
}

int NET_WHPIPE_Create(int heapId, int wmParam, void *userData, int forListening)
{
    GFLNetSession *init;
    WhPipeWork *work;

    GFL_NET_GetInitParam();
    init = GFL_NET_GetInitParam();
    if (g_pWhPipeWork != 0)
        return 0;
    work = GFL_HEAP_Alloc(heapId, sizeof(*work), 1, sFileNetWhPipe, 0xed);
    g_pWhPipeWork = work;
    work->channel = 0xff;
    if (WIH_Initialize(heapId, wmParam, forListening) == 0)
        return 0;
    WIH_SetGgid(init->init.ggid);
    work->userData = userData;
    work->shutdownRequest = 0;
    work->startedFlag = 0;
    work->tgid = WM_GetNextTgid();
    return 1;
}

void NET_WHPIPE_SetEventCallback(int (*callback)(int a, int b, int c))
{
    g_pWhPipeWork->eventCallback = callback;
}

/* Checks a scanned parent's beacon against our own init block; 1 when we may list it. */
int NET_WHPIPE_IsBeaconAcceptable(WhPipeEntry *entry)
{
    WhPipeWork *work = g_pWhPipeWork;
    GFLNetSession *init = GFL_NET_GetInitParam();
    WhPipeBeacon *beacon;
    int gameKind;
    u16 ggid;
    WhPipeBeaconCompareFunc compare;
    WhPipeNotifyFunc notify;

    gameKind = init->init.gameKind;
    ggid = init->init.ggid;
    beacon = &entry->beacon;
    if (beacon->status != 0)
        return 0;
    if (beacon->reserved != 0)
        return 0;
    if (beacon->checksum != GF_STANDARD_CalcCrc16((u8 *)beacon + 2, 0x6e))
        return 0;
    if (beacon->ggid != ggid)
        return 0;
    notify = g_pWhPipeWork->notifyFn;
    if (notify != 0)
        notify(g_pWhPipeWork->notifyArg, entry, beacon->kind, beacon->connectedNum);
    compare = init->init.compareBeaconFunc;
    if (compare != 0) {
        if (compare(gameKind, beacon->kind, work->userData) == 0)
            return 0;
    } else if (gameKind != beacon->kind) {
        return 0;
    }
    if (gameKind != 0x14 && beacon->connectedNum >= init->init.maxConnectNum && init->init.maxConnectNum > 1)
        return 0;
    return 1;
}

/* Scan callback: files an acceptable parent in the entry table, refreshing the slot of a known bssid. */
int NET_WHPIPE_StoreScannedEntry(void *arg)
{
    WhPipeEntry *entry = arg;
    int i;
    WhPipeWork *work = g_pWhPipeWork;

    GFL_NET_GetInitParam();
    if (NET_WHPIPE_IsBeaconAcceptable(entry) == 0)
        return 0;
    for (i = 0; i < WHPIPE_ENTRY_MAX; i++) {
        if (work->entryAge[i] != 0 && GF_STANDARD_CompareBytes(work->entry[i].bssid, entry->bssid, 6) == 0) {
            work->entryAge[i] = WHPIPE_ENTRY_LIFETIME;
            MI_CpuCopy8(entry, &work->entry[i], 0xC0);
            return 1;
        }
    }
    for (i = 0; i < WHPIPE_ENTRY_MAX; i++) {
        if (work->entryAge[i] == 0)
            break;
    }
    if (i >= WHPIPE_ENTRY_MAX)
        return 0;
    work->entryAge[i] = WHPIPE_ENTRY_LIFETIME;
    MI_CpuCopy8(entry, &work->entry[i], 0xC0);
    work->entryListChanged = 1;
    return 1;
}

/* Same tests as NET_WHPIPE_IsBeaconAcceptable, but only those selected by flags (WHPIPE_CHECK_*) and without the notify call. */
int NET_WHPIPE_CheckBeaconFlags(WhPipeEntry *entry, u32 flags)
{
    WhPipeWork *work = g_pWhPipeWork;
    GFLNetSession *init = GFL_NET_GetInitParam();
    int gameKind = init->init.gameKind;
    u16 ggid = init->init.ggid;
    WhPipeBeacon *beacon = &entry->beacon;
    WhPipeBeaconCompareFunc compare;

    if ((flags & WHPIPE_CHECK_STATUS) && beacon->status != 0)
        return 0;
    if ((flags & WHPIPE_CHECK_RESERVED) && beacon->reserved != 0)
        return 0;
    if ((flags & WHPIPE_CHECK_CHECKSUM) && beacon->checksum != GF_STANDARD_CalcCrc16((u8 *)beacon + 2, 0x6e))
        return 0;
    if ((flags & WHPIPE_CHECK_GGID) && beacon->ggid != ggid)
        return 0;
    if (flags & WHPIPE_CHECK_KIND) {
        compare = init->init.compareBeaconFunc;
        if (compare != 0) {
            if (compare(gameKind, beacon->kind, work->userData) == 0)
                return 0;
        } else if (gameKind != beacon->kind) {
            return 0;
        }
    }
    if ((flags & WHPIPE_CHECK_MEMBERS) && beacon->connectedNum >= init->init.maxConnectNum)
        return 0;
    return 1;
}

void NET_WHPIPE_ClearEntries(void)
{
    WhPipeWork *work = g_pWhPipeWork;
    int i;

    for (i = 0; i < WHPIPE_ENTRY_MAX; i++)
        work->entryAge[i] = 0;
    MI_CpuFill8(work->entry, 0, 0xC00);
}

void NET_WHPIPE_ResetState(WhPipeWork *work)
{
    work->beaconStatus = 0;
    work->entryListChanged = 0;
    work->disconnectDetected = 0;
    work->watchDisconnect = 0;
    work->scanning = 0;
    work->running = 0;
}

/*
 * interface: original preserves incoming r0-r2 and spends r3 on the
 * indirect callback target; legacy void(void) callers omit those inputs.
 * void(void) callback spelling changes the target register to r0 (run 2).
 */
int NET_WHPIPE_ForwardEvent(u32 a, u32 b, u32 c)
{
    return g_pWhPipeWork->eventCallback(a, b, c);
}

/* Starts scanning for parents; clearEntries also empties the entry table first. */
int NET_WHPIPE_StartScan(int clearEntries)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work == 0)
        return 0;
    NET_WHPIPE_ResetState(work);
    if (clearEntries != 0)
        NET_WHPIPE_ClearEntries();
    DWCi_MOV_WH_SetReceiver(NET_WHPIPE_ForwardEvent);
    work->running = 1;
    if (WIH_GetSysState() == 1 && DWCi_MOV_WH_StartScan(NET_WHPIPE_StoreScannedEntry, 0, 0) != 0)
        return 1;
    return 0;
}

void NET_WHPIPE_TaskBeginFinalize(WhPipeWork *work)
{
    if (WIH_GetSysState() == 1 && WIH_Finalize() != 0) {
        work->shutdownCountdown = 0xFF;
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskWaitFinalize);
    }
    if (WIH_GetSysState() == 9) {
        work->shutdownCountdown = 0xFF;
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskWaitFinalize);
    }
}

void NET_WHPIPE_TaskWaitFinalize(WhPipeWork *work)
{
    work->shutdownCountdown--;
    if (WIH_GetSysState() == 0 || WIH_GetSysState() == 1) {
        NET_WHPIPE_SetTask(g_pWhPipeWork, 0);
        return;
    }
    if (WIH_GetSysState() == 9) {
        DWCi_MOV_WH_StateInEndKeyShare();
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskBeginFinalize);
        return;
    }
    if (work->shutdownCountdown == 0) {
        DWCi_MOV_WH_StateInEndKeyShare();
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskBeginFinalize);
    }
}

/* Asks the pipe to shut down; 1 when nothing is running or the request was taken, 0 when a request is pending or the finalize call failed. */
int NET_WHPIPE_RequestFinalize(void)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work == 0)
        return 1;
    if (work->shutdownRequest == 0 && WIH_Finalize() != 0) {
        work->shutdownCountdown = 0xFF;
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskWaitFinalize);
        return 1;
    }
    return 0;
}

void NET_WHPIPE_Destroy(void)
{
    if (g_pWhPipeWork != 0) {
        GFL_HEAP_Free(g_pWhPipeWork);
        g_pWhPipeWork = 0;
    }
}

int NET_WHPIPE_NotifyEntryAcceptable(void *arg)
{
    WhPipeEntry *entry = arg;
    WhPipeWork *work = g_pWhPipeWork;
    void (*onConnected)(void);

    if (NET_WHPIPE_IsBeaconAcceptable(entry) == 0)
        return 0;
    onConnected = work->onConnected;
    if (onConnected != 0)
        onConnected();
    return 1;
}

/*
 * Per-frame: counts every live entry down; an entry that reaches 0 is gone and flags the table as changed.
 * stand-in: the volatile halfword accesses and the repeated age test are needed;
 * plain entryAge[i] accesses compile 16 bytes shorter.
 */
void NET_WHPIPE_TickEntryAges(void)
{
    u8 *work = (u8 *)g_pWhPipeWork;
    int i;

    for (i = 0; i < WHPIPE_ENTRY_MAX; i++) {
        u16 age = *(volatile u16 *)(work + i * 2 + BW_OFFSETOF(WhPipeWork, entryAge));
        if (age != 0 && age != 0) {
            *(volatile u16 *)(work + i * 2 + BW_OFFSETOF(WhPipeWork, entryAge)) = *(volatile u16 *)(work + i * 2 + BW_OFFSETOF(WhPipeWork, entryAge)) - 1;
            if (*(volatile u16 *)(work + i * 2 + BW_OFFSETOF(WhPipeWork, entryAge)) == 0)
                work[BW_OFFSETOF(WhPipeWork, entryListChanged)] = 1;
        }
    }
}

/* Builds our own beacon from the init block and the game's beacon callbacks, and hands it to the parent start. */
void NET_WHPIPE_PublishBeacon(void)
{
    WhPipeBeacon *beacon;
    GFLNetSession *init;
    WhPipeWork *work;
    int (*getSize)(void *);
    int size;

    if (GFL_NET_GetRunState() == 0)
        return;
    work = g_pWhPipeWork;
    init = GFL_NET_GetInitParam();
    getSize = init->init.getBeaconSizeFunc;
    if (getSize == 0)
        return;
    size = getSize(work->userData);
    if (size >= WHPIPE_BEACON_DATA_SIZE) {
        OS_Terminate();
        return;
    }
    beacon = &work->beacon;
    beacon->kind = init->init.gameKind;
    beacon->ggid = init->init.ggid;
    beacon->reserved = 0;
    beacon->status = work->beaconStatus;
    MI_CpuCopy8(init->init.getBeaconDataFunc(work->userData), beacon->data, size);
    NET_WHPIPE_SetBeaconGameInfo((u8 *)&work->beacon, 0x70);
}

/* Refreshes the advertised beacon: copies fresh game bytes and, when the member count changed or the countdown ran out, republishes it. */
void NET_WHPIPE_RefreshBeacon(void)
{
    WhPipeWork *work = g_pWhPipeWork;
    WhPipeBeacon *beacon = &work->beacon;
    GFLNetSession *init = GFL_NET_GetInitParam();
    int (*getSize)(void *) = init->init.getBeaconSizeFunc;
    int size;

    if (getSize != 0) {
        size = getSize(work->userData);
        if (size > WHPIPE_BEACON_DATA_SIZE)
            GF_PANIC_Fail((const char *)sEmptyString, 0, (const char *)sEmptyString);
        MI_CpuCopy8(init->init.getBeaconDataFunc(work->userData), beacon->data, size);
    }
    if (beacon->connectedNum != NET_WHPIPE_GetConnectedNum()) {
        work->beaconRefreshCountdown = 0;
        beacon->connectedNum = NET_WHPIPE_GetConnectedNum();
    }
    if (work->beaconRefreshCountdown == 0) {
        NET_WHPIPE_SetBeaconGameInfo((u8 *)&work->beacon, 0x70);
        work->beaconRefreshCountdown = 2;
    }
    work->beaconRefreshCountdown--;
}

/* Reacts to the WH state each frame: refreshes the beacon, watches the tick for a link drop, and finishes shutdowns. */
void NET_WHPIPE_UpdateState(u32 tick)
{
    int mode = WIH_GetSysState();
    WhPipeWork *work = g_pWhPipeWork;

    if (NET_WHPIPE_IsDisconnectDetected() == 0)
        NET_WHPIPE_RefreshBeacon();
    if (work->startTime == 0xFFFF)
        work->startTime = tick;
    if (work->watchDisconnect != 0) {
        if (WIH_GetOwnAid() == 0 && NET_WHPIPE_GetChildBitmap() == 0)
            work->disconnectDetected = 1;
        if (work->startTime > tick)
            work->disconnectDetected = 1;
    }
    if (DWCi_MOV_WH_GetLastError() == 0x19)
        GFL_NET_CallErrorStateFunc(0);
    switch (mode) {
    case 0:
        if (work->shutdownRequest == 1)
            NET_WHPIPE_Destroy();
        break;
    case 1:
        if (work->shutdownRequest == 1 && WIH_End(0) != 0)
            return;
        if (work->shutdownRequest == 2 && WIH_End(0) != 0)
            return;
        break;
    case 8:
    case 9:
        if (work != 0) {
            if (work->disconnectDetected == 0)
                GFL_NET_CallStateChangeFunc(DWCi_MOV_WH_GetLastError());
            work->disconnectDetected = 1;
        }
        break;
    }
}

/* Main per-frame entry: runs the current task, the state update, the entry ageing and the join lock countdown. */
void NET_WHPIPE_Update(u32 tick)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work != 0 && work->task != 0)
        work->task(work);
    if (g_pWhPipeWork != 0)
        NET_WHPIPE_UpdateState(tick);
    if (g_pWhPipeWork != 0) {
        if (NET_WHPIPE_IsStateScanning() != 0)
            NET_WHPIPE_TickEntryAges();
    }
    if (g_pWhPipeWork != 0) {
        if (g_pWhPipeWork->joinLockFrames != 0) {
            WIH_SetScanTimerPaused(1);
            g_pWhPipeWork->timerPaused = 1;
            if (g_pWhPipeWork->joinLockHold == 0)
                g_pWhPipeWork->joinLockFrames -= 1;
        } else {
            WIH_SetScanTimerPaused(0);
            g_pWhPipeWork->timerPaused = 0;
        }
    }
    WIH_UpdateScanTimer();
}

/* 1 when the pipe exists, a link is up and the WH state is 4 or 5 (connected). */
int NET_WHPIPE_IsConnected(void)
{
    if (g_pWhPipeWork == 0)
        return 0;
    if (WIH_GetOwnAid() == 0 && NET_WHPIPE_GetChildBitmap() == 0)
        return 0;
    if (WIH_GetSysState() == 4 || WIH_GetSysState() == 5)
        return 1;
    return 0;
}

int NET_WHPIPE_IsAidConnected(u16 aid)
{
    if (g_pWhPipeWork == 0)
        return 0;
    if (WIH_GetSysState() != 4 && WIH_GetSysState() != 5)
        return 0;
    if (WIH_GetBitmap() & (1 << aid))
        return 1;
    return 0;
}

/*
 * evidence: original truncates the index to u16 before calling IsAidConnected; extern follows caller width.
 * extent: trailing two zero bytes are alignment padding.
 */
int NET_WHPIPE_GetConnectedNum(void) { int count = 0; int aid = 0; for (; aid < 8; aid++) { if (NET_WHPIPE_IsAidConnected(aid) != 0) count++; } return count; }

/* 1 when the pipe work block is allocated. */
int NET_WHPIPE_IsWorkAllocated(void)
{
    return g_pWhPipeWork != 0;
}

/* 1 when there is no pipe or the WH state is 1 (idle). */
int NET_WHPIPE_IsIdle(void) { if (g_pWhPipeWork != 0) { if (WIH_GetSysState() == 1) return 1; return 0; } return 1; }

/* Bitmap of connected aids without the parent bit. */
unsigned int NET_WHPIPE_GetChildBitmap(void) { if (g_pWhPipeWork != 0) return WIH_GetBitmap() & 0xFFFE; return 0; }

int NET_WHPIPE_IsDisconnectDetected(void)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work != 0 && work->disconnectDetected != 0)
        return 1;
    return 0;
}

void NET_WHPIPE_SetWatchDisconnect(u8 watch)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work != 0) {
        work->watchDisconnect = watch;
        work->startTime = 0xFFFF;
    }
}

/*
 * lever: integer address sum preserves base+0x58 and the final pointer+8;
 * plain pointer additions fold these into base+0x60 (r1 DIFF, r2 EXACT).
 */
u8 *NET_WHPIPE_GetEntryBeaconData(int index) { u8 *base = (u8 *)g_pWhPipeWork; if (base != 0 && g_pWhPipeWork->entryAge[index] != 0) return (u8 *)((base + 0x58) + index * 0xC0) + 8; return 0; }

u8 *NET_WHPIPE_GetEntryBssid(int index) { u8 *base = (u8 *)g_pWhPipeWork; if (base != 0 && *(u16 *)(base + BW_OFFSETOF(WhPipeWork, entryAge) + index * 2) != 0) return base + 0xC + index * 0xC0; return 0; }

/*
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that the arm9
 * wih_dwc.c pollers call.  Reads the per-slot age flag array of the pipe
 * work block and returns the slot's beacon kind byte, or 0 when the work
 * block or the slot is not live.  NET_WHPIPE_GetEntryKind is byte-identical.
 */
u8 NET_WHPIPE_GetEntryBeaconKind(int index)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work != 0 && work->entryAge[index] != 0)
        return work->entry[index].beacon.kind;
    return 0;
}

/* Frees one entry slot (age 0). */
void NET_WHPIPE_ReleaseEntrySlot(u32 index)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work != 0) {
        if (work->entryAge[index] != 0) {
            work->entryAge[index] = 0;
        }
    }
}

/* Frees every entry slot without clearing the entries themselves. */
void NET_WHPIPE_ReleaseAllEntrySlots(void)
{
    WhPipeWork *work;
    int i;

    work = g_pWhPipeWork;
    if (work != 0) {
        for (i = 0; i < WHPIPE_ENTRY_MAX; i++)
            work->entryAge[i] = 0;
    }
}

/* Tail-call thunk to NET_WHPIPE_ReleaseEntrySlot. */
void NET_WHPIPE_ReleaseEntry(unsigned int index)
{
    NET_WHPIPE_ReleaseEntrySlot(index);
}

/* Writes the beacon's game kind through outKind and returns the beacon's game data. */
u8 *NET_WHPIPE_GetEntryBeacon(WhPipeEntry *entry, u8 *outKind)
{
    WhPipeBeacon *beacon = &entry->beacon;

    *outKind = beacon->kind;
    return beacon->data;
}

/*
 * True once the WH layer has counted a sent beacon (beaconSendCount != 0).
 * Earlier tables named this DWC_IsValidFriendData; that match is by byte
 * shape only, the body reads the WH work, not a friend entry.
 */
int NET_WHPIPE_HasBeaconBeenSent(void *unused)
{
    if (WIH_GetBeaconSendCount())
        return 1;
    return 0;
}

/*
 * Task states of the wireless pipe: NET_WHPIPE_SetTask stores the next task
 * function into work->task, the main loop calls it once per frame.  The
 * WH system states used below are the NitroSDK wh.c ones: 0 stop, 1 idle,
 * 2 scanning, 3 busy, 4 connected, 5 data sharing, 7 measure channel,
 * 9 error.
 */

/*
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 */
int NET_WHPIPE_IsStateScanning(void) { if (WIH_GetSysState() == 2) return 1; return 0; }

int NET_WHPIPE_SendData(u16 *data, unsigned int size, WihResultCallback callbackArg) { return DWCi_MOV_WH_SendData(data, size, callbackArg); }

unsigned int NET_WHPIPE_GetConnectBitmap(void) { return WIH_GetBitmap(); }

int NET_WHPIPE_GetOwnAid(void) { return WIH_GetOwnAid(); }

void NET_WHPIPE_TaskConnectParent(WhPipeWork *work)
{
    u16 connectModeTable[2];
    GFLNetSession *net;
    int channel;

    int state = WIH_GetSysState();

    connectModeTable[0] = g_ParentConnectModes[0];
    connectModeTable[1] = g_ParentConnectModes[1];
    if (state == 7) {
        net = GFL_NET_GetInitParam();
        work->beaconStatus = 0;
        work->entryListChanged = 0;
        work->scanning = 0;
        work->running = 0;
        channel = WIH_FinishMeasureChannel();
        if (work->channel == 0xFF)
            work->channel = channel;
        else
            channel = work->channel;
        if (net->init.bRenewTgid != 0)
            work->tgid = WM_GetNextTgid();
        NET_WHPIPE_PublishBeacon();
        WIH_ParentConnect(connectModeTable[net->init.bMPMode], work->tgid, channel, net->init.maxConnectNum - 1);
        NET_WHPIPE_SetTask(g_pWhPipeWork, 0);
    }
}

void NET_WHPIPE_TaskStartParent(WhPipeWork *work) { if (WIH_GetSysState() == 1 && WIH_StartMeasureChannel() != 0) NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskConnectParent); }

int NET_WHPIPE_StartParent(int autoChannel)
{
    WhPipeWork *work = g_pWhPipeWork;
    if (work->task != 0)
        return 0;
    if (autoChannel != 0)
        work->channel = 0xff;
    DWCi_MOV_WH_SetReceiver(NET_WHPIPE_ForwardEvent);
    g_pWhPipeWork->running = 1;
    NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskStartParent);
    return 1;
}

void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len)
{
    WhPipeWork *work = g_pWhPipeWork;
    GFLNetSession *net = GFL_NET_GetInitParam();
    if (work != 0 && net != 0) {
        ((WhPipeBeacon *)buf)->checksum = GF_STANDARD_CalcCrc16(buf + 2, len - 2);
        DC_FlushRange(buf, len);
        if (WIH_GetSysState() == 1) {
            DWCi_MOV_WH_SetUserGameInfo(buf, (u16)len);
            return;
        }
        WIH_SetBeaconGameInfo((u16 *)buf, len, net->init.ggid, work->tgid);
    }
}

void NET_WHPIPE_TaskConnectChild(WhPipeWork *work)
{
    GFLNetSession *net = GFL_NET_GetInitParam();
    u16 connectModeTable[2];
    connectModeTable[0] = g_ChildConnectModes[0];
    connectModeTable[1] = g_ChildConnectModes[1];
    if (WIH_GetSysState() == 1 || WIH_GetSysState() == 2) {
        DWCi_MOV_WH_ChildConnectAuto(connectModeTable[net->init.bMPMode], (const u16 *)g_pWhPipeWork->targetBssid, 0);
        WIH_SetJudgeScanFunc(NET_WHPIPE_NotifyEntryAcceptable);
        DWCi_MOV_WH_SetReceiver(NET_WHPIPE_ForwardEvent);
        g_pWhPipeWork->running = 1;
        NET_WHPIPE_SetTask(g_pWhPipeWork, 0);
    }
}

int NET_WHPIPE_StartChild(u32 unused, u8 *bssid, u32 entryIndex, void (*onConnected)(void))
{
    GFL_NET_GetInitParam();
    if (g_pWhPipeWork->task != 0)
        return 0;
    if (WIH_GetSysState() == 2) {
        g_pWhPipeWork->scanning = 0;
        DWCi_MOV_WH_EndScan();
    }
    NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskConnectChild);
    if (bssid != 0)
        MI_CpuCopy8(bssid, g_pWhPipeWork->targetBssid, 6);
    else
        MI_CpuCopy8(g_pWhPipeWork->entry[entryIndex].bssid, g_pWhPipeWork->targetBssid, 6);
    g_pWhPipeWork->onConnected = onConnected;
    return 1;
}

void NET_WHPIPE_TaskFinishEnd(WhPipeWork *work) { if (WIH_GetSysState() == 0) { WIH_FreeWork(); NET_WHPIPE_Destroy(); } }

int NET_WHPIPE_RequestEnd(WihEndCallback endCallback) { if (WIH_End(endCallback) != 0) { NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskFinishEnd); return 1; } return 0; }

int NET_WHPIPE_AcceptChild(void *startParentCb, void *userArg) { return 1; }

int NET_WHPIPE_RejectChild(void *startParentCb, void *userArg) { return 0; }

/*
 * evidence: WIH_SetJudgeAcceptFunc stores its argument unchanged; the caller passes a function pointer.
 */
void NET_WHPIPE_SetAcceptChild(int acceptChild) { if (acceptChild != 0) WIH_SetJudgeAcceptFunc(NET_WHPIPE_AcceptChild); else WIH_SetJudgeAcceptFunc(NET_WHPIPE_RejectChild); }

void NET_WHPIPE_TaskParentSearchWait(WhPipeWork *work)
{
    if (g_pWhPipeWork->timerPaused == 0) {
        if (work->searchTimer != 0)
            work->searchTimer--;
        if (work->searchTimer == 0) {
            if (WIH_Finalize() != 0)
                NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskChildScanStart);
        }
    }
}

void NET_WHPIPE_TaskParentSearchStart(WhPipeWork *work)
{
    u8 channelTable[3];
    if (NET_WHPIPE_IsIdle() != 0) {
        channelTable[0] = g_SearchChannels[0];
        channelTable[1] = g_SearchChannels[1];
        channelTable[2] = g_SearchChannels[2];
        work->searchChannelIndex = GFL_USE_GetRandom(3);
        if (work->searchChannelIndex >= 3)
            work->searchChannelIndex = 0;
        NET_WHPIPE_PublishBeacon();
        if (WIH_ParentConnect(0, work->tgid, channelTable[work->searchChannelIndex], 1) != 0) {
            work->searchTimer = GFL_USE_GetRandom(0x98) + 0x3C;
            NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskParentSearchWait);
        }
    }
}

void NET_WHPIPE_TaskChildScanWait(WhPipeWork *work) { work->searchTimer--; if (work->searchTimer == 0) { DWCi_MOV_WH_EndScan(); NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskParentSearchStart); } }

void NET_WHPIPE_TaskChildScanStart(WhPipeWork *work)
{
    if (WIH_GetSysState() == 1) {
        if (DWCi_MOV_WH_StartScan(NET_WHPIPE_StoreScannedEntry, 0, 0) != 0) {
            work->searchTimer = GFL_USE_GetRandom(0x28) + 0x3C;
            NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskChildScanWait);
        }
    }
}

int NET_WHPIPE_StartAutoSearch(void)
{
    WhPipeWork *work = g_pWhPipeWork;
    if (work == 0)
        return 0;
    NET_WHPIPE_StartJoinLock(0);
    NET_WHPIPE_ResetState(work);
    NET_WHPIPE_ClearEntries();
    DWCi_MOV_WH_SetReceiver(NET_WHPIPE_ForwardEvent);
    work->running = 1;
    NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskChildScanStart);
    return 1;
}

void NET_WHPIPE_OnChildDisconnected(void)
{
    if (g_pWhPipeWork->watchDisconnect)
        g_pWhPipeWork->disconnectDetected = 1;
}

u8 NET_WHPIPE_GetEntryKind(u8 i)
{
    WhPipeWork *work = g_pWhPipeWork;

    if (work != 0 && work->entryAge[i] != 0)
        return work->entry[i].beacon.kind;
    return 0;
}

void NET_WHPIPE_SelectEntry(u32 i)
{
    WhPipeWork *work = g_pWhPipeWork;
    WIH_SetScanTarget(work->entry[i].channel, work->entry[i].bssid);
}

void NET_WHPIPE_StartJoinLock(int a)
{
    if (g_pWhPipeWork)
        g_pWhPipeWork->joinLockFrames = 20;
}

void NET_WHPIPE_SetBeaconStatus(u8 value)
{
    if (g_pWhPipeWork) {
        g_pWhPipeWork->beaconStatus = value;
        NET_WHPIPE_PublishBeacon();
    }
}

void NET_WHPIPE_SetNotifyCallback(WhPipeNotifyFunc callback, void *value)
{
    if (g_pWhPipeWork) {
        g_pWhPipeWork->notifyFn = callback;
        g_pWhPipeWork->notifyArg = value;
    }
}
