#ifndef POKEMONTRADE_DEMO_UP_SHARED_TYPES_H
#define POKEMONTRADE_DEMO_UP_SHARED_TYPES_H

#include "pokemontrade_demo_types.h"

#define FRAME (((PokeTradeDemoWork *)work)->frame)

#define OBJ(i) (((PokeTradeDemoWork *)work)->mcssObj[i])

#define HEAP (((PokeTradeDemoWork *)work)->heapId)

#define SLOT0 (((PokeTradeDemoWork *)work)->slideOwn)

#define SLOT1 (((PokeTradeDemoWork *)work)->slidePeer)

struct IcaAnime;

struct Rec12;

struct Bank;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

struct Personal;

struct Sub0200852CObj;

struct Obj;

struct Actor;

typedef struct {
    u16 x;
    u16 y;
    u16 animSeq;
    u8 drawPriority;
    u8 bgPriority;
} ClactActorPos;

#endif
