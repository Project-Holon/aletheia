/*
 * file:     net_state.c
 * unit:     yes
 * function: GFL_NET_STATE_ChangeState, GFL_NET_STATE_ChangeStateDebug, GFL_NET_STATE_InitWork, GFL_NET_STATE_InitRandom, GFL_NET_STATE_FreeWork, GFL_NET_STATE_DeviceInitialized, GFL_NET_STATE_DeviceInitialize, GFL_NET_STATE_ConnectMacDone, GFL_NET_STATE_ExtendConnectTimer, GFL_NET_STATE_ConnectMac, GFL_NET_STATE_StartConnectMac, GFL_NET_STATE_ConnectMacAddress, GFL_NET_STATE_BeaconScanIdle, GFL_NET_STATE_StartBeaconScan, GFL_NET_STATE_BeaconScan, GFL_NET_STATE_Main, GFL_NET_STATE_ParentConnected, GFL_NET_STATE_ParentWait, GFL_NET_STATE_ParentConnectCallback, GFL_NET_STATE_StartParent, GFL_NET_STATE_ChangeParentWait, GFL_NET_STATE_InitParent, GFL_NET_STATE_GetChildWaitTime, GFL_NET_STATE_GetParentWaitTime, GFL_NET_STATE_ChangeoverConnect, GFL_NET_STATE_ChangeoverWaitDevice, GFL_NET_STATE_ChangeoverStopParent, GFL_NET_STATE_ChangeoverStopParentRetry, GFL_NET_STATE_ChangeoverParentConnectWait, GFL_NET_STATE_ChangeoverParentMain, GFL_NET_STATE_ChangeoverParentRestart, GFL_NET_STATE_ChangeoverParentCallback, GFL_NET_STATE_ChangeoverStartParent, GFL_NET_STATE_ChangeoverChildNegotiation, GFL_NET_STATE_ChildNegotiationWait, GFL_NET_STATE_ParentNegotiationWait, GFL_NET_STATE_ChangeoverChildConnected, GFL_NET_STATE_ChangeoverStopChild, GFL_NET_STATE_ChangeoverChildMain, GFL_NET_STATE_ChangeoverChildScan, GFL_NET_STATE_StartChangeover, GFL_NET_STATE_ChangeoverRestart, GFL_NET_STATE_ChangeChangeoverMode, GFL_NET_STATE_ChangeoverStopChildDevice, GFL_NET_STATE_SetChangeoverMode, GFL_NET_STATE_WaitDisconnect, GFL_NET_STATE_RecvExitCommand, GFL_NET_STATE_IsExitReady, GFL_NET_STATE_ExitWait, GFL_NET_STATE_ExitStopDevice, GFL_NET_STATE_Exit, GFL_NET_STATE_ClearExitFlag, GFL_NET_STATE_Idle, GFL_NET_STATE_EndDevice, GFL_NET_STATE_SetMPMode, GFL_NET_STATE_WifiError, GFL_NET_STATE_WifiLoggedOut, GFL_NET_STATE_WifiFatal, GFL_NET_STATE_WifiErrorWait, GFL_NET_STATE_WifiStopError, GFL_NET_STATE_SetWifiErrorCode, GFL_NET_STATE_WifiLoginMain, GFL_NET_STATE_WifiLoginStart, GFL_NET_STATE_WifiEnterLogin, GFL_NET_STATE_WifiEnterRandomMatch, GFL_NET_STATE_WifiEnterFriendMatch, GFL_NET_STATE_WifiEnterLoginDefault, GFL_NET_STATE_GetWifiState, GFL_NET_STATE_WifiConnected, GFL_NET_STATE_WifiMatchDisconnect, GFL_NET_STATE_WifiDisconnect, GFL_NET_STATE_WifiDisconnectFinal, GFL_NET_STATE_IsWifiDisconnectFinal, GFL_NET_STATE_IsWifiLoginState, GFL_NET_STATE_IsWifiLoginOrConnected, GFL_NET_STATE_WifiLogoutWait, GFL_NET_STATE_WifiLogoutStop, GFL_NET_STATE_WifiLogout, GFL_NET_STATE_WifiMatchWait, GFL_NET_STATE_WifiMatchStart, GFL_NET_STATE_WifiStartMatch, GFL_NET_STATE_SetAutoExit, GFL_NET_STATE_SetLoginOption, GFL_NET_STATE_NoProc, GFL_NET_STATE_SetErrorMode, GFL_NET_STATE_ClearErrorMode, GFL_NET_STATE_GetErrorMode, GFL_NET_STATE_SetError, GFL_NET_STATE_SetWifiError, GFL_NET_STATE_GetError, GFL_NET_STATE_FatalError, GFL_NET_STATE_IsFatalError
 * address:  0x0203AD74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x0203AD74 (__FILE__ anchor boundary).
 *
 * symbols:
 *   GFL_HEAP_Alloc            0x02030734  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   GFL_NET_SYSTEM_SetError            0x02039548  arm
 *   SAVEDATA_PanicFail            0x02034714  arm
 *   MI_CpuCopy8              0x02082D44  arm
 *   GFL_HEAP_Free            0x020307B0  arm
 *   GFL_NET_SYSTEM_GetCurrentAid            0x02039338  arm
 *   GFL_NET_SYSTEM_GetChildBitmap            0x020393A8  arm
 *   GFL_NET_SYSTEM_IsError            0x020393D0  arm
 *   GFL_NET_HANDLE_GetCurrentHandle            0x020399A8  arm
 *   GFL_NET_SYSTEM_IsSendEnable            0x02039594  arm
 *   GFL_NET_HANDLE_GetNetHandle            0x0203996C  arm
 *   _pNetState               0x021469DC  data
 *   GFL_NET_SYSTEM_ClampNetId            0x020395E0  arm
 *   OS_GetMacAddress         0x02087C6C  arm
 *   _FileName                0x020A7BA8  data
 *   _AssertNetStateNull      0x020A7BB4  data
 *   RTC_GetDateTime            0x020889C0  arm
 *   GF_STANDARD_RandSeed            0x0203F034  arm
 *   GF_STANDARD_Rand            0x0203F0A8  arm
 *   _VBlankCount             0x02FFFC3C  data
 *   UI_SetKeepAwakeFlagsGlobal            0x02034F84  arm
 *   _AssertMacAlign          0x020A7BC8  data
 *   GFL_NET_SYSTEM_SetNoSend            0x02039578  arm
 *   GFL_NET_SYSTEM_ResetError            0x02039560  arm
 *   _AssertNetTypeWifi       0x020A7BEC  data
 *   _AssertNetState          0x020A7C70  data
 *   _AssertWifiBattleError   0x020A7C7C  data
 *   GFL_NET_WM_ICON_EasyEnd            0x020370C8  arm
 *   GFL_NET_Exit            0x0203CEAC  arm
 *   GFL_NET_SendToHandle            0x0203D3A8  arm
 *   GFL_NET_GetUserArg            0x0203D650  arm
 *   GFL_NET_CallDeviceReadyFunc            0x0203D700  arm
 *   GFL_NET_GetSession            0x0203D788  arm
 *   GFL_NET_GetInitParam            0x0203D798  arm
 *   GFL_NET_IRC_WIRELESS_IsActive            0x0203DA4C  arm
 *   GFL_NET_SYSTEM_InitWork  0x02037288  arm
 *   GFL_NET_SYSTEM_InitDevice  0x02037700  arm
 *   GFL_NET_SYSTEM_SetDeviceOption  0x0203778C  arm
 *   GFL_NET_SYSTEM_ConnectDevice  0x020377B8  arm
 *   GFL_NET_SYSTEM_StartParent  0x02037894  arm
 *   GFL_NET_SYSTEM_StartBeaconScan  0x02037928  arm
 *   GFL_NET_SYSTEM_EndDevice  0x020379C8  arm
 *   GFL_NET_SYSTEM_ConnectToParent  0x02037A6C  arm
 *   GFL_NET_SYSTEM_FreeWork  0x02037B08  arm
 *   GFL_NET_SYSTEM_ResetAll  0x02037D78  arm
 *   GFL_NET_SYSTEM_IsDeviceReady  0x020392EC  arm
 *   GFL_NET_SYSTEM_SetNoChildError  0x020394DC  arm
 *   GFL_NET_HANDLE_InitWork  0x02039834  arm
 *   GFL_NET_HANDLE_ExitWork  0x020398B4  arm
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   GFL_NET_COMMAND_Init  0x0203A494  arm
 *   GFL_NET_COMMAND_Exit  0x0203A53C  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   UI_SetFlags39Global  0x0203516C  arm
 *   UI_ClearFlags39Global  0x020351A0  arm
 */

struct NetStateWork;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

#include "net_types.h"
typedef signed int     s32;

typedef signed char   s8;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetStateWork {
    u32  pad00[2];
    void (*state)(struct NetStateWork *s);
    MATHRandContext64 random;
    u32  pad24;
    void (*exitCallback)(void);
    void (*initCallback)(u32 a);
    NetErrorInfo errorInfo;
    u8   aMacAddress[6];
    u16  timer;
    s8   loginTarget;
    u8   pad49;
    u8   disconnectFinal;
    u8   matchDisconnect;
    u8   parentRetry;
    u8   errorMode;
    u8   wifiErrorCode;
    u8   autoExit;
    u8   loginOption;
    u8   exitRequested;
    u8   pad52;
    u8   changeoverHasMac;
    u8   pad54[2];
    u8   changeoverMode;
    u8   changeoverMac[6];
    u8   pad5D[7];
};

