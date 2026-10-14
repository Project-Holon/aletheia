/*
 * function: GSYNC_MENU_VBlank
 * address: 0x021D5120
 * packet: pkt_ov123_021D5120
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: root claimed this sole blocker of 021D5128; target's matched
 * definition and original body read no incoming argument registers.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void GSYNC_MENU_VBlank(void)
{
    CLACT_VBlankSystem();
}
