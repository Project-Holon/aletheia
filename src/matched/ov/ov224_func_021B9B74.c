/*
 * function: SUBWAY_MAP_GRAPHIC_VBlankClactUnit
 * address: 0x021B9B74
 * packet: pkt_ov224_021B9B74
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void SUBWAY_MAP_GRAPHIC_VBlankClactUnit(void *a0) { CLACT_VBlankSystem(); }
