/*
 * function: WEATHER_STORM_ScrollLayers
 * address:  0x021EF830
 * packet:   pkt_ov026_021EF830
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_STORM_ScrollLayers  0x021EF830  thumb  ov026
 *   WEATHER_TASK_GetCameraScroll  0x021A244C  thumb  ov021
 *   WEATHER_TASK_ShiftParticles  0x021A2564  thumb  ov021
 *   WEATHER_TASK_SetBillboardParam0C  0x021A2190  thumb  ov021
 *   WEATHER_TASK_SetBillboardParam10  0x021A21A0  thumb  ov021
 *   WEATHER_TASK_SetBillboardParam14  0x021A2170  thumb  ov021
 *   WEATHER_TASK_SetBillboardParam18  0x021A2180  thumb  ov021
 */
#include "../include/Obj00086.h"

typedef signed short s16;

typedef signed int     s32;
typedef unsigned char  u8;
extern void WEATHER_TASK_GetCameraScroll(u8 *o, s32 *outX, s32 *outY);
extern void WEATHER_TASK_ShiftParticles(int, int, int);
extern void WEATHER_TASK_SetBillboardParam0C(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardParam10(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardParam14(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardParam18(unsigned char *o, unsigned int v, int i);

void WEATHER_STORM_ScrollLayers(int a, s16 *p)
{
    int x;
    int y;

    WEATHER_TASK_GetCameraScroll((u8 *)a, &x, &y);
    WEATHER_TASK_ShiftParticles(a, x, y);
    if (p[11] != 0) {
        p[2] = (p[2] + 9) % 256;
        p[3] = (p[3] + 3) % 256;
        p[4] = (p[4] + 9) % 256;
        p[5] = (p[5] + 2) % 256;
    } else {
        p[2] = (p[2] + 3) % 256;
        p[3] = (p[3] + 8) % 256;
    }
    WEATHER_TASK_SetBillboardParam0C((unsigned char *)a, -(p[2] + x), 0);
    WEATHER_TASK_SetBillboardParam10((unsigned char *)a, y - p[3], 0);
    WEATHER_TASK_SetBillboardParam0C((unsigned char *)a, -(p[4] + x), 1);
    WEATHER_TASK_SetBillboardParam10((unsigned char *)a, y - p[5], 1);
    WEATHER_TASK_SetBillboardParam14((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
    WEATHER_TASK_SetBillboardParam18((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
}
