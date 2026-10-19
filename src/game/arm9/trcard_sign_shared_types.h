#ifndef TRCARD_SIGN_SHARED_TYPES_H
#define TRCARD_SIGN_SHARED_TYPES_H

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned long long u64;

struct SaveControl;

/* SDK date and time as filled by the RTC wrapper. */
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

#endif
