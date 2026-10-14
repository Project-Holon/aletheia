#ifndef ZUKAN_DETAIL_HEADBAR_SHARED_TYPES_H
#define ZUKAN_DETAIL_HEADBAR_SHARED_TYPES_H

#include "zukan_detail_procsys_shared_types.h"
#include "zukan_detail_common_shared_types.h"

struct Ov208Gfx;

struct Bmp;

struct Descriptor;

struct CharBuf;

struct MsgBank;

struct Obj020437AC;

struct Rec;

struct U16Vec;

struct Ov208Icon_021BE82C {
    u32 pad0[3];
    int fc;
};

struct Ov208Icon_021BE840 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE844 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE854 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Gfx { u16 heap; u16 pad; int f4; int f8; int fc; int f10; u32 f14; void *f18; int f1c; int f20; int f24; };

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

#endif
