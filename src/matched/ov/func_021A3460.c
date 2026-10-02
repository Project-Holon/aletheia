/*
 * function: func_021A3460
 * address:  0x021A3460
 * packet:   pkt_021A3460
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
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A330C  0x021A330C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D5F8(void *);
extern void *func_021A3074();
extern u32 func_021A330C(u32, u32, u32, u32, u32);

int func_021A3460(u32 a, u32 b, u32 c, u32 d)
{
return func_021A330C(a, func_0216D5F8(func_021A3074(a, b, c, d)), b, c, d);
}

