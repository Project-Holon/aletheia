/*
 * function: func_02191348
 * address:  0x02191348
 * packet:   pkt_ov021_02191348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02194990  0x02194990  thumb  ov021
 *   func_0219499C  0x0219499C  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02194990(u32, u32);
extern void func_0219499C(u32, u32, u32, u32);
extern u32 func_02193210(u32);
extern u32 func_02045770(u32);
extern void func_02043B5C(u32, u32);
extern u32 func_02045730(u32);
extern u32 func_020409B4(u32);

u32 func_02191348(u32 *a, u32 b)
{
    u32 x = func_02194990(a[2], *((u8 *)a + 1));
    func_02043B5C(func_02045770(x), 255);
    func_0219499C(a[2], *((u8 *)a + 1), b, func_02193210(a[5] + 0x160));
    return func_020409B4(func_02045730(x));
}
