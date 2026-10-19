/*
 * function: WEATHER_STORM_UpdateGust
 * address:  0x021EF664
 * packet:   pkt_ov026_021EF664
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 12-byte-stride tables index as a struct array: `muls` by the
 * 0xC already live as the p[6] load offset. An int[i * 3] subscript
 * costs a shift/add pair and four bytes.
 *
 * symbols:
 *   WEATHER_STORM_UpdateGust  0x021EF664  thumb  ov026
 *   WEATHER_STORM_PlayGustWarning  0x021EF920  thumb  ov026
 *   WEATHER_STORM_UpdateThunder  0x021EF950  thumb  ov026
 *   WEATHER_STORM_StartCalm  0x021EF614  thumb  ov026
 *   func_020056EC  0x020056EC  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_TASK_SetBillboardScaleX  0x021A2170  thumb  ov021
 *   WEATHER_TASK_SetBillboardScaleY  0x021A2180  thumb  ov021
 *   gWeatherStormGustWindX     0x021EFD74  data  ov026  a4
 *   gWeatherStormGustWindY     0x021EFD78  data  ov026  a4
 *   gWeatherStormGustLayerScale     0x021EFD3C  data  ov026  a4
 */
#include "../include/Obj00086.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
typedef unsigned char  u8;
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardScaleX(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardScaleY(unsigned char *o, unsigned int v, int i);
extern void WEATHER_STORM_PlayGustWarning(u8 *a, s16 *p, int b, int c);
extern void WEATHER_STORM_UpdateThunder(int, s16 *, int);
extern void WEATHER_STORM_StartCalm(int, u16 *, int, int);
typedef struct {
    int a;
    int b;
    int c;
} T3;

extern T3 gWeatherStormGustWindX[];
extern T3 gWeatherStormGustWindY[];
extern int gWeatherStormGustLayerScale[];

void WEATHER_STORM_UpdateGust(int a, s16 *p, int b, int d)
{
    u32 r;
    int i;

    switch (p[8]) {
    case 0:
        break;
    case 1:
        p[6] = p[6] + 1;
        WEATHER_STORM_PlayGustWarning((u8 *)a, p, b, 0x71F);
        if (p[6] >= p[7]) {
            p[8] = 3;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                WEATHER_TASK_ChangeFog((u8 *)a, 9, 0x7F70, 10, b);
                WEATHER_TASK_PlaySe((unsigned char *)a, 0x720);
            }
        }
        break;
    case 2:
        p[6] = p[6] + 1;
        WEATHER_STORM_PlayGustWarning((u8 *)a, p, b, 0x71F);
        WEATHER_STORM_UpdateThunder(a, p, b);
        if (p[6] >= p[7]) {
            p[8] = 4;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 0, 1);
                WEATHER_TASK_SetBillboardScaleX((unsigned char *)a, 0x1000, 0);
                WEATHER_TASK_SetBillboardScaleY((unsigned char *)a, 0x1000, 0);
            }
        }
        break;
    case 3:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            r = func_020056EC(0);
            p[8] = 2;
            p[7] = r % 400 + 0x3C;
            p[6] = 0;
            if (d == 0) {
                WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 1);
                WEATHER_TASK_SetBillboardScaleX((unsigned char *)a, 0x800, 0);
                WEATHER_TASK_SetBillboardScaleY((unsigned char *)a, 0x1800, 0);
            }
        }
        break;
    case 4:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            WEATHER_STORM_StartCalm(a, (u16 *)p, b, d);
        }
        break;
    }
    switch (p[8]) {
    case 0:
        break;
    case 1:
        if (p[7] - p[6] >= 9) {
            p[11] = 0;
            p[12] = 0;
        } else {
            p[11] = 0xA0;
            p[12] = 0x10;
        }
        break;
    case 2:
        i = p[6] % 0x48 * 6 / 0x48;
        p[11] = gWeatherStormGustWindX[i].a;
        p[12] = gWeatherStormGustWindY[i].a;
        ((struct Obj00086 *)p)->f1C = gWeatherStormGustLayerScale[(p[6] % 0xE0u) * 14 / 0xE0u];
        break;
    case 3:
    case 4:
        p[11] = 0xA0;
        p[12] = 0x10;
        ((struct Obj00086 *)p)->f1C = 0x800;
        break;
    }
}