struct RTCDate { u32 year; u32 month; u32 day; u32 week; };

struct RTCTime { u32 hour; u32 minute; u32 second; };

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void  MI_CpuFill8(void *dst, u8 val, u32 size);

extern void GFL_NET_SYSTEM_SetError(void);

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u32 GFL_HEAP_Free(void *p);

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

extern int   GFL_NET_SYSTEM_GetChildBitmap(void);

extern int  GFL_NET_SYSTEM_IsError(void);

extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern int    GFL_NET_SYSTEM_IsSendEnable(void);

extern GFLNetHandle *GFL_NET_HANDLE_GetNetHandle(s32 idx);

extern int GFL_NET_SYSTEM_ClampNetId(int slot);

extern void OS_GetMacAddress(u8 *);

extern int RTC_GetDateTime(struct RTCDate *date, struct RTCTime *time);

extern void GF_STANDARD_RandSeed(u32 seed);

extern u32 GF_STANDARD_Rand(void);

extern void GFL_NET_STATE_Idle(void);

extern void UI_SetKeepAwakeFlagsGlobal(u32 a);

extern void GFL_NET_SYSTEM_SetNoChildError(u8 v);

extern int UI_ClearFlags39Global(u32 v);

extern void UI_SetFlags39Global(u32 a);

extern void GFL_NET_SYSTEM_SetNoSend(void);

extern void GFL_NET_SYSTEM_ResetError(void);

void GFL_NET_WM_ICON_EasyEnd(void);

int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);

int GFL_NET_SYSTEM_InitDevice(u32 a0, u32 a1);

u32 GFL_NET_SYSTEM_SetDeviceOption(u32 p);

u32 GFL_NET_SYSTEM_ConnectDevice(u8 arg0);

u32 GFL_NET_SYSTEM_StartParent(u8 a0, u16 a1, u32 a2, u32 a3);

u32 GFL_NET_SYSTEM_StartBeaconScan(u32 a0, u16 a1);

int GFL_NET_SYSTEM_EndDevice(u32 p);

u32 GFL_NET_SYSTEM_ConnectToParent(u32 a0, u32 a1, u16 a2, u32 a3);

void GFL_NET_SYSTEM_FreeWork(void);

void GFL_NET_SYSTEM_ResetAll(void);

int GFL_NET_SYSTEM_IsDeviceReady(void);










void GFL_NET_HANDLE_InitWork(GFLNetSession *unused);

void GFL_NET_HANDLE_ExitWork(GFLNetSession *unused);



u32 GFL_NET_HANDLE_IsNegotiationDone(GFLNetHandle *handle);

int GFL_NET_HANDLE_GetNegotiationNum(void);

int GFL_NET_HANDLE_CheckNegotiation(void);

