/*
 * function: CG_HELP_VBlank
 * address: 0x021D43F0
 * packet: pkt_ov124_021D43F0
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 * extent: 8-byte tail stub; labelled function 021D43F8 follows.
 */
extern void CLACT_VBlankSystem(void);
void CG_HELP_VBlank(void)
{
    CLACT_VBlankSystem();
}
