/*
 * function: func_02029D44
 * address:  0x02029D44
 * packet:   pkt_02029D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020289F8(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_02029D44(u32 a, u32 b, u32 c, u32 d)
{
    u32 r = func_02029E74(b, c);

    if (r == ~0u) {
        r = func_02029E64(b, c, d);
    }

    func_020289F8(a, 6, r, 0x3C, 0);
}
