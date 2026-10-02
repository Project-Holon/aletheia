/*
 * function: func_021E3F08
 * address:  0x021E3F08
 * packet:   pkt_ov119_021E3F08
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0203FB44(int, u16, u16);

void func_021E3F08(char *p)
{
    u32 v;

    v = *(u32 *)(p + 0x86C);
    if (v != 0)
        func_0203FB44(2, v, v >> 16);
    *(u32 *)(p + 0x86C) = 0;
}
