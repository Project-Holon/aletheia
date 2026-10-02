/*
 * unit: yes
 * function: func_021DC664,func_021DC694
 * address: 0x021DC664
 * packet: pkt_ov093_021DC664
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0628 0x021F0628 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern unsigned char d_021F0628[];
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
void func_021DC664(int a, int b, int c) { if (c == func_021D775C(4) && func_021D775C(26) == 0 && (unsigned int)func_021D775C(43) > 50) func_021D76BC(43,50); }
void *func_021DC694(int *p) { *p = 1; return d_021F0628; }
