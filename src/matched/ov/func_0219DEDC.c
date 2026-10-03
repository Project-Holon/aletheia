/*
 * function: func_0219DEDC
 * address:  0x0219DEDC
 * packet:   pkt_0219DEDC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0219DE64(its own argument 1, 0x1, 0x20, 0x1) and returns 0x1.
 *
 * symbols:
 *   func_0219DE64  0x0219DE64  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_0219DE64(u32 a, u32 b, u16 c, u16 d);

u32 func_0219DEDC(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x20, 0x1);

    return 0x1;
}

