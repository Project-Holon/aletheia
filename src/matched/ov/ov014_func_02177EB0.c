/*
 * unit: yes
 * function: func_02177EB0, func_02177ED4, func_02177ED8
 * address: 0x02177EB0
 * packet: pkt_ov014_02177EB0
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 *   func_02179570 0x02179570 thumb ov014
 *   func_0217727C 0x0217727C thumb ov014
 *   func_02177E9C 0x02177E9C thumb ov014
 */

extern unsigned char *g_021797A4;
extern int func_02179570(int a);
extern void func_0217727C(unsigned int *p, unsigned int v);
extern void func_02177E9C(void);
int func_02177EB0(int a) { if (func_02179570(a) != 0) { func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177E9C); return 1; } return 0; }
int func_02177ED4(void) { return 1; }
int func_02177ED8(void) { return 0; }
