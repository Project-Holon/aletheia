/*
 * function: func_021B010C
 * address:  0x021B010C
 * packet:   pkt_ov021_021B010C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0084  0x021B0084  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_020122C0(u32 a, u32 b, void (*cb)(void), u32 size);
extern u32 *func_020124E8(u32 h);
extern void func_021B0084(void);

u32 func_021B010C(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = func_020122C0(a, 0, func_021B0084, 0xc);
    p = func_020124E8(h);
    p[0] = x;
    p[1] = y;
    return h;
}
