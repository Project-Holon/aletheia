/*
 * function: BTL_CALC_PackPokeIds
 * address: 0x021D806C
 * packet: pkt_ov093_021D806C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 BTL_CALC_PackPokeIds(const u8 *p) { u32 v=0; u32 i; for(i=0;i<6;i++) v|=(p[i]&31)<<(i*5); return v; }
