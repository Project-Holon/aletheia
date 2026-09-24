/*
 * function: func_021B7068
 * address:  0x021B7068
 * packet:   pkt_021B7068
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
 *   func_0201EF40  0x0201EF40  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201EF40(u32, u32, u32, u32);

int func_021B7068(u32 a, u32 b, u32 c, u32 d)
{
func_0201EF40(a, 0, ((*(u32 *)((u8 *)(b)) << 16) >> 16), d);
return 8;
}

