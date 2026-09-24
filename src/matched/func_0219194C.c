/*
 * function: func_0219194C
 * address:  0x0219194C
 * packet:   pkt_0219194C
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
 *   func_02045808  0x02045808  arm
 *   func_0219492C  0x0219492C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02045808(u32, u32, u32, u32);
extern u32 func_0219492C(u32, u32);

int func_0219194C(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(a)) != 0) {
    func_02045808(*(u32 *)((u8 *)(a)), b, c, d);
}
func_0219492C(*(u32 *)((u8 *)(a) + 12), *(u32 *)((u8 *)(a) + 8));
return func_020307B0(a);
}

