/*
 * file:     unit_02090BC4.c
 * unit:     yes
 * function: func_02090BC4, func_02090C40, func_02090CD4, func_02090D98, func_02090DEC, func_02090E50
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
 *   tmpUserGameInfoBuf               0x02153b00 data
 *   g_02153B00                       0x02153b00 data
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_SendCommandDirect            0x0208e44c arm
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

typedef struct WMMeasureChannelReq {
    u16 apiid;
    u16 ccaMode;
    u16 edThreshold;
    u16 channel;
    u16 measureTime;
} WMMeasureChannelReq;

extern WMErrCode WMi_CheckIdle(void);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_SendCommandDirect(void *data, u32 length);
WMErrCode func_02090BC4(WMCallbackFunc callback, u16 wepmode, const u16 *wepkey);
WMErrCode func_02090C40(WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 *wepkey);
WMErrCode func_02090CD4(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr);
WMErrCode func_02090D98(WMCallbackFunc callback, u16 flag);
WMErrCode func_02090DEC(WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
WMErrCode func_02090E50(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);
extern u32 g_02153B00[32];


/*
 * sdk:      WM_SetWEPKey (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_02090BC4(WMCallbackFunc callback, u16 wepmode, const u16 *wepkey)
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
    result = WMi_SendCommand(20, 2, (u32)wepmode, (u32)wepkey);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}


/*
 * sdk:      WM_SetWEPKeyEx (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_02090C40(WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 *wepkey)
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
    result = WMi_SendCommand(39, 3, (u32)wepmode, (u32)wepkey, (u32)wepkeyid);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

#define tmpUserGameInfoBuf g_02153B00


/*
 * sdk:      WM_SetGameInfo (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           g_02153B00 is wm_etc.o's static tmpUserGameInfoBuf (u32[32])
 */
WMErrCode func_02090CD4(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr)
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

    MIi_CpuCopy16(userGameInfo, tmpUserGameInfoBuf, userGameInfoSize);
    DC_StoreRange(tmpUserGameInfoBuf, userGameInfoSize);

    WMi_SetCallbackTable(24, callback);
    result = WMi_SendCommand(24, 5, (u32)tmpUserGameInfoBuf, (u32)userGameInfoSize, ggid, (u32)tgid, (u32)attr);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}


/*
 * sdk:      WM_SetBeaconIndication (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_02090D98(WMCallbackFunc callback, u16 flag)
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
WMErrCode func_02090DEC(WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime)
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
WMErrCode func_02090E50(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime)
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
