/*
 * function: func_021B8BF4
 * address: 0x021B8BF4
 * packet: pkt_ov071_021B8BF4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */

struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021B8BF4(void **p) { int i; for (i=0;i<6;i++) func_020452E8(p[i]); }
