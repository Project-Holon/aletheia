/*
 * function: func_021B2874
 * address:  0x021B2874
 * packet:   pkt_021B2874
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
 *   func_02189A24  0x02189A24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02189A24(u8 *p);

int func_021B2874(u32 a, u32 b, u32 c, u32 d)
{
if (func_02189A24(func_0201210C(func_0215A5DC((void *)b))) != 1) {
    return 1;
}
return 0;
}

