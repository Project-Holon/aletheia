/*
 * function: func_021A0974
 * address:  0x021A0974
 * packet:   pkt_021A0974
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021A0980(its own argument 1, its own argument 2, its own argument 3, 0x3c) and returns nothing.
 *
 * symbols:
 *   func_021A0980  0x021A0980  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_021A0980(u32 a1, u32 a2, u32 a3, u32 a4);

void func_021A0974(u32 a1, u32 a2, u32 a3)
{
    func_021A0980(a1, a2, a3, 0x3c);
}

