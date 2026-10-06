/*
 * function: func_021A80FC
 * address:  0x021A80FC
 * packet:   pkt_021A80FC
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
 *   func_021A3050  0x021A3050  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_02188CB4(u8 *p);
extern u16 func_021A3050(u8 *p);

int func_021A80FC(u32 a, u32 b, u32 c, u32 d)
{
return (((u32)func_021A3050(func_02188CB4((u8 *)a)) << 24) >> 24);
}

