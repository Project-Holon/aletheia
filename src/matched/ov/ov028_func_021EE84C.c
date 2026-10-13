/*
 * unit: yes
 * function: WEATHER_FOG_EndFinishFixed, WEATHER_FOG_UpdateParticleFixed
 * address: 0x021EE84C
 * packet: pkt_ov028_021EE84C
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 */

typedef unsigned int u32;
extern void WEATHER_TASK_DisableFog(u32 *, int);
extern void WEATHER_TASK_ResetLight(u32 *, int);
int WEATHER_FOG_EndFinishFixed(u32 *a, int b)
{
    WEATHER_TASK_DisableFog(a, b);
    WEATHER_TASK_ResetLight(a, b);
    return 1;
}

void WEATHER_FOG_UpdateParticleFixed(void)
{
}
