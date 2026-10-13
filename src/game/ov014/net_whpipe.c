/*
 * file:     net_whpipe.c
 * unit:     yes
 * function: func_0217721C, func_0217723C, func_0217725C, func_02177264, func_0217726C, func_02177274, func_0217727C, func_02177280, func_02177310, func_0217731C, func_021773E0, func_02177494, func_02177560, func_0217758C, func_021775AC, func_021775BC, func_02177614, func_02177660, func_021776C4, func_02177704, func_0217771C, func_02177744, func_0217778C, func_021777FC, func_02177888, func_0217796C, func_021779F4, func_02177A34, func_02177A74, func_02177A94, func_02177AA8, func_02177ACC, func_02177AEC, func_02177B0C, func_02177B2C, func_02177B58, func_02177B80, func_02177BAC, func_02177BCC, func_02177BF4, func_02177BFC
 * address:  0x0217721C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_GetGameKind 0x0203D5D4 arm
 *   WIH_DWC_GetAlertLevel 0x02010848 thumb
 *   func_0208EE9C 0x0208EE9C arm
 *   DWCi_MOV_WH_GetLastError  0x02178E68  thumb  ov014
 *   NET_WHPIPE_SetAcceptChild  0x02177EDC  thumb  ov014
 *   NET_WHPIPE_StartAutoSearch  0x02178034  thumb  ov014
 *   NET_WHPIPE_StartJoinLock  0x021780E4  thumb  ov014
 *   g_pWhPipeWork  0x021797A4  data   a4
 *   sFileNetWhPipe 0x02179780  data   a1
 *   func_02030734  0x02030734  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_021790E4  0x021790E4  thumb  ov014
 *   func_02178E1C  0x02178E1C  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02082BCC 0x02082BCC arm
 *   DWCi_MOV_WH_SetReceiver  0x0217933C  thumb  ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_StartScan  0x021785B4  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   DWCi_MOV_WH_StateInEndKeyShare  0x0217945C  thumb  ov014
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_02088234  0x02088234  arm
 *   NET_WHPIPE_SetBeaconGameInfo  0x02177D58  thumb  ov014
 *   sEmptyString   0x02179790  data   a4
 *   func_02034714  0x02034714  arm
 *   WIH_GetOwnAid  0x021795A4  thumb  ov014
 *   func_02179570  0x02179570  thumb  ov014
 *   GFL_NET_CallErrorStateFunc  0x0203D720  arm
 *   GFL_NET_CallStateChangeFunc  0x0203D754  arm
 *   NET_WHPIPE_IsStateScanning  0x02177C1C  thumb
 *   WIH_SetScanTimerPaused  0x02179664  thumb
 *   WIH_UpdateScanTimer  0x021793F8  thumb
 *   func_02178E38  0x02178E38  thumb  ov014
 */
#include "../arm9/net_whpipe_types.h"
#define OFFSETOF(type, field) ((u32)&((type *)0)->field)

typedef int BOOL;

