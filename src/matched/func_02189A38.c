/*
 * function: func_02189A38
 * address:  0x02189A38
 * packet:   pkt_02189A38
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
 *   func_02012984  0x02012984  thumb
 *   func_020113D8  0x020113D8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020113D8(u32);
extern u32 func_02012984(u32, u32, u32, u32);

int func_02189A38(u32 a, u32 b, u32 c, u32 d)
{
return func_020113D8(func_02012984(*(u32 *)((u8 *)(a) + 8), b, c, d));
}

