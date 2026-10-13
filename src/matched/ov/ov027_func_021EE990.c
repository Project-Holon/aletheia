/*
 * function: func_021EE990
 * address:  0x021EE990
 * packet:   pkt_ov027_021EE990
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The 2 trailing bytes (0x021EEA02) are alignment padding before
 * WEATHER_SANDSTORM_SpawnParticles, which is why the verdict is EXACT*.
 *
 * symbols:
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_GetParticlePos  0x021A2640  thumb  ov021
 *   WEATHER_TASK_SetParticlePosWrapped  0x021A2654  thumb  ov021
 *   WEATHER_TASK_RemoveParticle  0x021A21E0  thumb  ov021
 */

typedef unsigned int   u32;
unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
struct PtS;
void WEATHER_TASK_GetParticlePos(unsigned char *a, struct PtS *pt);
void WEATHER_TASK_SetParticlePosWrapped(int obj, unsigned short *src);
void WEATHER_TASK_RemoveParticle(u32 *p);

void func_021EE990(int a)
{
    int *o = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)a);
    short pt[2];

    WEATHER_TASK_GetParticleActor((unsigned char *)a);
    WEATHER_TASK_GetParticlePos((unsigned char *)a, (struct PtS *)pt);
    if (o[3] == 0) {
        pt[0] = pt[0] + (short)o[4];
        pt[1] = pt[1] + (short)o[2];
        if (o[0] % 5 == 0)
            o[4] = o[4] + o[5];
        if (o[0]++ > o[1])
            o[3] = 1;
        WEATHER_TASK_SetParticlePosWrapped(a, (short unsigned int *)pt);
    } else {
        WEATHER_TASK_RemoveParticle((u32 *)a);
    }
}