void GFL_NET_COMMAND_Init(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void GFL_NET_COMMAND_Exit(void);

void GFL_NET_STATE_ChangeState(struct NetStateWork *work, void *state, u32 timer);

void GFL_NET_STATE_ChangeStateDebug(struct NetStateWork *work, void *state, u32 timer, int line);

void GFL_NET_STATE_InitWork(u32 heapId);

void GFL_NET_STATE_InitRandom(MATHRandContext64 *context);

void GFL_NET_STATE_FreeWork(struct NetStateWork *work);

void GFL_NET_STATE_DeviceInitialized(struct NetStateWork *work);

void GFL_NET_STATE_DeviceInitialize(void *heapId, u32 initCallback);

void GFL_NET_STATE_ConnectMacDone(void);

void GFL_NET_STATE_ExtendConnectTimer(void);

void GFL_NET_STATE_ConnectMac(struct NetStateWork *work);

void GFL_NET_STATE_StartConnectMac(void);

void GFL_NET_STATE_ConnectMacAddress(int mac, int anyParent);

void GFL_NET_STATE_BeaconScanIdle(void);

void GFL_NET_STATE_StartBeaconScan(void);

void GFL_NET_STATE_BeaconScan(void);

u32 GFL_NET_STATE_Main(void);

void GFL_NET_STATE_ParentConnected(void);

void GFL_NET_STATE_ParentWait(void);

int GFL_NET_STATE_ParentConnectCallback(void);

void GFL_NET_STATE_StartParent(void);

void GFL_NET_STATE_ChangeParentWait(int heapId);

void GFL_NET_STATE_InitParent(u32 unused);

u32 GFL_NET_STATE_GetChildWaitTime(struct NetStateWork *work);

u32 GFL_NET_STATE_GetParentWaitTime(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverConnect(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverWaitDevice(void);

void GFL_NET_STATE_ChangeoverStopParent(void);

void GFL_NET_STATE_ChangeoverStopParentRetry(void);

void GFL_NET_STATE_ChangeoverParentConnectWait(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverParentMain(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverParentRestart(struct NetStateWork *work);

int GFL_NET_STATE_ChangeoverParentCallback(void);

void GFL_NET_STATE_ChangeoverStartParent(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverChildNegotiation(void);

void GFL_NET_STATE_ChildNegotiationWait(struct NetStateWork *work);

void GFL_NET_STATE_ParentNegotiationWait(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverChildConnected(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverStopChild(void);

void GFL_NET_STATE_ChangeoverChildMain(struct NetStateWork *work);

void GFL_NET_STATE_ChangeoverChildScan(struct NetStateWork *work);

void GFL_NET_STATE_StartChangeover(u16 unusedArg, u32 initCallback, u8 hasMac);

void GFL_NET_STATE_ChangeoverRestart(struct NetStateWork *work);

void GFL_NET_STATE_ChangeChangeoverMode(u8 mode, u8 hasMac, const void *mac);

void GFL_NET_STATE_ChangeoverStopChildDevice(struct NetStateWork *work);

void GFL_NET_STATE_SetChangeoverMode(u32 mode, u32 hasMac, u8 *mac);

void GFL_NET_STATE_WaitDisconnect(void);

void GFL_NET_STATE_RecvExitCommand(u32 netID, u32 size, u32 data, u32 work, u32 handle);

u32 GFL_NET_STATE_IsExitReady(void);

void GFL_NET_STATE_ExitWait(struct NetStateWork *work);

void GFL_NET_STATE_ExitStopDevice(void);

void GFL_NET_STATE_Exit(u32 exitCallback);

void GFL_NET_STATE_ClearExitFlag(void);


void GFL_NET_STATE_EndDevice(void);

GFLNetSession *GFL_NET_STATE_SetMPMode(int netID, int size, u8 *data, int work);

void GFL_NET_STATE_WifiError(void);

void GFL_NET_STATE_WifiLoggedOut(void);

void GFL_NET_STATE_WifiFatal(void);

void GFL_NET_STATE_WifiErrorWait(void);

void GFL_NET_STATE_WifiStopError(void);

void GFL_NET_STATE_SetWifiErrorCode(struct NetStateWork *work, u32 errorCode);

void GFL_NET_STATE_WifiLoginMain(struct NetStateWork *work);

void GFL_NET_STATE_WifiLoginStart(struct NetStateWork *work);

int GFL_NET_STATE_WifiEnterLogin(int loginTarget);

u32 GFL_NET_STATE_WifiEnterRandomMatch(void);

u32 GFL_NET_STATE_WifiEnterFriendMatch(void);

void GFL_NET_STATE_WifiEnterLoginDefault(void);

int GFL_NET_STATE_GetWifiState(void);

void GFL_NET_STATE_WifiConnected(void);

void GFL_NET_STATE_WifiMatchDisconnect(struct NetStateWork *work);

void GFL_NET_STATE_WifiDisconnect(u32 hasMatch);

void GFL_NET_STATE_WifiDisconnectFinal(void);

int GFL_NET_STATE_IsWifiDisconnectFinal(void);

int GFL_NET_STATE_IsWifiLoginState(void);

int GFL_NET_STATE_IsWifiLoginOrConnected(void);

void GFL_NET_STATE_WifiLogoutWait(struct NetStateWork *work);

void GFL_NET_STATE_WifiLogoutStop(void);

void GFL_NET_STATE_WifiLogout(u32 exitCallback);

void GFL_NET_STATE_WifiMatchWait(struct NetStateWork *work);

void GFL_NET_STATE_WifiMatchStart(void);

void GFL_NET_STATE_WifiStartMatch(void);

void GFL_NET_STATE_SetAutoExit(u8 autoExit);

void GFL_NET_STATE_SetLoginOption(u8 option);

void GFL_NET_STATE_NoProc(void);

u32 GFL_NET_STATE_SetErrorMode(u8 mode);

void GFL_NET_STATE_ClearErrorMode(void);

u32 GFL_NET_STATE_GetErrorMode(void);

void GFL_NET_STATE_SetError(int errorCode, u32 errorArg1, u32 errorArg2, u32 errorArg3);

void GFL_NET_STATE_SetWifiError(void);

u32 GFL_NET_STATE_GetError(void);

void GFL_NET_STATE_FatalError(void);

int GFL_NET_STATE_IsFatalError(void);

int GFL_NET_Exit(void (*a0)(u32));

int GFL_NET_SendToHandle(GFLNetHandle *a, u32 b, u32 c, const void *d);

u32 GFL_NET_GetUserArg(void);

void GFL_NET_CallDeviceReadyFunc(void);

GFLNetSession *GFL_NET_GetSession(void);

GFLNetSession *GFL_NET_GetInitParam(void);

int GFL_NET_IRC_WIRELESS_IsActive(void);

extern struct NetStateWork *_pNetState;

extern const char _FileName[];

extern const char _AssertNetStateNull[];

extern u32 _VBlankCount;

extern const char _AssertMacAlign[];

extern const char _AssertNetTypeWifi[];

extern const char _AssertNetState[];

extern const char _AssertWifiBattleError[];


/*
 * Setter and its tail-call export in net_state.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AD74.c \
 *       --addr 0x0203AD74 --arm --cc 1.1p1
 */
void GFL_NET_STATE_ChangeState(struct NetStateWork *work, void *state, u32 timer)
{
    work->state = state;
    work->timer = timer;
}





























void GFL_NET_STATE_ChangeStateDebug(struct NetStateWork *work, void *state, u32 timer, int line)
{
    GFL_NET_STATE_ChangeState(work, state, timer);
}






























/*
 * One-shot constructor: the singleton must still be NULL (otherwise
 * SAVEDATA_PanicFail(__FILE__, 0xb8, __FILE__)), 0x64 bytes are allocated with
 * the debug allocator, a halfword 0x32 and a byte 1 are set at +0x46 and
 * +0x4c, the embedded object at +0xc is initialised, and the 5-argument
 * delegate GFL_NET_COMMAND_Init is called with four zeros.
 *
 * The fields are written through the global every time -- the second and
 * third uses reload `[r1]` (`ldr r0, [r1]` twice after the store) while the
 * first reuses the allocator's return value in r0 -- which is what
 * `_pNetState->f46 = ...` spells and what a local pointer would not.
 *
 * Parked at MATCH, blocking class: label.  The only unresolved relocation is
 * the call at +0x68
 *   +0068 PC24 GFL_NET_STATE_InitRandom -> unresolved: 0203AE20 (arm, from header) has
 *                                            no witness outside
 *                                            0203AD8C..0203AE20
 * -- the callee 0x0203AE20 sits at the very end of this function's listing
 * extent and this call is its only branch anywhere in the image, so the
 * `label` class has no outside witness.  It graduates for free, with no
 * change to this C, as soon as src/matched/ holds a GFL_NET_STATE_InitRandom entry:
 * the `matched` class then witnesses the site.  GFL_NET_STATE_InitRandom itself is
 * chain-capped on 0x0203F0A8 (see docs/notes/GF_STANDARD_Rand.c.txt), which is
 * why the pair is parked rather than finished here.
 */
void GFL_NET_STATE_InitWork(u32 heapId)
{
    if (_pNetState != 0) {
        SAVEDATA_PanicFail(_FileName, 0xb8, _AssertNetStateNull);
    }
    _pNetState = GFL_HEAP_Alloc(heapId, 0x64, 1, _FileName, 0xb9);
    _pNetState->timer = 0x32;
    _pNetState->parentRetry = 1;
    GFL_NET_STATE_InitRandom(&_pNetState->random);
    GFL_NET_COMMAND_Init(0, 0, 0, 0, heapId);
}






























static inline void MATH_InitRand64(MATHRandContext64 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}






























/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_InitRandom.c  *       --func GFL_NET_STATE_InitRandom --addr 0x0203AE20 --cc 1.1p1 --arm
 *
 * net_state.c RNG seeder.  Mixes the MAC with the RTC date/time and the
 * system word 0x02FFFC3C, seeds GF_STANDARD_RandSeed, draws two words into one
 * u64 seed, and initialises a NitroSDK MATHRandContext64 with the SDK's
 * own MATH_InitRand64 inline (x = seed, mul 0x5D588B656C078965, add
 * 0x269EC3).  Wave 14 closed the 8-byte tail tie of
 * docs/notes/pkt_0203AE20.c.txt: +0x08..+0x14 are two u64 members, not
 * four u32 words, so the constants are stored as u64 pairs.
 */
void GFL_NET_STATE_InitRandom(MATHRandContext64 *context)
{
  struct RTCDate date;
  struct RTCTime time;
  u8 mac[6];
  u32 seed;
  OS_GetMacAddress(mac);
  RTC_GetDateTime(&date, &time);
  seed = ((date.year + ((date.day * (date.month << 8)) << 16)) + (time.hour << 16)) + ((time.minute + time.second) << 24);
  seed = seed + (mac[5] + ((mac[3] << 16) + (mac[4] << 8)));
  seed = seed + _VBlankCount;
  GF_STANDARD_RandSeed(seed);
  {
    u32 randHigh = GF_STANDARD_Rand();
    MATH_InitRand64(context, (((u64) randHigh) << 32) + GF_STANDARD_Rand());
  }
}






























/*
 * Shuts the network down when the transport's +0x74 virtual answers non-zero:
 * tears the tables down, saves the completion callback out of +0x28, drops
 * the context and finally calls the saved callback.  The callback load is
 * scheduled before GFL_HEAP_Free rather than after it and the context is
 * zeroed after that call too - the store-landing-after-the-next-call shape,
 * so the C keeps the callback in a local across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_FreeWork.c \
 *       --func GFL_NET_STATE_FreeWork --addr 0x0203AEEC --cc 1.1p1 --arm
 */
void GFL_NET_STATE_FreeWork(struct NetStateWork *work)
{
    void (*exitCallback)(void);

    if (GFL_NET_GetSession()->ops->isOffline() == 0)
        return;
    GFL_NET_COMMAND_Exit();
    GFL_NET_WM_ICON_EasyEnd();
    GFL_NET_SYSTEM_FreeWork();
    exitCallback = _pNetState->exitCallback;
    GFL_HEAP_Free(_pNetState);
    _pNetState = 0;
    if (exitCallback != 0)
        exitCallback();
}






























/*
 * Closes docs/notes/pkt_0203AF40.c.txt, which parked this at "DIFF, 10
 * concrete bytes" with an r4/r5 end-to-end swap and additionally predicted a
 * MATCH ceiling.  BOTH of those conclusions were wrong.
 *
 * 1. The r4/r5 swap was an artefact of that attempt's declaration order, not
 *    the real residue.  Declaring the two call results in source order
 *    (`s = GFL_NET_GetSession()` then `c = GFL_NET_GetInitParam()`) puts them in r5/r0
 *    exactly as the image does and the swap never appears.  That left a
 *    2-byte residue at +0x54/+0x58, not 10.
 *
 * 2. THE 2-BYTE RESIDUE: the image reloads the +0x2C callback into r1 and
 *    does `blx r1`, where the obvious C reloads into r0.  The tell is the
 *    `bl GFL_NET_GetUserArg` immediately before it whose result looks discarded.
 *    It is not discarded -- it is the callback's ARGUMENT.  Spelling the
 *    field `void (*f2c)(u32)` and writing `p->f2C(GFL_NET_GetUserArg())` pins r0
 *    to the argument, so the function pointer has to land in r1.  EXACT.
 *    This is the same shape src/pending/GFL_NET_STATE_ChangeoverParentConnectWait.c documents for its
 *    own callback ("takes GFL_NET_GetUserArg's return value in r0, which is why
 *    the function pointer is loaded into r1") -- a family idiom, not a
 *    one-off.
 *
 * 3. The note's MATCH-ceiling claim ("0x0203C00C is a data address with no
 *    outside witness") is also wrong: 0x0203C00C has TWENTY pool words
 *    image-wide (layout/data_objects.txt line 207 lists six plus twelve
 *    more) and resolves `literal x20, e.g. 0203B5CC`.  All 7 relocation
 *    sites resolve and the file is EXACT, not MATCH.
 *
 * The permuter was run before the hand fix and found nothing: --mode hill
 * --budget 800 (120 singles tried) and --mode anneal --budget 900 (900
 * compiles in 84s) both stayed flat at asm=10 bytes-out=2.  The lever is a
 * change to a function-pointer's SIGNATURE (arity), which is outside the
 * mutation table -- the same class of miss the permuter.md field reports
 * record for `cnt = *p++` and `int weight`.
 */
void GFL_NET_STATE_DeviceInitialized(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();

    if (pNetIni->init.bNetType != 1 && pNetIni->init.bNetType != 2)
        session->ops->setup(pNetIni->init.heapId, session, 0, session->userArg);
    GFL_NET_SYSTEM_ResetAll();
    if (work->initCallback != 0) {
        work->initCallback(GFL_NET_GetUserArg());
        work->initCallback = 0;
    }
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_Idle, 0, 0x12f);
}

























void GFL_NET_STATE_DeviceInitialize(void *heapId, u32 initCallback)
{
    UI_SetKeepAwakeFlagsGlobal(4);
    GFL_NET_STATE_InitWork((u32)heapId);
    _pNetState->initCallback = (void (*)(u32))initCallback;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_DeviceInitialized, 0, 0x13F);
}






























/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203B018.c \
 *       --addr 0x0203B018 --arm
 *
 * net_state.c.  GFL_NET_STATE_ConnectMacDone is the 4-byte `bx lr` no-op that
 * GFL_NET_STATE_ConnectMac hands to GFL_NET_SYSTEM_ConnectToParent as its completion callback (the
 * pool word at 0x0203B080 is its only referrer).  GFL_NET_STATE_ExtendConnectTimer is the
 * unlabelled leaf that bumps the state record's +0x46 countdown by 0x3C;
 * GFL_NET_STATE_ChangeoverConnect names it through a pool word.  Filing both here gives the
 * `matched` class a witness for each (docs/families/net_state.h, THE REPORT
 * TAG RULE, "the two genuine exceptions").
 *
 * Integrator: seed 0x0203B01C arm (member of this unit, no label).
 */
void GFL_NET_STATE_ConnectMacDone(void)
{
}






























void GFL_NET_STATE_ExtendConnectTimer(void)
{
    _pNetState->timer += 0x3c;
}






























/*
 *           resolved.  Adding the symbols: block (it had none) let
 *           0x0203B01C resolve as `literal x8, e.g. 0203B43C`; previously it
 *           reported "no address for '(void *)GFL_NET_STATE_ExtendConnectTimer'".  The ONE remaining
 *           site is 0x0203B018.
 * PARKED AT MATCH.  Every concrete byte is right (76 of 76) and the file is
 * the right size; the one open site is the ABS32 to 0x0203B018, the bare
 * `bx lr` filler word that sits between GFL_NET_STATE_DeviceInitialize's literal pool and the
 * unlabelled leaf at 0x0203B01C.  That address has no label (a prologue that
 * saves no `lr` is never auto-labelled) and the word appears in exactly one
 * literal pool image-wide - this function's own - so neither `label` nor
 * `literal` can attest it.
 *           referenced by exactly ONE word image-wide, the pool word at
 *           0x0203B080 (grep of asm/ finds it in main.s and the four unit
 *           listings, all the same address), and 0x0203B080 lies inside this
 *           function's own compared range 0203B038..0203B084.  `label`
 *           refuses (a `bx lr` saves no lr so disasm.py never labels it),
 *           `literal` refuses (no second occurrence outside the range) and
 *           `sole-ref/code` refuses (not a traced function start).  Blocking
 *           class: none available, own-pool-only code.  It would unstick if a
 *           future EXACT entry covered 0x0203B018 itself, but that address is
 *           outside pkt_0203B038's range (0x0203B038..0x0203B084).
 *
 * Both 0x0203B018 and 0x0203B01C must be declared in the symbols: block:
 * written as plain integer literals the pair folds into one pool word plus a
 * `sub r1, r4, #4`, which is four bytes short of the original's two words.
 * 0x0203B01C resolves as `literal x10`; only the no-op word does not.
 *
 * The call's completion callback is the leaf at 0x0203B01C (bumps the +0x46
 * halfword by 0x3C); the report's identifier is the no-op at 0x0203B018.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_STATE_ConnectMac.c \
 *       --func GFL_NET_STATE_ConnectMac --addr 0x0203B038 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ConnectMac(struct NetStateWork *work)
{
    if (GFL_NET_SYSTEM_ConnectToParent(0, (u32)work->aMacAddress, 0x200, (u32)(void *)GFL_NET_STATE_ExtendConnectTimer) != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ConnectMacDone, 0xA, 0x169);
}





























/*
 * Starts a 0x200-byte transfer over channel 1 and reports at line 0x17C
 * (380) when it answers zero.  The report site names GFL_NET_STATE_ConnectMac, the
 * sibling entry that put the read in flight.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_StartConnectMac.c \
 *       --func GFL_NET_STATE_StartConnectMac --addr 0x0203B084 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_StartConnectMac(void)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_SYSTEM_StartBeaconScan(1, 0x200) != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ConnectMac, 0, (int)0x17C);
}





























void GFL_NET_STATE_ConnectMacAddress(int mac, int anyParent)
{
    if ((int)_pNetState->aMacAddress & 1) {
        SAVEDATA_PanicFail(_FileName, 395, _AssertMacAlign);
    }
    if (mac != 0) {
        MI_CpuCopy8((void *)mac, _pNetState->aMacAddress, 6);
    }
    if (anyParent != 0) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_StartConnectMac, 0, 400);
    } else {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ConnectMac, 0, 403);
    }
}





























void GFL_NET_STATE_BeaconScanIdle(void)
{
}






























/*
 * The same 0x200-byte channel-1 start as GFL_NET_STATE_StartConnectMac with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_StartBeaconScan.c \
 *       --func GFL_NET_STATE_StartBeaconScan --addr 0x0203B170 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_StartBeaconScan(void)
{
    if (GFL_NET_SYSTEM_StartBeaconScan(1, 0x200) != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_BeaconScanIdle, 0, 0x1AE);
}






























/*
 * Tail-call wrapper over GFL_NET_STATE_ChangeStateDebug (the object at 0x021469DC, the
 * callback GFL_NET_STATE_StartBeaconScan, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for GFL_NET_BeaconScanStart (state 10 of GFL_NET_IRC_WIRELESS_Main).
 */
void GFL_NET_STATE_BeaconScan(void)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, GFL_NET_STATE_StartBeaconScan, 0, 0x1BC);
}




























u32 GFL_NET_STATE_Main(void)
{
    struct NetStateWork *work = _pNetState;

    if (work == 0)
        return 1;
    if (work->state != 0)
        work->state(work);
    if (_pNetState == 0)
        return 1;
    GFL_NET_STATE_NoProc();
    return 0;
}




























void GFL_NET_STATE_ParentConnected(void)
{
}




























void GFL_NET_STATE_ParentWait(void)
{
}



























int GFL_NET_STATE_ParentConnectCallback(void)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, GFL_NET_STATE_ParentConnected, 0, 0x1f4);
    return 1;
}



























/*
 * Starts a 0x200-entry transfer over channel 1 and reports through
 * GFL_NET_STATE_ChangeStateDebug at line 517 when the start call answers zero.  The line comes
 * out as `add r3, r4, #5` because r4 already holds the 0x200 argument, the
 * same constant-rematerialisation the consecutive-`__LINE__` idiom records.
 *
 * Both callback addresses (0x0203B22C and 0x0203B228, the two `bx lr` filler
 * words in the pool of GFL_NET_STATE_Main) are declared as symbols: written as
 * plain integer literals this compiler folds the pair into one pool word plus
 * a `sub r1, r4, #4`, which is four bytes short of the original's two pool
 * words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_StartParent.c \
 *       --func GFL_NET_STATE_StartParent --addr 0x0203B258 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_StartParent(void)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_SYSTEM_StartParent(1, 0x200, 1, (u32)(void *)GFL_NET_STATE_ParentConnectCallback) != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ParentWait, 0, 0x205);
}


























void GFL_NET_STATE_ChangeParentWait(int heapId)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ParentWait, 0, 0x214);
}



























void GFL_NET_STATE_InitParent(u32 unused)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, GFL_NET_STATE_StartParent, 0, 0x222);
}



























u32 GFL_NET_STATE_GetChildWaitTime(struct NetStateWork *work)
{
    u32 randHigh;
    u64 randNext = work->random.mul * work->random.x + work->random.add;
    work->random.x = randNext;
    randHigh = (u32)(randNext >> 32);
    return (u32)(((u64)randHigh * 40) >> 32) + 0x3c;
}



























u32 GFL_NET_STATE_GetParentWaitTime(struct NetStateWork *work)
{
    u32 randHigh;
    u64 randNext = work->random.mul * work->random.x + work->random.add;
    work->random.x = randNext;
    randHigh = (u32)(randNext >> 32);
    return (u32)(((u64)randHigh * 32) >> 32) + 0xb4;
}



























/*
 * Closes the residue docs/notes/pkt_0203B390.c.txt recorded ("DIFF, one
 * instruction": `mov r0, #1` hoisted above the `beq` in the original but
 * left inside the alt block in every spelling that note tried).  The note
 * was looking at the wrong constant.  What the original hoists is not the
 * `1`, it is the 0x200 -- `mov r4, #0x200` at +0x24, before the compare
 * chain -- and r4 then serves FOUR uses: the length argument of
 * GFL_NET_SYSTEM_ConnectToParent, the second argument of GFL_NET_SYSTEM_StartBeaconScan on the alt path, and
 * the base of both line numbers (`add r3, r4, #0x45` = 0x245 and
 * `add r3, r4, #0x4a` = 0x24A).  Binding it to ONE local `u32 n = 0x200;`
 * declared before the guards gives it a live range that spans both arms,
 * which is what pins it in r4 and frees r0 for the literal `1` to be
 * materialised in the pre-branch block.  The note's experiment of making
 * `one` a local was the right technique applied to the wrong value.
 *
 * EXACT on the first compile with that change; no permuter search needed.
 */
void GFL_NET_STATE_ChangeoverConnect(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u32 scanParam = 0x200;

    if (session->ops->isIdle() == 0)
        return;
    if (work->changeoverHasMac == 0 || work->changeoverMode == 1)
        goto alt;

    if (GFL_NET_SYSTEM_ConnectToParent(1, (u32)work->changeoverMac, scanParam, (u32)GFL_NET_STATE_ExtendConnectTimer) == 0)
        return;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverChildMain, GFL_NET_STATE_GetChildWaitTime(work), scanParam + 0x45);
    return;

alt:
    if (GFL_NET_SYSTEM_StartBeaconScan(1, scanParam) == 0)
        return;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverChildMain, GFL_NET_STATE_GetParentWaitTime(work), scanParam + 0x4a);
}




























