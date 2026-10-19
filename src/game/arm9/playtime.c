/*
 * file:     playtime.c
 * unit:     yes
 * function: PLAYTIME_Create, PLAYTIME_Init, PLAYTIME_AddSeconds, PLAYTIME_Copy, PLAYTIME_GetHours, PLAYTIME_GetMinutes, PLAYTIME_GetSeconds, PLAYTIME_SetStampNow, PLAYTIME_GetStampYear, PLAYTIME_GetStampMonth, PLAYTIME_GetStampDay, PLAYTIME_GetStampHour, PLAYTIME_GetStampMinute, PLAYTIME_GetStamp, PLAYTIME_SetStamp
 * address:  0x0200857C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from playtime.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   RTC_GetDate         0x02088864  arm
 *   RTC_GetTime         0x0208890C  arm
 *   playtime_file_name   0x020A70B8  data
 *   PLAYTIME_Init    0x020085A0  thumb
 */
#include "config_shared_types.h"
#include "playtime_shared_types.h"

struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void RTC_GetDate(struct RTCDate *date);

extern void RTC_GetTime(struct RTCTime *time);

/* The debug allocator: heap, size, clear, __FILE__ string, __LINE__. */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern const char playtime_file_name[];

void PLAYTIME_Init(struct PlayTime *playtime);

/*
 * Play-time counter: hours (saturating at 999), minutes, seconds and language packed
 * calendar stamp.  The stamp widths agree three ways: the AND masks in
 * PLAYTIME_Init, the shift pairs in the getters at 0x020086C8 and on, and the
 * RTCDate / RTCTime fields that PLAYTIME_SetStampNow feeds it from.
 *
 * The four unsigned divisions in PLAYTIME_AddSeconds compile to calls to the
 * compiler runtime helper _u32_div_f (0x0209C2B0).  `language / version` and `language % version` on
 * the same operands give two separate calls: the helper returns the quotient
 * in r0 and the remainder in r1, but the compiler does not common them up.
 */
void *PLAYTIME_Create(u32 heap_id)
{
    struct PlayTime *playtime = GFL_HEAP_Alloc(heap_id, sizeof(struct PlayTime), 1,
                                       playtime_file_name, 32);
    PLAYTIME_Init(playtime);
    return playtime;
}

void PLAYTIME_Init(struct PlayTime *playtime)
{
    playtime->hours        = 0;
    playtime->minutes      = 0;
    playtime->seconds      = 0;
    playtime->stamp.year   = 0;
    playtime->stamp.month  = 0;
    playtime->stamp.day    = 0;
    playtime->stamp.hour   = 0;
    playtime->stamp.minute = 0;
}

/* Add `seconds_to_add` seconds, carrying into minutes and hours and saturating at
 * 999:59:59.  The leading guard is the saturation test: once the counter is
 * full the object is left untouched. */
void PLAYTIME_AddSeconds(struct PlayTime *playtime, u32 seconds_to_add)
{
    u32 hours, minutes, seconds;

    hours = playtime->hours;
    if (hours == 999 && playtime->minutes == 59 && playtime->seconds == 59) {
        return;
    }
    seconds = playtime->seconds + seconds_to_add;
    minutes = playtime->minutes;
    if (seconds > 59) {
        minutes += seconds / 60;
        seconds = seconds % 60;
        if (minutes > 59) {
            hours += minutes / 60;
            minutes = minutes % 60;
            if (hours >= 999) {
                hours = 999;
                minutes = 59;
                seconds = 59;
            }
        }
    }
    playtime->hours   = hours;
    playtime->minutes = minutes;
    playtime->seconds = seconds;
}

void PLAYTIME_Copy(struct PlayTime *dest, const struct PlayTime *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PlayTime));
}

u16 PLAYTIME_GetHours(const struct PlayTime *playtime)
{
    return playtime->hours;
}

u8 PLAYTIME_GetMinutes(const struct PlayTime *playtime)
{
    return playtime->minutes;
}

u8 PLAYTIME_GetSeconds(const struct PlayTime *playtime)
{
    return playtime->seconds;
}

/* Stamp the object with the wall clock. */
void PLAYTIME_SetStampNow(struct PlayTime *playtime)
{
    struct RTCDate date;
    struct RTCTime time;

    RTC_GetDate(&date);
    RTC_GetTime(&time);

    playtime->stamp.year   = date.year;
    playtime->stamp.month  = date.month;
    playtime->stamp.day    = date.day;
    playtime->stamp.hour   = time.hour;
    playtime->stamp.minute = time.minute;
}

u32 PLAYTIME_GetStampYear(const struct PlayTime *playtime)
{
    return playtime->stamp.year;
}

u32 PLAYTIME_GetStampMonth(const struct PlayTime *playtime)
{
    return playtime->stamp.month;
}

u32 PLAYTIME_GetStampDay(const struct PlayTime *playtime)
{
    return playtime->stamp.day;
}

u32 PLAYTIME_GetStampHour(const struct PlayTime *playtime)
{
    return playtime->stamp.hour;
}

u32 PLAYTIME_GetStampMinute(const struct PlayTime *playtime)
{
    return playtime->stamp.minute;
}

void PLAYTIME_GetStamp(const struct PlayTime *playtime, struct PlayTimeStamp *out)
{
    *out = playtime->stamp;
}

void PLAYTIME_SetStamp(struct PlayTime *playtime, const struct PlayTimeStamp *in)
{
    playtime->stamp = *in;
}
