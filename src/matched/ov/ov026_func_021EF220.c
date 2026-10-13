/*
 * function: WEATHER_STORM_SpawnParticles
 * address:  0x021EF220
 * packet:   pkt_ov026_021EF220
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   gWeatherStormDropInit     0x021EFDC0  data  a4
 */
#include "../include/Obj09778.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020056EC(u32 v);
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void *WEATHER_TASK_AddParticle(void *p, int a1);
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
extern void (*gWeatherStormDropInit[])(int, s32, s32 *, int);

void WEATHER_STORM_SpawnParticles(int a, int n, int idx)
{
    u32 r;
    u32 rem;
    u8 *w;
    int i;
    int obj;
    s32 *e;
    int q;

    r = func_020056EC(0);
    w = (u8 *)WEATHER_TASK_GetWorkBuffer((int *)a);
    if (((struct Obj09778 *)w)->f10 == 0) {
        return;
    }
    if (((struct Obj09778 *)w)->f10 == 2 && (r & 1)) {
        return;
    }
    i = 0;
    if (n <= 0) {
        return;
    }
    rem = r % 100;
    do {
        obj = (int)WEATHER_TASK_AddParticle((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (s32 *)WEATHER_TASK_GetParticleWork((unsigned char *)obj);
        q = WEATHER_TASK_GetParticleActor((unsigned char *)obj);
        e[1] = (s32)w;
        switch (((struct Obj09778 *)w)->f10) {
        case 0:
            break;
        case 1:
            e[0] = 1;
            break;
        case 2:
            if (rem <= 0x32) { e[0] = 2; } else { e[0] = 0; }
            break;
        case 3:
        case 4:
            if (rem <= 0x50) { e[0] = 1; } else { e[0] = 2; }
            break;
        }
        gWeatherStormDropInit[e[0]](obj, e[1], e + 2, q);
        i++;
    } while (i < n);
}
