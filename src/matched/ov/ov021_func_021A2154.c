/*
 * function: WEATHER_TASK_SetLightColor
 * address:  0x021A2154
 * packet:   pkt_ov021_021A2154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   WEATHER_TASK_SetLightColor 0x021A2154 thumb ov021
 *   FIELD_LIGHT_StartColorFadeHold 0x021A063C thumb ov021
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void FIELD_LIGHT_StartColorFadeHold(u8 *p, u32 b, u32 c);

void WEATHER_TASK_SetLightColor(u8 *p, u32 b, u32 c)
{
    FIELD_LIGHT_StartColorFadeHold(*(u8 * *)&((struct Obj00954 *)p)->f8, b, c);
}
