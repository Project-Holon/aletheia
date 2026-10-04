/*
 * function: func_021B6ADC
 * address: 0x021B6ADC
 * packet: pkt_ov172_021B6ADC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C4D20 0x021C4D20 data a4
 *   d_021C4D10 0x021C4D10 data a1
 */
#include "../include/Obj08255.h"
typedef signed char s8;
typedef signed short s16;
extern const int d_021C4D20[];
extern const s8 d_021C4D10[];
s8 func_021B6ADC(int sample, char *p)
{
    int code, delta, step, value, index;
    code = 0;
    index = ((struct Obj08255 *)p)->f2;
    value = ((struct Obj08255 *)p)->f0;
    step = d_021C4D20[index];
    sample -= value;
    if (sample < 0) { code = 8; sample = -sample; }
    delta = step >> 3;
    if (sample >= step) { code |= 4; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 2; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 1; delta += step; }
    if (code & 8) value -= delta;
    else value += delta;
    if (value > 32767) value = 32767;
    else if (value < -32767) value = -32767;
    index += d_021C4D10[code];
    if (index < 0) index = 0;
    if (index > 88) index = 88;
    ((struct Obj08255 *)p)->f0 = value;
    ((struct Obj08255 *)p)->f2 = index;
    return code & 15;
}
