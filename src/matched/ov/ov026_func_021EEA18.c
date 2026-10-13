/*
 * function: WEATHER_RAIN_SpawnParticles
 * address:  0x021EEA18
 * packet:   pkt_ov026_021EEA18
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_RAIN_SpawnParticles  0x021EEA18  thumb  ov026
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_SetParticlePos  0x021A26C4  thumb  ov021
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

void WEATHER_RAIN_SpawnParticles(int a, int n, int idx)
{
    int i;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 m;
    int k;
    Pt pt;

    WEATHER_TASK_GetWorkBuffer((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)WEATHER_TASK_AddParticle((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)obj);
        h = WEATHER_TASK_GetParticleActor((unsigned char *)obj);
        r = func_020056EC(0);
        e[0] = 0;
        m = r % 3;
        CLACT_SetActorAnimIndex(h, (u16)m);
        k = r % 20;
        e[2] = k + (m + 1) * 16;
        if (m == 2) {
            e[2] += 16;
        }
        e[4] = k / 8 + (m + 1) * 8;
        if (m == 2) {
            e[4] += 8;
        }
        e[3] = 0;
        e[1] = (r & 1) + 1;
        pt.x = (u8)r + (m * 15 - 0x48);
        pt.y = -0x60;
        WEATHER_TASK_SetParticlePos(obj, (u32)(&pt));
        e[4] = e[4] * 2;
        e[2] = e[2] * 2;
        e[5] = func_020056EC(10);
    }
}
