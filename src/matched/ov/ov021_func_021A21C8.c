/*
 * function: WEATHER_TASK_AddParticle
 * address:  0x021A21C8
 * packet:   pkt_ov021_021A21C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_FindFreeParticle  0x021A274C  thumb  ov021
 *   WEATHER_TASK_LinkParticle  0x021A277C  thumb  ov021
 */

void *WEATHER_TASK_FindFreeParticle(void *p);
void WEATHER_TASK_LinkParticle(void *p, void *q);

void *WEATHER_TASK_AddParticle(void *p, int a1)
{
    void *r = WEATHER_TASK_FindFreeParticle(p);

    if (r != 0)
        WEATHER_TASK_LinkParticle(p, r);
    return r;
}
