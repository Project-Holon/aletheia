/*
 * function: func_021B9A64
 * address:  0x021B9A64
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Allocates and zeroes an a*b byte scratch block from tag 0xb9.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u8 *func_02030734(int, int, int, int, int);
extern void func_02082BCC(int, int, int);

u8 *func_021B9A64(int a, int b, int c)
{
    int n = b * a;
    u8 *p = func_02030734(c, n, 0, 0x021CE3A0, 0xb9);

    func_02082BCC((int)p, 0, n);
    return p;
}
