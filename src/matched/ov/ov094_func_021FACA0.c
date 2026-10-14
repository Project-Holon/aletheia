/*
 * function: BTLV_EFFVM_ParticleInitCallbackTarget
 * address:  0x021FACA0
 * packet:   pkt_ov094_021FACA0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_EFFVM_SetupEmitterCallbacks with mode 1.
 *
 * symbols:
 *   BTLV_EFFVM_SetupEmitterCallbacks 0x021FDFA0 thumb ov094
 */
extern int BTLV_EFFVM_SetupEmitterCallbacks(void *a, char *s, int mode);

void BTLV_EFFVM_ParticleInitCallbackTarget(void *a, void *b)
{
    BTLV_EFFVM_SetupEmitterCallbacks(a, b, 1);
}
