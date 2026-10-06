/*
 * function: func_021B1424
 * address:  0x021B1424
 * packet:   pkt_021B1424
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
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021926D8  0x021926D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0215A61C(int a0);
struct U;
extern int func_021926D8(struct U *u);

int func_021B1424(int a, int b, int c, int d)
{
if (func_021926D8((struct U *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}

