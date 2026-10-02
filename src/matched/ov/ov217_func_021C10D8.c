/*
 * function: func_021C10D8
 * address:  0x021C10D8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C1D74  0x021C1D74  thumb  ov217
 *   func_021C1DE8  0x021C1DE8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021C1D74(u32);
extern u32 func_021C1DE8();
u32 func_021C10D8(u32 a0)
{
    func_021C1D74(a0);
    return func_021C1DE8(a0);
}

