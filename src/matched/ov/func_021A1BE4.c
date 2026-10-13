/*
 * function: WEATHER_RequestChangeNoFade
 * address:  0x021A1BE4
 * packet:   pkt_021A1BE4
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
 *   WEATHER_StartTransition  0x021A1C34  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02701.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 WEATHER_StartTransition(u32, u32, u32, u32);

int WEATHER_RequestChangeNoFade(u32 a, u32 b, u32 c, u32 d)
{
WEATHER_StartTransition(a, b, c, d);
((struct Obj02701 *)((u8 *)(a)))->f10 = 0;
return 0;
}

