/*
 * function: func_021C1AC0
 * address:  0x021C1AC0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C1A84  0x021C1A84  thumb  ov217
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C1A84();
extern void func_021C1AB4();
void func_021C1AC0(u32 a0)
{
    func_021C1AB4(a0 + 0 + 0, func_021C1A84() + 0);
}

