/*
 * function: func_021D6B30
 * address: 0x021D6B30
 * packet: pkt_ov116_021D6B30
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200DF10 0x0200DF10 thumb
 */
typedef unsigned char  u8;
struct RecSlot;
extern void func_0200DF10(struct RecSlot *p, const void *src, u8 a, u8 b);
void func_021D6B30(unsigned char *a,void *b) { func_0200DF10(b,a+0x69e,*(unsigned short *)(a+8),*(unsigned short *)(a+10)); }
