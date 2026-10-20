#ifndef ISS_SYS_SHARED_TYPES_H
#define ISS_SYS_SHARED_TYPES_H

#include "../types.h"
#include "../sdk_fx.h"

/* Index of one 3D sound source of the 3D sound subsystem (16 sources).  The enum type
 * keeps loop counters out of constant folding (see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md). */
typedef enum { ISS_3DS_SOURCE_FIRST, ISS_3DS_SOURCE_MAX = 16 } Iss3dsSourceIndex;

/* One entry of the BGM table (archive 0xb9): the BGM and the tracks that go silent in it. */
typedef struct Iss3dsTableEntry {
    u32 bgmId;
    u16 mutedMask;      /* tracks silenced while this BGM plays */
    u16 reserved06;
} Iss3dsTableEntry;

/* One 3D sound source: a point that drives the volume and pan of some tracks. */
typedef struct Iss3dsSource {
    u32 active;
    struct VecFx32 pos;
    s32 radius;                 /* distance beyond which the source is silent */
    s32 amplitude;              /* volume at the source position */
    u16 trackMask;
    u16 reserved1A;
} Iss3dsSource;

/* 3D sound subsystem, 0x26c bytes. */
typedef struct Iss3dsSys {
    u16 heapId;
    u16 reserved02;
    u32 entered;                /* 1 between Enter and Leave */
    u8 targetVolume;            /* master volume the ramp moves toward (0..0x7f) */
    u8 volume;                  /* current master volume */
    u8 volumeStep;              /* ramp step of volume per update */
    u8 reserved0B;
    struct VecFx32 cameraPos;   /* listener position */
    struct VecFx32 cameraTarget;    /* point the listener looks at */
    Iss3dsSource sources[ISS_3DS_SOURCE_MAX];
    s32 volumeLevel[ISS_3DS_SOURCE_MAX];    /* per-source volume, ramped */
    s32 panLevel[ISS_3DS_SOURCE_MAX];       /* per-source pan, ramped */
    Iss3dsTableEntry *table;
    u8 tableCount;
    u8 tableIndex;              /* 0xff: none */
} Iss3dsSys;

#endif
