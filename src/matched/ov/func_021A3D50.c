/*
 * function: func_021A3D50
 * address:  0x021A3D50
 * packet:   pkt_021A3D50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A3D08  0x021A3D08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A3190(u32, u32);
extern u32 func_021A398C(u32);
extern u32 func_021A3D08(u32, u32);

int func_021A3D50(u32 a, u32 b)
{
return func_021A3D08(a, func_021A3190(func_021A398C(a), b));
}

