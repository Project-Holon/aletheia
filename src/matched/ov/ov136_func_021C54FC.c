/*
 * function: MB_SEQ_VBlankTask
 * address:  0x021C54FC
 * packet:   pkt_ov136_021C54FC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_VBlankTask 0x021C54FC thumb
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void func_020419E4(void);
extern void CLACT_VBlankSystem(void);
void MB_SEQ_VBlankTask(void)
{
    func_020419E4();
    CLACT_VBlankSystem();
}
