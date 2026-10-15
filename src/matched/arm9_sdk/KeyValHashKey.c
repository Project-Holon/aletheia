/*
 * function: PARTICLE_KillAllEffects
 * address:  0x02051620
 * packet:   pkt_02051620
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SPL_EMITTER_FreeResourceList 0x020524C8 arm
 */

extern void SPL_EMITTER_FreeResourceList(void *p);

void PARTICLE_KillAllEffects(void **p)
{
    SPL_EMITTER_FreeResourceList(*p);
}
