/*
 * function: WM_SetMPDataToPortEx
 * address:  0x0208FCB4
 * packet:   pkt_0208FCB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_mp.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Queues MP
 * send data on a port: checks the MP state, the connected children (on the
 * parent) and the buffer, flushes it and sends the SET_MP_DATA command.
 *
 * symbols:
 *   WMi_GetSystemWork   0x0208E4BC  arm
 *   WMi_CheckStateEx    0x0208E52C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   DC_StoreRange       0x020862D4  arm
 *   WMi_SendCommand     0x0208E3A0  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;

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

typedef enum WMApiid {
    WM_APIID_SET_MP_DATA = 15,
    WM_APIID_MAX = 0x7FFFFFFF
} WMApiid;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMStatus {
    u16 state;
    u8 pad002[0x7A];
    u32 *mp_sendBuf;
    u16 mp_sendBufSize;
    u16 mp_ackTime;
    u16 mp_waitAckFlag;
    u16 mp_readyBitmap;
    u8 pad088[0xFA];
    u16 child_bitmap;
    struct WMBssDesc *pInfoBuf;
    u16 aid;
} WMStatus;

typedef struct WMArm9Buf {
    struct WMArm7Buf *WM7;
    WMStatus *status;
} WMArm9Buf;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...);

WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData, u16 sendDataSize,
                               u16 destBitmap, u16 port, u16 prio)
{
    WMErrCode result;
    u16 childBitmap = 1;
    WMArm9Buf *p = WMi_GetSystemWork();
    WMStatus *status = p->status;

    result = WMi_CheckStateEx(2, 9, 10);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&status->aid, 2);
    if (status->aid == 0) {
        DC_InvalidateRange(&status->child_bitmap, 2);
        childBitmap = status->child_bitmap;
        DC_InvalidateRange(&status->mp_readyBitmap, 2);
    }

    if (sendData == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (childBitmap == 0) {
        return WM_ERRCODE_NO_ENTRY;
    }

    DC_InvalidateRange(&status->mp_sendBuf, 2);
    if ((u32 *)sendData == status->mp_sendBuf) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (sendDataSize > 512) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (sendDataSize == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange(sendData, sendDataSize);

    result = WMi_SendCommand(WM_APIID_SET_MP_DATA, 7, sendData, sendDataSize, destBitmap, port,
                             prio, callback, arg);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}
