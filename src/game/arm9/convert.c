/*
 * file:     convert.c
 * unit:     yes
 * function: RTC_ConvertDateToDay, RTCi_ConvertTimeToSecond, RTC_ConvertDateTimeToSecond, RTC_ConvertDayToDate, RTCi_ConvertSecondToTime, RTC_ConvertSecondToDateTime, func_02089274
 * address:  0x02088F58
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
 *   sDayOfYear                     0x020A86F4  data
 *   RTC_ConvertDateToDay           0x02088F58  arm
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

s32 RTC_ConvertDateToDay(RTCDate *date);
asm s32 RTCi_ConvertTimeToSecond(RTCTime *time);
s64 RTC_ConvertDateTimeToSecond(RTCDate *date, RTCTime *time);
void RTC_ConvertDayToDate(RTCDate *date, s32 day);
void RTCi_ConvertSecondToTime(RTCTime *time, s32 sec);
void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
RTCWeek RTC_GetDayOfWeek(RTCDate *date);
extern s32 sDayOfYear[12];



/*
 * sdk:      RTC_ConvertDateToDay (librtc.TWL.HYB.a convert.o)
 */
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


asm s32 RTCi_ConvertTimeToSecond(RTCTime *time)
{
    mov r1, #0x3c
    ldmia r0, {r2, r3}
    mla r3, r2, r1, r3
    ldr r0, [r0, #8]
    mla r0, r3, r1, r0
    bx lr
}



/*
 * sdk:      RTC_ConvertDateTimeToSecond (librtc.TWL.HYB.a convert.o)
 */
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




/*
 * sdk:      RTC_ConvertDayToDate (librtc.TWL.HYB.a convert.o)
 */
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




/*
 * sdk:      RTCi_ConvertSecondToTime (librtc.TWL.HYB.a convert.o)
 */
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




/*
 * sdk:      RTC_ConvertSecondToDateTime (librtc.TWL.HYB.a convert.o)
 */
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




RTCWeek RTC_GetDayOfWeek(RTCDate *date)
{
    int cent;
    int year = (int)(2000 + date->year);
    int month = (int)date->month;
    int day = (int)date->day;

    month -= 2;
    if (month < 1) {
        month += 12;
        --year;
    }
    cent = year / 100;
    year %= 100;
    return (RTCWeek)(((26 * month - 2) / 10 + day + year + year / 4 + cent / 4 + 5 * cent) % 7);
}
