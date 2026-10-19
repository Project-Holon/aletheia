/*
 * file:     net_devwireless.c
 * unit:     yes
 * function: GFL_NET_DEVWIRELESS_GetDeviceTable, GFL_NET_DEVWIRELESS_Setup, GFL_NET_DEVWIRELESS_Begin, GFL_NET_DEVWIRELESS_Update, GFL_NET_DEVWIRELESS_RequestDisconnect, GFL_NET_DEVWIRELESS_OnShutdownDone, GFL_NET_DEVWIRELESS_Cleanup, GFL_NET_DEVWIRELESS_ClearScanList, GFL_NET_DEVWIRELESS_UnusedSlot7, GFL_NET_DEVWIRELESS_UnusedSlot8, GFL_NET_DEVWIRELESS_UnusedSlot9, GFL_NET_DEVWIRELESS_GetScanResult, GFL_NET_DEVWIRELESS_GetScanResultMac, GFL_NET_DEVWIRELESS_UnusedSlot12, GFL_NET_DEVWIRELESS_UnusedSlot13, GFL_NET_DEVWIRELESS_HasBeaconBeenSent, GFL_NET_DEVWIRELESS_SetConnectCallback, GFL_NET_DEVWIRELESS_StartParent, GFL_NET_DEVWIRELESS_StartChildScan, GFL_NET_DEVWIRELESS_StartChild, GFL_NET_DEVWIRELESS_UnusedSlot19, GFL_NET_DEVWIRELESS_RequestShutdown, GFL_NET_DEVWIRELESS_IsDataSharing, GFL_NET_DEVWIRELESS_StepDataSharing, GFL_NET_DEVWIRELESS_GetSharedData, GFL_NET_DEVWIRELESS_SendData, GFL_NET_DEVWIRELESS_SetEventCallback, GFL_NET_DEVWIRELESS_IsActive, GFL_NET_DEVWIRELESS_IsConnected, NET_WHPIPE_IsWorkNotAllocated, NET_WHPIPE_IsWhIdle, NET_WHPIPE_QueryConnectBitmap, NET_WHPIPE_QueryOwnAid, GFL_NET_DEVWIRELESS_GetSignalLevel, GFL_NET_DEVWIRELESS_GetLastErrorCode, GFL_NET_DEVWIRELESS_SetWatchDisconnect, GFL_NET_DEVWIRELESS_SetAcceptChild, GFL_NET_DEVWIRELESS_StartAutoSearch, GFL_NET_DEVWIRELESS_StartJoinLock
 * address:  0x02177020
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
 *   sDevWirelessWork 0x021797A0  data   a4
 *   sFileNetDevWireless 0x0217976C  data   a1
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
 *   WIH_SetConnectCallback 0x02179628 thumb ov014
 *   NET_WHPIPE_StartParent 0x02177D0C thumb ov014
 *   NET_WHPIPE_StartScan 0x021775BC thumb ov014
 *   NET_WHPIPE_StartChild 0x02177E20 thumb ov014
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   WIH_StepDS 0x021793B8 thumb ov014
 *   WIH_GetSharedDataAdr 0x02179394 thumb ov014
 *   NET_WHPIPE_SendData 0x02177C30 thumb ov014
 *   NET_WHPIPE_SetEventCallback  0x02177310  thumb
 *   NET_WHPIPE_IsConnected 0x021779F4 thumb ov014
 *   GFL_NET_GetGameKind 0x0203D5D4 arm
 *   WIH_DWC_GetAlertLevel 0x02010848 thumb
 *   WM_GetLinkLevel 0x0208EE9C arm
 *   DWCi_MOV_WH_GetLastError  0x02178E68  thumb  ov014
 *   NET_WHPIPE_IsWorkAllocated 0x02177A94 thumb ov014
 *   NET_WHPIPE_IsDisconnectDetected 0x02177AEC thumb ov014
 *   NET_WHPIPE_SetWatchDisconnect 0x02177B0C thumb ov014
 *   NET_WHPIPE_GetConnectBitmap 0x02177C3C thumb ov014
 *   NET_WHPIPE_GetOwnAid 0x02177C44 thumb ov014
 *   NET_WHPIPE_SetAcceptChild 0x02177EDC thumb ov014
 *   NET_WHPIPE_StartAutoSearch 0x02178034 thumb ov014
 *   NET_WHPIPE_StartJoinLock 0x021780E4 thumb ov014
 */
#include "../arm9/net_whpipe_types.h"


/* State of the wireless device layer; one block, allocated by the setup slot. */
typedef struct DevWirelessWork {
    u32 setupParam;                         /* second argument of the setup slot, kept for the owner */
    void (*onEndedCallback)(void *result);  /* called once the pipe has shut down */
} DevWirelessWork;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u8 *GFL_NET_GetInitParam(void);

