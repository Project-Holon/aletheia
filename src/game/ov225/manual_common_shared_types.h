#ifndef MANUAL_COMMON_SHARED_TYPES_H
#define MANUAL_COMMON_SHARED_TYPES_H

#include "../types.h"

struct MsgBank;

struct PrintSys;

struct Descriptor;

/* The manual data object built by MANUAL_COMMON_CreateData (0x38). */
struct ManualData {
    void *owner;        /* 0x00 save/state object */
    u16 heap;           /* 0x04 */
    u16 pad06;
    void *screen;       /* 0x08 */
    struct GfFont *font;           /* 0x0C */
    struct PrintQueue *printQue[3];    /* 0x10 */
    void *bank[2];      /* 0x1C */
    void *arc[2];       /* 0x24 */
    void *assets;       /* 0x2C */
    u16 id;             /* 0x30 */
    u16 pad32;
    void *group;        /* 0x34 */
};

#endif
