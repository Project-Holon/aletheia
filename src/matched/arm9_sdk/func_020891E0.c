/*
 * function: RTC_ConvertSecondToDateTime
 * address:  0x020891E0
 * packet:   pkt_020891E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_ConvertSecondToDateTime (librtc.TWL.HYB.a convert.o)
 *
 * symbols:
 *   _ll_mod                        0x0209BE4C  arm
 *   RTCi_ConvertSecondToTime       0x02089160  arm
 *   _ll_sdiv                       0x0209BE5C  arm
 *   RTC_ConvertDayToDate           0x02089060  arm
 */

typedef unsigned long u32;
typedef long s32;
typedef long long s64;
typedef int BOOL;

typedef enum RTCWeek { RTC_WEEK_SUNDAY = 0, RTC_WEEK_MAX = 7 } RTCWeek;

typedef struct RTCDate { u32 year; u32 month; u32 day; RTCWeek week; } RTCDate;
typedef struct RTCTime { u32 hour; u32 minute; u32 second; } RTCTime;

void RTCi_ConvertSecondToTime(RTCTime *time, s32 sec);
void RTC_ConvertDayToDate(RTCDate *date, s32 day);

void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec)
{
    if (sec < 0) {
        sec = 0;
    } else if (sec > 3155759999LL) {
        sec = 3155759999LL;
    }
    RTCi_ConvertSecondToTime(time, (s32)(sec % 86400));
    RTC_ConvertDayToDate(date, (s32)(sec / 86400));
}
