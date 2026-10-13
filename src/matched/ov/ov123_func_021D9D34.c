/*
 * function: func_021D9D34
 * address: 0x021D9D34
 * packet: pkt_ov123_021D9D34
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker of owned ov123 021D9958; parent ownership audit passed.
 * extent: 8-byte tailcall stub; next labelled function 021D9D3C follows.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void func_021D9D34(void)
{
    CLACT_VBlankSystem();
}
