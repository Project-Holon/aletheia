/*
 * function: func_021A712C
 * address:  0x021A712C
 * packet:   pkt_ov021_021A712C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219F058  0x0219F058  thumb  ov021
 *   func_021A3674  0x021A3674  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A7258  0x021A7258  thumb  ov021
 *   func_021A35BC  0x021A35BC  thumb  ov021
 *   func_021A35F0  0x021A35F0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3074(u32 a);
extern void func_0219F058(u32 a, u16 *b, u16 *c);
extern void func_021A3674(u32 a, u32 b, u32 c);
extern u32 func_0216D5F8(u32 a);
extern void func_021A7258(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32 func_021A35BC(u32 a);
extern void func_021A35F0(u32 a, u32 b, u32 c, u32 d);

void func_021A712C(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    u16 v[2];
    u32 h;
    u32 fl;
    fl = 0;
    h = func_021A3074(b[1]);
    func_0219F058(h, &v[0], &v[1]);
    func_021A3674(b[1], 0, 0);
    if (d == 0)
        c = func_0216D5F8(h);
    func_021A7258(a, b, 0, e, c, v[0], v[1]);
    if (func_021A35BC(b[1]) == 1)
        fl |= 1;
    func_021A35F0(b[1], f, g, fl);
}
