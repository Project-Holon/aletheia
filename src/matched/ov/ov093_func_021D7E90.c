/*
 * function: BTL_CALC_ContainsU16
 * address: 0x021D7E90
 * packet: pkt_ov093_021D7E90
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
int BTL_CALC_ContainsU16(const u16 *p,u32 n,u32 v) { u32 i; for(i=0;i<n;i++) { if(v==p[i]) return 1; } return 0; }