extern int NET_WHPIPE_Create(int a, int b, u32 c, int d);

extern int NET_WHPIPE_IsIdle(void);

extern void NET_WHPIPE_Update(u32);

extern int NET_WHPIPE_RequestFinalize(void);

extern u32 GFL_HEAP_Free(void *p);

extern int NET_WHPIPE_RequestEnd(int a);

extern void NET_WHPIPE_ClearEntries(void);

/* Pipe layer (net_whpipe.c, net_whpipe_p02.c) */
extern u8 *NET_WHPIPE_GetEntryBeaconData(int entryIndex);

extern u8 *NET_WHPIPE_GetEntryBssid(int entryIndex);

extern int NET_WHPIPE_StartParent(int autoChannel);

extern int NET_WHPIPE_StartScan(int resetWork);

extern int NET_WHPIPE_StartChild(u32 unused, u8 *bssid, u32 entryIndex, u32 onConnected);

extern int NET_WHPIPE_SendData(int data, u32 size, int callbackArg);

extern void NET_WHPIPE_SetEventCallback(u32 callback);

extern int NET_WHPIPE_IsConnected(void);

/* WH layer (wih.c) and the beacon-sent check (net_whpipe.c) */
extern int NET_WHPIPE_HasBeaconBeenSent(void);

extern void WIH_SetConnectCallback(unsigned connectCallback);

extern int WIH_GetSysState(void);

extern int WIH_StepDS(int sendData);

extern int WIH_GetSharedDataAdr(u16 aid);

void *GFL_NET_DEVWIRELESS_GetDeviceTable(void);

int GFL_NET_DEVWIRELESS_Setup(int heapId, u32 setupParam, int wmParam, int userData);

int GFL_NET_DEVWIRELESS_Begin(void (*doneCallback)(void));

int GFL_NET_DEVWIRELESS_Update(u32 tick);

int GFL_NET_DEVWIRELESS_RequestDisconnect(void);

int GFL_NET_DEVWIRELESS_OnShutdownDone(void *result);

int GFL_NET_DEVWIRELESS_Cleanup(void (*endCallback)(void *));

int GFL_NET_DEVWIRELESS_ClearScanList(void);

int GFL_NET_DEVWIRELESS_UnusedSlot7(void);

int GFL_NET_DEVWIRELESS_UnusedSlot8(void);

int GFL_NET_DEVWIRELESS_UnusedSlot9(void);

void *GFL_NET_DEVWIRELESS_GetScanResult(int entryIndex);

void *GFL_NET_DEVWIRELESS_GetScanResultMac(int entryIndex);

int GFL_NET_DEVWIRELESS_UnusedSlot12(void);

int GFL_NET_DEVWIRELESS_UnusedSlot13(void);

int GFL_NET_DEVWIRELESS_HasBeaconBeenSent(void);

int GFL_NET_DEVWIRELESS_SetConnectCallback(int connectCallback);

int GFL_NET_DEVWIRELESS_StartParent(int autoChannel);

int GFL_NET_DEVWIRELESS_StartChildScan(int resetWork);

int GFL_NET_DEVWIRELESS_StartChild(u32 unused, u8 *bssid, u32 entryIndex, u32 unused2, u32 onConnected);

int GFL_NET_DEVWIRELESS_UnusedSlot19(void);

int GFL_NET_DEVWIRELESS_RequestShutdown(void);

int GFL_NET_DEVWIRELESS_IsDataSharing(void);

int GFL_NET_DEVWIRELESS_StepDataSharing(int sendData);

int GFL_NET_DEVWIRELESS_GetSharedData(u32 aid);

int GFL_NET_DEVWIRELESS_SendData(int data,u32 size,int unused,int callbackArg);

int GFL_NET_DEVWIRELESS_SetEventCallback(u32 callback);

int GFL_NET_DEVWIRELESS_IsActive(void);

int GFL_NET_DEVWIRELESS_IsConnected(void);

extern DevWirelessWork *sDevWirelessWork;

extern char sFileNetDevWireless[];

/* Returns the device table (slot array at 0x021796A0) that the net core calls into. */
void *GFL_NET_DEVWIRELESS_GetDeviceTable(void)
{
    return (void *)0x021796A0;
}

