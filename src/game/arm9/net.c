/*
 * file:     net.c
 * unit:     yes
 * function: func_0203CB34, func_0203CBAC, func_0203CD98, func_0203CDBC, func_0203CDD4, func_0203CEAC, func_0203CF04, func_0203CF10, func_0203CF3C, func_0203CF5C, func_0203CFA0, func_0203CFF0, func_0203D000, func_0203D010, func_0203D01C, func_0203D060, func_0203D0AC, func_0203D0B8, func_0203D0C4, func_0203D0D0, func_0203D0DC, func_0203D0FC, func_0203D10C, func_0203D12C, func_0203D14C, func_0203D158, func_0203D164, func_0203D170, func_0203D17C, func_0203D1A4, func_0203D1B4, func_0203D1C0, func_0203D1E8, func_0203D210, func_0203D24C, func_0203D26C, func_0203D29C, func_0203D2CC, func_0203D34C, func_0203D378, func_0203D394, func_0203D3A8, func_0203D3F8, func_0203D4D0, func_0203D56C, func_0203D578, func_0203D594, func_0203D5A0, func_0203D5AC, func_0203D5D4, func_0203D5EC, func_0203D610, func_0203D634, func_0203D644, func_0203D650, func_0203D668, func_0203D680, func_0203D6BC, func_0203D6CC, func_0203D700, func_0203D720, func_0203D754, func_0203D788, func_0203D798, func_0203D7B0, func_0203D7BC, func_0203D7C8, func_0203D7FC, func_0203D814, func_0203D828, func_0203D844, func_0203D864, func_0203D880, func_0203D88C, func_0203D8AC, func_0203D8C4, func_0203D8F0, func_0203D9EC, func_0203DA20, func_0203DA4C, func_0203DA68, func_0203DA7C, func_0203DAC4, func_0203DBB0, func_0203DC04, func_0203DC4C, func_0203DC68, func_0203DC70, func_0203E420, func_0203E458, func_0203E484, func_0203E4E8, func_0203E538, func_0203E590, func_0203E5AC
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
 *   func_02039338   0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039594  0x02039594  arm
 *   func_0203996C   0x0203996C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02034F84  0x02034F84  arm
 *   g_021469E0     0x021469E0  data
 *   file_020A7CA0  0x020A7CA0  data
 *   str_020A7CA8   0x020A7CA8  data
 *   str_020A7CB8   0x020A7CB8  data
 *   str_020A7CE8   0x020A7CE8  data
 *   func_0203064C  0x0203064C  arm
 *   func_0200F17C  0x0200F17C  thumb
 *   func_020306F0  0x020306F0  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_0200F234  0x0200F234  thumb
 *   func_0203EA9C 0x0203EA9C  arm
 *   func_020338F8  0x020338F8  arm
 *   g_020A7CEC     0x020A7CEC  data
 *   func_02039CA0  0x02039CA0  arm
 *   file_020A7CF8  0x020A7CF8  data
 *   file_020A7D2C  0x020A7D2C  data
 *   g_021469F0     0x021469F0  data
 *   file_020A7D34     0x020A7D34  data
 *   str_020A7D48  0x020A7D48  data
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   str_020A7D4C  0x020A7D4C  data
 *   s_020A7D68      0x020A7D68  data
 *   func_02037010 0x02037010 arm
 *   func_020370C8 0x020370C8 arm
 *   func_02037118 0x02037118 arm
 *   func_02037154 0x02037154 arm
 *   func_020371AC 0x020371AC arm
 *   func_02037A44 0x02037A44 arm
 *   func_02037C10 0x02037C10 arm
 *   func_02038C18 0x02038C18 arm
 *   func_02039414 0x02039414 arm
 *   func_02039468 0x02039468 arm
 *   func_020394C0 0x020394C0 arm
 *   func_020394F0 0x020394F0 arm
 *   func_020395EC 0x020395EC arm
 *   func_02039834 0x02039834 arm
 *   func_020398B4 0x020398B4 arm
 *   func_020399B8 0x020399B8 arm
 *   func_020399EC 0x020399EC arm
 *   func_02039ACC 0x02039ACC arm
 *   func_02039C3C 0x02039C3C arm
 *   func_02039D94 0x02039D94 arm
 *   func_0203A458 0x0203A458 arm
 *   func_0203A494 0x0203A494 arm
 *   func_0203AFCC 0x0203AFCC arm
 *   func_0203B0C4 0x0203B0C4 arm
 *   func_0203B1B0 0x0203B1B0 arm
 *   func_0203B1D8 0x0203B1D8 arm
 *   func_0203B2D0 0x0203B2D0 arm
 *   func_0203BA98 0x0203BA98 arm
 *   func_0203BD30 0x0203BD30 arm
 *   func_0203BF9C 0x0203BF9C arm
 *   func_0203BFF0 0x0203BFF0 arm
 *   func_0203C010 0x0203C010 arm
 *   func_0203C3B4 0x0203C3B4 arm
 *   func_0203C774 0x0203C774 arm
 *   func_0203C8E8 0x0203C8E8 arm
 *   func_0203C900 0x0203C900 arm
 *   func_0203C938 0x0203C938 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef signed int     s32;

#include "net_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *block);
extern u16 func_02039338(void);
extern GFLNetHandle *func_020399A8(void);
extern int    func_02039594(void);
extern GFLNetHandle *func_0203996C(s32 idx);
extern void func_02082D44(const void *src, void *dst, int n);
extern void func_02087C6C(void *dst);
extern s32 func_0203EFC8(const u8 *lhs, const u8 *rhs, u32 size);
extern void func_02034F84(u32 flag);
extern void func_0203064C(u32 parentHeapId, u32 heapId, u32 size);
extern struct GFLNetModeOps *func_0200F17C(u32 netType);
extern void func_0200F234(u32 netType);
extern void func_020306F0(u32 heapId);
extern void func_02034FB8(u32 flag);
extern void func_0203EA9C(void);
extern u32  func_020338F8(void);
extern void func_02039CA0(void);
extern void func_02039C68(GFLNetHandle *handle, u32 timingNo, u32 option);
extern u32 func_02039CB4(GFLNetHandle *handle, u32 timingNo, u32 option);
void func_02037010(u32 timeoutFrames, u32 timeoutExtra, u32 isWifi, u32 heapId);
void func_020370C8(void);
void func_02037118(u32 restartParamA, u32 restartParamB);
void func_02037154(void);
void func_020371AC(unsigned short timeoutFrames, unsigned short timeoutExtra);
void func_02037A44(int mode);
int func_02037C10(void);
int func_02038C18(u32 command, const void *data, u32 size, u32 sendFlags, u32 aid, u32 targetMask, u32 queueMode);
u32 func_02039414(void);
int func_02039468(u32 command, u32 aid);
int func_020394C0(void);
void func_020394F0(u32 waitMode);
int func_020395EC(GFLNetHandle *handle);
void func_02039834(GFLNetSession *unused);
void func_020398B4(GFLNetSession *unused);
u32 func_020399B8(u8 *handle);
int func_020399EC(void);
int func_02039ACC(void);
void func_02039C3C(GFLNetHandle *handle, u16 tag);
void func_02039D94(void);
void func_0203A458(u8 *handle, u32 gameKind);
void func_0203A494(u32 gameKindShifted, u32 recvFuncTable, u32 recvFuncTableNum, u32 userArg, u32 heapId);
void func_0203AFCC(u32 heapId, u32 transportArg);
void func_0203B0C4(int context, int flag);
void func_0203B1B0(void);
u32 func_0203B1D8(void);
void func_0203B2D0(u32 heapId);
void func_0203BA98(u16 heapId, u32 changeoverParam, u8 mode);
void func_0203BD30(u32 mode, u32 flags, u8 *macAddr);
void func_0203BF9C(u32 handler);
void func_0203BFF0(void);
void func_0203C010(void);
void func_0203C3B4(void);
void func_0203C774(u32 handler);
void func_0203C8E8(u8 autoExit);
void func_0203C900(u8 loginOption);
u32 func_0203C938(u8 mode);
void func_0203CB34(u32 parentHeapId, u32 zero, u32 oldBaseHeapId, u32 newBaseHeapId);
void func_0203CBAC(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg);
int func_0203CD98(void);
int func_0203CDBC(void);
void func_0203CDD4(void);
int func_0203CEAC(void (*exitCallback)(u32));
void func_0203CF04(void);
u32 func_0203CF10(u32 index);
void *func_0203CF3C(u32 index);
u32 func_0203CF5C(void);
void func_0203CFA0(void);
void func_0203CFF0(void *context);
void func_0203D000(void *context);
void func_0203D010(void);
void func_0203D01C(void);
void func_0203D060(u32 onFinished, u32 onResult, u32 onReady);
void func_0203D0AC(int gameKind);
void func_0203D0B8(void *dst, u32 slot);
void func_0203D0C4(unsigned int value);
void func_0203D0D0(void);
void func_0203D0DC(u32 changeoverParam);
void func_0203D0FC(int unused);
void func_0203D10C(u32 changeoverParam);
void func_0203D12C(int mode);
void func_0203D14C(u32 mode, u32 flags, u8 *macAddr);
u32 func_0203D158(void);
void func_0203D164(int retryRequest);
int func_0203D170(void);
void func_0203D17C(u32 frames);
u32 func_0203D1A4(GFLNetHandle *handle);
int func_0203D1B4(void);
u32 func_0203D1C0(u32 index);
void func_0203D1E8(u32 unusedArg, void *eventArg);
u32 func_0203D210(void);
void func_0203D24C(u16 timeoutFrames, u16 timeoutExtra);
u32 func_0203D26C(void);
u32 func_0203D29C(void);
void func_0203D2CC(void);
void func_0203D34C(u32 restartParamA, u32 restartParamB);
u32 func_0203D378(void);
u32 func_0203D394(GFLNetHandle *handle);
int func_0203D3A8(GFLNetHandle *handle, u32 command, u32 size, const void *data);
u32 func_0203D3F8(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
u32 func_0203D4D0(GFLNetHandle *handle, u32 targetMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
void func_0203D56C(void);
void func_0203D578(GFLNetHandle *handle, u32 command);
void func_0203D594(GFLNetHandle *handle, u16 tag);
void func_0203D5A0(void);
void func_0203D5AC(int gameKind, int unused);
u32 func_0203D5D4(void);
u32 func_0203D5EC(void);
u32 func_0203D610(void);
u32 func_0203D634(void);
void func_0203D644(u32 waitMode);
u32 func_0203D650(void);
void func_0203D668(u32 userArg);
u32 func_0203D680(void);
u32 func_0203D6BC(void);
u32 func_0203D6CC(void);
void func_0203D700(void);
void func_0203D720(u32 errorCode);
void func_0203D754(u32 newState);
GFLNetSession *func_0203D788(void);
GFLNetSession *func_0203D798(void);
void func_0203D7B0(u8 autoExit);
void func_0203D7BC(u8 loginOption);
void *func_0203D7C8(u32 heapId, u32 size, const char *fileName, u16 line);
void func_0203D7FC(void *block);
void func_0203D814(u32 paramA, u32 paramB);
void func_0203D828(u32 *outParamA, u32 *outParamB);
void func_0203D844(void *dst);
void func_0203D864(void);
u32 func_0203D880(void);
void func_0203D88C(u32 timeoutFrames, u32 timeoutExtra);
void func_0203D8AC(void);
void func_0203D8C4(u32 enable);
GFLNetInitializeStruct *func_0203D8F0(const GFLNetInitializeStruct *src, u32 callbackArg);
void func_0203D9EC(void);
void func_0203DA20(void);
int func_0203DA4C(void);
void func_0203DA68(unsigned int value);
void *func_0203DA7C(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32));
void func_0203DAC4(const u8 *mac);
void func_0203DBB0(void *dst, u32 slot);
void func_0203DC04(void);
void func_0203DC4C(u32 userArg);
void func_0203DC68(NetIrcWirelessLink *link, int state);
void func_0203DC70(void);
void *func_0203E420(void *beaconArg);
void *func_0203E458(void *beaconArg);
void func_0203E484(u32 unusedA, u32 unusedB, struct NetMacList *macList);
u32 func_0203E4E8(void);
void func_0203E538(int netId);
int func_0203E590(void);
void func_0203E5AC(int gameKind);
extern const char file_020A7CA0[];
extern const char str_020A7CA8[];
extern const char str_020A7CB8[];
extern const char str_020A7CE8[];
extern GFLNetMain g_021469E0;
extern char g_020A7CEC[];
extern const char file_020A7CF8[];
extern const char file_020A7D2C[];
extern NetIrcWirelessLink *g_021469F0;
extern const char file_020A7D34[];
extern const u8 str_020A7D48[];
extern const u8 str_020A7D4C[];
extern char s_020A7D68[];






















void func_0203CB34(u32 parentHeapId, u32 zero, u32 oldBaseHeapId, u32 newBaseHeapId)
{
    GFLNetModeOps *ops = func_0200F17C(1);

    if (ops != 0)
        ops->start(parentHeapId, zero);

    func_0200F234(1);

    if (oldBaseHeapId != newBaseHeapId) {
        g_021469E0.baseHeapId = (u16)newBaseHeapId;
        func_0203064C(oldBaseHeapId, newBaseHeapId, 0x9E80);
    }

    func_020371AC(0, 0);
    func_020370C8();
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
void func_0203CBAC(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg)
{
    GFLNetSession *session;
    u8 netType;
    u32 isWifi;

    if (g_021469E0.baseHeapId != 0)
        func_0203064C(g_021469E0.baseHeapId, req->heapId, 0x7800);
    else
        func_0203064C(req->parentHeapId, req->heapId, 0x7800);
    session = (GFLNetSession *)func_02030734(req->heapId, 0x354, 1, file_020A7CA0, 0x6a);
    g_021469E0.session = session;
    session->errorCheckEnabled = 1;
    session->ops = func_0200F17C(req->bNetType);
    if (session->ops == 0)
        func_02034714(file_020A7CA0, 0x6f, str_020A7CA8);
    if (req->bNetType == 4)
        req = (GFLNetInitializeStruct *)func_0203D8F0((const GFLNetInitializeStruct *)req, userArg);
    func_02082D44(req, session, 0x70);
    switch (req->bNetType) {
    case 1:
    case 2:
    case 6:
        session->ops->start(req->parentHeapId, 0);
        func_0203064C(req->parentHeapId, (u16)(req->wifiHeapId | 0x8000), req->heapSize);
        break;
    case 3:
    case 4:
        if (req->childSendSize > 0x80)
            func_02034714(file_020A7CA0, 0x84, str_020A7CB8);
        if (g_021469E0.baseHeapId != 0)
            func_0203064C(g_021469E0.baseHeapId, req->beaconHeapId, 0x1b00);
        else
            func_0203064C(req->parentHeapId, req->beaconHeapId, 0x1b00);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(file_020A7CA0, 0x8e, str_020A7CE8);
        return;
    }
    session->userArg = userArg;
    func_0203AFCC(req->heapId, transportArg);
    func_02039834(session);
    func_0203A494(req->gameKind << 8, req->recvFuncTable, req->recvFuncTableNum, session->userArg, req->heapId);
    netType = req->bNetType;
    {
        int isBeacon = (netType == 3) || (netType == 4);
        if (isBeacon)
            return;
    }
    isWifi = 0;
    if ((u8)(netType + 0xff) <= 1)
        isWifi = 1;
    func_02037010(req->timeoutFrames, req->timeoutExtra, isWifi, req->heapId);
}






















/*
 * Return the run state of the current mode through its operation table, or 0
 * when there is no session.
 */
