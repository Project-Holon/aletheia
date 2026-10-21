#ifndef GAME_ARM9_GF_STANDARD_TYPES_H
#define GAME_ARM9_GF_STANDARD_TYPES_H

#include "../types.h"
#include "../sdk_rtc.h"

/* Pending RTC read: the staged values are copied to date and time when the read completes. */
struct RtcRequest {
    u32            hasResult;
    u32            busy;
    s32            frameCount;
    u32            result;
    RTCDate date;
    RTCTime time;
    RTCDate stagedDate;
    RTCTime stagedTime;
};

/* Signed form of RtcDate used by the day-of-year count. */
struct RtcDateSigned {
    s32 year;
    u32 month;
    s32 day;
    s32 week;
};

#endif
