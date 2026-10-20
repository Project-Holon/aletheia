#ifndef GURU2_RECEIPT_SHARED_TYPES_H
#define GURU2_RECEIPT_SHARED_TYPES_H

#include "../ov137/guru2_shared_types.h"

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

struct Guru2ReceiptDescriptor;

struct Link;

struct Guru2ReceiptObj;

#include "../arm9/bg_sys.h"


typedef struct { int a[4]; } Guru2ReceiptDescriptor;

typedef struct {u8 pad[0x2c]; int index,count;} Guru2ReceiptObj;

#endif
