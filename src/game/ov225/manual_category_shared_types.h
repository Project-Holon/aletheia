#ifndef MANUAL_CATEGORY_SHARED_TYPES_H
#define MANUAL_CATEGORY_SHARED_TYPES_H

struct Node;

#include "../types.h"
#include "manual_common_shared_types.h"

/* One 8-byte selection table row. */
struct ManualListEntry { u16 item; u16 count; u32 flag; };

/* List state shared by a selection list and its list work: the MANUAL_COMMON_CreateListWork owner. */
struct ManualListState {
    u32 ready;                        /* 0x00 */
    u16 count;                        /* 0x04 */
    u16 pad06;                        /* 0x06 */
    struct ManualListEntry *data;     /* 0x08 entry table */
    u16 top;                          /* 0x0C restored to the owner on delete */
    u16 selected;                     /* 0x0E */
    u32 mode;                         /* 0x10 */
};

/* The selection list built by MANUAL_CATEGORY_CreateList and MANUAL_CATEGORY_CreateDetailList. */
struct ManualMenuList {
    void *owner;                      /* 0x00 list or detail owner region */
    void *data;                       /* 0x04 */
    struct ManualListState state;     /* 0x08 */
    void *widget;                     /* 0x1C */
    void *task;                       /* 0x20 */
};

#endif
