/*
 * function: BTL_POKEPARAM_AdvanceHitTurn
 * address: 0x021D6824
 * packet: pkt_ov093_021D6824
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_POKEPARAM_AdvanceHitTurn(u8 *p) { p[0x1ef]++; if(p[0x1ef]>=3) p[0x1ef]=0; (p+p[0x1ef])[0x1ec]=0; }
