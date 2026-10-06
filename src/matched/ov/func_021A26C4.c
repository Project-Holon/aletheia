/*
 * function: func_021A26C4
 * address:  0x021A26C4
 * packet:   pkt_021A26C4
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
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B404  0x0204B404  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0204B404(u32, u32, u32);
extern u32 func_021A2C28(u8 *p);

int func_021A26C4(u32 a, u32 b)
{
return func_0204B404(func_021A2C28((u8 *)a), b, 0);
}

