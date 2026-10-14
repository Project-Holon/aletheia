/*
 * function: PARTICLE_SetupSystemNoHandlers
 * address:  0x02051380
 * packet:   pkt_02051380
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with two zero arguments. Filed as the witness for ov094 BTLV_EFFVM_CmdLoadParticleResource.
 *
 * symbols:
 *   PARTICLE_SetupSystem  0x02051230  arm
 */

extern void PARTICLE_SetupSystem(void *, void *, int, int);

void PARTICLE_SetupSystemNoHandlers(void *p, void *r)
{
    PARTICLE_SetupSystem(p, r, 0, 0);
}
