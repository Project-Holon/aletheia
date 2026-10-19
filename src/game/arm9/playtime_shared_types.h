#ifndef PLAYTIME_SHARED_TYPES_H
#define PLAYTIME_SHARED_TYPES_H

#include "config_shared_types.h"

/* The packed date and time is a nested struct, not bitfields in PlayTime:
 * PLAYTIME_GetStamp and PLAYTIME_SetStamp move it as one ldr/str pair. */
struct PlayTimeStamp {
    u32 year   : 7;
    u32 month  : 4;
    u32 day    : 5;
    u32 hour   : 5;
    u32 minute : 6;
};

struct PlayTime {
    u16 hours;
    u8  minutes;
    u8  seconds;
    struct PlayTimeStamp stamp;
};

#endif
