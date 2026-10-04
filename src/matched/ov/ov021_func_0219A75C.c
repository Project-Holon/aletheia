/*
 * function: func_0219A75C
 * address:  0x0219A75C
 * packet:   pkt_ov021_0219A75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D4DB8  0x021D4DB8  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *func_0216D69C(void *p);
extern Step d_021D4DB8[];

void func_0219A75C(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4DB8[(s8)p[2]](a, p) == 1) {
    }
}
