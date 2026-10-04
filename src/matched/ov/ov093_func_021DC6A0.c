/*
 * function: func_021DC6A0
 * address: 0x021DC6A0
 * packet: pkt_ov093_021DC6A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DC6DC 0x021DC6DC thumb ov093
 *   func_021E8624 0x021E8624 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
typedef unsigned short u16;
extern int func_021D775C(int);
extern int func_021DC6DC(u16);
extern int func_021E8624(int a, int b);
extern void func_021D7704(int,int);
void func_021DC6A0(int a, void *b, int c) { if (c == func_021D775C(3) && func_021DC6DC(func_021D775C(18)) == 0 && func_021E8624((int)b,c) != 0) func_021D7704(49,0x14cd); }