/*
 * Reports at line 0x25D (605) when the transport's +0x78 virtual answers
 * non-zero.  The condition is the negated guard - the `pop` is on the equal
 * arm - so the C is the report inside a `!= 0` if, not a return.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverWaitDevice.c \
 *       --func GFL_NET_STATE_ChangeoverWaitDevice --addr 0x0203B448 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverWaitDevice(void)
{
    if (GFL_NET_GetSession()->ops->isIdle() != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverConnect, 0, (int)0x25D);
}




























/*
 * The same +0x10 virtual call as GFL_NET_STATE_ChangeoverStopParentRetry, reporting at line 0x265
 * (613).  Both the first call argument and the reported line derive from the
 * single 1 that the function materialises, which is what makes the line come
 * out as `add r3, r5, #0x264`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopParent.c \
 *       --func GFL_NET_STATE_ChangeoverStopParent --addr 0x0203B48C --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverStopParent(void)
{
    if (GFL_NET_GetSession()->ops->stepDisconnect(1, 0) != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverWaitDevice, 0, 0x265);
}




























/*
 * Calls the transport's +0x10 virtual with (1, 0) and reports at line 0x282
 * (642) when it answers non-zero.  The zero argument and the report's third
 * argument are the same `mov r4, #0` local, which is what puts the two
 * together in one register.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopParentRetry.c \
 *       --func GFL_NET_STATE_ChangeoverStopParentRetry --addr 0x0203B4DC --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverStopParentRetry(void)
{
    if (GFL_NET_GetSession()->ops->stepDisconnect(1, 0) != 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverConnect, 0, (int)0x282);
}



























/*
 * Wave 14: the "unresolvable" second tag site was a misread.  The pool word
 * at 0x0203B5CC (+0xA0) is 0x0203C00C (bytes 0c c0 03 02), not 0x0203B40C;
 * 0x0203C00C is the same tag GFL_NET_STATE_DeviceInitialized passes and resolves `literal`.
 * The first tag, 0x0203B4DC, resolves `matched` (src/matched/GFL_NET_STATE_ChangeoverStopParentRetry.c).
 * The callback takes GFL_NET_GetUserArg's result in r0, which is why the
 * function pointer is loaded into r1 (docs/families/net_state.h, THE
 * CALLBACK ARITY RULE).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverParentConnectWait.c \
 *       --func GFL_NET_STATE_ChangeoverParentConnectWait --addr 0x0203B52C --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverParentConnectWait(struct NetStateWork *work)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_SYSTEM_IsError() != 0)
        return;
    if (GFL_NET_SYSTEM_GetChildBitmap() == 0) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStopParentRetry, 0, 0x297);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() == 0)
        return;
    if (GFL_NET_HANDLE_CheckNegotiation() == 0)
        return;
    if (work->initCallback != 0) {
        work->initCallback(GFL_NET_GetUserArg());
        work->initCallback = 0;
    }
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_Idle, 0, 0x2a6);
}
























void GFL_NET_STATE_ChangeoverParentMain(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (GFL_NET_SYSTEM_GetChildBitmap() != 0) {
        GFL_NET_STATE_ChangeParentWait(GFL_NET_GetInitParam()->init.heapId);
        GFL_NET_CallDeviceReadyFunc();
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverParentConnectWait, 0, 0x2c1);
        return;
    }
    if (work->changeoverMode == 1)
        return;
    if (session->ops->hasBeaconBeenSent(0) == 0)
        return;
    if (work->timer != 0) {
        work->timer--;
        return;
    }
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStopParent, 0, 0x2d3);
}
























void GFL_NET_STATE_ChangeoverParentRestart(struct NetStateWork *work)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverParentMain, GFL_NET_STATE_GetParentWaitTime(work), 0x2e0);
}
























int GFL_NET_STATE_ChangeoverParentCallback(void)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverParentMain, GFL_NET_STATE_GetParentWaitTime(_pNetState), 0x2E6);
    return 1;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStartParent.c \
 *       --func GFL_NET_STATE_ChangeoverStartParent --addr 0x0203B6EC --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverStartParent(struct NetStateWork *work)
{
    if (GFL_NET_GetSession()->ops->isIdle() == 0)
        return;
    if (GFL_NET_SYSTEM_StartParent(0, 0x200, 0, (u32)GFL_NET_STATE_ChangeoverParentCallback) == 0)
        return;

    work->parentRetry = 0;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverParentRestart, 0x1E, 0x2FC);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildNegotiation.c \
 *       --func GFL_NET_STATE_ChangeoverChildNegotiation --addr 0x0203B758 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverChildNegotiation(void)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_HANDLE_CheckNegotiation() == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChildNegotiationWait, 0, 0x30E);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChildNegotiationWait.c \
 *       --func GFL_NET_STATE_ChildNegotiationWait --addr 0x0203B794 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChildNegotiationWait(struct NetStateWork *work)
{
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();

    if (GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle()) == 0)
        return;

    if (work->initCallback != 0) {
        work->initCallback(GFL_NET_GetUserArg());
        work->initCallback = 0;
    }

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_Idle, 0, 0x325);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ParentNegotiationWait.c \
 *       --func GFL_NET_STATE_ParentNegotiationWait --addr 0x0203B7F8 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ParentNegotiationWait(struct NetStateWork *work)
{
    GFL_NET_GetInitParam();

    GFL_NET_HANDLE_GetNetHandle(0xFF);
    GFL_NET_HANDLE_GetCurrentHandle();
    if (GFL_NET_HANDLE_GetNegotiationNum() < 2)
        return;

    GFL_NET_SYSTEM_GetCurrentAid();

    if (work->initCallback != 0) {
        work->initCallback(GFL_NET_GetUserArg());
        work->initCallback = 0;
    }

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_Idle, 0, 0x33F);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildConnected.c \
 *       --func GFL_NET_STATE_ChangeoverChildConnected --addr 0x0203B868 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverChildConnected(struct NetStateWork *work)
{
    GFL_NET_GetInitParam();

    if (GFL_NET_GetSession()->ops->getGgid() != 1)
        return;
    if (GFL_NET_HANDLE_CheckNegotiation() == 0)
        return;

    if (GFL_NET_IRC_WIRELESS_IsActive() == 1) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ParentNegotiationWait, 0, 0x354);
        return;
    }

    if (work->initCallback != 0) {
        work->initCallback(GFL_NET_GetUserArg());
        work->initCallback = 0;
    }

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_Idle, 0, 0x35B);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopChild.c \
 *       --func GFL_NET_STATE_ChangeoverStopChild --addr 0x0203B90C --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverStopChild(void)
{
    if (GFL_NET_GetSession()->ops->isIdle() == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStartParent, 0, 0x371);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildMain.c \
 *       --func GFL_NET_STATE_ChangeoverChildMain --addr 0x0203B950 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverChildMain(struct NetStateWork *work)
{
    if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverChildNegotiation, 0, 0x383);
        return;
    }

    if (work->changeoverMode == 2)
        return;

    if (work->timer != 0) {
        work->timer--;
        return;
    }

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStopChildDevice, 0, 0x390);
    GFL_NET_STATE_ChangeoverStopChildDevice(work);
}
























/*
 * A frame's 64-bit accumulator advanced by a 64-bit multiply: the pair at
 * +0x0c (little-endian u64) is multiplied by the pair at +0x14, the pair at
 * +0x1c is added in, both halves are stored back, and the new high half is
 * re-scaled by 30/2^32 into the u16 countdown at +0x46.
 *
 * Two spellings are load-bearing.  The multiply has to be written `y * x`
 * with x at +0x0c and y at +0x14: the other order loads +0x0c first and
 * swaps two `ldr`s.  And the addend has to stay inline in the multiply's own
 * statement (`r = y * x + *(u64 *)(p + 0x1c);`) with the low half stored by
 * a single 64-bit store: with a named addend and two u32 stores mwcc puts
 * the sum's low half in `ip` and the high half in `r2`, a five-instruction
 * difference in register choice alone.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildScan.c \
 *       --func GFL_NET_STATE_ChangeoverChildScan --addr 0x0203B9D4 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverChildScan(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u64 seedState, multiplier, nextState;

    if (session->ops->getTgid() == 1) {
        session->ops->forceReset();
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverChildConnected, 0, 0x3A5);
        return;
    }

    if (work->timer != 0) {
        work->timer = work->timer - 1;
        return;
    }

    seedState = work->random.x;
    multiplier = work->random.mul;
    nextState = multiplier * seedState + work->random.add;

    work->timer = (u16)((u32)(((u64)(u32)(nextState >> 32) * 30) >> 32) + 15);
    work->random.x = nextState;

    session->ops->begin(0);
}
























void GFL_NET_STATE_StartChangeover(u16 unusedArg, u32 initCallback, u8 hasMac)
{
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();
    struct NetStateWork *work;
    u64 seedState, multiplier, nextState;
    u32 delay = 30;

    GFL_NET_GetSession();
    GFL_NET_STATE_ChangeChangeoverMode(0, hasMac, 0);

    if (pNetIni->init.bNetType == 3 || pNetIni->init.bNetType == 4) {
        GFL_NET_SYSTEM_ConnectDevice(0);
        _pNetState->initCallback = (void (*)(u32))initCallback;
        work = _pNetState;
        seedState = work->random.x;
        multiplier = work->random.mul;
        nextState = multiplier * seedState + work->random.add;
        work->random.x = nextState;
        GFL_NET_STATE_ChangeStateDebug(work, (void *)GFL_NET_STATE_ChangeoverChildScan, (u32)(((u64)(u32)(nextState >> 32) * delay) >> 32), delay + 0x3A8);
    } else {
        work = _pNetState;
        if (work->changeoverHasMac != 0 && work->changeoverMode != 1) {
            GFL_NET_SYSTEM_ConnectToParent(1, (u32)work->changeoverMac, 0x200, (u32)GFL_NET_STATE_ExtendConnectTimer);
        } else {
            GFL_NET_SYSTEM_StartBeaconScan(1, 0x200);
        }
        _pNetState->initCallback = (void (*)(u32))initCallback;
        work = _pNetState;
        GFL_NET_STATE_ChangeStateDebug(work, (void *)GFL_NET_STATE_ChangeoverChildMain, delay, delay + 0x3B4);
    }
}

























/*
 * Two presets that differ only in the state byte they match and the handler
 * they advertise.  Each test is a conjunction of the state byte and the
 * eight-byte pointer stored beside it, and the first arm also refuses when
 * the vtable's +0x10 hook answers zero.
 *
 * The four code addresses are declared as the functions they are: written as
 * integer literals the front end folds two nearby ones into one pool word plus
 * a `sub`, which is four bytes shorter than the original.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverRestart.c \
 *       --func GFL_NET_STATE_ChangeoverRestart --addr 0x0203BBB0 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverRestart(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    struct NetStateWork *netState;

    netState = _pNetState;
    if (netState->changeoverMode == 2 && netState->state == GFL_NET_STATE_ChangeoverChildMain) {
        if (session->ops->stepDisconnect(1, 0) != 0) {
            GFL_NET_STATE_ChangeStateDebug(_pNetState, ((void *)GFL_NET_STATE_ChangeoverStopChild), 0, 0x3E0);
        }
    }

    netState = _pNetState;
    if (netState->changeoverMode == 1 && netState->state == GFL_NET_STATE_ChangeoverParentMain) {
        GFL_NET_STATE_ChangeStateDebug(netState, ((void *)GFL_NET_STATE_ChangeoverStopParent), 0, 0x3E9);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeChangeoverMode.c \
 *       --func GFL_NET_STATE_ChangeChangeoverMode --addr 0x0203BC58 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeChangeoverMode(u8 mode, u8 hasMac, const void *mac)
{
    GFL_NET_GetSession();
    _pNetState->changeoverHasMac = hasMac;
    _pNetState->changeoverMode = mode;

    if (mac != 0) {
        MI_CpuCopy8(mac, _pNetState->changeoverMac, 6);
    } else {
        MI_CpuFill8(_pNetState->changeoverMac, 0xFF, 6);
    }

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverRestart, 0, 0x406);
    GFL_NET_STATE_ChangeoverRestart(_pNetState);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopChildDevice.c \
 *       --func GFL_NET_STATE_ChangeoverStopChildDevice --addr 0x0203BCE0 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ChangeoverStopChildDevice(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->ops->stepDisconnect(1, 0) == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStopChild, 0, 0x411);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetChangeoverMode.c \
 *       --func GFL_NET_STATE_SetChangeoverMode --addr 0x0203BD30 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_SetChangeoverMode(u32 mode, u32 hasMac, u8 *mac)
{
    GFL_NET_GetSession();

    _pNetState->changeoverHasMac = (u8)hasMac;
    _pNetState->changeoverMode = (u8)mode;

    if (mac != 0)
        MI_CpuCopy8(mac, _pNetState->changeoverMac, 6);
    else
        MI_CpuFill8(_pNetState->changeoverMac, 0xFF, 6);

    if (_pNetState->changeoverMode == 2)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStopParent, 0, 0x430);

    if (_pNetState->changeoverMode == 1) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ChangeoverStopChildDevice, 0, 0x438);
        GFL_NET_STATE_ChangeoverStopChildDevice(_pNetState);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WaitDisconnect.c \
 *       --func GFL_NET_STATE_WaitDisconnect --addr 0x0203BDEC --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WaitDisconnect(void)
{
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();
    GFLNetSession *session = GFL_NET_GetSession();

    if ((u8)(pNetIni->init.bNetType + 0xFD) <= 1) {
        if (session->ops->getTgid() != 0)
            return;
        GFL_NET_Exit(0);
    } else {
        GFLNetSession *rssiSession = GFL_NET_GetSession();

        if ((rssiSession->ops->getAidBitmap() & 0xFFFE) != 0)
            return;
        GFL_NET_Exit(0);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_RecvExitCommand.c \
 *       --func GFL_NET_STATE_RecvExitCommand --addr 0x0203BE5C --cc 1.1p1 --arm
 */
