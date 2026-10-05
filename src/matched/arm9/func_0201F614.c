/*
 * function: func_0201F614
 * address:  0x0201F614
 * packet:   pkt_0201F614
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0203FB44(int, u16, u16);

void func_0201F614(int a, u32 x)
{
    func_0203FB44(a, x, x >> 16);
}
