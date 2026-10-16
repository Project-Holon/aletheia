/*
 * file:     net_devwifi.c
 * unit:     yes
 * function: GFL_NET_DEVWIFI_InitDwc, GFL_NET_DEVWIFI_Setup, GFL_NET_DEVWIFI_Begin, GFL_NET_DEVWIFI_Update, GFL_NET_DEVWIFI_UpdateDisconnect, GFL_NET_DEVWIFI_Cleanup, GFL_NET_DEVWIFI_StartMatchWithKey, GFL_NET_DEVWIFI_StartFriendMatch, GFL_NET_DEVWIFI_PollDisconnect, GFL_NET_DEVWIFI_SendMessage, GFL_NET_DEVWIFI_SetRecvCallback, GFL_NET_DEVWIFI_IsActive, GFL_NET_DEVWIFI_IsConnected, GFL_NET_DEVWIFI_IsOffline, GFL_NET_DEVWIFI_IsIdle, GFL_NET_DEVWIFI_GetAidBitmap, GFL_NET_DEVWIFI_GetMyAid, GFL_NET_DEVWIFI_GetSignalLevel, GFL_NET_DEVWIFI_GetLastErrorCode, GFL_NET_DEVWIFI_SetErrorOnDisconnect, GFL_NET_DEVWIFI_IsFriendWaiting, GFL_NET_DEVWIFI_IsVchatEnabled, GFL_NET_DEVWIFI_GetNewClientAid, GFL_NET_DEVWIFI_SetAllowConnect, GFL_NET_DEVWIFI_IsInSession, GFL_NET_DEVWIFI_GetDeviceTable
 * address:  0x02155160
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from dwc_rap.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   _pSetupParam     0x021A8260  data  ov009  a4
 *   _sNetDevwifiFile     0x021A1C4C  data  ov009  a1
 *   GFL_NET_GetWifiUserData 0x0203D5EC arm
 *   GFL_NET_GetFriendList 0x0203D610 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   DWC_GetAIDBitmap 0x0216B908 arm ov009
 *   DWC_GetLinkLevel  0x0205CCD8  arm
 *   DWC_GetLastErrorEx  0x02059E38  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   _wifiDeviceTable  0x021A1B80  data
 *   DWC_RAP_IsWorkAllocated 0x02155388 thumb ov009
 *   DWC_RAP_CreateWork 0x0215539C thumb ov009
 *   DWC_RAP_SetRecvCallbacks 0x02155648 thumb ov009
 *   DWC_RAP_StartMatchWithKey 0x0215568C thumb ov009
 *   DWC_RAP_RunStateMachine 0x0215592C thumb ov009
 *   DWC_RAP_SendMessage 0x02155B14 thumb ov009
 *   DWC_RAP_GetMyAidIfConnected 0x021562EC thumb ov009
 *   DWC_RAP_ProgressDisconnect 0x02156690 thumb ov009
 *   DWC_RAP_ResetToIdle 0x02156730 thumb ov009
 *   DWC_RAP_Shutdown 0x0215677C thumb ov009
 *   DWC_RAP_GetFriendStatus 0x02156874 thumb ov009
 *   DWC_RAP_StartFriendMatch 0x02156888 thumb ov009
 *   DWC_RAP_GetVchatEnabled 0x02156B70 thumb ov009
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   DWC_RAP_IsStateIdle 0x02156CAC thumb ov009
 *   DWC_RAP_IsStateInSession 0x02156CD0 thumb ov009
 *   DWC_RAP_StoreAllowConnect 0x02156D70 thumb ov009
 *   DWC_RAP_IsDisconnected 0x02156D84 thumb ov009
 *   DWC_RAP_StoreErrorOnDisconnect 0x02156DB0 thumb ov009
 *   DWC_RAPCOMMON_InitDwcWithNotice 0x02156DFC thumb ov009
 *   DWC_RAPCOMMON_CreateHeap 0x02157048 thumb ov009
 *   DWC_RAPCOMMON_DestroyHeap 0x021570B8 thumb ov009
 */
#include "dwc_rap_types.h"
#include "net_devwifi_shared_types.h"

void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_NET_GetWifiUserData(void);

extern u32 GFL_NET_GetFriendList(void);

u32 GFL_HEAP_Free(void *block);

extern int DWC_GetAIDBitmap(void);

extern int DWC_GetLinkLevel(void);

int DWC_GetLastErrorEx(int *errorCode, int *errorType);

void GFL_NET_STATE_SetError(int errorCode, u32 errorType, u32 dwcError, u32 gameCode);

u32 GFL_NET_STATE_GetError(void);

void GFL_NET_DEVWIFI_InitDwc(int heapId);

int GFL_NET_DEVWIFI_Setup(int heapId, int param);

int GFL_NET_DEVWIFI_Begin(void (*doneCallback)(int));

