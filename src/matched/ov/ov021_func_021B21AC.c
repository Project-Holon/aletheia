/*
 * function: func_021B21AC
 * address:  0x021B21AC
 * packet:   pkt_ov021_021B21AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B8484  0x021B8484  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5EC(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_0216DE94(u32, u32);
extern u32 func_0219E348(u32);
extern void func_021B8484(u32, u32, u32, u32);
extern void func_021B7DC0(u32, void *);
extern void func_0219E2C0(u32, void *);

int func_021B21AC(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = func_0216DE94(func_0215A5EC(b), func_02159B10(a, b));
    x = func_02159B10(a, b);
    y = func_02159B10(a, b);
    z = func_02159B10(a, b);
    o = func_0219E348(h);
    func_021B8484(o, x, y, z);
    func_021B7DC0(o, buf);
    func_0219E2C0(h, buf);
    return 0;
}
