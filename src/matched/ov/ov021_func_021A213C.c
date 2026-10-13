/*
 * function: WEATHER_TASK_IsLightFlashing
 * address:  0x021A213C
 * packet:   pkt_ov021_021A213C
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
 *   WEATHER_TASK_IsLightFlashing 0x021A213C thumb ov021
 *   FIELD_LIGHT_IsColorFading 0x021A065C thumb ov021
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;

extern int FIELD_LIGHT_IsColorFading(u8 *p);

int WEATHER_TASK_IsLightFlashing(u8 *p)
{
    return FIELD_LIGHT_IsColorFading(*(u8 * *)&((struct Obj00954 *)p)->f8);
}
