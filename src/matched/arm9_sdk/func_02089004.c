/*
 * function: RTC_ConvertDateTimeToSecond
 * address:  0x02089004
 * packet:   pkt_02089004
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_ConvertDateTimeToSecond (librtc.TWL.HYB.a convert.o)
 *
 * symbols:
 *   RTC_ConvertDateToDay           0x02088F58  arm
 *   RTCi_ConvertTimeToSecond       0x02088FEC  arm
 */

typedef unsigned long u32;
typedef long s32;
typedef long long s64;
typedef int BOOL;

typedef enum RTCWeek { RTC_WEEK_SUNDAY = 0, RTC_WEEK_MAX = 7 } RTCWeek;

typedef struct RTCDate { u32 year; u32 month; u32 day; RTCWeek week; } RTCDate;
typedef struct RTCTime { u32 hour; u32 minute; u32 second; } RTCTime;

s32 RTC_ConvertDateToDay(RTCDate *date);
s32 RTCi_ConvertTimeToSecond(RTCTime *time);

s64 RTC_ConvertDateTimeToSecond(RTCDate *date, RTCTime *time)
{
    s32 day;
    s32 sec;

    day = RTC_ConvertDateToDay(date);
    if (day == -1) {
        return -1;
    }
    sec = RTCi_ConvertTimeToSecond(time);
    if (sec == -1) {
        return -1;
    }
    return (s64)day * 86400 + sec;
}
