/*
 * function: func_02177FC4
 * address: 0x02177FC4
 * packet: pkt_ov014_02177FC4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 *   func_021788FC 0x021788FC thumb ov014
 *   func_0217727C 0x0217727C thumb ov014
 *   func_02177F48 0x02177F48 thumb ov014
 */

extern unsigned char *g_021797A4;
extern int func_021788FC(void);
extern void func_0217727C(unsigned int *p, unsigned int v);
extern void func_02177F48(unsigned char *p);
void func_02177FC4(unsigned char *p) { p[0xCF2]--; if (p[0xCF2] == 0) { func_021788FC(); func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177F48); } }
