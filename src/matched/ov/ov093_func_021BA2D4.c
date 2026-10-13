/*
 * function: BTL_MAIN_NotifyCapture
 * address: 0x021BA2D4
 * packet: pkt_ov093_021BA2D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_NotifyCapture 0x021BB8DC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_NotifyCapture(u8 *, u32 *);
void BTL_MAIN_NotifyCapture(u32 p, u32 *q) {
    u8 *v = *(u8 **)(p + 8);
    if (v) BTL_SERVER_NotifyCapture(v, q);
}
