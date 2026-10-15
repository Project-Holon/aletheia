/*
 * function: PARTICLE_KillEffect
 * address:  0x02051630
 * packet:   pkt_02051630
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Dereference the first argument and tail-call SPL_EMITTER_FreeResource with the loaded
 * pointer.  Unlabelled ARM leaf in the ARM9 listing; matched so its overlay
 * callers get a `matched` witness.
 *
 * symbols:
 *   SPL_EMITTER_FreeResource  0x0205250C  arm
 */

extern void SPL_EMITTER_FreeResource(char *p, char *q);

void PARTICLE_KillEffect(void **p, void *q)
{
    SPL_EMITTER_FreeResource(*p, q);
}
