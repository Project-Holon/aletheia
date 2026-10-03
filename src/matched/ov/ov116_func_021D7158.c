/*
 * function: func_021D7158
 * address: 0x021D7158
 * packet: pkt_ov116_021D7158
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
int func_021D7158(u8 *p)
{
    if (*(int *)p < 0) return 1;
    if (*(u32 *)(p + 4) != 0) return 1;
    if (*(u32 *)(p + 12) != 0) return 1;
    if (*(u16 *)(p + 8) != 0) return 1;
    return 0;
}
