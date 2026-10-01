/*
 * function: func_021AEC84
 * address:  0x021AEC84
 * packet:   pkt_ov021_021AEC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_0201210C(u32 a);
extern u32 func_021BE92C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0215897C(u32 a, u32 b);

int func_021AEC84(u32 a, u32 b)
{
    u32 x = func_0215A5F4(b);
    u32 y = func_0215A5DC(b);

    func_0215897C(x, func_021BE92C(y, func_0201210C(y), 0, 0, 1, 0, 0));
    return 1;
}