int GFL_NET_DEVWIFI_Update(int cancelRequest);

int GFL_NET_DEVWIFI_UpdateDisconnect(void *requestClose);

int GFL_NET_DEVWIFI_Cleanup(void (*doneCallback)(int));

int GFL_NET_DEVWIFI_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused);

int GFL_NET_DEVWIFI_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo);

int GFL_NET_DEVWIFI_PollDisconnect(int requestClose);

int GFL_NET_DEVWIFI_SendMessage(int data, int size, int unused, void (*doneCallback)(int));

int GFL_NET_DEVWIFI_SetRecvCallback(int callback);

int GFL_NET_DEVWIFI_IsActive(void);

int GFL_NET_DEVWIFI_IsConnected(void);

int GFL_NET_DEVWIFI_IsOffline(void);

int GFL_NET_DEVWIFI_IsIdle(void);

int GFL_NET_DEVWIFI_GetAidBitmap(void);

int GFL_NET_DEVWIFI_GetMyAid(void);

int GFL_NET_DEVWIFI_GetSignalLevel(void);

int GFL_NET_DEVWIFI_GetLastErrorCode(void);

void GFL_NET_DEVWIFI_SetErrorOnDisconnect(u32 enabled);

int GFL_NET_DEVWIFI_IsFriendWaiting(int friendIndex);

s16 GFL_NET_DEVWIFI_IsVchatEnabled(void);

int GFL_NET_DEVWIFI_GetNewClientAid(void);

void GFL_NET_DEVWIFI_SetAllowConnect(u32 allowed);

int GFL_NET_DEVWIFI_IsInSession(void);

void *GFL_NET_DEVWIFI_GetDeviceTable(void);

int DWC_RAP_IsWorkAllocated(void);

int DWC_RAP_CreateWork(int userData, int friendList);

void DWC_RAP_SetRecvCallbacks(int serverFunc, int clientFunc);

int DWC_RAP_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused);

int DWC_RAP_RunStateMachine(int cancelRequest);

int DWC_RAP_SendMessage(int data, int size);

int DWC_RAP_GetMyAidIfConnected(void);

int DWC_RAP_ProgressDisconnect(int pollOnly);

int DWC_RAP_ResetToIdle(void);

void DWC_RAP_Shutdown(void);

unsigned char DWC_RAP_GetFriendStatus(int friendIndex);

int DWC_RAP_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo);

s16 DWC_RAP_GetVchatEnabled(void);

int DWC_RAP_GetNewClientAid(void);

int DWC_RAP_IsStateIdle(void);

int DWC_RAP_IsStateInSession(void);

void DWC_RAP_StoreAllowConnect(u32 allowed);

int DWC_RAP_IsDisconnected(void);

void DWC_RAP_StoreErrorOnDisconnect(u32 enabled);

void DWC_RAPCOMMON_InitDwcWithNotice(int heapId);

void DWC_RAPCOMMON_CreateHeap(u32 heapId, u32 size);

void DWC_RAPCOMMON_DestroyHeap(void);

extern int *_pSetupParam;

extern char _sNetDevwifiFile[];

extern char _wifiDeviceTable[];

void GFL_NET_DEVWIFI_InitDwc(int heapId)
{
    DWC_RAPCOMMON_InitDwcWithNotice(heapId);
}

int GFL_NET_DEVWIFI_Setup(int heapId, int param)
{
    GFLNetInitializeStruct *netInit;

    if (_pSetupParam != 0)
        return 0;
    netInit = GFL_NET_GetInitParam();
    DWC_RAPCOMMON_CreateHeap(netInit->wifiHeapId, netInit->heapSize);
    _pSetupParam = GFL_HEAP_Alloc(heapId, 8, 1, _sNetDevwifiFile, 0xba);
    *_pSetupParam = param;
    return 1;
}

int GFL_NET_DEVWIFI_Begin(void (*doneCallback)(int))
{
    u32 userData;
    int result;
    userData = GFL_NET_GetWifiUserData();
    result = DWC_RAP_CreateWork(userData, GFL_NET_GetFriendList());
    if (doneCallback) doneCallback(1);
    return result;
}

int GFL_NET_DEVWIFI_Update(int cancelRequest)
{
    return DWC_RAP_RunStateMachine(cancelRequest);
}

/*
 * Null-pointer guard through DWC_RAP_ProgressDisconnect, then either DWC_RAP_ResetToIdle or DWC_RAP_RunStateMachine.
 */
int GFL_NET_DEVWIFI_UpdateDisconnect(void *requestClose)
{
    int DWC_RAP_ProgressDisconnect(int);
    int DWC_RAP_ResetToIdle(void);
    int DWC_RAP_RunStateMachine(int cancelRequest);
    int pollOnly;
    if (requestClose == 0) pollOnly = 1;
    else pollOnly = 0;
    if (DWC_RAP_ProgressDisconnect(pollOnly)) {
        DWC_RAP_ResetToIdle();
        return 1;
    }
    DWC_RAP_RunStateMachine((int)requestClose);
    return 1;
}