void GFL_NET_STATE_RecvExitCommand(u32 netID, u32 size, u32 data, u32 work, u32 handle)
{
    GFL_NET_SendToHandle((void *)handle, 2, 0, 0);

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WaitDisconnect, 0, 0x46C);
}


























/*
 * "If the state is non-zero, park the card interface."  The result of the
 * test is kept in a local and returned, so the zero path is the `popeq` that
 * gives back r0 == 0 and the busy path returns whatever GFL_NET_Exit leaves
 * in r0 - no second `mov r0, #0` anywhere.
 *
 * The local is load-bearing: spelling it `if (GFL_NET_SYSTEM_GetCurrentAid() == 0) return 0;
 * return GFL_NET_Exit(0);` hoists the `mov r0, #0` that sets up the call's
 * argument above the conditional return and lands two instructions late.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_IsExitReady.c \
 *       --func GFL_NET_STATE_IsExitReady --addr 0x0203BEAC --cc 1.1p1 --arm
 */
u32 GFL_NET_STATE_IsExitReady(void)
{
    u32 result;

    result = GFL_NET_SYSTEM_GetCurrentAid();
    if (result != 0)
        result = GFL_NET_Exit(0);
    return result;
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ExitWait.c \
 *       --func GFL_NET_STATE_ExitWait --addr 0x0203BEC8 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ExitWait(struct NetStateWork *work)
{
    GFLNetSession *session;

    GFL_NET_GetInitParam();
    session = GFL_NET_GetSession();

    if (session->ops->isIdle() != 0) {
        if (session->ops->cleanup(0) == 0)
            return;
        GFL_NET_STATE_FreeWork(work);
        return;
    }

    if (session->ops->isActive() != 0)
        return;
    if (session->ops->cleanup(0) == 0)
        return;
    GFL_NET_STATE_FreeWork(work);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ExitStopDevice.c \
 *       --func GFL_NET_STATE_ExitStopDevice --addr 0x0203BF4C --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ExitStopDevice(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (session->ops->stepDisconnect(1, 0) == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_ExitWait, 0, 0x4A4);
}


























/*
 * 116 bytes, three functions: the setter, the 28-byte leaf that clears the
 * same flag, and the four-byte `bx lr` stub the card task is handed as a
 * callback (src/pending/GFL_NET_STATE_EndDevice.c passes it at 0x0203C00C).
 *
 * The two leaves carry no label in the generated listing - neither saves `lr`
 * - so this range used to stop at 0x0203BF9C with an `EXACT*`, the inferred
 * extent running on to the next labelled function at 0x0203C010.  Writing
 * them as the unit's own functions is what closes the range.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203BF9C.c \
 *       --addr 0x0203BF9C --arm --cc 1.1p1
 */
void GFL_NET_STATE_Exit(u32 exitCallback)
{
    struct NetStateWork *work = _pNetState;

    if (work != 0 && work->exitRequested != 0)
        return;

    work->exitCallback = (void (*)(void))exitCallback;
    _pNetState->exitRequested = 1;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, ((void *)GFL_NET_STATE_ExitStopDevice), 5, 0x4B7);
}


























void GFL_NET_STATE_ClearExitFlag(void)
{
    if (_pNetState != 0)
        _pNetState->exitRequested = 0;
}


























void GFL_NET_STATE_Idle(void)
{
}























/*
 * PROMOTED FROM src/pending/ AT THE END OF WAVE 4 LANE 0x02038000..0x02040000.
 * It was parked at MATCH with every concrete byte right, held there only by
 * the `bl` to 0x020379C8, which nothing outside this range witnessed.  That
 * address has since been matched, so the site now resolves on the `matched`
 * class and the whole 52 bytes are EXACT with no change to the C at all.
 *
 * The callback stub this file passes, 0x0203C00C, is matched as well now, as
 * the last function of src/matched/unit_0203BF9C.c.
 *
 * Allocates 0x200 bytes, then starts the card task on the object at
 * 0x021469DC with the four-byte `bx lr` stub at 0x0203C00C as its callback and
 * 0x4DA (1242) as the fourth argument - the source file/line pair of an assert
 * style entry point.  The stub is a real 4-byte ARM function in the listing, so
 * its address is declared as the function it is and passed as a function
 * pointer; the pool word for it is attested by a dozen other pools elsewhere
 * in the image, and unk_021469DC likewise.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_STATE_EndDevice.c \
 *       --func GFL_NET_STATE_EndDevice --addr 0x0203C010 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_EndDevice(void)
{
    GFL_NET_SYSTEM_EndDevice(0x200);
    GFL_NET_STATE_ChangeStateDebug(_pNetState, GFL_NET_STATE_Idle, 0, 0x4DA);
}























GFLNetSession *GFL_NET_STATE_SetMPMode(int netID, int size, u8 *data, int work)
{
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();

    pNetIni->init.bMPMode = *data;
    return pNetIni;
}






















/*
 * Empty callback (a lone bx lr), one of three adjacent stubs at
 * 0x0203C05C/60/64 whose addresses GFL_NET_STATE_WifiLoginMain, GFL_NET_STATE_GetWifiState,
 * GFL_NET_STATE_WifiMatchDisconnect and GFL_NET_STATE_WifiMatchWait pass or compare as handler pointers.
 */
void GFL_NET_STATE_WifiError(void)
{
}






















void GFL_NET_STATE_WifiLoggedOut(void)
{
}






















void GFL_NET_STATE_WifiFatal(void)
{
}























/*
 * Calls the virtual at +0xC of the object at *(net context + 0x340) with a
 * zero argument and reports through GFL_NET_STATE_ChangeStateDebug when it answers a negative
 * result.  The `mov r4, #0` local is what feeds both the call's r0 and the
 * report's r2, hence its placement; the `popge` is the `>= 0` half of the
 * signed comparison.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiErrorWait.c  *       --func GFL_NET_STATE_WifiErrorWait --addr 0x0203C068 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiErrorWait(void)
{
    if (GFL_NET_GetSession()->ops->update(0) < 0)
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiError, 0, (int)0x52C);
}






















void GFL_NET_STATE_WifiStopError(void)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFL_NET_SYSTEM_SetNoChildError(1);
    session->ops->update(0);
}























/*
 * Stores one byte at +0x4E, negating it first unless it is 1005 or 1006.  The
 * threshold is written `v - 1005 > 1`, and 1005 is not encodable as an ARM
 * immediate in a `sub`, so mwcc builds it the other way round: `mvn r2, #1004`
 * is -1005 and one `add` finishes the subtraction.  The comparison is
 * unsigned (`rsbhi`), and the negation is `rsb r1, r1, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetWifiErrorCode.c \
 *       --func GFL_NET_STATE_SetWifiErrorCode --addr 0x0203C0DC --cc 1.1p1 --arm
 */
void GFL_NET_STATE_SetWifiErrorCode(struct NetStateWork *work, u32 errorCode)
{
    if (errorCode - 1005 > 1)
        errorCode = -errorCode;
    work->wifiErrorCode = (u8)errorCode;
}






















void GFL_NET_STATE_WifiLoginMain(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetModeOps *ops = session->ops;
    s32 result = ops->update(0);

    if (result == 1000) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiStopError, 0, 1403);
        return;
    }

    ops = session->ops;
    if (ops->getTgid() != 0) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiStopError, 0, 1407);
        return;
    }

    if (result == 1007) {
        return;
    }

    if (result == 1001) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoggedOut, 0, 1413);
        return;
    }

    if (result == 1002) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiFatal, 0, 1416);
        return;
    }

    if (result >= 10) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiFatal, 0, 1420);
        return;
    }

    if (result >= 0) {
        return;
    }

    GFL_NET_STATE_SetWifiErrorCode(work, result);
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiError, 0, 1424);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiLoginStart.c \
 *       --func GFL_NET_STATE_WifiLoginStart --addr 0x0203C238 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiLoginStart(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();

    if (session->ops->startFriendMatch(work->loginTarget, pNetIni->init.maxConnectNum, 0) != 0)
        return;

    GFL_NET_SYSTEM_ResetAll();
    GFL_NET_HANDLE_ExitWork(session);
    GFL_NET_HANDLE_InitWork(session);
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoginMain, 0, 0x5AC);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiEnterLogin.c \
 *       --func GFL_NET_STATE_WifiEnterLogin --addr 0x0203C2B0 --cc 1.1p1 --arm
 */
