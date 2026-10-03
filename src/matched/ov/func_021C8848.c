/*
 * function: func_021C8848
 * address:  0x021C8848
 * packet:   pkt_021C8848
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021666A4  0x021666A4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020120F4(u32);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012ED0(u32);
extern void *func_0215A5DC();
extern void func_021666A4(int a0);
extern u32 func_02188C80(void *);

int func_021C8848(u32 a, u32 b, u32 c, u32 d)
{
func_021666A4(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC(b, b, c, d))))));
return 0;
}

