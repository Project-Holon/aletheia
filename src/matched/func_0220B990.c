/*
 * function: func_0220B990
 * address:  0x0220B990
 * packet:   pkt_0220B990
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220B094  0x0220B094  thumb  ov196
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0220B094(u8 *, u32);

u32 func_0220B990(u8 *p)
{
    return func_0220B094(p + 0x28, *(u32 *)(p + 0x59c));
}

