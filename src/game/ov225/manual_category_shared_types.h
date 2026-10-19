#ifndef MANUAL_CATEGORY_SHARED_TYPES_H
#define MANUAL_CATEGORY_SHARED_TYPES_H

struct Node;

#include "../types.h"

/* The manual data object built by MANUAL_COMMON_CreateData (was State_021B9B3C / Obj views). */
struct ManualData {
    void *owner;        /* 0x00 save/state object */
    u16 heap;           /* 0x04 */
    u16 pad06;
    void *screen;       /* 0x08 */
    void *font;         /* 0x0C */
    void *printQue[3];  /* 0x10 */
    void *bank[2];      /* 0x1C */
    void *arc[2];       /* 0x24 */
    void *assets;       /* 0x2C */
    u16 id;             /* 0x30 */
    u16 pad32;
    void *group;        /* 0x34 */
};

/* One 8-byte selection table row. */
struct ManualListEntry { u16 item; u16 count; u32 flag; };

/* The selection list built by MANUAL_CATEGORY_CreateList and MANUAL_CATEGORY_CreateDetailList. */
struct ManualMenuList {
    void *owner;            /* 0x00 list or detail owner region */
    void *data;             /* 0x04 */
    u32 ready;              /* 0x08 */
    u16 entryCount;         /* 0x0C */
    u16 pad0E;
    struct ManualListEntry *entries;  /* 0x10 */
    u16 savedA;             /* 0x14 restored to the owner on delete */
    u16 savedB;             /* 0x16 */
    u32 mode;               /* 0x18 */
    void *widget;           /* 0x1C */
    void *task;             /* 0x20 */
};

#endif
