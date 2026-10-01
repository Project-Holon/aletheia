/*
 * function: func_021D9440
 * address: 0x021D9440
 * packet: pkt_ov131_021D9440
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
typedef signed short s16;
typedef unsigned int u32;
s16 func_021D9440(u8 *p, u32 target)
{
    u32 position;
    u8 row, remainder;
    s8 delta;
    position = *(u32 *)(p + 0x14);
    row = position / 24u;
    remainder = position % 24u;
    delta = target - (u8)(row % 10);
    if (delta < -2) delta += 10;
    if (delta > 8 && row > 6) delta -= 10;
    return delta * 24 + 8 - remainder;
}
