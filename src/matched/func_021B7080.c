/*
 * function: func_021B7080
 * address:  0x021B7080
 * packet:   pkt_021B7080
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
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF18  0x0200BF18  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0200BE48(u32);
extern u32 func_0200BF18(u32, u32);
extern u32 func_02012EBC(u32, u32, u32, u32);

int func_021B7080(u32 a, u32 b, u32 c, u32 d)
{
return func_0200BF18(func_0200BE48(func_02012EBC(b, b, c, d)), *(u32 *)((u8 *)(c)));
}

