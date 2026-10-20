#ifndef STA_ACT_LIGHT_SHARED_TYPES_H
#define STA_ACT_LIGHT_SHARED_TYPES_H

struct StaActLightVec2;

struct StaActLightDesc;

struct StaActLightVec3;

#include "../types.h"

typedef struct StaActLightVec2 { short x, y; } StaActLightVec2;

typedef struct StaActLightVec3 { int x, y, z; } StaActLightVec3;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } StaActLightPos;

typedef struct StaActLightDesc { StaActLightVec2 pos; StaActLightPos shape; } StaActLightDesc;

#endif
