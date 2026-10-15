#ifndef POKEMONTRADE_DEMO_UP_SHARED_TYPES_H
#define POKEMONTRADE_DEMO_UP_SHARED_TYPES_H

#include "pokemontrade_demo_types.h"

#define FRAME (((PokeTradeDemoWork *)p)->frame)

#define OBJ(i) (((PokeTradeDemoWork *)p)->mcssObj[i])

#define HEAP (((PokeTradeDemoWork *)p)->heapId)

#define SLOT0 (((PokeTradeDemoWork *)p)->slideOwn)

#define SLOT1 (((PokeTradeDemoWork *)p)->slidePeer)

struct IcaAnime;

struct Rec12;

struct Bank;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

#endif
