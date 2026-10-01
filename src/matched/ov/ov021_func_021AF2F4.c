/*
 * function: func_021AF2F4
 * address:  0x021AF2F4
 * packet:   pkt_ov021_021AF2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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
extern u32 func_02011330(u32 a);
extern u32 func_02029830(u32 a, u32 b);
extern void func_0215897C(u32 a, u32 b);

int func_021AF2F4(u32 a, u32 b)
{
    u32 y = func_0215A5DC(b);
    u32 x = func_0215A5F4(b);

    func_0215897C(x, func_02029830(y, func_02011330(a)));
    return 1;
}
