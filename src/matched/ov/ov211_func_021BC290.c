/*
 * function: func_021BC290
 * address: 0x021BC290
 * packet: pkt_ov211_021BC290
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BC8D8 0x021BC8D8 data a4
 */
extern unsigned char d_021BC8D8[];
int func_021BC290(unsigned char *p){*(unsigned *)(p+12)=(*(unsigned (**)(unsigned char *))(d_021BC8D8+*(unsigned *)(p+12)*4))(p);return *(unsigned *)(p+12)!=6;}
