/*
 * function: func_021A596C
 * address:  0x021A596C
 * packet:   pkt_ov021_021A596C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A6BB4  0x021A6BB4  thumb  ov021
 *   func_021A682C  0x021A682C  thumb  ov021
 *   func_021A5A68  0x021A5A68  thumb  ov021
 *   func_021A5B4C  0x021A5B4C  thumb  ov021
 *   func_021A5AD4  0x021A5AD4  thumb  ov021
 *   func_021A5B7C  0x021A5B7C  thumb  ov021
 *   func_021A6C30  0x021A6C30  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32  func_021A3AB8(u32 a, u32 v);
extern void func_021A3CC0(u32 a);
extern void func_021A6BB4(u8 *p, u32 a1, u32 a2);
extern u32  func_021A682C(u8 *p, u32 a1, u32 a2);
extern int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021A5B4C(u8 *p, u32 a, u32 b);
extern void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5B7C(u8 *p);
extern void func_021A6C30(u8 *p);

void func_021A596C(u8 *p, u32 b, u32 c)
{
    u32 t;
    u32 x;
    u32 y;

    t = func_021A3AB8(*(u32 *)(p + 0x14), c);
    func_021A3CC0(*(u32 *)(p + 0x14));
    func_021A6BB4(p + 0xc, t, *(u32 *)(p + 0x1c));
    x = func_021A682C(p, t, 0);
    y = func_021A5A68(p, x, b, c, 0);
    func_021A5B4C(p, c, y);
    func_021A5AD4(p, y, x, b, c, 0);
    func_021A5B7C(p);
    func_021A6C30(p + 0xc);
}
