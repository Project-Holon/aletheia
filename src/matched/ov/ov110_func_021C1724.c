/*
 * function: func_021C1724
 * address: 0x021C1724
 * packet: pkt_ov110_021C1724
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C17D4 0x021C17D4 thumb ov110
 *   func_021C1840 0x021C1840 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C17D4(void *);
extern void func_021C1840(void *);
void func_021C1724(int a,u8 *p) { func_021C17D4(p); func_021C1840(p+4); }
