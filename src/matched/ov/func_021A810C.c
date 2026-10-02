/*
 * function: func_021A810C
 * address:  0x021A810C
 * packet:   pkt_021A810C
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_02188CB4();
extern u32 func_021A3038(u32, u32);

int func_021A810C(u32 a, u32 b, u32 c, u32 d)
{
return func_021A3038(func_02188CB4(a, b, c, d), b);
}