/* Slot 1: allocates the layer and starts the pipe; wmParam goes to the WH init, userData to the pipe callbacks. */
int GFL_NET_DEVWIRELESS_Setup(int heapId, u32 setupParam, int wmParam, int userData)
{
    int forListening;
    DevWirelessWork *work;

    if (sDevWirelessWork != 0)
        return 0;
    work = GFL_HEAP_Alloc(heapId, 8, 1, sFileNetDevWireless, 0xb4);
    forListening = 1;
    sDevWirelessWork = work;
    work->setupParam = setupParam;
    if (GFL_NET_GetInitParam()[0x65] != 5)
        forListening = 0;
    return NET_WHPIPE_Create(heapId, wmParam, userData, forListening);
}

/*
 * Slot 2: nothing to start asynchronously; calls the done callback at once.
 * extent: trailing two-byte zero alignment padding.
 */
int GFL_NET_DEVWIRELESS_Begin(void (*doneCallback)(void))
{
    if (doneCallback != 0) {
        NET_WHPIPE_IsIdle();
        doneCallback();
    }
    return NET_WHPIPE_IsIdle();
}

/*
 * Slot 3: per-frame update with the tick counter.
 * extent: lead and unlabelled tail-call follower at 0x021770A0.
 */
int GFL_NET_DEVWIRELESS_Update(u32 tick)
{
    NET_WHPIPE_Update(tick);
    return 1;
}

/* Slot 4: asks the pipe to shut down (same target as slot 21). */
int GFL_NET_DEVWIRELESS_RequestDisconnect(void)
{
    return NET_WHPIPE_RequestFinalize();
}

/* Pipe end callback: reports to the owner, frees the layer. */
int GFL_NET_DEVWIRELESS_OnShutdownDone(void *result)
{
    if (sDevWirelessWork->onEndedCallback != 0)
        sDevWirelessWork->onEndedCallback(result);
    GFL_HEAP_Free(sDevWirelessWork);
    sDevWirelessWork = 0;
    return 1;
}

/* Slot 5: ends the pipe; endCallback runs when the end has finished. */
int GFL_NET_DEVWIRELESS_Cleanup(void (*endCallback)(void *))
{
    if(sDevWirelessWork != 0) {
        sDevWirelessWork->onEndedCallback = endCallback;
        return NET_WHPIPE_RequestEnd((int)GFL_NET_DEVWIRELESS_OnShutdownDone);
    }
    return 1;
}

/* Slot 6: forgets all scanned parents. */
int GFL_NET_DEVWIRELESS_ClearScanList(void) { NET_WHPIPE_ClearEntries(); return 1; }

int GFL_NET_DEVWIRELESS_UnusedSlot7(void) { return 1; }

int GFL_NET_DEVWIRELESS_UnusedSlot8(void) { return 1; }

int GFL_NET_DEVWIRELESS_UnusedSlot9(void) { return 1; }

/*
 * Slot 10: beacon game data of scan entry entryIndex (null for an index of
 * 16 or more, or an empty entry).
 */
void *GFL_NET_DEVWIRELESS_GetScanResult(int entryIndex)
{
    if (entryIndex >= 16) return 0;
    return NET_WHPIPE_GetEntryBeaconData(entryIndex);
}

/* Slot 11: BSSID of scan entry entryIndex (null for an index of 16 or more, or an empty entry). */
void *GFL_NET_DEVWIRELESS_GetScanResultMac(int entryIndex) { if (entryIndex >= 16) return 0; return NET_WHPIPE_GetEntryBssid(entryIndex); }

/* Slot 12: unused by this device; reports success. */
int GFL_NET_DEVWIRELESS_UnusedSlot12(void) { return 1; }

/* Slot 13: unused by this device; reports success. */
int GFL_NET_DEVWIRELESS_UnusedSlot13(void) { return 1; }

/* Slot 14: nonzero once the WH layer has counted a sent beacon. */
int GFL_NET_DEVWIRELESS_HasBeaconBeenSent(void) { return NET_WHPIPE_HasBeaconBeenSent(); }

/* Slot 15: stores the callback the WH layer calls when a child connects. */
int GFL_NET_DEVWIRELESS_SetConnectCallback(int connectCallback) { WIH_SetConnectCallback(connectCallback); return 1; }

/* Slot 16: starts the parent task of the pipe; autoChannel nonzero lets it pick the channel. */
int GFL_NET_DEVWIRELESS_StartParent(int autoChannel) { return NET_WHPIPE_StartParent(autoChannel); }

/* Slot 17: starts the child-side scan; resetWork nonzero first clears the pipe work block. */
int GFL_NET_DEVWIRELESS_StartChildScan(int resetWork) { return NET_WHPIPE_StartScan(resetWork); }

/* Slot 18: starts the child connect task toward the given BSSID (or scan entry); onConnected runs after. */
int GFL_NET_DEVWIRELESS_StartChild(u32 unused, u8 *bssid, u32 entryIndex, u32 unused2, u32 onConnected) { return NET_WHPIPE_StartChild(unused,bssid,entryIndex,onConnected); }

