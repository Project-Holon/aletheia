/*
 * function: func_021DC03C
 * address: 0x021DC03C
 * packet: pkt_ov121_021DC03C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC030 0x021DC030 thumb ov121
 *   d_021DF838 0x021DF838 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021DC024(void *);
extern int func_021DC030(u32 p);
extern const int d_021DF838[];
int func_021DC03C(void *p) { int i,add; i=func_021DC024(p); add=func_021DC030((u32)p) ? 0 : 5; return add+d_021DF838[i]; }
