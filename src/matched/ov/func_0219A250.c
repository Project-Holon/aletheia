/*
 * function: func_0219A250
 * address:  0x0219A250
 * packet:   pkt_0219A250
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls func_0219A290(its own argument 1, 0xc, 0xb, 0x0) and returns nothing.
 *
 * symbols:
 *   func_0219A290  0x0219A290  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_0219A290(u32 a1, u32 a2, u32 a3, u32 a4);

void func_0219A250(u32 a1)
{
    func_0219A290(a1, 0xc, 0xb, 0x0);
}

