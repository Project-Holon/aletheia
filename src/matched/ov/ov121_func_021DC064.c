/*
 * function: func_021DC064
 * address: 0x021DC064
 * packet: pkt_ov121_021DC064
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC030 0x021DC030 thumb ov121
 *   d_021DF848 0x021DF848 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021DC024(void *);
extern int func_021DC030(u32 p);
extern const int d_021DF848[];
int func_021DC064(void *p) { int i,add; i=func_021DC024(p); add=func_021DC030((u32)p) ? 3 : 0; return add+d_021DF848[i]; }
