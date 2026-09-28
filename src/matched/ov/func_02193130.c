/*
 * function: func_02193130
 * address:  0x02193130
 * packet:   pkt_02193130
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
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201F7A8(u32, u32, u32, u32);
extern u32 func_020452E8(u32);

int func_02193130(u32 a, u32 b, u32 c, u32 d)
{
func_0201F7A8(a, 0, c, d);
return func_020452E8(a);
}

