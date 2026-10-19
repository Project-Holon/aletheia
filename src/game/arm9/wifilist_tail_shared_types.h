#ifndef WIFILIST_TAIL_SHARED_TYPES_H
#define WIFILIST_TAIL_SHARED_TYPES_H

struct SaveControl;

#include "../types.h"

/* RTC calendar date (the RTCDate of config.c). */
#include "../sdk_rtc.h"

/* Trainer status record, 0x20 bytes (layout of config.c). */
#ifndef MYSTATUS_STRUCT_DEFINED
#define MYSTATUS_STRUCT_DEFINED
struct MyStatus {
    u16 name[8];
    u32 id;
    u32 profile_id;
    u8  nation;
    u8  area;
    u8  language;
    u8  rom_code;
    u8  trainer_view;
    u8  sex;
};
#endif

#endif
