#ifndef BMP_MENUWORK_SHARED_TYPES_H
#define BMP_MENUWORK_SHARED_TYPES_H

struct BmpWin;

struct MsgBank;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    union {
        const void *text;   /* +0x00  item text */
        void       *handle; /* same word read as an owned string handle */
        u32         raw;    /* 0 = free entry, 0xFFFFFFFF = list terminator */
    } u;
    u32 value;              /* +0x04  value returned when chosen */
} BmpMenuWork;

#endif
