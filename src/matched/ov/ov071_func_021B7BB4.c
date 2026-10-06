/*
 * function: func_021B7BB4
 * address: 0x021B7BB4
 * packet: pkt_ov071_021B7BB4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B6C7C 0x021B6C7C thumb ov071
 *   func_021B6B70 0x021B6B70 thumb ov071
 */

typedef unsigned char  u8;
extern void func_021B6C7C(int *p, int idx);
extern int func_021B6B70(void **p, u8 *q);
void func_021B7BB4(int *a,char *p) { int i; func_021B6C7C(a,3); p+=0x2c; for(i=0;i<2;i++) func_021B6B70((void **)a[1],(u8 *)(p+i*16)); }
