/*
 * function: func_021D6FF8
 * address: 0x021D6FF8
 * packet: pkt_ov120_021D6FF8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

void func_021D6FF8(u8 *p, int state)
{
    *(int *)(p + 0x108) = state;
    if (state == 2) *(u32 *)(p + 0x10c) = *(u32 *)(p + 0x104) + 48;
    else if (state == 1) *(u32 *)(p + 0x10c) = *(u32 *)(p + 0x104) - 48;
}
