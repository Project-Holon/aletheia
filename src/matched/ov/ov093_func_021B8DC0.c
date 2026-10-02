/*
 * function: func_021B8DC0
 * address: 0x021B8DC0
 * packet: pkt_ov093_021B8DC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B8E70 0x021B8E70 thumb ov093
 */
extern int func_021B8D8C(void *,void *,unsigned int);
extern unsigned char func_021B8E70(unsigned char *,unsigned int);
unsigned char func_021B8DC0(unsigned char *p,void *a,unsigned int b) { int k=func_021B8D8C(p,a,b); if(k!=6) return func_021B8E70(p,k); return 255; }
