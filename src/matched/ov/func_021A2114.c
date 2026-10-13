/*
 * function: WEATHER_TASK_SetLight
 * address:  0x021A2114
 * packet:   pkt_021A2114
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_LIGHT_ChangeTable  0x021A0590  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18001.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_LIGHT_ChangeTable(u32, u32, u32, u32);

int WEATHER_TASK_SetLight(u32 a, int b, u32 c)
{
return FIELD_LIGHT_ChangeTable(((struct Obj18001 *)((u8 *)(a)))->f8, b, c, 1);
}

