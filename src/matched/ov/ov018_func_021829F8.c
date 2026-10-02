/*
 * function: func_021829F8
 * address: 0x021829F8
 * packet: pkt_ov018_021829F8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02183A14 0x02183A14 data a2
 *   func_021828B8 0x021828B8 thumb ov018
 */

extern unsigned short d_02183A14[];
extern void func_021828B8(void *, void *, unsigned short *);
void func_021829F8(void *a, void *b) { func_021828B8(a,b,d_02183A14); }
