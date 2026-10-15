/*
 * function: SHINKA_DEMO_EFFECT_StartIntro
 * address:  0x0220882C
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Move the ov195 scene object to state 1 with a 0x26c timer.  Labelled leaf.
 *
 * symbols:
 *   SHINKA_DEMO_EFFECT_SetParticleActive  0x02208A2C  thumb
 */
void SHINKA_DEMO_EFFECT_StartIntro(int *p)
{
    void SHINKA_DEMO_EFFECT_SetParticleActive(char *p);

    SHINKA_DEMO_EFFECT_SetParticleActive((char *)p[4]);
    p[2] = 1;
    p[3] = 0x26c;
}
