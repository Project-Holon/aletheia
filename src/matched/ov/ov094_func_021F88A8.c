/*
 * function: BTLV_EFFECT_GetVisibilityMode
 * address:  0x021F88A8
 * packet:   pkt_ov094_021F88A8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns bits 18..25 of the word at 0x1ec of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned m : 8;
    unsigned lo : 10;
    unsigned v : 8;
    unsigned b26 : 1;
} Work;

extern Work *gBtlvEff;

int BTLV_EFFECT_GetVisibilityMode(void)
{
    return gBtlvEff->v;
}
