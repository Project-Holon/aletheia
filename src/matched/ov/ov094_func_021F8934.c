/*
 * function: BTLV_EFFECT_SetAllPokeSpriteAnim
 * address:  0x021F8934
 * packet:   pkt_ov094_021F8934
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs BTLV_MCSS_SetSpriteWorkFlagForRule with a (enum counter keeps the entry guard) on each of the first 8 active slots of the handle at 0x190.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_MCSS_IsSpriteLoaded 0x021FFD9C thumb ov094
 *   BTLV_MCSS_SetSpriteWorkFlagForRule 0x0220055C thumb ov094
 */
typedef enum { SLOT_ZERO } Slot;

extern char *gBtlvEff;
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern void BTLV_MCSS_SetSpriteWorkFlagForRule(void *, int, int);

void BTLV_EFFECT_SetAllPokeSpriteAnim(int a)
{
    Slot i;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded(*(void **)(gBtlvEff + 0x190), i) != 0)
            BTLV_MCSS_SetSpriteWorkFlagForRule(*(void **)(gBtlvEff + 0x190), i, a);
    }
}
