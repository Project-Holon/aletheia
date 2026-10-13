/*
 * file:     net.c
 * unit:     yes
 * function: GFL_NET_SetupHeaps, GFL_NET_StartSession, GFL_NET_GetRunState, GFL_NET_IsSessionNull, GFL_NET_EndSession, GFL_NET_Exit, GFL_NET_ClearExitFlag, GFL_NET_GetScanResult, GFL_NET_GetScanResultMac, GFL_NET_Main, GFL_NET_RequestDisconnect, GFL_NET_ConnectMacAddressParent, GFL_NET_ConnectMacAddressChild, GFL_NET_BeaconScanStart, GFL_NET_StartByNetType, GFL_NET_StartChangeoverEx, GFL_NET_SetGameKindOverride, GFL_NET_IRC_WIRELESS_GetMacAddress, GFL_NET_IRC_WIRELESS_SetSessionParam, GFL_NET_IRC_WIRELESS_Exit, GFL_NET_StartChangeoverChild, GFL_NET_EndDeviceWrapper, GFL_NET_StartChangeoverParent, GFL_NET_SetDeviceModeIfRunning, GFL_NET_SetChangeoverModeWrapper, GFL_NET_IRC_WIRELESS_Step, GFL_NET_IRC_WIRELESS_SetRetryRequest, GFL_NET_IRC_WIRELESS_GetRetryCount, GFL_NET_SetLinkTimeout, GFL_NET_GetHandleNetID, GFL_NET_GetNegotiationNum, GFL_NET_IsConnectMember, GFL_NET_NotifyUserEvent, GFL_NET_IsIdle, GFL_NET_SetTimeout, GFL_NET_IsNetTypeBeacon, GFL_NET_IsNetTypeWifi, GFL_NET_RestartByNetType, GFL_NET_RestartWithDefaultTimeout, GFL_NET_IsParentAid, GFL_NET_IsHandleReady, GFL_NET_SendToHandle, GFL_NET_SendData, GFL_NET_SendDataMask, GFL_NET_ResetSendQueue, GFL_NET_IsSendQueueEntryOfHandle, GFL_NET_StartTimingSync, GFL_NET_CheckTimingSync, GFL_NET_SetGameKind, GFL_NET_GetGameKind, GFL_NET_GetWifiUserData, GFL_NET_GetFriendList, GFL_NET_GetFriendListNum, GFL_NET_SetWaitMode, GFL_NET_GetUserArg, GFL_NET_SetUserArg, GFL_NET_GetMaxConnectNum, GFL_NET_GetChildSendSize, GFL_NET_GetParentSendSize, GFL_NET_CallDeviceReadyFunc, GFL_NET_CallErrorStateFunc, GFL_NET_CallStateChangeFunc, GFL_NET_GetSession, GFL_NET_GetInitParam, GFL_NET_SetAutoExit, GFL_NET_SetLoginOption, GFL_NET_AllocAligned, GFL_NET_FreeAligned, GFL_NET_SetIrcParams, GFL_NET_GetIrcParams, GFL_NET_CopyInitParam, GFL_NET_ClearBeaconCallbacks, GFL_NET_CheckError, GFL_NET_RestartWithTimeout, GFL_NET_RestartNoTimeout, GFL_NET_SetErrorCheckEnabled, GFL_NET_IRC_WIRELESS_Create, GFL_NET_IRC_WIRELESS_Destroy, GFL_NET_IRC_WIRELESS_DestroyIfIdle, GFL_NET_IRC_WIRELESS_IsActive, GFL_NET_IRC_WIRELESS_SetSessionParamValue, GFL_NET_IRC_WIRELESS_SetCallbacks, GFL_NET_IRC_WIRELESS_AddMacAddress, GFL_NET_IRC_WIRELESS_CopyMacAddress, GFL_NET_IRC_WIRELESS_OnSyncReady, GFL_NET_IRC_WIRELESS_OnConnectEnd, GFL_NET_IRC_WIRELESS_SetState, GFL_NET_IRC_WIRELESS_Main, GFL_NET_IRC_WIRELESS_GetBeaconData, GFL_NET_IRC_WIRELESS_GetBeaconCompare, GFL_NET_IRC_WIRELESS_AddMacList, GFL_NET_IRC_WIRELESS_RetryStep, GFL_NET_IRC_WIRELESS_RequestRetry, GFL_NET_IRC_WIRELESS_GetRetryCountValue, GFL_NET_IRC_WIRELESS_SetGameKindOverride
 * address:  0x0203CB34
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x0203CB34 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02034714  0x02034714  arm
 *   func_020307B0   0x020307B0  arm
 *   GFL_NET_SYSTEM_GetCurrentAid   0x02039338  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SYSTEM_IsSendEnable  0x02039594  arm
 *   GFL_NET_HANDLE_GetNetHandle   0x0203996C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02034F84  0x02034F84  arm
 *   gGFLNetMain     0x021469E0  data
 *   sNetFileName  0x020A7CA0  data
 *   str_020A7CA8   0x020A7CA8  data
 *   str_020A7CB8   0x020A7CB8  data
 *   str_020A7CE8   0x020A7CE8  data
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   func_0200F17C  0x0200F17C  thumb
 *   func_020306F0  0x020306F0  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_0200F234  0x0200F234  thumb
 *   GFL_NET_LOWER_DATA_MainSend 0x0203EA9C  arm
 *   FLASH_ACCESS_GetBusyFlag  0x020338F8  arm
 *   g_020A7CEC     0x020A7CEC  data
 *   GFL_NET_HANDLE_IsTimingSync  0x02039CA0  arm
 *   file_020A7CF8  0x020A7CF8  data
 *   file_020A7D2C  0x020A7D2C  data
 *   gNetIrcWirelessLink     0x021469F0  data
 *   sNetIrcWirelessFileName     0x020A7D34  data
 *   str_020A7D48  0x020A7D48  data
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   str_020A7D4C  0x020A7D4C  data
 *   s_020A7D68      0x020A7D68  data
 *   GFL_NET_WM_ICON_EasyStart 0x02037010 arm
 *   GFL_NET_WM_ICON_EasyEnd 0x020370C8 arm
 *   GFL_NET_WM_ICON_EasySetScreen 0x02037118 arm
 *   GFL_NET_WM_ICON_EasyMain 0x02037154 arm
 *   GFL_NET_WM_ICON_SetDefaultPos 0x020371AC arm
 *   GFL_NET_SYSTEM_SetDeviceMode 0x02037A44 arm
 *   GFL_NET_SYSTEM_Main 0x02037C10 arm
 *   GFL_NET_SYSTEM_SetSendQueue 0x02038C18 arm
 *   GFL_NET_SYSTEM_CheckError 0x02039414 arm
 *   GFL_NET_SYSTEM_IsSendQueueEntry 0x02039468 arm
 *   GFL_NET_SYSTEM_IsSendQueueEmpty 0x020394C0 arm
 *   GFL_NET_SYSTEM_SetWaitMode 0x020394F0 arm
 *   GFL_NET_HANDLE_GetNetHandleID 0x020395EC arm
 *   GFL_NET_HANDLE_InitWork 0x02039834 arm
 *   GFL_NET_HANDLE_ExitWork 0x020398B4 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_StartTimingSync 0x02039C3C arm
 *   GFL_NET_HANDLE_Main 0x02039D94 arm
 *   GFL_NET_HANDLE_SetAllTimingValue 0x0203A458 arm
 *   GFL_NET_COMMAND_Init 0x0203A494 arm
 *   GFL_NET_STATE_DeviceInitialize 0x0203AFCC arm
 *   GFL_NET_STATE_ConnectMacAddress 0x0203B0C4 arm
 *   GFL_NET_STATE_BeaconScan 0x0203B1B0 arm
 *   GFL_NET_STATE_Main 0x0203B1D8 arm
 *   GFL_NET_STATE_InitParent 0x0203B2D0 arm
 *   GFL_NET_STATE_StartChangeover 0x0203BA98 arm
 *   GFL_NET_STATE_SetChangeoverMode 0x0203BD30 arm
 *   GFL_NET_STATE_Exit 0x0203BF9C arm
 *   GFL_NET_STATE_ClearExitFlag 0x0203BFF0 arm
 *   GFL_NET_STATE_EndDevice 0x0203C010 arm
 *   GFL_NET_STATE_WifiEnterLoginDefault 0x0203C3B4 arm
 *   GFL_NET_STATE_WifiLogout 0x0203C774 arm
 *   GFL_NET_STATE_SetAutoExit 0x0203C8E8 arm
 *   GFL_NET_STATE_SetLoginOption 0x0203C900 arm
 *   GFL_NET_STATE_SetErrorMode 0x0203C938 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef signed int     s32;

#include "net_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *block);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int    GFL_NET_SYSTEM_IsSendEnable(void);
extern GFLNetHandle *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern void func_02082D44(const void *src, void *dst, int n);
extern void func_02087C6C(void *dst);
extern s32 func_0203EFC8(const u8 *lhs, const u8 *rhs, u32 size);
extern void func_02034F84(u32 flag);
extern void GFL_HEAP_CreateChildHeap(u32 parentHeapId, u32 heapId, u32 size);
extern struct GFLNetModeOps *func_0200F17C(u32 netType);
extern void func_0200F234(u32 netType);
extern void func_020306F0(u32 heapId);
extern void func_02034FB8(u32 flag);
extern void GFL_NET_LOWER_DATA_MainSend(void);
extern u32  FLASH_ACCESS_GetBusyFlag(void);
extern void GFL_NET_HANDLE_IsTimingSync(void);
extern void func_02039C68(GFLNetHandle *handle, u32 timingNo, u32 option);
extern u32 func_02039CB4(GFLNetHandle *handle, u32 timingNo, u32 option);
void GFL_NET_WM_ICON_EasyStart(u32 timeoutFrames, u32 timeoutExtra, u32 isWifi, u32 heapId);
void GFL_NET_WM_ICON_EasyEnd(void);
void GFL_NET_WM_ICON_EasySetScreen(u32 restartParamA, u32 restartParamB);
void GFL_NET_WM_ICON_EasyMain(void);
void GFL_NET_WM_ICON_SetDefaultPos(unsigned short timeoutFrames, unsigned short timeoutExtra);
void GFL_NET_SYSTEM_SetDeviceMode(int mode);
int GFL_NET_SYSTEM_Main(void);
int GFL_NET_SYSTEM_SetSendQueue(u32 command, const void *data, u32 size, u32 sendFlags, u32 aid, u32 targetMask, u32 queueMode);
u32 GFL_NET_SYSTEM_CheckError(void);
int GFL_NET_SYSTEM_IsSendQueueEntry(u32 command, u32 aid);
int GFL_NET_SYSTEM_IsSendQueueEmpty(void);
void GFL_NET_SYSTEM_SetWaitMode(u32 waitMode);
int GFL_NET_HANDLE_GetNetHandleID(GFLNetHandle *handle);
void GFL_NET_HANDLE_InitWork(GFLNetSession *unused);
void GFL_NET_HANDLE_ExitWork(GFLNetSession *unused);
u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *handle);
int GFL_NET_HANDLE_GetNegotiationNum(void);
int GFL_NET_HANDLE_CheckNegotiation(void);
void GFL_NET_HANDLE_StartTimingSync(GFLNetHandle *handle, u16 tag);
void GFL_NET_HANDLE_Main(void);
void GFL_NET_HANDLE_SetAllTimingValue(u8 *handle, u32 gameKind);
void GFL_NET_COMMAND_Init(u32 gameKindShifted, u32 recvFuncTable, u32 recvFuncTableNum, u32 userArg, u32 heapId);
void GFL_NET_STATE_DeviceInitialize(u32 heapId, u32 transportArg);
void GFL_NET_STATE_ConnectMacAddress(int context, int flag);
void GFL_NET_STATE_BeaconScan(void);
u32 GFL_NET_STATE_Main(void);
void GFL_NET_STATE_InitParent(u32 heapId);
void GFL_NET_STATE_StartChangeover(u16 heapId, u32 changeoverParam, u8 mode);
void GFL_NET_STATE_SetChangeoverMode(u32 mode, u32 flags, u8 *macAddr);
void GFL_NET_STATE_Exit(u32 handler);
void GFL_NET_STATE_ClearExitFlag(void);
void GFL_NET_STATE_EndDevice(void);
void GFL_NET_STATE_WifiEnterLoginDefault(void);
void GFL_NET_STATE_WifiLogout(u32 handler);
void GFL_NET_STATE_SetAutoExit(u8 autoExit);
void GFL_NET_STATE_SetLoginOption(u8 loginOption);
u32 GFL_NET_STATE_SetErrorMode(u8 mode);
void GFL_NET_SetupHeaps(u32 parentHeapId, u32 zero, u32 oldBaseHeapId, u32 newBaseHeapId);
void GFL_NET_StartSession(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg);
int GFL_NET_GetRunState(void);
int GFL_NET_IsSessionNull(void);
void GFL_NET_EndSession(void);
int GFL_NET_Exit(void (*exitCallback)(u32));
void GFL_NET_ClearExitFlag(void);
u32 GFL_NET_GetScanResult(u32 index);
void *GFL_NET_GetScanResultMac(u32 index);
u32 GFL_NET_Main(void);
void GFL_NET_RequestDisconnect(void);
void GFL_NET_ConnectMacAddressParent(void *context);
void GFL_NET_ConnectMacAddressChild(void *context);
void GFL_NET_BeaconScanStart(void);
void GFL_NET_StartByNetType(void);
void GFL_NET_StartChangeoverEx(u32 onFinished, u32 onResult, u32 onReady);
void GFL_NET_SetGameKindOverride(int gameKind);
void GFL_NET_IRC_WIRELESS_GetMacAddress(void *dst, u32 slot);
void GFL_NET_IRC_WIRELESS_SetSessionParam(unsigned int value);
void GFL_NET_IRC_WIRELESS_Exit(void);
void GFL_NET_StartChangeoverChild(u32 changeoverParam);
void GFL_NET_EndDeviceWrapper(int unused);
void GFL_NET_StartChangeoverParent(u32 changeoverParam);
void GFL_NET_SetDeviceModeIfRunning(int mode);
void GFL_NET_SetChangeoverModeWrapper(u32 mode, u32 flags, u8 *macAddr);
u32 GFL_NET_IRC_WIRELESS_Step(void);
void GFL_NET_IRC_WIRELESS_SetRetryRequest(int retryRequest);
int GFL_NET_IRC_WIRELESS_GetRetryCount(void);
void GFL_NET_SetLinkTimeout(u32 frames);
u32 GFL_NET_GetHandleNetID(GFLNetHandle *handle);
int GFL_NET_GetNegotiationNum(void);
u32 GFL_NET_IsConnectMember(u32 index);
void GFL_NET_NotifyUserEvent(u32 unusedArg, void *eventArg);
u32 GFL_NET_IsIdle(void);
void GFL_NET_SetTimeout(u16 timeoutFrames, u16 timeoutExtra);
u32 GFL_NET_IsNetTypeBeacon(void);
u32 GFL_NET_IsNetTypeWifi(void);
void GFL_NET_RestartByNetType(void);
void GFL_NET_RestartWithDefaultTimeout(u32 restartParamA, u32 restartParamB);
u32 GFL_NET_IsParentAid(void);
u32 GFL_NET_IsHandleReady(GFLNetHandle *handle);
int GFL_NET_SendToHandle(GFLNetHandle *handle, u32 command, u32 size, const void *data);
u32 GFL_NET_SendData(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
u32 GFL_NET_SendDataMask(GFLNetHandle *handle, u32 targetMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
void GFL_NET_ResetSendQueue(void);
void GFL_NET_IsSendQueueEntryOfHandle(GFLNetHandle *handle, u32 command);
void GFL_NET_StartTimingSync(GFLNetHandle *handle, u16 tag);
void GFL_NET_CheckTimingSync(void);
void GFL_NET_SetGameKind(int gameKind, int unused);
u32 GFL_NET_GetGameKind(void);
u32 GFL_NET_GetWifiUserData(void);
u32 GFL_NET_GetFriendList(void);
u32 GFL_NET_GetFriendListNum(void);
void GFL_NET_SetWaitMode(u32 waitMode);
u32 GFL_NET_GetUserArg(void);
void GFL_NET_SetUserArg(u32 userArg);
u32 GFL_NET_GetMaxConnectNum(void);
u32 GFL_NET_GetChildSendSize(void);
u32 GFL_NET_GetParentSendSize(void);
void GFL_NET_CallDeviceReadyFunc(void);
void GFL_NET_CallErrorStateFunc(u32 errorCode);
void GFL_NET_CallStateChangeFunc(u32 newState);
GFLNetSession *GFL_NET_GetSession(void);
GFLNetSession *GFL_NET_GetInitParam(void);
void GFL_NET_SetAutoExit(u8 autoExit);
void GFL_NET_SetLoginOption(u8 loginOption);
void *GFL_NET_AllocAligned(u32 heapId, u32 size, const char *fileName, u16 line);
void GFL_NET_FreeAligned(void *block);
void GFL_NET_SetIrcParams(u32 paramA, u32 paramB);
void GFL_NET_GetIrcParams(u32 *outParamA, u32 *outParamB);
void GFL_NET_CopyInitParam(void *dst);
void GFL_NET_ClearBeaconCallbacks(void);
u32 GFL_NET_CheckError(void);
void GFL_NET_RestartWithTimeout(u32 timeoutFrames, u32 timeoutExtra);
void GFL_NET_RestartNoTimeout(void);
void GFL_NET_SetErrorCheckEnabled(u32 enable);
GFLNetInitializeStruct *GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, u32 callbackArg);
void GFL_NET_IRC_WIRELESS_Destroy(void);
void GFL_NET_IRC_WIRELESS_DestroyIfIdle(void);
int GFL_NET_IRC_WIRELESS_IsActive(void);
void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value);
void *GFL_NET_IRC_WIRELESS_SetCallbacks(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32));
void GFL_NET_IRC_WIRELESS_AddMacAddress(const u8 *mac);
void GFL_NET_IRC_WIRELESS_CopyMacAddress(void *dst, u32 slot);
void GFL_NET_IRC_WIRELESS_OnSyncReady(void);
void GFL_NET_IRC_WIRELESS_OnConnectEnd(u32 userArg);
void GFL_NET_IRC_WIRELESS_SetState(NetIrcWirelessLink *link, int state);
void GFL_NET_IRC_WIRELESS_Main(void);
void *GFL_NET_IRC_WIRELESS_GetBeaconData(void *beaconArg);
void *GFL_NET_IRC_WIRELESS_GetBeaconCompare(void *beaconArg);
void GFL_NET_IRC_WIRELESS_AddMacList(u32 unusedA, u32 unusedB, struct NetMacList *macList);
u32 GFL_NET_IRC_WIRELESS_RetryStep(void);
void GFL_NET_IRC_WIRELESS_RequestRetry(int netId);
int GFL_NET_IRC_WIRELESS_GetRetryCountValue(void);
void GFL_NET_IRC_WIRELESS_SetGameKindOverride(int gameKind);
extern const char sNetFileName[];
extern const char str_020A7CA8[];
extern const char str_020A7CB8[];
extern const char str_020A7CE8[];
extern GFLNetMain gGFLNetMain;
extern char g_020A7CEC[];
extern const char file_020A7CF8[];
extern const char file_020A7D2C[];
extern NetIrcWirelessLink *gNetIrcWirelessLink;
extern const char sNetIrcWirelessFileName[];
extern const u8 str_020A7D48[];
extern const u8 str_020A7D4C[];
extern char s_020A7D68[];






















void GFL_NET_SetupHeaps(u32 parentHeapId, u32 zero, u32 oldBaseHeapId, u32 newBaseHeapId)
{
    GFLNetModeOps *ops = func_0200F17C(1);

    if (ops != 0)
        ops->initLibrary(parentHeapId, zero);

    func_0200F234(1);

    if (oldBaseHeapId != newBaseHeapId) {
        gGFLNetMain.baseHeapId = (u16)newBaseHeapId;
        GFL_HEAP_CreateChildHeap(oldBaseHeapId, newBaseHeapId, 0x9E80);
    }

    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
    GFL_NET_WM_ICON_EasyEnd();
}






















/*
 * Start one network session. Allocates the 0x354-byte session record on the
 * request's heap, publishes it in gGFLNetMain, looks up the mode operation
 * table for the net type and copies the 0x70-byte init block into the session.
 * Then dispatches on the net type: the wifi types (1, 2, 6) start the mode and
 * allocate the wifi heap, the beacon types (3, 4) check the child send size
 * (at most 0x80) and allocate the beacon heap, types 0 and 5 do nothing, and
 * any other value is an assert failure. Finally registers the receive table
 * and, for the non-beacon types, starts the timeout sequence.
 *
 * The beacon test is kept in a local (isBeacon); written inline it folds into
 * a range check and the code changes.
 */
