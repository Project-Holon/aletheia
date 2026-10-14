/*
 * function: BTLV_EFFECT_SetPokeSpriteKey
 * address:  0x021F7EE8
 * packet:   pkt_ov094_021F7EE8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_MCSS_AddPoke  0x021FEEA8  thumb  ov094
 */

typedef unsigned int u32;

extern char *gBtlvEff;
extern void BTLV_MCSS_AddPoke(char *w, void *src, int key);

void BTLV_EFFECT_SetPokeSpriteKey(void *m, int key)
{
    BTLV_MCSS_AddPoke(*(char **)(gBtlvEff + 0x190), m, key);
}
