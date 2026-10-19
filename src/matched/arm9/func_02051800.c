/*
 * function: PARTICLE_EMITTER_SetOffsetX
 * address:  0x02051800
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x64. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16174.h"

void PARTICLE_EMITTER_SetOffsetX(char *p, int v)
{
    ((struct Obj16174 *)p)->f64 = v;
}