extern u32 GFL_NET_GetGameKind(void);
extern u16 WIH_DWC_GetAlertLevel(void);
extern int func_0208EE9C(void);
int DWCi_MOV_WH_GetLastError(void);
extern void NET_WHPIPE_SetAcceptChild(int a);
extern int NET_WHPIPE_StartAutoSearch(void);
extern void NET_WHPIPE_StartJoinLock(int a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GFL_NET_GetInitParam(void);
extern u16 func_0208F1B4(void);
extern int func_021790E4(u32 heap, int a, int b);
extern void func_02178E1C(u32 v);
u16 func_0203F1FC(const u8 *src, u32 len);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_02082BCC(void *, u32, u32);
extern void DWCi_MOV_WH_SetReceiver(void *cb);
extern int func_02178E4C(void);
extern int DWCi_MOV_WH_StartScan(u32 a, u16 *b, u32 c);
extern int func_02179498(void);
extern void DWCi_MOV_WH_StateInEndKeyShare(void);
extern u32 func_020307B0(void *p);
extern int GFL_NET_GetRunState(void);
extern void func_02088234(void);
extern void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len);
extern void func_02034714(const char *expr, u32 line, const char *file);
unsigned short WIH_GetOwnAid(void);
int func_02179570(void (*cb)(int));
void GFL_NET_CallErrorStateFunc(u32 a);
void GFL_NET_CallStateChangeFunc(u32 a);
int NET_WHPIPE_IsStateScanning(void);
void WIH_SetScanTimerPaused(unsigned char v);
void WIH_UpdateScanTimer(void);
extern u16 func_02178E38(void);
int GFL_NET_DEVWIRELESS_GetSignalLevel(void);
int GFL_NET_DEVWIRELESS_GetLastErrorCode(void);
void GFL_NET_DEVWIRELESS_SetWatchDisconnect(unsigned char watch);
void GFL_NET_DEVWIRELESS_SetAcceptChild(int accept);
int GFL_NET_DEVWIRELESS_StartAutoSearch(void);
void GFL_NET_DEVWIRELESS_StartJoinLock(int frames);
void NET_WHPIPE_SetTask(WhPipeWork *work, WhPipeTask task);
int NET_WHPIPE_Create(int heapId, int wmParam, u32 userData, int forListening);
void NET_WHPIPE_SetEventCallback(int (*callback)(int a, int b, int c));
int NET_WHPIPE_IsBeaconAcceptable(WhPipeEntry *entry);
int NET_WHPIPE_StoreScannedEntry(WhPipeEntry *entry);
int NET_WHPIPE_CheckBeaconFlags(WhPipeEntry *entry, u32 flags);
void NET_WHPIPE_ClearEntries(void);
void NET_WHPIPE_ResetState(WhPipeWork *work);
int NET_WHPIPE_ForwardEvent(int a, int b, int c);
int NET_WHPIPE_StartScan(int clearEntries);
void NET_WHPIPE_TaskBeginFinalize(WhPipeWork *work);
void NET_WHPIPE_TaskWaitFinalize(WhPipeWork *work);
int NET_WHPIPE_RequestFinalize(void);
void NET_WHPIPE_Destroy(void);
int NET_WHPIPE_NotifyEntryAcceptable(WhPipeEntry *entry);
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
extern WhPipeWork *g_pWhPipeWork;
extern char sFileNetWhPipe[];
extern u8 sEmptyString[];


/*
 * Device table entries that belong to net_devwireless.c (they sit before the
 * __FILE__ anchor of net_whpipe.c); see misplaced.tsv.
 * extent: two zero alignment bytes at 0217723A; existing code starts 0217723C.
 */
int GFL_NET_DEVWIRELESS_GetSignalLevel(void)
{
    if (GFL_NET_GetGameKind() == 3) return 3 - WIH_DWC_GetAlertLevel();
    return 3 - func_0208EE9C();
}



/*
 * Normalises a queried mode: 5 maps to 0, and a zero mode with the predicate
 * set maps to 0x14.
 */
int GFL_NET_DEVWIRELESS_GetLastErrorCode(void)
{
    int code = DWCi_MOV_WH_GetLastError();

    if (code == 5)
        code = 0;
    if (NET_WHPIPE_IsDisconnectDetected() != 0 && code == 0)
        code = 0x14;
    return code;
}


void GFL_NET_DEVWIRELESS_SetWatchDisconnect(unsigned char watch)
{
    NET_WHPIPE_SetWatchDisconnect(watch);
}


void GFL_NET_DEVWIRELESS_SetAcceptChild(int accept)
{
    NET_WHPIPE_SetAcceptChild(accept);
}


int GFL_NET_DEVWIRELESS_StartAutoSearch(void)
{
    return NET_WHPIPE_StartAutoSearch();
}


void GFL_NET_DEVWIRELESS_StartJoinLock(int frames)
{
    NET_WHPIPE_StartJoinLock(frames);
}








void NET_WHPIPE_SetTask(WhPipeWork *work, WhPipeTask task)
{
    work->task = task;
}








int NET_WHPIPE_Create(int heapId, int wmParam, u32 userData, int forListening)
{
    WhPipeNetInit *init;
    WhPipeWork *work;

    GFL_NET_GetInitParam();
    init = GFL_NET_GetInitParam();
    if (g_pWhPipeWork != 0)
        return 0;
    work = func_02030734(heapId, 0xCF8, 1, sFileNetWhPipe, 0xed);
    g_pWhPipeWork = work;
    work->channel = 0xff;
    if (func_021790E4(heapId, wmParam, forListening) == 0)
        return 0;
    func_02178E1C(init->ggid);
    work->userData = userData;
    work->shutdownRequest = 0;
    work->startedFlag = 0;
    work->tgid = func_0208F1B4();
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
    WhPipeNetInit *init = GFL_NET_GetInitParam();
    WhPipeBeacon *beacon;
    int gameKind;
    u16 ggid;
    WhPipeBeaconCompareFunc compare;
    WhPipeNotifyFunc notify;

    gameKind = init->gameKind;
    ggid = init->ggid;
    beacon = &entry->beacon;
    if (beacon->status != 0)
        return 0;
    if (beacon->reserved != 0)
        return 0;
    if (beacon->checksum != func_0203F1FC((u8 *)beacon + 2, 0x6e))
        return 0;
    if (beacon->ggid != ggid)
        return 0;
    notify = g_pWhPipeWork->notifyFn;
    if (notify != 0)
        notify(g_pWhPipeWork->notifyArg, entry, beacon->kind, beacon->connectedNum);
    compare = init->compareBeacon;
    if (compare != 0) {
        if (compare(gameKind, beacon->kind, work->userData) == 0)
            return 0;
    } else if (gameKind != beacon->kind) {
        return 0;
    }
    if (gameKind != 0x14 && beacon->connectedNum >= init->maxConnectNum && init->maxConnectNum > 1)
        return 0;
    return 1;
}


