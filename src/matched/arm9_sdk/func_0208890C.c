/*
 * function: RTC_GetTime
 * address:  0x0208890C
 * packet:   pkt_0208890C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_GetTime (catalog: RTC_GetDate) (librtc.TWL.HYB.a external.o)
 *
 * symbols:
 *   g_02151428                     0x02151428  data
 *   RTC_GetTimeAsync             0x0208889C  arm
 *   RtcWaitBusy                    0x02088ED4  arm
 *   RtcGetResultCallback           0x02088EC4  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum RTCResult {
    RTC_RESULT_SUCCESS = 0,
    RTC_RESULT_BUSY,
    RTC_RESULT_ILLEGAL_PARAMETER,
    RTC_RESULT_SEND_ERROR,
    RTC_RESULT_INVALID_COMMAND,
    RTC_RESULT_ILLEGAL_STATUS,
    RTC_RESULT_FATAL_ERROR,
    RTC_RESULT_MAX
} RTCResult;

typedef enum RTCWeek { RTC_WEEK_SUNDAY = 0, RTC_WEEK_MAX = 7 } RTCWeek;

typedef struct RTCDate { u32 year; u32 month; u32 day; RTCWeek week; } RTCDate;
typedef struct RTCTime { u32 hour; u32 minute; u32 second; } RTCTime;

typedef void (*RTCCallback)(RTCResult result, void *arg);
typedef void (*RTCInterrupt)(void);

typedef struct RTCWork {
    u32 lock;
    RTCCallback callback;
    void *buffer[2];
    void *callbackArg;
    u32 sequence;
    u32 index;
    RTCInterrupt interrupt;
    RTCResult commonResult;
} RTCWork;

/* external.o .bss: rtcInitialized at +0, rtcWork at +4, one section-relative pool word */
typedef struct RtcBss {
    u16 rtcInitialized;
    RTCWork rtcWork;
} RtcBss;

extern RtcBss g_02151428;
#define rtcWork (g_02151428.rtcWork)

RTCResult RTC_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg);
void RtcWaitBusy(void);
void RtcGetResultCallback(RTCResult result, void *arg);

RTCResult RTC_GetTime(RTCTime *time)
{
    rtcWork.commonResult = RTC_GetTimeAsync(time, RtcGetResultCallback, 0);
    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return rtcWork.commonResult;
}
