#ifndef MANUAL_COMMON_SHARED_TYPES_H
#define MANUAL_COMMON_SHARED_TYPES_H

#include "../types.h"

struct MsgBank;

struct PrintSys;

struct Descriptor;

/* Manual data object built by MANUAL_COMMON_CreateData (0x38). */
struct ManualData {
    void *owner;                     /* 0x00 save control object */
    u16 heap;                        /* 0x04 */
    u16 pad06;                       /* 0x06 */
    void *screen;                    /* 0x08 graphic screen */
    u32 font;                        /* 0x0C */
    u32 printQue0;                   /* 0x10 */
    u32 printQue1;                   /* 0x14 */
    u32 printQue2;                   /* 0x18 */
    void *bank0;                     /* 0x1C */
    void *bank1;                     /* 0x20 */
    void *arc0;                      /* 0x24 */
    void *arc1;                      /* 0x28 */
    void *assets;                    /* 0x2C archive table */
    u16 id;                          /* 0x30 */
    u16 pad32;                       /* 0x32 */
    void *group;                     /* 0x34 */
};

#endif
