/*
 * function: func_021F05E8
 * address:  0x021F05E8
 * packet:   pkt_ov032_021F05E8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0DF4  0x021F0DF4  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F0DF4(u32 h, u8 v);

void func_021F05E8(u8 *p, int a, u32 b)
{
    u8 m;

    if (a == 4)
        m = 0xf;
    else
        m = 1 << a;
    if ((1 & m) && *(int *)(p + 0x28) != 0x30)
        func_021F0DF4(*(u32 *)(p + 0x2bc), b + 1);
    if (2 & m)
        func_021F0DF4(*(u32 *)(p + 0x2c0), b + 4);
    if ((4 & m) && p[0x7b] != 0)
        func_021F0DF4(*(u32 *)(p + 0x2c4), b + 7);
    if (8 & m)
        func_021F0DF4(*(u32 *)(p + 0x2c8), b + 10);
}
