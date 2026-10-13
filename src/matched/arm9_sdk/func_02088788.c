/*
 * function: RTC_Init
 * address:  0x02088788
 * packet:   pkt_02088788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_Init (librtc.TWL.HYB.a external.o)
 *
 * symbols:
 *   g_02151428                     0x02151428  data
 *   PXI_Init                       0x02088498  arm
 *   PXI_IsCallbackReady            0x020885EC  arm
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   RtcCommonCallback              0x02088A04  arm
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

void PXI_Init(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
void RtcCommonCallback(int tag, u32 data, BOOL err);

void RTC_Init(void)
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
