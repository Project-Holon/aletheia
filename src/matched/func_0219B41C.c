/*
 * function: func_0219B41C
 * address:  0x0219B41C
 * packet:   pkt_0219B41C
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
 *   func_0219B45C  0x0219B45C  thumb  ov021
 *   func_0219B478  0x0219B478  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0219B45C(u32, u32, u32, u32);
extern u32 func_0219B478(u32);

int func_0219B41C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0219B45C(a, b, c, d) == 0) {
    return 0;
}
if (func_0219B478(a) != 0) {
    return 1;
}
return 0;
}

