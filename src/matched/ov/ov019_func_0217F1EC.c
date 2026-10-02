/*
 * function: func_0217F1EC
 * address: 0x0217F1EC
 * packet: pkt_ov019_0217F1EC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021916E0 0x021916E0 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021916E0(u32 *p);
u32 func_0217F1EC(u8 *p)
{
    if (*(u32 **)(p + 0x280C) == 0 || *(u8 *)(p + 0x2828) == 0) return 1;
    return func_021916E0(*(u32 **)(p + 0x280C));
}
