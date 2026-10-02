/*
 * function: func_021C11DC
 * address:  0x021C11DC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C1AC0  0x021C1AC0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_021C1AC0(u32, u8);
u32 func_021C11DC(u32 a0, u8 a1)
{
    return *(u8*)(((u8*)func_021C1AC0(a0, a1)) + 8);
}

