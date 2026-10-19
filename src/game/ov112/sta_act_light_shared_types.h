#ifndef STA_ACT_LIGHT_SHARED_TYPES_H
#define STA_ACT_LIGHT_SHARED_TYPES_H

struct Vec2;

struct Desc;

struct Vec3;

#include "../types.h"

typedef struct Vec2 { short x, y; } Vec2;

typedef struct Vec3 { int x, y, z; } Vec3;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef struct Desc { Vec2 pos; Pos shape; } Desc;

#endif
