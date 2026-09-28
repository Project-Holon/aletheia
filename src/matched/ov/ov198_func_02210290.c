/*
 * function: func_02210290
 * address:  0x02210290
 * packet:   pkt_02210290
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220E13C  0x0220E13C  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0220E13C(u8 *);

u32 func_02210290(u8 *p)
{
    func_0220E13C(p);
    *(u32 *)(p + 0x217c) = 0x16;
    return 0x17;
}