void GFL_NET_StartSession(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg)
{
    GFLNetSession *session;
    u8 netType;
    u32 isWifi;

    if (gGFLNetMain.baseHeapId != 0)
        GFL_HEAP_CreateChildHeap(gGFLNetMain.baseHeapId, req->heapId, 0x7800);
    else
        GFL_HEAP_CreateChildHeap(req->parentHeapId, req->heapId, 0x7800);
    session = (GFLNetSession *)func_02030734(req->heapId, 0x354, 1, sNetFileName, 0x6a);
    gGFLNetMain.session = session;
    session->errorCheckEnabled = 1;
    session->ops = func_0200F17C(req->bNetType);
    if (session->ops == 0)
        func_02034714(sNetFileName, 0x6f, str_020A7CA8);
    if (req->bNetType == 4)
        req = (GFLNetInitializeStruct *)GFL_NET_IRC_WIRELESS_Create((const GFLNetInitializeStruct *)req, userArg);
    func_02082D44(req, session, 0x70);
    switch (req->bNetType) {
    case 1:
    case 2:
    case 6:
        session->ops->initLibrary(req->parentHeapId, 0);
        GFL_HEAP_CreateChildHeap(req->parentHeapId, (u16)(req->wifiHeapId | 0x8000), req->heapSize);
        break;
    case 3:
    case 4:
        if (req->childSendSize > 0x80)
            func_02034714(sNetFileName, 0x84, str_020A7CB8);
        if (gGFLNetMain.baseHeapId != 0)
            GFL_HEAP_CreateChildHeap(gGFLNetMain.baseHeapId, req->beaconHeapId, 0x1b00);
        else
            GFL_HEAP_CreateChildHeap(req->parentHeapId, req->beaconHeapId, 0x1b00);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(sNetFileName, 0x8e, str_020A7CE8);
        return;
    }
    session->userArg = userArg;
    GFL_NET_STATE_DeviceInitialize(req->heapId, transportArg);
    GFL_NET_HANDLE_InitWork(session);
    GFL_NET_COMMAND_Init(req->gameKind << 8, req->recvFuncTable, req->recvFuncTableNum, session->userArg, req->heapId);
    netType = req->bNetType;
    {
        int isBeacon = (netType == 3) || (netType == 4);
        if (isBeacon)
            return;
    }
    isWifi = 0;
    if ((u8)(netType + 0xff) <= 1)
        isWifi = 1;
    GFL_NET_WM_ICON_EasyStart(req->timeoutFrames, req->timeoutExtra, isWifi, req->heapId);
}






















