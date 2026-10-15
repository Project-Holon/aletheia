/*
 * function: MANUAL_GRAPHIC_DrawClactUnit
 * address: 0x021B9B28
 * packet: pkt_ov225_021B9B28
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 */
typedef unsigned short u16;
extern void CLACT_DrawSystem(void);
void MANUAL_GRAPHIC_DrawClactUnit(void *a0) {CLACT_DrawSystem();}
