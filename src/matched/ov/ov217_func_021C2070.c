/*
 * function: func_021C2070
 * address:  0x021C2070
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
 *   func_021C2550  0x021C2550  thumb  ov217
 *   func_021C256C  0x021C256C  thumb  ov217
 *   func_021C25B0  0x021C25B0  thumb  ov217
 *   func_021C25D0  0x021C25D0  thumb  ov217
 *   func_021C2630  0x021C2630  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C2550(u32 a0);
extern u32 func_021C256C();
extern u32 func_021C25B0();
extern u32 func_021C25D0();
extern u32 func_021C2630();
u32 func_021C2070(u32 a0, u32 a1)
{
    u32 v1 = func_021C2550(a0);
    func_021C256C(v1, a0);
    func_021C2630(v1, a1);
    func_021C25B0(v1);
    func_021C25D0(v1);
    return v1;
}

