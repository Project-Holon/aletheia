/*
 * function: BTL_REC_SEL_GRAPHIC_DrawClact
 * address: 0x021BB3C8
 * packet: pkt_ov214_021BB3C8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_DrawSystem(void);
void BTL_REC_SEL_GRAPHIC_DrawClact(void) { CLACT_DrawSystem(); }
