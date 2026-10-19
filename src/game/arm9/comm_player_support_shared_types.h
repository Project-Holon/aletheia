#ifndef COMM_PLAYER_SUPPORT_SHARED_TYPES_H
#define COMM_PLAYER_SUPPORT_SHARED_TYPES_H

#include "../types.h"

/* A 0x20-byte player record, read through the accessors MYSTATUS_CreateNameStrbuf etc. */
struct PlayerRecord {
    u32 words[8];
};

/* RTC date as GF_STANDARD_GetCachedDate fills it: year, month, day, weekday. */
struct RtcDate {
    s32 year;
    s32 month;
    s32 day;
    s32 weekday;
};

#endif
