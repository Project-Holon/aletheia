/*
 * function: func_021B1CFC
 * address:  0x021B1CFC
 * packet:   pkt_021B1CFC
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
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02158F58(u32);
extern void *func_0215A5F4();
extern void *func_02188CB4(unsigned char *p);
extern u32 func_021A2F54(u32);

int func_021B1CFC(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A2F54(func_02188CB4(*(void **)((u8 *)(func_02158F58(func_0215A5F4(b, b, c, d))) + 4))) == 1) {
    return 1;
}
return 0;
}

