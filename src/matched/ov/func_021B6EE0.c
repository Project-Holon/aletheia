/*
 * function: func_021B6EE0
 * address:  0x021B6EE0
 * packet:   pkt_021B6EE0
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
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02157E9C  0x02157E9C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct GiftMon;
extern void *func_02157E9C(const struct GiftMon *g, int heap, void *save);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5E4(void *a0);

int func_021B6EE0(u32 a, u32 b)
{
return (int)func_02157E9C((const struct GiftMon *)b, func_0215A5CC((void *)a), func_0215A5E4((void *)a));
}

