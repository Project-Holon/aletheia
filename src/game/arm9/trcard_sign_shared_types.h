#ifndef TRCARD_SIGN_SHARED_TYPES_H
#define TRCARD_SIGN_SHARED_TYPES_H

#include "../types.h"

struct SaveControl;

/* SDK date and time as filled by the RTC wrapper. */
#include "../sdk_rtc.h"


/* The date a badge was won; the fourth byte is read back with the other three
 * as one word but never written here. */
struct BadgeDate {
    u8 year;
    u8 month;
    u8 day;
    u8 reserved;
};

#endif
