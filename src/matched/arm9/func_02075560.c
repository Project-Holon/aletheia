/*
 * function: func_02075560
 * address:  0x02075560
 * packet:   pkt_0207533C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8   *func_02074324(u32 a);
extern u32   func_02075698(u32 a, u32 b, u32 c, u32 d, u32 *p, u32 e);

u32 func_02075560(u32 a, u32 b)
{
    u8 *p = func_02074324(b);

    if (p == 0) return 0;
    return func_02075698(a, *(u8 *)(p + 9), *(u16 *)(p + 4), *(u8 *)(p + 8),
                         (u32 *)p, b);
}
