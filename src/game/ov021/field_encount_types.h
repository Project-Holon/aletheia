#ifndef ALETHEIA_OV021_FIELD_ENCOUNT_TYPES_H
#define ALETHEIA_OV021_FIELD_ENCOUNT_TYPES_H

/*
 * Wild encounter work of the field map (field_encount.c, effect_encount.c).
 */

#include "../types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct EffectEncount;

/* One wild slot of a zone encounter table (4 bytes). form 0x1F picks a random form. */
typedef struct EncountSlot {
    u16 species : 11;
    u16 form : 5;
    u8 minLevel;
    u8 maxLevel;
} EncountSlot;

/*
 * Wild encounter table of one zone (0xE8 bytes, owned by the event data
 * system). rate[] is indexed by the encounter type: 0 grass, 1 dark grass,
 * 2 rustling grass or dust cloud, 3 surfing, 4 rippling water, 5 fishing,
 * 6 fishing in rippling water. ground[] holds types 0..2, water[] types 3
 * and 4, fishing[] types 5 and 6.
 */
typedef struct EncountData {
    u8 rate[7];                  /* 0x00 */
    u8 effectKind : 7;           /* 0x07 index of the effect encount setting (0..2) */
    u8 enabled : 1;              /* 0x07 */
    EncountSlot ground[3][12];   /* 0x08 */
    EncountSlot water[2][5];     /* 0x98 */
    EncountSlot fishing[2][5];   /* 0xC0 */
} EncountData;

/* Encounter work, 0x14 bytes, allocated by FIELD_ENCOUNT_Create (fieldmap.c keeps it). */
typedef struct FieldEncount {
    struct FieldMap *fieldMap;            /* 0x00 */
    struct GameSystem *gameSystem;        /* 0x04 */
    struct GameData *gameData;            /* 0x08 */
    EncountData *encountData;             /* 0x0C NULL when the zone has no table */
    struct EffectEncount *effectEncount;  /* 0x10 effect_encount.c work */
} FieldEncount;

#endif