int GFL_NET_STATE_WifiEnterLogin(int loginTarget)
{
    if (loginTarget != -1) {
        if (GFL_NET_SYSTEM_SetDeviceOption((u32)loginTarget) == 0)
            return 0;
    }

    _pNetState->loginTarget = loginTarget;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoginStart, 0, 0x5C4);
    return 1;
}


























/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5D9, returning success.  The twin at 0x0203C35C is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiEnterRandomMatch.c  *       --func GFL_NET_STATE_WifiEnterRandomMatch --addr 0x0203C304 --cc 1.1p1 --arm
 */
u32 GFL_NET_STATE_WifiEnterRandomMatch(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    _pNetState->loginTarget = -2;
    GFL_NET_SYSTEM_ResetAll();
    GFL_NET_HANDLE_ExitWork(session);
    GFL_NET_HANDLE_InitWork(session);
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoginMain, 0, (int)0x5D9);
    return 1;
}


























/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5FD, returning success.  The twin at 0x0203C304 is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiEnterFriendMatch.c  *       --func GFL_NET_STATE_WifiEnterFriendMatch --addr 0x0203C35C --cc 1.1p1 --arm
 */
u32 GFL_NET_STATE_WifiEnterFriendMatch(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    _pNetState->loginTarget = -2;
    GFL_NET_SYSTEM_ResetAll();
    GFL_NET_HANDLE_ExitWork(session);
    GFL_NET_HANDLE_InitWork(session);
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoginMain, 0, (int)0x5FD);
    return 1;
}


























