/*
 * function: func_02194A24
 * address:  0x02194A24
 * packet:   pkt_02194A24
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
 *   func_02195E54  0x02195E54  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02195E54(u32, u32, u32, u32);

int func_02194A24(u32 a, u32 b, u32 c, u32 d)
{
return func_02195E54(a, b, ((c << 24) >> 24), 0);
}

