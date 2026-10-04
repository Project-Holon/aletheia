/*
 * function: func_021BA2D4
 * address: 0x021BA2D4
 * packet: pkt_ov093_021BA2D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB8DC 0x021BB8DC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BB8DC(u8 *, u32 *);
void func_021BA2D4(u32 p, u32 *q) {
    u8 *v = *(u8 **)(p + 8);
    if (v) func_021BB8DC(v, q);
}
