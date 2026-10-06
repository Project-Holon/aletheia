/*
 * function: func_021D6920
 * address: 0x021D6920
 * packet: pkt_ov093_021D6920
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
int func_021D6920(u8 *p, u32 n) { if(n<3) { n=p[0x1ef]-n; if((int)n<0) n+=3; return (p+n)[0x1ec]; } return 0; }
