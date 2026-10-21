#ifndef WIFI_HISTORY_SHARED_TYPES_H
#define WIFI_HISTORY_SHARED_TYPES_H

#include "../types.h"
#include "mystatus_types.h"

/* One slot of the 20-entry history table (0x28 bytes). */
struct HistoryEntry {
    struct MyStatus record;     /* 0x00 */
    u16 meetCount;                  /* 0x20 */
    u16 swapCount;                  /* 0x22 */
    u8  rank;                       /* 0x24 */
    u8  score;                      /* 0x25 */
    u8  greeting : 3;               /* 0x26, set only below 5 */
    u8  isMarked : 1;
    u8  isOccupied : 1;
    u8  : 3;
    u8  reserved27;                 /* 0x27 */
};

#endif
