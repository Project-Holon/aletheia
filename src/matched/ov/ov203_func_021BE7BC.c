/*
 * function: func_021BE7BC
 * address:  0x021BE7BC
 * packet:   pkt_021BE7BC
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE7A8  0x021BE7A8  thumb  ov203
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BE7A8(u32);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);

void func_021BE7BC(u32 a, u32 b, u32 c)
{
    u16 *t = (u16 *)func_021BE7A8(a);

    func_02011510(b, 0xa0, *t, c);
}

