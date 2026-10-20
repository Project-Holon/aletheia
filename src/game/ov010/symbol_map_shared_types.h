#ifndef SYMBOL_MAP_SHARED_TYPES_H
#define SYMBOL_MAP_SHARED_TYPES_H

#include "../types.h"

struct GameSystem;

struct GameData;

struct GameEvent;

struct GameEvent;

/* One list entry of the link record: an 11-bit id and 21 bits of payload. */
typedef struct SymbolMapEntry {
    u32 id : 11;
    u32 payload : 21;
} SymbolMapEntry;

/* The 0x54-byte record two players exchange over the link. */
typedef struct SymbolMapLinkRecord {
    SymbolMapEntry entries[20];   /* 0x00 */
    u32 entryCount : 6;           /* 0x50 */
    u32 symbolIndex : 4;          /* 0..6, low part of the grid table index */
    u32 symbolGroup : 4;          /* multiplied by 7 in the grid table index */
    u32 state : 4;                /* 4 = local record */
    u32 page : 6;
    u32 reserved : 8;
} SymbolMapLinkRecord;

#endif
