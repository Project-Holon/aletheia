/*
 * function: func_021F4AA8
 * address: 0x021F4AA8
 * packet: pkt_ov112_021F4AA8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049030 0x02049030 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02049030(u32 a);
u16 func_021F4AA8(int i)
{
    u32 n = (u16)func_02049030(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}
