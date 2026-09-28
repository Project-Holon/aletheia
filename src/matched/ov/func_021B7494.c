/*
 * function: func_021B7494
 * address:  0x021B7494
 * packet:   pkt_021B7494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201ED04(u32);
extern u32 func_020307B0(u32);
extern u32 func_020409B4(u32);
extern u32 func_02045808(u32);
extern u32 func_02045C04(u32);
extern u32 func_02190728(u32);
extern u32 func_02190788(u32, u32, u32, u32);

int func_021B7494(u32 a, u32 b, u32 c, u32 d)
{
func_02190788(*(u32 *)((u8 *)(a) + 12), b, c, d);
func_02190728(*(u32 *)((u8 *)(a) + 12));
func_020409B4(1);
func_02045808(*(u32 *)((u8 *)(a) + 24));
func_02045808(*(u32 *)((u8 *)(a) + 28));
func_0201ED04(*(u32 *)((u8 *)(a) + 20));
func_02045C04(*(u32 *)((u8 *)(a) + 8));
return func_020307B0(a);
}

