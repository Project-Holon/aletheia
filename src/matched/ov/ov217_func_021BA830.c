/*
 * function: func_021BA830
 * address:  0x021BA830
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA830  0x021BA830  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_020414EC();
u32 func_021BA830(void)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}

