/*
 * function: WEATHER_TASK_FlashLight
 * address:  0x021A2130
 * packet:   pkt_ov021_021A2130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_LIGHT_StartColorFade  0x021A0618  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19728.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_LIGHT_StartColorFade(u8 *p, u32 a, u32 b, u32 c);

void WEATHER_TASK_FlashLight(u8 *p, u32 b, u32 c, u32 d)
{
    FIELD_LIGHT_StartColorFade((u8 *)(((struct Obj19728 *)p)->f8), b, c, d);
}