/*
 * Return the run state of the current mode through its operation table, or 0
 * when there is no session.
 */
int GFL_NET_GetRunState(void)
{
    GFLNetSession *s = GFL_NET_GetSession();

    if (s == 0) {
        return 0;
    }

    return s->ops->isActive();
}
























int GFL_NET_IsSessionNull(void)
{
    return GFL_NET_GetSession() == 0;
}
























/*
 * Tear down the current session. Saves the three heap ids and the net type,
 * calls the optional exit callback and the connect-end callback, shuts down the
 * handle layer, frees the session record and clears the session pointer. Then
 * releases the heaps the net type had allocated: the wifi heap for types 1, 2
 * and 6, the beacon heap for types 3 and 4, nothing extra for types 0 and 5
 * (any other type is an assert failure). The base heap is released last.
 *
 * The switch has to use `default:` for the assert arm, not an explicit case 0,
 * or the jump table layout differs. The gGFLNetMain store goes through an
 * array-style access because the pointer-plus-offset form folds the offset
 * into the literal pool word.
 */
void GFL_NET_EndSession(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    void (*callback)(u32);
    u16 heapId;
    u16 wifiHeapId;
    u16 beaconHeapId;
    u8 netType;

    callback = session->exitCallback;
    heapId = session->init.heapId;
    wifiHeapId = session->init.wifiHeapId;
    beaconHeapId = session->init.beaconHeapId;
    netType = session->init.bNetType;

    if (callback != 0)
        callback(session->userArg);

    callback = session->init.connectEndFunc;
    if (callback != 0)
        callback(session->userArg);

    GFL_NET_HANDLE_ExitWork(session);
    func_0200F234(netType);
    func_020307B0(session);

    gGFLNetMain.session = 0;

    switch (netType) {
    case 1:
    case 2:
    case 6:
        func_020306F0(wifiHeapId);
        break;
    case 3:
    case 4:
        func_020306F0(beaconHeapId);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(sNetFileName, 0xEE, str_020A7CE8);
        return;
    }

    func_020306F0(heapId);
    func_02034FB8(4);
}
























