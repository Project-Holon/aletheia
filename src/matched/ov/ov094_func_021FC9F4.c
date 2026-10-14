/*
 * function: BTLV_EFFVM_WaitParticleCallback
 * address:  0x021FC9F4
 * packet:   pkt_ov094_021FC9F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wait callback: done once flag bit 16 of the state word is clear.
 */
typedef struct {
    unsigned lo : 16;
    unsigned bit : 1;
} Flags;

int BTLV_EFFVM_WaitParticleCallback(void *a, Flags *s)
{
    if (s->bit)
        return 0;
    return 1;
}
