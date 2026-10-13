/*
 * file:     net_whpipe_p02.c
 * unit:     yes
 * function: NET_WHPIPE_IsStateScanning, NET_WHPIPE_TaskConnectParent, NET_WHPIPE_TaskStartParent, NET_WHPIPE_StartParent, NET_WHPIPE_SetBeaconGameInfo, NET_WHPIPE_TaskConnectChild, NET_WHPIPE_StartChild, NET_WHPIPE_TaskFinishEnd, NET_WHPIPE_RequestEnd, NET_WHPIPE_SetAcceptChild, NET_WHPIPE_TaskParentSearchWait, NET_WHPIPE_TaskParentSearchStart, NET_WHPIPE_TaskChildScanWait, NET_WHPIPE_TaskChildScanStart, NET_WHPIPE_StartAutoSearch, NET_WHPIPE_OnChildDisconnected, NET_WHPIPE_GetEntryKind, NET_WHPIPE_SelectEntry, NET_WHPIPE_StartJoinLock, NET_WHPIPE_SetBeaconStatus, NET_WHPIPE_SetNotifyCallback
 * address:  0x02177C1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from wih.c at 0x02178138 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   g_ParentConnectModes     0x0217967C  data   a2
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02178E28  0x02178E28  thumb  ov014
 *   g_ChildConnectModes     0x02179680  data  ov014  a2
 *   func_0217771C  0x0217771C  thumb  ov014
 *   func_02082D44  0x02082D44  arm
 *   func_02177704 0x02177704 thumb ov014
 *   g_SearchChannels     0x02179678  data  a1
 *   func_02177AA8  0x02177AA8  thumb  ov014
 *   func_020056EC  0x020056EC  thumb
 *   func_021773E0  0x021773E0  thumb  ov014
 *   func_0217758C  0x0217758C  thumb  ov014
 *   func_02177560  0x02177560  thumb  ov014
 *   DWCi_MOV_WH_ChildConnectAuto 0x02178524 thumb ov014
 *   DWCi_MOV_WH_StartScan 0x021785B4 thumb ov014
 *   WIH_SetScanTarget 0x02178714 thumb ov014
 *   DWCi_MOV_WH_EndScan 0x021788FC thumb ov014
 *   func_02178E38 0x02178E38 thumb ov014
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_02179024 0x02179024 thumb ov014
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   func_02179288 0x02179288 thumb ov014
 *   func_02179328 0x02179328 thumb ov014
 *   DWCi_MOV_WH_SetReceiver 0x0217933C thumb ov014
 *   DWCi_MOV_WH_SendData 0x02179368 thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_02179570 0x02179570 thumb ov014
 *   WIH_GetOwnAid 0x021795A4 thumb ov014
 *   WIH_SetJudgeScanFunc 0x021795C0 thumb ov014
 *   WIH_SetBeaconGameInfo 0x021795D4 thumb ov014
 */
#include "../arm9/net_whpipe_types.h"

typedef int BOOL;

