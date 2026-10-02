/*
 * function: func_021C2E4C
 * address: 0x021C2E4C
 * packet: pkt_ov093_021C2E4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021C2E4C(u8 *p)
{
    if (++*(u32 *)(p + 0x778) == 0)
        *(u32 *)(p + 0x778) = 1;
    return *(u32 *)(p + 0x778);
}
