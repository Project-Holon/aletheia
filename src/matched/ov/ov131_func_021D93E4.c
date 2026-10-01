/*
 * function: func_021D93E4
 * address: 0x021D93E4
 * packet: pkt_ov131_021D93E4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
u32 func_021D93E4(u8 *p, u32 target)
{
    u8 row;
    s8 delta;
    row = *(u32 *)(p + 0x14) / 24u;
    delta = target - (u8)(row % 10);
    if (delta < -2) delta += 10;
    if (delta > 8) delta -= 10;
    return (u8)(row + delta);
}