/*
 * Request a session exit. Ticks the wireless link cleanup, then, if a session
 * exists, stores the caller's exit callback in it and installs the session
 * teardown routine (GFL_NET_EndSession) as the pending handler: through the
 * type-1 hook for wifi sessions and through the generic hook for all others.
 * Returns 1 when a session existed, otherwise 0.
 *
 * The `if (session != 0) { ... return 1; } return 0;` shape is required: the
 * early-return form shifts the code that follows. The net type byte is read
 * before the callback is stored.
 */
int GFL_NET_Exit(void (*exitCallback)(u32))
{
    GFLNetSession *session;

    session = GFL_NET_GetSession();
    GFL_NET_IRC_WIRELESS_DestroyIfIdle();
    if (session != 0) {
        u8 netType = session->init.bNetType;

        session->exitCallback = exitCallback;
        if (netType == 1) {
            GFL_NET_STATE_WifiLogout((u32)GFL_NET_EndSession);
        } else {
            GFL_NET_STATE_Exit((u32)GFL_NET_EndSession);
        }
        GFL_NET_WM_ICON_EasyEnd();
        return 1;
    }
    return 0;
}
























void GFL_NET_ClearExitFlag(void)
{
    GFL_NET_STATE_ClearExitFlag();
}
























/*
 * Return the scan result entry for index from the current mode, or 0 when
 * there is no session. Dispatches through the getScanResult slot of the mode
 * operation table; the table pointer itself is not checked.
 */
u32 GFL_NET_GetScanResult(u32 index)
{
    GFLNetSession *session;

    session = GFL_NET_GetSession();
    if (session == 0)
        return 0;
    return session->ops->getScanResult(index);
}
























/*
 * Return the scan result MAC for index through the getScanResultMac slot of
 * the mode operation table. The session must exist.
 */
void *GFL_NET_GetScanResultMac(u32 index)
{
    GFLNetSession *session;

    session = GFL_NET_GetSession();
    return session->ops->getScanResultMac(index);
}
























/*
 * Per-frame network update. Runs the wireless link state machine and the
 * state layer. Returns 1 when the state layer is busy or there is no session;
 * otherwise advances the handle layer, the send queue and the timing sync and
 * returns the handle layer's result.
 */
u32 GFL_NET_Main(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    GFL_NET_LOWER_DATA_MainSend();
    GFL_NET_IRC_WIRELESS_Main();
    if (GFL_NET_STATE_Main() != 0) {
        return 1;
    }
    if (session == 0) {
        return 1;
    }
    GFL_NET_WM_ICON_EasyMain();
    GFL_NET_HANDLE_Main();
    GFL_NET_SYSTEM_Main();
    return GFL_NET_SYSTEM_IsSendEnable();
}
























void GFL_NET_RequestDisconnect(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *initSession;

    if (GFL_NET_STATE_Main() != 0)
        return;
    if (session == 0 || session->ops == 0)
        return;

    initSession = GFL_NET_GetInitParam();
    switch (initSession->init.bNetType) {
    case 1:
    case 2:
        return;
    }

    session->ops->update(0);
}
























/*
 * Tail wrapper: connect to the parent at context (flag 1). Called from state
 * 10 of the wireless link state machine.
 */
void GFL_NET_ConnectMacAddressParent(void *context)
{
    GFL_NET_STATE_ConnectMacAddress((int)context, 1);
}
























/*
 * Tail wrapper: connect to the child at context (flag 0), the twin of
 * GFL_NET_ConnectMacAddressParent.
 */
void GFL_NET_ConnectMacAddressChild(void *context)
{
    GFL_NET_STATE_ConnectMacAddress((int)context, 0);
}
























/*
 * Tail wrapper: start the beacon scan. Called from state 10 of the wireless
 * link state machine.
 */
void GFL_NET_BeaconScanStart(void)
{
    GFL_NET_STATE_BeaconScan();
}
























void GFL_NET_StartByNetType(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    switch (session->init.bNetType) {
    case 1:
    case 2:
        GFL_NET_STATE_WifiEnterLoginDefault();
        return;
    case 0:
    case 5:
        GFL_NET_STATE_InitParent(session->init.heapId);
        return;
    default:
        return;
    }
}























/*
 * Start a changeover. When a wireless link exists, the three callbacks are
 * installed first and the handler returned by the callback setter replaces the
 * caller's finish callback. The result is handed to the state layer together
 * with the session's heap id and mode 1.
 */
void GFL_NET_StartChangeoverEx(u32 onFinished, u32 onResult, u32 onReady)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u32 handler = onFinished;

    if (GFL_NET_IRC_WIRELESS_IsActive() == 1)
        handler = (u32)GFL_NET_IRC_WIRELESS_SetCallbacks((void (*)(u32))onFinished, (void (*)(u32, int))onResult, (void (*)(u32))onReady);

    GFL_NET_STATE_StartChangeover(session->init.heapId, handler, 1);
}






















void GFL_NET_SetGameKindOverride(int gameKind)
{
    GFL_NET_IRC_WIRELESS_SetGameKindOverride(gameKind);
}






















void GFL_NET_IRC_WIRELESS_GetMacAddress(void *dst, u32 slot)
{
    GFL_NET_IRC_WIRELESS_CopyMacAddress(dst, slot);
}






















void GFL_NET_IRC_WIRELESS_SetSessionParam(unsigned int value)
{
    GFL_NET_IRC_WIRELESS_SetSessionParamValue(value);
}






















void GFL_NET_IRC_WIRELESS_Exit(void){ GFL_NET_IRC_WIRELESS_Destroy(); }























void GFL_NET_StartChangeoverChild(u32 changeoverParam)
{
    GFL_NET_STATE_StartChangeover(GFL_NET_GetSession()->init.heapId, changeoverParam, 1);
}





















void GFL_NET_EndDeviceWrapper(int unused)
{
    GFL_NET_GetSession();
    GFL_NET_STATE_EndDevice();
}



















void GFL_NET_StartChangeoverParent(u32 changeoverParam)
{
    GFL_NET_STATE_StartChangeover(GFL_NET_GetSession()->init.heapId, changeoverParam, 0);
}





















/*
 * Forward the mode to the state layer only when the session reports that the
 * connection is up (run state non-zero).
 */
void GFL_NET_SetDeviceModeIfRunning(int mode)
{
    if (GFL_NET_GetRunState() == 0)
        return;

    GFL_NET_SYSTEM_SetDeviceMode(mode);
}




















void GFL_NET_SetChangeoverModeWrapper(u32 mode, u32 flags, u8 *macAddr)
{
    GFL_NET_STATE_SetChangeoverMode(mode, flags, macAddr);
}




















u32 GFL_NET_IRC_WIRELESS_Step(void)
{
    return GFL_NET_IRC_WIRELESS_RetryStep();
}




















void GFL_NET_IRC_WIRELESS_SetRetryRequest(int retryRequest)
{
    GFL_NET_IRC_WIRELESS_RequestRetry(retryRequest);
}




















int GFL_NET_IRC_WIRELESS_GetRetryCount(void)
{
    return GFL_NET_IRC_WIRELESS_GetRetryCountValue();
}
























/*
 * Set the link timeout through the setLinkTimeout slot of the mode operation
 * table, when the table exists. The hook's result is dropped.
 */
void GFL_NET_SetLinkTimeout(u32 frames)
{
    GFLNetSession *session;
    GFLNetModeOps *ops;

    session = GFL_NET_GetSession();
    ops = session->ops;
    if (ops == 0)
        return;
    ops->setLinkTimeout(frames);
}
























/*
 * Forward to GFL_NET_HANDLE_GetNetHandleID and mask the result to a byte.  GFL_NET_HANDLE_GetNetHandleID is
 * called from GFL_NET_IsSendQueueEntryOfHandle (outside this range), which is what attests the
 * `bl` here as a real function rather than a wildcarded relocation.
 */
u32 GFL_NET_GetHandleNetID(GFLNetHandle *handle)
{
    return GFL_NET_HANDLE_GetNetHandleID(handle) & 0xff;
}























int GFL_NET_GetNegotiationNum(void)
{
    return GFL_NET_HANDLE_GetNegotiationNum();
}























/*
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with GFL_NET_HANDLE_GetNetHandle and ask GFL_NET_HANDLE_IsNegotiationDone about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 */
u32 GFL_NET_IsConnectMember(u32 index)
{
    if (GFL_NET_GetSession() == 0) {
        return 0;
    }
    return GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetNetHandle(index));
}






















