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
#include "../types.h"

#include "../sdk_os.h"

#include "../sdk_wm.h"

#include "wm_system.h"
#include "os_cache.h"
#include "mi_memory.h"
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
