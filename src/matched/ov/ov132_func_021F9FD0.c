/*
 * function: STA_ACT_EFFECT_SetEmitterPos
 * address:  0x021F9FD0
 * packet:   pkt_021F9FD0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_EMITTER_SetEmitPos  0x02051838  arm
 *
 * Addresses are Black-image addresses.
 */

extern void PARTICLE_EMITTER_SetEmitPos(void *, int);

void STA_ACT_EFFECT_SetEmitterPos(char *p, int i, int a)
{
    void *v = *(void **)(p + i * 16 + 0x4808);

    if (v != 0)
        PARTICLE_EMITTER_SetEmitPos(v, a);
}
