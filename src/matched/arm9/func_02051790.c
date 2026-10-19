/*
 * function: PARTICLE_EMITTER_GetPos
 * address:  0x02051790
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies the vector at offset 0x34 out. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */

typedef struct {
    int x, y, z;
} Vec;

void PARTICLE_EMITTER_GetPos(char *p, Vec *out)
{
    *out = *(Vec *)(p + 0x34);
}
