/*
 * function: NAMEIN_GRAPHIC_DrawClact
 * address: 0x021F4D0C
 * packet: pkt_ov194_021F4D0C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_DrawSystem(void);
void NAMEIN_GRAPHIC_DrawClact(u8 *a0) { CLACT_DrawSystem(); }
