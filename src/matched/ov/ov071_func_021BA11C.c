/*
 * function: func_021BA11C
 * address: 0x021BA11C
 * packet: pkt_ov071_021BA11C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 */

extern void func_02041EE4(unsigned, unsigned, unsigned);
void func_021BA11C(char *p) { func_02041EE4(6, 3, (*(int *)(p + 0x2d8) >> 8) % 64); }
