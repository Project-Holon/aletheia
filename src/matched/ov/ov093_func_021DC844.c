/*
 * function: func_021DC844
 * address: 0x021DC844
 * packet: pkt_ov093_021DC844
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: second payload of func_021D7320 is the unchanged callback word.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021DC820 0x021DC820 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct QS { u8 pad[12]; u32 v; };
extern int func_021D775C(int);
extern void func_021D7320(struct QS *, u32);
extern int func_021DC820(u8 *, int, int, int, u16, u8);
void func_021DC844(struct QS *a, int b, int c) { if (c == func_021D775C(3)) func_021D7320(a, (u32)func_021DC820); }
