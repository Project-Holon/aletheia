/*
 * function: WEATHER_TASK_Create
 * address:  0x021A1DB4
 * packet:   pkt_ov021_021A1DB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gWeatherTaskFileName     0x021DDE80  data  ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03584.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 gWeatherTaskFileName[];
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);

u32 *WEATHER_TASK_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i)
{
    u32 *o;

    o = func_02030734(i, 0x784, 1, (const char *)gWeatherTaskFileName, 0x17E);
    o[0] = a;
    o[5] = b;
    o[1] = d;
    o[2] = c;
    o[4] = e;
    o[6] = f;
    o[3] = g;
    ((struct Obj03584 *)o)->f1C = h;
    return o;
}
