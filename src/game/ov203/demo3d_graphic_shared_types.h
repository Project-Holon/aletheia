#ifndef DEMO3D_GRAPHIC_SHARED_TYPES_H
#define DEMO3D_GRAPHIC_SHARED_TYPES_H

struct Node;

struct LightSlot;

struct Bank;

struct Cfg;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

/*
 * Graphic context of the demo3d demo (0x18 bytes; DEMO3D_GRAPHIC_Create allocates it
 * with func_02030734(heap, 24, ...)).  It is split into a bg section at 0x00,
 * a clact section at 0x04 and a g3d section at 0x08.
 */
typedef struct Demo3dGraphic {
    int               bg;         /* 0x00 BG_SYS state */
    struct Bank      *clact;      /* 0x04 CLACT unit */
    int               g3dTag;     /* 0x08 never written */
    struct LightSlot *lightSlots; /* 0x0C G3D light slots */
    void             *proc;       /* 0x10 func_020056A0 proc handle */
    int               engineOn;   /* 0x14 DEMO3D_DATA_GetAnimCount result */
} Demo3dGraphic;

struct Cfg {
    u32 f0, f4, f8;
    u8 fc, fd, fe;
    u8 sec : 7, bit7 : 1;
};

#endif
