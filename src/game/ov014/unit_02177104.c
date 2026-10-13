/*
 * file:     unit_02177104.c (home: net_devwireless.c, slots 10-28 of the device table at 0x021796A0)
 * unit:     yes
 * function: GFL_NET_DEVWIRELESS_GetScanResult, GFL_NET_DEVWIRELESS_GetScanResultMac, GFL_NET_DEVWIRELESS_SetConnectCallback, GFL_NET_DEVWIRELESS_StartChild, GFL_NET_DEVWIRELESS_IsDataSharing, GFL_NET_DEVWIRELESS_SetEventCallback, GFL_NET_DEVWIRELESS_IsActive
 * address:  0x02177104
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
 *   func_02177B2C 0x02177B2C thumb ov014
 *   func_02177B58 0x02177B58 thumb ov014
 *   WIH_HasBeaconBeenSent 0x02177C08 thumb ov014
 *   WIH_SetConnectCallback 0x02179628 thumb ov014
 *   NET_WHPIPE_StartParent 0x02177D0C thumb ov014
 *   func_021775BC 0x021775BC thumb ov014
 *   NET_WHPIPE_StartChild 0x02177E20 thumb ov014
 *   func_021776C4 0x021776C4 thumb ov014
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_021793B8 0x021793B8 thumb ov014
 *   func_02179394 0x02179394 thumb ov014
 *   NET_WHPIPE_SendData 0x02177C30 thumb ov014
 *   func_02177310  0x02177310  thumb
 *   func_021779F4 0x021779F4 thumb ov014
 */
typedef unsigned char  u8;

typedef unsigned int u32;

typedef unsigned short u16;

/* Pipe layer (net_whpipe.c, net_whpipe_p02.c) */
extern u8 *func_02177B2C(int entryIndex);
extern u8 *func_02177B58(int entryIndex);
extern int NET_WHPIPE_StartParent(int autoChannel);
extern int func_021775BC(int resetWork);
extern int NET_WHPIPE_StartChild(u32 unused, u8 *bssid, u32 entryIndex, u32 onConnected);
extern int func_021776C4(void);
extern int NET_WHPIPE_SendData(int data, u32 size, int callbackArg);
extern void func_02177310(u32 callback);
extern int func_021779F4(void);
/* WH layer (wih.c) and the beacon-sent check (unit_02177C08.c) */
extern int WIH_HasBeaconBeenSent(void);
extern void WIH_SetConnectCallback(unsigned connectCallback);
extern int func_02178E4C(void);
extern int func_021793B8(int sendData);
extern int func_02179394(u16 aid);

/* Device table slots, in table order (see g_021796A0). */
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
int GFL_NET_DEVWIRELESS_SendData(int data, u32 size, int unused, int callbackArg);
int GFL_NET_DEVWIRELESS_SetEventCallback(u32 callback);
int GFL_NET_DEVWIRELESS_IsActive(void);
int GFL_NET_DEVWIRELESS_IsConnected(void);

/*
 * Slot 10: beacon game data of scan entry entryIndex (null for an index of
 * 16 or more, or an empty entry).
 */
void *GFL_NET_DEVWIRELESS_GetScanResult(int entryIndex)
{
    if (entryIndex >= 16) return 0;
    return func_02177B2C(entryIndex);
}

/* Slot 11: BSSID of scan entry entryIndex (null for an index of 16 or more, or an empty entry). */
void *GFL_NET_DEVWIRELESS_GetScanResultMac(int entryIndex) { if (entryIndex >= 16) return 0; return func_02177B58(entryIndex); }

/* Slot 12: unused by this device; reports success. */
int GFL_NET_DEVWIRELESS_UnusedSlot12(void) { return 1; }

/* Slot 13: unused by this device; reports success. */
int GFL_NET_DEVWIRELESS_UnusedSlot13(void) { return 1; }

/* Slot 14: nonzero once the WH layer has counted a sent beacon. */
int GFL_NET_DEVWIRELESS_HasBeaconBeenSent(void) { return WIH_HasBeaconBeenSent(); }

/* Slot 15: stores the callback the WH layer calls when a child connects. */
int GFL_NET_DEVWIRELESS_SetConnectCallback(int connectCallback) { WIH_SetConnectCallback(connectCallback); return 1; }

/* Slot 16: starts the parent task of the pipe; autoChannel nonzero lets it pick the channel. */
int GFL_NET_DEVWIRELESS_StartParent(int autoChannel) { return NET_WHPIPE_StartParent(autoChannel); }

/* Slot 17: starts the child-side scan; resetWork nonzero first clears the pipe work block. */
int GFL_NET_DEVWIRELESS_StartChildScan(int resetWork) { return func_021775BC(resetWork); }

/* Slot 18: starts the child connect task toward the given BSSID (or scan entry); onConnected runs after. */
int GFL_NET_DEVWIRELESS_StartChild(u32 unused, u8 *bssid, u32 entryIndex, u32 unused2, u32 onConnected) { return NET_WHPIPE_StartChild(unused,bssid,entryIndex,onConnected); }

/* Slot 19: unused by this device; reports failure. */
int GFL_NET_DEVWIRELESS_UnusedSlot19(void) { return 0; }

/* Slot 21: asks the pipe to shut down; nonzero once the request was accepted. */
int GFL_NET_DEVWIRELESS_RequestShutdown(void) { return func_021776C4(); }

/* Slot 22: true while the WH state is 5 (data sharing running). */
int GFL_NET_DEVWIRELESS_IsDataSharing(void) { if (func_02178E4C() == 5) return 1; return 0; }

/* Slot 23: submits this frame's send data to the data-sharing step. */
int GFL_NET_DEVWIRELESS_StepDataSharing(int sendData) { return func_021793B8(sendData); }

/* Slot 24: data-sharing entry received from the child with the given aid. */
int GFL_NET_DEVWIRELESS_GetSharedData(u32 aid) { return func_02179394((u16)aid); }

/*
 * Slot 25: send data of the given size, completion callbackArg. The second
 * argument is forwarded unchanged to 02177C30; that leaf performs the u16
 * truncation itself. Its matched signature uses full width.
 */
int GFL_NET_DEVWIRELESS_SendData(int data,u32 size,int unused,int callbackArg) { return NET_WHPIPE_SendData(data,size,callbackArg); }


/* Slot 26: stores the pipe's event callback; always succeeds. */
int GFL_NET_DEVWIRELESS_SetEventCallback(u32 callback)
{
    func_02177310(callback);
    return 1;
}

/* Slot 27: true while the WH layer is running (state 1 to 10, not stopped). */
int GFL_NET_DEVWIRELESS_IsActive(void)
{
    switch (func_02178E4C()) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: return 1;
    case 0: default: return 0;
    }
}

/* Slot 28: true while connected (pipe task running and WH state 4 or 5). */
int GFL_NET_DEVWIRELESS_IsConnected(void) { return func_021779F4(); }
