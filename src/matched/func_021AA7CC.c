/*
 * function: func_021AA7CC
 * address:  0x021AA7CC
 * packet:   pkt_021AA7CC
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
 *   func_021AAB54  0x021AAB54  thumb  ov021
 *   func_021AAFFC  0x021AAFFC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021AAB54(u32, u32, u32, u32);
extern u32 func_021AAFFC(u32);

int func_021AA7CC(u32 a, u32 b, u32 c, u32 d)
{
func_021AAB54(a, b, c, d);
return func_021AAFFC(b);
}

