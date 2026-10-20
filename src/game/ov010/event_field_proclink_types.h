#ifndef GAME_OV010_EVENT_FIELD_PROCLINK_TYPES_H
#define GAME_OV010_EVENT_FIELD_PROCLINK_TYPES_H

#include "../types.h"

/* One proc link entry (0x18 bytes). */
typedef struct ProcLinkEntry {
    u8 active : 4;              /* 0x00: 0 = empty */
    u8 idFilter : 4;            /*       nonzero: only the ids below may use it */
    u8 age;                     /* 0x01: usable while below 30 */
    u8 value;                   /* 0x02: usable while at most 100 */
    u8 kind;                    /* 0x03: 7 when set by EVENT_FIELD_PROCLINK_ApplyReturnEntry */
    u16 allowedIds[8];          /* 0x04 */
    u8 reserved14[4];
} ProcLinkEntry;

#endif
