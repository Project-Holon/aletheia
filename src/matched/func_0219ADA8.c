/*
 * function: func_0219ADA8
 * address:  0x0219ADA8
 * packet:   pkt_0219ADA8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0219AD18(its own argument 1, 0x2, 0x0, 0x24) and returns nothing.
 *
 * symbols:
 *   func_0219AD18  0x0219AD18  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_0219AD18(u32 a1, u32 a2, u32 a3, u32 a4);

void func_0219ADA8(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x0, 0x24);
}

