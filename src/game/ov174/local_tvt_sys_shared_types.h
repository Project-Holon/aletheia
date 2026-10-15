#ifndef LOCAL_TVT_SYS_SHARED_TYPES_H
#define LOCAL_TVT_SYS_SHARED_TYPES_H

struct Obj;

struct Cfg;

struct Sub0200852CObj;

struct Actor;

struct MsgBank;

struct Descriptor;

struct PrintSys;

struct U16Vec;

struct WordSet;

struct CharBuf;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32_021B61C4;

typedef unsigned u32_021B6594;

typedef signed int     s32;

typedef unsigned int   u32_021B68F8;

typedef unsigned int   u32_021B6A04;

typedef struct { u8 x, y; } Pair_021B6100;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad00[0x0C];
    unsigned char state;
    unsigned char pad0D[0x34 - 0x0D];
    int pending;
    unsigned char pad38[0x40 - 0x38];
    unsigned char *steps;
    unsigned char pad44[0x89 - 0x44];
    unsigned char stepIdx;
};

typedef unsigned int u32;

#endif
