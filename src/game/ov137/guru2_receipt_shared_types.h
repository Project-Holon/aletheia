#ifndef GURU2_RECEIPT_SHARED_TYPES_H
#define GURU2_RECEIPT_SHARED_TYPES_H

#include "guru2_shared_types.h"

struct GfFont;

struct MsgBank;

struct WordSet;

struct Node;

struct PrintSys;

struct Rec;

struct DispVram;

#include "../types.h"

typedef struct { u8 pad[0x4804]; volatile int previous; } FrameObj;

struct U16Vec;

struct Bank;

struct Cfg;

struct Sub0200852CObj;

struct FrameObj;

struct CharBuf;

struct Descriptor;

struct Link;

struct Obj;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

typedef struct { int a[4]; } Descriptor;

typedef struct {u8 pad[0x2c]; int index,count;} Obj;

#endif
