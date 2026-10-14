#ifndef DRAW_SYSTEM_SHARED_TYPES_H
#define DRAW_SYSTEM_SHARED_TYPES_H

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

#endif
