/*
 * file:     external.c
 * unit:     yes
 * function: RTC_Init, RTC_GetDateAsync, RTC_GetDate, RTC_GetTimeAsync, RTC_GetTime, RTC_GetDateTimeAsync, RTC_GetDateTime, RTCEXi_GetCommonCallback, RtcCommonCallback, RtcBCD2HEX, RtcGetResultCallback, RtcWaitBusy
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
 * Unlabelled 12-byte ARM pointer thunk in a .word run:
 *   ldr r0, [pc, #0]; bx lr; .word rtcWork
 * Same shape as MICEXi_GetLimitedSamplingCallback and, for the same reason, witnessable only as a
 * `matched` entry.  It unblocks the TWL park src/pending/RTCEXi_CommonCallback.c.
 * The pointer word resolves `literal x1` against the duplicate 0x0215142C
 * word at 0x02088EE8.
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   g_02151428                     0x02151428  data
 *   PXI_Init                       0x02088498  arm
 *   PXI_IsCallbackReady            0x020885EC  arm
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
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
 *   rtcWork  0x0215142C  arm
 *   RTC_GetDayOfWeek           0x02089274  arm
 *   RTCi_WriteRawStatus2Async  0x02088F1C  arm
 *   OS_IsRunOnTwl              0x02085D3C  arm
 *   RTCEXi_CommonCallback      0x02700000  arm  twl
 *   g_0215142C 0x0215142C data
 */
#define RTC_RAW_DATE   ((RTCRawDate *)0x02FFFDE8)
#define RTC_RAW_TIME   ((RTCRawTime *)0x02FFFDEC)
#define RTC_RAW_STAT2  ((RTCRawStatus2 *)0x02FFFDEA)
#define RTC_RAW_ALARM  ((RTCRawAlarm *)0x02FFFDEC)
typedef unsigned int u32;

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

typedef enum RTCPxiResult {
    RTC_PXI_RESULT_SUCCESS = 0,
    RTC_PXI_RESULT_INVALID_COMMAND,
    RTC_PXI_RESULT_ILLEGAL_STATUS,
    RTC_PXI_RESULT_BUSY,
    RTC_PXI_RESULT_FATAL_ERROR,
    RTC_PXI_RESULT_MAX
} RTCPxiResult;

typedef enum RTCAlarmStatus { RTC_ALARM_STATUS_OFF = 0, RTC_ALARM_STATUS_ON, RTC_ALARM_STATUS_MAX } RTCAlarmStatus;

typedef struct RTCAlarmParam { RTCWeek week; u32 hour; u32 minute; u32 enable; } RTCAlarmParam;

typedef struct RTCRawDate {
    u32 year:8;
    u32 month:5;
    u32 dummy0:3;
    u32 day:6;
    u32 dummy1:2;
    u32 week:3;
    u32 dummy2:5;
} RTCRawDate;

typedef struct RTCRawTime {
    u32 hour:6;
    u32 afternoon:1;
    u32 dummy0:1;
    u32 minute:7;
    u32 dummy1:1;
    u32 second:7;
    u32 dummy2:9;
} RTCRawTime;

typedef struct RTCRawStatus2 {
    u16 intr_mode:4;
    u16 dummy0:2;
    u16 intr2_enable:1;
    u16 test:1;
    u16 dummy1:8;
} RTCRawStatus2;

typedef struct RTCRawAlarm {
    u32 week:3;
    u32 dummy0:3;
    u32 afternoon:1;
    u32 enable_week:1;
    u32 hour:6;
    u32 dummy1:1;
    u32 enable_hour:1;
    u32 minute:7;
    u32 enable_minute:1;
    u32 dummy2:8;
} RTCRawAlarm;

