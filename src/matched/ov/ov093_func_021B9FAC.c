/*
 * function: func_021B9FAC
 * address: 0x021B9FAC
 * packet: pkt_ov093_021B9FAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 func_021B9FAC(u8 *p, int i, u32 *out) {
    u32 q = (u32)p + (u32)i * 40;
    *out = *(u16 *)(q + 40);
    return *(u32 *)(q + 36);
}
