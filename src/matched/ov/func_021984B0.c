/*
 * function: func_021984B0
 * address:  0x021984B0
 * packet:   pkt_021984B0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198318(its own argument 1, 0x3, 0x2, 0x5) and returns 0x1.
 *
 * symbols:
 *   func_02198318  0x02198318  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198318(u32 a, u32 b, u16 c, u16 d);

u32 func_021984B0(u32 a1)
{
    func_02198318(a1, 0x3, 0x2, 0x5);

    return 0x1;
}

