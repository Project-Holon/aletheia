/*
 * function: func_02197F9C
 * address:  0x02197F9C
 * packet:   pkt_02197F9C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02197F6C(its own argument 1, 0x1) and returns 0x1.
 *
 * symbols:
 *   func_02197F6C  0x02197F6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02197F6C(u32 a1, u32 a2);

u32 func_02197F9C(u32 a1)
{
    func_02197F6C(a1, 0x1);

    return 0x1;
}

