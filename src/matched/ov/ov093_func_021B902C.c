/*
 * function: func_021B902C
 * address: 0x021B902C
 * packet: pkt_ov093_021B902C
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
int func_021B902C(u8 a,u8 b) { if(a==b) return 1; if(a==(u8)((b+2)&3)) return 1; return 0; }
