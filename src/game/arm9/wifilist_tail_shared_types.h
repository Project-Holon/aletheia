#ifndef WIFILIST_TAIL_SHARED_TYPES_H
#define WIFILIST_TAIL_SHARED_TYPES_H

struct SaveControl;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* RTC calendar date (the RTCDate of config.c). */
struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

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
