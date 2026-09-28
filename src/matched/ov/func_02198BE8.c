/*
 * function: func_02198BE8
 * address:  0x02198BE8
 * packet:   pkt_02198BE8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198B4C(its own argument 1, 0x2, 0x0) and returns 0x0.
 *
 * symbols:
 *   func_02198B4C  0x02198B4C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198B4C(u32 a1, u32 a2, u32 a3);

u32 func_02198BE8(u32 a1)
{
    func_02198B4C(a1, 0x2, 0x0);

    return 0x0;
}

