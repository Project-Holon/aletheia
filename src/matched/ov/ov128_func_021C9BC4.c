/*
 * function: func_021C9BC4
 * address: 0x021C9BC4
 * packet: pkt_ov128_021C9BC4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
void func_021C9BC4(u32 p) { int i;void *q;for(i=0;i<10;i++) {q=*(void **)(p+296+i*8);func_020456F8(q);func_02041B6C(func_02045730(q));}}
