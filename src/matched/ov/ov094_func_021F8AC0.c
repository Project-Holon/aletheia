/*
 * function: BTLV_EFFECT_ResetIntroState
 * address:  0x021F8AC0
 * packet:   pkt_ov094_021F8AC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls BTLV_EFFECT_PauseVm, then stores the argument at 0x238 and clears 0x23c and 0x240 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_EFFECT_PauseVm 0x021F7BEC thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_EFFECT_PauseVm(void);

void BTLV_EFFECT_ResetIntroState(int a)
{
    BTLV_EFFECT_PauseVm();
    *(int *)(gBtlvEff + 0x238) = a;
    *(int *)(gBtlvEff + 0x23c) = 0;
    *(int *)(gBtlvEff + 0x240) = 0;
}
