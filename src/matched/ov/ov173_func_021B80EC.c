/*
 * function: func_021B80EC
 * address: 0x021B80EC
 * packet: pkt_ov173_021B80EC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202822C 0x0202822C thumb
 */
extern void func_0202822C(char *,int);
int func_021B80EC(char *p,unsigned short id) {unsigned short *q=(unsigned short *)(p+0x1d0);q[5]=1;q[3]=1;q[4]=id;func_0202822C(*(char **)((unsigned)p+q[3]*4+0x220),1);return 13;}
