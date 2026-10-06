/*
 * function: func_0219EF04
 * address:  0x0219EF04
 * packet:   pkt_0219EF04
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219EA94  0x0219EA94  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D69C(void *p);
extern u32 func_0219EA94(u32, u32);

int func_0219EF04(u32 a, u32 b, u32 c, u32 d)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}

