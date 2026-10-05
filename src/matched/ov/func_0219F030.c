/*
 * function: func_0219F030
 * address:  0x0219F030
 * packet:   pkt_0219F030
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
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D568(u32, u32);
extern u32 func_0216DAC8(u32, u32, u32, u32);

int func_0219F030(u32 a, u32 b, u32 c, u32 d)
{
func_0216DAC8(a, 1, c, d);
return func_0216D568(a, (1 << 15));
}

