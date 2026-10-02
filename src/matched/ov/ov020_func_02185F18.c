/*
 * function: func_02185F18
 * address: 0x02185F18
 * packet: pkt_ov020_02185F18
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201284C 0x0201284C thumb
 *   func_02013FEC 0x02013FEC thumb
 *   func_02012894 0x02012894 thumb
 */
typedef struct { int f[7]; } S7;
extern unsigned short *func_0201284C(void *);
extern int func_02013FEC(unsigned short);
extern S7 *func_02012894(void *);
void func_02185F18(void *p,S7 *out) { if (func_02013FEC(func_0201284C(p)[2])) *out=*func_02012894(p); }
