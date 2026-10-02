/*
 * function: func_021BD93C
 * address:  0x021BD93C
 * packet:   pkt_021BD93C
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
 *   func_021A3098  0x021A3098  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_02188CB4();
extern u32 func_021A3098(u32);

int func_021BD93C(u32 a, u32 b, u32 c, u32 d)
{
return func_021A3098(func_02188CB4(*(u32 *)((u8 *)(*(u32 *)((u8 *)(a) + 8)) + 12), b, c, d));
}

