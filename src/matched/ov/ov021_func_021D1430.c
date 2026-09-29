/*
 * function: func_021D1430
 * address:  0x021D1430
 * packet:   pkt_ov021_021D1430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045768  0x02045768  arm
 *   func_02045770  0x02045770  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_02040B1C  0x02040B1C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02045768(u32 a);
extern u32 func_02045770(u32 a);
extern void func_020439A0(u32 a, u32 b, u32 c, u32 d, u16 e, u16 f, u32 g, u32 h, u32 i);
extern u32 func_020437D4(u32 a);
extern u32 func_020437EC(u32 a);
extern void func_02040B1C(u32 a, u32 b, u32 c, u32 d);

void func_021D1430(u8 *p, u32 n)
{
    u32 a = func_02045768(*(u32 *)(p + 4));
    u32 b = func_02045770(*(u32 *)(p + 4));
    u32 x;
    u32 y;

    func_020439A0(*(u32 *)(p + 0x10), b, 0, n << 5, *(u16 *)(p + 8), *(u16 *)(p + 10), 0x20, 0x20, 0xFFFF);
    x = func_020437D4(b);
    y = func_020437EC(b);
    func_02040B1C(3, x, y, a);
}
