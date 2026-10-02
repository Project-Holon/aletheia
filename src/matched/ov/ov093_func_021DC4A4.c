/*
 * unit: yes
 * function: func_021DC4A4,func_021DC4C8
 * address: 0x021DC4A4
 * packet: pkt_ov093_021DC4A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F05F8 0x021F05F8 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern unsigned char d_021F05F8[];
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
void func_021DC4A4(int a, int b, int c) { if (c == func_021D775C(2) && func_021D775C(50) > 0) func_021D76BC(65,1); }
void *func_021DC4C8(int *p) { *p = 1; return d_021F05F8; }
