/*
 * function: func_021A282C
 * address:  0x021A282C
 * packet:   pkt_021A282C
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
 *   func_021A2978  0x021A2978  thumb  ov021
 *   func_021A29A8  0x021A29A8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A2978(u32, u32, u32, u32);
extern u32 func_021A29A8(u32, u32, u32);

int func_021A282C(u32 a, u32 b, u32 c, u32 d)
{
func_021A2978((a + 40), *(u32 *)((u8 *)(a) + 32), b, d);
return func_021A29A8((a + 40), *(u32 *)((u8 *)(a) + 32), b);
}

