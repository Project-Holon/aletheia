/*
 * function: func_021C7D00
 * address: 0x021C7D00
 * packet: pkt_ov093_021C7D00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7D24 0x021C7D24 thumb ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 */
typedef unsigned char u8;
extern int func_021C7D24(u8 *);
extern int func_021B86A0(unsigned int **, unsigned int);
int func_021C7D00(u8 *p) { int i = func_021C7D24(p + 0x1ab8); if (!func_021B86A0(*(unsigned int ***)(p + 4), i)) i = 6; return i; }
