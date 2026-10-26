/*
 * file:     wm_etc.c
 * unit:     yes
 * function: WM_SetWEPKey, WM_SetWEPKeyEx, WM_SetGameInfo, WM_SetBeaconIndication, WM_SetLifeTime, WM_MeasureChannel, WMi_CheckInitializedAfterMeasure
 * address:  0x02090BC4
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
 *   WMi_CheckIdle                    0x0208e4e8 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   WMi_SendCommand                  0x0208e3a0 arm
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   MIi_CpuCopy16                    0x02082a60 arm
 *   sWmEtcTmpUserGameInfoBuf               0x02153b00 data
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_SendCommandDirect            0x0208e44c arm
 *   WMi_CheckInitialized  0x0208E4CC  arm
 */
#include "../types.h"

#include "../sdk_os.h"

#include "../sdk_wm.h"

typedef struct WMMeasureChannelReq {
    u16 apiid;
    u16 ccaMode;
    u16 edThreshold;
    u16 channel;
    u16 measureTime;
} WMMeasureChannelReq;

#include "wm_system.h"
#include "os_cache.h"
#include "mi_memory.h"
WMErrCode WM_SetWEPKey(WMCallbackFunc callback, u16 wepmode, const u16 *wepkey);
WMErrCode WM_SetWEPKeyEx(WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 *wepkey);
WMErrCode WM_SetGameInfo(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr);
WMErrCode WM_SetBeaconIndication(WMCallbackFunc callback, u16 flag);
WMErrCode WM_SetLifeTime(WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
WMErrCode WM_MeasureChannel(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);
u32 WMi_CheckInitializedAfterMeasure(void);
extern u32 sWmEtcTmpUserGameInfoBuf[32];

/*
 * sdk:      WM_SetWEPKey (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_SetWEPKey(WMCallbackFunc callback, u16 wepmode, const u16 *wepkey)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (wepmode > 3) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (wepmode != 0) {
        if (wepkey == 0) {
            return WM_ERRCODE_INVALID_PARAM;
        }
        DC_StoreRange((void *)wepkey, 80);
    }

    WMi_SetCallbackTable(20, callback);
    result = WMi_SendCommand(20, 2, (u32)wepmode, wepkey);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_SetWEPKeyEx (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_SetWEPKeyEx(WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 *wepkey)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (wepmode > 3) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (wepmode != 0) {
        if (wepkey == 0) {
            return WM_ERRCODE_INVALID_PARAM;
        }
        DC_StoreRange((void *)wepkey, 80);
    }

    WMi_SetCallbackTable(39, callback);
    result = WMi_SendCommand(39, 3, (u32)wepmode, wepkey, (u32)wepkeyid);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_SetGameInfo (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           the buffer is wm_etc.o's static (u32[32])
 */
WMErrCode WM_SetGameInfo(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr)
{
    WMErrCode result;

    result = WMi_CheckStateEx(2, 7, 9);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (userGameInfo == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (userGameInfoSize > 0x70) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    MIi_CpuCopy16(userGameInfo, sWmEtcTmpUserGameInfoBuf, userGameInfoSize);
    DC_StoreRange(sWmEtcTmpUserGameInfoBuf, userGameInfoSize);

    WMi_SetCallbackTable(24, callback);
    result = WMi_SendCommand(24, 5, sWmEtcTmpUserGameInfoBuf, (u32)userGameInfoSize, ggid, (u32)tgid, (u32)attr);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_SetBeaconIndication (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_SetBeaconIndication(WMCallbackFunc callback, u16 flag)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (flag != 0 && flag != 1) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    WMi_SetCallbackTable(25, callback);
    result = WMi_SendCommand(25, 1, (u32)flag);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_SetLifeTime (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_SetLifeTime(WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(29, callback);
    result = WMi_SendCommand(29, 4, (u32)tableNumber, (u32)camLifeTime, (u32)frameLifeTime, (u32)mpLifeTime);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_MeasureChannel (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_MeasureChannel(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime)
{
    WMErrCode result;
    WMMeasureChannelReq Req;

    (void)WMi_GetSystemWork();

    result = WMi_CheckStateEx(1, 2);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(30, callback);

    Req.apiid = 30;
    Req.ccaMode = ccaMode;
    Req.edThreshold = edThreshold;
    Req.channel = channel;
    Req.measureTime = measureTime;

    result = WMi_SendCommandDirect(&Req, sizeof(Req));
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

u32 WMi_CheckInitializedAfterMeasure(void)
{
    return WMi_CheckInitialized();
}
