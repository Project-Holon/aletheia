#ifndef GAME_OV010_FIELD_ENCOUNT_ST_TYPES_H
#define GAME_OV010_FIELD_ENCOUNT_ST_TYPES_H

#include "../types.h"

/* One wild encounter entry: species and form in 4 bytes. */
typedef struct EncounterSlot {
    u16 species : 11;
    u16 form : 5;
    u16 reserved;
} EncounterSlot;

/* The 0xE8-byte encounter table row of a zone, filled by FIELD_ENCOUNT_ST_LoadEncountData. */
struct EncountRow {
    u8 reserved00[5];
    u8 hasSetA;                           /* 0x05 */
    u8 hasSetB;                           /* 0x06 */
    u8 flags;                             /* 0x07: 0x80 set after load */
    u8 reserved08[0xc0 - 8];
    EncounterSlot setA[5];                /* 0xC0 */
    EncounterSlot setB[5];                /* 0xD4 */
};

#endif
