/*
 * function: WEATHER_TASK_GetParticleWork
 * address:  0x021A2630
 * packet:   pkt_ov021_021A2630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleWorkPtr 0x021A2C24 thumb ov021
 */

extern unsigned char *WEATHER_TASK_GetParticleWorkPtr(unsigned char *o);

unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o)
{
    return WEATHER_TASK_GetParticleWorkPtr(o);
}
