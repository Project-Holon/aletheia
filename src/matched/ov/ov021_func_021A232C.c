/*
 * function: WEATHER_TASK_ChangeFog
 * address:  0x021A232C
 * packet:   pkt_ov021_021A232C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 *   FIELD_FOG_GetSlope  0x021A01D4  thumb  ov021
 *   WEATHER_TASK_QueueFogChange  0x021A2CC8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_FOG_FADE_Init(u8 *p, u32 a, u32 b, u32 c);
extern u32 FIELD_FOG_GetSlope(u8 *p);
extern void WEATHER_TASK_QueueFogChange(void *p, int a, int b, int c);

void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d)
{
    int h;

    if (d == 1) {
        FIELD_FOG_FADE_Init((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
        return;
    }
    if (d == 2) {
        if (a == FIELD_FOG_GetSlope((u8 *)(((struct Obj00954 *)p)->f4))) {
            FIELD_FOG_FADE_Init((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
            return;
        }
        h = c / 2;
        FIELD_FOG_FADE_Init((u8 *)(((struct Obj00954 *)p)->f4), 0x7FDF, FIELD_FOG_GetSlope((u8 *)(((struct Obj00954 *)p)->f4)), h);
        WEATHER_TASK_QueueFogChange(p, a, b, h);
    }
}
