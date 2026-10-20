#ifndef MANUAL_CATEGORY_SHARED_TYPES_H
#define MANUAL_CATEGORY_SHARED_TYPES_H

struct Node;

#include "../types.h"
#include "manual_common_shared_types.h"

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
