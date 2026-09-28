/*
 * function: func_021989C8
 * address:  0x021989C8
 * packet:   pkt_021989C8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02198960(its own argument 1, 0xf) and returns 0x1.
 *
 * symbols:
 *   func_02198960  0x02198960  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_02198960(u32 a1, u32 a2);

u32 func_021989C8(u32 a1)
{
    func_02198960(a1, 0xf);

    return 0x1;
}

