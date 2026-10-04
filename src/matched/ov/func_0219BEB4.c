/*
 * function: func_0219BEB4
 * address:  0x0219BEB4
 * packet:   pkt_0219BEB4
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021D046C  0x021D046C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D534(void *p);
extern void *func_0216D67C(void *a0);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021D046C(u32, u32, u32);

int func_0219BEB4(u32 a, u32 b)
{
return func_021D046C(func_02188CD0((u8 *)func_0216D534(func_0216D67C((void *)a))), a, b);
}

