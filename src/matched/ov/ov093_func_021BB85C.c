/*
 * function: BTL_SERVER_GetClientChecked
 * address: 0x021BB85C
 * packet: pkt_ov093_021BB85C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i) { if (i < 4 && (p+i*12)[31] != 255) return p+20+i*12; return 0; }