/* Scan callback: files an acceptable parent in the entry table, refreshing the slot of a known bssid. */
int NET_WHPIPE_StoreScannedEntry(WhPipeEntry *entry)
{
    int i;
    WhPipeWork *work = g_pWhPipeWork;

    GFL_NET_GetInitParam();
    if (NET_WHPIPE_IsBeaconAcceptable(entry) == 0)
        return 0;
    for (i = 0; i < WHPIPE_ENTRY_MAX; i++) {
        if (work->entryAge[i] != 0 && func_0203EFC8(work->entry[i].bssid, entry->bssid, 6) == 0) {
            work->entryAge[i] = WHPIPE_ENTRY_LIFETIME;
            func_02082D44(entry, &work->entry[i], 0xC0);
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
    func_02082D44(entry, &work->entry[i], 0xC0);
    work->entryListChanged = 1;
    return 1;
}


/* Same tests as NET_WHPIPE_IsBeaconAcceptable, but only those selected by flags (WHPIPE_CHECK_*) and without the notify call. */
int NET_WHPIPE_CheckBeaconFlags(WhPipeEntry *entry, u32 flags)
{
    WhPipeWork *work = g_pWhPipeWork;
    WhPipeNetInit *init = GFL_NET_GetInitParam();
    int gameKind = init->gameKind;
    u16 ggid = init->ggid;
    WhPipeBeacon *beacon = &entry->beacon;
    WhPipeBeaconCompareFunc compare;

    if ((flags & WHPIPE_CHECK_STATUS) && beacon->status != 0)
        return 0;
    if ((flags & WHPIPE_CHECK_RESERVED) && beacon->reserved != 0)
        return 0;
    if ((flags & WHPIPE_CHECK_CHECKSUM) && beacon->checksum != func_0203F1FC((u8 *)beacon + 2, 0x6e))
        return 0;
    if ((flags & WHPIPE_CHECK_GGID) && beacon->ggid != ggid)
        return 0;
    if (flags & WHPIPE_CHECK_KIND) {
        compare = init->compareBeacon;
        if (compare != 0) {
            if (compare(gameKind, beacon->kind, work->userData) == 0)
                return 0;
        } else if (gameKind != beacon->kind) {
            return 0;
        }
    }
    if ((flags & WHPIPE_CHECK_MEMBERS) && beacon->connectedNum >= init->maxConnectNum)
        return 0;
    return 1;
}


void NET_WHPIPE_ClearEntries(void)
{
    WhPipeWork *work = g_pWhPipeWork;
    int i;

    for (i = 0; i < WHPIPE_ENTRY_MAX; i++)
        work->entryAge[i] = 0;
    func_02082BCC(work->entry, 0, 0xC00);
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
int NET_WHPIPE_ForwardEvent(int a, int b, int c)
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
    if (func_02178E4C() == 1 && DWCi_MOV_WH_StartScan((u32)NET_WHPIPE_StoreScannedEntry, 0, 0) != 0)
        return 1;
    return 0;
}


void NET_WHPIPE_TaskBeginFinalize(WhPipeWork *work)
{
    if (func_02178E4C() == 1 && func_02179498() != 0) {
        work->shutdownCountdown = 0xFF;
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskWaitFinalize);
    }
    if (func_02178E4C() == 9) {
        work->shutdownCountdown = 0xFF;
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskWaitFinalize);
    }
}


