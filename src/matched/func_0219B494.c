/*
 * function: func_0219B494
 * address:  0x0219B494
 * packet:   pkt_0219B494
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
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D804(u32);
extern u32 func_0216D81C(u32);
extern u32 func_0216D83C(u32, u32, u32, u32);
extern u32 func_0216D86C(u32);

int func_0219B494(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D83C(a, b, c, d) != func_0216D804(a)) {
    return 1;
}
if (func_0216D86C(a) != func_0216D81C(a)) {
    return 1;
}
return 0;
}

