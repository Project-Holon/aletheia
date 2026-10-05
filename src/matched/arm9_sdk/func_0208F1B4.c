/*
 * function: func_0208F1B4
 * address:  0x0208F1B4
 * packet:   pkt_0208F1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_GetNextTgid (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           g_020A872C is the function-local static tgid_bak (_ZZ14WM_GetNextTgidvE8tgid_bak), initial 0x10000
 *
 * symbols:
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

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

extern void RTC_Init(void);
extern int RTC_GetTime(RTCTime *time);
extern u32 g_020A872C;
#define tgid_bak g_020A872C

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
