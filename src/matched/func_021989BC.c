/*
 * function: func_021989BC
 * address:  0x021989BC
 * packet:   pkt_021989BC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198960(its own argument 1, 0x8) and returns 0x1.
 *
 * symbols:
 *   func_02198960  0x02198960  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198960(u32 a1, u32 a2);

u32 func_021989BC(u32 a1)
{
    func_02198960(a1, 0x8);

    return 0x1;
}

