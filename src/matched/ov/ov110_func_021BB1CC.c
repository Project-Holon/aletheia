/*
 * function: func_021BB1CC
 * address: 0x021BB1CC
 * packet: pkt_ov110_021BB1CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9A3C 0x021B9A3C thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9A3C(u8 *,u16,int);
int func_021BB1CC(u32 p,u32 i,int c) { return func_021B9A3C(*(u8 **)(p+4),*(u16 *)(p+i*2+0x8bc),c); }
