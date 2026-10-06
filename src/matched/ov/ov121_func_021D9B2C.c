/*
 * function: func_021D9B2C
 * address: 0x021D9B2C
 * packet: pkt_ov121_021D9B2C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *
 * Setter: stores three words at +0x18, +0x1c and +0x20.
 */
typedef unsigned int u32;

void func_021D9B2C(char *p, u32 a, u32 b, int c)
{
    *(u32 *)(p + 0x18) = a;
    *(u32 *)(p + 0x1c) = b;
    *(u32 *)(p + 0x20) = c;
}
