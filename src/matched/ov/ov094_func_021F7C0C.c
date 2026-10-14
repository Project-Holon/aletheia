/*
 * function: BTLV_EFFECT_ResumeVm
 * address:  0x021F7C0C
 * packet:   pkt_ov094_021F7C0C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls BTLV_EFFVM_ClearBlockedFlag on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 1.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_EFFVM_ClearBlockedFlag 0x021F9814 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_EFFVM_ClearBlockedFlag(void *);

void BTLV_EFFECT_ResumeVm(void)
{
    BTLV_EFFVM_ClearBlockedFlag(*(void **)(gBtlvEff + 0x188));
    *(int *)(gBtlvEff + 0x1e8) = 1;
}
