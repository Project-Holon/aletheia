/*
 * function: func_021860B8
 * address: 0x021860B8
 * packet: pkt_ov020_021860B8
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02161E78 0x02161E78 thumb ov010
 */
extern void func_02161E78(char *);
void func_021860B8(char *p) { int i; p += 0xf8; for (i=0;i<10;i++) func_02161E78(p+i*0x18); }