void PXI_Init(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
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
extern void rtcWork(void);
extern RTCWeek RTC_GetDayOfWeek(RTCDate *date);
extern int RTCi_WriteRawStatus2Async(void);
extern int OS_IsRunOnTwl(void);
extern RTCResult RTCEXi_CommonCallback(void);
extern void g_0215142C(void);
void RTC_Init(void);
RTCResult RTC_GetDate(RTCDate *date);
RTCResult RTC_GetTime(RTCTime *time);
RTCResult RTC_GetDateTime(RTCDate *date, RTCTime *time);
void *RTCEXi_GetCommonCallback(void);
void RtcCommonCallback(int tag, u32 data, int err);
unsigned long RtcBCD2HEX(unsigned long bcd);
extern RtcBss g_02151428;



/*
 * sdk:      RTC_Init (librtc.TWL.HYB.a external.o)
 */
void RTC_Init(void)
{
    if (g_02151428.rtcInitialized) {
        return;
    }
    g_02151428.rtcInitialized = 1;

    g_02151428.rtcWork.lock = 0;
    g_02151428.rtcWork.callback = 0;
    g_02151428.rtcWork.interrupt = 0;
    g_02151428.rtcWork.buffer[0] = 0;
    g_02151428.rtcWork.buffer[1] = 0;

    PXI_Init();
    while (!PXI_IsCallbackReady(5, 1)) {
    }
    PXI_SetFifoRecvCallback(5, RtcCommonCallback);
}



/*
 * sdk:      RTC_GetDateAsync (librtc.TWL.HYB.a external.o)
 */
RTCResult RTC_GetDateAsync(RTCDate *date, RTCCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (g_02151428.rtcWork.lock != 0) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    g_02151428.rtcWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    g_02151428.rtcWork.sequence = 0;
    g_02151428.rtcWork.index = 0;
    g_02151428.rtcWork.buffer[0] = (void *)date;
    g_02151428.rtcWork.callback = callback;
    g_02151428.rtcWork.callbackArg = arg;

    if (RTCi_ReadRawDateAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        g_02151428.rtcWork.lock = 0;
        return RTC_RESULT_SEND_ERROR;
    }
}



/*
 * sdk:      RTC_GetDate (librtc.TWL.HYB.a external.o)
 */
RTCResult RTC_GetDate(RTCDate *date)
{
    g_02151428.rtcWork.commonResult = RTC_GetDateAsync(date, RtcGetResultCallback, 0);
    if (g_02151428.rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return g_02151428.rtcWork.commonResult;
}



/*
 * sdk:      RTC_GetTimeAsync (librtc.TWL.HYB.a external.o)
 */
RTCResult RTC_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (g_02151428.rtcWork.lock != 0) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    g_02151428.rtcWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    g_02151428.rtcWork.sequence = 1;
    g_02151428.rtcWork.index = 0;
    g_02151428.rtcWork.buffer[0] = (void *)time;
    g_02151428.rtcWork.callback = callback;
    g_02151428.rtcWork.callbackArg = arg;

    if (RTCi_ReadRawTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        g_02151428.rtcWork.lock = 0;
        return RTC_RESULT_SEND_ERROR;
    }
}



/*
 * sdk:      RTC_GetTime (catalog: RTC_GetDate) (librtc.TWL.HYB.a external.o)
 */
RTCResult RTC_GetTime(RTCTime *time)
{
    g_02151428.rtcWork.commonResult = RTC_GetTimeAsync(time, RtcGetResultCallback, 0);
    if (g_02151428.rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return g_02151428.rtcWork.commonResult;
}



/*
 * sdk:      RTC_GetDateTimeAsync (librtc.TWL.HYB.a external.o)
 */
RTCResult RTC_GetDateTimeAsync(RTCDate *date, RTCTime *time, RTCCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (g_02151428.rtcWork.lock != 0) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    g_02151428.rtcWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    g_02151428.rtcWork.sequence = 2;
    g_02151428.rtcWork.index = 0;
    g_02151428.rtcWork.buffer[0] = (void *)date;
    g_02151428.rtcWork.buffer[1] = (void *)time;
    g_02151428.rtcWork.callback = callback;
    g_02151428.rtcWork.callbackArg = arg;

    if (RTCi_ReadRawDateTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        g_02151428.rtcWork.lock = 0;
        return RTC_RESULT_SEND_ERROR;
    }
}



/*
 * sdk:      RTC_GetDateTime (catalog: RTC_GetAlarmParam) (librtc.TWL.HYB.a external.o)
 */
RTCResult RTC_GetDateTime(RTCDate *date, RTCTime *time)
{
    g_02151428.rtcWork.commonResult = RTC_GetDateTimeAsync(date, time, RtcGetResultCallback, 0);
    if (g_02151428.rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return g_02151428.rtcWork.commonResult;
}


void *RTCEXi_GetCommonCallback(void)
{
    return (void *)rtcWork;
}




void RtcCommonCallback(int tag, u32 data, int err)
{
    u8 command;
    RTCPxiResult pxiresult;
    RTCResult result;

    if (err) {
        if (g_02151428.rtcWork.index)
            g_02151428.rtcWork.index = 0;
        if (g_02151428.rtcWork.lock != 0)
            g_02151428.rtcWork.lock = 0;
        if (g_02151428.rtcWork.callback) {
            RTCCallback cb = g_02151428.rtcWork.callback;
            g_02151428.rtcWork.callback = 0;
            cb(RTC_RESULT_FATAL_ERROR, g_02151428.rtcWork.callbackArg);
        }
        return;
    }

    command = (u8)((data & 0x7F00) >> 8);
    pxiresult = (RTCPxiResult)(u8)(data & 0xFF);

    if (command == 0x30) {
        if (g_02151428.rtcWork.interrupt)
            g_02151428.rtcWork.interrupt();
        return;
    }

    if (pxiresult == RTC_PXI_RESULT_SUCCESS) {
        result = RTC_RESULT_SUCCESS;
        switch (g_02151428.rtcWork.sequence) {
        case 0:
            {
                RTCDate *pDst = (RTCDate *)g_02151428.rtcWork.buffer[0];
                RTCRawDate *pSrc = RTC_RAW_DATE;
                pDst->year = RtcBCD2HEX(pSrc->year);
                pDst->month = RtcBCD2HEX(pSrc->month);
                pDst->day = RtcBCD2HEX(pSrc->day);
                pDst->week = RTC_GetDayOfWeek(pDst);
            }
            break;
        case 1:
            {
                RTCTime *pDst = (RTCTime *)g_02151428.rtcWork.buffer[0];
                RTCRawTime *pSrc = RTC_RAW_TIME;
                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->second = RtcBCD2HEX(pSrc->second);
            }
            break;
        case 2:
            {
                RTCDate *pDst = (RTCDate *)g_02151428.rtcWork.buffer[0];
                RTCRawDate *pSrc = RTC_RAW_DATE;
                pDst->year = RtcBCD2HEX(*(u32 *)pSrc & 0xFF);
                pDst->month = RtcBCD2HEX(pSrc->month);
                pDst->day = RtcBCD2HEX(pSrc->day);
                pDst->week = RTC_GetDayOfWeek(pDst);
            }
            {
                RTCTime *pDst = (RTCTime *)g_02151428.rtcWork.buffer[1];
                RTCRawTime *pSrc = (RTCRawTime *)(RTC_RAW_DATE + 1);
                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->second = RtcBCD2HEX(pSrc->second);
            }
            break;
        case 3:
        case 4:
        case 5:
            break;
        case 6:
            {
                RTCAlarmStatus *pDst = (RTCAlarmStatus *)g_02151428.rtcWork.buffer[0];
                if (RTC_RAW_STAT2->intr_mode == 4)
                    *pDst = RTC_ALARM_STATUS_ON;
                else
                    *pDst = RTC_ALARM_STATUS_OFF;
            }
            break;
        case 7:
            {
                RTCAlarmStatus *pDst = (RTCAlarmStatus *)g_02151428.rtcWork.buffer[0];
                if (RTC_RAW_STAT2->intr2_enable)
                    *pDst = RTC_ALARM_STATUS_ON;
                else
                    *pDst = RTC_ALARM_STATUS_OFF;
            }
            break;
        case 8:
            {
                RTCAlarmParam *pDst = (RTCAlarmParam *)g_02151428.rtcWork.buffer[0];
                RTCRawAlarm *pSrc = RTC_RAW_ALARM;
                pDst->week = (RTCWeek)pSrc->week;
                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->enable = 0;
                if (pSrc->enable_week)
                    pDst->enable += 1;
                if (RTC_RAW_ALARM->enable_hour)
                    pDst->enable += 2;
                if (RTC_RAW_ALARM->enable_minute)
                    pDst->enable += 4;
            }
            break;
        case 9:
            if (g_02151428.rtcWork.index == 0) {
                if (*(RTCAlarmStatus *)g_02151428.rtcWork.buffer[0] == RTC_ALARM_STATUS_ON) {
                    if (RTC_RAW_STAT2->intr_mode != 4) {
                        g_02151428.rtcWork.index++;
                        RTC_RAW_STAT2->intr_mode = 4;
                        if (!RTCi_WriteRawStatus2Async()) {
                            g_02151428.rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {
                    if (RTC_RAW_STAT2->intr_mode != 0) {
                        g_02151428.rtcWork.index++;
                        RTC_RAW_STAT2->intr_mode = 0;
                        if (!RTCi_WriteRawStatus2Async()) {
                            g_02151428.rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                g_02151428.rtcWork.index = 0;
            }
            break;
        case 10:
            if (g_02151428.rtcWork.index == 0) {
                if (*(RTCAlarmStatus *)g_02151428.rtcWork.buffer[0] == RTC_ALARM_STATUS_ON) {
                    if (!RTC_RAW_STAT2->intr2_enable) {
                        g_02151428.rtcWork.index++;
                        RTC_RAW_STAT2->intr2_enable = 1;
                        if (!RTCi_WriteRawStatus2Async()) {
                            g_02151428.rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {
                    if (RTC_RAW_STAT2->intr2_enable) {
                        g_02151428.rtcWork.index++;
                        RTC_RAW_STAT2->intr2_enable = 0;
                        if (!RTCi_WriteRawStatus2Async()) {
                            g_02151428.rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                g_02151428.rtcWork.index = 0;
            }
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
        default:
            if (OS_IsRunOnTwl() == 1) {
                result = RTCEXi_CommonCallback();
            } else {
                g_02151428.rtcWork.index = 0;
                result = RTC_RESULT_INVALID_COMMAND;
            }
        }
    } else {
        g_02151428.rtcWork.index = 0;
        switch (pxiresult) {
        case RTC_PXI_RESULT_INVALID_COMMAND:
            result = RTC_RESULT_INVALID_COMMAND;
            break;
        case RTC_PXI_RESULT_ILLEGAL_STATUS:
            result = RTC_RESULT_ILLEGAL_STATUS;
            break;
        case RTC_PXI_RESULT_BUSY:
            result = RTC_RESULT_BUSY;
            break;
        case RTC_PXI_RESULT_FATAL_ERROR:
        default:
            result = RTC_RESULT_FATAL_ERROR;
        }
    }

    if (g_02151428.rtcWork.index == 0) {
        if (g_02151428.rtcWork.lock != 0)
            g_02151428.rtcWork.lock = 0;
        if (g_02151428.rtcWork.callback) {
            RTCCallback cb = g_02151428.rtcWork.callback;
            g_02151428.rtcWork.callback = 0;
            cb(result, g_02151428.rtcWork.callbackArg);
        }
    }
}



unsigned long RtcBCD2HEX(unsigned long bcd)
{
    unsigned long hex = 0;
    long i;
    long w;

    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 0xF) >= 10)
            return 0;
    }
    for (i = 0, w = 1; i < 8; i++) {
        hex += ((bcd >> (i * 4)) & 0xF) * w;
        w *= 10;
    }
    return hex;
}




/*
 * note:     librtc external.o RtcGetResultCallback.
 */
void RtcGetResultCallback(RTCResult result, void *arg)
{
    g_02151428.rtcWork.commonResult = result;
}




/* hand-written in the original: spin-wait on the lock word with the address in ip; mwccarm never picks ip for a leaf load (9 C variants tried) */
asm void RtcWaitBusy(void)
{
    ldr ip, =g_0215142C
loc_02088ED8:
    ldr	r0, [ip]
    cmp	r0, #1
    beq loc_02088ED8
    bx	lr
}
