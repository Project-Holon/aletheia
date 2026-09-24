/*
 * function: func_0219F01C
 * address:  0x0219F01C
 * packet:   pkt_0219F01C
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
 *   func_02158768  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02158768(u32, u32, u32, u32);

int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1)
{
return func_02158768(a, ((c << 16) >> 16), e1, *(u16 *)((u8 *)((u8 *)&e1) + 4));
}

