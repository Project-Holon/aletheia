/*
 * function: func_021C270C
 * address:  0x021C270C
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
 *   func_021C2914  0x021C2914  thumb  ov217
 *   func_021C2950  0x021C2950  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C2914(void *a0);
extern void func_021C2950(u32);
u32 func_021C270C(void *a0)
{
    func_021C2950((u32)a0);
    return func_021C2914(a0);
}

