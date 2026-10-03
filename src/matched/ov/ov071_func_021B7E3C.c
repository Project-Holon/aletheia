/*
 * function: func_021B7E3C
 * address: 0x021B7E3C
 * packet: pkt_ov071_021B7E3C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6F40 0x021B6F40 thumb ov071
 *   func_021B6FE0 0x021B6FE0 thumb ov071
 */

typedef unsigned char  u8;
extern void *func_021B6F40(u8 **p);
extern void func_021B6FE0(void *,unsigned char *,int);
void func_021B7E3C(void **a,void *p) { int i; unsigned char *t; t=func_021B6F40(p); for(i=0;i<6;i++) func_021B6FE0(a[i+3],t,i); }
