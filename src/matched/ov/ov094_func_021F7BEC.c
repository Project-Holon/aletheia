/*
 * function: BTLV_EFFECT_PauseVm
 * address:  0x021F7BEC
 * packet:   pkt_ov094_021F7BEC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls BTLV_EFFVM_StopScript on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 0.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_EFFVM_StopScript 0x021F97E4 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_EFFVM_StopScript(void *);

void BTLV_EFFECT_PauseVm(void)
{
    BTLV_EFFVM_StopScript(*(void **)(gBtlvEff + 0x188));
    *(int *)(gBtlvEff + 0x1e8) = 0;
}
