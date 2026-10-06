/*
 * function: func_02197FA8
 * address:  0x02197FA8
 * packet:   pkt_02197FA8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02197F6C(its own argument 1, 0x2) and returns 0x1.
 *
 * symbols:
 *   func_02197F6C  0x02197F6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern int func_02197F6C(u32 a, u32 b);

u32 func_02197FA8(u32 a1)
{
    func_02197F6C(a1, 0x2);

    return 0x1;
}