/* Slot 19: unused by this device; reports failure. */
int GFL_NET_DEVWIRELESS_UnusedSlot19(void) { return 0; }

/* Slot 21: asks the pipe to shut down; nonzero once the request was accepted. */
int GFL_NET_DEVWIRELESS_RequestShutdown(void) { return NET_WHPIPE_RequestFinalize(); }

/* Slot 22: true while the WH state is 5 (data sharing running). */
int GFL_NET_DEVWIRELESS_IsDataSharing(void) { if (WIH_GetSysState() == 5) return 1; return 0; }

/* Slot 23: submits this frame's send data to the data-sharing step. */
int GFL_NET_DEVWIRELESS_StepDataSharing(int sendData) { return WIH_StepDS(sendData); }

/* Slot 24: data-sharing entry received from the child with the given aid. */
int GFL_NET_DEVWIRELESS_GetSharedData(u32 aid) { return WIH_GetSharedDataAdr((u16)aid); }

/*
 * Slot 25: send data of the given size, completion callbackArg. The second
 * argument is forwarded unchanged to 02177C30; that leaf performs the u16
 * truncation itself. Its matched signature uses full width.
 */
int GFL_NET_DEVWIRELESS_SendData(int data,u32 size,int unused,int callbackArg) { return NET_WHPIPE_SendData(data,size,callbackArg); }

/* Slot 26: stores the pipe's event callback; always succeeds. */
int GFL_NET_DEVWIRELESS_SetEventCallback(u32 callback)
{
    NET_WHPIPE_SetEventCallback(callback);
    return 1;
}

/* Slot 27: true while the WH layer is running (state 1 to 10, not stopped). */
int GFL_NET_DEVWIRELESS_IsActive(void)
{
    switch (WIH_GetSysState()) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: return 1;
    case 0: default: return 0;
    }
}

/* Slot 28: true while connected (pipe task running and WH state 4 or 5). */
int GFL_NET_DEVWIRELESS_IsConnected(void) { return NET_WHPIPE_IsConnected(); }

extern u32 GFL_NET_GetGameKind(void);

extern u16 WIH_DWC_GetAlertLevel(void);

extern int WM_GetLinkLevel(void);

int DWCi_MOV_WH_GetLastError(void);

int NET_WHPIPE_IsWorkNotAllocated(void);

int NET_WHPIPE_IsWhIdle(void);

unsigned int NET_WHPIPE_QueryConnectBitmap(void);

int NET_WHPIPE_QueryOwnAid(void);

int GFL_NET_DEVWIRELESS_GetSignalLevel(void);

int GFL_NET_DEVWIRELESS_GetLastErrorCode(void);

void GFL_NET_DEVWIRELESS_SetWatchDisconnect(unsigned char watch);

void GFL_NET_DEVWIRELESS_SetAcceptChild(int accept);

int GFL_NET_DEVWIRELESS_StartAutoSearch(void);

void GFL_NET_DEVWIRELESS_StartJoinLock(int frames);

int NET_WHPIPE_IsWorkAllocated(void);

int NET_WHPIPE_IsDisconnectDetected(void);

void NET_WHPIPE_SetWatchDisconnect(u8 watch);

unsigned int NET_WHPIPE_GetConnectBitmap(void);

int NET_WHPIPE_GetOwnAid(void);

void NET_WHPIPE_SetAcceptChild(int acceptChild);

int NET_WHPIPE_StartAutoSearch(void);

void NET_WHPIPE_StartJoinLock(int a);

int NET_WHPIPE_IsWorkNotAllocated(void)
{
    if (NET_WHPIPE_IsWorkAllocated() == 0)
        return 1;
    return 0;
}

int NET_WHPIPE_IsWhIdle(void)
{
    if (WIH_GetSysState() == 1)
        return 1;
    return 0;
}

unsigned int NET_WHPIPE_QueryConnectBitmap(void)
{
    return NET_WHPIPE_GetConnectBitmap();
}

int NET_WHPIPE_QueryOwnAid(void)
{
    return NET_WHPIPE_GetOwnAid();
}

/*
 * Device table entries that belong to net_devwireless.c (they sit before the
 * __FILE__ anchor of net_whpipe.c); see misplaced.tsv.
 * extent: two zero alignment bytes at 0217723A; existing code starts 0217723C.
 */
int GFL_NET_DEVWIRELESS_GetSignalLevel(void)
{
    if (GFL_NET_GetGameKind() == 3) return 3 - WIH_DWC_GetAlertLevel();
    return 3 - WM_GetLinkLevel();
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
