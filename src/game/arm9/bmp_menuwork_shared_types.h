#ifndef BMP_MENUWORK_SHARED_TYPES_H
#define BMP_MENUWORK_SHARED_TYPES_H

struct BmpWin;

struct MsgBank;

#include "../types.h"

typedef struct BmpMenuWork {
    union {
        const void *text;   /* +0x00  item text */
        void       *handle; /* same word read as an owned string handle */
        u32         raw;    /* 0 = free entry, 0xFFFFFFFF = list terminator */
    } u;
    u32 value;              /* +0x04  value returned when chosen */
} BmpMenuWork;

#endif
