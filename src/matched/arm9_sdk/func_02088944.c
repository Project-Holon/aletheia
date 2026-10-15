/*
 * function: RTC_GetDateTimeAsync
 * address:  0x02088944
 * packet:   pkt_02088944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_GetDateTimeAsync (librtc.TWL.HYB.a external.o)
 *
 * symbols:
 *   g_02151428                     0x02151428  data
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   RTCi_ReadRawDateTimeAsync      0x02088EEC  arm
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

OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
BOOL RTCi_ReadRawDateTimeAsync(void);

RTCResult RTC_GetDateTimeAsync(RTCDate *date, RTCTime *time, RTCCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (rtcWork.lock != 0) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    rtcWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    rtcWork.sequence = 2;
    rtcWork.index = 0;
    rtcWork.buffer[0] = (void *)date;
    rtcWork.buffer[1] = (void *)time;
    rtcWork.callback = callback;
    rtcWork.callbackArg = arg;

    if (RTCi_ReadRawDateTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        rtcWork.lock = 0;
        return RTC_RESULT_SEND_ERROR;
    }
}
