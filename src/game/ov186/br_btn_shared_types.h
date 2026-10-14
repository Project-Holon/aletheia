#ifndef BR_BTN_SHARED_TYPES_H
#define BR_BTN_SHARED_TYPES_H

#include "br_proc_sys_shared_types.h"

struct PrintSys;

typedef signed short s16;

struct MsgBank;

struct Actor;

struct Obj;

struct Bmp;

struct Obj020437AC;

struct Node;

typedef unsigned int   u32_021F9CB8;

struct Rec_021F9CB8 { u16 a, b; };

struct Set { struct Rec_021F9CB8 rec[6]; u32_021F9CB8 count; };

struct Obj {
    u16 heap;
    u16 pad0;
    int f4;
    int f8;
    int *fC;
    int f10;
    int f14;
    int pad18;
    int f1C;
    int pad20[6];
    u8 f38;
    u8 f39;
    u8 f3a;
    u8 f3b;
    char *f3c;
    char *f40;
    void *f44;
    void *f48;
    u32_021F9CB8 f4c;
    int pad50[2];
    int f58;
    struct Set *f5c;
};

typedef struct { void *actor,*grid,*bmp;u32 fC,b,a; } Obj;

#endif