int GFL_NET_DEVWIFI_Cleanup(void (*doneCallback)(int))
{
    if (_pSetupParam != 0) {
        DWC_RAP_Shutdown();
        if (doneCallback != 0)
            doneCallback(1);
        GFL_HEAP_Free(_pSetupParam);
        _pSetupParam = 0;
    }
    DWC_RAPCOMMON_DestroyHeap();
    return 1;
}

int GFL_NET_DEVWIFI_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused)
{
    return DWC_RAP_StartMatchWithKey(matchValue, maxPlayers, useFilter, unused);
}

int GFL_NET_DEVWIFI_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo)
{
    return DWC_RAP_StartFriendMatch(friendIndex, maxPlayers, limitToTwo);
}

int GFL_NET_DEVWIFI_PollDisconnect(int requestClose)
{
    int DWC_RAP_ProgressDisconnect(int);
    int DWC_RAP_ResetToIdle(void);
    int pollOnly;
    if (requestClose == 0) pollOnly = 1;
    else pollOnly = 0;
    if (DWC_RAP_ProgressDisconnect(pollOnly)) {
        DWC_RAP_ResetToIdle();
        return 1;
    }
    return 0;
}

int GFL_NET_DEVWIFI_SendMessage(int data, int size, int unused, void (*doneCallback)(int))
{
    if (DWC_RAP_SendMessage(data, size)) {
        if (doneCallback) doneCallback(1);
        return 1;
    }
    return 0;
}

/*
 * Calls DWC_RAP_SetRecvCallbacks on the argument twice and returns 1.
 */
int GFL_NET_DEVWIFI_SetRecvCallback(int callback)
{
    DWC_RAP_SetRecvCallbacks(callback, callback);

    return 1;
}

int GFL_NET_DEVWIFI_IsActive(void)
{
    return DWC_RAP_IsWorkAllocated();
}

/*
 * False when the word call returns -1.
 */
int GFL_NET_DEVWIFI_IsConnected(void)
{
    if (DWC_RAP_GetMyAidIfConnected() != -1) {
        return 1;
    }

    return 0;
}

/*
 * True when no session is open or the state machine reports a lost connection.
 */
int GFL_NET_DEVWIFI_IsOffline(void)
{
    int offline;
    offline = DWC_RAP_IsDisconnected();
    if (!DWC_RAP_IsWorkAllocated()) offline |= 1;
    return offline;
}

int GFL_NET_DEVWIFI_IsIdle(void)
{
    return DWC_RAP_IsStateIdle();
}

int GFL_NET_DEVWIFI_GetAidBitmap(void)
{
    return DWC_GetAIDBitmap();
}

int GFL_NET_DEVWIFI_GetMyAid(void)
{
    return DWC_RAP_GetMyAidIfConnected();
}

/*
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 */
int GFL_NET_DEVWIFI_GetSignalLevel(void)
{
    return 3 - DWC_GetLinkLevel();
}

int GFL_NET_DEVWIFI_GetLastErrorCode(void)
{
    int errorCode, errorType, dwcError;

    dwcError = DWC_GetLastErrorEx(&errorCode, &errorType);
    if (dwcError != 0)
        GFL_NET_STATE_SetError(errorCode, errorType, dwcError, 0);
    if (dwcError == 0)
        return 0;
    if (errorCode == 0)
        return -10000;
    dwcError = ((int *)GFL_NET_STATE_GetError())[3];
    if (dwcError == 0)
        dwcError = errorCode;
    return dwcError;
}

void GFL_NET_DEVWIFI_SetErrorOnDisconnect(u32 enabled)
{
    DWC_RAP_StoreErrorOnDisconnect(enabled);
}

/*
 * True when the friend is in the waiting-for-a-partner status.
 */
int GFL_NET_DEVWIFI_IsFriendWaiting(int friendIndex)
{
    if (DWC_RAP_GetFriendStatus(friendIndex) == 6) return 1;
    return 0;
}

s16 GFL_NET_DEVWIFI_IsVchatEnabled(void)
{
    return DWC_RAP_GetVchatEnabled();
}

int GFL_NET_DEVWIFI_GetNewClientAid(void)
{
    return DWC_RAP_GetNewClientAid();
}

void GFL_NET_DEVWIFI_SetAllowConnect(u32 allowed)
{
    DWC_RAP_StoreAllowConnect(allowed);
}

int GFL_NET_DEVWIFI_IsInSession(void)
{
    return DWC_RAP_IsStateInSession();
}

/*
 * Address of the module state object.
 */
void *GFL_NET_DEVWIFI_GetDeviceTable(void)
{
    return _wifiDeviceTable;
}
