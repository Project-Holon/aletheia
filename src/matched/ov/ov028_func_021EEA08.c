/*
 * function: WEATHER_FOG_EndParticles
 * address: 0x021EEA08
 * packet: pkt_ov028_021EEA08
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 */

extern int *WEATHER_TASK_GetWorkBuffer(int *);
int WEATHER_FOG_EndParticles(int *a)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer(a);
    p[1] = 0;
    return 1;
}
