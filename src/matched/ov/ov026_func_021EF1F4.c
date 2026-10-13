/*
 * function: WEATHER_STORM_UpdateParticle
 * address: 0x021EF1F4
 * packet: pkt_ov026_021EF1F4
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   gWeatherStormDropUpdate 0x021EFDCC data ov026 a4
 */
#include "../include/Obj20382.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *WEATHER_TASK_GetParticleWork(u8 *);
extern u32 WEATHER_TASK_GetParticleActor(u8 *);
extern void (*gWeatherStormDropUpdate[])(u8 *, int, u8 *, u32);
void WEATHER_STORM_UpdateParticle(u8 *a)
{
    u8 *p;
    u32 q;
    p = WEATHER_TASK_GetParticleWork(a);
    q = WEATHER_TASK_GetParticleActor(a);
    gWeatherStormDropUpdate[*(int *)p](a, ((struct Obj20382 *)p)->f4, p + 8, q);
}
