/*
 * function: BTLV_EFFECT_VBlankTask
 * address:  0x021F8B90
 * packet:   pkt_ov094_021F8B90
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls CLACT_VBlankSystem, then PALANM_TransferPalettes on the handle at 0x18c of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
extern char *gBtlvEff;
extern void CLACT_VBlankSystem(void);
struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);

void BTLV_EFFECT_VBlankTask(void)
{
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(*(void **)(gBtlvEff + 0x18c));
}
