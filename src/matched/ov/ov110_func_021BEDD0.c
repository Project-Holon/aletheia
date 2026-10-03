/*
 * function: func_021BEDD0
 * address: 0x021BEDD0
 * packet: pkt_ov110_021BEDD0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEDC4 0x021BEDC4 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BEDC4(u8 *);
unsigned func_021BEDD0(u8 *p) { return *(u16 *)p*2+func_021BEDC4(p); }
