/*
 * function: func_021BE820
 * address:  0x021BE820
 * packet:   pkt_021BE820
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02045770(u32);
extern void func_02043B5C(u32, u32);
extern void func_02045334(u32);

void func_021BE820(u8 *p)
{
    func_02043B5C(func_02045770(*(u32 *)(p + 0x154)), 0);
    func_02045334(*(u32 *)(p + 0x154));
}

