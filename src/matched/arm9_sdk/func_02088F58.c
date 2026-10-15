/*
 * function: RTC_ConvertDateToDay
 * address:  0x02088F58
 * packet:   pkt_02088F58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_ConvertDateToDay (librtc.TWL.HYB.a convert.o)
 *
 * symbols:
 *   sDayOfYear                     0x020A86F4  data
 */

typedef unsigned long u32;
typedef long s32;
typedef long long s64;
typedef int BOOL;

typedef enum RTCWeek { RTC_WEEK_SUNDAY = 0, RTC_WEEK_MAX = 7 } RTCWeek;

typedef struct RTCDate { u32 year; u32 month; u32 day; RTCWeek week; } RTCDate;
typedef struct RTCTime { u32 hour; u32 minute; u32 second; } RTCTime;

extern s32 sDayOfYear[12];

s32 RTC_ConvertDateToDay(RTCDate *date)
{
    s32 dayNum;

    if (date->year >= 100 || date->month < 1 || date->month > 12 ||
        date->day < 1 || date->day > 31 || date->week >= RTC_WEEK_MAX ||
        date->month < 1 || date->month > 12) {
        return -1;
    }
    dayNum = (s32)(date->day - 1) + sDayOfYear[date->month - 1];
    if (date->month >= 3 && (date->year & 3) == 0) {
        dayNum++;
    }
    return (s32)(date->year * 365 + dayNum + (date->year + 3) / 4);
}
