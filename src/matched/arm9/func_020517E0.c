/*
 * function: PARTICLE_EMITTER_GetScaleY
 * address:  0x020517E0
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x60. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16171.h"

int PARTICLE_EMITTER_GetScaleY(char *p)
{
    return ((struct Obj16171 *)p)->f60;
}
