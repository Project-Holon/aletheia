/*
 * function: func_021BC6D0
 * address:  0x021BC6D0
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
 *   func_021BC63C  0x021BC63C  thumb  ov217
 *   func_021C09F8  0x021C09F8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BC63C(void *p);
extern u32 func_021C09F8(void *p);
u32 func_021BC6D0(void *p)
{
    return func_021C09F8((void *)func_021BC63C(p));
}

