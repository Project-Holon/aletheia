/*
 * function: SUBWAY_MAP_GRAPHIC_DrawClactUnit
 * address: 0x021B9B6C
 * packet: pkt_ov224_021B9B6C
 * region: ov224
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
void SUBWAY_MAP_GRAPHIC_DrawClactUnit(void *a0) { CLACT_DrawSystem(); }
