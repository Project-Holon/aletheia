/*
 * unit: yes
 * function: func_021D8760, func_021D8788
 * address: 0x021D8760
 * packet: pkt_ov093_021D8760
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0740 0x021F0740 data ov093 a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021F0740[];
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021C8288(u8 *p);
void func_021D8760(int a,int b,int c) { if (c==func_021D775C(2)) { if (func_021C8288((u8 *)b)==2) func_021D7704(53,8192); } }
u8 *func_021D8788(u32 *p) { *p=1; return d_021F0740; }
