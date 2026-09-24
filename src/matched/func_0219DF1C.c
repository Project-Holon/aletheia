/*
 * function: func_0219DF1C
 * address:  0x0219DF1C
 * packet:   pkt_0219DF1C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0219DE64(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 *
 * symbols:
 *   func_0219DE64  0x0219DE64  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_0219DE64(u32 a1, u32 a2, u32 a3, u32 a4);

u32 func_0219DF1C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x10, 0x2);

    return 0x1;
}