void GFL_NET_NotifyUserEvent(u32 unusedArg, void *eventArg)
{
    void (*setAcceptConnection)(void *) = GFL_NET_GetSession()->ops->setAcceptConnection;

    if (setAcceptConnection == 0) {
        return;
    }
    setAcceptConnection(eventArg);
}






















/*
 * "Nothing running, or the +0x6c hook says idle".  The first test reads
 * gGFLNetMain.session straight out of the singleton (the same two
 * instructions GFL_NET_GetSession is made of), while the second goes through the
 * real call; that asymmetry is what says the first read is a file-local
 * access and not an inlined copy of the extern.
 */
u32 GFL_NET_IsIdle(void)
{
    if (gGFLNetMain.session == 0) {
        return 1;
    }
    return GFL_NET_GetSession()->ops->isActive() == 0;
}
























/*
 * Store a halfword pair into +0x5c/+0x5e of the network state block, if it
 * exists.  Both stores are predicated off the one null test, which is why
 * the two parameters have to survive the accessor call in r5/r4.
 */
void GFL_NET_SetTimeout(u16 timeoutFrames, u16 timeoutExtra)
{
    GFLNetSession *initSession = GFL_NET_GetInitParam();

    if (initSession != 0) {
        initSession->init.timeoutFrames = timeoutFrames;
        initSession->init.timeoutExtra = timeoutExtra;
    }
}
























/*
 * "State is 3 or 4" predicate on the +0x65 mode byte of the network
 * singleton.  The range test is written as one unsigned compare on the
 * biased byte, so the original spells `- 3` as `add r0, r0, #0xfd` with the
 * `and r0, r0, #0xff` that the u8 cast forces.
 */
u32 GFL_NET_IsNetTypeBeacon(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session != 0) {
        if ((u8)(session->init.bNetType + 0xfd) <= 1) {
            return 1;
        }
    }
    return 0;
}
























/*
 * Sibling of GFL_NET_IsNetTypeBeacon one range lower: "state is 1 or 2" on the +0x65
 * mode byte.  Same shape, `add r0, r0, #0xff` for the bias instead of
 * `#0xfd`.
 */
u32 GFL_NET_IsNetTypeWifi(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session != 0) {
        if ((u8)(session->init.bNetType + 0xff) <= 1) {
            return 1;
        }
    }
    return 0;
}
























/*
 * Restart the session by net type. Asserts (file "net.c", line 868) when the
 * state layer reports that it is busy. Otherwise, for a session that is not a
 * beacon type (3), restarts with the stored timeout pair, the wifi flag and
 * the session's heap id; with no session, or for beacon type, it only runs
 * the default restart.
 *
 * Both session accessors are called even though they read the same global
 * (GFL_NET_GetInitParam null-checks, GFL_NET_GetSession does not); both results
 * stay live and the first is used only for the net type test.
 */
void GFL_NET_RestartByNetType(void)
{
    GFLNetSession *initSession = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();

    if (FLASH_ACCESS_GetBusyFlag() == 1) {
        func_02034714(sNetFileName, 868, str_020A7CE8);
        return;
    }
    if (session != 0 && initSession->init.bNetType != 3) {
        u32 isWifi = 0;

        if ((u8)(session->init.bNetType + 0xff) <= 1) {
            isWifi = 1;
        }
        GFL_NET_WM_ICON_EasyStart(session->init.timeoutFrames, session->init.timeoutExtra, isWifi, session->init.heapId);
    } else {
        GFL_NET_WM_ICON_EasyEnd();
    }
}
























/*
 * Three-call sequence: stamp the (0xf0, 0) pair into the state block, run
 * the transfer at 0x02037118 with this function's own two arguments, then
 * kick the state machine at 0x0203D2CC.  Both arguments have to outlive the
 * first call, which is what spends r5/r4.
 */
void GFL_NET_RestartWithDefaultTimeout(u32 restartParamA, u32 restartParamB)
{
    GFL_NET_SetTimeout(0xf0, 0);
    GFL_NET_WM_ICON_EasySetScreen(restartParamA, restartParamB);
    GFL_NET_RestartByNetType();
}
























/*
 * Inverted forward: 1 when GFL_NET_SYSTEM_GetCurrentAid reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 */
u32 GFL_NET_IsParentAid(void)
{
    u32 isParent = 0;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        isParent = 1;
    }
    return isParent;
}
























/*
 * Leaf predicate on the +0x4a byte of an entry: "is this entry in state 5".
 * No relocation and no frame; the same three-instruction body appears
 * inlined inside GFL_NET_HANDLE_IsNegotiationDone.
 */
u32 GFL_NET_IsHandleReady(GFLNetHandle *handle)
{
    return handle->state == 5;
}























/*
 * Send a command with data to every member (target mask 0xff) through the
 * given handle. The leading session lookup is made for effect only.
 */
int GFL_NET_SendToHandle(GFLNetHandle *handle, u32 command, u32 size, const void *data)
{
    GFL_NET_GetInitParam();
    return GFL_NET_SYSTEM_SetSendQueue(command, data, size, 0, GFL_NET_HANDLE_GetNetHandleID(handle), 0xff, 0);
}























/*
 * Send a command to a handle. A sendId of 0xff targets every member; any
 * other id selects one member (ids of 7 or more are an assert failure).
 * Returns 0 without sending when the handle is not in state 5 and the command
 * is 0x11 or higher, or when skipIfQueued is set and the command is already
 * in the send queue.
 */
u32 GFL_NET_SendData(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode)
{
    u8 targetMask;

    GFL_NET_GetInitParam();
    targetMask = 0xff;
    if (GFL_NET_IsHandleReady(handle) == 0 && command >= 0x11) {
        return 0;
    }
    if (skipIfQueued != 0 && GFL_NET_SYSTEM_IsSendQueueEntry(command, GFL_NET_HANDLE_GetNetHandleID(handle)) != 0) {
        return 0;
    }
    if (sendId != 0xff) {
        if (sendId >= 7) {
            func_02034714(sNetFileName, 1019, g_020A7CEC);
        }
        targetMask = 1 << sendId;
    }
    return GFL_NET_SYSTEM_SetSendQueue(command, data, size, sendFlags, GFL_NET_HANDLE_GetNetHandleID(handle), targetMask, queueMode);
}























/*
 * The explicit-mask sibling of GFL_NET_SendData: identical guards, but the
 * destination bitmask arrives as the second parameter instead of being
 * derived from a send id, so there is no assert and no `lsl`, and the mask
 * stays in r6 across the whole body.  The two stack arguments that live
 * next to each other go out as one `stmib`.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D578 because the
 * follower at 0x0203D56C has no label.  It is not a byte difference; the
 * follower is a twelve-byte ARM long-branch veneer (ldr ip, [pc]; bx ip;
 * .word 0x020394C0) that saves no lr and so is invisible to disasm.py.  It
 * wants seeding into layout/function_starts.txt, which is the integrator's
 * file.
 */
u32 GFL_NET_SendDataMask(GFLNetHandle *handle, u32 targetMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued,
                  u32 queueMode)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_IsHandleReady(handle) == 0 && command >= 0x11) {
        return 0;
    }
    if (skipIfQueued != 0 && GFL_NET_SYSTEM_IsSendQueueEntry(command, GFL_NET_HANDLE_GetNetHandleID(handle)) != 0) {
        return 0;
    }
    return GFL_NET_SYSTEM_SetSendQueue(command, data, size, sendFlags, GFL_NET_HANDLE_GetNetHandleID(handle), targetMask, queueMode);
}






















void GFL_NET_ResetSendQueue(void)
{
    GFL_NET_SYSTEM_IsSendQueueEmpty();
}























/*
 * Forwards the first argument through GFL_NET_HANDLE_GetNetHandleID and passes the result
 * with the second argument to GFL_NET_SYSTEM_IsSendQueueEntry.
 */
void GFL_NET_IsSendQueueEntryOfHandle(GFLNetHandle *handle, u32 command)
{
    u32 aid = GFL_NET_HANDLE_GetNetHandleID(handle);

    GFL_NET_SYSTEM_IsSendQueueEntry(command, aid);
}




















void GFL_NET_StartTimingSync(GFLNetHandle *handle, u16 tag)
{
    GFL_NET_HANDLE_StartTimingSync(handle, tag);
}




















void GFL_NET_CheckTimingSync(void)
{
    GFL_NET_HANDLE_IsTimingSync();
}





















/*
 * Set the session's game kind byte and update the handle layer's all-handle
 * slot (0xff) with it.
 */
