/*
 * function: func_0219AB68
 * address:  0x0219AB68
 * packet:   pkt_ov021_0219AB68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D4D04  0x021D4D04  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *func_0216D69C(void *p);
extern Step d_021D4D04[];

void func_0219AB68(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4D04[p[0]](a, p) == 1) {
    }
}
