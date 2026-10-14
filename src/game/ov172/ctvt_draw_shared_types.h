#ifndef CTVT_DRAW_SHARED_TYPES_H
#define CTVT_DRAW_SHARED_TYPES_H

#include "draw_system_shared_types.h"
#include "ctvt_talk_shared_types.h"

struct Vec2;

typedef unsigned int   u32_021BA2B8;

typedef unsigned int   u32_021BA2C4;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

typedef unsigned int   u32_021BA8C4;

typedef unsigned int   u32_021BA9EC;

typedef unsigned int u32_021BAE58;

typedef unsigned long u32_021BAEE0;

struct SpritePos {
    s16 x;
    s16 y;
};

typedef unsigned long u32_021BB288;

typedef unsigned int u32_021BB4D0;

typedef unsigned long u32_021BCC40;

typedef unsigned int   u32_021BE0B0;

typedef unsigned int   u32_021BE0B4;

typedef unsigned int   u32_021BE0C8;

typedef unsigned long u32_021BE0D0;

typedef unsigned int u32_021BE11C;

typedef struct { u32_021BE11C heap; u8 count; u8 pad[3]; void *items; u32_021BE11C zero; u8 a,b,c,d; } Descriptor;

#endif
