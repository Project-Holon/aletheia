/*
 * file:     wm_dcf.c
 * unit:     yes
 * function: WM_StartDCF, WM_SetDCFData, WM_EndDCF
 * address:  0x0208FE64
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
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   DC_InvalidateRange               0x020862b8 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   WMi_SendCommand                  0x0208e3a0 arm
 *   MI_CpuCopy8                      0x02082d44 arm
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
    u8 pad02[0xE];
    u32 dcf_flag;
} WMStatus;

extern void *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
WMErrCode WM_SetDCFData(WMCallbackFunc callback, const u8 *destAdr, const u16 *sendData, u16 sendDataSize);
WMErrCode WM_EndDCF(WMCallbackFunc callback);


/*
 * sdk:      WM_StartDCF (libwm.TWL.HYB.a(wm_dcf.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_StartDCF(WMCallbackFunc callback, struct WMDcfRecvBuf *recvBuf, u16 recvBufSize)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(1, 8);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&p->status->dcf_flag, 4);
    if (p->status->dcf_flag == 1) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if (recvBufSize < 16) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (recvBuf == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange(recvBuf, recvBufSize);

    WMi_SetCallbackTable(17, callback);
    result = WMi_SendCommand(17, 2, (u32)recvBuf, (u32)recvBufSize);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}


/*
 * sdk:      WM_SetDCFData (libwm.TWL.HYB.a(wm_dcf.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_SetDCFData(WMCallbackFunc callback, const u8 *destAdr, const u16 *sendData, u16 sendDataSize)
{
    WMErrCode result;
    u32 wMac[2];
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(1, 11);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&p->status->dcf_flag, 4);
    if (p->status->dcf_flag == 0) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if (sendDataSize > 1508) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange((void *)sendData, sendDataSize);

    WMi_SetCallbackTable(18, callback);
    MI_CpuCopy8(destAdr, wMac, 6);
    result = WMi_SendCommand(18, 4, wMac[0], wMac[1], (u32)sendData, (u32)sendDataSize);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}


/*
 * sdk:      WM_EndDCF (libwm.TWL.HYB.a(wm_dcf.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_EndDCF(WMCallbackFunc callback)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(1, 11);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&p->status->dcf_flag, 4);
    if (p->status->dcf_flag == 0) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    WMi_SetCallbackTable(19, callback);
    result = WMi_SendCommand(19, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}
