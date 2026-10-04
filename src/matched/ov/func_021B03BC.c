/*
 * function: func_021B03BC
 * address:  0x021B03BC
 * packet:   pkt_021B03BC
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
 *   func_021B01B8  0x021B01B8  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0215897C(void *vm, void *task);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4();
extern u32 func_021B01B8(u32 a, u32 x, u32 y);

int func_021B03BC(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4(b, b, c, d), (void *)func_021B01B8((u32)func_0215A5DC((void *)b), b, 0));
return 1;
}

