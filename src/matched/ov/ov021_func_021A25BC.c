/*
 * function: WEATHER_TASK_PlaySe
 * address:  0x021A25BC
 * packet:   pkt_ov021_021A25BC
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
 *   WEATHER_TASK_PlaySe 0x021A25BC thumb ov021
 *   WEATHER_TASK_PlaySound 0x021A2C30 thumb ov021
 */
#include "../include/Obj19740.h"

extern void WEATHER_TASK_PlaySound(unsigned char *o, int a, int b);

void WEATHER_TASK_PlaySe(unsigned char *o, int arg)
{
    WEATHER_TASK_PlaySound(o + 0x40, ((struct Obj19740 *)o)->fC, arg);
}
