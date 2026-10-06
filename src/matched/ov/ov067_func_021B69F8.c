/*
 * function: func_021B69F8
 * address: 0x021B69F8
 * packet: pkt_ov067_021B69F8
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned int u32;
typedef unsigned short u16;
u32 func_021B69F8(u32 p) {
    int r = 1;
    if (*(u32 *)(p+8) != *(u16 *)(p+42) && *(u32 *)(p+8) != *(u16 *)(p+44)) r = 0;
    return r;
}
