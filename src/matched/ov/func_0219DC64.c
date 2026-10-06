/*
 * function: func_0219DC64
 * address:  0x0219DC64
 * packet:   pkt_0219DC64
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0219DC34(its own argument 1, 0x1) and returns 0x1.
 *
 * symbols:
 *   func_0219DC34  0x0219DC34  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern int func_0219DC34(u32 a, u32 b);

u32 func_0219DC64(u32 a1)
{
    func_0219DC34(a1, 0x1);

    return 0x1;
}

