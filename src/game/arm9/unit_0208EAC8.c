/*
 * file:     unit_0208EAC8.c
 * unit:     yes
 * function: WM_SetIndCallback, WM_SetPortCallback, func_0208EBE4, func_0208EC34, func_0208ECA4, func_0208ED70, func_0208EE60, func_0208EE9C, WM_GetDispersionBeaconPeriod, func_0208EFC4, func_0208F05C, func_0208F1B4
 * address:  0x0208EAC8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   WMi_CheckInitialized             0x0208e4cc arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   MI_CpuFill8           0x02082BCC  arm
 *   OS_GetMacAddress      0x02087C6C  arm
 *   WM_GetConnectedAIDs   0x0208EA1C  arm
 *   WM_GetAID             0x0208E9EC  arm
 *   DC_InvalidateRange               0x020862b8 arm
 *   MIi_CpuCopyFast                  0x02082b0c arm
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WMi_CheckEnableFlag              0x0208eaa0 arm
 *   RTC_Init                         0x02088788 arm
 *   RTC_GetTime                      0x0208890c arm
 *   g_020A872C                       0x020a872c data
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef long s32;

typedef short s16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_NO_DATASET = 5,
    WM_ERRCODE_INVALID_PARAM = 6,
    WM_ERRCODE_NO_ENTRY = 7,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMArm9Buf {
    struct WMArm7Buf *WM7;
    struct WMStatus *status;
    u32 *indbuf;
    u32 *fifo9to7;
    u32 *fifo7to9;
    u16 dmaNo;
    u16 scanOnlyFlag;
    WMCallbackFunc CallbackTable[44];
    WMCallbackFunc indCallback;
    WMCallbackFunc portCallbackTable[16];
    void *portCallbackArgument[16];
    u32 connectedAidBitmap;
    u16 myAid;
    u8 reserved1[174];
} WMArm9Buf;

typedef struct WMStatus {
    u16 state;
    u8 pad02[0xA];
    u32 mp_flag;
    u8 pad10[0x2C];
    u16 mp_sendSize;
    u16 mp_recvSize;
    u8 pad40[0x32];
    u16 mp_recvBufSize;
    u8 pad74[0x48];
    u16 linkLevel;
    u8 padBE[0x3A];
    u16 pparam_maxEntry;
    u8 padFA[0x88];
    u16 child_bitmap;
    u8 pad184[4];
    u16 aid;
} WMStatus;

typedef struct WMPortRecvCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 port;
    struct WMMpRecvBuf *recvBuf;
    u16 *data;
    u16 length;
    u16 aid;
    u8 macAddress[6];
    u16 seqNo;
    void *arg;
    u16 myAid;
    u16 connectedAidBitmap;
    u8 ssid[24];
    u16 reason;
    u16 rssi;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortRecvCallback;

typedef struct WMMpRecvData {
    u16 length;
    u16 rate_rssi;
    u16 aid;
    u16 noResponse;
    u16 wmHeader;
    u16 cdata[1];
} WMMpRecvData;

typedef struct WMMpRecvHeader {
    u16 bitmap;
    u16 errBitmap;
    u16 count;
    u16 length;
    u16 txCount;
    WMMpRecvData data[1];
} WMMpRecvHeader;

typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1,
    WM_LINK_LEVEL_2,
    WM_LINK_LEVEL_3,
    WM_LINK_LEVEL_MAX
} WMLinkLevel;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    struct {
        u16 basic;
        u16 support;
    } rateSet;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    u8 gameInfo[128];
} WMBssDesc;

typedef struct WMOtherElements {
    u8 count;
    u8 rsv[3];
    struct {
        u8 id;
        u8 length;
        u8 rsv[2];
        u8 *body;
    } element[16];
} WMOtherElements;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

extern OSIntrMode OS_DisableInterrupts(void);
extern WMErrCode WMi_CheckInitialized(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern WMArm9Buf *WMi_GetSystemWork(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void OS_GetMacAddress(u8 *macAddress);
extern u16 WM_GetConnectedAIDs(void);
extern u16 WM_GetAID(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL WMi_CheckEnableFlag(void);
extern void RTC_Init(void);
extern int RTC_GetTime(RTCTime *time);
WMErrCode WM_SetIndCallback(WMCallbackFunc callback);
WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg);
WMErrCode func_0208EBE4(struct WMStatus *statusBuf);
int func_0208EC34(void);
int func_0208ECA4(void);
WMMpRecvData *func_0208ED70(const WMMpRecvHeader *header, u16 aid);
u16 func_0208EE60(void);
WMLinkLevel func_0208EE9C(void);
u16 WM_GetDispersionBeaconPeriod(void);
u16 func_0208EFC4(void);
WMOtherElements func_0208F05C(WMBssDesc *bssDesc);
u16 func_0208F1B4(void);
extern u32 g_020A872C;






/*
 * sdk:      WM_SetIndCallback (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_SetIndCallback(WMCallbackFunc callback)
{
    OSIntrMode e;
    WMErrCode result;

    e = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return result;
    }

    WMi_GetSystemWork()->indCallback = callback;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}






WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg)
{
    WMErrCode result;
    OSIntrMode e;
    WMPortRecvCallback cb_Port;
    WMArm9Buf *p;

    if (callback != 0) {
        MI_CpuFill8(&cb_Port, 0, sizeof(cb_Port));
        cb_Port.apiid = 0x82;
        cb_Port.errcode = WM_ERRCODE_SUCCESS;
        cb_Port.state = 25;
        cb_Port.port = port;
        cb_Port.recvBuf = 0;
        cb_Port.data = 0;
        cb_Port.length = 0;
        cb_Port.seqNo = 0xFFFF;
        cb_Port.arg = arg;
        cb_Port.aid = 0;
        OS_GetMacAddress(cb_Port.macAddress);
    }

    e = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return result;
    }

    p = WMi_GetSystemWork();
    p->portCallbackTable[port] = callback;
    p->portCallbackArgument[port] = arg;
    if (callback != 0) {
        cb_Port.connectedAidBitmap = WM_GetConnectedAIDs();
        cb_Port.myAid = WM_GetAID();
        (*callback)(&cb_Port);
    }
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}






/*
 * sdk:      WM_ReadStatus (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208EBE4(struct WMStatus *statusBuf)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    if (statusBuf == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_InvalidateRange(p->status, 2000);
    MIi_CpuCopyFast(p->status, statusBuf, 2000);
    return WM_ERRCODE_SUCCESS;
}






/*
 * sdk:      WM_GetMPSendBufferSize (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
int func_0208EC34(void)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, 7, 8);
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    DC_InvalidateRange(&p->status->mp_flag, 4);
    if (p->status->mp_flag == 1) {
        return 0;
    }

    DC_InvalidateRange(&p->status->mp_sendSize, 4);
    return (p->status->mp_sendSize + 31) & ~31;
}




/*
 * sdk:      WM_GetMPReceiveBufferSize (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
int func_0208ECA4(void)
{
    WMErrCode result;
    BOOL isParent;
    int maxReceiveSize;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, 7, 8);
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    DC_InvalidateRange(&p->status->mp_flag, 4);
    if (p->status->mp_flag == 1) {
        return 0;
    }

    DC_InvalidateRange(&p->status->aid, 2);
    isParent = (p->status->aid == 0) ? 1 : 0;
    DC_InvalidateRange(&p->status->mp_recvSize, 2);
    maxReceiveSize = p->status->mp_recvSize;
    if (isParent == 1) {
        DC_InvalidateRange(&p->status->pparam_maxEntry, 2);
        return (((maxReceiveSize + 12) * p->status->pparam_maxEntry + 10 + 31) & ~31) * 2;
    }
    return ((maxReceiveSize + 50 + 31) & ~31) * 2;
}



/*
 * sdk:      WM_ReadMPData (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMMpRecvData *func_0208ED70(const WMMpRecvHeader *header, u16 aid)
{
    int i;
    WMErrCode result;
    WMMpRecvData *recvdata_p[15];
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    if (aid < 1 || aid > 15) {
        return 0;
    }

    DC_InvalidateRange(&p->status->child_bitmap, 2);
    if (!(p->status->child_bitmap & (1 << aid))) {
        return 0;
    }

    if (header->count == 0 || header->count > 15) {
        return 0;
    }

    recvdata_p[0] = (WMMpRecvData *)&header->data[0];
    i = 0;
    do {
        if (recvdata_p[i]->aid == aid) {
            return recvdata_p[i];
        }
        i++;
        recvdata_p[i] = (WMMpRecvData *)((u32)recvdata_p[i - 1] + header->length);
    } while (i < header->count);

    return 0;
}



/*
 * sdk:      WM_GetAllowedChannel (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
u16 func_0208EE60(void)
{
    WMErrCode result;

    if (OS_IsRunOnTwl()) {
        if (!WMi_CheckEnableFlag()) {
            return 0;
        }
    }

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return 0x8000;
    }
    return *(u16 *)0x02FFFCFA;
}



/*
 * sdk:      WM_GetLinkLevel (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMLinkLevel func_0208EE9C(void)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return WM_LINK_LEVEL_0;
    }

    DC_InvalidateRange(&p->status->state, 2);
    switch (p->status->state) {
    case 9:
        DC_InvalidateRange(&p->status->child_bitmap, 2);
        if (p->status->child_bitmap == 0) {
            return WM_LINK_LEVEL_0;
        }
    case 10:
    case 11:
        DC_InvalidateRange(&p->status->linkLevel, 2);
        return (WMLinkLevel)p->status->linkLevel;
    }
    return WM_LINK_LEVEL_0;
}



/*
 * sdk:      WM_GetDispersionBeaconPeriod (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
u16 WM_GetDispersionBeaconPeriod(void)
{
    u8 mac[6];
    u16 ret;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++) {
        ret += mac[i];
    }
    ret += (u16)*(volatile u32 *)0x02FFFC3C;
    ret *= 7;
    return (u16)(200 + (ret % 20));
}



/*
 * sdk:      WM_GetDispersionScanPeriod (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
u16 func_0208EFC4(void)
{
    u8 mac[6];
    u16 ret;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++) {
        ret += mac[i];
    }
    ret += (u16)*(volatile u32 *)0x02FFFC3C;
    ret *= 13;
    return (u16)(30 + (ret % 10));
}



/*
 * sdk:      WM_GetOtherElements (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMOtherElements func_0208F05C(WMBssDesc *bssDesc)
{
    WMOtherElements elems;
    u8 *p_elem;
    int i;
    u16 curr_elem_len;
    u16 elems_len;
    u16 elems_len_counter;

    if (bssDesc->gameInfoLength != 0) {
        elems.count = 0;
        return elems;
    }

    elems.count = (u8)bssDesc->otherElementCount;
    if (elems.count == 0) {
        return elems;
    }
    if (elems.count > 16) {
        elems.count = 16;
    }

    p_elem = (u8 *)&bssDesc->gameInfo;
    elems_len = (u16)(bssDesc->length * sizeof(u16) - 64);
    elems_len_counter = 0;

    for (i = 0; i < elems.count; i++) {
        elems.element[i].id = p_elem[0];
        elems.element[i].length = p_elem[1];
        elems.element[i].body = p_elem + 2;
        curr_elem_len = (u16)(elems.element[i].length + 2);
        elems_len_counter += curr_elem_len;
        if (elems_len_counter > elems_len) {
            elems.count = 0;
            return elems;
        }
        p_elem += curr_elem_len;
    }
    return elems;
}

#define tgid_bak g_020A872C



/*
 * sdk:      WM_GetNextTgid (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           g_020A872C is the function-local static tgid_bak (_ZZ14WM_GetNextTgidvE8tgid_bak), initial 0x10000
 */
u16 func_0208F1B4(void)
{
    if (tgid_bak == 0x10000) {
        RTCTime rt[1];

        RTC_Init();
        if (RTC_GetTime(rt) == 0) {
            tgid_bak = (u16)(rt[0].second + (rt[0].minute << 8));
        }
    }
    tgid_bak = (u16)(tgid_bak + 1);
    return (u16)tgid_bak;
}
