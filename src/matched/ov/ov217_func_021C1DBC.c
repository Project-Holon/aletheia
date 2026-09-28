/*
 * function: func_021C1DBC
 * address:  0x021C1DBC
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
 *   func_021C1D7C  0x021C1D7C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02030734();
extern u32 func_021C1D7C();
u32 func_021C1DBC(u32 a0)
{
    u32 v1 = func_02030734(a0, 4044, 0, 0x21C4064, 1588);
    func_021C1D7C(v1, a0);
    return v1;
}

