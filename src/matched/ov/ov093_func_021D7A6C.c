/*
 * function: BTL_CALC_ApplyTypeAffinity
 * address: 0x021D7A6C
 * packet: pkt_ov093_021D7A6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned char u8;
u32 BTL_CALC_ApplyTypeAffinity(u32 a,u32 b) { switch(b) { case 0:return 0; case 1:return a/4; case 2:return a/2; case 3:return a; case 4:return a*2; case 5:return a*4; } return a; }
