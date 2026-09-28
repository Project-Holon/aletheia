/*
 * function: RTC_GetDayOfWeek
 * address:  0x02089274
 * packet:   pkt_02089274
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK librtc convert.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 */

typedef enum RTCWeek {
    RTC_WEEK_SUNDAY = 0,
    RTC_WEEK_MAX = 7
} RTCWeek;

typedef struct RTCDate {
    unsigned long year;
    unsigned long month;
    unsigned long day;
    RTCWeek week;
} RTCDate;

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
