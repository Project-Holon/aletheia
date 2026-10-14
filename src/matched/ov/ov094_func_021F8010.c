/*
 * function: BTLV_EFFECT_ReleasePokeSprite
 * address:  0x021F8010
 * packet:   pkt_ov094_021F8010
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls BTLV_MCSS_RemoveSprite for slot a, then marks slot a-8 of the table at 0x1f8 free.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_MCSS_RemoveSprite 0x021FF0F8 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_MCSS_RemoveSprite(void *, int);

void BTLV_EFFECT_ReleasePokeSprite(int a)
{
    BTLV_MCSS_RemoveSprite(*(void **)(gBtlvEff + 0x190), a);
    ((int *)(gBtlvEff + 0x1f8))[a - 8] = -1;
}