int func_0203CD98(void)
{
    GFLNetSession *s = func_0203D788();

    if (s == 0) {
        return 0;
    }

    return s->ops->getRunState();
}
























int func_0203CDBC(void)
{
    return func_0203D788() == 0;
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
void func_0203CDD4(void)
{
    GFLNetSession *session = func_0203D788();
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

    func_020398B4(session);
    func_0200F234(netType);
    func_020307B0(session);

    g_021469E0.session = 0;

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
        func_02034714(file_020A7CA0, 0xEE, str_020A7CE8);
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
int func_0203CEAC(void (*exitCallback)(u32))
{
    GFLNetSession *session;

    session = func_0203D788();
    func_0203DA20();
    if (session != 0) {
        u8 netType = session->init.bNetType;

        session->exitCallback = exitCallback;
        if (netType == 1) {
            func_0203C774((u32)func_0203CDD4);
        } else {
            func_0203BF9C((u32)func_0203CDD4);
        }
        func_020370C8();
        return 1;
    }
    return 0;
}
























void func_0203CF04(void)
{
    func_0203BFF0();
}
























/*
 * Return the scan result entry for index from the current mode, or 0 when
 * there is no session. Dispatches through the getScanResult slot of the mode
 * operation table; the table pointer itself is not checked.
 */
u32 func_0203CF10(u32 index)
{
    GFLNetSession *session;

    session = func_0203D788();
    if (session == 0)
        return 0;
    return session->ops->getScanResult(index);
}
























/*
 * Return the scan result MAC for index through the getScanResultMac slot of
 * the mode operation table. The session must exist.
 */
void *func_0203CF3C(u32 index)
{
    GFLNetSession *session;

    session = func_0203D788();
    return session->ops->getScanResultMac(index);
}
























/*
 * Per-frame network update. Runs the wireless link state machine and the
 * state layer. Returns 1 when the state layer is busy or there is no session;
 * otherwise advances the handle layer, the send queue and the timing sync and
 * returns the handle layer's result.
 */
u32 func_0203CF5C(void)
{
    GFLNetSession *session = func_0203D788();

    func_0203EA9C();
    func_0203DC70();
    if (func_0203B1D8() != 0) {
        return 1;
    }
    if (session == 0) {
        return 1;
    }
    func_02037154();
    func_02039D94();
    func_02037C10();
    return func_02039594();
}
























void func_0203CFA0(void)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *initSession;

    if (func_0203B1D8() != 0)
        return;
    if (session == 0 || session->ops == 0)
        return;

    initSession = func_0203D798();
    switch (initSession->init.bNetType) {
    case 1:
    case 2:
        return;
    }

    session->ops->requestDisconnect(0);
}
























/*
 * Tail wrapper: connect to the parent at context (flag 1). Called from state
 * 10 of the wireless link state machine.
 */
void func_0203CFF0(void *context)
{
    func_0203B0C4((int)context, 1);
}
























/*
 * Tail wrapper: connect to the child at context (flag 0), the twin of
 * GFL_NET_ConnectMacAddressParent.
 */
void func_0203D000(void *context)
{
    func_0203B0C4((int)context, 0);
}
























/*
 * Tail wrapper: start the beacon scan. Called from state 10 of the wireless
 * link state machine.
 */
void func_0203D010(void)
{
    func_0203B1B0();
}
























void func_0203D01C(void)
{
    GFLNetSession *session = func_0203D788();

    switch (session->init.bNetType) {
    case 1:
    case 2:
        func_0203C3B4();
        return;
    case 0:
    case 5:
        func_0203B2D0(session->init.heapId);
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
void func_0203D060(u32 onFinished, u32 onResult, u32 onReady)
{
    GFLNetSession *session = func_0203D788();
    u32 handler = onFinished;

    if (func_0203DA4C() == 1)
        handler = (u32)func_0203DA7C((void (*)(u32))onFinished, (void (*)(u32, int))onResult, (void (*)(u32))onReady);

    func_0203BA98(session->init.heapId, handler, 1);
}






















void func_0203D0AC(int gameKind)
{
    func_0203E5AC(gameKind);
}






















void func_0203D0B8(void *dst, u32 slot)
{
    func_0203DBB0(dst, slot);
}






















void func_0203D0C4(unsigned int value)
{
    func_0203DA68(value);
}






















void func_0203D0D0(void){ func_0203D9EC(); }























void func_0203D0DC(u32 changeoverParam)
{
    func_0203BA98(func_0203D788()->init.heapId, changeoverParam, 1);
}





















void func_0203D0FC(int unused)
{
    func_0203D788();
    func_0203C010();
}



















void func_0203D10C(u32 changeoverParam)
{
    func_0203BA98(func_0203D788()->init.heapId, changeoverParam, 0);
}





















/*
 * Forward the mode to the state layer only when the session reports that the
 * connection is up (run state non-zero).
 */
void func_0203D12C(int mode)
{
    if (func_0203CD98() == 0)
        return;

    func_02037A44(mode);
}




















void func_0203D14C(u32 mode, u32 flags, u8 *macAddr)
{
    func_0203BD30(mode, flags, macAddr);
}




















u32 func_0203D158(void)
{
    return func_0203E4E8();
}




















void func_0203D164(int retryRequest)
{
    func_0203E538(retryRequest);
}




















int func_0203D170(void)
{
    return func_0203E590();
}
























/*
 * Set the link timeout through the setLinkTimeout slot of the mode operation
 * table, when the table exists. The hook's result is dropped.
 */
void func_0203D17C(u32 frames)
{
    GFLNetSession *session;
    GFLNetModeOps *ops;

    session = func_0203D788();
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
u32 func_0203D1A4(GFLNetHandle *handle)
{
    return func_020395EC(handle) & 0xff;
}























int func_0203D1B4(void)
{
    return func_020399EC();
}























/*
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with GFL_NET_HANDLE_GetNetHandle and ask GFL_NET_HANDLE_IsNegotiationDone about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 */
u32 func_0203D1C0(u32 index)
{
    if (func_0203D788() == 0) {
        return 0;
    }
    return func_020399B8((u8 *)func_0203996C(index));
}






















void func_0203D1E8(u32 unusedArg, void *eventArg)
{
    void (*notifyFunc)(void *) = func_0203D788()->ops->notifyUserEvent;

    if (notifyFunc == 0) {
        return;
    }
    notifyFunc(eventArg);
}






















/*
 * "Nothing running, or the +0x6c hook says idle".  The first test reads
 * g_021469E0.session straight out of the singleton (the same two
 * instructions GFL_NET_GetSession is made of), while the second goes through the
 * real call; that asymmetry is what says the first read is a file-local
 * access and not an inlined copy of the extern.
 */
u32 func_0203D210(void)
{
    if (g_021469E0.session == 0) {
        return 1;
    }
    return func_0203D788()->ops->getRunState() == 0;
}
























/*
 * Store a halfword pair into +0x5c/+0x5e of the network state block, if it
 * exists.  Both stores are predicated off the one null test, which is why
 * the two parameters have to survive the accessor call in r5/r4.
 */
void func_0203D24C(u16 timeoutFrames, u16 timeoutExtra)
{
    GFLNetSession *initSession = func_0203D798();

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
u32 func_0203D26C(void)
{
    GFLNetSession *session = func_0203D788();

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
u32 func_0203D29C(void)
{
    GFLNetSession *session = func_0203D788();

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
void func_0203D2CC(void)
{
    GFLNetSession *initSession = func_0203D798();
    GFLNetSession *session = func_0203D788();

    if (func_020338F8() == 1) {
        func_02034714(file_020A7CA0, 868, str_020A7CE8);
        return;
    }
    if (session != 0 && initSession->init.bNetType != 3) {
        u32 isWifi = 0;

        if ((u8)(session->init.bNetType + 0xff) <= 1) {
            isWifi = 1;
        }
        func_02037010(session->init.timeoutFrames, session->init.timeoutExtra, isWifi, session->init.heapId);
    } else {
        func_020370C8();
    }
}
























/*
 * Three-call sequence: stamp the (0xf0, 0) pair into the state block, run
 * the transfer at 0x02037118 with this function's own two arguments, then
 * kick the state machine at 0x0203D2CC.  Both arguments have to outlive the
 * first call, which is what spends r5/r4.
 */
void func_0203D34C(u32 restartParamA, u32 restartParamB)
{
    func_0203D24C(0xf0, 0);
    func_02037118(restartParamA, restartParamB);
    func_0203D2CC();
}
























/*
 * Inverted forward: 1 when GFL_NET_SYSTEM_GetCurrentAid reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 */
u32 func_0203D378(void)
{
    u32 isParent = 0;

    if (func_02039338() == 0) {
        isParent = 1;
    }
    return isParent;
}
























/*
 * Leaf predicate on the +0x4a byte of an entry: "is this entry in state 5".
 * No relocation and no frame; the same three-instruction body appears
 * inlined inside GFL_NET_HANDLE_IsNegotiationDone.
 */
u32 func_0203D394(GFLNetHandle *handle)
{
    return handle->state == 5;
}























/*
 * Send a command with data to every member (target mask 0xff) through the
 * given handle. The leading session lookup is made for effect only.
 */
int func_0203D3A8(GFLNetHandle *handle, u32 command, u32 size, const void *data)
{
    func_0203D798();
    return func_02038C18(command, data, size, 0, func_020395EC(handle), 0xff, 0);
}























/*
 * Send a command to a handle. A sendId of 0xff targets every member; any
 * other id selects one member (ids of 7 or more are an assert failure).
 * Returns 0 without sending when the handle is not in state 5 and the command
 * is 0x11 or higher, or when skipIfQueued is set and the command is already
 * in the send queue.
 */
u32 func_0203D3F8(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode)
{
    u8 targetMask;

    func_0203D798();
    targetMask = 0xff;
    if (func_0203D394(handle) == 0 && command >= 0x11) {
        return 0;
    }
    if (skipIfQueued != 0 && func_02039468(command, func_020395EC(handle)) != 0) {
        return 0;
    }
    if (sendId != 0xff) {
        if (sendId >= 7) {
            func_02034714(file_020A7CA0, 1019, g_020A7CEC);
        }
        targetMask = 1 << sendId;
    }
    return func_02038C18(command, data, size, sendFlags, func_020395EC(handle), targetMask, queueMode);
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
u32 func_0203D4D0(GFLNetHandle *handle, u32 targetMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued,
                  u32 queueMode)
{
    func_0203D798();
    if (func_0203D394(handle) == 0 && command >= 0x11) {
        return 0;
    }
    if (skipIfQueued != 0 && func_02039468(command, func_020395EC(handle)) != 0) {
        return 0;
    }
    return func_02038C18(command, data, size, sendFlags, func_020395EC(handle), targetMask, queueMode);
}






















void func_0203D56C(void)
{
    func_020394C0();
}























/*
 * Forwards the first argument through GFL_NET_HANDLE_GetNetHandleID and passes the result
 * with the second argument to GFL_NET_SYSTEM_IsSendQueueEntry.
 */
void func_0203D578(GFLNetHandle *handle, u32 command)
{
    u32 aid = func_020395EC(handle);

    func_02039468(command, aid);
}




















void func_0203D594(GFLNetHandle *handle, u16 tag)
{
    func_02039C3C(handle, tag);
}




















void func_0203D5A0(void)
{
    func_02039CA0();
}





















/*
 * Set the session's game kind byte and update the handle layer's all-handle
 * slot (0xff) with it.
 */
void func_0203D5AC(int gameKind, int unused)
{
    GFLNetSession *initSession;

    func_0203D788();
    initSession = func_0203D798();
    initSession->init.gameKind = (u8)gameKind;
    func_0203A458((u8 *)func_0203996C(0xff), gameKind);
}






















/*
 * Returns the byte at +0x67 of the net context, or 0 when there is none.
 */
u32 func_0203D5D4(void)
{
    GFLNetSession *initSession = func_0203D798();

    return initSession != 0 ? initSession->init.gameKind : 0;
}






















/*
 * Calls the net context's +0x44 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 */
u32 func_0203D5EC(void)
{
    GFLNetSession *session = func_0203D788();

    if (session->init.getWifiUserDataFunc == 0) {
        return 0;
    }
    return session->init.getWifiUserDataFunc(session->userArg);
}






















/*
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 */
u32 func_0203D610(void)
{
    GFLNetSession *session = func_0203D788();

    if (session->init.getFriendListFunc == 0) {
        return 0;
    }
    return session->init.getFriendListFunc(session->userArg);
}
















u32 func_0203D634(void)
{
    return func_0203D788()->init.friendListNum;
}

















void func_0203D644(u32 waitMode)
{
    func_020394F0(waitMode);
}



















/*
 * Returns the word at +0x34c of the net context, or 0 when there is none.
 */
u32 func_0203D650(void)
{
    GFLNetSession *session = func_0203D788();

    return session != 0 ? session->userArg : 0;
}



















/*
 * Stores the argument at +0x34c of the net context, when there is one.
 */
void func_0203D668(u32 userArg)
{
    GFLNetSession *session = func_0203D788();

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
u32 func_0203D680(void)
{
    GFLNetSession *session = func_0203D788();

    if (session->init.maxConnectNum > 8)
        func_02034714(file_020A7CA0, 0x593, file_020A7CF8);
    return session->init.maxConnectNum;
}



















/*
 * Returns the byte at +0x61 of the net context.
 */
u32 func_0203D6BC(void)
{
    return func_0203D788()->init.childSendSize;
}



















/*
 * Halfword getter for the null-test sibling of GFL_NET_GetMaxConnectNum: reports through
 * the assert reporter at line 0x5B1 (1457) when GFL_NET_GetSession comes back null, then
 * reads +0x6C from it regardless.  The null test is the `movs r4, r0` /
 * `bne` pair, so the result is kept in a local that the tail still
 * dereferences rather than being re-requested.
 *
 */
u32 func_0203D6CC(void)
{
    GFLNetSession *session = func_0203D788();

    if (session == 0)
        func_02034714(file_020A7CA0, 0x5B1, file_020A7D2C);
    return session->init.parentSendSize;
}



















/*
 * Calls the net context's +0x30 callback with its +0x34c argument.
 */
void func_0203D700(void)
{
    GFLNetSession *session = func_0203D788();

    if (session->init.deviceReadyFunc != 0) {
        session->init.deviceReadyFunc(session->userArg);
    }
}



















/*
 * Calls the net context's +0x28 callback with the GFL_NET_HANDLE_GetCurrentHandle result,
 * the argument and the context's +0x34c value.
 */
void func_0203D720(u32 errorCode)
{
    GFLNetSession *session = func_0203D788();

    if (session->init.errorStateFunc == 0) {
        return;
    }
    session->init.errorStateFunc(
        (u32)func_020399A8(), errorCode, session->userArg);
}



















/*
 * Calls the net context's +0x24 callback with the GFL_NET_HANDLE_GetCurrentHandle result,
 * the argument and the context's +0x34c value.
 */
void func_0203D754(u32 newState)
{
    GFLNetSession *session = func_0203D788();

    if (session->init.stateChangeFunc == 0) {
        return;
    }
    session->init.stateChangeFunc(
        (u32)func_020399A8(), newState, session->userArg);
}















GFLNetSession *func_0203D788(void)
{
    return g_021469E0.session;
}















/*
 * Return the session pointer held in gGFLNetMain, or 0 when none is set.
 */
GFLNetSession *func_0203D798(void)
{
    if (g_021469E0.session == 0) {
        return 0;
    }
    return g_021469E0.session;
}















/*
 * Tail-call thunk: set the auto-exit flag in the state layer.
 */
void func_0203D7B0(u8 autoExit)
{
    func_0203C8E8(autoExit);
}















/*
 * Tail-call thunk: set the login option in the state layer.
 */
void func_0203D7BC(u8 loginOption)
{
    func_0203C900(loginOption);
}















/*
 * Allocates size rounded up to 0x20 plus 0x20, rounds the result up to a
 * 0x20 boundary and stores the raw pointer in the word just before the
 * aligned block, which GFL_NET_FreeAligned releases it by.
 */
void *func_0203D7C8(u32 heapId, u32 size, const char *fileName, u16 line)
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
void func_0203D7FC(void *block)
{
    if (block == 0) {
        return;
    }
    func_020307B0(*(void **)((u8 *)block - 4));
}















/*
 * Stores the two net_irc_wireless context words at +0xc and +4.
 */
void func_0203D814(u32 paramA, u32 paramB)
{
    g_021469E0.ircParamA = paramA;
    g_021469E0.ircParamB = paramB;
}















/*
 * Reads back the two net_irc_wireless context words.
 */
void func_0203D828(u32 *outParamA, u32 *outParamB)
{
    *outParamA = g_021469E0.ircParamA;
    *outParamB = g_021469E0.ircParamB;
}















/*
 * Copies 0x70 bytes from the net context into the destination.
 */
void func_0203D844(void *dst)
{
    func_02082D44(dst, func_0203D788(), 0x70);
}















/*
 * Clears the net context's +0x2c and +0x1c words.
 */
void func_0203D864(void)
{
    GFLNetSession *session = func_0203D788();

    if (session != 0) {
        session->init.connectEndFunc = 0;
        session->init.getBeaconCompareFunc = 0;
    }
}















/*
 * A bare tail-call thunk to GFL_NET_SYSTEM_CheckError.
 */
u32 func_0203D880(void)
{
    return func_02039414();
}















/*
 * Truncates both arguments to 16 bits, then runs the pair through
 * the timeout setter and GFL_NET_RestartByNetType.
 */
void func_0203D88C(u32 timeoutFrames, u32 timeoutExtra)
{
    func_020371AC((u16)timeoutFrames, (u16)timeoutExtra);
    func_0203D2CC();
}















/*
 * Runs the timeout setter(0, 0) and GFL_NET_RestartByNetType.
 */
void func_0203D8AC(void)
{
    func_020371AC(0, 0);
    func_0203D2CC();
}















/*
 * Writes 1 or 0 to the net context's +0x352 byte depending on whether the
 * argument is 1; a null context is a no-op.
 */
void func_0203D8C4(u32 enable)
{
    GFLNetSession *session = g_021469E0.session;

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
GFLNetInitializeStruct *func_0203D8F0(const GFLNetInitializeStruct *src, u32 callbackArg)
{
    NetIrcWirelessLink *link;

    if (g_021469F0 != 0 && g_021469F0->active == 1)
        return (GFLNetInitializeStruct *)src;

    link = func_02030734((u16)((src->parentHeapId & 0x7FFF) | 0x8000), sizeof(NetIrcWirelessLink), 1, file_020A7D34, 0x72);
    link->init = *src;
    link->callbackArg = callbackArg;
    link->savedConnectEndFunc = src->connectEndFunc;
    link->savedGetBeaconDataFunc = src->getBeaconDataFunc;
    link->savedGetBeaconCompareFunc = src->getBeaconCompareFunc;
    link->init.bNetType = 3;
    link->init.connectEndFunc = func_0203DC4C;
    link->init.getBeaconDataFunc = func_0203E420;
    link->init.getBeaconCompareFunc = func_0203E458;
    link->savedBMPMode = link->init.bMPMode;
    link->init.bMPMode = 0;
    link->expectedMemberNum = link->init.maxConnectNum;

    g_021469F0 = link;
    func_02034F84(0x20);
    return &g_021469F0->init;
}













/*
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through the state-layer release (0x20) and the heap release, then clears the slot.
 */
void func_0203D9EC(void)
{
    if (g_021469F0 == 0) {
        return;
    }
    func_02034FB8(0x20);
    func_020307B0(g_021469F0);
    g_021469F0 = 0;
}













/*
 * Calls GFL_NET_IRC_WIRELESS_Destroy when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 */
void func_0203DA20(void)
{
    NetIrcWirelessLink *link = g_021469F0;

    if (link == 0) {
        return;
    }
    if (link->active != 0) {
        return;
    }
    func_0203D9EC();
}













int func_0203DA4C(void)
{
    return g_021469F0 != 0;
}











/*
 * Stores a word into the singleton at +0x74.
 */
void func_0203DA68(unsigned int value)
{
    g_021469F0->sessionParam = value;
}












/*
 * Install the three wireless link callbacks and return the sync-ready handler.
 * With no live link the function returns its first argument untouched. Each
 * non-null callback is stored in the link; the link is re-read from the global
 * for the second and third store.
 */
void *func_0203DA7C(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32))
{
    NetIrcWirelessLink *link = g_021469F0;

    if (link == 0)
        return onFinished;
    if (onFinished != 0)
        link->onFinishedFunc = onFinished;
    if (onResult != 0)
        g_021469F0->onResultFunc = onResult;
    if (onReady != 0)
        g_021469F0->onReadyFunc = onReady;
    return func_0203DC04;
}










void func_0203DAC4(const u8 *mac)
{
    int i;

    if (g_021469F0 == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (func_0203EFC8(mac, g_021469F0->macs.mac[i].addr, 6) == 0)
            return;
    }
    {
        u8 emptyMac[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 4; i++) {
            if (func_0203EFC8(emptyMac, g_021469F0->macs.mac[i].addr, 6) == 0) {
                func_02082D44(mac, g_021469F0->macs.mac[i].addr, 6);
                g_021469F0->macs.count = i;
                return;
            }
        }
    }
    func_0203C938(1);
}









void func_0203DBB0(void *dst, u32 slot)
{
    NetIrcWirelessLink *link = g_021469F0;

    if (link != 0) {
        func_02082D44(link->macs.mac[slot].addr, dst, 6);
    } else {
        func_02034714(file_020A7D34, 0x109, (const char *)str_020A7D48);
    }
}








void func_0203DC04(void)
{
    if (g_021469F0 == 0)
        return;
    g_021469F0->syncReady = 1;
    if (g_021469F0->requestedNetIDPlus1 != 0) {
        g_021469F0->netID = g_021469F0->requestedNetIDPlus1 - 1;
    } else {
        g_021469F0->netID = func_02039338();
    }
}








/*
 * net_irc_wireless.c.  Callback installed at +0x2C by GFL_NET_IRC_WIRELESS_Create and
 * by states 4 and 14 of GFL_NET_IRC_WIRELESS_Main: flags +0x103 of the live context.
 * An unlabelled ARM leaf.
 */
void func_0203DC4C(u32 userArg)
{
    NetIrcWirelessLink *link = g_021469F0;

    if (link != 0)
        link->connectEnded = 1;
}








/*
 * net_irc_wireless.c.  The state setter of the wireless state machine
 * GFL_NET_IRC_WIRELESS_Main: stores the new state at +0x109.  An unlabelled ARM leaf
 * (no lr save), filed as the `matched` witness for GFL_NET_IRC_WIRELESS_Main's 27 calls.
 */
void func_0203DC68(NetIrcWirelessLink *link, int state)
{
    link->state = state;
}






void func_0203DC70(void)
{
    NetIrcWirelessLink *link = g_021469F0;

    if (link == 0)
        return;

    switch (link->state) {
    case 0:
        if (link->syncReady != 1)
            return;
        link->active = 1;
        func_02039C68(func_020399A8(), 3, 0);
        func_0203DC68(link, 1);
        break;
    case 1:
        if (func_02039CB4(func_020399A8(), 3, 0) == 0)
            return;
        func_0203DC68(link, 2);
        break;
    case 2:
        if (func_02039338() == 0) {
            if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
                return;
            func_0203DC68(link, 3);
            link->timeoutCounter = 0xC8;
        } else {
            if (func_0203D3A8(func_020399A8(), 0x10, 0, 0) == 0)
                return;
            func_0203DC68(link, 3);
        }
        break;
    case 3:
        link->timeoutCounter--;
        if (func_0203D210()) {
            if (g_021469F0->onReadyFunc != 0)
                g_021469F0->onReadyFunc(g_021469F0->callbackArg);
            if (link->retryEnabled != 0 && link->init.maxConnectNum == 4 && link->netID == 0) {
                func_0203DC68(link, 0xE);
                link->retryCount++;
            } else if (link->netID == 0 && link->init.maxConnectNum == 4) {
                link->retryCount++;
                func_0203CEAC(0);
                link->onResultFunc(link->callbackArg, 1);
                func_0203DC68(link, 4);
            } else {
                link->onResultFunc(link->callbackArg, 0);
                func_0203DC68(link, 9);
            }
        }
        if (link->timeoutCounter == 0)
            func_0203CEAC(0);
        break;
    case 4:
        if (func_0203CD98() != 0)
            return;
        link->init.bNetType = 3;
        link->init.connectEndFunc = func_0203DC4C;
        if (link->gameKindOverride != 0)
            link->init.gameKind = link->gameKindOverride;
        link->syncReady = 0;
        link->connectEnded = 0;
        func_0203CBAC((GFLNetInitializeStruct *)link, 0, link->callbackArg);
        func_0203DC68(link, 5);
        break;
    case 5:
        if (func_0203CD98() != 1)
            return;
        func_0203D788()->ops->setSessionParam(g_021469F0->sessionParam);
        func_0203D0DC((u32)func_0203DC04);
        func_0203DC68(link, 6);
        break;
    case 6:
        if (link->syncReady != 1)
            return;
        link->active = 1;
        if (func_0203D3A8(func_020399A8(), 9, 0x24, &g_021469F0->macs) == 0)
            return;
        func_0203DC68(link, 7);
        break;
    case 7:
        if (link->syncReady != 1)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        func_0203D17C(0xC8);
        func_0203DC68(link, 8);
        break;
    case 8:
        if (func_0203D210() == 0)
            return;
        if (g_021469F0->onReadyFunc != 0)
            g_021469F0->onReadyFunc(g_021469F0->callbackArg);
        func_0203DC68(link, 9);
        break;
    case 9:
        if (func_0203D210() == 0)
            return;
        if (link->gameKindOverride != 0) {
            link->init.linkExtraFlags = 0;
            link->init.gameKind = link->gameKindOverride;
        }
        link->init.bNetType = 0;
        link->init.connectEndFunc = link->savedConnectEndFunc;
        link->init.bMPMode = link->savedBMPMode;
        func_0203CBAC((GFLNetInitializeStruct *)link, 0, link->callbackArg);
        g_021469F0->active = 0;
        func_0203DC68(link, 0xA);
        break;
    case 10:
        if (func_0203CD98() != 1)
            return;
        if (link->netID == 0) {
            func_0203D01C();
            func_0203DC68(link, 0xC);
        } else if (link->init.maxConnectNum == 4) {
            func_0203D010();
            func_0203DC68(link, 0xB);
        } else {
            func_0203CFF0(link->macs.mac);
            func_0203DC68(link, 0xC);
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
            scanEntry = (u8 *)func_0203CF10((int)scanIndex);
            if (scanEntry == 0)
                return;
            for (slot = 0; slot < 4; slot++) {
                if (func_0203EFC8(ownMac, scanEntry + 4 + slot * 8, 6) == 0) {
                    func_0203D000(func_0203CF3C((u32)scanIndex));
                    func_0203DC68(link, 0xC);
                    break;
                }
            }
        }
    }
    case 12:
        if (link->netID == 0) {
            if (func_020399EC() == 0)
                return;
            if (func_02039ACC() != 1)
                return;
            func_0203DC68(link, 0xD);
        } else {
            if (func_02039ACC() != 1)
                return;
            func_0203DC68(link, 0xD);
        }
        break;
    case 13:
        if (link->netID != 0) {
            if (link->onFinishedFunc != 0)
                link->onFinishedFunc(link->callbackArg);
            func_0203DA20();
        } else {
            if (func_020399EC() < link->expectedMemberNum)
                return;
            if (link->onFinishedFunc != 0)
                link->onFinishedFunc(link->callbackArg);
            func_0203DA20();
        }
        break;
    case 14:
        if (func_0203CD98() != 0)
            return;
        link->init.bNetType = 3;
        link->init.connectEndFunc = func_0203DC4C;
        link->syncReady = 0;
        link->connectEnded = 0;
        func_0203CBAC((GFLNetInitializeStruct *)link, 0, link->callbackArg);
        func_0203DC68(link, 0xF);
        break;
    case 15:
        if (func_0203CD98() != 1)
            return;
        func_0203D788()->ops->setSessionParam(g_021469F0->sessionParam);
        func_0203D0DC((u32)func_0203DC04);
        func_0203DC68(link, 0x10);
        break;
    case 16:
        if (link->syncReady != 1)
            return;
        func_02039C68(func_020399A8(), 3, 0);
        g_021469F0->active = 1;
        func_0203DC68(link, 0x11);
        break;
    case 17:
        if (func_02039CB4(func_020399A8(), 3, 0) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        func_0203DC68(link, 0x12);
        link->timeoutCounter = 0xC8;
        break;
    case 18:
        link->timeoutCounter--;
        if (func_0203D210() == 0 && link->timeoutCounter != 0)
            return;
        if (g_021469F0->onReadyFunc != 0)
            g_021469F0->onReadyFunc(g_021469F0->callbackArg);
        if (link->retryEnabled != 0 && link->retryCount < 3) {
            link->retryCount++;
            if (link->retryCount >= 3)
                func_0203DC68(link, 9);
            else
                func_0203DC68(link, 0xE);
        } else {
            func_0203DC68(link, 9);
        }
        break;
    }
}





void *func_0203E420(void *beaconArg)
{
    NetIrcWirelessLink *link = g_021469F0;
    void *beaconData;

    if (link == 0)
        return 0;
    beaconData = link->savedGetBeaconDataFunc(beaconArg);
    func_02082D44(beaconData, link->beaconCopy, 0x4C);
    return &link->macs;
}



void *func_0203E458(void *beaconArg)
{
    void *compareData;
    if (g_021469F0 == 0)
        return 0;
    compareData = g_021469F0->savedGetBeaconCompareFunc(beaconArg);
    return (char *)compareData + 0x24;
}




/*
 * Merge a received MAC list into the link's table, entry by entry (at most
 * four). A count of four or more reports an assert.
 */
void func_0203E484(u32 unusedA, u32 unusedB, struct NetMacList *macList)
{
    int i;
    int macCount;

    if (macList->count >= 4) {
        func_02034714(file_020A7D34, 0x2a5, (const char *)str_020A7D4C);
    }
    macCount = macList->count;
    if (macCount > 4) {
        macCount = 4;
    }
    for (i = 0; i < macCount; i++) {
        func_0203DAC4(macList->mac[i].addr);
    }
}




/*
 * Retry step: only a link in state 0x10 advances. It seeds the expected member
 * count from the retry count, restarts the session and parks the state at 9.
 * Returns 1 when it advanced, otherwise 0.
 */
u32 func_0203E4E8(void)
{
    NetIrcWirelessLink *link = g_021469F0;

    if (link == 0)
        return 0;
    if (link->state != 0x10)
        return 0;
    link->expectedMemberNum = link->retryCount + 1;
    func_0203CEAC(0);
    g_021469F0->state = 9;
    return 1;
}


void func_0203E538(int netId)
{
    if (g_021469F0 == 0)
        func_02034714(file_020A7D34, 0x2e4, s_020A7D68);
    if (g_021469F0 != 0) {
        g_021469F0->requestedNetIDPlus1 = (u8)(netId + 1);
        g_021469F0->retryEnabled = 1;
    }
}


/*
 * Reads byte 0x108 of the singleton, or 0 when it is not allocated.
 */
int func_0203E590(void)
{
    NetIrcWirelessLink *link = g_021469F0;
    if (link == 0) return 0;
    return link->retryCount;
}


void func_0203E5AC(int gameKind)
{
    if (g_021469F0 == 0)
        func_02034714(file_020A7D34, 0x31a, s_020A7D68);
    if (g_021469F0 != 0)
        g_021469F0->gameKindOverride = (u8)gameKind;
}