void GFL_NET_STATE_WifiEnterLoginDefault(void)
{
    _pNetState->loginTarget = -1;
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoginStart, 0, 0x60d);
}

























/*
 * Unlabelled ARM leaf (saves no register, so disasm.py gives it no func_
 * label): a channel-id classifier that reads the pointer at _pNetState, then
 * the u32 at +8 of the record, and maps five distinct table addresses to
 * 0/1/3/4/5 (anything else returns 2).
 *
 * The five constants sit in their own pool words at 0x0203C450..0x0203C460
 * and are each loaded with `ldr` from pc, so they are link-time absolute
 * (R_ARM_ABS32) values that the compiler cannot fold against one another.
 * They are spelled as the addresses of the matched arm9 functions that live
 * at those addresses, taken as integers, so each becomes its own relocation
 * and no `sub`/constant-fold is possible.
 */
int GFL_NET_STATE_GetWifiState(void)
{
    void *curState = _pNetState->state;

    if (curState == GFL_NET_STATE_WifiLoginMain) {
        return 0;
    }
    if (curState == GFL_NET_STATE_WifiStopError) {
        return 1;
    }
    if (curState == GFL_NET_STATE_WifiErrorWait) {
        return 3;
    }
    if (curState == GFL_NET_STATE_WifiLoggedOut) {
        return 4;
    }
    if (curState == GFL_NET_STATE_WifiFatal) {
        return 5;
    }
    return 2;
}
























void GFL_NET_STATE_WifiConnected(void)
{
    GFL_NET_GetSession();
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLoginMain, 0, 0x637);
}


























/*
 * The other half of the connect/disconnect pair whose partner is
 * src/matched/GFL_NET_STATE_WifiDisconnect.c: it turns the state byte at +0x4B into the
 * vtable's +0x54 hook, then either starts the link layer or, when the +0x0C
 * hook reports a negative result, files line 0x655.
 *
 * `v` is materialised as 0 before the first call and raised to 1 by
 * `moveq` on the state byte's own compare, so the hook's first argument
 * shares a register with the loop's zero rather than being rematerialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiMatchDisconnect.c \
 *       --func GFL_NET_STATE_WifiMatchDisconnect --addr 0x0203C494 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiMatchDisconnect(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    u32 sendMask = 0;

    GFL_NET_SYSTEM_SetNoChildError(0);

    if (work->matchDisconnect == 0)
        sendMask = 1;

    if (session->ops->pollDisconnect(sendMask, 0) != 0) {
        GFL_NET_SYSTEM_ResetAll();
        GFL_NET_HANDLE_ExitWork(session);
        GFL_NET_HANDLE_InitWork(session);
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiConnected, 0, 0x64F);
    } else if (session->ops->update(0) < 0) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiError, 0, 0x655);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiDisconnect.c \
 *       --func GFL_NET_STATE_WifiDisconnect --addr 0x0203C554 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiDisconnect(u32 hasMatch)
{
    struct NetStateWork *work = _pNetState;

    if (work == 0)
        return;

    if (hasMatch != 0) {
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
            _pNetState->matchDisconnect = 0;
        else
            _pNetState->matchDisconnect = 1;
    } else {
        work->matchDisconnect = 0;
    }

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiMatchDisconnect, 0, 0x671);
    GFL_NET_STATE_WifiMatchDisconnect(_pNetState);
}


























/*
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiDisconnectFinal.c \
 *       --func GFL_NET_STATE_WifiDisconnectFinal --addr 0x0203C5C8 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiDisconnectFinal(void)
{
    GFL_NET_STATE_WifiDisconnect(1);
    _pNetState->disconnectFinal = 1;
}


























/*
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 */
int GFL_NET_STATE_IsWifiDisconnectFinal(void)
{
    return _pNetState->disconnectFinal;
}

























/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is GFL_NET_STATE_WifiLoginMain.
 */
int GFL_NET_STATE_IsWifiLoginState(void)
{
    return _pNetState->state == (void *)GFL_NET_STATE_WifiLoginMain;
}

























