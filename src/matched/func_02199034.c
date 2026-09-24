/*
 * function: func_02199034
 * address:  0x02199034
 * packet:   pkt_02199034
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D674(u32, u32);
extern u32 func_0216D6BC(u32, u32, u32, u32);

int func_02199034(u32 a, u32 b, u32 c, u32 d)
{
*(u16 *)((u8 *)(func_0216D6BC(a, 4, c, d)) + 2) = c;
return func_0216D674(a, b);
}

