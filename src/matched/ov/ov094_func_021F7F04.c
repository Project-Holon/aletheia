/*
 * function: BTLV_EFFECT_DeletePokeSprite
 * address:  0x021F7F04
 * packet:   pkt_ov094_021F7F04
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_MCSS_RemoveSprite with the handle at 0x190 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_MCSS_RemoveSprite 0x021FF0F8 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_MCSS_RemoveSprite(void *, int);

void BTLV_EFFECT_DeletePokeSprite(int a)
{
    BTLV_MCSS_RemoveSprite(*(void **)(gBtlvEff + 0x190), a);
}
