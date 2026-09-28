/*
 * function: func_0219DC58
 * address:  0x0219DC58
 * packet:   pkt_0219DC58
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0219DC34(its own argument 1, 0x0) and returns 0x1.
 *
 * symbols:
 *   func_0219DC34  0x0219DC34  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_0219DC34(u32 a1, u32 a2);

u32 func_0219DC58(u32 a1)
{
    func_0219DC34(a1, 0x0);

    return 0x1;
}

