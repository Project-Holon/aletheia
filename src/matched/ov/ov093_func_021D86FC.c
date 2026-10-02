/*
 * unit: yes
 * function: func_021D86FC, func_021D8728
 * address: 0x021D86FC
 * packet: pkt_ov093_021D86FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F07C8 0x021F07C8 data ov093 a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021F07C8[];
extern int func_021D775C(int);
extern void func_021D7704(int,int);
void func_021D86FC(int a,int b,int c) { u8 k; if (c==func_021D775C(4)) { k=func_021D775C(22); if (k==14 || k==9) func_021D7704(53,2048); } }
u8 *func_021D8728(u32 *p) { *p=1; return d_021F07C8; }
