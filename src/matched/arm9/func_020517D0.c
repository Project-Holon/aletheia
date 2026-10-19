/*
 * function: PARTICLE_EMITTER_GetScaleX
 * address:  0x020517D0
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x5c. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16169.h"

int PARTICLE_EMITTER_GetScaleX(char *p)
{
    return ((struct Obj16169 *)p)->f5C;
}
