/*
 * function: func_0219A780
 * address:  0x0219A780
 * packet:   pkt_0219A780
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D438(u32, u32);
extern u32 func_0216D5F8(u32, u32, u32, u32);
extern u32 func_02197E7C(u32, u32);

int func_0219A780(u32 a, u32 b, u32 c, u32 d)
{
func_0216D438(a, ((func_02197E7C(((func_0216D5F8(a, b, c, d) << 16) >> 16), 0) << 16) >> 16));
*(u8 *)((u8 *)(b) + 2) = 1;
return 1;
}

