#ifndef ISS_SYS_SHARED_TYPES_H
#define ISS_SYS_SHARED_TYPES_H

#include "../types.h"

typedef struct {
    int x, y, z;
} IssVec3;

/* One entry of the 3D sound table: the BGM that uses it and the sound it plays. */
typedef struct {
    u32 bgmId;
    u32 soundId;
} Iss3dsTableEntry;

enum {
    ISS_3DS_SLOT_COUNT = 16
};

/* One positional sound source. */
typedef struct {
    u32 active;
    IssVec3 pos;
    int radius;
    int amp;
    u16 trackMask;
    u16 reserved;
} Iss3dsSlot;

/* 3D sound subsystem, 0x26c bytes. */
typedef struct {
    u16 heapId;
    u16 reserved02;
    u32 entered;
    u8 volume;
    u8 maxVolume;
    u8 fadeSpeed;
    u8 reserved0B;
    IssVec3 cameraPos;
    IssVec3 cameraTarget;
    Iss3dsSlot slots[ISS_3DS_SLOT_COUNT];
    u32 slotLevelA[ISS_3DS_SLOT_COUNT];
    u32 slotLevelB[ISS_3DS_SLOT_COUNT];
    Iss3dsTableEntry *table;
    u8 tableCount;
    u8 tableIndex;
} Iss3dsSys;

#endif