/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is GFL_NET_STATE_WifiLoginMain or GFL_NET_STATE_WifiConnected.
 */
int GFL_NET_STATE_IsWifiLoginOrConnected(void)
{
    void *curState = _pNetState->state;
    return curState == (void *)GFL_NET_STATE_WifiLoginMain || curState == (void *)GFL_NET_STATE_WifiConnected;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiLogoutWait.c \
 *       --func GFL_NET_STATE_WifiLogoutWait --addr 0x0203C65C --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiLogoutWait(struct NetStateWork *work)
{
    GFLNetSession *session;

    GFL_NET_GetInitParam();
    session = GFL_NET_GetSession();

    session->ops->update(1);

    if (session->ops->isIdle() != 0) {
        session->ops->cleanup(0);
        GFL_NET_STATE_FreeWork(work);
        return;
    }

    if (session->ops->isActive() == 0) {
        session->ops->cleanup(0);
        GFL_NET_STATE_FreeWork(work);
        return;
    }

    if (session->ops->isOffline() == 0)
        return;

    session->ops->cleanup(0);
    GFL_NET_STATE_FreeWork(work);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiLogoutStop.c \
 *       --func GFL_NET_STATE_WifiLogoutStop --addr 0x0203C710 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiLogoutStop(void)
{
    GFLNetSession *session = GFL_NET_GetSession();

    session->ops->update(0);
    if (session->ops->stepDisconnect(1, 0) == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLogoutWait, 0, 0x702);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiLogout.c \
 *       --func GFL_NET_STATE_WifiLogout --addr 0x0203C774 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiLogout(u32 exitCallback)
{
    GFLNetSession *session;

    if (_pNetState == 0)
        return;

    session = GFL_NET_GetSession();
    UI_ClearFlags39Global(1);
    _pNetState->exitCallback = (void (*)(void))exitCallback;
    session->ops->pollDisconnect(1, 0);

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiLogoutStop, 5, 0x719);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiMatchWait.c \
 *       --func GFL_NET_STATE_WifiMatchWait --addr 0x0203C7E0 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiMatchWait(struct NetStateWork *work)
{
    GFLNetSession *session = GFL_NET_GetSession();
    int result = session->ops->update(0);

    if (result < 0) {
        GFL_NET_STATE_SetWifiErrorCode(work, (u32)result);
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiError, 0, 0x72E);
    } else if (result > 0) {
        GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiConnected, 0, 0x737);
    }
}

























/*
 * Promoted from src/pending/ on lane 1.  Every concrete byte is right; the one
 * open site was the `bl` to 0x02037700, whose only branch anywhere in the
 * image is this one, so `label` had no outside witness.  With
 * src/matched/GFL_NET_SYSTEM_InitDevice.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiMatchStart.c \
 *       --func GFL_NET_STATE_WifiMatchStart --addr 0x0203C864 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_WifiMatchStart(void)
{
    GFLNetSession *pNetIni = GFL_NET_GetInitParam();

    if (GFL_NET_SYSTEM_InitDevice(0x200, pNetIni->init.heapId) == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiMatchWait, 0, 0x74A);
}

























/*
 * 140 bytes, three functions.  The middle one, 0x0203C8E8, is a 16-byte leaf
 * that saves nothing and so carries no label in the generated listing; the
 * per-function file for 0x0203C8A8 therefore reported an `EXACT*`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203C8A8.c \
 *       --addr 0x0203C8A8 --arm --cc 1.1p1
 */
void GFL_NET_STATE_WifiStartMatch(void)
{
    if (GFL_NET_SYSTEM_IsDeviceReady() != 0)
        return;

    GFL_NET_GetInitParam();
    UI_SetFlags39Global(1);
    GFL_NET_STATE_ChangeStateDebug(_pNetState, (void *)GFL_NET_STATE_WifiMatchStart, 0, 0x760);
}

























void GFL_NET_STATE_SetAutoExit(u8 autoExit)
{
    if (_pNetState != 0)
        _pNetState->autoExit = autoExit;
}

























void GFL_NET_STATE_SetLoginOption(u8 option)
{
    GFLNetSession *session = GFL_NET_GetSession();

    if (_pNetState != 0)
        _pNetState->loginOption = option;

    session->ops->setWatchDisconnect(option);
}
























void GFL_NET_STATE_NoProc(void){ }

























/*
 * Opens the state: with no live object the answer is 0, otherwise the mode
 * byte at +0x4D is written, the two setup calls run and the answer is 1.
 * src/matched/GFL_NET_STATE_ClearErrorMode.c is the matching close.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetErrorMode.c \
 *       --func GFL_NET_STATE_SetErrorMode --addr 0x0203C938 --cc 1.1p1 --arm
 */
u32 GFL_NET_STATE_SetErrorMode(u8 mode)
{
    struct NetStateWork *work;

    work = _pNetState;
    if (work == 0)
        return 0;
    work->errorMode = mode;
    GFL_NET_SYSTEM_SetError();
    GFL_NET_SYSTEM_SetNoSend();
    return 1;
}

























/*
 * Closes the state src/matched/GFL_NET_STATE_SetErrorMode.c opens: clears the mode byte and
 * runs the teardown call.  With no live object it is a bare `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ClearErrorMode.c \
 *       --func GFL_NET_STATE_ClearErrorMode --addr 0x0203C968 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_ClearErrorMode(void)
{
    struct NetStateWork *work;

    work = _pNetState;
    if (work == 0)
        return;
    work->errorMode = 0;
    GFL_NET_SYSTEM_ResetError();
}

























/*
 * The mode byte src/matched/GFL_NET_STATE_SetErrorMode.c writes, read back - 0 when there
 * is no object.  Both loads are conditional, so the function is two
 * instructions plus the two pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_GetErrorMode.c \
 *       --func GFL_NET_STATE_GetErrorMode --addr 0x0203C990 --cc 1.1p1 --arm
 */
u32 GFL_NET_STATE_GetErrorMode(void)
{
    struct NetStateWork *work;

    work = _pNetState;
    return work ? work->errorMode : 0;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetError.c \
 *       --func GFL_NET_STATE_SetError --addr 0x0203C9AC --cc 1.1p1 --arm
 */
void GFL_NET_STATE_SetError(int errorCode, u32 errorArg1, u32 errorArg2, u32 errorArg3)
{
    if (_pNetState == 0)
        return;

    if ((u32)(errorCode - 0x3ED) > 1)
        errorCode = -errorCode;

    _pNetState->errorInfo.errorCode = errorCode;
    _pNetState->errorInfo.errorType = errorArg1;
    _pNetState->errorInfo.dwcError = errorArg2;
    _pNetState->errorInfo.gameCode = errorArg3;

    if (errorArg3 != 0)
        GFL_NET_SYSTEM_SetError();
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetWifiError.c \
 *       --func GFL_NET_STATE_SetWifiError --addr 0x0203CA04 --cc 1.1p1 --arm
 */
void GFL_NET_STATE_SetWifiError(void)
{
    GFLNetSession *pNetIni;
    u32 isWifiType;

    if (_pNetState == 0)
        return;

    pNetIni = GFL_NET_GetInitParam();

    isWifiType = 0;
    if ((u8)(pNetIni->init.bNetType + 0xFF) <= 5) {
        if (((1 << (u8)(pNetIni->init.bNetType + 0xFF)) & 0x23) != 0)
            isWifiType = 1;
    }

    if (isWifiType == 0)
        SAVEDATA_PanicFail(_FileName, 0x8B7, _AssertNetTypeWifi);

    _pNetState->errorInfo.errorCode = 0;
    _pNetState->errorInfo.errorType = 0;
    _pNetState->errorInfo.dwcError = 0;
    _pNetState->errorInfo.gameCode = 0;
}






















/*
 * Returns the object's work area at +0x30, reporting through SAVEDATA_PanicFail
 * with the source file at 0x020A7BA8 and line 0x8CA (2250) when the object has
 * not been created - the report is not fatal, the address of the null object's
 * field is still what comes back.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_GetError.c \
 *       --func GFL_NET_STATE_GetError --addr 0x0203CA98 --cc 1.1p1 --arm
 */
u32 GFL_NET_STATE_GetError(void)
{
    if (_pNetState == 0)
        SAVEDATA_PanicFail(_FileName, 0x8CA, _AssertNetState);
    return (u32)&_pNetState->errorInfo;
}






















/*
 * Unlabelled ARM assert thunk: tail call SAVEDATA_PanicFail(_FileName, 0x8D8, _AssertWifiBattleError), the fall-through failure path after GFL_NET_STATE_GetError.
 */
void GFL_NET_STATE_FatalError(void)
{
    SAVEDATA_PanicFail(_FileName, 0x8D8, _AssertWifiBattleError);
}






















/*
 * Unlabelled ARM predicate: the card task object exists and its callback at +8 is GFL_NET_STATE_FatalError.
 * MATCH only because 0x0203CADC (GFL_NET_STATE_FatalError.c, EXACT) is not yet a labelled
 * function start: the pool word has no outside witness until the seed lands.
 */
int GFL_NET_STATE_IsFatalError(void)
{
    struct NetStateWork *work = _pNetState;
    if (work != 0 && work->state == (void *)GFL_NET_STATE_FatalError) {
        return 1;
    }
    return 0;
}
