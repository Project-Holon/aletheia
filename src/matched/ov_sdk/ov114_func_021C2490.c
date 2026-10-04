/*
 * function: func_021C2490
 * address:  0x021C2490
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0DA4  0x021C0DA4  arm  ov114
 *   func_021C2464  0x021C2464  arm  ov114
 *   func_021C2BB0  0x021C2BB0  arm  ov114
 *
 *
 * Flushes the object selected by `a`, then applies `b`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *func_021C0DA4(int);
extern void func_021C2BB0(u8 *);
extern void func_021C2464(u8 *p);

void func_021C2490(int a, int b)
{
    u8 *p = func_021C0DA4(a);
    if (p != 0)
        func_021C2BB0(p);
    func_021C2464((u8 *)b);
}
