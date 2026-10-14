/*
 * function: BTLV_EFFECT_SetIntroState
 * address:  0x021F8A40
 * packet:   pkt_ov094_021F8A40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the mode at 0x238 of the global work block; resets 0x23c/0x240 unless mode 2, and mode 3 calls BTLV_MCSS_SaveVanishStates.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_MCSS_SaveVanishStates 0x02200608 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_MCSS_SaveVanishStates(void *);

void BTLV_EFFECT_SetIntroState(int a)
{
    *(int *)(gBtlvEff + 0x238) = a;
    if (*(int *)(gBtlvEff + 0x238) != 2) {
        *(int *)(gBtlvEff + 0x23c) = 0;
        *(int *)(gBtlvEff + 0x240) = 0;
    }
    if (a == 3)
        BTLV_MCSS_SaveVanishStates(*(void **)(gBtlvEff + 0x190));
}
