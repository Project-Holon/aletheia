/*
 * function: WEATHER_TASK_GetParticleActor
 * address:  0x021A2638
 * packet:   pkt_ov021_021A2638
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
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   WEATHER_TASK_GetParticleActorPtr 0x021A2C28 thumb ov021
 */

extern unsigned int WEATHER_TASK_GetParticleActorPtr(unsigned char *p);

unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o)
{
    return WEATHER_TASK_GetParticleActorPtr(o);
}