void GFL_NET_SetGameKind(int gameKind, int unused)
{
    GFLNetSession *initSession;

    GFL_NET_GetSession();
    initSession = GFL_NET_GetInitParam();
    initSession->init.gameKind = (u8)gameKind;
    GFL_NET_HANDLE_SetAllTimingValue((u8 *)GFL_NET_HANDLE_GetNetHandle(0xff), gameKind);
}






















/*
 * Returns the byte at +0x67 of the net context, or 0 when there is none.
 */
u32 GFL_NET_GetGameKind(void)
{
    GFLNetSession *initSession = GFL_NET_GetInitParam();

    return initSession != 0 ? initSession->init.gameKind : 0;
}






















/*
 * Calls the net context's +0x44 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 */
u32 GFL_NET_GetWifiUserData(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->init.getWifiUserDataFunc == 0) {
        return 0;
    }
    return session->init.getWifiUserDataFunc(session->userArg);
}






















/*
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 */
u32 GFL_NET_GetFriendList(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->init.getFriendListFunc == 0) {
        return 0;
    }
    return session->init.getFriendListFunc(session->userArg);
}
















u32 GFL_NET_GetFriendListNum(void)
{
    return GFL_NET_GetSession()->init.friendListNum;
}

















void GFL_NET_SetWaitMode(u32 waitMode)
{
    GFL_NET_SYSTEM_SetWaitMode(waitMode);
}



















/*
 * Returns the word at +0x34c of the net context, or 0 when there is none.
 */
u32 GFL_NET_GetUserArg(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    return session != 0 ? session->userArg : 0;
}



















/*
 * Stores the argument at +0x34c of the net context, when there is one.
 */
void GFL_NET_SetUserArg(u32 userArg)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session != 0) {
        session->userArg = userArg;
    }
}


















/*
 * Returns the net context's +0x60 byte, reporting through the assert reporter with
 * the source file at 0x020A7CA0 ("net.c") and line 0x593 (1427) when the byte
 * is past 8.  The guard is unsigned (`bls`), so the comparison is
 * `> 8` against an unsigned char.
 *
 */
u32 GFL_NET_GetMaxConnectNum(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->init.maxConnectNum > 8)
        func_02034714(sNetFileName, 0x593, file_020A7CF8);
    return session->init.maxConnectNum;
}



















/*
 * Returns the byte at +0x61 of the net context.
 */
u32 GFL_NET_GetChildSendSize(void)
{
    return GFL_NET_GetSession()->init.childSendSize;
}



















/*
 * Halfword getter for the null-test sibling of GFL_NET_GetMaxConnectNum: reports through
 * the assert reporter at line 0x5B1 (1457) when GFL_NET_GetSession comes back null, then
 * reads +0x6C from it regardless.  The null test is the `movs r4, r0` /
 * `bne` pair, so the result is kept in a local that the tail still
 * dereferences rather than being re-requested.
 *
 */
u32 GFL_NET_GetParentSendSize(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session == 0)
        func_02034714(sNetFileName, 0x5B1, file_020A7D2C);
    return session->init.parentSendSize;
}



















/*
 * Calls the net context's +0x30 callback with its +0x34c argument.
 */
void GFL_NET_CallDeviceReadyFunc(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->init.deviceReadyFunc != 0) {
        session->init.deviceReadyFunc(session->userArg);
    }
}



















/*
 * Calls the net context's +0x28 callback with the GFL_NET_HANDLE_GetCurrentHandle result,
 * the argument and the context's +0x34c value.
 */
void GFL_NET_CallErrorStateFunc(u32 errorCode)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->init.errorStateFunc == 0) {
        return;
    }
    session->init.errorStateFunc(
        (u32)GFL_NET_HANDLE_GetCurrentHandle(), errorCode, session->userArg);
}



















/*
 * Calls the net context's +0x24 callback with the GFL_NET_HANDLE_GetCurrentHandle result,
 * the argument and the context's +0x34c value.
 */
void GFL_NET_CallStateChangeFunc(u32 newState)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->init.stateChangeFunc == 0) {
        return;
    }
    session->init.stateChangeFunc(
        (u32)GFL_NET_HANDLE_GetCurrentHandle(), newState, session->userArg);
}















GFLNetSession *GFL_NET_GetSession(void)
{
    return gGFLNetMain.session;
}















/*
 * Return the session pointer held in gGFLNetMain, or 0 when none is set.
 */
GFLNetSession *GFL_NET_GetInitParam(void)
{
    if (gGFLNetMain.session == 0) {
        return 0;
    }
    return gGFLNetMain.session;
}















/*
 * Tail-call thunk: set the auto-exit flag in the state layer.
 */
void GFL_NET_SetAutoExit(u8 autoExit)
{
    GFL_NET_STATE_SetAutoExit(autoExit);
}















/*
 * Tail-call thunk: set the login option in the state layer.
 */
void GFL_NET_SetLoginOption(u8 loginOption)
{
    GFL_NET_STATE_SetLoginOption(loginOption);
}















/*
 * Allocates size rounded up to 0x20 plus 0x20, rounds the result up to a
 * 0x20 boundary and stores the raw pointer in the word just before the
 * aligned block, which GFL_NET_FreeAligned releases it by.
 */
void *GFL_NET_AllocAligned(u32 heapId, u32 size, const char *fileName, u16 line)
{
    u8 *rawBlock = (u8 *)func_02030734(heapId, ((size + 0x24) & ~0x1fu) + 0x20, 1, fileName, line);
    u8 *alignedBlock = (u8 *)(((u32)rawBlock + 0x20) & ~0x1fu);

    *(void **)(alignedBlock - 4) = rawBlock;
    return alignedBlock;
}















/*
 * Releases the aligned block GFL_NET_AllocAligned returns, via the pointer kept
 * just before it, and tolerates a null.
 */
void GFL_NET_FreeAligned(void *block)
{
    if (block == 0) {
        return;
    }
    func_020307B0(*(void **)((u8 *)block - 4));
}















/*
 * Stores the two net_irc_wireless context words at +0xc and +4.
 */
void GFL_NET_SetIrcParams(u32 paramA, u32 paramB)
{
    gGFLNetMain.ircParamA = paramA;
    gGFLNetMain.ircParamB = paramB;
}















/*
 * Reads back the two net_irc_wireless context words.
 */
void GFL_NET_GetIrcParams(u32 *outParamA, u32 *outParamB)
{
    *outParamA = gGFLNetMain.ircParamA;
    *outParamB = gGFLNetMain.ircParamB;
}















/*
 * Copies 0x70 bytes from the net context into the destination.
 */
void GFL_NET_CopyInitParam(void *dst)
{
    func_02082D44(dst, GFL_NET_GetSession(), 0x70);
}















/*
 * Clears the net context's +0x2c and +0x1c words.
 */
void GFL_NET_ClearBeaconCallbacks(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session != 0) {
        session->init.connectEndFunc = 0;
        session->init.getBeaconSizeFunc = 0;
    }
}















/*
 * A bare tail-call thunk to GFL_NET_SYSTEM_CheckError.
 */
u32 GFL_NET_CheckError(void)
{
    return GFL_NET_SYSTEM_CheckError();
}















/*
 * Truncates both arguments to 16 bits, then runs the pair through
 * the timeout setter and GFL_NET_RestartByNetType.
 */
void GFL_NET_RestartWithTimeout(u32 timeoutFrames, u32 timeoutExtra)
{
    GFL_NET_WM_ICON_SetDefaultPos((u16)timeoutFrames, (u16)timeoutExtra);
    GFL_NET_RestartByNetType();
}















/*
 * Runs the timeout setter(0, 0) and GFL_NET_RestartByNetType.
 */
void GFL_NET_RestartNoTimeout(void)
{
    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
    GFL_NET_RestartByNetType();
}















/*
 * Writes 1 or 0 to the net context's +0x352 byte depending on whether the
 * argument is 1; a null context is a no-op.
 */
void GFL_NET_SetErrorCheckEnabled(u32 enable)
{
    GFLNetSession *session = gGFLNetMain.session;

    if (session == 0) {
        return;
    }
    if (enable == 1) {
        session->errorCheckEnabled = 1;
    } else {
        session->errorCheckEnabled = 0;
    }
}















/*
 * Wrap a caller's 0x70-byte init block for the wireless link. Allocates a
 * 0x10C-byte record on the block's own heap (id | 0x8000), copies the block in,
 * saves its connect-end, beacon data and beacon compare callbacks, installs the
 * wireless link's own versions in their place, publishes the record in
 * gNetIrcWirelessLink and returns it. With a live record whose active flag is 1
 * it returns the block untouched.
 *
 * The block parameter is const: without it the stores into the new record may
 * alias the block and the compiler orders the loads differently.
 */
