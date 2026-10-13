/*
 * function: WEATHER_TASK_GetParticleCount
 * address:  0x021A21BC
 * packet:   pkt_ov021_021A21BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (ldr r1,[pc]; ldr r0,[r0,r1]; bx lr; pool 0x778), filed
 * for lane S30 (callee of ov027/ov028 functions).
 *
 * symbols:
 *   WEATHER_TASK_GetParticleCount 0x021A21BC thumb ov021
 */
#include "../include/Obj19731.h"

int WEATHER_TASK_GetParticleCount(unsigned char *o)
{
    return ((struct Obj19731 *)o)->f778;
}
