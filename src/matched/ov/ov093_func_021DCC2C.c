/*
 * unit: yes
 * function: func_021DCC2C,func_021DCC50
 * address: 0x021DCC2C
 * packet: pkt_ov093_021DCC2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0708 0x021F0708 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern unsigned char d_021F0708[];
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
void func_021DCC2C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) *d = func_021D76BC(32,-func_021D775C(32)); }
void *func_021DCC50(int *p) { *p = 1; return d_021F0708; }