GFLNetInitializeStruct *GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, u32 callbackArg)
{
    NetIrcWirelessLink *link;

    if (gNetIrcWirelessLink != 0 && gNetIrcWirelessLink->active == 1)
        return (GFLNetInitializeStruct *)src;

    link = func_02030734((u16)((src->parentHeapId & 0x7FFF) | 0x8000), sizeof(NetIrcWirelessLink), 1, sNetIrcWirelessFileName, 0x72);
    link->init = *src;
    link->callbackArg = callbackArg;
    link->savedConnectEndFunc = src->connectEndFunc;
    link->savedGetBeaconDataFunc = src->getBeaconDataFunc;
    link->savedGetBeaconSizeFunc = src->getBeaconSizeFunc;
    link->init.bNetType = 3;
    link->init.connectEndFunc = GFL_NET_IRC_WIRELESS_OnConnectEnd;
    link->init.getBeaconDataFunc = GFL_NET_IRC_WIRELESS_GetBeaconData;
    link->init.getBeaconSizeFunc = GFL_NET_IRC_WIRELESS_GetBeaconCompare;
    link->savedBMPMode = link->init.bMPMode;
    link->init.bMPMode = 0;
    link->expectedMemberNum = link->init.maxConnectNum;

    gNetIrcWirelessLink = link;
    func_02034F84(0x20);
    return &gNetIrcWirelessLink->init;
}













/*
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through the state-layer release (0x20) and the heap release, then clears the slot.
 */
void GFL_NET_IRC_WIRELESS_Destroy(void)
{
    if (gNetIrcWirelessLink == 0) {
        return;
    }
    func_02034FB8(0x20);
    func_020307B0(gNetIrcWirelessLink);
    gNetIrcWirelessLink = 0;
}













/*
 * Calls GFL_NET_IRC_WIRELESS_Destroy when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 */
void GFL_NET_IRC_WIRELESS_DestroyIfIdle(void)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;

    if (link == 0) {
        return;
    }
    if (link->active != 0) {
        return;
    }
    GFL_NET_IRC_WIRELESS_Destroy();
}













int GFL_NET_IRC_WIRELESS_IsActive(void)
{
    return gNetIrcWirelessLink != 0;
}











/*
 * Stores a word into the singleton at +0x74.
 */
void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value)
{
    gNetIrcWirelessLink->sessionParam = value;
}












/*
 * Install the three wireless link callbacks and return the sync-ready handler.
 * With no live link the function returns its first argument untouched. Each
 * non-null callback is stored in the link; the link is re-read from the global
 * for the second and third store.
 */
void *GFL_NET_IRC_WIRELESS_SetCallbacks(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32))
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;

    if (link == 0)
        return onFinished;
    if (onFinished != 0)
        link->onFinishedFunc = onFinished;
    if (onResult != 0)
        gNetIrcWirelessLink->onResultFunc = onResult;
    if (onReady != 0)
        gNetIrcWirelessLink->onReadyFunc = onReady;
    return GFL_NET_IRC_WIRELESS_OnSyncReady;
}










void GFL_NET_IRC_WIRELESS_AddMacAddress(const u8 *mac)
{
    int i;

    if (gNetIrcWirelessLink == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (func_0203EFC8(mac, gNetIrcWirelessLink->macs.mac[i].addr, 6) == 0)
            return;
    }
    {
        u8 emptyMac[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 4; i++) {
            if (func_0203EFC8(emptyMac, gNetIrcWirelessLink->macs.mac[i].addr, 6) == 0) {
                func_02082D44(mac, gNetIrcWirelessLink->macs.mac[i].addr, 6);
                gNetIrcWirelessLink->macs.count = i;
                return;
            }
        }
    }
    GFL_NET_STATE_SetErrorMode(1);
}









void GFL_NET_IRC_WIRELESS_CopyMacAddress(void *dst, u32 slot)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;

    if (link != 0) {
        func_02082D44(link->macs.mac[slot].addr, dst, 6);
    } else {
        func_02034714(sNetIrcWirelessFileName, 0x109, (const char *)str_020A7D48);
    }
}








void GFL_NET_IRC_WIRELESS_OnSyncReady(void)
{
    if (gNetIrcWirelessLink == 0)
        return;
    gNetIrcWirelessLink->syncReady = 1;
    if (gNetIrcWirelessLink->requestedNetIDPlus1 != 0) {
        gNetIrcWirelessLink->netID = gNetIrcWirelessLink->requestedNetIDPlus1 - 1;
    } else {
        gNetIrcWirelessLink->netID = GFL_NET_SYSTEM_GetCurrentAid();
    }
}








/*
 * net_irc_wireless.c.  Callback installed at +0x2C by GFL_NET_IRC_WIRELESS_Create and
 * by states 4 and 14 of GFL_NET_IRC_WIRELESS_Main: flags +0x103 of the live context.
 * An unlabelled ARM leaf.
 */
void GFL_NET_IRC_WIRELESS_OnConnectEnd(u32 userArg)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;

    if (link != 0)
        link->connectEnded = 1;
}








/*
 * net_irc_wireless.c.  The state setter of the wireless state machine
 * GFL_NET_IRC_WIRELESS_Main: stores the new state at +0x109.  An unlabelled ARM leaf
 * (no lr save), filed as the `matched` witness for GFL_NET_IRC_WIRELESS_Main's 27 calls.
 */
void GFL_NET_IRC_WIRELESS_SetState(NetIrcWirelessLink *link, int state)
{
    link->state = state;
}






