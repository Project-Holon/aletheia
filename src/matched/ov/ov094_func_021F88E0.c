/*
 * function: BTLV_EFFECT_IsSeSuppressed
 * address:  0x021F88E0
 * packet:   pkt_ov094_021F88E0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns flag bit 26 of the word at 0x1ec of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned lo : 26;
    unsigned b26 : 1;
} Work;

extern Work *gBtlvEff;

int BTLV_EFFECT_IsSeSuppressed(void)
{
    return gBtlvEff->b26;
}
