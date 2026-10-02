/*
 * function: func_021BB49C
 * address: 0x021BB49C
 * packet: pkt_ov072_021BB49C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
extern void func_020456F8(void *p);
extern u8 func_02045730(void *p);
extern void func_02041B6C(unsigned int v);
void func_021BB49C(void **p) { void *q = *p; func_020456F8(q); func_02041B6C(func_02045730(q)); }
