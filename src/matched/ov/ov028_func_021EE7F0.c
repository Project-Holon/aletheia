/*
 * function: WEATHER_FOG_EndParticlesFixed
 * address: 0x021EE7F0
 * packet: pkt_ov028_021EE7F0
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
int WEATHER_FOG_EndParticlesFixed(int *a)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer(a);
    p[0] = 0;
    return 1;
}
