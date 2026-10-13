#ifndef ALETHEIA_OV021_EFFECT_ENCOUNT_TYPES_H
#define ALETHEIA_OV021_EFFECT_ENCOUNT_TYPES_H

#include "field_effect_types.h"
#include "field_encount_types.h"

/*
 * Special encounter effects of the field (effect_encount.c): the shaking
 * grass, rippling water and dust cloud spots. While the player walks, the
 * work counts steps; when enough steps passed and a random roll succeeds, it
 * picks one tile near the player and shows an effect object on it. Stepping
 * onto the tile starts a wild encounter or an item event.
 */

/* One tile near the player where a spot can appear (12 bytes). */
typedef struct EffectEncountCandidate {
    u8 kind;                 /* 0x00 spot kind of the tile attribute (8 = no spot) */
    u8 pad01;
    u16 gridX;               /* 0x02 */
    u16 gridHeight;          /* 0x04 height in tiles, set when the candidate is picked */
    u16 gridZ;               /* 0x06 */
    int heightFx;            /* 0x08 height of the tile as fx32 */
} EffectEncountCandidate;

/* Work of the effect encount system, 0x5C0 bytes (FieldEncount.effectEncount). */
typedef struct EffectEncount {
    FieldEffectSys *fieldEffectSys;          /* 0x00 */
    u16 candidateCount;                      /* 0x04 */
    u8 pad06[2];
    EffectEncountCandidate candidates[121];  /* 0x08 */
    FieldEffectObj *effectObj;               /* 0x5B4 effect object of the active spot, or NULL */
    u16 stepsNeeded;                         /* 0x5B8 steps between two spot rolls */
    u16 spawnPercent;                        /* 0x5BA chance of a spot per roll */
    u16 itemId;                              /* 0x5BC item the item event hands out */
    u8 pad5BE[2];
} EffectEncount;

/* The active spot, saved in the field gimmick work so it survives a map change (0x10 bytes). */
typedef struct EffectEncountSpot {
    u16 zoneId;              /* 0x00 zone the spot belongs to */
    s16 gridX;               /* 0x02 */
    s16 gridHeight;          /* 0x04 */
    s16 gridZ;               /* 0x06 */
    int heightFx;            /* 0x08 */
    u8 kind;                 /* 0x0C */
    u8 active : 4;           /* 0x0D nonzero while the spot exists */
    u8 needsRestore : 2;     /* 0x0D set on map exit: recreate the effect object on entry */
    u8 consumed : 2;         /* 0x0D the player already used the spot */
    u8 pad0E[2];
} EffectEncountSpot;

/* Field gimmick slot of GameData as the effect encount system uses it (GAME_DATA_GetFieldGimmick). */
typedef struct EncountGimmickWork {
    u8 stepWork[0x0C];       /* 0x00 EncountStepWork of field_encount.c */
    u32 effectStepCount;     /* 0x0C steps since the last spot roll */
    EffectEncountSpot spot;  /* 0x10 */
} EncountGimmickWork;

#endif
