/*
 * function: func_021C19B4
 * address:  0x021C19B4
 * packet:   pkt_ov021_021C19B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 func_021A572C(u32 a);
extern u32 func_0216D67C(u32 a);
extern int func_0216D83C(u32 a);
extern int func_021641E8(int a);
extern int func_0216D86C(u32 a);
extern int func_021641F8(int a);
extern u32 func_0216D8AC(u32 a);
extern u32 func_0216DDDC(u32 a, s16 x, s16 y, u32 d, u32 e, u32 f);

u32 func_021C19B4(u32 a, u32 b)
{
    u32 r6;
    u32 h;
    int x;
    int y;

    r6 = func_021A572C(a);
    h = func_0216D67C(r6);
    x = func_0216D83C(r6);
    x += func_021641E8(b);
    y = func_0216D86C(r6);
    y += func_021641F8(b);
    return func_0216DDDC(h, x, y, func_0216D8AC(r6), 1, 0);
}
