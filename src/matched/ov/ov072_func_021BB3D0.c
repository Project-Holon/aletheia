/*
 * function: func_021BB3D0
 * address: 0x021BB3D0
 * packet: pkt_ov072_021BB3D0
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
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int v);
void func_021BB3D0(void **p) { void *q = *p; func_020456F8(q); func_02041B6C(func_02045730(q)); }
