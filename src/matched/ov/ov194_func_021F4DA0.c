/*
 * function: NAMEIN_GRAPHIC_GetGridHeight
 * address: 0x021F4DA0
 * packet: pkt_ov194_021F4DA0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p) { return p[1]; }