void GFL_NET_IRC_WIRELESS_Main(void)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;

    if (link == 0)
        return;

    switch (link->state) {
    case 0:
        if (link->syncReady != 1)
            return;
        link->active = 1;
        func_02039C68(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0);
        GFL_NET_IRC_WIRELESS_SetState(link, 1);
        break;
    case 1:
        if (func_02039CB4(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0) == 0)
            return;
        GFL_NET_IRC_WIRELESS_SetState(link, 2);
        break;
    case 2:
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0, 0) == 0)
                return;
            GFL_NET_IRC_WIRELESS_SetState(link, 3);
            link->timeoutCounter = 0xC8;
        } else {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x10, 0, 0) == 0)
                return;
            GFL_NET_IRC_WIRELESS_SetState(link, 3);
        }
        break;
    case 3:
        link->timeoutCounter--;
        if (GFL_NET_IsIdle()) {
            if (gNetIrcWirelessLink->onReadyFunc != 0)
                gNetIrcWirelessLink->onReadyFunc(gNetIrcWirelessLink->callbackArg);
            if (link->retryEnabled != 0 && link->init.maxConnectNum == 4 && link->netID == 0) {
                GFL_NET_IRC_WIRELESS_SetState(link, 0xE);
                link->retryCount++;
            } else if (link->netID == 0 && link->init.maxConnectNum == 4) {
                link->retryCount++;
                GFL_NET_Exit(0);
                link->onResultFunc(link->callbackArg, 1);
                GFL_NET_IRC_WIRELESS_SetState(link, 4);
            } else {
                link->onResultFunc(link->callbackArg, 0);
                GFL_NET_IRC_WIRELESS_SetState(link, 9);
            }
        }
        if (link->timeoutCounter == 0)
            GFL_NET_Exit(0);
        break;
    case 4:
        if (GFL_NET_GetRunState() != 0)
            return;
        link->init.bNetType = 3;
        link->init.connectEndFunc = GFL_NET_IRC_WIRELESS_OnConnectEnd;
        if (link->gameKindOverride != 0)
            link->init.gameKind = link->gameKindOverride;
        link->syncReady = 0;
        link->connectEnded = 0;
        GFL_NET_StartSession((GFLNetInitializeStruct *)link, 0, link->callbackArg);
        GFL_NET_IRC_WIRELESS_SetState(link, 5);
        break;
    case 5:
        if (GFL_NET_GetRunState() != 1)
            return;
        GFL_NET_GetSession()->ops->setSessionParam(gNetIrcWirelessLink->sessionParam);
        GFL_NET_StartChangeoverChild((u32)GFL_NET_IRC_WIRELESS_OnSyncReady);
        GFL_NET_IRC_WIRELESS_SetState(link, 6);
        break;
    case 6:
        if (link->syncReady != 1)
            return;
        link->active = 1;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x24, &gNetIrcWirelessLink->macs) == 0)
            return;
        GFL_NET_IRC_WIRELESS_SetState(link, 7);
        break;
    case 7:
        if (link->syncReady != 1)
            return;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0, 0) == 0)
            return;
        GFL_NET_SetLinkTimeout(0xC8);
        GFL_NET_IRC_WIRELESS_SetState(link, 8);
        break;
    case 8:
        if (GFL_NET_IsIdle() == 0)
            return;
        if (gNetIrcWirelessLink->onReadyFunc != 0)
            gNetIrcWirelessLink->onReadyFunc(gNetIrcWirelessLink->callbackArg);
        GFL_NET_IRC_WIRELESS_SetState(link, 9);
        break;
    case 9:
        if (GFL_NET_IsIdle() == 0)
            return;
        if (link->gameKindOverride != 0) {
            link->init.linkExtraFlags = 0;
            link->init.gameKind = link->gameKindOverride;
        }
        link->init.bNetType = 0;
        link->init.connectEndFunc = link->savedConnectEndFunc;
        link->init.bMPMode = link->savedBMPMode;
        GFL_NET_StartSession((GFLNetInitializeStruct *)link, 0, link->callbackArg);
        gNetIrcWirelessLink->active = 0;
        GFL_NET_IRC_WIRELESS_SetState(link, 0xA);
        break;
    case 10:
        if (GFL_NET_GetRunState() != 1)
            return;
        if (link->netID == 0) {
            GFL_NET_StartByNetType();
            GFL_NET_IRC_WIRELESS_SetState(link, 0xC);
        } else if (link->init.maxConnectNum == 4) {
            GFL_NET_BeaconScanStart();
            GFL_NET_IRC_WIRELESS_SetState(link, 0xB);
        } else {
            GFL_NET_ConnectMacAddressParent(link->macs.mac);
            GFL_NET_IRC_WIRELESS_SetState(link, 0xC);
        }
        break;
    case 11: {
        u8 ownMac[6];
        int scanIndex;
        int slot;
        u8 *scanEntry;

        scanIndex = 0;
        func_02087C6C(ownMac);
        for (;; scanIndex++) {
            scanEntry = (u8 *)GFL_NET_GetScanResult((int)scanIndex);
            if (scanEntry == 0)
                return;
            for (slot = 0; slot < 4; slot++) {
                if (func_0203EFC8(ownMac, scanEntry + 4 + slot * 8, 6) == 0) {
                    GFL_NET_ConnectMacAddressChild(GFL_NET_GetScanResultMac((u32)scanIndex));
                    GFL_NET_IRC_WIRELESS_SetState(link, 0xC);
                    break;
                }
            }
        }
    }
    case 12:
        if (link->netID == 0) {
            if (GFL_NET_HANDLE_GetNegotiationNum() == 0)
                return;
            if (GFL_NET_HANDLE_CheckNegotiation() != 1)
                return;
            GFL_NET_IRC_WIRELESS_SetState(link, 0xD);
        } else {
            if (GFL_NET_HANDLE_CheckNegotiation() != 1)
                return;
            GFL_NET_IRC_WIRELESS_SetState(link, 0xD);
        }
        break;
    case 13:
        if (link->netID != 0) {
            if (link->onFinishedFunc != 0)
                link->onFinishedFunc(link->callbackArg);
            GFL_NET_IRC_WIRELESS_DestroyIfIdle();
        } else {
            if (GFL_NET_HANDLE_GetNegotiationNum() < link->expectedMemberNum)
                return;
            if (link->onFinishedFunc != 0)
                link->onFinishedFunc(link->callbackArg);
            GFL_NET_IRC_WIRELESS_DestroyIfIdle();
        }
        break;
    case 14:
        if (GFL_NET_GetRunState() != 0)
            return;
        link->init.bNetType = 3;
        link->init.connectEndFunc = GFL_NET_IRC_WIRELESS_OnConnectEnd;
        link->syncReady = 0;
        link->connectEnded = 0;
        GFL_NET_StartSession((GFLNetInitializeStruct *)link, 0, link->callbackArg);
        GFL_NET_IRC_WIRELESS_SetState(link, 0xF);
        break;
    case 15:
        if (GFL_NET_GetRunState() != 1)
            return;
        GFL_NET_GetSession()->ops->setSessionParam(gNetIrcWirelessLink->sessionParam);
        GFL_NET_StartChangeoverChild((u32)GFL_NET_IRC_WIRELESS_OnSyncReady);
        GFL_NET_IRC_WIRELESS_SetState(link, 0x10);
        break;
    case 16:
        if (link->syncReady != 1)
            return;
        func_02039C68(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0);
        gNetIrcWirelessLink->active = 1;
        GFL_NET_IRC_WIRELESS_SetState(link, 0x11);
        break;
    case 17:
        if (func_02039CB4(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0) == 0)
            return;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0, 0) == 0)
            return;
        GFL_NET_IRC_WIRELESS_SetState(link, 0x12);
        link->timeoutCounter = 0xC8;
        break;
    case 18:
        link->timeoutCounter--;
        if (GFL_NET_IsIdle() == 0 && link->timeoutCounter != 0)
            return;
        if (gNetIrcWirelessLink->onReadyFunc != 0)
            gNetIrcWirelessLink->onReadyFunc(gNetIrcWirelessLink->callbackArg);
        if (link->retryEnabled != 0 && link->retryCount < 3) {
            link->retryCount++;
            if (link->retryCount >= 3)
                GFL_NET_IRC_WIRELESS_SetState(link, 9);
            else
                GFL_NET_IRC_WIRELESS_SetState(link, 0xE);
        } else {
            GFL_NET_IRC_WIRELESS_SetState(link, 9);
        }
        break;
    }
}





void *GFL_NET_IRC_WIRELESS_GetBeaconData(void *beaconArg)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;
    void *beaconData;

    if (link == 0)
        return 0;
    beaconData = link->savedGetBeaconDataFunc(beaconArg);
    func_02082D44(beaconData, link->beaconCopy, 0x4C);
    return &link->macs;
}



void *GFL_NET_IRC_WIRELESS_GetBeaconCompare(void *beaconArg)
{
    void *compareData;
    if (gNetIrcWirelessLink == 0)
        return 0;
    compareData = gNetIrcWirelessLink->savedGetBeaconSizeFunc(beaconArg);
    return (char *)compareData + 0x24;
}




/*
 * Merge a received MAC list into the link's table, entry by entry (at most
 * four). A count of four or more reports an assert.
 */
void GFL_NET_IRC_WIRELESS_AddMacList(u32 unusedA, u32 unusedB, struct NetMacList *macList)
{
    int i;
    int macCount;

    if (macList->count >= 4) {
        func_02034714(sNetIrcWirelessFileName, 0x2a5, (const char *)str_020A7D4C);
    }
    macCount = macList->count;
    if (macCount > 4) {
        macCount = 4;
    }
    for (i = 0; i < macCount; i++) {
        GFL_NET_IRC_WIRELESS_AddMacAddress(macList->mac[i].addr);
    }
}




/*
 * Retry step: only a link in state 0x10 advances. It seeds the expected member
 * count from the retry count, restarts the session and parks the state at 9.
 * Returns 1 when it advanced, otherwise 0.
 */
u32 GFL_NET_IRC_WIRELESS_RetryStep(void)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;

    if (link == 0)
        return 0;
    if (link->state != 0x10)
        return 0;
    link->expectedMemberNum = link->retryCount + 1;
    GFL_NET_Exit(0);
    gNetIrcWirelessLink->state = 9;
    return 1;
}


void GFL_NET_IRC_WIRELESS_RequestRetry(int netId)
{
    if (gNetIrcWirelessLink == 0)
        func_02034714(sNetIrcWirelessFileName, 0x2e4, s_020A7D68);
    if (gNetIrcWirelessLink != 0) {
        gNetIrcWirelessLink->requestedNetIDPlus1 = (u8)(netId + 1);
        gNetIrcWirelessLink->retryEnabled = 1;
    }
}


/*
 * Reads byte 0x108 of the singleton, or 0 when it is not allocated.
 */
int GFL_NET_IRC_WIRELESS_GetRetryCountValue(void)
{
    NetIrcWirelessLink *link = gNetIrcWirelessLink;
    if (link == 0) return 0;
    return link->retryCount;
}


void GFL_NET_IRC_WIRELESS_SetGameKindOverride(int gameKind)
{
    if (gNetIrcWirelessLink == 0)
        func_02034714(sNetIrcWirelessFileName, 0x31a, s_020A7D68);
    if (gNetIrcWirelessLink != 0)
        gNetIrcWirelessLink->gameKindOverride = (u8)gameKind;
}
