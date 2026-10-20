#ifndef STA_ACT_EFFECT_SHARED_TYPES_H
#define STA_ACT_EFFECT_SHARED_TYPES_H

#include "sta_acting_shared_types.h"

typedef struct { int a; StaActingVec v; } StaActEffectPart;

/* One of the eight effect-system records in the array created by
 * STA_ACT_EFFECT_Create (stride 0x4848). +0x04 is the particle work buffer
 * handed to PARTICLE_CreateSystemDefault, +0x4804 its handle, +0x4808 four
 * parts. */
typedef struct {
    union {
        int s;                 /* 0x00 1 while the system runs, 0 when killed */
        unsigned int u;
    } active;
    unsigned char particleWork[0x4800]; /* 0x04 PARTICLE system work buffer */
    union {
        unsigned int u;        /* 0x4804 PARTICLE system handle */
        void *p;
    } system;
    StaActEffectPart part[4];              /* 0x4808 up to four effect parts */
} ActEffectSystem;

/* Effect manager (0x24244 bytes) created by STA_ACT_EFFECT_Create. */
typedef struct {
    unsigned short heapId;
    unsigned char pad_2[2];
    ActEffectSystem systems[8];
} ActEffectManager;

#endif
