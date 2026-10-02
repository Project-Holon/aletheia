/*
 * function: func_021D1F64
 * address:  0x021D1F64
 * packet:   pkt_021D1F64
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
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0201210C();
extern u32 func_0216D9E4(u32);
extern void *func_02188C7C(unsigned char *p);

int func_021D1F64(u32 a, u32 b, u32 c, u32 d)
{
return func_0216D9E4(func_02188C7C(func_0201210C(*(u32 *)((u8 *)(a) + 4), b, c, d)));
}

