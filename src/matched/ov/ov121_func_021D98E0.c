/*
 * function: MYSTERY_GRAPHIC_DrawClact
 * address: 0x021D98E0
 * packet: pkt_ov121_021D98E0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 */
extern void CLACT_DrawSystem(void);
void MYSTERY_GRAPHIC_DrawClact(void *a0) { CLACT_DrawSystem(); }
