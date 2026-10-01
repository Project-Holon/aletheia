/*
 * function: func_021AE430
 * address:  0x021AE430
 * packet:   pkt_ov021_021AE430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AE754  0x021AE754  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_020122C0(u32 a, u32 b, void (*cb)(void), u32 size);
extern u32 *func_020124E8(u32 h);
extern void func_021AE754(void);

u32 func_021AE430(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = func_020122C0(a, 0, func_021AE754, 8);
    p = func_020124E8(h);
    p[0] = x;
    p[1] = y;
    return h;
}
