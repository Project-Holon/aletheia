/*
 * function: func_021A284C
 * address:  0x021A284C
 * packet:   pkt_021A284C
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
 *   func_021A29F4  0x021A29F4  thumb  ov021
 *   func_021A2994  0x021A2994  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A2994(u32);
extern void func_021A29F4(u16 *p, u32 a1, u32 a2, u32 a3);

int func_021A284C(u32 a, u32 b, u32 c, u32 d)
{
func_021A29F4((u16 *)(a + 40), b, c, d);
return func_021A2994((a + 40));
}

