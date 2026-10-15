#ifndef DEMO3D_GRAPHIC_SHARED_TYPES_H
#define DEMO3D_GRAPHIC_SHARED_TYPES_H

struct Node;

struct LightSlot;

struct Cfg;

struct Obj;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Block {int tag;struct LightSlot *slots;};

struct Obj {int a,b;struct Block block;};

struct Cfg {
    u32 f0, f4, f8;
    u8 fc, fd, fe;
    u8 sec : 7, bit7 : 1;
};

#endif
