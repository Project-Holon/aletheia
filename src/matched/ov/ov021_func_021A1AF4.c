/*
 * function: WEATHER_Update
 * address:  0x021A1AF4
 * packet:   pkt_ov021_021A1AF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWeatherTransitionHandlers     0x021DDE6C  data  ov021  a4
 *   WEATHER_RequestChange  0x021A1BDC  thumb  ov021
 *   WEATHER_TASK_Update  0x021A1E08  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09548.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void (*const gWeatherTransitionHandlers[])(void *p, int x);
extern void WEATHER_RequestChange(void *p, u32 v);
extern void WEATHER_TASK_Update(u32 v, int x);

void WEATHER_Update(u8 *p, int x)
{
    int i;
    u16 t;

    gWeatherTransitionHandlers[*(u16 *)(p + 8)](p, x);
    if (((struct Obj09548 *)p)->fA == 0) {
        t = ((struct Obj09548 *)p)->f14;
        if (t != 0xFFFF) {
            WEATHER_RequestChange(p, t);
            ((struct Obj09548 *)p)->f14 = 0xFFFF;
        }
    }
    for (i = 0; i < 2; i++) {
        WEATHER_TASK_Update(*(u32 *)(p + 0x20 + i * 4), x);
    }
}
