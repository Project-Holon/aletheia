/*
 * function: WEATHER_DIAMOND_DUST_UpdateParticle
 * address:  0x021EF5D0
 * packet:   pkt_ov025_021EF5D0
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_DIAMOND_DUST_UpdateParticle 0x021EF5D0 thumb ov025
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   WEATHER_TASK_GetParticlePos 0x021A2640 thumb ov021
 *   WEATHER_TASK_RemoveParticle 0x021A21E0 thumb ov021
 *   _s32_div_f    0x0209C0A4 arm
 */

typedef signed short s16;

typedef unsigned int   u32;
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
struct PtS;
extern void WEATHER_TASK_GetParticlePos(unsigned char *, struct PtS *);
extern void WEATHER_TASK_RemoveParticle(u32 *p);

void WEATHER_DIAMOND_DUST_UpdateParticle(int a)
{
    int *p;
    s16 v[2];

    p = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)a);
    WEATHER_TASK_GetParticleActor((unsigned char *)a);
    WEATHER_TASK_GetParticlePos((unsigned char *)a, (struct PtS *)v);
    *p = *p + 1;
    if (*p % p[4] == 0) {
        v[0] = v[0] + (s16)p[2];
    }
    if (*p % p[5] == 0) {
        v[1] = v[1] + (s16)p[3];
    }
    if (*p >= p[1]) {
        WEATHER_TASK_RemoveParticle((u32 *)a);
    }
}
