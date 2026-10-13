/*
 * function: func_021C665C
 * address: 0x021C665C
 * packet: pkt_ov128_021C665C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: preserves incoming r0 at the tail call; callers load its argument
 *   even though CLACT_VBlankSystem's own body ignores that register.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void func_021C665C(void *p) { CLACT_VBlankSystem(); }
