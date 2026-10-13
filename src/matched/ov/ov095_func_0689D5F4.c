/*
 * function: BTL_POSPOKE_GetPosByPokeId
 * address: 0x0689D5F4
 * packet: pkt_ov095_0689D5F4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: reads r0 base and full-word r1 index; byte load returned in r0.
 */
typedef unsigned char u8;
int BTL_POSPOKE_GetPosByPokeId(u8 *p, int i) { return (p + i)[18]; }
