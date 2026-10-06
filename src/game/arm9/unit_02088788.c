/*
 * file:     unit_02088788.c
 * unit:     yes
 * function: func_02088788, func_020887F4, func_02088864, func_0208889C, func_0208890C, func_02088944, func_020889C0
 * address:  0x02088788
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
 *   g_02151428                     0x02151428  data
 *   PXI_Init                       0x02088498  arm
 *   PXI_IsCallbackReady            0x020885EC  arm
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   RtcCommonCallback              0x02088A04  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   RTCi_ReadRawDateAsync      0x02088EFC  arm
 *   RTC_GetDateAsync               0x020887F4  arm
 *   RtcWaitBusy                    0x02088ED4  arm
 *   RtcGetResultCallback           0x02088EC4  arm
 *   RTCi_ReadRawTimeAsync      0x02088F0C  arm
 *   RTC_GetTimeAsync             0x0208889C  arm
 *   RTCi_ReadRawDateTimeAsync      0x02088EEC  arm
 *   RTC_GetDateTimeAsync             0x02088944  arm
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

void PXI_Init(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
void RtcCommonCallback(int tag, u32 data, BOOL err);
OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
BOOL RTCi_ReadRawDateAsync(void);
RTCResult RTC_GetDateAsync(RTCDate *date, RTCCallback callback, void *arg);
void RtcWaitBusy(void);
void RtcGetResultCallback(RTCResult result, void *arg);
BOOL RTCi_ReadRawTimeAsync(void);
RTCResult RTC_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg);
BOOL RTCi_ReadRawDateTimeAsync(void);
RTCResult RTC_GetDateTimeAsync(RTCDate *date, RTCTime *time, RTCCallback callback, void *arg);
void func_02088788(void);
RTCResult func_020887F4(RTCDate *date, RTCCallback callback, void *arg);
RTCResult func_02088864(RTCDate *date);
RTCResult func_0208889C(RTCTime *time, RTCCallback callback, void *arg);
RTCResult func_0208890C(RTCTime *time);
RTCResult func_02088944(RTCDate *date, RTCTime *time, RTCCallback callback, void *arg);
RTCResult func_020889C0(RTCDate *date, RTCTime *time);
extern RtcBss g_02151428;

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_Init (librtc.TWL.HYB.a external.o)
 */
void func_02088788(void)
{
    if (g_02151428.rtcInitialized) {
        return;
    }
    g_02151428.rtcInitialized = 1;

    rtcWork.lock = 0;
    rtcWork.callback = 0;
    rtcWork.interrupt = 0;
    rtcWork.buffer[0] = 0;
    rtcWork.buffer[1] = 0;

    PXI_Init();
    while (!PXI_IsCallbackReady(5, 1)) {
    }
    PXI_SetFifoRecvCallback(5, RtcCommonCallback);
}

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_GetDateAsync (librtc.TWL.HYB.a external.o)
 */
RTCResult func_020887F4(RTCDate *date, RTCCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (rtcWork.lock != 0) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    rtcWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    rtcWork.sequence = 0;
    rtcWork.index = 0;
    rtcWork.buffer[0] = (void *)date;
    rtcWork.callback = callback;
    rtcWork.callbackArg = arg;

    if (RTCi_ReadRawDateAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        rtcWork.lock = 0;
        return RTC_RESULT_SEND_ERROR;
    }
}

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_GetDate (librtc.TWL.HYB.a external.o)
 */
RTCResult func_02088864(RTCDate *date)
{
    rtcWork.commonResult = RTC_GetDateAsync(date, RtcGetResultCallback, 0);
    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return rtcWork.commonResult;
}

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_GetTimeAsync (librtc.TWL.HYB.a external.o)
 */
RTCResult func_0208889C(RTCTime *time, RTCCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (rtcWork.lock != 0) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    rtcWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    rtcWork.sequence = 1;
    rtcWork.index = 0;
    rtcWork.buffer[0] = (void *)time;
    rtcWork.callback = callback;
    rtcWork.callbackArg = arg;

    if (RTCi_ReadRawTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        rtcWork.lock = 0;
        return RTC_RESULT_SEND_ERROR;
    }
}

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_GetTime (catalog: RTC_GetDate) (librtc.TWL.HYB.a external.o)
 */
RTCResult func_0208890C(RTCTime *time)
{
    rtcWork.commonResult = RTC_GetTimeAsync(time, RtcGetResultCallback, 0);
    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return rtcWork.commonResult;
}

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_GetDateTimeAsync (librtc.TWL.HYB.a external.o)
 */
RTCResult func_02088944(RTCDate *date, RTCTime *time, RTCCallback callback, void *arg)
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

#define rtcWork (g_02151428.rtcWork)


/*
 * sdk:      RTC_GetDateTime (catalog: RTC_GetAlarmParam) (librtc.TWL.HYB.a external.o)
 */
RTCResult func_020889C0(RTCDate *date, RTCTime *time)
{
    rtcWork.commonResult = RTC_GetDateTimeAsync(date, time, RtcGetResultCallback, 0);
    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return rtcWork.commonResult;
}
