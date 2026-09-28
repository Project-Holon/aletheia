/*
 * function: func_02090CD4
 * address:  0x02090CD4
 * packet:   pkt_02090CD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_SetGameInfo (libwm.TWL.HYB.a(wm_etc.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           g_02153B00 is wm_etc.o's static tmpUserGameInfoBuf (u32[32])
 *
 * symbols:
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   MIi_CpuCopy16                    0x02082a60 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   WMi_SendCommand                  0x0208e3a0 arm
 *   tmpUserGameInfoBuf               0x02153b00 data
 *   g_02153B00                       0x02153b00 data
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);
extern u32 g_02153B00[32];
#define tmpUserGameInfoBuf g_02153B00

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
