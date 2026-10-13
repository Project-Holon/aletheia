/*
 * function: TOWNMAP_GRH_VBlankSprites
 * address: 0x021BBB04
 * packet: pkt_ov072_021BBB04
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void TOWNMAP_GRH_VBlankSprites(void *p) { CLACT_VBlankSystem(); }
