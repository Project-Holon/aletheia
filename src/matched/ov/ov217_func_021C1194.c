/*
 * function: func_021C1194
 * address:  0x021C1194
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
 *   func_021C18F8  0x021C18F8  thumb  ov217
 *   func_021C1A64  0x021C1A64  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C18F8();
extern void func_021C1A64(u32, u32);
u32 func_021C1194(u32 a0, u32 a1)
{
    func_021C1A64(a0, a1);
    return func_021C18F8(a0);
}

