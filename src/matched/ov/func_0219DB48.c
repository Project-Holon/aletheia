/*
 * function: func_0219DB48
 * address:  0x0219DB48
 * packet:   pkt_0219DB48
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
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_021AC578  0x021AC578  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0219DC08(u32, u32, u32, u32);
extern u32 func_021AC578(u32, u32);

int func_0219DB48(u32 a, u32 b, u32 c, u32 d)
{
return func_021AC578(a, func_0219DC08(a, b, c, d));
}

