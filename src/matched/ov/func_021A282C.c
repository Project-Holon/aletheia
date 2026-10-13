/*
 * function: WEATHER_TASK_LoadResources
 * address:  0x021A282C
 * packet:   pkt_021A282C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   WEATHER_TASK_LoadArchive  0x021A2978  thumb  ov021
 *   WEATHER_TASK_LoadSpriteResources  0x021A29A8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void WEATHER_TASK_LoadArchive(u8 *p, u16 *q, u32 c, u32 a3);
extern u32 WEATHER_TASK_LoadSpriteResources(u32, u32, u32);

int WEATHER_TASK_LoadResources(u32 a, u32 b, u32 c, u32 d)
{
WEATHER_TASK_LoadArchive((u8 *)(a + 40), (u16 *)(((struct Obj12084 *)((u8 *)(a)))->f20), b, d);
return WEATHER_TASK_LoadSpriteResources((a + 40), ((struct Obj12084 *)((u8 *)(a)))->f20, b);
}

