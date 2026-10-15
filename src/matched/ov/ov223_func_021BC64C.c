/*
 * function: PSEL_GRAPHIC_ClactDraw
 * address: 0x021BC64C
 * packet: pkt_ov223_021BC64C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void CLACT_DrawSystem(void);
void PSEL_GRAPHIC_ClactDraw(void *a0) { CLACT_DrawSystem(); }
