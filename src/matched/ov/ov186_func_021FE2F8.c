/*
 * function: BR_UTIL_StepOrbit
 * address: 0x021FE2F8
 * packet: pkt_ov186_021FE2F8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
#include "../include/Obj01284.h"
extern const short FX_SinCosTable_[];
int BR_UTIL_StepOrbit(char *p, int *out, int step)
{
    unsigned short angle_delta;
    signed char direction;
    int angle;
    int initial_angle;
    int duration;
    unsigned short initial_radius;
    int radius_delta;
    int radius, x, y;
    initial_angle = ((struct Obj01284 *)p)->f14;
    angle_delta = ((struct Obj01284 *)p)->f16 - initial_angle;
    initial_radius = ((struct Obj01284 *)p)->f10;
    radius_delta = (short)(*(short *)&((struct Obj01284 *)p)->f12 - (short)initial_radius);
    direction = radius_delta / (radius_delta < 0 ? -radius_delta : radius_delta);
    duration = ((struct Obj01284 *)p)->f18;
    angle = (unsigned short)(initial_angle + angle_delta * step / duration);
    if (radius_delta < 0) radius_delta = -radius_delta;
    radius = initial_radius + direction * (step * radius_delta / duration);
    if (radius < 0) radius = 0;
    x = (FX_SinCosTable_[(angle >> 4) * 2 + 1] * radius) >> 12;
    y = (FX_SinCosTable_[(angle >> 4) * 2] * radius) >> 12;
    x += ((struct Obj01284 *)p)->f0;
    y += ((struct Obj01284 *)p)->f4;
    ((struct Obj01284 *)p)->f8 = x;
    ((struct Obj01284 *)p)->fC = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == ((struct Obj01284 *)p)->f18;
}
