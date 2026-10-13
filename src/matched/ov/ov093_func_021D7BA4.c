/*
 * function: BTL_CALC_RollHitCount
 * address: 0x021D7BA4
 * packet: pkt_ov093_021D7BA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   gBtlCalcHitCountThresholds 0x021F0421 data a1
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 BTL_CALC_Random(u32);
extern u8 gBtlCalcHitCountThresholds[6];
int BTL_CALC_RollHitCount(int a) { u8 r,i; if(a!=5) return a; r=BTL_CALC_Random(100); for(i=0;i<6;++i) { if(r<gBtlCalcHitCountThresholds[i]) return i; } return a; }
