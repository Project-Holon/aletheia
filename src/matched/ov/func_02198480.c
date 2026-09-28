/*
 * function: func_02198480
 * address:  0x02198480
 * packet:   pkt_02198480
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198318(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 *
 * symbols:
 *   func_02198318  0x02198318  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198318(u32 a1, u32 a2, u32 a3, u32 a4);

u32 func_02198480(u32 a1)
{
    func_02198318(a1, 0x0, 0x2, 0x5);

    return 0x1;
}

