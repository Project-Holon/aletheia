/*
 * function: func_0216CF6C
 * address:  0x0216CF6C
 * packet:   pkt_ov010_0216CF6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D508  0x0216D508  thumb  ov010
 *   func_0216E180  0x0216E180  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DD1C(u32 x, u8 **o, int *n);
extern int func_0216D948(u32 x);
extern void func_0216D76C(u8 *o);
extern void func_0216D55C(u8 *o, u32 v);
extern void func_0216D508(u32 v);
extern void func_0216E180(u8 *o);

void func_0216CF6C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 2;

    n = 0;
    while (func_0216DD1C(x, &o, &n)) {
        if (func_0216D948(x) == 1)
            func_0216D76C(o);
        func_0216D55C(o, k);
        func_0216D508(*(u32 *)(o + 0x88));
        func_0216E180(o);
    }
}
