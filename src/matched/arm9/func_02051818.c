/*
 * function: PARTICLE_EMITTER_SetOffsetY
 * address:  0x02051818
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x68. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16176.h"

void PARTICLE_EMITTER_SetOffsetY(char *p, int v)
{
    ((struct Obj16176 *)p)->f68 = v;
}
