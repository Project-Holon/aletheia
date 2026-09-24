/*
 * function: func_021BF38C
 * address:  0x021BF38C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF810  0x021BF810  thumb  ov217
 *   func_021C0FF8  0x021C0FF8  thumb  ov217
 *
 * Argues func_021C0FF8() on a +0x360 value, selecting bit 1 from
 * func_021BF810().
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BF810();
extern u32 func_021C0FF8();
u32 func_021BF38C(u32 a0)
{
    if (func_021BF810() == 0) {
    return func_021C0FF8(*(u32*)(((u8*)a0) + 864), 1);
    }
    return func_021C0FF8(*(u32*)(((u8*)a0) + 864), 0);
}
