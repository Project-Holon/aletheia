/*
 * function: WEATHER_SNOW_UpdateParticle
 * address:  0x021EE980
 * packet:   pkt_ov025_021EE980
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_SNOW_UpdateParticle  0x021EE980  thumb  ov025
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_GetParticlePos  0x021A2640  thumb  ov021
 *   WEATHER_TASK_SetParticlePosWrapped  0x021A2654  thumb  ov021
 *   WEATHER_TASK_RemoveParticle  0x021A21E0  thumb  ov021
 *   _u32_div_f  0x0209C2B0  arm
 *   gSnowWobbleOffsetX  0x021EF790  data  ov025  a1
 */

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef unsigned int   u32;
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
struct PtS;
extern void WEATHER_TASK_GetParticlePos(unsigned char *, struct PtS *);
extern void WEATHER_TASK_SetParticlePosWrapped(int obj, unsigned short *src);
extern void WEATHER_TASK_RemoveParticle(u32 *p);
extern signed char gSnowWobbleOffsetX[];

void WEATHER_SNOW_UpdateParticle(int a)
{
    int *p;
    int s;
    int *q;
    Pt pt;

    p = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)a);
    WEATHER_TASK_GetParticleActor((unsigned char *)a);
    s = p[8];
    q = (int *)p[7];
    if (s == 0) {
        if (*q != 0) {
            p[8] = s + 1;
        }
    } else {
        p[9] = p[9] - 1;
        if (p[9] < 0) {
            WEATHER_TASK_RemoveParticle((u32 *)a);
            return;
        }
    }
    WEATHER_TASK_GetParticlePos((unsigned char *)a, (struct PtS *)&pt);
    pt.x = pt.x + gSnowWobbleOffsetX[p[5]];
    if (p[4] > p[3]) {
        pt.y = pt.y + 1;
        p[4] = p[4] % p[3];
    }
    WEATHER_TASK_SetParticlePosWrapped(a, (short unsigned int *)(&pt));
    p[4] = p[4] + 8;
    p[5] = (unsigned)(p[5] + 1) % 337u;
    if ((pt.y < -284 && pt.y > -296) || (pt.y > 212 && pt.y < 232)) {
        *(int *)p[0] = 1;
        WEATHER_TASK_RemoveParticle((u32 *)a);
    }
}
