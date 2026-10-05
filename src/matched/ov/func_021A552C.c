/*
 * function: func_021A552C
 * address:  0x021A552C
 * packet:   pkt_021A552C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls func_021A550C() and returns 0x0.
 *
 * symbols:
 *   func_021A550C  0x021A550C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_021A550C(u32 *p);

u32 func_021A552C(u32 *p)
{
    func_021A550C(p);

    return 0x0;
}