void NET_WHPIPE_TaskWaitFinalize(WhPipeWork *work)
{
    work->shutdownCountdown--;
    if (func_02178E4C() == 0 || func_02178E4C() == 1) {
        NET_WHPIPE_SetTask(g_pWhPipeWork, 0);
        return;
    }
    if (func_02178E4C() == 9) {
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
    if (work->shutdownRequest == 0 && func_02179498() != 0) {
        work->shutdownCountdown = 0xFF;
        NET_WHPIPE_SetTask(g_pWhPipeWork, NET_WHPIPE_TaskWaitFinalize);
        return 1;
    }
    return 0;
}


void NET_WHPIPE_Destroy(void)
{
    if (g_pWhPipeWork != 0) {
        func_020307B0(g_pWhPipeWork);
        g_pWhPipeWork = 0;
    }
}


int NET_WHPIPE_NotifyEntryAcceptable(WhPipeEntry *entry)
{
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
        u16 age = *(volatile u16 *)(work + i * 2 + OFFSETOF(WhPipeWork, entryAge));
        if (age != 0 && age != 0) {
            *(volatile u16 *)(work + i * 2 + OFFSETOF(WhPipeWork, entryAge)) = *(volatile u16 *)(work + i * 2 + OFFSETOF(WhPipeWork, entryAge)) - 1;
            if (*(volatile u16 *)(work + i * 2 + OFFSETOF(WhPipeWork, entryAge)) == 0)
                work[OFFSETOF(WhPipeWork, entryListChanged)] = 1;
        }
    }
}


/* Builds our own beacon from the init block and the game's beacon callbacks, and hands it to the parent start. */
void NET_WHPIPE_PublishBeacon(void)
{
    WhPipeBeacon *beacon;
    WhPipeNetInit *init;
    WhPipeWork *work;
    WhPipeBeaconSizeFunc getSize;
    int size;

    if (GFL_NET_GetRunState() == 0)
        return;
    work = g_pWhPipeWork;
    init = GFL_NET_GetInitParam();
    getSize = init->getBeaconSize;
    if (getSize == 0)
        return;
    size = getSize(work->userData);
    if (size >= WHPIPE_BEACON_DATA_SIZE) {
        func_02088234();
        return;
    }
    beacon = &work->beacon;
    beacon->kind = init->gameKind;
    beacon->ggid = init->ggid;
    beacon->reserved = 0;
    beacon->status = work->beaconStatus;
    func_02082D44((void *)init->getBeaconData(work->userData), beacon->data, size);
    NET_WHPIPE_SetBeaconGameInfo((u8 *)&work->beacon, 0x70);
}


/* Refreshes the advertised beacon: copies fresh game bytes and, when the member count changed or the countdown ran out, republishes it. */
void NET_WHPIPE_RefreshBeacon(void)
{
    WhPipeWork *work = g_pWhPipeWork;
    WhPipeBeacon *beacon = &work->beacon;
    WhPipeNetInit *init = GFL_NET_GetInitParam();
    WhPipeBeaconSizeFunc getSize = init->getBeaconSize;
    int size;

    if (getSize != 0) {
        size = getSize(work->userData);
        if (size > WHPIPE_BEACON_DATA_SIZE)
            func_02034714((const char *)sEmptyString, 0, (const char *)sEmptyString);
        func_02082D44((void *)init->getBeaconData(work->userData), beacon->data, size);
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
    int mode = func_02178E4C();
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
        if (work->shutdownRequest == 1 && func_02179570(0) != 0)
            return;
        if (work->shutdownRequest == 2 && func_02179570(0) != 0)
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
    if (func_02178E4C() == 4 || func_02178E4C() == 5)
        return 1;
    return 0;
}


int NET_WHPIPE_IsAidConnected(u16 aid)
{
    if (g_pWhPipeWork == 0)
        return 0;
    if (func_02178E4C() != 4 && func_02178E4C() != 5)
        return 0;
    if (func_02178E38() & (1 << aid))
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
int NET_WHPIPE_IsIdle(void) { if (g_pWhPipeWork != 0) { if (func_02178E4C() == 1) return 1; return 0; } return 1; }


/* Bitmap of connected aids without the parent bit. */
unsigned int NET_WHPIPE_GetChildBitmap(void) { if (g_pWhPipeWork != 0) return func_02178E38() & 0xFFFE; return 0; }


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
u8 *NET_WHPIPE_GetEntryBeaconData(int index) { u8 *base = (u8 *)g_pWhPipeWork; if (base != 0 && *(u16 *)(base + OFFSETOF(WhPipeWork, entryAge) + index * 2) != 0) return (u8 *)((unsigned int)(base + 0x58) + index * 0xC0) + 8; return 0; }
u8 *NET_WHPIPE_GetEntryBssid(int index) { u8 *base = (u8 *)g_pWhPipeWork; if (base != 0 && *(u16 *)(base + OFFSETOF(WhPipeWork, entryAge) + index * 2) != 0) return base + 0xC + index * 0xC0; return 0; }
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
