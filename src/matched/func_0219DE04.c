/*
 * function: func_0219DE04
 * address:  0x0219DE04
 * packet:   pkt_0219DE04
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0219DC88(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 *
 * symbols:
 *   func_0219DC88  0x0219DC88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_0219DC88(u32 a1, u32 a2, u32 a3, u32 a4);

u32 func_0219DE04(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x2, 0x5);

    return 0x1;
}

