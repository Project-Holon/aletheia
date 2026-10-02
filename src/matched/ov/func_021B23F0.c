/*
 * function: func_021B23F0
 * address:  0x021B23F0
 * packet:   pkt_021B23F0
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021F37A4  0x021F37A4  thumb  ov040
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0201210C(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4();
extern u32 func_021F37A4(u32);

int func_021B23F0(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4(b, b, c, d);
func_021F37A4(func_0201210C(func_0215A5DC((void *)b)));
return 0;
}

