/*
 * function: func_021D7B3C
 * address: 0x021D7B3C
 * packet: pkt_ov093_021D7B3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
u32 func_021D7B3C(u32 a,u32 b) { u32 m; a*=b; m=a%100; a/=100; if(m>=50) ++a; return a; }
