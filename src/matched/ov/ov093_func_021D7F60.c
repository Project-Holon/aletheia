/*
 * function: func_021D7F60
 * address: 0x021D7F60
 * packet: pkt_ov093_021D7F60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7F38 0x021D7F38 thumb ov093
 *   func_021D7F4C 0x021D7F4C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D7F38(u32);
extern int func_021D7F4C(u32);
int func_021D7F60(u32 n) { if(func_021D7F38(n)) return 1; if(func_021D7F4C(n)) return 1; return n==89; }
