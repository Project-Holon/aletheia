/*
 * function: RTC_ConvertDayToDate
 * address:  0x02089060
 * packet:   pkt_02089060
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RTC_ConvertDayToDate (librtc.TWL.HYB.a convert.o)
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

void RTC_ConvertDayToDate(RTCDate *date, s32 day)
{
    u32 year;
    s32 month;
    s32 prev;

    if (day < 0) {
        day = 0;
    }
    if (day > 36524) {
        day = 36524;
    }
    date->week = (RTCWeek)((day + 6) % 7);

    for (year = 0; year < 99; year++) {
        prev = day;
        day -= ((year & 3) == 0) ? 366 : 365;
        if (day < 0) {
            day = prev;
            break;
        }
    }
    date->year = year;
    if (day > 365) {
        day = 365;
    }
    if ((year & 3) == 0) {
        if (day < 60) {
            if (day < 31) {
                month = 1;
            } else {
                day -= 31;
                month = 2;
            }
            date->month = (u32)month;
            date->day = (u32)(day + 1);
            return;
        } else {
            day--;
        }
    }
    for (month = 11; month >= 0; month--) {
        if (day >= sDayOfYear[month]) {
            date->month = (u32)(month + 1);
            date->day = (u32)(day - sDayOfYear[month] + 1);
            return;
        }
    }
}
