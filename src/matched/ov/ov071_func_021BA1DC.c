/*
 * function: func_021BA1DC
 * address: 0x021BA1DC
 * packet: pkt_ov071_021BA1DC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */

typedef unsigned char u8;
int func_021BA1DC(char *p, unsigned a) { int x = ((*(int *)(p + 0x2d8) >> 8) + a) >> 5; if (x >= *(u8 *)(p + 0x27c)) x = 0xffff; return x; }
