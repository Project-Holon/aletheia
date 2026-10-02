/*
 * function: func_021D7BA4
 * address: 0x021D7BA4
 * packet: pkt_ov093_021D7BA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D78AC 0x021D78AC thumb ov093
 *   d_021F0421 0x021F0421 data a1
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 func_021D78AC(u32);
extern u8 d_021F0421[6];
int func_021D7BA4(int a) { u8 r,i; if(a!=5) return a; r=func_021D78AC(100); for(i=0;i<6;++i) { if(r<d_021F0421[i]) return i; } return a; }
