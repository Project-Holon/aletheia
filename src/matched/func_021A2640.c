/*
 * function: func_021A2640
 * address:  0x021A2640
 * packet:   pkt_021A2640
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
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B454  0x0204B454  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0204B454(u32, u32, u32);
extern u32 func_021A2C28(u32, u32, u32, u32);

int func_021A2640(u32 a, u32 b, u32 c, u32 d)
{
return func_0204B454(func_021A2C28(a, b, c, d), b, 0);
}

