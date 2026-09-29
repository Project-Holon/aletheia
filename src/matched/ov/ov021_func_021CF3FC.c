/*
 * function: func_021CF3FC
 * address:  0x021CF3FC
 * packet:   pkt_ov021_021CF3FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0203D4D0 with 0x2707 on the handle of func_0203996C(0xff) when c == 1,
 * otherwise on the handle of func_020399A8().
 *
 * symbols:
 *   func_0203996C  0x0203996C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_021CF128  0x021CF128  thumb  ov021
 *   func_0203D4D0  0x0203D4D0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0203996C(u32 a);
extern u32 func_020399A8(void);
extern u32 func_021CF128(void);
extern void func_0203D4D0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void func_021CF3FC(u32 a, u32 b, int c)
{
    u32 h;

    if (c == 1) {
        h = func_0203996C(0xff);
        func_0203D4D0(h, b, 0x2707, func_021CF128(), a, 0, 0, 1);
    } else {
        h = func_020399A8();
        func_0203D4D0(h, b, 0x2707, func_021CF128(), a, 0, 0, 1);
    }
}
