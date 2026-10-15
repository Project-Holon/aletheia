/*
 * function: RTCi_ConvertSecondToTime
 * address:  0x02089160
 * packet:   pkt_02089160
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTCi_ConvertSecondToTime (librtc.TWL.HYB.a convert.o)
 */

typedef unsigned long u32;
typedef long s32;
typedef long long s64;
typedef int BOOL;

typedef enum RTCWeek { RTC_WEEK_SUNDAY = 0, RTC_WEEK_MAX = 7 } RTCWeek;

typedef struct RTCDate { u32 year; u32 month; u32 day; RTCWeek week; } RTCDate;
typedef struct RTCTime { u32 hour; u32 minute; u32 second; } RTCTime;

void RTCi_ConvertSecondToTime(RTCTime *time, s32 sec)
{
    if (sec < 0) {
        sec = 0;
    }
    if (sec > 86399) {
        sec = 86399;
    }
    time->second = (u32)(sec % 60);
    time->minute = (u32)(sec / 60 % 60);
    time->hour = (u32)(sec / 60 / 60);
}