extern void *GFL_NET_GetInitParam(void);
extern u16 func_0208F1B4(void);
extern void func_0217778C(void);
extern void func_0217727C(WhPipeWork *work, WhPipeTask task);
int func_021775AC(int a, int b, int c);
u16 func_0203F1FC(const u8 *src, u32 len);
void func_020862F0(void *p, u32 n);
void func_02178E28(void *p, u32 n);
int func_0217771C(u8 *obj);
void func_02082D44(void *d, void *s, u32 n);
extern void func_02177704(void);
int func_02177AA8(void);
u32 func_020056EC(u32 n);
int func_021773E0(u8 *p);
void func_0217758C(u8 *p);
void func_02177560(void);
/* Evidence: NET_WHPIPE_SendData truncates its second argument to u16 at the tail call; the extern reflects that caller width. */
int NET_WHPIPE_IsStateScanning(void);
int NET_WHPIPE_SendData(int a, unsigned int b, int c);
unsigned int NET_WHPIPE_GetConnectBitmap(void);
int NET_WHPIPE_GetOwnAid(void);
void NET_WHPIPE_TaskConnectParent(WhPipeWork *work);
void NET_WHPIPE_TaskStartParent(WhPipeWork *work);
int NET_WHPIPE_StartParent(int a);
void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len);
void NET_WHPIPE_TaskConnectChild(WhPipeWork *work);
int NET_WHPIPE_StartChild(u32 a, u8 *b, u32 c, void (*d)(void));
void NET_WHPIPE_TaskFinishEnd(WhPipeWork *work);
int NET_WHPIPE_RequestEnd(int a);
int NET_WHPIPE_AcceptChild(void);
int NET_WHPIPE_RejectChild(void);
/* Evidence: func_02179328 stores its argument unchanged; the caller passes a function pointer. */
void NET_WHPIPE_SetAcceptChild(int a);
void NET_WHPIPE_TaskParentSearchWait(WhPipeWork *work);
void NET_WHPIPE_TaskParentSearchStart(WhPipeWork *work);
void NET_WHPIPE_TaskChildScanWait(WhPipeWork *work);
void NET_WHPIPE_TaskChildScanStart(WhPipeWork *work);
int NET_WHPIPE_StartAutoSearch(void);
void NET_WHPIPE_OnChildDisconnected(void);
/* Leaf called from WIH_DWC_PollStatus at +005C; byte-identical to func_02177B80: read g_pWhPipeWork, test the per-slot flag, return the slot's state byte, or 0. */
u8 NET_WHPIPE_GetEntryKind(u8 i);
/* Leaf called from ov010 DELIVERY_BEACON_StepCollectPieces. */
void NET_WHPIPE_SelectEntry(u32 i);
void NET_WHPIPE_StartJoinLock(int a);
void NET_WHPIPE_SetBeaconStatus(u8 value);
/* Leaf called from ov122 func_021D4B74; two stores into the pipe work block. */
void NET_WHPIPE_SetNotifyCallback(u32 callback, u32 value);
/* The bssid argument is const: that lets the ldrh of b[1] schedule above the strh of b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md). */
int DWCi_MOV_WH_ChildConnectAuto(u32 a, const u16 *b, u32 c);
int DWCi_MOV_WH_StartScan(u32 a, u16 *b, u32 c);
void WIH_SetScanTarget(u16 value, void *src);
int DWCi_MOV_WH_EndScan(void);
u16 func_02178E38(void);
int func_02178E4C(void);
int func_02178E84(void);
u16 func_02179024(void);
void WIH_FreeWork(void);
BOOL func_02179288(int mode, u16 tgid, int channel, u16 maxEntry);
void func_02179328(void *v);
void DWCi_MOV_WH_SetReceiver(void *cb);
/* Guard wrapper: forwards to DWCi_MOV_WH_StateInSetMPData when WIH_GetOwnAid is nonzero or one of bits 1-7 of func_02178E38 is set, else returns 0. */
BOOL DWCi_MOV_WH_SendData(int a, u16 b, int c);
/* The DWC copy of the NitroSDK demo wh.c WH_Finalize (DWCi_MOV_WH_*), returning BOOL. */
BOOL func_02179498(void);
int func_02179570(void (*cb)(int));
unsigned short WIH_GetOwnAid(void);
void WIH_SetJudgeScanFunc(unsigned v);
/* When the state word of the WH work block is 4 or 5, forwards to the arm9 function at 0x02090CD4 (WM_SetGameInfo shape) with (0, a, b, c, d, 1), the halfword arguments truncated. */
void WIH_SetBeaconGameInfo(int a, int b, int c, int d);
extern WhPipeWork *g_pWhPipeWork;
extern u16 g_ParentConnectModes[2];
extern u16 g_ChildConnectModes[2];
extern u8 g_SearchChannels[3];

/*
 * Task states of the wireless pipe: func_0217727C stores the next task
 * function into work->task, the main loop calls it once per frame.  The
 * WH system states used below are the NitroSDK wh.c ones: 0 stop, 1 idle,
 * 2 scanning, 3 busy, 4 connected, 5 data sharing, 7 measure channel,
 * 9 error.
 */

/*
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 */
int NET_WHPIPE_IsStateScanning(void) { if (func_02178E4C() == 2) return 1; return 0; }

int NET_WHPIPE_SendData(int data, unsigned int size, int callbackArg) { return DWCi_MOV_WH_SendData(data, size, callbackArg); }

unsigned int NET_WHPIPE_GetConnectBitmap(void) { return func_02178E38(); }

int NET_WHPIPE_GetOwnAid(void) { return WIH_GetOwnAid(); }

void NET_WHPIPE_TaskConnectParent(WhPipeWork *work)
{
    u16 connectModeTable[2];
    WhPipeNetInit *net;
    int channel;

    int state = func_02178E4C();

    connectModeTable[0] = g_ParentConnectModes[0];
    connectModeTable[1] = g_ParentConnectModes[1];
    if (state == 7) {
        net = GFL_NET_GetInitParam();
        work->beaconStatus = 0;
        work->entryListChanged = 0;
        work->scanning = 0;
        work->running = 0;
        channel = func_02179024();
        if (work->channel == 0xFF)
            work->channel = channel;
        else
            channel = work->channel;
        if (net->bRenewTgid != 0)
            work->tgid = func_0208F1B4();
        func_0217778C();
        func_02179288(connectModeTable[net->bMPMode], work->tgid, channel, net->maxConnectNum - 1);
        func_0217727C(g_pWhPipeWork, 0);
    }
}

void NET_WHPIPE_TaskStartParent(WhPipeWork *work) { if (func_02178E4C() == 1 && func_02178E84() != 0) func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskConnectParent); }

int NET_WHPIPE_StartParent(int autoChannel)
{
    WhPipeWork *work = g_pWhPipeWork;
    if (work->task != 0)
        return 0;
    if (autoChannel != 0)
        work->channel = 0xff;
    DWCi_MOV_WH_SetReceiver(func_021775AC);
    g_pWhPipeWork->running = 1;
    func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskStartParent);
    return 1;
}

