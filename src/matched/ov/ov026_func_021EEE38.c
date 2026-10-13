/*
 * function: WEATHER_THUNDERSTORM_SpawnParticles
 * address:  0x021EEE38
 * packet:   pkt_ov026_021EEE38
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_SpawnParticles  0x021EEE38  thumb  ov026
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_SetParticlePos  0x021A26C4  thumb  ov021
 *   gWeatherThunderstormSpeedScale     0x021EFD08  data  ov026  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void *WEATHER_TASK_AddParticle(void *p, int a1);
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
extern int WEATHER_TASK_SetParticlePos(u32 a, u32 b);
extern int gWeatherThunderstormSpeedScale[];

void WEATHER_THUNDERSTORM_SpawnParticles(int a, int n, int idx)
{
    int i;
    int *w;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 m;
    Pt pt;

    w = WEATHER_TASK_GetWorkBuffer((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)WEATHER_TASK_AddParticle((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)obj);
        h = WEATHER_TASK_GetParticleActor((unsigned char *)obj);
        r = func_020056EC(0);
        m = r % 3;
        CLACT_SetActorAnimIndex(h, (u16)m);
        e[2] = e[4] = (r & 15) + (m + 1) * 14;
        e[4] = gWeatherThunderstormSpeedScale[w[2] / 60] * e[4] / 10;
        e[2] = gWeatherThunderstormSpeedScale[w[2] / 60] * e[2] / 10;
        e[3] = 0;
        pt.x = r % 0x180 - 0x80;
        pt.y = r % 0x28 - 0x50;
        WEATHER_TASK_SetParticlePos(obj, (u32)(&pt));
    }
}
