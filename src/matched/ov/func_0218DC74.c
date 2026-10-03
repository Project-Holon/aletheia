/*
 * function: func_0218DC74
 * address:  0x0218DC74
 * packet:   pkt_0218DC74
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
 *   func_02193B04  0x02193B04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_02193B04(u32 a, u32 b, u32 c, u32 d);

int func_0218DC74(u32 a, u32 b, u32 c)
{
return func_02193B04(*(u32 *)((u8 *)(a) + 108), b, c, *(u16 *)((u8 *)(a)));
}

