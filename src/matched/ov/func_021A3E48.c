/*
 * function: func_021A3E48
 * address:  0x021A3E48
 * packet:   pkt_021A3E48
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021A3D6C(its own argument 1, 0x1) and returns 0x0.
 *
 * symbols:
 *   func_021A3D6C  0x021A3D6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_021A3D6C(u32 a1, u32 a2);

u32 func_021A3E48(u32 a1)
{
    func_021A3D6C(a1, 0x1);

    return 0x0;
}

