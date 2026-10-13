/*
 * function: BTL_SERVER_IsClientUsed
 * address: 0x021BB890
 * packet: pkt_ov093_021BB890
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_IsClientSlotUsed 0x021BB830 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_SERVER_IsClientSlotUsed(u8 *);
int BTL_SERVER_IsClientUsed(u8 *p, u8 i) { if (i < 4) return BTL_SERVER_IsClientSlotUsed(p+20+i*12); return 0; }
