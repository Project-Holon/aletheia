#ifndef ALETHEIA_OV021_EVENT_FISHING_TYPES_H
#define ALETHEIA_OV021_EVENT_FISHING_TYPES_H

#include "field_effect_types.h"

/*
 * Work of the fishing event task (event_fishing.c, created when the player
 * uses a rod facing water), and of the rod and exclamation effect helpers
 * in the same file.
 */
typedef struct FishingWork {
    void *gameSystem;                     /* 0x00 */
    void *gameData;                       /* 0x04 */
    void *fieldMap;                       /* 0x08 */
    void *encount;                        /* 0x0C */
    void *trainerRecord;                  /* 0x10 */
    void *mmdlSys;                        /* 0x14 */
    void *fieldPlayer;                    /* 0x18 */
    void *mmdl;                           /* 0x1C: the field model of the player */
    s16 targetGrid[3];                    /* 0x20: grid position of the water tile */
    u16 pad26;
    u32 playerState;                      /* 0x28 */
    u32 exclamEffect;                     /* 0x2C: exclamation mark effect handle */
    u32 rodEffect;                        /* 0x30: fishing rod effect handle */
    VecFx32 playerPos;                    /* 0x34: y is the side the line was cast to */
    VecFx32 targetPos;                    /* 0x40: y is the side the player stands on, the vector is handed to the rod effect */
    u8 pad4C[0xC];
    u8 playerDir;                         /* 0x58: also the rod kind of the rod effect */
    u8 hasEncounter;                      /* 0x59 */
    u16 noTarget;                         /* 0x5A: 1 when no fishable water tile faces the player */
    u32 biteDelay;                        /* 0x5C: frames to wait for the bite */
    u32 counter;                          /* 0x60: frames spent in the current step */
    void *wildEncounter;                  /* 0x64: 0 when the cast catches nothing */
} FishingWork;

#endif
