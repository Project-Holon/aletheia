#ifndef GAME_ARM9_GF_STANDARD_TYPES_H
#define GAME_ARM9_GF_STANDARD_TYPES_H

#include "../types.h"

/*
 * The game's own RTC records (gf_standard.c). They are not the SDK RTCDate and
 * RTCTime: every member is a full word.
 */

/* Calendar date as GF_STANDARD_GetCachedDate fills it. */
struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;               /* weekday, 0 = Sunday */
};

/* Time of day as GF_STANDARD_GetCachedTime fills it. */
struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

/* Pending RTC read: the staged values are copied to date and time when the read completes. */
struct RtcRequest {
    u32            hasResult;
    u32            busy;
    s32            frameCount;
    u32            result;
    struct RtcDate date;
    struct RtcTime time;
    struct RtcDate stagedDate;
    struct RtcTime stagedTime;
};

/* Signed form of RtcDate used by the day-of-year count. */
struct RtcDateSigned {
    s32 year;
    u32 month;
    s32 day;
    s32 week;
};

#endif
