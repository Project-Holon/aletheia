/*
 * function: WEATHER_TASK_RemoveParticle
 * address:  0x021A21E0
 * packet:   pkt_ov021_021A21E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_TASK_IsParticleLinked  0x021A2BC4  thumb  ov021
 *   WEATHER_TASK_UnlinkParticle  0x021A27B8  thumb  ov021
 */

typedef unsigned int u32;

int WEATHER_TASK_IsParticleLinked(u32 a);
void WEATHER_TASK_UnlinkParticle(u32 x, u32 *p);

void WEATHER_TASK_RemoveParticle(u32 *p)
{
    if (WEATHER_TASK_IsParticleLinked((u32)p) != 0)
        WEATHER_TASK_UnlinkParticle(p[0], p);
}
