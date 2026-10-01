/*
 * function: func_0219A5E0
 * address:  0x0219A5E0
 * packet:   pkt_ov021_0219A5E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D4DE8  0x021D4DE8  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern u8 *func_0216D69C(u32);
extern Step d_021D4DE8[];

void func_0219A5E0(u32 a)
{
    u8 *p = func_0216D69C(a);
    while (d_021D4DE8[(s8)p[2]](a, p) == 1) {
    }
}
