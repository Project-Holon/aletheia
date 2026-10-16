/*
 * file:     net_irc_wireless.c
 * unit:     yes
 * function: GFL_NET_IRC_WIRELESS_Create, GFL_NET_IRC_WIRELESS_Destroy, GFL_NET_IRC_WIRELESS_DestroyIfIdle, GFL_NET_IRC_WIRELESS_IsActive, GFL_NET_IRC_WIRELESS_SetSessionParamValue, GFL_NET_IRC_WIRELESS_SetCallbacks, GFL_NET_IRC_WIRELESS_AddMacAddress, GFL_NET_IRC_WIRELESS_CopyMacAddress, GFL_NET_IRC_WIRELESS_OnSyncReady, GFL_NET_IRC_WIRELESS_OnConnectEnd, GFL_NET_IRC_WIRELESS_SetState, GFL_NET_IRC_WIRELESS_Main, GFL_NET_IRC_WIRELESS_GetBeaconData, GFL_NET_IRC_WIRELESS_GetBeaconCompare, GFL_NET_IRC_WIRELESS_AddMacList, GFL_NET_IRC_WIRELESS_RetryStep, GFL_NET_IRC_WIRELESS_RequestRetry, GFL_NET_IRC_WIRELESS_GetRetryCountValue, GFL_NET_IRC_WIRELESS_SetGameKindOverride
 * address:  0x0203D8F0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from net.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02034714  0x02034714  arm
 *   func_020307B0   0x020307B0  arm
 *   GFL_NET_SYSTEM_GetCurrentAid   0x02039338  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   gNetIrcWirelessLink     0x021469F0  data
 *   sNetIrcWirelessFileName     0x020A7D34  data
 *   str_020A7D48  0x020A7D48  data
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   str_020A7D4C  0x020A7D4C  data
 *   s_020A7D68      0x020A7D68  data
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_STATE_SetErrorMode 0x0203C938 arm
 *   GFL_NET_StartSession 0x0203CBAC arm arm9
 *   GFL_NET_GetRunState 0x0203CD98 arm arm9
 *   GFL_NET_Exit 0x0203CEAC arm arm9
 *   GFL_NET_GetScanResult 0x0203CF10 arm arm9
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm arm9
 *   GFL_NET_ConnectMacAddressParent 0x0203CFF0 arm arm9
 *   GFL_NET_ConnectMacAddressChild 0x0203D000 arm arm9
 *   GFL_NET_BeaconScanStart 0x0203D010 arm arm9
 *   GFL_NET_StartByNetType 0x0203D01C arm arm9
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm arm9
 *   GFL_NET_SetLinkTimeout 0x0203D17C arm arm9
 *   GFL_NET_IsIdle 0x0203D210 arm arm9
 *   GFL_NET_SendToHandle 0x0203D3A8 arm arm9
 *   GFL_NET_GetSession 0x0203D788 arm arm9
 */
#include "net_shared_types.h"
#include "net_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern u32 func_020307B0(void *block);

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void MI_CpuCopy8(const void *src, void *dst, int n);

extern void OS_GetMacAddress(void *dst);

extern s32 GF_STANDARD_CompareBytes(const u8 *lhs, const u8 *rhs, u32 size);

extern void UI_SetKeepAwakeFlagsGlobal(u32 flag);

extern void UI_ClearKeepAwakeFlagsGlobal(u32 flag);

extern void GFL_NET_HANDLE_SetTimingSyncRange(GFLNetHandle *handle, u32 timingNo, u32 option);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(GFLNetHandle *handle, u32 timingNo, u32 option);

int GFL_NET_HANDLE_GetNegotiationNum(void);

int GFL_NET_HANDLE_CheckNegotiation(void);

u32 GFL_NET_STATE_SetErrorMode(u8 mode);

void GFL_NET_StartSession(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg);

int GFL_NET_GetRunState(void);

int GFL_NET_Exit(void (*exitCallback)(u32));

u32 GFL_NET_GetScanResult(u32 index);

void *GFL_NET_GetScanResultMac(u32 index);

void GFL_NET_ConnectMacAddressParent(void *context);

void GFL_NET_ConnectMacAddressChild(void *context);

void GFL_NET_BeaconScanStart(void);

void GFL_NET_StartByNetType(void);

void GFL_NET_StartChangeoverChild(u32 changeoverParam);

void GFL_NET_SetLinkTimeout(u32 frames);

u32 GFL_NET_IsIdle(void);

int GFL_NET_SendToHandle(GFLNetHandle *handle, u32 command, u32 size, const void *data);

GFLNetSession *GFL_NET_GetSession(void);

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

extern NetIrcWirelessLink *gNetIrcWirelessLink;

extern const char sNetIrcWirelessFileName[];

extern const u8 str_020A7D48[];

extern const u8 str_020A7D4C[];

extern char s_020A7D68[];

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
    UI_SetKeepAwakeFlagsGlobal(0x20);
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
    UI_ClearKeepAwakeFlagsGlobal(0x20);
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
        if (GF_STANDARD_CompareBytes(mac, gNetIrcWirelessLink->macs.mac[i].addr, 6) == 0)
            return;
    }
    {
        u8 emptyMac[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 4; i++) {
            if (GF_STANDARD_CompareBytes(emptyMac, gNetIrcWirelessLink->macs.mac[i].addr, 6) == 0) {
                MI_CpuCopy8(mac, gNetIrcWirelessLink->macs.mac[i].addr, 6);
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
        MI_CpuCopy8(link->macs.mac[slot].addr, dst, 6);
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
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0);
        GFL_NET_IRC_WIRELESS_SetState(link, 1);
        break;
    case 1:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0) == 0)
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
        OS_GetMacAddress(ownMac);
        for (;; scanIndex++) {
            scanEntry = (u8 *)GFL_NET_GetScanResult((int)scanIndex);
            if (scanEntry == 0)
                return;
            for (slot = 0; slot < 4; slot++) {
                if (GF_STANDARD_CompareBytes(ownMac, scanEntry + 4 + slot * 8, 6) == 0) {
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
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0);
        gNetIrcWirelessLink->active = 1;
        GFL_NET_IRC_WIRELESS_SetState(link, 0x11);
        break;
    case 17:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0) == 0)
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
    MI_CpuCopy8(beaconData, link->beaconCopy, 0x4C);
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
