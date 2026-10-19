/*
 * function: PARTICLE_EMITTER_SetScaleX
 * address:  0x020517D8
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x5c. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16170.h"

void PARTICLE_EMITTER_SetScaleX(char *p, int v)
{
    ((struct Obj16170 *)p)->f5C = v;
}
