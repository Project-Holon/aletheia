/*
 * function: INTRUDE_COMM_VIEW_VBlankHandler
 * address: 0x021D5368
 * packet: pkt_ov122_021D5368
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: root-claimed sole callback witness for INTRUDE_COMM_VIEW_Create.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void INTRUDE_COMM_VIEW_VBlankHandler(void)
{
    CLACT_VBlankSystem();
}
