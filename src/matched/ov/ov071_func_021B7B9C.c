/*
 * function: func_021B7B9C
 * address: 0x021B7B9C
 * packet: pkt_ov071_021B7B9C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6B38 0x021B6B38 thumb ov071
 */

extern void func_021B6B38(void **p);
void func_021B7B9C(char *p) { int i; p += 0x2c; for (i=0;i<2;i++) func_021B6B38((void **)(p+i*16)); }
