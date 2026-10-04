/*
 * unit: yes
 * function: func_021D8794, func_021D87BC
 * address: 0x021D8794
 * packet: pkt_ov093_021D8794
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F05D8 0x021F05D8 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021F05D8[];
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021C8288(u8 *p);
void func_021D8794(int a,int b,int c) { if (c==func_021D775C(2)) { if (func_021C8288((u8 *)b)==1) func_021D7704(53,8192); } }
u8 *func_021D87BC(u32 *p) { *p=1; return d_021F05D8; }
