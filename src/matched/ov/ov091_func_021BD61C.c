/*
 * function: func_021BD61C
 * address: 0x021BD61C
 * packet: pkt_ov091_021BD61C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
extern void func_020452E8(struct Descriptor *);
void func_021BD61C(char *p) { func_020452E8(*(struct Descriptor **)(p+0x1FC)); func_020452E8(*(struct Descriptor **)(p+0x200)); }
