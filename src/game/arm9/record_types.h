#ifndef GAME_ARM9_RECORD_TYPES_H
#define GAME_ARM9_RECORD_TYPES_H

#include "../types.h"

/* Save block 0x26: counters with ceilings, sealed by a checksum (0x1E0). */
typedef struct RecordBlock {
    u32 wordCounters[0x47];         /* counters 0x00..0x46 */
    u16 halfCounters[0x60];         /* counters 0x47..0xA6 */
    u16 checksum;                   /* over +4..+0x1DC */
    u16 cryptSeed;                  /* high half of the seal key */
} RecordBlock;

#endif
