/*
 * function: BTL_CALC_MulRatioMin1
 * address: 0x021D7B2C
 * packet: pkt_ov093_021D7B2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_CALC_MulRatio 0x021D7B10 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 BTL_CALC_MulRatio(u32,u32);
u32 BTL_CALC_MulRatioMin1(u32 a,u32 b) { u32 r=BTL_CALC_MulRatio(a,b); if(r==0) r=1; return r; }
