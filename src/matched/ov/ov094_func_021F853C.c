/*
 * function: BTLV_EFFECT_GetPokeSpriteState
 * address:  0x021F853C
 * packet:   pkt_ov094_021F853C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_MCSS_IsVanished with the handle at 0x190 of the global work block.
 * Unlabelled; filed as a witness for the caller ov093 BTLV_CORE_SetMonShown (wave B3 lane 17).
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_MCSS_IsVanished  0x021FF348  thumb  ov094
 */
extern char *gBtlvEff;
extern int BTLV_MCSS_IsVanished(void *, int);

int BTLV_EFFECT_GetPokeSpriteState(int a)
{
    return BTLV_MCSS_IsVanished(*(void **)(gBtlvEff + 0x190), a);
}
