#ifndef COMM_PLAYER_SUPPORT_SHARED_TYPES_H
#define COMM_PLAYER_SUPPORT_SHARED_TYPES_H

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

/* A 0x20-byte player record, read through the accessors MYSTATUS_CreateNameStrbuf etc. */
struct PlayerRecord {
    u32 words[8];
};

/* RTC date as GF_STANDARD_SetField00_F4E4 fills it: year, month, day, weekday. */
struct RtcDate {
    s32 year;
    s32 month;
    s32 day;
    s32 weekday;
};

#endif
