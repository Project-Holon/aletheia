/*
 * function: BTL_CLIENT_SetRequestParam
 * address: 0x021CD960
 * packet: pkt_ov093_021CD960
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;

void BTL_CLIENT_SetRequestParam(u8 *p, u32 v) {
    *(u32 *)(p + 0xA0) = v;
    p[0x1B2] |= 8;
}
