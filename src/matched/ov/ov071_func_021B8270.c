/*
 * function: func_021B8270
 * address: 0x021B8270
 * packet: pkt_ov071_021B8270
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6B38 0x021B6B38 thumb ov071
 *   d_021BA978 0x021BA978 data a4
 */

extern unsigned d_021BA978[];
extern void func_021B6B38(void **p);
void func_021B8270(unsigned char *p) { unsigned i; for(i=0;i<d_021BA978[p[0x32]];i++) func_021B6B38((void **)(p+i*16)); }
