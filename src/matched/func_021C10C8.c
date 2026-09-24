/*
 * function: func_021C10C8
 * address:  0x021C10C8
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
 *   func_021C1D64  0x021C1D64  thumb  ov217
 *   func_021C1DBC  0x021C1DBC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C1D64();
extern u32 func_021C1DBC();
u32 func_021C10C8(void)
{
    u32 v4 = func_021C1DBC();
    func_021C1D64();
    return v4;
}

