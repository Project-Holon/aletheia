/*
 * function: func_02024498
 * address:  0x02024498
 * packet:   pkt_02024464
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209F724  0x0209F724  data
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02045EC0(u32 a, u32 b);
extern void func_02045C04(u32 a);
extern u32 func_0201D478(u32 a);
extern void func_02045808(u32 a);

extern u16 g_0209F724[];

u32 func_02024498(u32 a0, u32 a1, u32 a2)
{
    u32 x = func_02045B38(0, 2, g_0209F724[a0], a2);
    u32 y = func_02045EC0(x, a1);
    u32 z;

    func_02045C04(x);
    z = func_0201D478(y);
    func_02045808(y);

    return z;
}
