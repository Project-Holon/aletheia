#ifndef DUP_FITTING_SHARED_TYPES_H
#define DUP_FITTING_SHARED_TYPES_H

struct Object;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { u32 x,y; } DupFittingPairU32;

typedef struct {int x,y;} DupFittingPair;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;

#endif
