/*
 * function: WEATHER_SNOW_SpawnParticles
 * address:  0x021EEA34
 * packet:   pkt_ov025_021EEA34
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_SetParticlePosWrapped  0x021A2654  thumb  ov021
 */

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
extern void WEATHER_TASK_SetParticlePosWrapped(int obj, unsigned short *src);

void WEATHER_SNOW_SpawnParticles(int a, int n, int idx)
{
    int *q;
    int i;
    int obj;
    int *e;
    int h;
    Pt pt;

    q = WEATHER_TASK_GetWorkBuffer((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)WEATHER_TASK_AddParticle((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)obj);
        h = WEATHER_TASK_GetParticleActor((unsigned char *)obj);
        CLACT_SetActorAnimIndex(h, (u16)func_020056EC(4));
        e[4] = 0;
        e[5] = 0;
        e[8] = 0;
        e[9] = (int)func_020056EC(0) % 30 + 2;
        e[3] = func_020056EC(8) + 12;
        e[0] = (int)(q + 1);
        e[7] = (int)(q + 2);
        pt.x = func_020056EC(0x19E) - 0x20;
        if (q[1] == 1 && i >= n / 2) {
            pt.y = -8 - 0x20 - func_020056EC(0x14);
        } else {
            pt.y = -8 - func_020056EC(0x14);
        }
        WEATHER_TASK_SetParticlePosWrapped(obj, (short unsigned int *)(&pt));
    }
}
