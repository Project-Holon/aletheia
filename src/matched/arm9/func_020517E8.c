/*
 * function: PARTICLE_EMITTER_SetScaleY
 * address:  0x020517E8
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the word at offset 0x60. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16172.h"

void PARTICLE_EMITTER_SetScaleY(char *p, int v)
{
    ((struct Obj16172 *)p)->f60 = v;
}
