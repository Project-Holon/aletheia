/*
 * function: MB_COMM_SYS_VBlank
 * address: 0x021EEEAC
 * packet: pkt_ov107_021EEEAC
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Full 8-byte tailstub loads the even ARM target 0204A648; its own matched body takes no inputs.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void MB_COMM_SYS_VBlank(void) { CLACT_VBlankSystem(); }
