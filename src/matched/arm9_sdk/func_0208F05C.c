/*
 * function: func_0208F05C
 * address:  0x0208F05C
 * packet:   pkt_0208F05C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_GetOtherElements (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:

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
