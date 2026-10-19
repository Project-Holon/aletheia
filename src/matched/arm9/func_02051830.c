/*
 * function: PARTICLE_EMITTER_GetAlpha
 * address:  0x02051830
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the halfword at offset 0x70. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16178.h"

unsigned short PARTICLE_EMITTER_GetAlpha(char *p)
{
    return ((struct Obj16178 *)p)->f70;
}
