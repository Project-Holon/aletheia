/*
 * function: func_021D7260
 * address: 0x021D7260
 * packet: pkt_ov116_021D7260
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
void func_021D7260(u8 *p)
{
    (*(s16 *)(p + 10))++;
    if (*(s16 *)(p + 10) == 3600) *(u16 *)(p + 8) = 1;
}
