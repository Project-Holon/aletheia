/*
 * function: func_021D6CCC
 * address: 0x021D6CCC
 * packet: pkt_ov120_021D6CCC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02042FB0 0x02042FB0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
void func_021D6CCC(u8 *p, int n)
{
    u8 *q = *(u8 **)(p + 0x11c) + 0xc;
    int base = (u16)*(unsigned int *)p;
    int off;
    int x, y;
    y = 0;
    off = 6 * n;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++)
            func_02042FB0(4, x, y + off, *(u16 *)(q + 0x3e) + base);
}
