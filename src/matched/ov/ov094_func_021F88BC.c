/*
 * function: BTLV_EFFECT_SetSeSuppressed
 * address:  0x021F88BC
 * packet:   pkt_ov094_021F88BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets flag bit 26 of the word at 0x1ec of the global work block.
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

void BTLV_EFFECT_SetSeSuppressed(int a)
{
    gBtlvEff->b26 = a;
}
