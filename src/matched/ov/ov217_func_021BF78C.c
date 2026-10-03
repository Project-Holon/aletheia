/*
 * function: func_021BF78C
 * address:  0x021BF78C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C11F4  0x021C11F4  thumb  ov217
 *
 * Gate on four handles at +0x2BC..+0x2C8: 1 only when all four report idle.
 * The `||` chain is what produces the image's inverted last test.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int func_021C11F4(u8 *p);
u32 func_021BF78C(u32 a0)
{
    if (func_021C11F4(*(u8 **)(((u8*)a0) + 700)) != 0 || func_021C11F4(*(u8 **)(((u8*)a0) + 704)) != 0 || func_021C11F4(*(u8 **)(((u8*)a0) + 708)) != 0 || func_021C11F4(*(u8 **)(((u8*)a0) + 712)) != 0) {
    return 0;
    }
    return 1;
}