void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len)
{
    WhPipeWork *work = g_pWhPipeWork;
    WhPipeNetInit *net = GFL_NET_GetInitParam();
    if (work != 0 && net != 0) {
        ((WhPipeBeacon *)buf)->checksum = func_0203F1FC(buf + 2, len - 2);
        func_020862F0(buf, len);
        if (func_02178E4C() == 1) {
            func_02178E28(buf, (u16)len);
            return;
        }
        WIH_SetBeaconGameInfo((int)buf, len, net->ggid, work->tgid);
    }
}

void NET_WHPIPE_TaskConnectChild(WhPipeWork *work)
{
    WhPipeNetInit *net = GFL_NET_GetInitParam();
    u16 connectModeTable[2];
    connectModeTable[0] = g_ChildConnectModes[0];
    connectModeTable[1] = g_ChildConnectModes[1];
    if (func_02178E4C() == 1 || func_02178E4C() == 2) {
        DWCi_MOV_WH_ChildConnectAuto(connectModeTable[net->bMPMode], (const u16 *)g_pWhPipeWork->targetBssid, 0);
        WIH_SetJudgeScanFunc((unsigned int)func_0217771C);
        DWCi_MOV_WH_SetReceiver(func_021775AC);
        g_pWhPipeWork->running = 1;
        func_0217727C(g_pWhPipeWork, 0);
    }
}

int NET_WHPIPE_StartChild(u32 unused, u8 *bssid, u32 entryIndex, void (*onConnected)(void))
{
    GFL_NET_GetInitParam();
    if (g_pWhPipeWork->task != 0)
        return 0;
    if (func_02178E4C() == 2) {
        g_pWhPipeWork->scanning = 0;
        DWCi_MOV_WH_EndScan();
    }
    func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskConnectChild);
    if (bssid != 0)
        func_02082D44(bssid, g_pWhPipeWork->targetBssid, 6);
    else
        func_02082D44(g_pWhPipeWork->entry[entryIndex].bssid, g_pWhPipeWork->targetBssid, 6);
    g_pWhPipeWork->onConnected = onConnected;
    return 1;
}

void NET_WHPIPE_TaskFinishEnd(WhPipeWork *work) { if (func_02178E4C() == 0) { WIH_FreeWork(); func_02177704(); } }

int NET_WHPIPE_RequestEnd(int endCallback) { if (func_02179570((void (*)(int))endCallback) != 0) { func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskFinishEnd); return 1; } return 0; }

int NET_WHPIPE_AcceptChild(void) { return 1; }

int NET_WHPIPE_RejectChild(void) { return 0; }

/*
 * evidence: func_02179328 stores its argument unchanged; the caller passes a function pointer.
 */
void NET_WHPIPE_SetAcceptChild(int acceptChild) { if (acceptChild != 0) func_02179328(NET_WHPIPE_AcceptChild); else func_02179328(NET_WHPIPE_RejectChild); }

void NET_WHPIPE_TaskParentSearchWait(WhPipeWork *work)
{
    if (g_pWhPipeWork->timerPaused == 0) {
        if (work->searchTimer != 0)
            work->searchTimer--;
        if (work->searchTimer == 0) {
            if (func_02179498() != 0)
                func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskChildScanStart);
        }
    }
}

void NET_WHPIPE_TaskParentSearchStart(WhPipeWork *work)
{
    u8 channelTable[3];
    if (func_02177AA8() != 0) {
        channelTable[0] = g_SearchChannels[0];
        channelTable[1] = g_SearchChannels[1];
        channelTable[2] = g_SearchChannels[2];
        work->searchChannelIndex = func_020056EC(3);
        if (work->searchChannelIndex >= 3)
            work->searchChannelIndex = 0;
        func_0217778C();
        if (func_02179288(0, work->tgid, channelTable[work->searchChannelIndex], 1) != 0) {
            work->searchTimer = func_020056EC(0x98) + 0x3C;
            func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskParentSearchWait);
        }
    }
}

void NET_WHPIPE_TaskChildScanWait(WhPipeWork *work) { work->searchTimer--; if (work->searchTimer == 0) { DWCi_MOV_WH_EndScan(); func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskParentSearchStart); } }

void NET_WHPIPE_TaskChildScanStart(WhPipeWork *work)
{
    if (func_02178E4C() == 1) {
        if (DWCi_MOV_WH_StartScan((u32)func_021773E0, 0, 0) != 0) {
            work->searchTimer = func_020056EC(0x28) + 0x3C;
            func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskChildScanWait);
        }
    }
}

int NET_WHPIPE_StartAutoSearch(void)
{
    WhPipeWork *work = g_pWhPipeWork;
    if (work == 0)
        return 0;
    NET_WHPIPE_StartJoinLock(0);
    func_0217758C((u8 *)work);
    func_02177560();
    DWCi_MOV_WH_SetReceiver(func_021775AC);
    work->running = 1;
    func_0217727C(g_pWhPipeWork, NET_WHPIPE_TaskChildScanStart);
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
        func_0217778C();
    }
}

void NET_WHPIPE_SetNotifyCallback(u32 callback, u32 value)
{
    if (g_pWhPipeWork) {
        g_pWhPipeWork->notifyFn = (void *)callback;
        g_pWhPipeWork->notifyArg = value;
    }
}
