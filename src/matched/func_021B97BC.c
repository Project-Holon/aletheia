/*
 * function: func_021B97BC
 * address:  0x021B97BC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B08  0x021B9B08  thumb  ov217
 *   func_021B9B80  0x021B9B80  thumb  ov217
 *   func_021B9B90  0x021B9B90  thumb  ov217
 *
 * Reports the body state of the +0x10 handle: 1 when func_021B9B80() is
 * idle, else the func_021B9B90() code mapped to 2/3/4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021B9B08();
extern u32 func_021B9B80();
extern u32 func_021B9B90();
u32 func_021B97BC(u8 *a0)
{
    func_021B9B08(*(u32*)(a0 + 16));
    if (func_021B9B80(*(u32*)(a0 + 16)) != 0) {
    switch (func_021B9B90(*(u32*)(a0 + 16))) {
    case 0:
    return 2;
    case 1:
    return 3;
    case 2:
    return 4;
    }
    return 4;
    }
    return 1;
}
